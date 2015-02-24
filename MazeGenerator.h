#ifndef __MAZEGENERATOR_H__
#define __MAZEGENERATOR_H__

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

extern float level[9][20][15];  //a 3D arrway that stores the parent, door leftpt, blockpt, and childs					//0 = parent, 1 = leftpt, 2 = block, 3 = blockleft, 4 = blockright, 5 = childamount, 6-10 = childs
extern int MaxLevel;  // MaxLevel is set based on the difficulity

void MazeInitializer();
int setDifficulity(int difficulity);
int DoorGenerator();
int AssignParentChild(int curlevel, int prevDoorAmount);
void BlockGenerator(int curlevel, int doors);


#endif