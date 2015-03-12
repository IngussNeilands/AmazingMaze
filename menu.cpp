#include "Iw2D.h"
#include "s3ePointer.h"
#include "IwResManager.h"
#include "s3eKeyboard.h"
#include "Iw2DSceneGraph.h"
#include "math.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;
#include "MazeGenerator.h"
#include "PlayerMovement.h"

//int MaxLevel;  // MaxLevel is set based on the difficulity
int x = 0;
int y = 0;

int StartM(CIw2DImage* StartBg, CIw2DImage* PlayBt, CIw2DImage* PlayBtC, CIw2DImage* StartTitle, CIw2DImage* ScoresBt, CIw2DImage* ScoresBtC){
	Iw2DInit();
	int w = Iw2DGetSurfaceWidth();
	int h = Iw2DGetSurfaceHeight();
	double g = (double)w / 320;
	int stage = 0;
	CIw2DImage* PBT = PlayBt;
	CIw2DImage* SBT = ScoresBt;
	if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) && S3E_POINTER_STATE_DOWN && stage == 0){
		x = s3ePointerGetX();
		y = s3ePointerGetY();
		//printf("x = %i y = %i \n", x ,y);
		if (x > 0 && y > 200 * h / 480 && x < 320 * w / 320 && y < 300 * h / 480) PBT = PlayBtC;
		if (x > 0 && y > 325 * h / 480 && x < 320 * w / 320 && y < 425 * h / 480) SBT = ScoresBtC;
	}
	else{
		if (x > 0 && y > 200 * h / 480 && x < 320 * w / 320 && y < 300 * h / 480 && stage == 0) stage = 1;
		if (x > 0 && y > 325 * h / 480 && x < 320 * w / 320 && y < 425 * h / 480 && stage == 0) stage = 7;
		x = 0;
		y = 0;
	}
	Iw2DDrawImage(StartBg, CIwFVec2(0, 0), CIwFVec2(w, h));
	Iw2DDrawImage(StartTitle, CIwFVec2(5 * w / 320, 25 * h / 480), CIwFVec2(315 * g, 170 * h / 480));
	Iw2DDrawImage(PBT, CIwFVec2(-130 * w / 320, 200 * h / 480), CIwFVec2(575 * g, 100 * h / 480));
	Iw2DDrawImage(SBT, CIwFVec2(-130 * w / 320, 325 * h / 480), CIwFVec2(575 * g, 100 * h / 480));
	return stage;
}

int LevelM(CIw2DImage* LevelBg, CIw2DImage* LevelTitle, CIw2DImage* BackBt, CIw2DImage* BackBtC,
	CIw2DImage* EasyBt, CIw2DImage* EasyBtC, CIw2DImage* MedBt, CIw2DImage* MedBtC, CIw2DImage* HardBt, CIw2DImage*HardBtC){
	Iw2DInit();
	int w = Iw2DGetSurfaceWidth();
	int h = Iw2DGetSurfaceHeight();
	double g = (double)w / 320;
	CIw2DImage* BBT = BackBt;
	CIw2DImage* EBT = EasyBt;
	CIw2DImage* MBT = MedBt;
	CIw2DImage* HBT = HardBt;
	int stage = 1;
	MazeInitializer();
	if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) && S3E_POINTER_STATE_DOWN && stage == 1){
		x = s3ePointerGetX();
		y = s3ePointerGetY();
		if (x > 5 * w / 320 && y > 5 * h / 480 && x < 80 * w / 320 && y < 45 * h / 480 && stage == 1)	BBT = BackBtC;
		if (x > 60 * w / 320 && y > 155 * h / 480 && x < 260 * w / 320 && y < 245 * h / 480 && stage == 1) EBT = EasyBtC;
		if (x > 60 * w / 320 && y > 255 * h / 480 && x < 260 * w / 320 && y < 345 * h / 480 && stage == 1) MBT = MedBtC;
		if (x > 60 * w / 320 && y > 355 * h / 480 && x < 260 * w / 320 && y < 445 * h / 480 && stage == 1) HBT = HardBtC;
	}
	else{
		if (x > 5 * w / 320 && y > 5 * h / 480 && x < 80 * w / 320 && y < 45 * h / 480 && stage == 1) stage = 0;  //Back to StartM
		if (x > 60 * w / 320 && y > 155 * h / 480 && x < 260 * w / 320 && y < 245 * h / 480 && stage == 1) {   //Easy Stage
			MazeInitializer();
			setDifficulity(1);
			DoorGenerator();
			stage = 2;
		}
		if (x > 60 * w / 320 && y > 255 * h / 480 && x < 260 * w / 320 && y < 345 * h / 480 && stage == 1) {   //Medium Stage
			MazeInitializer();
			setDifficulity(2);
			DoorGenerator();
			stage = 2;
		}
		if (x > 60 * w / 320 && y > 355 * h / 480 && x < 260 * w / 320 && y < 445 * h / 480 && stage == 1) {   //Hard Stage
			MazeInitializer();
			setDifficulity(3);
			DoorGenerator();
			stage = 2;
		}
		x = 0;
		y = 0; // ?
	}
	Iw2DDrawImage(LevelBg, CIwFVec2(0, 0), CIwFVec2(w, h));
	Iw2DDrawImage(BBT, CIwFVec2(5 * w / 320, 5 * h / 480), CIwFVec2(75 * g, 40 * g));
	Iw2DDrawImage(LevelTitle, CIwFVec2(36 * w / 320, 40 * h / 480), CIwFVec2(250 * g, 110 * h / 480));
	Iw2DDrawImage(EBT, CIwFVec2(60 * w / 320, 155 * h / 480), CIwFVec2(200 * g, 90 * h / 480));
	Iw2DDrawImage(MBT, CIwFVec2(60 * w / 320, 255 * h / 480), CIwFVec2(200 * g, 90 * h / 480));
	Iw2DDrawImage(HBT, CIwFVec2(60 * w / 320, 355 * h / 480), CIwFVec2(200 * g, 90 * h / 480));
	return stage;
}

