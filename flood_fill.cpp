#include <GL/glut.h>
#include<bits/stdc++.h>
using namespace std;
#define PI 3.14

vector<int> x;
vector<int> y;
int vertex; // number of vertices
int radius = 50;

int Xc = 200;
int Yc = 200;

struct Color{
    GLfloat red;
    GLfloat green;
    GLfloat blue;
};
Color boundColor = {1.0, 0.0, 0.0}; // red boundary
Color backgroundColor = {0.0, 0.0, 0.0}; // black background
Color insideColor = {1.0, 1.0, 1.0}; // fill inside with white color

void generatePolygonPoints(){
    // generate all the vertices of the polygon
    for(int i=1; i<=vertex; i++){
		int currx = (int)(Xc + radius * cos(((i-1)*2.0*PI)/vertex));
		int curry = (int)(Yc + radius * sin(((i-1)*2.0*PI)/vertex));
        x.push_back(currx); // store them in x, y

        y.push_back(curry);
    }
}

// function draws a line between two points
void lineDraw(int a1, int b1, int a2, int b2){
	glBegin(GL_LINES); // inbuilt function to draw a line
	glVertex2i(a1, b1);
	glVertex2i(a2, b2);
	glEnd();
}

// for each pair of consecutive points, draw a line
void drawPolygon(){
    for (int i=0; i<(vertex-1); i++)
        lineDraw(x[i], y[i], x[i+1], y[i+1]); // passing consecutive pair of points
	// connects the last vertex to the first vertex
    lineDraw(x[vertex-1], y[vertex-1], x[0], y[0]);
}


Color getColorPixel(GLint pointX, GLint pointY){
	Color pointColor;
    // used to return pixel data
	glReadPixels(pointX, pointY, 1, 1, GL_RGB, GL_FLOAT, &pointColor);
	return pointColor;
}

void fillColorPixel(GLint pointX, GLint pointY){
    // set color of a pixel to be the internal color
	glColor3f(1, 1, 1);
	glBegin(GL_POINTS);
	glVertex2i(pointX, pointY); // draw the point (internal to the polygon)
	glEnd();
	glFlush();
}

// fill inside of polygon using flood fill algorithm
void FloodFill(int currX, int currY){

	Color currentColor = getColorPixel(currX, currY);
    if (currentColor.green == backgroundColor.green && currentColor.blue == backgroundColor.blue && currentColor.red == backgroundColor.red)
    {
        fillColorPixel(currX, currY);
        FloodFill(currX + 1, currY);
        FloodFill(currX, currY + 1);
        FloodFill(currX - 1, currY);
        FloodFill(currX, currY - 1);
        return;
    }
    else
		return;

}

// function used to display all points on the window
void disp(){
	glColor3f(1, 0, 0); // color red used for drawing the boundary of the polygon
    drawPolygon(); // draw the boundary polygon
	FloodFill(Xc, Yc); // fill the inside using Flood Fill algorithm
    glFlush();
}

int main(int argc, char **argv){

    cout<<"Enter the number of vertices of the regular polygon.\n";
    cin>>vertex;
    generatePolygonPoints(); // center of screen

    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(400, 400); // display window size
	glutInitWindowPosition(800, 150); // display window popping position
	glutCreateWindow("Flood Fill Algorithm"); // title of the window
	gluOrtho2D(0, 400, 0, 400); // orthographic window boundary defined
    glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT); // clears existing buffer values

	glutDisplayFunc(disp); // calling the display function
	glutMainLoop(); // refreshes the window if there is any change
	return 0;
}