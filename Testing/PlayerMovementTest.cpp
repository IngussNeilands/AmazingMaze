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


/* Test case 1: testing that the player can succssfully move in a door to reach a more
inner layer of the maze.
Inputs include parameters for the player's current level within the maze, along
with its angle along the circular walls
*/
void testMoveDown(){
	printf("The value returned from moveDown(1,270 ) = %d", moveDown(1, 270));
	printf("Expected value of moveDown(1,270) = 32");
	printf("The value returned from moveDown(2, 270) = %d", moveDown(2, 270));
	printf("Expected value of moveDown(2,270) = 42");
	printf("The value returned from moveDown(3, 270) = %d", moveDown(3, 270));
	printf("Expected value of moveDown(3,270) = 55");
	printf("The value returned from moveDown(4, 270) = %d", moveDown(4, 270));
	printf("Expected value of moveDown(4,270) = 67");
	printf("The value returned from moveDown(5, 270) = %d", moveDown(5, 270));
	printf("Expected value of moveDown(5,270) = 78");
}

/* Test case 2: testing that the player can succssfully move out a door in order
to escape the maze eventually.
Inputs include parameters for the player's current level within the maze, along
with its angle along the circular walls
*/
void testMoveUp(){
	printf("The value returned from moveUp(1,270 ) = %d", moveUp(1, 270));
	printf("Expected value of moveUp(1,270) = 78");
	printf("The value returned from moveUp(2, 270) = %d", moveUp(2, 270));
	printf("Expected value of moveUp(2,270) = 66");
	printf("The value returned from moveUp(3, 270) = %d", moveUp(3, 270));
	printf("Expected value of moveUp(3,270) = 52");
	printf("The value returned from moveUp(4, 270) = %d", moveUp(4, 270));
	printf("Expected value of moveUp(4,270) = 35");
	printf("The value returned from moveUp(5, 270) = %d", moveUp(5, 270));
	printf("Expected value of moveUp(5,270) = 22");
}

/* Test case 3: testing that the player can move in and out of the maze, based on the desired button that
they pressed
*/
void testPlayerMove(){
	CIw2DImage* InBt = CIw2DImage();
	CIw2DImage* InBtC = CIw2DImage();
	CIw2DImage* OutBt = CIw2DImage();
	CIw2DImage* OutBtC = CIw2DImage();
	printf("The value returned from PlayerMovement = %d", PlayerMove(1, 270 , InBt, InBtC, OutBt,OutBtC));
	printf("Expected return value of PlayerMove = 2");

	CIw2DImage* InBt1 = CIw2DImage();
	CIw2DImage* InBtC1 = CIw2DImage();
	CIw2DImage* OutBt1 = CIw2DImage();
	CIw2DImage* OutBtC1 = CIw2DImage();
	printf("The value returned from PlayerMovement = %d", PlayerMove(4, 270 , InBt, InBtC, OutBt,OutBtC));
	printf("Expected return value of PlayerMove = 3");

}