int InGameM(CIw2DImage* PauseBt, CIw2DImage* PauseBtC, CIw2DImage* BG, int currentLevel){
	Iw2DInit();
	int w = Iw2DGetSurfaceWidth();
	int h = Iw2DGetSurfaceHeight();
	double g = (double)w / 320;
	CIw2DImage* PBT = PauseBt;
	int stage = 2;
	if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) && S3E_POINTER_STATE_DOWN && stage == 2){
		x = s3ePointerGetX();
		y = s3ePointerGetY();
		if (x > 284 * w / 320 && y > 0 && x < 320 * w / 320 && y < 36 * h / 480 && stage == 2) PBT = PauseBtC;
	}
	else{
		if (x > 284 * w / 320 && y > 0 && x < 320 * w / 320 && y < 36 * h / 480 && stage == 2) stage = 3;
		x = 0;
		y = 0;
		if (currentLevel == MaxLevel + 1) stage = 4;
	}
	Iw2DDrawImage(BG, CIwFVec2(0, 0), CIwFVec2( w, h));
	Iw2DDrawImage(PBT, CIwFVec2(284 * w / 320, 0), CIwFVec2(36 * g, 36 * h / 480));
	return stage;
}

int PauseM(CIw2DImage* PausedBg, CIw2DImage* PausedTitle, CIw2DImage* ResumeBt, CIw2DImage* ResumeBtC,
	CIw2DImage* StartOverBt, CIw2DImage* StartOverBtC, CIw2DImage* ChangeLevelBt, CIw2DImage* ChangeLevelBtC){
	Iw2DInit();
	int w = Iw2DGetSurfaceWidth();
	int h = Iw2DGetSurfaceHeight();
	double g = (double)w / 320;
	CIw2DImage* RBT = ResumeBt;
	CIw2DImage* SOBT = StartOverBt;
	CIw2DImage* CLBT = ChangeLevelBt;
	int stage = 3;
	if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) && S3E_POINTER_STATE_DOWN && stage == 3){
		x = s3ePointerGetX();
		y = s3ePointerGetY();
		if (x > 36 * w / 320 && y > 95 * h / 480 && x < 286 * w / 320 && y < 175 * h / 480 && stage == 3) RBT = ResumeBtC;
		if (x > 36 * w / 320 && y > 185 * h / 480 && x < 286 * w / 320 && y < 305 * h / 480 && stage == 3) SOBT = StartOverBtC;
		if (x > 36 * w / 320 && y > 315 * h / 480 && x < 286 * w / 320 && y < 435 * h / 480 && stage == 3) CLBT = ChangeLevelBtC;
	}
	else{
		//printf(" x = %i, y = %i \n", x, y);
		if (x > 36 * w / 320 && y > 95 * h / 480 && x < 286 * w / 320 && y < 175 * h / 480 && stage == 3) stage = 2;
		if (x > 36 * w / 320 && y > 185 * h / 480 && x < 286 * w / 320 && y < 305 * h / 480 && stage == 3) stage = 5;
		if (x > 36 * w / 320 && y > 315 * h / 480 && x < 286 * w / 320 && y < 435 * h / 480 && stage == 3) stage = 1;
		x = 0;
		y = 0;
	}
	Iw2DDrawImage(PausedBg, CIwFVec2(0, 0), CIwFVec2(w, h));
	Iw2DDrawImage(PausedTitle, CIwFVec2(36 * w / 320, 10 * h / 480), CIwFVec2(250 * g, 80 * h / 480));
	Iw2DDrawImage(RBT, CIwFVec2(36 * w / 320, 95 * h / 480), CIwFVec2(250 * g, 80 * h / 480));
	Iw2DDrawImage(SOBT, CIwFVec2(36 * w / 320, 185 * h / 480), CIwFVec2(250 * g, 120 * h / 480));
	Iw2DDrawImage(CLBT, CIwFVec2(36 * w / 320, 315 * h / 480), CIwFVec2(250 * g, 120 * h / 480));
	return stage;
}

