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

//int test[10];
//float level[8][24][11];  //a 3D arrway that stores the parent, door leftpt, blockpt, and childs
//int MaxLevel = 3;  // MaxLevel is set based on the difficulity
//float level[9][20][15];  //a 3D arrway that stores the parent, door leftpt, blockpt, and childs					//0 = parent, 1 = leftpt, 2 = block, 3 = blockleft, 4 = blockright, 5 = childamount, 6-10 = childs
//int MaxLevel;  // MaxLevel is set based on the difficulity

void MazeInitializer(){
	for (int leveler = 0; leveler < 9; leveler++){
		for (int doorr = 0; doorr < 20; doorr++){
			for (int sec = 0; sec < 15; sec++){
				level[leveler][doorr][sec] = -1;
			}
		}
	}
}

int DoorGenerator(){  //generates the values for the door leftpt for each door based on MaxLevel
	
	float leftpt = 0;
	int prevDoorAmount;
	/*for (int x = 0; x < 10; x++){
		test[x] = x*x;
	}*/
	printf("MaxLevel = %i \n", MaxLevel);
	for (int currentLevel = 1; currentLevel <= MaxLevel; currentLevel++){
		srand(time(NULL));
		int DoorAmount = (rand() % (currentLevel * 2)) + 2;  //decide how many doors for the level
		if (currentLevel != 1){   // if it is not the first level, the dooramount is decided by the function assignParentChild
			DoorAmount = AssignParentChild(currentLevel, prevDoorAmount);
		}
		printf("door amount = %i, MaxLevel = %i ", DoorAmount, MaxLevel);
		for (int door = 1; door <= DoorAmount; door++){  //generate door leftpt 
			if (currentLevel == 1){  // forlevel 1 only
				srand(time(NULL));
				if (door == 1)leftpt = (rand() % ((628 / DoorAmount*door)));
				
				srand(time(NULL));
				if (door != 1)leftpt = (rand() % ((628 / DoorAmount*door) - (628/DoorAmount * (door-1)))) + (628 / DoorAmount * (door - 1));  // leftpt will be generated based on the doorAmount and evenly
				printf("level 1: leftpt = %f", leftpt);
				level[currentLevel][door - 1][1] = leftpt / 100; //record the leftpt at location 1
				level[currentLevel][door - 1][0] = -2;  // initialize parent to NULL
				level[currentLevel][door - 1][3] = -2; // initialize parent left block and rightblock to NULL
				level[currentLevel][door - 1][4] = -2;
			}
			else {
				srand(time(NULL));
				float leftEdge = level[currentLevel][door - 1][3]; //acquire left edge for door location and add 0.3 space for 
				float rightEdge = level[currentLevel][door - 1][4];
				float distance = rightEdge - leftEdge;
				if (distance <= 0) {
					rightEdge = rightEdge + 6.28;
					distance = rightEdge - leftEdge;
				}
				int parentdoor = level[currentLevel][door - 1][0];
				int sibilings = level[currentLevel - 1][parentdoor][5];
				if (sibilings == 1){
					int distancex = (int)(distance * 100) - 50;
					leftpt = (rand() % distancex) + leftEdge*100;
					if (leftpt > 628) leftpt = leftpt - 628;
					if (currentLevel == MaxLevel){
						int difference = leftpt - level[currentLevel][parentdoor][1];
						int tempL = leftpt * 100;
						int tempP = level[currentLevel][parentdoor][1] * 100;
						while ((abs(tempL-tempP)) < 70)
							printf("resetting.......\n");
							leftpt = (rand() % distancex) + leftEdge * 100;
							tempL = leftpt * 100;
							if (leftpt > 628) leftpt = leftpt - 628;
					}
					level[currentLevel][door - 1][1] = (leftpt + 10)/100;
				}
				else if(sibilings>1){
					int distancex = (int)(distance * 100);
					float avg = distancex / sibilings;
					int childrank = 0;
					for (int x = 6; x < 6 + sibilings; x++){
						if (level[currentLevel - 1][parentdoor][x] == door-1){
							childrank = x - 5;
						}
					}
					int newLeftEdge = (leftEdge*100) + avg * (childrank-1);
					int newRightEdge = (leftEdge*100) + avg * childrank - 50;
					leftpt = (rand() % (newRightEdge - newLeftEdge)) + newLeftEdge;
					if (leftpt > 628) leftpt = leftpt - 628;
					level[currentLevel][door - 1][1] = (leftpt + 5)/100;
				}
			}
		}
		prevDoorAmount = DoorAmount;
		BlockGenerator(currentLevel, prevDoorAmount);
	}
	return 1;
}

