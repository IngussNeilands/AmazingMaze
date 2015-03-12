#ifndef __MENU_H__
#define __MENU_H__

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


int StartM(CIw2DImage* StartBg, CIw2DImage* PlayBt, CIw2DImage* PlayBtC , CIw2DImage* StartTitle, CIw2DImage* ScoresBt, CIw2DImage* ScoresBtC);
int LevelM(CIw2DImage* LevelBg, CIw2DImage* LevelTitle, CIw2DImage* BackBt, CIw2DImage* BackBtC,
	CIw2DImage* EasyBt, CIw2DImage* EasyBtC, CIw2DImage* MedBt, CIw2DImage* MedBtC, CIw2DImage* HardBt, CIw2DImage*HardBtC);
int InGameM(CIw2DImage* PauseBt, CIw2DImage* PauseBtC, CIw2DImage* BG, int currentLevel);
int PauseM(CIw2DImage* PausedBg, CIw2DImage* PausedTitle, CIw2DImage* ResumeBt, CIw2DImage* ResumeBtC,
	CIw2DImage* StartOverBt, CIw2DImage* StartOverBtC, CIw2DImage* ChangeLevelBt, CIw2DImage* ChangeLevelBtC);
int PostM(CIw2DImage* PostBg, CIw2DImage* PostTitle, CIw2DImage* RetryBt, CIw2DImage* RetryBtC,
          CIw2DImage* ChangeLevelBt, CIw2DImage* ChangeLevelBtC, CIw2DImage* MainMenuBt, CIw2DImage* MainMenuBtC);

int EasyM(CIw2DImage* EasyBg, CIw2DImage* EasyTitle, CIw2DImage* BackBt, CIw2DImage* BackBtC, CIw2DImage* EasyScoresBt, CIw2DImage* EasyScoresBtC, CIw2DImage* MedScoresBt, CIw2DImage* MedScoresBtC, CIw2DImage* HardScoresBt, CIw2DImage*HardScoresBtC);
int MediumM(CIw2DImage* EasyBg, CIw2DImage* EasyTitle, CIw2DImage* BackBt, CIw2DImage* BackBtC, CIw2DImage* EasyScoresBt, CIw2DImage* EasyScoresBtC, CIw2DImage* MedScoresBt, CIw2DImage* MedScoresBtC, CIw2DImage* HardScoresBt, CIw2DImage*HardScoresBtC);
int HardM(CIw2DImage* EasyBg, CIw2DImage* EasyTitle, CIw2DImage* BackBt, CIw2DImage* BackBtC, CIw2DImage* EasyScoresBt, CIw2DImage* EasyScoresBtC, CIw2DImage* MedScoresBt, CIw2DImage* MedScoresBtC, CIw2DImage* HardScoresBt, CIw2DImage*HardScoresBtC);



#endif