int PostM(CIw2DImage* PostBg, CIw2DImage* PostTitle, CIw2DImage* RetryBt, CIw2DImage* RetryBtC,
          CIw2DImage* ChangeLevelBt, CIw2DImage* ChangeLevelBtC, CIw2DImage* MainMenuBt, CIw2DImage* MainMenuBtC){
	Iw2DInit();
	int w = Iw2DGetSurfaceWidth();
	int h = Iw2DGetSurfaceHeight();
	double g = (double)w / 320;
    CIw2DImage* RBT = RetryBt;
    CIw2DImage* CLBT = ChangeLevelBt;
    CIw2DImage* MMBT = MainMenuBt;
    int stage = 4;
    if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) && S3E_POINTER_STATE_RELEASED && stage == 4){
        x = s3ePointerGetX();
        y = s3ePointerGetY();
		if (x > 60 * w / 320 && y > 180 * h / 480 && x < 260 * w / 320 && y < 247 * h / 480 && stage == 4) RBT = RetryBtC;
		if (x > 60 * w / 320 && y > 255 * h / 480 && x < 260 * w / 320 && y < 345 * h / 480 && stage == 4) CLBT = ChangeLevelBtC;
		if (x > 60 * w / 320 && y > 355 * h / 480 && x < 260 * w / 320 && y < 445 * h / 480 && stage == 4) MMBT = MainMenuBtC;
    }
    else{
		if (x > 60 * w / 320 && y > 180 * h / 480 && x < 260 * w / 320 && y < 247 * h / 480 && stage == 4) stage = 5;
		if (x > 60 * w / 320 && y > 255 * h / 480 && x < 260 * w / 320 && y < 345 * h / 480 && stage == 4) stage = 1;
		if (x > 60 * w / 320 && y > 355 * h / 480 && x < 260 * w / 320 && y < 445 * h / 480 && stage == 4) stage = 0;
        x = 0;
        y = 0;
    }
	Iw2DDrawImage(PostBg, CIwFVec2(0, 0), CIwFVec2(w, h));
	Iw2DDrawImage(PostTitle, CIwFVec2(15 * w / 320, 15 * h / 480), CIwFVec2(285 * g, 55 * h / 480));
	Iw2DDrawImage(RBT, CIwFVec2(60 * w / 320, 180 * h / 480), CIwFVec2(200 * g, 67 * h / 480));
	Iw2DDrawImage(CLBT, CIwFVec2(60 * w / 320, 255 * h / 480), CIwFVec2(200 * g, 90 * h / 480));
	Iw2DDrawImage(MMBT, CIwFVec2(60 * w / 320, 355 * h / 480), CIwFVec2(200 * g, 90 * h / 480));
  
    return stage;
}

