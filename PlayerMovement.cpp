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


float level[9][20][15];  //a 3D arrway that stores the parent, door leftpt, blockpt, and childs					//0 = parent, 1 = leftpt, 2 = block, 3 = blockleft, 4 = blockright, 5 = childamount, 6-10 = childs
int MaxLevel;  // MaxLevel is set based on the difficulity
int sign = 1;



//load btn1 //load btn2 

float DrawPlayer(int curLevel,float angle, CIw2DImage* player){
	
	int surface_width = Iw2DGetSurfaceWidth();
	int surface_height = Iw2DGetSurfaceHeight();
	float radian = angle * 2 * PI / 360;
	float factor = 2.0;
	if (curLevel == 1) factor = 2.00;
	if (curLevel == 2) factor = 1.81;
	if (curLevel == 3) factor = 1.52;
	if (curLevel == 4) factor = 1.34;
	if (curLevel == 5) factor = 1.15;
	if (curLevel == 6) factor = 0.97;
	if (curLevel == 7) factor = 0.73;
	if (curLevel == (MaxLevel + 1)) factor = 0;
	factor = factor * sign;
//	printf("print factor = %f\n", factor);
	CIwFVec2 image_position;  //initialization?

	//CIw2DImage* OutBt = Iw2DCreateImage("textures/out1.png");
	int levelamount = curLevel + 1;
	if (curLevel == MaxLevel) levelamount = curLevel;
	float drawWidth = (surface_width - 30) / 2;
	if (curLevel == MaxLevel) drawWidth = drawWidth - 30;
	float avg = drawWidth / levelamount;
	float innerR = avg * (curLevel - 1);
	float outterR = avg * curLevel;
	float radius = (innerR + outterR) / 2;
	//printf("innerR = %f   outterR = %f    radius = %f \n", innerR, outterR, radius);
	image_position.x = cos(radian) * radius;
	image_position.y = sin(radian) * radius;
	image_position.y = image_position.y + surface_height / 2 - radius / (curLevel * 3.5 * 2);
	image_position.x = image_position.x + surface_width / 2 - radius / (curLevel * 3.5 * 2);
	angle = angle + factor;
	if (angle > 360){
		angle = angle - 360;
	}
	if (angle < 0){
		angle = angle + 360;
	}
	int nextlocation = (((angle + factor) *2.0 * PI / 360)+1.535889742)  * 100;
	if (nextlocation > 628) nextlocation = nextlocation - 628;
	if (nextlocation < 0) nextlocation = nextlocation + 628;
	int wall;
	for (int doors = 0; doors < 20; doors++){
		wall = level[curLevel - 1][doors][2] * 100;
		if (wall == -100) break;
		//printf("nextL = %i, wall = %i\n", nextlocation, wall);
		int limit = abs(int(factor * 6));
		int difference = abs(nextlocation - wall);
		//printf("difference %i <= limit %i \n", difference, limit);
		if (difference <= limit){
			//printf("changing \n");
			sign = sign * -1;
		}
		
	}
	

	Iw2DSetColour(0xffffffff);
	Iw2DDrawImage(player, image_position, CIwFVec2(radius / (curLevel*3.5), radius / (curLevel*3.5)));
	return angle;

}



int PlayerMove(int curLevel, float angle, CIw2DImage* InBt, CIw2DImage* InBtC, CIw2DImage* OutBt, CIw2DImage* OutBtC){
	CIw2DImage* IBT = InBt;
	CIw2DImage* OBT = OutBt;
	int Levle = curLevel;
	int surface_width = Iw2DGetSurfaceWidth();
	int surface_height = Iw2DGetSurfaceHeight();
	if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) & S3E_POINTER_STATE_PRESSED){
		int xx = s3ePointerGetX();
		int yy = s3ePointerGetY();

		if (xx > 8 && yy > surface_height - 80 && xx < 152 && yy < surface_height - 8) {
		IBT = InBtC;
		Levle = moveDown(curLevel, angle);
		}
		if (xx > surface_width - 152 && yy > surface_height - 80 && xx < surface_width - 8 && yy < surface_height - 8){
		OBT = OutBtC;
		Levle = moveUp(curLevel, angle);
		}
	}
	Iw2DDrawImage(IBT, CIwFVec2(8, surface_height - 80), CIwFVec2(144, 72));
	Iw2DDrawImage(OBT, CIwFVec2(surface_width - 152, surface_height - 80), CIwFVec2(144, 72));
	return Levle;
}

int moveUp(int currentLevel, float angle){
	float radian = angle * 2 * PI / 360 + 1.56761102;
	if (radian > 6.28) radian = radian - 6.28;
	printf("radian = %f\n", radian);
	int moveTo = currentLevel;
	float doorsizes = 0.3;
	if (currentLevel == 1) doorsizes = 0.3;
	if (currentLevel == 2) doorsizes = 0.2;
	if (currentLevel == 3) doorsizes = 0.1333;
	if (currentLevel == 4) doorsizes = 0.088866667;
	if (currentLevel == 5) doorsizes = 0.059244;
	if (currentLevel == 6) doorsizes = 0.039496;
	if (currentLevel == 7) doorsizes = 0.04;

	for (int doors = 0; doors < 20; doors++){
		float doorleftpt = level[currentLevel][doors][1] - 0.1;
	if (doorleftpt < -0.5) break;
	float doorrightpt = doorleftpt + doorsizes + 0.1;
	//printf("-------------------------------------leftpt = %f, rightpt = %f\n", doorleftpt, doorrightpt);
	if (radian >= doorleftpt && radian <= doorrightpt) moveTo++;
	} 
	return moveTo;
}

int moveDown(int currentLevel, float angle){
	float radian = angle * 2 * PI / 360 + 1.56761102;
	if (radian > 6.28) radian = radian - 6.28;
	printf("radian = %f\n", radian);
	int moveTo = currentLevel;
	float doorsizes = 0.3;
	if (currentLevel == 1) doorsizes = 0.3;
	if (currentLevel == 2) doorsizes = 0.2;
	if (currentLevel == 3) doorsizes = 0.1333;
	if (currentLevel == 4) doorsizes = 0.088866667;
	if (currentLevel == 5) doorsizes = 0.059244;
	if (currentLevel == 6) doorsizes = 0.039496;
	if (currentLevel == 7) doorsizes = 0.04;

	for (int doors = 0; doors < 20; doors++){
		float doorleftpt = level[currentLevel - 1][doors][1] - 0.1;
		if (doorleftpt < -0.5) break;
		float doorrightpt = doorleftpt + doorsizes + 0.1;
		//printf("-------------------------------------leftpt = %f, rightpt = %f\n", doorleftpt, doorrightpt);
		if (radian >= doorleftpt && radian <= doorrightpt) moveTo--;
	}
	return moveTo;
}
