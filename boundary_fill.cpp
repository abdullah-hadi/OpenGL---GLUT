#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265
int centerX = 200;
int centerY = 200;
int radius = 100;

struct Color { GLfloat red; GLfloat purple; GLfloat blue; };
Color boundColor = { 1.0, 0.0, 0.0 };
Color insideColor = { 0.12, 0, 0.12 };

Color getColorPixel(GLint pointX, GLint pointY) {
    Color pointColor;
    glReadPixels(pointX, pointY, 1, 1, GL_RGB, GL_FLOAT, &pointColor);
    return pointColor;
}

void fillColorPixel(GLint pointX, GLint pointY) {
    glColor3f(insideColor.red, insideColor.purple, insideColor.blue);
    glBegin(GL_POINTS);
    glVertex2i(pointX, pointY);
    glEnd();
    glFlush();
}

void BoundaryFill(int currX, int currY) {
    Color currentColor = getColorPixel(currX, currY);
    if (currentColor.red != boundColor.red || currentColor.purple != boundColor.purple || currentColor.blue != boundColor.blue) {
        if (currentColor.red != insideColor.red || currentColor.purple != insideColor.purple || currentColor.blue != insideColor.blue) {
            fillColorPixel(currX, currY);
            BoundaryFill(currX + 1, currY);
            BoundaryFill(currX, currY + 1);
            BoundaryFill(currX - 1, currY);
            BoundaryFill(currX, currY - 1);
        }
    }
}

void drawCircle() {
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;
    while (x <= y) {
        glVertex2i(centerX + x, centerY + y);
        glVertex2i(centerX - x, centerY + y);
        glVertex2i(centerX + x, centerY - y);
        glVertex2i(centerX - x, centerY - y);
        glVertex2i(centerX + y, centerY + x);
        glVertex2i(centerX - y, centerY + x);
        glVertex2i(centerX + y, centerY - x);
        glVertex2i(centerX - y, centerY - x);
        x++;
        if (d < 0) { d = d + 4 * x + 6; }
        else { y--; d = d + 4 * (x - y) + 10; }
    }
}

void disp() {
    glColor3f(boundColor.red, boundColor.purple, boundColor.blue);
    glBegin(GL_POINTS);
    drawCircle();
    glEnd();
    BoundaryFill(centerX, centerY);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(800, 150);
    glutCreateWindow("Circle Boundary Fill Algorithm 201-115-020");
    gluOrtho2D(0, 400, 0, 400);
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(disp);
    glutMainLoop();
    return 0;
}