int EasyM(CIw2DImage* EasyBg, CIw2DImage* EasyTitle, CIw2DImage* BackBt, CIw2DImage* BackBtC,
	CIw2DImage* EasyScoresBt, CIw2DImage* EasyScoresBtC, CIw2DImage* MedScoresBt, CIw2DImage* MedScoresBtC,
	CIw2DImage* HardScoresBt, CIw2DImage*HardScoresBtC){
	Iw2DInit();
	int w = Iw2DGetSurfaceWidth();
	int h = Iw2DGetSurfaceHeight();
	double g = (double)w / 320;
    CIw2DImage* BBT = BackBt;
    CIw2DImage* EBT = EasyScoresBt;
    CIw2DImage* MBT = MedScoresBt;
    CIw2DImage* HBT = HardScoresBt;
    int stage = 7;
    if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) && S3E_POINTER_STATE_DOWN && stage == 7){
        x = s3ePointerGetX();
        y = s3ePointerGetY();
		if (x > 5 * w / 320 && y > 5 * h / 480 && x < 80 * w / 320 && y < 45 * h / 480 && stage == 7)   BBT = BackBtC;
		if (x > 5 * w / 320 && y > 425 * h / 480 && x < 105 * w / 320 && y < 470 * h / 480 && stage == 7) EBT = EasyScoresBtC;
		if (x > 110 * w / 320 && y > 425 * h / 480 && x < 210 * w / 320 && y < 470 * h / 480 && stage == 7) MBT = MedScoresBtC;
		if (x > 215 * w / 320 && y > 425 * h / 480 && x < 315 * w / 320 && y < 470 * h / 480 && stage == 7) HBT = HardScoresBtC;
    }
    else{
		if (x > 5 * w / 320 && y > 5 * h / 480 && x < 80 * w / 320 && y < 45 * h / 480 && stage == 7) stage = 0;  //Back to StartM
		if (x > 5 * w / 320 && y > 425 * h / 480 && x < 105 * w / 320 && y < 470 * h / 480 && stage == 7) stage = 7;
		if (x > 110 * w / 320 && y > 425 * h / 480 && x < 210 * w / 320 && y < 470 * h / 480 && stage == 7) stage = 8;
		if (x > 215 * w / 320 && y > 425 * h / 480 && x < 315 * w / 320 && y < 470 * h / 480 && stage == 7) stage = 9;
        x = 0;
        y = 0;
    }
	Iw2DDrawImage(EasyBg, CIwFVec2(0, 0), CIwFVec2(w, h));
	Iw2DDrawImage(BBT, CIwFVec2(5 * w / 320, 5 * h / 480), CIwFVec2(75 * g, 40 * h / 480));
	Iw2DDrawImage(EasyTitle, CIwFVec2(36 * w / 320, 40 * h / 480), CIwFVec2(250 * g, 110 * h / 480));
	Iw2DDrawImage(EBT, CIwFVec2(5 * w / 320, 425 * h / 480), CIwFVec2(100 * g, 45 * h / 480));
	Iw2DDrawImage(MBT, CIwFVec2(110 * w / 320, 425 * h / 480), CIwFVec2(100 * g, 45 * h / 480));
	Iw2DDrawImage(HBT, CIwFVec2(215 * w / 320, 425 * h / 480), CIwFVec2(100 * g, 45 * h / 480));
    return stage;
}
int MediumM(CIw2DImage* EasyBg, CIw2DImage* EasyTitle, CIw2DImage* BackBt, CIw2DImage* BackBtC,
	CIw2DImage* EasyScoresBt, CIw2DImage* EasyScoresBtC, CIw2DImage* MedScoresBt, CIw2DImage* MedScoresBtC,
	CIw2DImage* HardScoresBt, CIw2DImage*HardScoresBtC){
	Iw2DInit();
	int w = Iw2DGetSurfaceWidth();
	int h = Iw2DGetSurfaceHeight();
	double g = (double)w / 320;
	CIw2DImage* BBT = BackBt;
	CIw2DImage* EBT = EasyScoresBt;
	CIw2DImage* MBT = MedScoresBt;
	CIw2DImage* HBT = HardScoresBt;
	int stage = 8;
	if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) && S3E_POINTER_STATE_DOWN && stage == 8){
		x = s3ePointerGetX();
		y = s3ePointerGetY();
		if (x > 5 * w / 320 && y > 5 * h / 480 && x < 80 * w / 320 && y < 45 * h / 480 && stage == 8)   BBT = BackBtC;
		if (x > 5 * w / 320 && y > 425 * h / 480 && x < 105 * w / 320 && y < 470 * h / 480 && stage == 8) EBT = EasyScoresBtC;
		if (x > 110 * w / 320 && y > 425 * h / 480 && x < 210 * w / 320 && y < 470 * h / 480 && stage == 8) MBT = MedScoresBtC;
		if (x > 215 * w / 320 && y > 425 * h / 480 && x < 315 * w / 320 && y < 470 * h / 480 && stage == 8) HBT = HardScoresBtC;
	}
	else{
		if (x > 5 * w / 320 && y > 5 * h / 480 && x < 80 * w / 320 && y < 45 * h / 480 && stage == 8) stage = 0;  //Back to StartM
		if (x > 5 * w / 320 && y > 425 * h / 480 && x < 105 * w / 320 && y < 470 * h / 480 && stage == 8) stage = 7;
		if (x > 110 * w / 320 && y > 425 * h / 480 && x < 210 * w / 320 && y < 470 * h / 480 && stage == 8) stage = 8;
		if (x > 215 * w / 320 && y > 425 * h / 480 && x < 315 * w / 320 && y < 470 * h / 480 && stage == 8) stage = 9;
		x = 0;
		y = 0;
	}
	Iw2DDrawImage(EasyBg, CIwFVec2(0, 0), CIwFVec2(w, h));
	Iw2DDrawImage(BBT, CIwFVec2(5 * w / 320, 5 * h / 480), CIwFVec2(75 * g, 40 * h / 480));
	Iw2DDrawImage(EasyTitle, CIwFVec2(36 * w / 320, 40 * h / 480), CIwFVec2(250 * g, 110 * h / 480));
	Iw2DDrawImage(EBT, CIwFVec2(5 * w / 320, 425 * h / 480), CIwFVec2(100 * g, 45 * h / 480));
	Iw2DDrawImage(MBT, CIwFVec2(110 * w / 320, 425 * h / 480), CIwFVec2(100 * g, 45 * h / 480));
	Iw2DDrawImage(HBT, CIwFVec2(215 * w / 320, 425 * h / 480), CIwFVec2(100 * g, 45 * h / 480));
	return stage;
}
int HardM(CIw2DImage* EasyBg, CIw2DImage* EasyTitle, CIw2DImage* BackBt, CIw2DImage* BackBtC,
	CIw2DImage* EasyScoresBt, CIw2DImage* EasyScoresBtC, CIw2DImage* MedScoresBt, CIw2DImage* MedScoresBtC,
	CIw2DImage* HardScoresBt, CIw2DImage*HardScoresBtC){
	Iw2DInit();
	int w = Iw2DGetSurfaceWidth();
	int h = Iw2DGetSurfaceHeight();
	double g = (double)w / 320;
	CIw2DImage* BBT = BackBt;
	CIw2DImage* EBT = EasyScoresBt;
	CIw2DImage* MBT = MedScoresBt;
	CIw2DImage* HBT = HardScoresBt;
	int stage = 9;
	if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) && S3E_POINTER_STATE_DOWN && stage == 9){
		x = s3ePointerGetX();
		y = s3ePointerGetY();
		if (x > 5 * w / 320 && y > 5 * h / 480 && x < 80 * w / 320 && y < 45 * h / 480 && stage == 9)   BBT = BackBtC;
		if (x > 5 * w / 320 && y > 425 * h / 480 && x < 105 * w / 320 && y < 470 * h / 480 && stage == 9) EBT = EasyScoresBtC;
		if (x > 110 * w / 320 && y > 425 * h / 480 && x < 210 * w / 320 && y < 470 * h / 480 && stage == 9) MBT = MedScoresBtC;
		if (x > 215 * w / 320 && y > 425 * h / 480 && x < 315 * w / 320 && y < 470 * h / 480 && stage == 9) HBT = HardScoresBtC;
	}
	else{
		if (x > 5 * w / 320 && y > 5 * h / 480 && x < 80 * w / 320 && y < 45 * h / 480 && stage == 9) stage = 0;  //Back to StartM
		if (x > 5 * w / 320 && y > 425 * h / 480 && x < 105 * w / 320 && y < 470 * h / 480 && stage == 9) stage = 7;
		if (x > 110 * w / 320 && y > 425 * h / 480 && x < 210 * w / 320 && y < 470 * h / 480 && stage == 9) stage = 8;
		if (x > 215 * w / 320 && y > 425 * h / 480 && x < 315 * w / 320 && y < 470 * h / 480 && stage == 9) stage = 9;
		x = 0;
		y = 0;
	}
	Iw2DDrawImage(EasyBg, CIwFVec2(0, 0), CIwFVec2(w, h));
	Iw2DDrawImage(BBT, CIwFVec2(5 * w / 320, 5 * h / 480), CIwFVec2(75 * g, 40 * h / 480));
	Iw2DDrawImage(EasyTitle, CIwFVec2(36 * w / 320, 40 * h / 480), CIwFVec2(250 * g, 110 * h / 480));
	Iw2DDrawImage(EBT, CIwFVec2(5 * w / 320, 425 * h / 480), CIwFVec2(100 * g, 45 * h / 480));
	Iw2DDrawImage(MBT, CIwFVec2(110 * w / 320, 425 * h / 480), CIwFVec2(100 * g, 45 * h / 480));
	Iw2DDrawImage(HBT, CIwFVec2(215 * w / 320, 425 * h / 480), CIwFVec2(100 * g, 45 * h / 480));
	return stage;
}






