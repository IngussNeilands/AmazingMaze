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

void DrawMaze(int curLevel, CIw2DImage* Color[8], CIw2DImage* bg, CIw2DImage* Overlay){
	Iw2DInit();
	CIw2DImage* Circle = Color[1];
	int surface_width = Iw2DGetSurfaceWidth();
	int surface_height = Iw2DGetSurfaceHeight();
	for (int leveler = 1; leveler <= curLevel; leveler++){
		Circle = Color[leveler];
		int levelamount = curLevel + 1;
		if (curLevel == MaxLevel) levelamount = curLevel;
		float drawWidth = (surface_width - 30 * surface_width/320)/2;
		if (curLevel == MaxLevel) drawWidth = drawWidth - 30 * surface_width / 320;
		float avgWidth = drawWidth / levelamount;
		float radius = avgWidth * leveler;
		float radius2 = radius + 2;
		float X = surface_width / 2 - radius2;
		float Y = surface_height / 2 - radius2;
		//printf("radius ========= %f", radius);
		Iw2DSetColour(0xffffffff);
		if (leveler <= MaxLevel){
				Iw2DDrawImage(Circle, CIwFVec2(X, Y), CIwFVec2(radius2 * 2, radius2 * 2));  // draw the walls
			//Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(radius, radius), 0, 2 * PI);
			//Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(radius + 1, radius + 1), 0, 2 * PI);
			//Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(radius - 1, radius - 1), 0, 2 * PI);
		}
		if (leveler == curLevel && leveler<MaxLevel){
			radius = avgWidth * (leveler + 1);
			radius2 = radius + 2;
			X = surface_width / 2 - radius;
			Y = surface_height / 2 - radius;
			Circle = Color[leveler + 1];
			Iw2DDrawImage(Circle, CIwFVec2(X, Y), CIwFVec2(radius2 * 2, radius2 * 2));  // draw the most outside wall
			//Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(radius, radius), 0, 2 * PI);
			//Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(radius + 1, radius + 1), 0, 2 * PI);
			//Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height  / 2), CIwFVec2(radius - 1, radius - 1), 0, 2 * PI);
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
		for (int door = 0; door < 10; door++){
			float leftpt = level[leveler][door][1];
			float block = level[leveler][door][2];
			//printf("radius = %f", radius);
			if (block > -1){ 
				//if (printed == 0) printf("Max Level = %i [%i][%i][1]: leftpt = %f  block = %f parent = %f  chlidnm = %f blockleft = %f blockright = %f\n", 
				//MaxLevel, leveler, door, level[leveler][door][1], level[leveler][door][2], level[leveler][door][0], level[leveler][door][5], level[leveler][door][3], level[leveler][door][4]);
				for (float x = 0; x < doorsize; x = x + 0.005){
					for (float y = -7; y <= 7; y = y + 1){
						//printf("x = %f, y = %f \n", x, y);
						Iw2DSetColour(0xffffffff);
						float xx = (radius + y) * sin(level[leveler][door][1] + x);
						float yy = (radius + y) * cos(level[leveler][door][1] + x);
						Iw2DDrawImageRegion(bg, CIwFVec2((surface_width / 2 + xx), (surface_height / 2 - yy)), CIwFVec2((320 / 2 + xx), (480 / 2 - yy)), CIwFVec2(1.5, 1.5));
						//Iw2DDrawImageRegion(Overlay, CIwFVec2(surface_width / 2 + xx, surface_height / 2 - yy), CIwFVec2(surface_width / 2 + xx, surface_height / 2 - yy), CIwFVec2(1, 1));
						//Iw2DSetColour(0xff66ff66);
						//Iw2DDrawRect(CIwFVec2(surface_width /2+ xx, surface_height /2- yy), CIwFVec2(1, 1));
					}

				}
				if (leveler != MaxLevel){
					for (float w = -0.02; w <= 0.02; w = w + 0.002){
						float radiushalf = (radius2 + radius) / 2;
						float pt1x = radius * sin(level[leveler][door][2] + w);
						float pt1y = radius * cos(level[leveler][door][2] + w);
						float pt2x = radiushalf * sin(level[leveler][door][2] + w);
						float pt2y = radiushalf * cos(level[leveler][door][2] + w);
						float pt3x = radius2 *sin(level[leveler][door][2] + w);
						float pt3y = radius2 *cos(level[leveler][door][2] + w);
						uint32 first = 0xff8585ff; //red
						uint32 second = 0xff4BB0F6; // orange
						if (leveler == 2) {
							first = 0xff4bb0f6;
							second = 0xff8ff1ff; //yellow
						}
						if (leveler == 3) {
							first = 0xff8ff1ff;
							second = 0xff6cf551; //green
						}
						if (leveler == 4) {
							first = 0xff6cf551;
							second = 0xfffff663;//blue
						}
						if (leveler == 5) {
							first = 0xfffff663;
							second = 0xffff8863;//indigo
						}
						if (leveler == 6) {
							first = 0xffff8863;
							second = 0xffff9cc4;//purple
						}
						Iw2DSetColour(first);
						Iw2DDrawLine(CIwFVec2(surface_width / 2 + pt1x, surface_height / 2 - pt1y), CIwFVec2(surface_width / 2 + pt2x, surface_height / 2 - pt2y));
						Iw2DSetColour(second); 
						Iw2DDrawLine(CIwFVec2(surface_width / 2 + pt2x, surface_height / 2 - pt2y), CIwFVec2(surface_width / 2 + pt3x, surface_height / 2 - pt3y));
						first = second;
					}
				}
			}
		}
	}

	//Iw2DSurfaceShow();

}