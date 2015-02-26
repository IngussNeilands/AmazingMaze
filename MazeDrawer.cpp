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

//float level[9][20][15];  //a 3D arrway that stores the parent, door leftpt, blockpt, and childs					//0 = parent, 1 = leftpt, 2 = block, 3 = blockleft, 4 = blockright, 5 = childamount, 6-10 = childs
//int MaxLevel;  // MaxLevel is set based on the difficulity


void printall(){
	for (int leveler = 1; leveler <= MaxLevel; leveler++){
		for (int door = 0; door < 20; door++){

			float block = level[leveler][door][2];
			if (block > -1){
				    printf("---Max Level = %i [%i][%i][1]: leftpt = %f  block = %f parent = %f  childnm = %f blockleft = %f blockright = %f\n",
					MaxLevel, leveler, door, level[leveler][door][1], level[leveler][door][2], level[leveler][door][0], level[leveler][door][5], level[leveler][door][3], level[leveler][door][4]);
			}
		}
	}
}

void DrawMaze(int curLevel){
	Iw2DInit();
	int surface_width = Iw2DGetSurfaceWidth();
	int surface_height = Iw2DGetSurfaceHeight();
	for (int leveler = 1; leveler <= curLevel; leveler++){
		int levelamount = curLevel + 1;
		if (curLevel == MaxLevel) levelamount = curLevel;
		float drawWidth = (surface_width - 30)/2;
		if (curLevel == MaxLevel) drawWidth = drawWidth - 30;
		float avgWidth = drawWidth / levelamount;
		float radius = avgWidth * leveler;
		//printf("radius ========= %f", radius);
		Iw2DSetColour(0xff66ff66);
		if (leveler <= MaxLevel){
			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(radius, radius), 0, 2 * PI);
			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(radius + 1, radius + 1), 0, 2 * PI);
			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(radius - 1, radius - 1), 0, 2 * PI);
		}
		if (leveler == curLevel && leveler<MaxLevel){
			radius = avgWidth * (leveler + 1);
			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(radius, radius), 0, 2 * PI);
			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(radius + 1, radius + 1), 0, 2 * PI);
			Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height  / 2), CIwFVec2(radius - 1, radius - 1), 0, 2 * PI);
		}
	}
	for (int leveler = 1; leveler <= curLevel; leveler++){
		int levelamount = curLevel + 1;
		if (curLevel == MaxLevel) levelamount = curLevel;
		float drawWidth = (surface_width - 30) / 2;
		if (curLevel == MaxLevel) drawWidth = drawWidth - 30;
		float avgWidth = drawWidth / levelamount;
		float radius = avgWidth * leveler;
		float radius2 = avgWidth * (leveler + 1);
		float doorsize = 0.3;
		if (leveler == 1) doorsize = 0.3;
		if (leveler == 2) doorsize = 0.2;
		if (leveler == 3) doorsize = 0.1333;
		if (leveler == 4) doorsize = 0.088866667;
		if (leveler == 5) doorsize = 0.059244;
		if (leveler == 6) doorsize = 0.039496;
		if (leveler == 7) doorsize = 0.04;
		for (int door = 0; door < 20; door++){
			float leftpt = level[leveler][door][1];
			float block = level[leveler][door][2];
			if (block > -1){
				//if (printed == 0) printf("Max Level = %i [%i][%i][1]: leftpt = %f  block = %f parent = %f  chlidnm = %f blockleft = %f blockright = %f\n", 
				//MaxLevel, leveler, door, level[leveler][door][1], level[leveler][door][2], level[leveler][door][0], level[leveler][door][5], level[leveler][door][3], level[leveler][door][4]);
				float pt1x = radius * sin(level[leveler][door][2]);
				float pt1y = radius * cos(level[leveler][door][2]);
				float pt2x = radius2 * sin(level[leveler][door][2]);
				float pt2y = radius2 * cos(level[leveler][door][2]);

				Iw2DSetColour(0xff000000);
				Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(radius, radius), leftpt, leftpt + doorsize);
				Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(radius + 1, radius + 1), leftpt, leftpt + doorsize);
				Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(radius - 1, radius - 1), leftpt, leftpt + doorsize);
				if (leveler != MaxLevel){
					Iw2DSetColour(0xff66ff66);
					Iw2DDrawLine(CIwFVec2(surface_width / 2 + pt1x, surface_height / 2 - pt1y), CIwFVec2(surface_width / 2 + pt2x, surface_height / 2 - pt2y));
				}
			}
		}
	}

	//Iw2DSurfaceShow();

}