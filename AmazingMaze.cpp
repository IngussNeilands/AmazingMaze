#include <string>
#include <iostream>
#include "Iw2D.h"
//#include "input.h"
#include "s3ePointer.h"
#include "IwResManager.h"
#include "s3eKeyboard.h"
#include "Iw2DSceneGraph.h"
#include "math.h"
#include "IwGx.h"
#include <sstream>
using namespace std;
#include "MazeGenerator.h"
#include "MazeDrawer.h"
#include "PlayerMovement.h"
#include "menu.h"

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

const _STL::string doubleToStr(double x){
	_STL::stringstream ss;
	ss << x;
	return ss.str();
}

int main()
{
	// Initialise Iw2D
	Iw2DInit();
	// Get surface width and height
	int surface_width = Iw2DGetSurfaceWidth();
	int surface_height = Iw2DGetSurfaceHeight();
	int currentLevel = 1;
	clock_t duration = 0;
	clock_t beg = clock();
	clock_t now = clock();
	clock_t pastTime = 0;
	clock_t totalT = 0;
	int record_beg = 0;
	int printCountDown = 1;
	//g_pInput = new Input();
	//for StartMenu
	CIw2DImage* StartBg = Iw2DCreateImage("textures/menubg.png");
	CIw2DImage* PlayBt = Iw2DCreateImage("textures/playbt.png");
	CIw2DImage* PlayBtC = Iw2DCreateImage("textures/playbtclicked.png");
	CIw2DImage* StartTitle = Iw2DCreateImage("textures/title.png");
	//for LevelMenu
	CIw2DImage* LevelBg = Iw2DCreateImage("textures/menubg.png");
	CIw2DImage* LevelTitle = Iw2DCreateImage("textures/chooselevel.png");
	CIw2DImage* BackBt = Iw2DCreateImage("textures/backbt.png");
	CIw2DImage* BackBtC = Iw2DCreateImage("textures/backbtclicked.png");
	CIw2DImage* EasyBt = Iw2DCreateImage("textures/easybt.png");
	CIw2DImage* EasyBtC = Iw2DCreateImage("textures/easybtclicked.png");
	CIw2DImage* MedBt = Iw2DCreateImage("textures/mediumbt.png");
	CIw2DImage* MedBtC = Iw2DCreateImage("textures/mediumbtclicked.png");
	CIw2DImage* HardBt = Iw2DCreateImage("textures/hardbt.png");
	CIw2DImage* HardBtC = Iw2DCreateImage("textures/hardbtclicked.png");
	//for InGameMenu
	CIw2DImage* Player = Iw2DCreateImage("textures/gem1.png");
	CIw2DImage* InBt = Iw2DCreateImage("textures/inbt.png");
	CIw2DImage* InBtC = Iw2DCreateImage("textures/inbtclicked.png");
	CIw2DImage* OutBt = Iw2DCreateImage("textures/outbt.png");
	CIw2DImage* OutBtC = Iw2DCreateImage("textures/outbtclicked.png");
	CIw2DImage* PauseBt = Iw2DCreateImage("textures/pausebt.png");
	CIw2DImage* PauseBtC = Iw2DCreateImage("textures/pausebtclicked.png");
	//for PauseMenu
	CIw2DImage* PauseBg = Iw2DCreateImage("textures/menubg.png");
	CIw2DImage* PauseTitle = Iw2DCreateImage("textures/pausedtitle.png");
	CIw2DImage* ResumeBt = Iw2DCreateImage("textures/resumebt.png");
	CIw2DImage* ResumeBtC = Iw2DCreateImage("textures/resumebtclicked.png");
	CIw2DImage* StartOverBt = Iw2DCreateImage("textures/startoverbt.png");
	CIw2DImage* StartOverBtC = Iw2DCreateImage("textures/startoverbtclicked.png");
	CIw2DImage* ChangeLevelBt = Iw2DCreateImage("textures/changelevelbt.png");
	CIw2DImage* ChangeLevelBtC = Iw2DCreateImage("textures/changelevelbtclicked.png");

	CIwFVec2 image_position = CIwFVec2(surface_width / 2 - 2.5, surface_height / 2 - 2.5);
	uint32 timer = (uint32)s3eTimerGetMs();
	int stage = 0;  //0 = StartM, 1 = LevelM, 2 = InGameM, 3 = PauseM, 4 = PostM, 5 = reset
	float angle = 270;
	while (!s3eDeviceCheckQuitRequest())
	{

		s3eKeyboardUpdate();
		s3ePointerUpdate();

		// Clear background to blue
		
		
		
		if (stage == 0){
			stage = StartM(StartBg, PlayBt, PlayBtC, StartTitle);
			Iw2DSurfaceShow();
		}
		if (stage == 1){
			stage = LevelM(LevelBg, LevelTitle, BackBt, BackBtC, EasyBt, EasyBtC, MedBt, MedBtC, HardBt, HardBtC);
			currentLevel = 1;
			duration = 0;
			beg = clock();
			printCountDown = 1; 
			pastTime = 0;
			totalT = 0;
			angle = 270;
			Iw2DSurfaceShow();
		}
		if (stage == 2){
				if(printCountDown == 1){
					Iw2DSurfaceClear(0xff000000); // 0x00000000 - black  0xffffffff = white.  AGBR,
					Iw2DSetColour(0xffffffff);
					stage = InGameM(PauseBt, PauseBtC); // BG + Pause Button
					DrawMaze(currentLevel);  // Maze
					DrawPlayer(currentLevel, angle, Player); // player + player Movement
					PlayerMove(currentLevel, angle, InBt, InBtC, OutBt, OutBtC);
					now = clock();
					duration = (now - beg);
					totalT = 3999 - duration;
					if (totalT <= 100) {
						printCountDown = 0;
						beg = clock();
					}
					double diff = totalT / (double)CLOCKS_PER_SEC;
					double TT = floor(diff);
					_STL::string result;
					result = doubleToStr(TT);
					IwGxPrintSetScale(2);
					IwGxPrintSetColour(255, 255, 0);
					IwGxPrintString(20, 30, "Start In:", false);
			    	IwGxPrintString(140, 30, result.c_str(), false);
			}
			if (printCountDown == 0){
				Iw2DSurfaceClear(0xff000000); // 0x00000000 - black  0xffffffff = white.  AGBR,
				Iw2DSetColour(0xffffffff);
				stage = InGameM(PauseBt, PauseBtC); // BG + Pause Button
				DrawMaze(currentLevel);  // Maze
				angle = DrawPlayer(currentLevel, angle, Player); // player + player Movement
				currentLevel = PlayerMove(currentLevel, angle, InBt, InBtC, OutBt, OutBtC);
				if (currentLevel != MaxLevel+1)now = clock();
				duration = now - beg;
				totalT = pastTime + duration;
				double diff = totalT / (double)CLOCKS_PER_SEC;
				double TT = floor(diff * 100) / 100;
				_STL::string result;
				result = doubleToStr(TT);
				IwGxPrintSetScale(2);
				IwGxPrintSetColour(255, 255, 0);
				IwGxPrintString(20, 30, "Time:", false);
				IwGxPrintString(100, 30, result.c_str(), false);
			}
			
			Iw2DSurfaceShow();
		}
		if (stage == 3){
			Iw2DSurfaceClear(0xff000000); // 0x00000000 - black  0xffffffff = white.  AGBR,
			Iw2DSetColour(0xffffffff);
			if (printCountDown == 0) pastTime = pastTime + duration;
			beg = clock();
			printCountDown = 1;
			stage = PauseM(PauseBg, PauseTitle, ResumeBt, ResumeBtC, StartOverBt, StartOverBtC, ChangeLevelBt, ChangeLevelBtC);
			Iw2DSurfaceShow();
		}
		if (stage == 5){
			angle = 270;
			currentLevel = 1;
			duration = 0;
			beg = clock();
			totalT = 0;
			printCountDown = 1;
			//pastTime = 0;
			stage = 2;
		}


		

		// Sleep to allow the OS to process events etc.
		s3eDeviceYield(0);
	}

	// Shut down Iw2D
	//delete image;
	//delete g_pInput;
	Iw2DTerminate();

}

