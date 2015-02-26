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

int MaxLevel;  // MaxLevel is set based on the difficulity
int x = 0;
int y = 0;

int StartM(CIw2DImage* StartBg, CIw2DImage* PlayBt, CIw2DImage* PlayBtC , CIw2DImage* StartTitle){
	int stage = 0;
	CIw2DImage* PBT = PlayBt;
	if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) && S3E_POINTER_STATE_DOWN && stage == 0){
		x = s3ePointerGetX();
		y = s3ePointerGetY();
		//printf("x = %i y = %i \n", x ,y);
		if (x > 45 && y > 266 && x < 270 && y < 341) PBT = PlayBtC;
	}
	else{
		if (x > 45 && y > 266 && x < 270 && y < 341 && stage == 0) stage = 1;
		x = 0;
		y = 0;
	} 
	Iw2DDrawImage(StartBg, CIwFVec2(0, 0), CIwFVec2(320, 492));
	Iw2DDrawImage(StartTitle, CIwFVec2(5, 66), CIwFVec2(315, 170));
	Iw2DDrawImage(PBT, CIwFVec2(45, 266), CIwFVec2(225, 75));
	return stage;
}

int LevelM(CIw2DImage* LevelBg, CIw2DImage* LevelTitle, CIw2DImage* BackBt, CIw2DImage* BackBtC,
	CIw2DImage* EasyBt, CIw2DImage* EasyBtC, CIw2DImage* MedBt, CIw2DImage* MedBtC, CIw2DImage* HardBt, CIw2DImage*HardBtC){
	CIw2DImage* BBT = BackBt;
	CIw2DImage* EBT = EasyBt;
	CIw2DImage* MBT = MedBt;
	CIw2DImage* HBT = HardBt;
	int stage = 1;
	MazeInitializer();
	if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) && S3E_POINTER_STATE_DOWN && stage == 1){
		x = s3ePointerGetX();
		y = s3ePointerGetY();
		if (x > 5 && y > 5 && x < 80 && y < 45 && stage == 1)	BBT = BackBtC;
		if (x > 60 && y > 155 && x < 260 && y < 245 && stage == 1) EBT = EasyBtC;
		if (x > 60 && y > 255 && x < 260 && y < 345 && stage == 1) MBT = MedBtC;
		if (x > 60 && y > 355 && x < 260 && y < 445 && stage == 1) HBT = HardBtC;
	}
	else{
		if (x > 5 && y > 5 && x < 80 && y < 45 && stage == 1) stage = 0;  //Back to StartM
		if (x > 60 && y > 155 && x < 260 && y < 245 && stage == 1) {   //Easy Stage
			MazeInitializer();
			setDifficulity(1);
			DoorGenerator();
			stage = 2;
		}
		if (x > 60 && y > 255 && x < 260 && y < 345 && stage == 1) {   //Medium Stage
			MazeInitializer();
			setDifficulity(2);
			DoorGenerator();
			stage = 2;
		}
		if (x > 60 && y > 355 && x < 260 && y < 445 && stage == 1) {   //Hard Stage
			MazeInitializer();
			setDifficulity(3);
			DoorGenerator();
			stage = 2;
		}
		x = 0;
		y = 0; // ?
	}
	Iw2DDrawImage(LevelBg, CIwFVec2(0, 0), CIwFVec2(320, 492));
	Iw2DDrawImage(BBT, CIwFVec2(5, 5), CIwFVec2(75, 40));
	Iw2DDrawImage(LevelTitle, CIwFVec2(36, 40), CIwFVec2(250, 110));
	Iw2DDrawImage(EBT, CIwFVec2(60, 155), CIwFVec2(200, 90));
	Iw2DDrawImage(MBT, CIwFVec2(60, 255), CIwFVec2(200, 90));
	Iw2DDrawImage(HBT, CIwFVec2(60, 355), CIwFVec2(200, 90));
	return stage;
}

int InGameM(CIw2DImage* PauseBt, CIw2DImage* PauseBtC){
	CIw2DImage* PBT = PauseBt;
	int stage = 2;
	if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) && S3E_POINTER_STATE_DOWN && stage == 2){
		x = s3ePointerGetX();
		y = s3ePointerGetY();
		if (x > 165 && y > 5 && x < 315 && y < 55 && stage == 2) PBT = PauseBtC;
	}
	else{
		if (x > 165 && y > 5 && x < 315 && y < 55 && stage == 2) stage = 3;
		x = 0;
		y = 0;
	}
	Iw2DDrawImage(PBT, CIwFVec2(213 , 5), CIwFVec2(108, 36));
	return stage;
}

int PauseM(CIw2DImage* PausedBg, CIw2DImage* PausedTitle, CIw2DImage* ResumeBt, CIw2DImage* ResumeBtC,
	CIw2DImage* StartOverBt, CIw2DImage* StartOverBtC, CIw2DImage* ChangeLevelBt, CIw2DImage* ChangeLevelBtC){
	CIw2DImage* RBT = ResumeBt;
	CIw2DImage* SOBT = StartOverBt;
	CIw2DImage* CLBT = ChangeLevelBt;
	int stage = 3;
	if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) && S3E_POINTER_STATE_DOWN && stage == 3){
		x = s3ePointerGetX();
		y = s3ePointerGetY();
		if (x > 36 && y > 95 && x < 286 && y < 175 && stage == 3) RBT = ResumeBtC;
		if (x > 36 && y > 185 && x < 286 && y < 305 && stage == 3) SOBT = StartOverBtC;
		if (x > 36 && y > 315 && x < 286 && y < 435 && stage == 3) CLBT = ChangeLevelBtC;
	}
	else{
		printf(" x = %i, y = %i \n", x, y);
		if (x > 36 && y > 95 && x < 286 && y < 175 && stage == 3) stage = 2;
		if (x > 36 && y > 185 && x < 286 && y < 305 && stage == 3) stage = 5;
		if (x > 36 && y > 315 && x < 286 && y < 435 && stage == 3) stage = 1;
		x = 0;
		y = 0;
	}
	Iw2DDrawImage(PausedBg, CIwFVec2(0, 0), CIwFVec2(320, 492));
	Iw2DDrawImage(PausedTitle, CIwFVec2(36, 10), CIwFVec2(250, 80));
	Iw2DDrawImage(RBT, CIwFVec2(36, 95), CIwFVec2(250, 80));
	Iw2DDrawImage(SOBT, CIwFVec2(36, 185), CIwFVec2(250, 120));
	Iw2DDrawImage(CLBT, CIwFVec2(36, 315), CIwFVec2(250, 120));
	return stage;
}

int PostM(){
	return 0;
}





