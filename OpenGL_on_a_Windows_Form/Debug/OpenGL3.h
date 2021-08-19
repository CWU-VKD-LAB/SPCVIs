///-------------------------------------------------------------------------------------------------
// file:	OpenGL3.h
//
// summary:	Declares the OpenGL class
///-------------------------------------------------------------------------------------------------

#pragma once

#include <windows.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "glut.h"
#include "stdafx.h"
#include "ClassData.h"
#include "FileHandling.h"
#include "InteractiveSPC.h"
#include <sstream>



///-------------------------------------------------------------------------------------------------
// namespace: System
//
// summary:	.
///-------------------------------------------------------------------------------------------------

using namespace System::Windows::Forms;

///-------------------------------------------------------------------------------------------------
// namespace: OpenGLForm
//
// summary:	.
///-------------------------------------------------------------------------------------------------

namespace OpenGLForm
{
	/// <summary>	THE MAGIC. </summary>
	ClassData data;
	/// <summary>	The new file. </summary>
	FileHandling newFile;



	/// <summary>	The fourth graph. </summary>
	InteractiveSPC graph4;



	public ref class COpenGL3 : public System::Windows::Forms::NativeWindow
	{
	public:

		/// <summary>	Height of the world. </summary>
		double worldHeight;
		/// <summary>	Width of the world. </summary>
		double worldWidth;
		/// <summary>	Holds the clicked dimension. </summary>
		int clickedDimension;
		//double normx1, normx2, normy1, normy2;
		double rectx1, rectx2, recty1, recty2;
		double rectOrx1, rectOrx2, rectOry1, rectOry2;
		//int graphNumber;		
		//std::vector<double> x1CoordGraph, x2CoordGraph, y1CoordGraph, y2CoordGraph;
		/// <summary>	Holds mouse X coord when mapped to world. </summary>
		double worldMouseX;
		/// <summary>	Holds mouse Y coord when mapped to world. </summary>
		double worldMouseY;

		/// <summary>	Is made true via mouselistener when dragging the mouse. </summary>
		bool drawingDragged;
		bool mouseButtonDown = false;
		bool drawingAndRectEnabled;
		bool drawingOrRectEnabled;
		bool drawingOrRectComplete;
		/// <summary>	holds which graph to display, -1 for none right now. </summary>
		int graphType = -1;
		
		

		/// <summary>	The original wh. </summary>
		int originalWH;
		/// <summary>	The original ww. </summary>
		int originalWW;
		int cpPosx;
		int cpPosy;
		


		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// 
		///
		///
		///
		/// <param name="parentForm">	The parent form. </param>
		/// <param name="iWidth">	 	Zero-based index of the width. </param>
		/// <param name="iHeight">   	Zero-based index of the height. </param>
		/// <param name="igraphType">	Type of the igraph. </param>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		COpenGL3(System::Windows::Forms::Form ^ parentForm, GLsizei iWidth, GLsizei iHeight, int igraphType)
		{
			graphType = igraphType;

			CreateParams^ cp = gcnew CreateParams;

			worldWidth = iWidth;
			worldHeight = iHeight;
			drawingDragged = false;
			clickedDimension = -1;

			originalWW = iWidth;
			originalWH = iHeight;
			
			// Initialize reverse data axis
			reverseDataAxis = 0; 
			nonOrtho = 0;
		
			swapAxes= 0;
			nonLinearScaleX = 0;
			nonLinearScaleY = 0; 
			

			// Set the position on the form
			cp->X = 201;
			cpPosx = 201;
			cp->Y = 33;
			cpPosy = 33;
			cp->Height = iHeight;
			cp->Width = iWidth;

			// Specify the form as the parent.
			cp->Parent = parentForm->Handle;
			
			// Create as a child of the specified parent and make OpenGL compliant (no clipping)
			cp->Style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_BORDER | WS_TABSTOP;

			// Create the actual window
			this->CreateHandle(cp);

			m_hDC = GetDC((HWND)this->Handle.ToPointer());

			if (m_hDC)
			{
				MySetPixelFormat(m_hDC);
				ReSizeGLScene(iWidth, iHeight);
				//InitGL();
			}
		}


		void resetDrawingArea() {
			SetWindowPos((HWND)this->Handle.ToPointer(), NULL, 201, 33, originalWW, originalWH, SWP_SHOWWINDOW);
			SetFocus((HWND)this->Handle.ToPointer());
			cpPosx = 201;
		}

		// CHANGE BACKGROUND COLOR
		void setClassColor(float R, float G, float B, int classnumber) {
			if (classnumber > 0 && classnumber <= data.numOfClasses) {
			
				graph4.data.setClassColor(R, G, B, classnumber);
			
			}

		}

		int getClassSize() {
			//int numberOfClasses = 0; 
			//for (int i = 1; i <= data.classNum.size(); i++)
			//{
			//	if (data.classNum[i] != data.classNum[i - 1])
			//		numberOfClasses = numberOfClasses + 1;
			//}
			return graph4.data.numOfClasses;
			//return numberOfClasses;
		}





		/* RENDERING FOR DIFFERENT GRAPHS *//////////////////////////////////////////////////////////////////////////////////////



	
		System::Void Render4(System::Void)
		{
			graph4.display();
		}



		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Swap open gl buffers. </summary>
		///
		////////////////////////////////////////////////////////////////////////////////////////////////////

		System::Void SwapOpenGLBuffers(System::Void)
		{
			SwapBuffers(m_hDC);
		}


		void clearAllGraphData() 
		{
			data.~ClassData();
		

			graph4.data.~ClassData();
		


			data.resetSomeVars();
			
			graph4.data.resetSomeVars();

		}


		void setFileName(ClassData file) {
			clearAllGraphData();


			/* Opens the file and process the data */
			//data.fileName = "input.csv";
			data.fileName = file.fileName;
			data.worldWidth = worldWidth;
			data.worldHeight = worldHeight;
			data.xmax = 0;
			data.ymax = 0;
			newFile.openFile(data);
			newFile.sortGraph(data);
			newFile.normalizeData(data);





		
			// C-SPC
			graph4.data = data;
		 


			
		
			graph4.data.classsize = int(data.xdata[0].size());

			for (int y = 0; y < graph4.data.classsize; y++)
			{

				graph4.data.graphwidth.push_back(worldWidth / (graph4.data.classsize + 1)); // Width size for each graph
				graph4.data.graphheight.push_back(worldHeight / (2)); // Height size for each graph
				graph4.data.nonOrthoY2.push_back(1);
				graph4.data.nonOrthoX1.push_back(-1);
				graph4.data.nonOrthoY1.push_back(-1);
				graph4.data.nonOrthoX2.push_back(1);
				
				
			}
	
			graph4.fillGraphLocations(); // Creates starting graph positions, and fills example data for now.
			graph4.data.setClassColors();

			//for (int j = 0; j < 3; j++)
			//{
			//	graph4.drawData(200,300,300,400, 0, j);
			//}

			//graph4.data.setClassColor(255.0, 0.0, 0.0, 1);


			
		
			originalWH = worldHeight; // Saves orginals to use for increments like for zooming.
			originalWW = worldWidth;
		}


		void zoom(int scaler) {
			int width = originalWW;
			int height = originalWH;


	
			if (graphType == 4) { // C-SPC

				graph4.data.worldWidth -= width / 20 * scaler;
				graph4.data.worldHeight -= height / 20 * scaler;
				graph4.data.leftWidth += width / 20 * scaler;
				graph4.data.bottomHeight += height / 20 * scaler;

				graph4.data.panamount -= scaler * 2;
			}


		}

		void panHorizontal(bool right) {



			 if (graphType == 4) { // C-SPC
				if (right) {
					graph4.data.pan_x -= graph4.data.panamount;
				}
				else {
					graph4.data.pan_x += graph4.data.panamount;
				}
			}



		}


		void panVertical(bool up) {



			 if (graphType == 4) { // C-SPC
				if (up) {
					graph4.data.pan_y -= graph4.data.panamount;
				}
				else {
					graph4.data.pan_y += graph4.data.panamount;
				}
			}
	
		}


	private:
		/// <summary>	The device-context. </summary>
		/// <summary>	The device-context. </summary>
		HDC m_hDC;
		/// <summary>	The hglrc. </summary>
		HGLRC m_hglrc;


	protected:

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Destructor. </summary>
		///
		////////////////////////////////////////////////////////////////////////////////////////////////////

		~COpenGL3(System::Void)
		{
			this->DestroyHandle();
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	My set pixel format. </summary>
		///
		/// <param name="hdc">	The hdc. </param>
		///
		/// <returns>	A GLint. </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		GLint MySetPixelFormat(HDC hdc)
		{
			static	PIXELFORMATDESCRIPTOR pfd =				// pfd Tells Windows How We Want Things To Be
			{
				sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
				1,											// Version Number
				PFD_DRAW_TO_WINDOW |						// Format Must Support Window
				PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
				PFD_DOUBLEBUFFER,							// Must Support Double Buffering
				PFD_TYPE_RGBA,								// Request An RGBA Format
				16,										// Select Our Color Depth
				0, 0, 0, 0, 0, 0,							// Color Bits Ignored
				0,											// No Alpha Buffer
				0,											// Shift Bit Ignored
				0,											// No Accumulation Buffer
				0, 0, 0, 0,									// Accumulation Bits Ignored
				16,											// 16Bit Z-Buffer (Depth Buffer)  
				0,											// No Stencil Buffer
				0,											// No Auxiliary Buffer
				PFD_MAIN_PLANE,								// Main Drawing Layer
				0,											// Reserved
				0, 0, 0										// Layer Masks Ignored
			};

			GLint  iPixelFormat;

			// get the device context's best, available pixel format match 
			if ((iPixelFormat = ChoosePixelFormat(hdc, &pfd)) == 0)
			{
				MessageBox::Show("ChoosePixelFormat Failed");
				return 0;
			}

			// make that match the device context's current pixel format 
			if (SetPixelFormat(hdc, iPixelFormat, &pfd) == FALSE)
			{
				MessageBox::Show("SetPixelFormat Failed");
				return 0;
			}

			if ((m_hglrc = wglCreateContext(m_hDC)) == NULL)
			{
				MessageBox::Show("wglCreateContext Failed");
				return 0;
			}

			if ((wglMakeCurrent(m_hDC, m_hglrc)) == NULL)
			{
				MessageBox::Show("wglMakeCurrent Failed");
				return 0;
			}


			return 1;
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Initializes the gl. </summary>
		///
		/// <param name="parameter1">	The first parameter. </param>
		///
		/// <returns>	True if it succeeds, false if it fails. </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		bool InitGL(GLvoid)										// All setup for opengl goes here
		{

			return TRUE;										// Initialisation went ok
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Re size gl scene. </summary>
		///
		/// <param name="width"> 	The width. </param>
		/// <param name="height">	The height. </param>
		///
		/// <returns>	A GLvoid. </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize and initialise the gl window
		{
			if (height == 0)										// Prevent A Divide By Zero By
			{
				height = 1;										// Making Height Equal One
			}
		}

		double getWorldMouseX() {

			// this will get the mouse position relative to the child window
			LPPOINT pts = new POINT;
			GetCursorPos(pts);

			::ScreenToClient((HWND)this->Handle.ToPointer(), pts); // gets the mouse coordinate relative to the OpenGL view

			double xWorld = pts->x;
			delete pts;
			return xWorld;
		} // Converts raw mouse X coordinates to world coordinates


		double getWorldMouseY() {

			// this will get the mouse position relative to the child window
			LPPOINT pts = new POINT;
			GetCursorPos(pts);

			::ScreenToClient((HWND)this->Handle.ToPointer(), pts); // Gets the mouse position relative to the OpenGL view

			double yWorld = pts->y;
			delete pts;
			return yWorld;
		} // Converts raw mouse Y coordinates to world coordinates

		

// Processing mouse button clicks

		virtual void WndProc(Message %msg) override
		{
			// get the X and Y coordinates of the mouse position
			this->worldMouseX = this->getWorldMouseX();
			this->worldMouseY = this->getWorldMouseY();
			// Get keys pressed and pergorm action
	
		
			switch (msg.Msg)
			{

			case WM_LBUTTONDOWN:
			{

				if (graphType == 1) { // S-CPC
					//No graph dragging
				}


				else if (graphType == 4) { // C-SPC

					{
						graph4.graphClicked = graph4.findClickedGraph(worldMouseX, worldMouseY);
						bool colliding = (graph4.graphClicked != -1);
						if (colliding && reverseDataAxis == 0 && nonOrtho == 0 && swapAxes ==0 && drawingAndRectEnabled == false && 
							drawingOrRectEnabled == false)
						{
							graph4.dragging = true;
							graph4.data.xgraphcoordinates[graph4.graphClicked] = worldMouseX - graph4.data.pan_x;
							graph4.data.ygraphcoordinates[graph4.graphClicked] = worldMouseY - graph4.data.pan_y;
						}

						if (drawingAndRectEnabled)
						{
							drawRectArea();
							graph4.data.rectAndCoordx1.push_back(double(worldMouseX- graph4.data.pan_x));
							graph4.data.rectAndCoordy1.push_back(double(worldMouseY- graph4.data.pan_y));
							
							mouseButtonDown = true;
					    }
						if (drawingOrRectEnabled)
						{
							drawRectArea();
							graph4.data.rectOrCoordx1.push_back(double(worldMouseX - graph4.data.pan_x));
							graph4.data.rectOrCoordy1.push_back(double(worldMouseY - graph4.data.pan_y));

							mouseButtonDown = true;
						}
					}
				}



			}
			break;
			case WM_RBUTTONDOWN:
			{

				if (graphType == 1) { // S-CPC
					// NOTHING YET
				}

				else if (graphType == 3) { // S-SPC
					// NOTHING YET
				}
				else if (graphType == 4) { // C-SPC
					// NOTHING YET
				}
			}
			break;
			case WM_MOUSEMOVE:
			{

				//if (drawingDragged)
				//{
				if (graphType == 1) { // S-CPC
					//graph1.data.ygraphcoordinates[lineClicked] = worldMouseY;
				}
				else if (graphType == 2) { // C-CPC
					// NOTHING YET
				}

				else if (graphType == 4) { // C-SPC
					// DRAGGING
					if (graph4.dragging) {
						graph4.data.xgraphcoordinates[graph4.graphClicked] = worldMouseX - graph4.data.pan_x;
						graph4.data.ygraphcoordinates[graph4.graphClicked] = worldMouseY - graph4.data.pan_y;
					}
				}

				//if (graph4.data.drawRect && mouseButtonDown == true)
				//{
				//	graph4.data.temprx2 = worldMouseX;
				//	graph4.data.temprectAndCoordy2 = worldMouseY;
				//	drawRectArea();
				//}

				//}
			}
			break;
			case WM_LBUTTONUP:
			{
				{
					if (reverseDataAxis == 1)
					{
						setReverseDataX();
			
					}
					else if (reverseDataAxis == 2)
					{
						setReverseDataY();
					}
					else if(nonOrtho == 1)
					{
						reverseDataAxis = 0;
						nonOrthogonalX();
						
					}

					else if (nonOrtho == 2)
					{
						reverseDataAxis = 0;
						nonOrthogonalY();
					}
					else if (swapAxes == 1)
					{
						swapCoordinates();
					}
				}
				//check if the mouse click was on a graph and detect whcih 
				if (graph4.dragging) {

					graph4.dragging = false;
					graph4.graphClicked = -1;

				}


				if (this->drawingDragged) {

					this->drawingDragged = false;

				}


			}
			if (drawingAndRectEnabled == true)
			{
				
				graph4.data.rectAndCoordx2.push_back(double(worldMouseX - graph4.data.pan_x));
				graph4.data.rectAndCoordy2.push_back(double(worldMouseY - graph4.data.pan_y));
				drawRectArea();
				clipAndData();
				//mouseButtonDown = false;
					
			}
			if (drawingOrRectEnabled == true)
			{

				graph4.data.rectOrCoordx2.push_back(double(worldMouseX - graph4.data.pan_x));
				graph4.data.rectOrCoordy2.push_back(double(worldMouseY - graph4.data.pan_y));
				drawRectArea();
				//if(drawingOrRectComplete)
				//	clipOrData();
				//mouseButtonDown = false;

			}
			break;
			case WM_KEYDOWN:
			{
				switch ((int)msg.WParam) {
				case VK_UP:
				{
					MessageBox::Show("Key Up");
					graph4.data.setClassColor(255.0, 0.0, 0.0, 1);
				}
				break;
				}
			}
			break;
			}
			NativeWindow::WndProc(msg);
		}

		
	private:
		void setReverseDataX();
		void setReverseDataY();
public:
	// 1=x, 2=y
	int reverseDataAxis;
	int swapAxes;
	void setMeanData(int meanClassNumber);
	int nonOrtho;
	float nonOrthoXAngle; 
	float nonOrthoXDiff;
	float nonOrthoYAngle;
	float nonOrthoYDiff;
	int nonLinearScaleX; 
	int nonLinearScaleY;
	float nonLinearLesserThan; 
	float nonLinearGreaterThan;
	
	

public:
	void changeScaleX(int graphIndex, int step, int nonLinearScaleX);
	int getNumberOfGraphs();
	System::String^ displayCoordinateLabels(std::vector<int> coordNumber);
	
	void changeScaleY(int graphIndexY, int stepY, int changeScaleY);
	void showHideLines();
	void nonOrthogonalX();
	void nonOrthogonalY();
	void swapCoordinates();
	void displayClassOnTop(int classNumber);
	void showHideClass(int classNumber, int hideVar);
	
	void drawRectArea();
	void clipAndData();
	void clipOrData();
	void displayHdData();
	void reduceOcclusion();
	
	void automateClassification();
};
}


void OpenGLForm::COpenGL3::setReverseDataX()
{	
	
	System::String^ displayString("YData = ");
	for (int k = 0; k < graph4.data.xdata.size(); k++)
	{
		displayString += graph4.data.ydata[k][graph4.graphClicked].ToString() + "\t";
		
		
	}	

	//MessageBox::Show(displayString->ToString());
	System::String^ displayString1("XData = ");
	for (int k = 0; k < graph4.data.xdata.size(); k++)
	{
		
		displayString1 += graph4.data.xdata[k][graph4.graphClicked].ToString() + "\t";
		graph4.data.xdata[k][graph4.graphClicked] = 1 - graph4.data.xdata[k][graph4.graphClicked];

	}

	//MessageBox::Show(displayString1->ToString());
	
}


void OpenGLForm::COpenGL3::setReverseDataY()
{

	for (int k = 0; k < graph4.data.xdata.size(); k++)
	{
		graph4.data.ydata[k][graph4.graphClicked] = 1 - graph4.data.ydata[k][graph4.graphClicked];
	}




	//std::vector<std::vector<float>> x1Coord, x2Coord, y1Coord, y2Coord;

	//x1Coord = { {0.0,  0.0,  0.0,  0.0 } };
	//x2Coord = { {0.0,  0.0,  0.0,  0.6 } };
	//y1Coord = { {0.0,  0.0,  0.0,  0.0  } };
	//y2Coord = { {0.0,  0.0,  0.0,  0.06  } };


	//for (int i = 1; i <= graph4.data.classsize; i++)
	//{

	//	graph4.data.y1CoordGraph[i-1] = (graph4.data.ygraphcoordinates[i - 1] - graph4.data.graphheight[i - 1] / 2);
	//	graph4.data.y2CoordGraph[i - 1] = (graph4.data.ygraphcoordinates[i - 1] + graph4.data.graphheight[i - 1] / 2);

	//}

	//float r = 0, g = 0, b = 0; int y = 0;
	//for (int s = 0; s < x1Coord[0].size(); s++)
	//{
	//	
	//	for(int c = 0; c < x1Coord.size(); c++) //classsize = number of graphs
	//	{
	//		graph4.data.rectAndCoordx1.push_back(graph4.data.x1CoordGraph[s] + x1Coord[c][s] * graph4.data.graphwidth[s]);
	//		graph4.data.rectAndCoordx2.push_back(graph4.data.x1CoordGraph[s] + x2Coord[c][s] * graph4.data.graphwidth[s]);
	//		graph4.data.rectAndCoordy1[y] = (graph4.data.y2CoordGraph[s] - y1Coord[c][s] * graph4.data.graphheight[s]);
	//		graph4.data.rectAndCoordy2[y] = (graph4.data.y2CoordGraph[s] - y2Coord[c][s] * graph4.data.graphheight[s]);
 //           graph4.data.rectR.push_back(r);
	//		graph4.data.rectG.push_back(g);
	//		graph4.data.rectB.push_back(b);
	//		y++;
	//	}
	//	
	///*	r = rand() % 256;
	//	g = rand() % 256;
	//	b = rand() % 256;*/
	//}


	
}


void OpenGLForm::COpenGL3::setMeanData(int meanClassNumber)
{
	//code for mean 
	graph4.data.setClassColor(255.0, 0.0, 0.0, (meanClassNumber + 1)); //Set the mean class color as red. 
	std::vector<float> avgValueIndex;
	std::vector<float> avgValues;
	std::vector<float> finalAvgValues;
	std::vector<float> avgValuesX;
	std::vector<float> finalAvgValuesX;
	float avgTemp = 0;
	for (int k = 0; k < graph4.data.classNum.size(); k++)
	{
		if (graph4.data.classNum[k] == (meanClassNumber+1))
		{
	
			avgValueIndex.push_back(k);
		}

	}

	for (int s = 0; s < avgValueIndex.size(); s++)
	{
		for (int t = 0; t < graph4.data.ydata[0].size(); t++)
		{
			avgValues.push_back(graph4.data.ydata[avgValueIndex[s]][t]);
			avgValuesX.push_back(graph4.data.xdata[avgValueIndex[s]][t]);
		}
	}

	int avgLinesInput = avgValues.size() / graph4.data.ydata[0].size();
	float temp = 0;
	float tempX = 0; 
	int temp1 = 0;
	if (avgLinesInput != 1)
	{
		for (int j = 0; j < graph4.data.ydata[0].size(); j++)
		{
			for (int m = temp1; m < avgValues.size(); m = m + graph4.data.ydata[0].size())
			{
				temp = temp + avgValues[m];
				tempX = tempX + avgValuesX[m];
			}
			temp = temp / avgLinesInput;
			tempX = tempX / avgLinesInput;
			finalAvgValues.push_back(temp);
			finalAvgValuesX.push_back(tempX);
			temp = 0;
			tempX = 0;
			temp1 += 1;
		}
	}
	else
	{
		for (int p = 0; p < avgValues.size(); p++)
		{
			finalAvgValues.push_back(avgValues[p]);
			finalAvgValuesX.push_back(avgValuesX[p]);
		}
		
	}
	graph4.data.ydata.push_back(finalAvgValues);
	graph4.data.xdata.push_back(finalAvgValuesX);
	//int avgClass = graph4.data.numOfClasses + 1;
	graph4.data.numOfClasses += 1;
	int avgClass = graph4.data.numOfClasses;
	std::vector<float> yellowRGB;
	yellowRGB.push_back(255);
	yellowRGB.push_back(255);
	yellowRGB.push_back(0);
	graph4.data.classColor.push_back(yellowRGB);
	graph4.data.classNum.push_back(avgClass);
	//graph4.data.setClassColor(255, 255, 0.0, avgClass);
	for (int i = 1; i < graph4.data.xdata[0].size()+1; i++)
	{

		float buffer = finalAvgValues[i] - finalAvgValues[0];
		graph4.data.ygraphcoordinates[i] = graph4.data.ygraphcoordinates[i] + graph4.data.ygraphcoordinates[i] * buffer;

	}
	
}










void OpenGLForm::COpenGL3::changeScaleX(int graphIndex, int step, int nonLinearScaleX)
{
	
	//std::vector<float> distanceSquareXData;
	float xRatio = 0.0;
	float xmin = graph4.data.xdata[0][graphIndex - 1];
	
	//std::vector<float> slopeXData;

	//for (int s = 0; s < graph4.data.xdata.size(); s++)
	//{
	//	if (xmin > graph4.data.xdata[s][graphIndex - 1])
	//		xmin = graph4.data.xdata[s][graphIndex - 1];
	//}
	//for (int i = 0; i < graph4.data.xdata.size(); i++)
	//{
	//	
	//	distanceSquareXData.push_back((pow(graph4.data.xmax - graph4.data.originalXData[i][graphIndex - 1],2) + pow(graph4.data.ymax - graph4.data.ydata[i][graphIndex - 1], 2)));
	//	slopeXData.push_back((graph4.data.ymax - graph4.data.ydata[i][graphIndex - 1])/(graph4.data.xmax - graph4.data.originalXData[i][graphIndex - 1]));
	//}
	//float scaleFactor = step * 0.10 * graph4.data.graphwidth[graph4.data.graphwidth.size() - 1];
	//graph4.data.graphwidth[graphIndex - 1] = graph4.data.graphwidth[graphIndex - 1] + scaleFactor ;

	//	for (int i = 0; i < graph4.data.xdata[0].size() + 1; i++)
	//	{
	//		graph4.data.xgraphcoordinates[i + graphIndex] = graph4.data.xgraphcoordinates[i + graphIndex] + scaleFactor;
	//		if (graphIndex > 1 && i < graphIndex - 1)
	//		{
	//			if (graph4.data.ygraphcoordinates[graphIndex - i] == graph4.data.ygraphcoordinates[graphIndex -i- 1] && graph4.data.ygraphcoordinates[1 + graphIndex - i] == graph4.data.ygraphcoordinates[graphIndex -i- 1])
	//				graph4.data.xgraphcoordinates[i] = graph4.data.xgraphcoordinates[i] - scaleFactor;
	//		}
	//		
	//	}
	//
	//
	//if (nonLinearScaleX == 1) //To scale first part of the graph
	//{
	//	xRatio = step * 0.10 *graph4.data.xmax;
	//	
	//	for (int k = 0; k < graph4.data.xdata.size(); k++)
	//	{
	//		if (graph4.data.xdata[k][graphIndex - 1] > nonLinearLesserThan)
	//		{
	//			if (step == 1)
	//			{
	//				if (graph4.data.xdata[k][graphIndex - 1] != graph4.data.xmax)
	//					//graph4.data.xdata[k][graphIndex - 1] = graph4.data.xmax -sqrt(distanceSquareXData[k] - pow((graph4.data.ymax - graph4.data.ydata[k][graphIndex - 1]),2));
	//					graph4.data.xdata[k][graphIndex - 1] = graph4.data.xdata[k][graphIndex - 1] + 0.015;

	//			}
	//			//else if (step == -1)
	//			//	if (graph4.data.xdata[k][graphIndex - 1] != graph4.data.xmax)
	//			//		graph4.data.xdata[k][graphIndex - 1] = graph4.data.xdata[k][graphIndex - 1] - 0.015;
	//		}
	//		if (graph4.data.xdata[k][graphIndex - 1] <= nonLinearLesserThan)
	//		{

	//			if (step == -1)
	//			{
	//				if (graph4.data.xdata[k][graphIndex - 1] > xmin)
	//				{
	//					graph4.data.xdata[k][graphIndex - 1] = graph4.data.xdata[k][graphIndex - 1] - graph4.data.xdata[k][graphIndex - 1] * 0.1;
	//				}
	//			}

	//			graph4.data.xdata[k][graphIndex - 1] = graph4.data.xdata[k][graphIndex - 1] - 0.01;
	//			if (step == 1)
	//			{
	//				if (graph4.data.xdata[k][graphIndex - 1] > xmin)
	//				{
	//					graph4.data.xdata[k][graphIndex - 1] = graph4.data.xdata[k][graphIndex - 1] + graph4.data.xdata[k][graphIndex - 1] * 0.1;
	//				}
	//			}

	//		}
	//	}
	//}
	//if (nonLinearScaleX == 2) //to scale second part of the graph
	//{
	//	for (int k = 0; k < graph4.data.xdata.size(); k++)
	//	{
	//		if (graph4.data.xdata[k][graphIndex - 1] <= nonLinearGreaterThan)
	//		{
	//			if (step == 1)
	//			{
	//				if (graph4.data.xdata[k][graphIndex - 1] > xmin)
	//				{
	//					graph4.data.xdata[k][graphIndex - 1] = graph4.data.xdata[k][graphIndex - 1] - 0.06;
	//				}
	//				else
	//					graph4.data.xdata[k][graphIndex - 1] = graph4.data.xdata[k][graphIndex - 1] - 0;

	//			}
	//			else if (step == -1)
	//			{
	//				if (graph4.data.xdata[k][graphIndex - 1] > xmin)
	//				{
	//					graph4.data.xdata[k][graphIndex - 1] = graph4.data.xdata[k][graphIndex - 1] + 0.015;
	//				}
	//			}

	//		}
	//		if (graph4.data.xdata[k][graphIndex - 1] > nonLinearGreaterThan)
	//		{
	//			if (step == -1)
	//			{
	//				if (graph4.data.xdata[k][graphIndex - 1] < graph4.data.xmax)
	//					graph4.data.xdata[k][graphIndex - 1] = graph4.data.xdata[k][graphIndex - 1] + graph4.data.xdata[k][graphIndex - 1] * 0.08;
	//			}


	//			else if (step == 1)
	//			{
	//				if (graph4.data.xdata[k][graphIndex - 1] < graph4.data.xmax)
	//					graph4.data.xdata[k][graphIndex - 1] = graph4.data.xdata[k][graphIndex - 1] - 0.015;
	//			}

	//		}
	//	}
	//	
	//}



float scaleFactor = step * 0.10 * graph4.data.graphwidth[graph4.data.graphwidth.size()-1];
graph4.data.graphwidth[graphIndex - 1] = scaleFactor + graph4.data.graphwidth[graphIndex - 1];

for (int i = 0; i < graph4.data.xdata.size(); i++)
{

	if (nonLinearScaleX == 2 && graph4.data.xdata[i][graphIndex - 1] <= nonLinearGreaterThan)
	{
			graph4.data.xdata[i][graphIndex - 1] = graph4.data.xdata[i][graphIndex - 1] - step *0.1* graph4.data.xdata[i][graphIndex - 1];
	
	}
	else if (nonLinearScaleX == 1 && graph4.data.xdata[i][graphIndex - 1] > nonLinearLesserThan && graph4.data.xdata[i][graphIndex - 1]!=1)
	{
		graph4.data.xdata[i][graphIndex - 1] = graph4.data.xdata[i][graphIndex - 1] + step * 0.1 * (1- graph4.data.xdata[i][graphIndex - 1]);
	}
	

}


}




int OpenGLForm::COpenGL3::getNumberOfGraphs()
{
	
	return graph4.data.classsize;
}


System::String^ OpenGLForm::COpenGL3::displayCoordinateLabels(std::vector<int> coordNumber)
{
	//std::vector<int> coordNumber;
	System::String^ coordinateLabels;
	coordinateLabels = gcnew System::String("");
	//std::string::size_type sz;
	//for (int i = 1; i < graph4.data.xlabels.size(); i += 3)
	//{
	//	coordNumber.push_back(graph4.data.xlabels[i] - 48);
	//}
	int count = 1;
	if (coordNumber.size() == NULL)
	{
		for (int i = 1; i < graph4.data.xlabels.size(); i += 3)
	    {
			coordNumber.push_back(graph4.data.xlabels[i] - 48);
	    }
	
	for (int i = 0; i < graph4.data.graphwidth.size()*2; i++)
	{
		
		coordinateLabels = coordinateLabels + "X"  + coordNumber[i] + ", ";
	}	
	}

	else
	{
		coordinateLabels = gcnew System::String("");
		for (int a = 0; a < coordNumber.size(); a++)
		{
			coordinateLabels = coordinateLabels + "X" + coordNumber[a] + ", ";
		}
	}
	return coordinateLabels;
}


void OpenGLForm::COpenGL3::changeScaleY(int graphIndexY, int stepY, int nonLinearScaleY)
{
	

	float scaleFactor = stepY * 0.10 * graph4.data.graphheight[graph4.data.graphheight.size() - 1];
	graph4.data.graphheight[graphIndexY - 1] = scaleFactor + graph4.data.graphheight[graphIndexY - 1];

	for (int i = 0; i < graph4.data.ydata.size(); i++)
	{

		if (nonLinearScaleY == 2 && graph4.data.ydata[i][graphIndexY - 1] <= nonLinearGreaterThan)
		{
			graph4.data.ydata[i][graphIndexY - 1] = graph4.data.ydata[i][graphIndexY - 1] - stepY * 0.1 * graph4.data.ydata[i][graphIndexY - 1];
		}
		else if (nonLinearScaleY == 1 && graph4.data.ydata[i][graphIndexY - 1] > nonLinearLesserThan&& graph4.data.ydata[i][graphIndexY - 1] != 1)
		{
			graph4.data.ydata[i][graphIndexY - 1] = graph4.data.ydata[i][graphIndexY - 1] + stepY * 0.1 * (1 - graph4.data.ydata[i][graphIndexY - 1]);
		}


	}

	

	
}


void OpenGLForm::COpenGL3::showHideLines()
{
	graph4.data.showHideLinesVar = !(graph4.data.showHideLinesVar);
	
}


void OpenGLForm::COpenGL3::nonOrthogonalX()
{
	//std::vector<float> dataOriginalX;
	std::vector<float> dataRadiusX;
	//nonOrthoXAngle = 30;
	float xRadian = -nonOrthoXAngle * (3.14 / 180);

	//if(nonOrthoXDiff >= 0)
	//nonOrthoXDiff = -nonOrthoXDiff * (3.14 / 180);
	//else
	//nonOrthoXDiff = -nonOrthoXDiff * (3.14 / 180);
	nonOrthoXDiff = 30 * (3.14 / 180);
	//std::vector<float> ;
	graph4.data.nonOrthoX2[graph4.graphClicked] = 2 *cos(xRadian) - 1; //-30 degrees
	graph4.data.nonOrthoY2[graph4.graphClicked] = 2* sin(xRadian)  +1;

	//calculate xdata and ydata
	for (int k = 0; k < graph4.data.xdata.size(); k++)
	{
		//dataOriginalX.push_back(graph4.data.xdata[k][graph4.graphClicked]);
		dataRadiusX.push_back(sqrt(pow(graph4.data.xdata[k][graph4.graphClicked],2)));

	}
	for (int k = 0; k < graph4.data.xdata.size(); k++)
	{
		
		graph4.data.xdata[k][graph4.graphClicked] = dataRadiusX[k] * cos(nonOrthoXDiff);
		graph4.data.ydata[k][graph4.graphClicked] = graph4.data.ydata[k][graph4.graphClicked] - dataRadiusX[k] * sin(nonOrthoXDiff);
		//dataRadiusX[k] = 0; 
		//graph4.data.xdata[k][graph4.graphClicked] = graph4.data.xdata[k][graph4.graphClicked]- graph4.data.ydata[k][graph4.graphClicked]*(1/tan(3.14/4));
		//graph4.data.ydata[k][graph4.graphClicked] = graph4.data.ydata[k][graph4.graphClicked] *(1/sin(3.14/4)) ;
		
	}

}


void OpenGLForm::COpenGL3::nonOrthogonalY()
{
	
	std::vector<float> dataRadiusY;	

	float yRadian = (90 - nonOrthoYAngle) * (3.14 / 180);
	if (nonOrthoYDiff >= 0)
		nonOrthoYDiff = -nonOrthoYDiff * (3.14 / 180);
	else
		nonOrthoYDiff = -nonOrthoYDiff * (3.14 / 180);
	//std::vector<float> ;


	graph4.data.nonOrthoX1[graph4.graphClicked] = 2 * cos(yRadian) -1;
	graph4.data.nonOrthoY1[graph4.graphClicked] = -2 * sin(yRadian) +1;

	//calculate xdata and ydata
	for (int k = 0; k < graph4.data.xdata.size(); k++)
	{
		dataRadiusY.push_back(sqrt(pow(graph4.data.ydata[k][graph4.graphClicked], 2)));

	}
	for (int k = 0; k < graph4.data.xdata.size(); k++)
	{

		graph4.data.ydata[k][graph4.graphClicked] = dataRadiusY[k] * sin(yRadian);
		graph4.data.xdata[k][graph4.graphClicked] = graph4.data.xdata[k][graph4.graphClicked] + dataRadiusY[k] * cos(yRadian);


	}
}


void OpenGLForm::COpenGL3::swapCoordinates()
{

	std::vector<std::vector<float>> temp;
	for (int k = 0; k < graph4.data.xdata.size(); k++)
	{
		temp.push_back(graph4.data.xdata[k]);
		graph4.data.xdata[k][graph4.graphClicked] = graph4.data.ydata[k][graph4.graphClicked];
		graph4.data.ydata[k][graph4.graphClicked] = temp[k][graph4.graphClicked];
	}
	

}


void OpenGLForm::COpenGL3::displayClassOnTop(int classNumber)
{
	graph4.data.classToDisplayOnTop = classNumber + 1; 
}


void OpenGLForm::COpenGL3::showHideClass(int classNumber, int hideVar)
{

	for (int i = 0; i < graph4.data.xdata.size(); i++)
	{
		if ((classNumber + 1) == graph4.data.classNum[i])
		{
			graph4.data.dataTransparency[i] = hideVar;
		}
	}
}





void OpenGLForm::COpenGL3::drawRectArea()
{
	if (drawingAndRectEnabled)
	{
		graph4.data.drawAndRect = true;
		graph4.data.drawOrRect = false;

	}

	else if (drawingOrRectEnabled)
	{
		graph4.data.drawOrRect = true;
		graph4.data.drawAndRect = false;
	}

		//if (graph4.data.rectAndCoordx1.size() > 0 && graph4.data.rx2.size() > 0)
		//{
		//	clipAndData(graph4.data.rectAndCoordx1[graph4.data.rectAndCoordx1.size() - 1], graph4.data.rx2[graph4.data.rx2.size() - 1],
		//		graph4.data.rectAndCoordy1[graph4.data.rectAndCoordy1.size() - 1], graph4.data.rectAndCoordy2[graph4.data.rectAndCoordy2.size() - 1]);
		//}
		

}


void OpenGLForm::COpenGL3::clipAndData()
{
	 
	rectx1 = graph4.data.rectAndCoordx1[graph4.data.rectAndCoordx1.size() - 1];
	rectx2 = graph4.data.rectAndCoordx2[graph4.data.rectAndCoordx2.size() - 1];
	recty1 = graph4.data.rectAndCoordy1[graph4.data.rectAndCoordy1.size() - 1];
	recty2 = graph4.data.rectAndCoordy2[graph4.data.rectAndCoordy2.size() - 1];
	
	//for (int i = 0; i < graph4.data.classsize; i++)
	//{
	//	graph4.data.x1CoordGraph.push_back(graph4.data.xgraphcoordinates[i] - graph4.data.graphwidth[i] / 2);
	//	graph4.data.x2CoordGraph.push_back(graph4.data.xgraphcoordinates[i] + graph4.data.graphwidth[i] / 2);
	//	graph4.data.y1CoordGraph.push_back(graph4.data.ygraphcoordinates[i] - graph4.data.graphheight[i] / 2);
	//	graph4.data.y2CoordGraph.push_back(graph4.data.ygraphcoordinates[i] + graph4.data.graphheight[i] / 2);

	//	
	//}

	for (int k = 0; k < graph4.data.classsize; k++)
	{
		if (rectx1 >= graph4.data.x1CoordGraph[k] && rectx1 <= graph4.data.x2CoordGraph[k] && recty1 >= graph4.data.y1CoordGraph[k] && recty1 <= graph4.data.y2CoordGraph[k])
		{
			//MessageBox::Show("In if Loop");
			graph4.data.normAndx1.push_back(((rectx1 - graph4.data.x1CoordGraph[k]) / (graph4.data.x2CoordGraph[k] - graph4.data.x1CoordGraph[k])));
			graph4.data.normAndx2.push_back(((rectx2 - graph4.data.x1CoordGraph[k]) / (graph4.data.x2CoordGraph[k] - graph4.data.x1CoordGraph[k])));
			
			/*****NOTE: In the graph, y coordinate increases while moving down, hence interchanged recty1 and recty2*****/
			graph4.data.normAndy2.push_back(1 - ((recty1 - graph4.data.y1CoordGraph[k]) / (graph4.data.y2CoordGraph[k] - graph4.data.y1CoordGraph[k])));
			graph4.data.normAndy1.push_back(1 - ((recty2 - graph4.data.y1CoordGraph[k]) / (graph4.data.y2CoordGraph[k] - graph4.data.y1CoordGraph[k])));
			graph4.data.graphNumberAnd.push_back(k);
			break;
		}
	}
	for (int j = 0; j < graph4.data.xdata.size(); j++)
	{
		if (graph4.data.xdata[j][graph4.data.graphNumberAnd[graph4.data.graphNumberAnd.size()-1]] < graph4.data.normAndx1[graph4.data.normAndx1.size()-1] || graph4.data.xdata[j][graph4.data.graphNumberAnd[graph4.data.graphNumberAnd.size() - 1]] > graph4.data.normAndx2[graph4.data.normAndx2.size() -1]
			|| graph4.data.ydata[j][graph4.data.graphNumberAnd[graph4.data.graphNumberAnd.size() - 1]] < graph4.data.normAndy1[graph4.data.normAndy1.size() -1] || graph4.data.ydata[j][graph4.data.graphNumberAnd[graph4.data.graphNumberAnd.size() - 1]] > graph4.data.normAndy2[graph4.data.normAndy2.size() -1])
		{
			graph4.data.dataTransparency[j] = 0;
	    }
	   
		
		
	}

}


void OpenGLForm::COpenGL3::clipOrData()
{
	//MessageBox::Show("In ClipOrFunc");
	int tempNo;
	std::vector<int> visibleDataIndex;
	for (int m = 0; m < graph4.data.rectOrCoordx1.size(); m++)
	{
		for(int z = 0; z < graph4.data.classsize; z++)
		{
			if (graph4.data.rectOrCoordx1[m] >= graph4.data.x1CoordGraph[z] && graph4.data.rectOrCoordx1[m] <= graph4.data.x2CoordGraph[z] 
				&& graph4.data.rectOrCoordy1[m] >= graph4.data.y1CoordGraph[z] && graph4.data.rectOrCoordy1[m] <= graph4.data.y2CoordGraph[z] 
				)
			{
				//MessageBox::Show("In if Loop");
				graph4.data.normOrx1.push_back((graph4.data.rectOrCoordx1[m] - graph4.data.x1CoordGraph[z]) / (graph4.data.x2CoordGraph[z] - graph4.data.x1CoordGraph[z]));
				graph4.data.normOrx2.push_back((graph4.data.rectOrCoordx2[m] - graph4.data.x1CoordGraph[z]) / (graph4.data.x2CoordGraph[z] - graph4.data.x1CoordGraph[z]));

				/*****NOTE: In the graph, y coordinate increases while moving down, hence interchanged rectOry1 and rectOry2*****/
				graph4.data.normOry2.push_back(1 - ((graph4.data.rectOrCoordy1[m] - graph4.data.y1CoordGraph[z]) / (graph4.data.y2CoordGraph[z] - graph4.data.y1CoordGraph[z])));
				graph4.data.normOry1.push_back(1 - ((graph4.data.rectOrCoordy2[m] - graph4.data.y1CoordGraph[z]) / (graph4.data.y2CoordGraph[z] - graph4.data.y1CoordGraph[z])));
				graph4.data.graphNumberOr.push_back(z);
				
			}
			
		}

	}

	for (int n = 0; n < (graph4.data.graphNumberOr.size()); n++)
	{
		tempNo = graph4.data.graphNumberOr[n];
		for (int j = 0; j < graph4.data.xdata.size(); j++)
		{
			if (graph4.data.xdata[j][tempNo] >= graph4.data.normOrx1[n] && graph4.data.xdata[j][tempNo] <= graph4.data.normOrx2[n]
				&& graph4.data.ydata[j][tempNo] >= graph4.data.normOry1[n] && graph4.data.ydata[j][tempNo] <= graph4.data.normOry2[n])
			{
				//MessageBox::Show("In if Loop");
				visibleDataIndex.push_back(j);
			}

		}
	}


		
	for (int k = 0; k < visibleDataIndex.size(); k++)
	{
		if (graph4.data.dataTransparency[visibleDataIndex[k]] == 0)
			continue;
		graph4.data.dataTransparency[visibleDataIndex[k]] = 254;

	}

	for (int g = 0; g < graph4.data.xdata.size(); g++)
	{
		if (graph4.data.dataTransparency[g] == 255)
			graph4.data.dataTransparency[g] = 0;
		if(graph4.data.dataTransparency[g] == 254)
			graph4.data.dataTransparency[g] = 255;
	}

}


void OpenGLForm::COpenGL3::displayHdData()
{
	//MessageBox::Show("Setting HDdisplay to true");

	graph4.data.numOfGraphsPerRowHdDisplay = ceil(sqrt(graph4.data.classsize));
	graph4.data.hdDisplay = true;
	bool swtch = false;
	for (int y = 0; y < graph4.data.classsize; y++)
	{
		graph4.data.graphwidth[y] = (worldWidth / (graph4.data.numOfGraphsPerRowHdDisplay+ 2));
		graph4.data.graphheight[y] = (worldHeight / (graph4.data.classsize/graph4.data.numOfGraphsPerRowHdDisplay + 3));
		//graph4.data.graphwidth[y] = (worldWidth / 5);
  //      graph4.data.graphheight[y] = (worldHeight / 5);
	}



	for (int i = 1; i <= graph4.data.numOfGraphsPerRowHdDisplay; i++)
	{		
		//data.xgraphcoordinates.push_back(data.graphwidth[i - 1] * i + i * 0.08 * data.graphwidth[data.graphwidth.size() - 1]);			
		graph4.data.xgraphcoordinates[i - 1]= (graph4.data.graphwidth[i - 1] * i + i * 10);
		graph4.data.ygraphcoordinates[i - 1] = (graph4.data.graphheight[i - 1]);

	    //set coordinates to draw rectangles
		graph4.data.x1CoordGraph[i - 1] = (graph4.data.xgraphcoordinates[i - 1] - graph4.data.graphwidth[i - 1] / 2);
		graph4.data.x2CoordGraph[i - 1] = (graph4.data.xgraphcoordinates[i - 1] + graph4.data.graphwidth[i - 1] / 2);
		graph4.data.y1CoordGraph[i - 1] = (graph4.data.ygraphcoordinates[i - 1] - graph4.data.graphheight[i - 1] / 2);
		graph4.data.y2CoordGraph[i - 1] = (graph4.data.ygraphcoordinates[i - 1] + graph4.data.graphheight[i - 1] / 2);

	}
	int tempIndex = graph4.data.numOfGraphsPerRowHdDisplay;
	float tt =float( graph4.data.classsize / graph4.data.numOfGraphsPerRowHdDisplay);

	for (int k = 1; k < (graph4.data.classsize / graph4.data.numOfGraphsPerRowHdDisplay) + 1; k++)
	{
		swtch = !(swtch);
		for (int j = 1; j <= graph4.data.numOfGraphsPerRowHdDisplay; j++)
		{
			if (swtch)
			{
				graph4.data.xgraphcoordinates[ tempIndex + j - 1] = graph4.data.xgraphcoordinates[graph4.data.numOfGraphsPerRowHdDisplay - 1 -(j - 1)];
			}
			else
			{
				graph4.data.xgraphcoordinates[tempIndex + j - 1] = graph4.data.xgraphcoordinates[j - 1];
			}
		
			graph4.data.ygraphcoordinates[tempIndex + j - 1] = (graph4.data.graphheight[j - 1] * (k+1) + (k +1)* 10);
		}
		tempIndex = tempIndex + graph4.data.numOfGraphsPerRowHdDisplay;
		if (tempIndex >= graph4.data.classsize)
			break;
	}
		
}


void OpenGLForm::COpenGL3::reduceOcclusion()
{
	//int numberOfVisibleLines = 0;
	//double sumOfPointsX = 0;
	//double sumOfPointsY = 0;
	//std::vector<double> tempAvgX, tempAvgY;
	//for (int g = 0; g < graph4.data.graphNumberAnd.size(); g++)
	//{
	//	sumOfPointsX = 0;
	//	sumOfPointsY = 0;
	//	for (int i = 0; i < graph4.data.xdata.size(); i++)
	//	{
	//		if (graph4.data.dataTransparency[i] > 10)
	//		{
	//			numberOfVisibleLines += 1;
	//			sumOfPointsX = sumOfPointsX + graph4.data.xdata[i][graph4.data.graphNumberAnd[g]];
	//			sumOfPointsY = sumOfPointsY + graph4.data.ydata[i][graph4.data.graphNumberAnd[g]];
	//		}


	//		//graph4.data.dataTransparency[i] = 254.9;
	//	}
	//	tempAvgX.push_back(sumOfPointsX / numberOfVisibleLines);
	//	tempAvgY.push_back(sumOfPointsY / numberOfVisibleLines);
	//	numberOfVisibleLines = 0;
	//}

	//for (int g = 0; g < graph4.data.graphNumberAnd.size(); g++)
	//{
	//	for (int i = 0; i < graph4.data.xdata.size(); i++)
	//	{
	//		if (graph4.data.dataTransparency[i] != 0)
	//		{
	//			graph4.data.xdata[i][graph4.data.graphNumberAnd[g]] = tempAvgX[g];
	//			graph4.data.ydata[i][graph4.data.graphNumberAnd[g]] = tempAvgY[g];

	//		}
	//			
	//	}
	//}

	//DELETE BELOW


	int numberOfVisibleLines_g = 0;
	int numberOfVisibleLines_r = 0;

	double sumOfPointsX_g = 0;
	double sumOfPointsY_g = 0;

	double sumOfPointsX_r = 0;
	double sumOfPointsY_r = 0;

	double tempAvgX_g, tempAvgY_g;
	double tempAvgX_r, tempAvgY_r;


		for (int i = 0; i < graph4.data.xdata.size(); i++)
		{
			if (graph4.data.dataTransparency[i] > 100)
			{
				if (graph4.data.classNum[i] == 1)
				{
					numberOfVisibleLines_g += 1;

					sumOfPointsX_g = sumOfPointsX_g + graph4.data.xdata[i][4];
					sumOfPointsY_g = sumOfPointsY_g + graph4.data.ydata[i][4];
					//if (numberOfVisibleLines_g < 20)
					//	graph4.data.dataTransparency[i] = 0;
				}

				if (graph4.data.classNum[i] == 2)
				{
					numberOfVisibleLines_r += 1;

					sumOfPointsX_r = sumOfPointsX_r + graph4.data.xdata[i][4];
					sumOfPointsY_r = sumOfPointsY_r + graph4.data.ydata[i][4];

				}

			}


			//graph4.data.dataTransparency[i] = 254.9;
		}
		tempAvgX_g = (sumOfPointsX_g / numberOfVisibleLines_g);
		tempAvgY_g = (sumOfPointsY_g / numberOfVisibleLines_g);

		tempAvgX_r = (sumOfPointsX_r / numberOfVisibleLines_r);
		tempAvgY_r = (sumOfPointsY_r / numberOfVisibleLines_r);


		for (int i = 0; i < graph4.data.xdata.size(); i++)
		{
			if (graph4.data.dataTransparency[i] > 100)
			{
				if (graph4.data.classNum[i] == 1)
				{
					graph4.data.xdata[i][4] = tempAvgX_g;
					graph4.data.ydata[i][4] = tempAvgY_g-0.01;


				}

				if (graph4.data.classNum[i] == 2)
				{
					graph4.data.xdata[i][4] = tempAvgX_r;
					graph4.data.ydata[i][4] = tempAvgY_r;
				}

			}

		}
	
}




void OpenGLForm::COpenGL3::automateClassification()
{
	std::vector<std::vector<float>> dataPerClass(graph4.data.numOfClasses, { -1 }); //dataPerClass[classNumber - 1][data instance]
	std::vector<float> tempDataVector;

	for (int c = 0; c < graph4.data.xdata.size(); c++)
	{
		for (int d = 1; d <= graph4.data.numOfClasses; d++)
		{
			if (graph4.data.classNum[c] == d)
			{
				if (dataPerClass[d - 1][0] == -1)
				{
					dataPerClass[d - 1][0] = c;
				}
				else
				{
					dataPerClass[d - 1].push_back(c);
				}

			}

		}

	}



	std::vector<std::vector<std::vector<float>>> tempData;
	std::vector<std::vector<float>>tempDatVar;
	std::vector<float> temp;

	for (int p = 1; p <= dataPerClass.size(); p++)
	{
		for (int u = 0; u < dataPerClass[p - 1].size(); u++)
		{
			for (int g = 0; g < graph4.data.xdata[0].size(); g++)
			{
				temp.push_back(graph4.data.xdata[dataPerClass[p - 1][u]][g]);
				temp.push_back(graph4.data.ydata[dataPerClass[p - 1][u]][g]);
			}
			tempDatVar.push_back(temp);
			temp.clear();
		}
		tempData.push_back(tempDatVar);
		tempDatVar.clear();
	}



	// Mean calculation 
	std::vector<float> mean;
	std::vector<std::vector<float>> meanFinal;
	std::vector<std::vector<float>> varianceFinal;
	std::vector<float> variance;
	float tempMeanX = 0, tempVarianceX = 0, tempMeanY = 0, tempVarianceY = 0;
	int m = 0;
	for (int b = 0; b < tempData.size(); b++)
	{
		m = 0;
		for (int q = 0; q < tempData[b][m].size(); q++)
		{
			for (int z = 0; z < tempData[b].size(); z++)
			{
				tempMeanX += tempData[b][z][q];
			}
			tempMeanX = tempMeanX / tempData[b].size();

			mean.push_back(tempMeanX);

			tempMeanX = 0;
		}
		m += 1;
		meanFinal.push_back(mean);
		mean.clear();
	}

	//Variance calculation
	int h = 0;
	for (int g = 0; g < tempData.size(); g++)
	{
		h = 0;
		for (int w = 0; w < tempData[g][h].size(); w++)
		{
			for (int a = 0; a < tempData[g].size(); a++)
			{
				tempVarianceX += (tempData[g][a][w] - meanFinal[g][w]) * (tempData[g][a][w] - meanFinal[g][w]);
			}
			tempVarianceX = tempVarianceX / tempData[g].size();
			variance.push_back(tempVarianceX);
			tempVarianceX = 0;

		}
		h += 1;
		varianceFinal.push_back(variance);
		variance.clear();
	}



	//calculate Coefficient of Variance
	std::vector<float> cTemp;

	std::vector<std::vector<float>> coefficientOfVariance;
	for (int cov = 0; cov < meanFinal.size(); cov++)
	{
		for (int cv = 0; cv < meanFinal[0].size(); cv++)
		{
			//tempCOV = sqrtf(varianceFinal[cov][cv]) ;
			cTemp.push_back(sqrtf(varianceFinal[cov][cv]) / meanFinal[cov][cv]);
		}
		coefficientOfVariance.push_back(cTemp);
		cTemp.clear();
	}

	//calculate the mean of COVs per coordinate
	std::vector<std::vector<float>> covScore(2, coefficientOfVariance[0]);
	float tmpCOV = 0;
	for (int cs = 0; cs < coefficientOfVariance[0].size(); cs++)
	{
		for (int c = 0; c < coefficientOfVariance.size(); c++)
		{
			tmpCOV += coefficientOfVariance[c][cs];
		}
		tmpCOV = tmpCOV / coefficientOfVariance.size();
		covScore[0][cs] = tmpCOV;
		covScore[1][cs] = cs;
		
		tmpCOV = 0;

	}


	//not ok
	float temp1, temp2;
	for (int iv = 0; iv < covScore[0].size(); iv++)
	{
		for (int jv = iv + 1; jv < covScore[0].size(); jv++)
		{
			if (covScore[0][iv] >= covScore[0][jv])
			{
				temp1 = covScore[0][iv];
				temp2 = covScore[1][iv];
				covScore[0][iv] = covScore[0][jv];
				covScore[1][iv] = covScore[1][jv];
				covScore[0][jv] = temp1;
				covScore[1][jv] = temp2;

			}

		}
		graph4.data.covScore.push_back(covScore[1][iv]);
	}


	//Arrange coordinates as per covScore

	std::vector<float> covScoreX, covScoreY;
	for (int kv = 0; kv < covScore[1].size() * 0.5; kv++)
	{
		covScoreX.push_back(covScore[1][covScore[1].size() * 0.5 + kv]);
		covScoreY.push_back(covScore[1][kv]);
	}

	////Reassign and redraw data as per new coordinate Orders
	float tempCoordX=0, tempCoordY=0;
	int inX, inY, switchX, switchY;
	std::vector<float> tmpDtX;
	std::vector<std::vector<float>> tmpDatX(graph4.data.xdata.size(), graph4.data.xdata[0]);
	std::vector<float> tmpDtY;
	std::vector<std::vector<float>> tmpDatY(graph4.data.ydata.size(), graph4.data.ydata[0]);
	for (int ji = 0; ji < graph4.data.xdata[0].size(); ji++)
	{
		
		inX = covScoreX[ji];
		inY = covScoreY[ji];
		if (inX % 2 == 0)
		{
			//if (inX >= graph4.data.xdata[0].size())
				inX = inX / 2;
		}
		else
		{
			//if (inX >= graph4.data.xdata[0].size())
			inX = (inX - 1) / 2; switchX = 1;
		}
		if (inY % 2 != 0)
		{
			//if (inY >= graph4.data.ydata[0].size())
				inY = (inY - 1) / 2;

		}
		else
		{
			//if (inY >= graph4.data.ydata[0].size())
				inY = inY / 2;
				switchY = 1;
		}
		for  (int ig = 0; ig < graph4.data.xdata.size(); ig++)
		{
			
		
			if (switchX == 1)
			{
				tmpDatX[ig][ji] = graph4.data.ydata[ig][inX];
			}
			else
			{
				tmpDatX[ig][ji] = graph4.data.xdata[ig][inX];
			}

			if (switchY == 1)
			{
				tmpDatY[ig][ji] = graph4.data.xdata[ig][inY];
			}
			else
			{
				tmpDatY[ig][ji] = graph4.data.ydata[ig][inY];
			}
			
			
		}



		switchX = 0; switchY = 0;
	}




	////UNCOMMENT


	for (int gr = 0; gr < graph4.data.xdata[0].size(); gr++)
	{
		for (int n = 0; n < graph4.data.xdata.size(); n++)
		{
			graph4.data.xdata[n][gr] = tmpDatX[n][gr];
			graph4.data.ydata[n][gr] = tmpDatY[n][gr];
		}
	}



	 //Rearrange the classes per number of variance
	std::vector<float> t;
	for (int i = 0; i < graph4.data.numOfClasses; i++)
	{
		t.push_back(i);
	}
	std::vector<std::vector<float>> varClass(2, t);
	t.clear();

	float tmp =0;
	for (int va = 0; va < varianceFinal.size(); va++)
	{
		for (int ca = 0; ca < varianceFinal[0].size(); ca++)
		{
			tmp += varianceFinal[va][ca];
		}
		tmp = tmp / varianceFinal[0].size();
		varClass[0][va] = tmp;
		varClass[1][va] = va;
		tmp = 0;

	}

	for (int iv = 0; iv < varClass[0].size(); iv++)
	{
		for (int jv = iv + 1; jv < varClass[0].size(); jv++)
		{
			
			if (varClass[0][iv] >= varClass[0][jv])
			{
				temp1 = varClass[0][iv];
				temp2 = varClass[1][iv];
				varClass[0][iv] = varClass[0][jv];
				varClass[1][iv] = varClass[1][jv];
				varClass[0][jv] = temp1;
				varClass[1][jv] = temp2;
				

			}
			
		}
	}




	//
	//find rect coordinates limits for drawing rectangles
	float tmpXmax = 0, tmpXmin = 1, tmpYmax = 0, tmpYmin = 1;
	std::vector<std::vector<float>> x1CoordL, x2CoordL, y1CoordL, y2CoordL; // x1CoordL[class][graphNumber]
	std::vector<float> x1Coordt, x2Coordt, y1Coordt, y2Coordt;
	for (int n = 0; n < tempData.size(); n++)
	{
		
		for (int i = 0; i < covScoreX.size(); i++)
		{
			tmpXmax = 0, tmpXmin = 1,tmpYmax = 0, tmpYmin = 1;
			for  (int m = 0; m < tempData[varClass[1][n]].size(); m++)
			{
		
				if (tempData[varClass[1][n]][m][covScoreX[i]] < tmpXmin)
					tmpXmin = tempData[varClass[1][n]][m][covScoreX[i]];
				if (tempData[varClass[1][n]][m][covScoreX[i]]!=1 && tempData[varClass[1][n]][m][covScoreX[i]] > tmpXmax)
					tmpXmax = tempData[varClass[1][n]][m][covScoreX[i]];

				if (tempData[varClass[1][n]][m][covScoreY[i]] < tmpYmin)
					tmpYmin = tempData[varClass[1][n]][m][covScoreY[i]];
				if (tempData[varClass[1][n]][m][covScoreY[i]]!= 1 && tempData[varClass[1][n]][m][covScoreY[i]] > tmpYmax)
					tmpYmax = tempData[varClass[1][n]][m][covScoreY[i]];
			}

			if (tmpXmin == 0 && tmpXmax == 1 && tmpYmin == 0 && tmpYmax == 1)
			{
				tmpXmin = 0, tmpXmax = 0;
				tmpYmin = 0, tmpYmax = 0;
			}

			x1Coordt.push_back(tmpXmin);
			x2Coordt.push_back(tmpXmax);
			y1Coordt.push_back(tmpYmin);
			y2Coordt.push_back(tmpYmax);
		
	
		}
	
		x1CoordL.push_back(x1Coordt);
		x2CoordL.push_back(x2Coordt);
		y1CoordL.push_back(y1Coordt);
		y2CoordL.push_back(y2Coordt);
		x1Coordt.clear();
		x2Coordt.clear();
		y1Coordt.clear();
		y2Coordt.clear();
		

	}





 // //Uncomment this below to draw the max limit of the rectangle
 //float r=255, g=255, b=0;
	//for (int c = 0; c < x1Coord.size(); c++)
	//{
	//	
	//	for (int s = 0; s < x1Coord[c].size(); s++) //classsize = number of graphs
	//	{
	//		graph4.data.rectAndCoordx1.push_back(graph4.data.x1CoordGraph[s] + x1Coord[c][s] * graph4.data.graphwidth[s]);
	//		graph4.data.rectAndCoordx2.push_back(graph4.data.x1CoordGraph[s] + x2Coord[c][s] * graph4.data.graphwidth[s]);
	//		graph4.data.rectAndCoordy1.push_back(graph4.data.y2CoordGraph[s] - y1Coord[c][s] * graph4.data.graphheight[s]);
	//		graph4.data.rectAndCoordy2.push_back(graph4.data.y2CoordGraph[s] - y2Coord[c][s] * graph4.data.graphheight[s]);
	//		graph4.data.rectR.push_back(r);
	//		graph4.data.rectG.push_back(g);
	//		graph4.data.rectB.push_back(b);
	//	}
	//	
	//	r = rand() % 256;
	//	g = rand() % 256;
	//	b = rand() % 256;
	//}

	
	std::vector<std::vector<float>> x1Coord, x2Coord, y1Coord, y2Coord;
	std::vector<float> randomRectCoordX1, randomRectCoordX2, randomRectCoordY1, randomRectCoordY2;

	// Drawing 10 random rectangles rectangles per graph
	//BELOW GENERATES RANDOM RECTANGLES FOR JUST A PARTICULAR CLASS x2CoordL[class][g] -> Change class each time 

	for (int r = 0; r < 10; r++)
	{
		for (int g = 0; g < graph4.data.classsize; g++)//classsize = number of graphs
		{
			//srand(time(NULL));
			randomRectCoordX1.push_back(x1CoordL[0][g] + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (x2CoordL[0][g] - x1CoordL[0][g]-0.1))));
			randomRectCoordX2.push_back(randomRectCoordX1[g] + 0.1);
			randomRectCoordY1.push_back(y1CoordL[0][g] + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (y2CoordL[0][g] - y1CoordL[0][g] - 0.1))));
			randomRectCoordY2.push_back(randomRectCoordY1[g] + 0.1);
		}

