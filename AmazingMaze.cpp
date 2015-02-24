#include <string>
#include <iostream>
#include "Iw2D.h"
//#include "input.h"
#include "s3ePointer.h"
#include "IwResManager.h"
#include "s3eKeyboard.h"
#include "Iw2DSceneGraph.h"
#include "math.h"

using namespace std;
#include "MazeGenerator.h"
#include "MazeDrawer.h"
#include "PlayerMovement.h"

float level[9][20][15];  //a 3D arrway that stores the parent, door leftpt, blockpt, and childs					//0 = parent, 1 = leftpt, 2 = block, 3 = blockleft, 4 = blockright, 5 = childamount, 6-10 = childs
int MaxLevel;  // MaxLevel is set based on the difficulity

using namespace Iw2DSceneGraphCore;
using namespace Iw2DSceneGraph;

// Scene root node
//CNode* g_SceneRoot = NULL;

// Set the surface type to be XRGB888 which uses a 32 bit data format, with 8 bits for channel and the top 8 bits left unused
//
// Discover the screen width, height and pitch
uint32 screenWidth = s3eSurfaceGetInt(S3E_SURFACE_WIDTH);
uint32 screenHeight = s3eSurfaceGetInt(S3E_SURFACE_HEIGHT);
uint32 screenPitch = s3eSurfaceGetInt(S3E_SURFACE_PITCH);


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
	CIw2DImage* rainbowbg = Iw2DCreateImage("textures/rainbowbg.png");
	CIw2DImage* bg = Iw2DCreateImage("textures/rainbowbg.png");
	CIw2DImage* player = Iw2DCreateImage("textures/gem1.png");
	CIw2DImage* InBt = Iw2DCreateImage("textures/in1.png");
	
	CIw2DImage* touchscreenButtonImage[4];
	touchscreenButtonImage[0] = Iw2DCreateImage("textures/touchscreenMoveUp.png");
	touchscreenButtonImage[1] = Iw2DCreateImage("textures/touchscreenMoveL.png");
	touchscreenButtonImage[2] = Iw2DCreateImage("textures/touchscreenMoveDown.png");
	touchscreenButtonImage[3] = Iw2DCreateImage("textures/touchscreenMoveR.png");

	CIwFVec2 image_position = CIwFVec2(surface_width / 2 - 2.5, surface_height / 2 - 2.5);
	uint32 timer = (uint32)s3eTimerGetMs();
	int curLevel = 1;
	int maze = 0;
	float angle = 270;
	float Pangle;
	int once = 0;

	while (!s3eDeviceCheckQuitRequest())
	{

		s3eKeyboardUpdate();
		s3ePointerUpdate();

		// Clear background to blue
		
		
		
		if (maze == 0){
			Iw2DDrawImage(menubg, CIwFVec2(0, 0), CIwFVec2(320, 492));
			Iw2DDrawImage(playbt, CIwFVec2(85, 286), CIwFVec2(150, 50));
			Iw2DSurfaceClear(0xffffffff);
			if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) & S3E_POINTER_STATE_DOWN)
			{
				//  g_DrawTouchscreenButtons = 1;

				int displayWidth = Iw2DGetSurfaceWidth();
				int displayHeight = Iw2DGetSurfaceHeight();
				int x = s3ePointerGetX() * 4 / displayWidth;
				int y = s3ePointerGetY() * 4 / displayHeight;
				int Maxlvl;
				if (x == 1 && y == 2){
					MazeInitializer();
					setDifficulity(2);
					DoorGenerator();
					printall();
					maze = 1;
					x = 0;
					y = 0;
				}
				if (x == 2 && y == 2){
					MazeInitializer();
					setDifficulity(2);
					DoorGenerator();
					printall();
					maze = 1;
					x = 0;
					y = 0;
				}
			}
			Iw2DSurfaceShow();
		}
		// Render filled arc
		if (maze == 1){
			Iw2DSurfaceClear(0xff000000); // 0x00000000 - black  0xffffffff = white.  AGBR,
			Iw2DSetColour(0xffffffff);
			//Iw2DDrawImage(rainbowbg, CIwFVec2(0, 0), CIwFVec2(320, 492));
			DrawMaze(curLevel);
			Pangle = angle;
			angle = DrawPlayer(curLevel, angle, player, InBt);
			if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) & S3E_POINTER_STATE_PRESSED){
				//  g_DrawTouchscreenButtons = 1;

				int displayWidth = Iw2DGetSurfaceWidth();
				int displayHeight = Iw2DGetSurfaceHeight();
				int x = s3ePointerGetX();
				int y = s3ePointerGetY();
				
				if (x < 160 && y < 160) curLevel= moveUp(curLevel, angle);
				if (x>displayWidth - 160 && y > displayHeight - 160) curLevel = moveDown(curLevel, angle);
			}

			
			
		}

		Iw2DSurfaceShow();
		

		// Sleep to allow the OS to process events etc.
		s3eDeviceYield(0);
	}

	// Shut down Iw2D
	//delete image;
	//delete g_pInput;
	Iw2DTerminate();

}

