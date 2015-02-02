#include "s3e.h"
#include "IwDebug.h"
#include "Iw2DSceneGraph.h"
#include "IwGx.h"

using namespace Iw2DSceneGraphCore;
using namespace Iw2DSceneGraph;

// Scene root node
CNode* g_SceneRoot = NULL;

// Set the surface type to be XRGB888 which uses a 32 bit data format, with 8 bits for channel and the top 8 bits left unused
//
// Discover the screen width, height and pitch
uint32 screenWidth = s3eSurfaceGetInt(S3E_SURFACE_WIDTH);
uint32 screenHeight = s3eSurfaceGetInt(S3E_SURFACE_HEIGHT);
uint32 screenPitch = s3eSurfaceGetInt(S3E_SURFACE_PITCH);

// Main entry point for the application
int main()
{
	// Initialise Iw2D
	Iw2DInit();

	// Get surface width and height
	int surface_width = Iw2DGetSurfaceWidth();
	int surface_height = Iw2DGetSurfaceHeight();

	// Rotation angle of rectangle
	//float angle = 0;

	// Wait for a quit request from the host OS
	while (!s3eDeviceCheckQuitRequest())
	{
		// Clear background to blue
		Iw2DSurfaceClear(0xff8080);

		// Set up a transform
		//CIwFMat2D mat;
		//mat.SetRot(angle);
		//mat.ScaleRot(2.0f);
		//mat.SetTrans(CIwFVec2((float)surface_width / 2, (float)surface_height / 2));
		//Iw2DSetTransformMatrix(mat);
		//	angle += 0.01f;

		// Render filled rectangle
		//Iw2DSetColour(0xff00ffff);
		//Iw2DFillRect(CIwFVec2(-50.0f, -100.0f), CIwFVec2(100.0f, 200.0f));

		// Render filled arc
		Iw2DSetColour(0xff59ff4d);
		Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(25.0f, 25.0f), 0, 2 * PI);
		Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(26.0f, 26.0f), 0, 2 * PI);
		Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(27.0f, 27.0f), 0, 2 * PI);
		//Iw2DDrawLine(CIwFVec2(surface_width / 2 + 14.1, surface_height / 2 - 20.62), CIwFVec2(surface_width / 2 + 31.77, surface_height / 2 - 38.29));
		Iw2DDrawLine(CIwFVec2(surface_width / 2 + 14.1, surface_height / 2 - 20.62), CIwFVec2(surface_width / 2 + 28.24, surface_height / 2 - 41.26));

		Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(50.0f, 50.0f), 0, 2 * PI);
		Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(51.0f, 51.0f), 0, 2 * PI);
		Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(52.0f, 52.0f), 0, 2 * PI);
		Iw2DDrawLine(CIwFVec2(surface_width / 2 - 17.5391614, surface_height / 2 + 46.82283435), CIwFVec2(surface_width / 2 - 26.3087, surface_height / 2 + 70.23425));
		Iw2DDrawLine(CIwFVec2(surface_width / 2 - 35.28, surface_height / 2 - 35.43), CIwFVec2(surface_width / 2 - 52.92, surface_height / 2 - 53.14));


		Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(75.0f, 75.0f), 0, 2 * PI);
		Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(76.0f, 76.0f), 0, 2 * PI);
		Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(77.0f, 77.0f), 0, 2 * PI);
		Iw2DDrawLine(CIwFVec2(surface_width / 2 + 63.1308696, surface_height / 2 - 40.490657), CIwFVec2(surface_width / 2 + 84.17449279, surface_height / 2 - 53.98754266));
		Iw2DDrawLine(CIwFVec2(surface_width / 2 + 32.05, surface_height / 2 + 67.8), CIwFVec2(surface_width / 2 + 42.73, surface_height / 2 + 90.41));
		Iw2DDrawLine(CIwFVec2(surface_width / 2 - 74.48188, surface_height / 2 - 8.8005), CIwFVec2(surface_width / 2 - 99.30917, surface_height / 2 - 11.734));

		Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(100.0f, 100.0f), 0, 2 * PI);
		Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(101.0f, 101.0f), 0, 2 * PI);
		Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(102.0f, 102.0f), 0, 2 * PI);


		Iw2DSetColour(0xffff8080);

		Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(25.0f, 25.0f), 0, 0.3);
		Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(26.0f, 26.0f), 0, 0.3);
		Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(27.0f, 27.0f), 0, 0.3);


		Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(50.0f, 50.0f), 5, 5.2);
		Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(51.0f, 51.0f), 5, 5.2);
		Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(52.0f, 52.0f), 5, 5.2);

		Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(50.0f, 50.0f), 2.5, 2.7);
		Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(51.0f, 51.0f), 2.5, 2.7);
		Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(52.0f, 52.0f), 2.5, 2.7);

		Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(75.0f, 75.0f), 4, 4.13);
		Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(76.0f, 76.0f), 4, 4.13);
		Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(77.0f, 77.0f), 4, 4.13);

		Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(75.0f, 75.0f), 0.7, 0.83);
		Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(76.0f, 76.0f), 0.7, 0.83);
		Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(77.0f, 77.0f), 0.7, 0.83);

		Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(75.0f, 75.0f), 1.2, 1.33);
		Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(76.0f, 76.0f), 1.2, 1.33);
		Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(77.0f, 77.0f), 1.2, 1.33);

		Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(100.0f, 100.0f), 2, 2.08);
		Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(101.0f, 101.0f), 2, 2.08);
		Iw2DDrawArc(CIwFVec2(surface_width / 2, surface_height / 2), CIwFVec2(102.0f, 102.0f), 2, 2.08);

		Iw2DSetColour(0xff0000ff);
		//Iw2DDrawRect(CIwFVec2(surface_width / 2 - 1, surface_height / 2 - 1), CIwFVec2(2, 2));
		Iw2Dget
		// Flip the surface buffer to screen
		Iw2DSurfaceShow();

		// Sleep to allow the OS to process events etc.
		s3eDeviceYield(0);
	}

	// Shut down Iw2D
	Iw2DTerminate();

	return 0;
}