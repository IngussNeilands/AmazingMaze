#include "Iw2D.h"
//#include "input.h"
#include "s3ePointer.h"
#include "IwResManager.h"
#include "s3eKeyboard.h"
#include "Iw2DSceneGraph.h"
#include "math.h"
#include <string>
#include <iostream>

using namespace Iw2DSceneGraphCore;
using namespace Iw2DSceneGraph;

// Scene root node
CNode* g_SceneRoot = NULL;

// Set the surface type to be XRGB888 which uses a 32 bit data format, with 8 bits for channel and the top 8 bits left unused
//
// Discover the screen width, height and pitch
uint32 screenWidth = s3eSurfaceGetInt(S3E_SURFACE_WIDTH);
uint32 screenHeight = s3eSurfaceGetInt(S3E_SURFACE_HEIGHT);
uint32 screenPitch = s3eSurfaceGetInt(S3E_SURFACE_PITCH);
float left[7];
float right[7];


bool checkCollision(CIwFVec2 xy){
	//if (xy.y <= screenHeight/2 - 25 ) return false;
	
	int r1 = 0;
	int stage = 0;
	int stageX = abs((xy.x - screenWidth / 2) / 27);
	int stageY = abs((xy.y - screenHeight / 2) / 27);
	if (stageX <= stageY) {
		stage = stageY;
	}
	else stage = stageX;
	//Iw2DDrawString(std::to_string(stage), CIwFVec2(10, 10), CIwFVec2(20, 20));

	if (stage == 0) r1 = 0; 
	if (stage == 1) r1 = 25;
	if (stage == 2) r1 = 50;
	if (stage == 3) r1 = 75;
	int r2 = r1 + 25;
	
	for (float i = 0; i <= 360; i=i+0.5){
			float x1 = (screenWidth / 2) + (r1 * sin(i*PI / 180));
			float y1 = (screenHeight / 2) - (r1 * cos(i*PI / 180));
			float x2 = (screenWidth / 2) + (r2 * sin(i*PI / 180));
			float y2 = (screenHeight / 2) - (r2 * cos(i*PI / 180));
			Iw2DSetColour(0xff000000);
			Iw2DDrawRect(CIwFVec2(x2, y2), CIwFVec2(1, 1));
			if (i >= 0 && i <= 90){
				if (stage < 0){
					if (xy.x <= x1 && xy.y >= y1) return true;
				}
				if (xy.x >= x2 && xy.y <= y2) return true;
			}
			if (i >= 90 && i <= 180){
				if (stage < 0){
					if (xy.x <= x1 && xy.y <= y1) return true;
			}
				if (xy.x >= x2 && xy.y >= y2) return true;
			}

			if (i >= 180 && i <= 270){
				if (stage < 0){
					if (xy.x >= x1 && xy.y <= y1) return true;
				}
				if (xy.x <= x2 && xy.y >= y2) return true;
			}
			if (i >= 270 && i <= 360){
				if (stage < 0){
					if (xy.x >= x1 && xy.y >= y1) return true;
				}
				if (xy.x <= x2 && xy.y <= y2) return true;
			}
	}
	return false;
}
bool checkException(CIwFVec2 xy){
	
		int Lx = (screenWidth / 2) + ((24) * sin(left[0]));
		int Ly = (screenHeight / 2) - ((28) * cos(left[0]));
		int Rx = (screenWidth / 2) + ((28) * sin(right[0]));
		int Ry = (screenHeight / 2) - ((24) * cos(right[0]));

		int Lx1 = (screenWidth / 2) + ((49) * sin(5));
		int Ly1 = (screenHeight / 2) - ((53) * cos(5));
		int Rx1 = (screenWidth / 2) + ((53) * sin(5.2));
		int Ry1 = (screenHeight / 2) - ((49) * cos(5.2));

		int Lx2 = (screenWidth / 2) + ((49) * sin(2.5));
		int Ly2 = (screenHeight / 2) - ((53) * cos(2.5));
		int Rx2 = (screenWidth / 2) + ((53) * sin(2.7));
		int Ry2 = (screenHeight / 2) - ((49) * cos(2.7));

		if ( (xy.x >= Lx && xy.x <= Rx && xy.y >= Ly && xy.y <= Ry ) ||
		     (xy.x >= Lx1 && xy.x <= Rx1 && xy.y >= Ly1 && xy.y <= Ry1) ||
		     (xy.x >= Lx2 && xy.x <= Rx2 && xy.y >= Ly2 && xy.y <= Ry2) ) return true;
		return false;
}