		x1Coord.push_back(randomRectCoordX1);
		x2Coord.push_back(randomRectCoordX2);
		y1Coord.push_back(randomRectCoordY1);
		y2Coord.push_back(randomRectCoordY2);

		randomRectCoordX1.clear();
		randomRectCoordX2.clear();
		randomRectCoordY1.clear();
		randomRectCoordY2.clear();
	}







	//Manually adding coordinates
	//NOTEPAD CODE HERE


	x1Coord.clear();
	x2Coord.clear();
	y1Coord.clear();
	y2Coord.clear();



	//x1Coord = { {0.0,  0.1,  0.00, 0.0, 0.18}, {0, 0, 0, 0, 0.15}, {0, 0, 0, 0, 0.16 }, {0, 0, 0, 0, 0.00 } };
	//x2Coord = { {0.2,  0.3,  0.00, 0.0, 0.3 }, {0, 0, 0, 0, 0.3 }, {0, 0, 0, 0, 0.28 }, {0, 0, 0, 0, 0.11 } };
	//y1Coord = { {0.0,  0.19, 0.00, 0.0, 0.36}, {0, 0, 0, 0, 0.45}, {0, 0, 0, 0, 0.22 }, {0, 0, 0, 0, 0.00 } };
	//y2Coord = { {0.1,  0.52, 0.00, 0.0, 0.4 }, {0, 0, 0, 0, 0.5 }, {0, 0, 0, 0, 0.28 }, {0, 0, 0, 0, 0.60 } };
	x1Coord = { {0.0,  0.1,   0.18}, {0, 0,  0.15}, {0, 0,  0.16 }, {0, 0, 0.00 } };
	x2Coord = { {0.2,  0.3,  0.3 }, {0, 0,  0.3 }, {0, 0,  0.28 }, {0, 0, 0.11 } };
	y1Coord = { {0.0,  0.19,  0.36}, {0, 0,  0.45}, {0, 0,  0.22 }, {0, 0, 0.00 } };
	y2Coord = { {0.1,  0.52,  0.4 }, {0, 0,  0.5 }, {0, 0, 0.28 }, {0, 0, 0.60 } };

	float r = 0, g = 0, b = 0;
	for (int s = 0; s < x1Coord[0].size(); s++)
	{

		for (int c = 0; c < x1Coord.size(); c++) //classsize = number of graphs
		{
			graph4.data.rectAndCoordx1.push_back(graph4.data.x1CoordGraph[s] + x1Coord[c][s] * graph4.data.graphwidth[s]);
			graph4.data.rectAndCoordx2.push_back(graph4.data.x1CoordGraph[s] + x2Coord[c][s] * graph4.data.graphwidth[s]);
			graph4.data.rectAndCoordy1.push_back(graph4.data.y2CoordGraph[s] - y1Coord[c][s] * graph4.data.graphheight[s]);
			graph4.data.rectAndCoordy2.push_back(graph4.data.y2CoordGraph[s] - y2Coord[c][s] * graph4.data.graphheight[s]);
			graph4.data.rectR.push_back(r);
			graph4.data.rectG.push_back(g);
			graph4.data.rectB.push_back(b);
		}

		/*	r = rand() % 256;
			g = rand() % 256;
			b = rand() % 256;*/
	}



	//std::vector<std::vector<float>> x1coordand, x2coordand, y1coordand, y2coordand;

	//x1coordand = { {0, -1, -1, -1,  -1} };
	//x2coordand = { {0.15, -1, -1, -1, -1 } };
	//y1coordand = { {0, -1, -1, -1, -1 } };
	//y2coordand = { {0.03, -1, -1, -1, -1 } };

	//for (int i = 0; i < x1coordand.size(); i++)
	//{
	//	for (int h = 0; h < x1coordand[0].size(); h++)
	//	{
	//		for (int j = 0; j < graph4.data.xdata.size(); j++)
	//		{
	//			if ((graph4.data.xdata[j][h] >= x1coordand[i][h] && graph4.data.xdata[j][h] <= x2coordand[i][h]
	//				&& graph4.data.ydata[j][h] >= y1coordand[i][h] && graph4.data.ydata[j][h] <= y2coordand[i][h]))
	//			{
	//				graph4.data.dataTransparency[j] = 250;
	//			}

	//		}
	//	}

	//}


	//for (int j = 0; j < graph4.data.xdata.size(); j++)
	//{
	//	if (graph4.data.dataTransparency[j] == 255)
	//	{
	//		graph4.data.dataTransparency[j] = 0;
	//	}

	//}




	//////Setting transparency to 0 with the coords outside of the rectangle
	//std::vector<std::vector<float>> x1CoordOR, x2CoordOR, y1CoordOR, y2CoordOR;


	//x1CoordOR = { {-1, 0.1, -1, -1,-1} };
	//x2CoordOR = { {-1, 0.3, -1, -1, -1} };
	//y1CoordOR = { {-1, 0.15, -1, -1, -1} };
	//y2CoordOR = { {-1, 0.52, -1, -1, -1} };

	//for (int i = 0; i < x1CoordOR.size(); i++)
	//{
	//	for (int h = 0; h < x1CoordOR[0].size(); h++)
	//	{
	//		for (int j = 0; j < graph4.data.xdata.size(); j++)
	//		{
	//			if (graph4.data.dataTransparency[j] == 250 && x1CoordOR[i][h] != -1)
	//			{
	//				if ((graph4.data.xdata[j][h] >= x1CoordOR[i][h] && graph4.data.xdata[j][h] <= x2CoordOR[i][h]
	//					&& graph4.data.ydata[j][h] >= y1CoordOR[i][h] && graph4.data.ydata[j][h] <= y2CoordOR[i][h]))
	//				{
	//					graph4.data.dataTransparency[j] = 245;
	//				}
	//			}

	//		}
	//	}

	//}

	//for (int j = 0; j < graph4.data.xdata.size(); j++)
	//{
	//	if (graph4.data.dataTransparency[j] == 250)
	//	{
	//		graph4.data.dataTransparency[j] = 0;
	//	}

	//}


	////   //3rd Rect 

	//   std::vector<std::vector<float>> x1CoordOR1, x2CoordOR1, y1CoordOR1, y2CoordOR1;


	//   x1CoordOR1 = { {-1,-1,-1,-1, 0.18}, {-1,-1,-1,-1, 0.15}, {-1,-1,-1,-1, 0.16} };
	//   x2CoordOR1 = { {-1,-1,-1,-1, 0.3}, {-1,-1,-1,-1, 0.3}, {-1,-1,-1,-1, 0.28} };
	//   y1CoordOR1 = { {-1,-1,-1,-1, 0.36}, {-1,-1,-1,-1, 0.45}, {-1,-1,-1,-1, 0.22} };
	//   y2CoordOR1 = { {-1,-1,-1,-1, 0.4}, {-1,-1,-1,-1, 0.5}, {-1,-1,-1,-1, 0.28} };

	//   for (int i = 0; i < x1CoordOR1.size(); i++)
	//   {
	//   	for (int h = 0; h < x1CoordOR1[0].size(); h++)
	//   	{
	//   		for (int j = 0; j < graph4.data.xdata.size(); j++)
	//   		{
	//   			if (graph4.data.dataTransparency[j] == 245 && x1CoordOR1[i][h] != -1)
	//   			{
	//   				if ((graph4.data.xdata[j][h] >= x1CoordOR1[i][h] && graph4.data.xdata[j][h] <= x2CoordOR1[i][h]
	//   					&& graph4.data.ydata[j][h] >= y1CoordOR1[i][h] && graph4.data.ydata[j][h] <= y2CoordOR1[i][h]))
	//   				{
	//   					graph4.data.dataTransparency[j] = 240;
	//   				}
	//   			}

	//   		}
	//   	}

	//   }

	//   for (int j = 0; j < graph4.data.xdata.size(); j++)
	//   {
	//   	if (graph4.data.dataTransparency[j] == 245)
	//   	{
	//   		graph4.data.dataTransparency[j] = 0;
	//   	}

	//   }



	   //std::vector<std::vector<float>> x1CoordN, x2CoordN, y1CoordN, y2CoordN;
	   //x1CoordN = { {-1, -1, 0.58,  0.32} };
	   //x2CoordN = { {-1, -1, 0.72, 0.4 } };
	   //y1CoordN = { {-1, -1,  0.25, 0.25 } };
	   //y2CoordN = { {-1, -1, 0.35, 0.3} };

	   //for (int i = 0; i < x1CoordN.size(); i++)
	   //{
	   //	for (int h = 0; h < x1CoordN[0].size(); h++)
	   //	{
	   //		for (int j = 0; j < graph4.data.xdata.size(); j++)
	   //		{
	   //			if (graph4.data.dataTransparency[j] == 240 && x1CoordN[i][h] != -1)
	   //			{
	   //				if ((graph4.data.xdata[j][h] >= x1CoordN[i][h] && graph4.data.xdata[j][h] <= x2CoordN[i][h]
	   //					&& graph4.data.ydata[j][h] >= y1CoordN[i][h] && graph4.data.ydata[j][h] <= y2CoordN[i][h]))
	   //				{
	   //					graph4.data.dataTransparency[j] = 0;
	   //				}
	   //			}

	   //		}
	   //	}

	   //}










