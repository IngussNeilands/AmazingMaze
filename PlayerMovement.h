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


float DrawPlayer(int curLevel, float angle, CIw2DImage* player, CIw2DImage* InBt);
int moveUp(int curLevel, float angle);
int moveDown(int curLevel, float angle);
#endif