// Main entry point for the application
int main()
{
	// Initialise Iw2D
	Iw2DInit();

	// Get surface width and height
	int surface_width = Iw2DGetSurfaceWidth();
	int surface_height = Iw2DGetSurfaceHeight();
	//g_pInput = new Input();

	CIw2DImage* image = Iw2DCreateImage("textures/gem1.png");
	CIw2DImage* menubg = Iw2DCreateImage("textures/menubg.png");
	CIw2DImage* playbt = Iw2DCreateImage("textures/playbt.png");
	CIw2DImage* bg = Iw2DCreateImage("textures/rainbowbg.png");
	CIw2DImage* touchscreenButtonImage[4];
	touchscreenButtonImage[0] = Iw2DCreateImage("textures/touchscreenMoveUp.png");
	touchscreenButtonImage[1] = Iw2DCreateImage("textures/touchscreenMoveL.png");
	touchscreenButtonImage[2] = Iw2DCreateImage("textures/touchscreenMoveDown.png");
	touchscreenButtonImage[3] = Iw2DCreateImage("textures/touchscreenMoveR.png");

	CIwFVec2 image_position = CIwFVec2(surface_width / 2 - 2.5, surface_height / 2 - 2.5);
	uint32 timer = (uint32)s3eTimerGetMs();
	int maze = 0;
	// Rotation angle of rectangle
	//float angle = 0;
	
	// Wait for a quit request from the host OS
	while (!s3eDeviceCheckQuitRequest())
	{
		// Update input system
		//g_pInput->Update();	
		// Update audio system
		s3eKeyboardUpdate();
		s3ePointerUpdate();

		// Clear background to blue
		Iw2DSurfaceClear(0xff8080);

		// Set up a transform
		//CIwFMat2D mat;
		//mat.SetRot(angle);
		//mat.ScaleRot(2.0f);
		//mat.SetTrans(CIwFVec2((float)surface_width / 2, (float)surface_height / 2));
		//Iw2DSetTransformMatrix(mat);
		//	angle += 0.01f;

		// Render filled rectangle
		//Iw2DSetColour(0xff00ffff);
		//Iw2DFillRect(CIwFVec2(-50.0f, -100.0f), CIwFVec2(100.0f, 200.0f));

		// Draw the control buttons
		if (maze == 0){
			Iw2DDrawImage(menubg, CIwFVec2(0, 0), CIwFVec2(320, 492));
			Iw2DDrawImage(playbt, CIwFVec2(85, 286), CIwFVec2(150, 50));


			if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) & S3E_POINTER_STATE_DOWN)
			{
				//  g_DrawTouchscreenButtons = 1;

				int displayWidth = Iw2DGetSurfaceWidth();
				int displayHeight = Iw2DGetSurfaceHeight();
				int x = s3ePointerGetX() * 4 / displayWidth;
				int y = s3ePointerGetY() * 4 / displayHeight;
				if (x == 1 && y == 2)
					maze = 1;
				if (x == 2 && y == 2)
					maze = 1;
			
			}

		}
		// Render filled arc
		if (maze == 1){
			//Iw2DDrawImage(bg, CIwFVec2(0, 0), CIwFVec2(320, 492));
			Iw2DSetColour(0xff59ff4d);
			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(25.0f, 25.0f), 0, 2 * PI);
			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(26.0f, 26.0f), 0, 2 * PI);
			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(27.0f, 27.0f), 0, 2 * PI);
			//Iw2DDrawLine(CIwFVec2(surface_width / 2 + 14.1, surface_height / 2 - 20.62), CIwFVec2(surface_width / 2 + 31.77, surface_height / 2 - 38.29));
			Iw2DDrawLine(CIwFVec2(surface_width / 2 + 14.1, surface_height / 2 - 20.62), CIwFVec2(surface_width / 2 + 28.24, surface_height / 2 - 41.26));

			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(50.0f, 50.0f), 0, 2 * PI);
			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(51.0f, 51.0f), 0, 2 * PI);
			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(52.0f, 52.0f), 0, 2 * PI);
			Iw2DDrawLine(CIwFVec2(surface_width / 2 - 17.5391614, surface_height / 2 + 46.82283435), CIwFVec2(surface_width / 2 - 26.3087, surface_height / 2 + 70.23425));
			Iw2DDrawLine(CIwFVec2(surface_width / 2 - 35.28, surface_height / 2 - 35.43), CIwFVec2(surface_width / 2 - 52.92, surface_height / 2 - 53.14));


			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(75.0f, 75.0f), 0, 2 * PI);
			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(76.0f, 76.0f), 0, 2 * PI);
			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(77.0f, 77.0f), 0, 2 * PI);
			Iw2DDrawLine(CIwFVec2(surface_width / 2 + 63.1308696, surface_height / 2 - 40.490657), CIwFVec2(surface_width / 2 + 84.17449279, surface_height / 2 - 53.98754266));
			Iw2DDrawLine(CIwFVec2(surface_width / 2 + 32.05, surface_height / 2 + 67.8), CIwFVec2(surface_width / 2 + 42.73, surface_height / 2 + 90.41));
			Iw2DDrawLine(CIwFVec2(surface_width / 2 - 74.48188, surface_height / 2 - 8.8005), CIwFVec2(surface_width / 2 - 99.30917, surface_height / 2 - 11.734));

			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(100.0f, 100.0f), 0, 2 * PI);
			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(101.0f, 101.0f), 0, 2 * PI);
			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(102.0f, 102.0f), 0, 2 * PI);

			Iw2DDrawImage(image, image_position, CIwFVec2(5, 5));
			Iw2DDrawImage(touchscreenButtonImage[0], CIwFVec2(90, surface_height - 74));
			Iw2DDrawImage(touchscreenButtonImage[1], CIwFVec2(10, surface_height - 74));
			Iw2DDrawImage(touchscreenButtonImage[3], CIwFVec2(surface_width - 74, surface_height - 74));
			Iw2DDrawImage(touchscreenButtonImage[2], CIwFVec2(surface_width / 2, surface_height - 74));


			Iw2DSetColour(0xffff8080);

			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(25.0f, 25.0f), 0, 0.3);
			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(26.0f, 26.0f), 0, 0.3);
			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(27.0f, 27.0f), 0, 0.3);
			left[0] = 0.00001;
			right[0] = 0.3;


			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(50.0f, 50.0f), 5, 5.2);
			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(51.0f, 51.0f), 5, 5.2);
			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(52.0f, 52.0f), 5, 5.2);
			left[1] = 5;
			right[1] = 5.2;

			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(50.0f, 50.0f), 2.5, 2.7);
			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(51.0f, 51.0f), 2.5, 2.7);
			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(52.0f, 52.0f), 2.5, 2.7);
			left[2] = 2.5;
			right[2] = 2.7;

			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(75.0f, 75.0f), 4, 4.13);
			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(76.0f, 76.0f), 4, 4.13);
			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(77.0f, 77.0f), 4, 4.13);
			left[3] = 4;
			right[3] = 4.13;

			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(75.0f, 75.0f), 0.7, 0.83);
			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(76.0f, 76.0f), 0.7, 0.83);
			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(77.0f, 77.0f), 0.7, 0.83);
			left[4] = 0.7;
			right[4] = 0.83;

			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(75.0f, 75.0f), 1.2, 1.33);
			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(76.0f, 76.0f), 1.2, 1.33);
			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(77.0f, 77.0f), 1.2, 1.33);
			left[5] = 1.2;
			right[5] = 1.33;

			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(100.0f, 100.0f), 2, 2.08);
			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(101.0f, 101.0f), 2, 2.08);
			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(102.0f, 102.0f), 2, 2.08);
			left[6] = 2;
			right[6] = 2.08;




			if (s3eKeyboardGetState(s3eKeyAbsLeft) & S3E_KEY_STATE_DOWN){
				image_position.x = image_position.x - 1;
				if (checkCollision(image_position)) {
					image_position.x = image_position.x + 1;
				}
				if (checkException(image_position)){
					image_position.x = image_position.x - 1;
				}

			}
			if (s3eKeyboardGetState(s3eKeyAbsRight) & S3E_KEY_STATE_DOWN){
				image_position.x = image_position.x + 1;
				if (checkCollision(image_position)) {
					image_position.x = image_position.x - 1;
				}
				if (checkException(image_position)){
					image_position.x = image_position.x + 1;
				}
			}
			if (s3eKeyboardGetState(s3eKeyAbsDown) & S3E_KEY_STATE_DOWN){
				image_position.y = image_position.y + 1;
				if (checkCollision(image_position)) {
					image_position.y = image_position.y - 1;
				}
				if (checkException(image_position)){
					image_position.y = image_position.y + 1;
				}
			}
			if (s3eKeyboardGetState(s3eKeyAbsUp) & S3E_KEY_STATE_DOWN){
				image_position.y = image_position.y - 1;
				if (checkCollision(image_position)) {
					image_position.y = image_position.y + 1;
				}
				if (checkException(image_position)){
					image_position.y = image_position.y - 1;
				}
			}


			int displayWidth = Iw2DGetSurfaceWidth();
			int displayHeight = Iw2DGetSurfaceHeight();

			int size = MIN(displayWidth / 3, displayHeight / 4) - 8;
			if (size < 64)
				size = 32;
			else
				size = 64;


			if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) & S3E_POINTER_STATE_DOWN)
			{
				//  g_DrawTouchscreenButtons = 1;

				int displayWidth = Iw2DGetSurfaceWidth();
				int displayHeight = Iw2DGetSurfaceHeight();
				int x = s3ePointerGetX() * 4 / displayWidth;
				int y = s3ePointerGetY() * 4 / displayHeight;
				if (x == 0 && y == 3)
					//  xMovement--;
					image_position.x = image_position.x - 1;
				if (x == 3 && y == 3)
					//   xMovement++;
					image_position.x = image_position.x + 1;
				if (x == 2 && y == 3)
					//   input_y = 1;
					image_position.y = image_position.y + 1;
				if (x == 1 && y == 3)
					image_position.y = image_position.y - 1;
			}
		}

		//Iw2DSetColour(0xff0000ff);
		//Iw2DDrawRect(CIwFVec2(surface_width / 2 - 1, surface_height / 2 - 1), CIwFVec2(2, 2));
		//Iw2Dget
		// Flip the surface buffer to screen
		Iw2DSurfaceShow();

		// Sleep to allow the OS to process events etc.
		s3eDeviceYield(0);
	}

	// Shut down Iw2D
	delete image;
	//delete g_pInput;
	Iw2DTerminate();

	return 0;
}