//END OF NOTEPAD CODE

//to count number of imntances visible (right classification)
int instancesC = 0;
for (int j = 0; j < graph4.data.xdata.size(); j++)
{
	if (graph4.data.dataTransparency[j] != 0)
	{
		instancesC++;
	}

}

	std::ofstream myfile("bcData.csv");
	
	for (int n = 0; n < graph4.data.xdata.size(); n++)
	{
		if (graph4.data.dataTransparency[n] < 10)
		{
			for (int m = 0; m < graph4.data.xdata[0].size(); m++)
			{
				myfile << graph4.data.xdata[n][m]<<"\t" << graph4.data.ydata[n][m]<< "\t";
			}
			myfile << "\t"<< graph4.data.classNum[n] << "\t"<<n<< std::endl;
		}

	}


	std::ofstream myfile3("bcDataWithinRect.csv");

	for (int n = 0; n < graph4.data.xdata.size(); n++)
	{
		if (graph4.data.dataTransparency[n] > 0)
		{
			for (int m = 0; m < graph4.data.xdata[0].size(); m++)
			{
				myfile3 << graph4.data.xdata[n][m] << "\t" << graph4.data.ydata[n][m] << "\t";
			}
			myfile3 << "\t" << graph4.data.classNum[n] << "\t" << n << std::endl;
		}

	}

	MessageBox::Show("DONE!!!!!");
	//write optimized coordinates to csv file
	//std::ofstream myfile2("optimizedCoordinateOrder.csv");

	//for (int m = 0; m < covScore[0].size(); m++)
	//{
	//	{
	//		myfile2 << covScore[0][m] << "\t" << covScore[1][m]+70 << std::endl;
	//	}
	//}


	/*std::vector<std::vector<float>> instances(2);
	int class1, class2;
		for (int m = 0; m < x1Coord.size(); m++)
		{
			
			for (int j = 0; j < graph4.data.xdata[0].size(); j++)
			{
				
				for (int i = 0; i < graph4.data.xdata.size(); i++)
				{
					if (graph4.data.xdata[i][j] >= x1Coord[m][j] && graph4.data.xdata[i][j] <= x2Coord[m][j]
						&& graph4.data.ydata[i][j] >= y1Coord[m][j] && graph4.data.ydata[i][j] <= y2Coord[m][j])
					{
						if (graph4.data.classNum[i] == 1)
						{
							class1++;
						}
						else if(graph4.data.classNum[i] == 2)
							class2++;
					}
					
				}

				instances[0].push_back(class1);
				instances[1].push_back(class2);
				class1 = 0; class2 = 0;
			}


		}
	

	std::ofstream myfile1("bc_rectCoord.csv");
	int it = 0;
	for (int m = 0; m < x1Coord.size(); m++)
	{
		for (int n = 0; n < x1Coord[0].size(); n++)
		{
			myfile1 << x1Coord[m][n] << "\t" << y1Coord[m][n] << "\t"<<x2Coord[m][n] << "\t" << y2Coord[m][n] << "\t" << instances[0][it] << "\t" << instances[1][it] << "\t";
			myfile1  << n + 1 << std::endl;
			myfile1 << instancesC<< std::endl;
			it++;
		}
		
	}*/
}
