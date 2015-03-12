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
#include <stdio.h>
#include <list>
#include <fstream>

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



std::list<double> EasyScores;
std::list<double> MediumScores;
std::list<double> HardScores;
std::list<double>::iterator it;


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
	int printonce = 0;
	int insertonce = 0;

	std::ifstream ifile("easyScore.txt");
	
	double num1 = 0.0;
	while (ifile >> num1){
		EasyScores.push_back(num1);
	}
	EasyScores.sort();

	
	std::ifstream ifile2("mediumScore.txt");

	double num2 = 0.0;
	while (ifile2 >> num2){
		MediumScores.push_back(num2);
	}
	MediumScores.sort();


	std::ifstream ifile3("hardScore.txt");

	double num3 = 0.0;
	while (ifile3 >> num3){
		HardScores.push_back(num3);
	}
	HardScores.sort();
   

  
    
	//g_pInput = new Input();
	//for StartMenu
	CIw2DImage* StartBg = Iw2DCreateImage("textures/menubg.png");
	CIw2DImage* PlayBt = Iw2DCreateImage("textures/playbt.png");
	CIw2DImage* PlayBtC = Iw2DCreateImage("textures/playbtclicked.png");
	CIw2DImage* StartTitle = Iw2DCreateImage("textures/title.png");
    CIw2DImage* ScoresBt = Iw2DCreateImage("textures/scoresbt.png");
    CIw2DImage* ScoresBtC = Iw2DCreateImage("textures/scoresbtclicked.png");
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
	CIw2DImage* InGameBg = Iw2DCreateImage("textures/rainbowbg.png");
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
    //for PostMenu
    CIw2DImage* PostBg = Iw2DCreateImage("textures/menubg.png");
    CIw2DImage* PostTitle = Iw2DCreateImage("textures/finished.png");
    CIw2DImage* RetryBt = Iw2DCreateImage("textures/retrybt.png");
    CIw2DImage* RetryBtC = Iw2DCreateImage("textures/retrybtclicked.png");
    CIw2DImage* MainMenuBt = Iw2DCreateImage("textures/mainmenubt.png");
    CIw2DImage* MainMenuBtC = Iw2DCreateImage("textures/mainmenubtclicked.png");
    //for ScoreMenu
    CIw2DImage* ScoresBg = Iw2DCreateImage("textures/menubg.png");
   // CIw2DImage* ScoresTitle = Iw2DCreateImage("textures/scorestitle.png");
    CIw2DImage* EasyTitle = Iw2DCreateImage("textures/easyscorestitle.png");
    CIw2DImage* MedTitle = Iw2DCreateImage("textures/mediumscorestitle.png");
    CIw2DImage* HardTitle = Iw2DCreateImage("textures/hardscorestitle.png");
    CIw2DImage* EasyScoresBt = Iw2DCreateImage("textures/easyscoresbt.png");
    CIw2DImage* EasyScoresBtC = Iw2DCreateImage("textures/easyscoresbtclicked.png");
    CIw2DImage* MedScoresBt = Iw2DCreateImage("textures/mediumscoresbt.png");
    CIw2DImage* MedScoresBtC = Iw2DCreateImage("textures/mediumscoresbtclicked.png");
    CIw2DImage* HardScoresBt = Iw2DCreateImage("textures/hardscoresbt.png");
    CIw2DImage* HardScoresBtC = Iw2DCreateImage("textures/hardscoresbtclicked.png");

	//for Maze
	CIw2DImage* Color[8];
	Color[1] = Iw2DCreateImage("textures/Red.png");
	Color[2] = Iw2DCreateImage("textures/Orange.png");
	Color[3] = Iw2DCreateImage("textures/Yellow.png");
	Color[4] = Iw2DCreateImage("textures/Green.png");
	Color[5] = Iw2DCreateImage("textures/Blue.png");
	Color[6] = Iw2DCreateImage("textures/Indigo.png");
	Color[7] = Iw2DCreateImage("textures/Purple.png");
	CIw2DImage* MazeOverlay = Iw2DCreateImage("textures/mazeoverlay.png");
	CIw2DImage* TimerOverlay = Iw2DCreateImage("textures/TimerOverlay.png");


	CIwFVec2 image_position = CIwFVec2(surface_width / 2 - 2.5, surface_height / 2 - 2.5);
	uint32 timer = (uint32)s3eTimerGetMs();
	int stage = 0;  //0 = StartM, 1 = LevelM, 2 = InGameM, 3 = PauseM, 4 = PostM, 5 = reset 7=EasyScoreH 8=MediumScoreH 9=HardScoreH
	float angle = 270;
    _STL::string result;
	double TT;
   
    
    
	while (!s3eDeviceCheckQuitRequest())
	{

		s3eKeyboardUpdate();
		s3ePointerUpdate();
		// Clear background to blue
		//for (int i = 0; i < EasyScores.size(); ++i) {
		//	std::cout << EasyScores[i] << std::endl;
		//	}
		double fontsizeScale = surface_width / 320;
		
		
		if (stage == 0){
            stage = StartM(StartBg, PlayBt, PlayBtC, StartTitle, ScoresBt, ScoresBtC);
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
			insertonce = 0;
			Iw2DSurfaceShow();
		}
		if (stage == 2){
			if (printonce == 0){
				printall();
				printonce = 1;
			}
           
				if(printCountDown == 1){
					Iw2DSurfaceClear(0xffffffff); // 0x00000000 - black  0xffffffff = white.  AGBR,
					Iw2DSetColour(0xffffffff);
					Iw2DInit();
					int w = Iw2DGetSurfaceWidth();
					int h = Iw2DGetSurfaceHeight();
					double g = (double)w / 320;
					stage = InGameM(PauseBt, PauseBtC, InGameBg, currentLevel); // BG + Pause Button
					//Iw2DDrawImage(MazeOverlay, CIwFVec2(0, 80), CIwFVec2(320, 320));
					DrawMaze(currentLevel, Color, InGameBg, MazeOverlay);  // Maze
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
					Iw2DDrawImage(TimerOverlay, CIwFVec2(0, 55 * h / 480), CIwFVec2(320*g, 20*g));
					IwGxPrintSetScale(2 * fontsizeScale);
					IwGxPrintSetColour(255, 255, 0);
					IwGxPrintString(75 * w / 320, 60 * h / 480, "Start In:", false);
					IwGxPrintString(225 * w / 320, 60 * h / 480, result.c_str(), false);
			}
           
			if (printCountDown == 0){
				Iw2DSurfaceClear(0xffffffff); // 0x00000000 - black  0xffffffff = white.  AGBR,
				Iw2DSetColour(0xffffffff);
				Iw2DInit();
				int w = Iw2DGetSurfaceWidth();
				int h = Iw2DGetSurfaceHeight();
				double g = (double)w / 320;
				stage = InGameM(PauseBt, PauseBtC, InGameBg, currentLevel); // BG + Pause Button
				//Iw2DDrawImage(MazeOverlay, CIwFVec2(0, 80), CIwFVec2(320, 320));
				DrawMaze(currentLevel, Color, InGameBg, MazeOverlay);  // Maze
				angle = DrawPlayer(currentLevel, angle, Player); // player + player Movement
				currentLevel = PlayerMove(currentLevel, angle, InBt, InBtC, OutBt, OutBtC);
				if (currentLevel != MaxLevel+1) now = clock();
				duration = now - beg;
				totalT = pastTime + duration;
				double diff = totalT / (double)CLOCKS_PER_SEC;
				TT = floor(diff * 100) / 100;
				result = doubleToStr(TT);
                
				Iw2DDrawImage(TimerOverlay, CIwFVec2(0, 55 * h / 480), CIwFVec2(320 * g, 20 * h / 480));
				IwGxPrintSetScale(2 * fontsizeScale);
				IwGxPrintSetColour(255, 255, 0);
				IwGxPrintString(75 * w / 320, 60 * h / 480, "Time:", false);
				IwGxPrintString(195 * w / 320, 60 * h / 480, result.c_str(), false);
                
			}
			
			Iw2DSurfaceShow();
		}
        
		if (stage == 3){
			Iw2DSurfaceClear(0xffffffff); // 0x00000000 - black  0xffffffff = white.  AGBR,
			Iw2DSetColour(0xffffffff);
			if (printCountDown == 0) pastTime = pastTime + duration;
			beg = clock();
			printCountDown = 1;
			stage = PauseM(PauseBg, PauseTitle, ResumeBt, ResumeBtC, StartOverBt, StartOverBtC, ChangeLevelBt, ChangeLevelBtC);
			Iw2DSurfaceShow();
		}
        
        if (stage == 4){
			Iw2DSurfaceClear(0xffffffff); // 0x00000000 - black  0xffffffff = white.  AGBR,
			Iw2DInit();
			int w = Iw2DGetSurfaceWidth();
			int h = Iw2DGetSurfaceHeight();
			double g = (double)w / 320;
            stage = PostM(PostBg, PostTitle, RetryBt, RetryBtC, ChangeLevelBt, ChangeLevelBtC, MainMenuBt, MainMenuBtC);
			Iw2DDrawImage(TimerOverlay, CIwFVec2(0, 100 * h / 480), CIwFVec2(320 * g, 40 * h / 480));
			std::list<double> *List;
			if (MaxLevel == 3){
				if (insertonce == 0){
					EasyScores.push_back(TT);
					insertonce = 1;
					EasyScores.sort();
				}
			}
			if (MaxLevel == 4 || MaxLevel == 5){
				if (insertonce == 0){
					MediumScores.push_back(TT);
					insertonce = 1;
					MediumScores.sort();
				}
			}
			if (MaxLevel == 6 || MaxLevel == 7){
				if (insertonce == 0){
					HardScores.push_back(TT);
					insertonce = 1;
					HardScores.sort();
				}
			}
			IwGxPrintSetScale(3 * fontsizeScale);
            IwGxPrintSetColour(255, 255, 0);
			IwGxPrintString(60 * w / 320, 110 * h / 480, "Time:", false);
			IwGxPrintString(180 * w / 320, 110 * h / 480, result.c_str(), false);
            Iw2DSurfaceShow();
        }
        
		if (stage == 5){
			angle = 270;
			currentLevel = 1;
			duration = 0;
			beg = clock();
			totalT = 0;
			printCountDown = 1;
			pastTime = 0;
			insertonce = 0;
			stage = 2;
		}
        
        if (stage == 7){
            stage = EasyM(ScoresBg, EasyTitle, BackBt, BackBtC, EasyScoresBt, EasyScoresBtC, MedScoresBt, MedScoresBtC, HardScoresBt, HardScoresBtC);
			printf("in stage 7 \n");
			Iw2DInit();
			int w = Iw2DGetSurfaceWidth();
			int h = Iw2DGetSurfaceHeight();
			double g = (double)w / 320;
			Iw2DDrawImage(TimerOverlay, CIwFVec2(0, 150 * h / 480), CIwFVec2(320 * g, 270 * h/480));
			int counter = 1;
			IwGxPrintSetScale(2 * fontsizeScale);
			IwGxPrintSetColour(255, 255, 255);
			IwGxPrintString(50 * w / 320, 155 * h / 480, "Rank", false);
			IwGxPrintString(190 * w / 320, 155 * h / 480, "Time", false);
			for (int i = 1; i <= 10; i++){
				if (i != 10){
					IwGxPrintString(70 * w / 320, (160 + i * 23)* h / 480, doubleToStr(i).c_str(), false);
				}
				else {
					IwGxPrintString(60 * w / 320, (160 + i * 23)* h / 480, doubleToStr(i).c_str(), false);
				}
			}
			for (it = EasyScores.begin(); it != EasyScores.end(); ++it){
				printf("the scores in easy lists are: %f\n", *it);
				IwGxPrintString(190 * w / 320, (160 + counter * 23)* h / 480, doubleToStr(*it).c_str(), false);
				counter++;
				if (counter > 10) break;
			}
            Iw2DSurfaceShow();
        }
		if (stage == 8){
			Iw2DInit();
			int w = Iw2DGetSurfaceWidth();
			int h = Iw2DGetSurfaceHeight();
			double g = (double)w / 320;
			stage = MediumM(ScoresBg, MedTitle, BackBt, BackBtC, EasyScoresBt, EasyScoresBtC, MedScoresBt, MedScoresBtC, HardScoresBt, HardScoresBtC);
			printf("in stage 8 \n");
			Iw2DDrawImage(TimerOverlay, CIwFVec2(0, 150 * h / 480), CIwFVec2(320 * g, 270 * h / 480));
			int counter = 1;
			IwGxPrintSetScale(2 * fontsizeScale);
			IwGxPrintSetColour(255, 255, 255);
			IwGxPrintString(50 * w / 320, 155 * h / 480, "Rank", false);
			IwGxPrintString(190 * w / 320, 155 * h / 480, "Time", false);
			for (int i = 1; i <= 10; i++){
				if (i != 10){
					IwGxPrintString(70 * w / 320, (160 + i * 23)* h / 480, doubleToStr(i).c_str(), false);
				}
				else {
					IwGxPrintString(60 * w / 320, (160 + i * 23)* h / 480, doubleToStr(i).c_str(), false);
				}
			}
			for (it = MediumScores.begin(); it != MediumScores.end(); ++it){
				printf("the scores in easy lists are: %f\n", *it);
				IwGxPrintString(190 * w / 320, (160 + counter * 23)* h / 480, doubleToStr(*it).c_str(), false);
				counter++;
				if (counter > 10) break;
			}
			Iw2DSurfaceShow();
		}
		if (stage == 9){
			Iw2DInit();
			int w = Iw2DGetSurfaceWidth();
			int h = Iw2DGetSurfaceHeight();
			double g = (double)w / 320;
			stage = HardM(ScoresBg, HardTitle, BackBt, BackBtC, EasyScoresBt, EasyScoresBtC, MedScoresBt, MedScoresBtC, HardScoresBt, HardScoresBtC);
			printf("in stage 9 \n");
			Iw2DDrawImage(TimerOverlay, CIwFVec2(0, 150 * h / 480), CIwFVec2(320 * g, 270 * h / 480));
			int counter = 1;
			IwGxPrintSetScale(2 * fontsizeScale);
			IwGxPrintSetColour(255, 255, 255);
			IwGxPrintString(50 * w / 320, 155 * h / 480, "Rank", false);
			IwGxPrintString(190 * w / 320, 155 * h / 480, "Time", false);
			for (int i = 1; i <= 10; i++){
				if (i != 10){
					IwGxPrintString(70 * w / 320, (160 + i * 23)* h / 480, doubleToStr(i).c_str(), false);
				}
				else {
					IwGxPrintString(60 * w / 320, (160 + i * 23)* h / 480, doubleToStr(i).c_str(), false);
				}
			}
			for (it = HardScores.begin(); it != HardScores.end(); ++it){
				printf("the scores in easy lists are: %f\n", *it);
				IwGxPrintString(190 * w / 320, (160 + counter * 23)* h / 480, doubleToStr(*it).c_str(), false);
				counter++;
				if (counter > 10) break;
			}
			Iw2DSurfaceShow();
		}
		


		// Sleep to allow the OS to process events etc.
		s3eDeviceYield(0);
	}

	// Shut down Iw2D
	//delete image;
	//delete g_pInput;
	Iw2DTerminate();

}