int AssignParentChild(int curlevel, int prevDoorAmount){
	//printf("hello");
	int childnum = 0;
	float blockright;
	float blockleft;
	float difference;
	int childamount;
	int loc = 6;
	for (int doorloc = 0; doorloc < prevDoorAmount; doorloc++){
		if (curlevel == MaxLevel){
			srand(time(NULL));
			int parent = rand() % prevDoorAmount;
			blockleft = level[curlevel - 1][prevDoorAmount - 1][2];
			if (parent != 0) blockleft = level[curlevel - 1][parent - 1][2];
			blockright = level[curlevel - 1][parent][2];
			level[curlevel - 1][parent][6] = 0;
			level[curlevel - 1][parent][5] = 1;
			level[curlevel][0][0] = parent;
			level[curlevel][0][3] = blockleft;
			level[curlevel][0][4] = blockright;
			return 1;
		}
		blockleft = level[curlevel - 1][prevDoorAmount - 1][2];  // assign blockleft value to the last door's block location
		if (doorloc != 0) blockleft = level[curlevel - 1][doorloc - 1][2]; // if it is not the first door, the blockleft is = to the previous door's block location
		blockright = level[curlevel - 1][doorloc][2];  // assign blockright to the current door's block location
		difference = blockright - blockleft;  // find out the distance betweent the two block
		if (difference <= 0) difference = difference + 6.28;
		if (prevDoorAmount == 1) {
			blockright = blockleft - 0.1;
			difference = blockright - blockleft;
		}
		childamount = (int) (difference / 0.9) ;  // assign childamount based on the amount of distance
		loc = 6;
		level[curlevel - 1][doorloc][5] = 0;  //set the parent's childamount to 0;
		for (int childN = 0; childN < childamount; childN++){  // loop for each child
			//srand(time(NULL));
			int rander = rand();
			printf("rander = %i \n", rander);
			if ((rander % 100) < 75 ){  // 50% of the child actually show up as a door
				level[curlevel - 1][doorloc][loc] = childnum;  // record the childnumber at the loc for the parent
				level[curlevel - 1][doorloc][5]++; // increase the childamount for the parent
			//	printf("doorloc = %i\n", doorloc);
				level[curlevel][childnum][0] = doorloc; // for the children, assign the parent
				level[curlevel][childnum][3] = blockleft; // record down the blockleft location and the block right location
				level[curlevel][childnum][4] = blockright;
				childnum++;  //move on to the next child
				loc++; // loc to record the child is moved on to the next one
			}
			else{ 
				printf("-----------------didn't show-----------------------\n"); 
			}
		}
		//printf("---childnm = %i, ---childamount = %i", childnum, childamount);
	}
	if (curlevel != MaxLevel && childnum == 0) {
		return AssignParentChild(curlevel, prevDoorAmount);
	}
	return childnum;
	}


void BlockGenerator(int curlevel, int doors){
	float blockpt; 
	for (int doorloc = 1; doorloc <= doors; doorloc++){
		srand(time(NULL));
			int leftEdge = (level[curlevel][doorloc - 1][1] + 0.3) * 100;
			printf("leftEdge = %i\n", leftEdge);
			int rightEdge = (level[curlevel][doorloc][1] - 0.3) * 100;  // decide the right most value
			if (doorloc == doors) rightEdge = (level[curlevel][0][1] - 0.3) * 100; // if at the last door, rightEdge = first door's value
			int distance = rightEdge - leftEdge;
			if (distance <= 0) distance = distance + 628;
			blockpt = ((rand() % distance) + leftEdge);  // if not, just do the same as normal case
			if (blockpt > 2 * PI*100) blockpt = blockpt - 2 * PI *100;
			printf("blockpt = %f \n ", blockpt);
			level[curlevel][doorloc - 1][2] = blockpt/100;  // set the blockpt for the last door
	}
}

int setDifficulity(int difficulity){
	srand(time(NULL));
	if (difficulity == 1) MaxLevel = 3;
	if (difficulity == 2) MaxLevel = (rand() % 2) + 4;
	if (difficulity == 3) MaxLevel = (rand() % 2) + 6;

	return MaxLevel;
}

