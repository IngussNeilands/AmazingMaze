#ifndef __PLAYERMOVEMENT_H__
#define __PLAYERMOVEMENT_H__

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


float DrawPlayer(int curLevel, float angle, CIw2DImage* player);
int PlayerMove(int curLevel, float angle, CIw2DImage* InBt, CIw2DImage* InBtC, CIw2DImage* OutBt, CIw2DImage* OutBtC);
int moveUp(int currentLevel, float angle);
int moveDown(int currentLevel, float angle);
#endif