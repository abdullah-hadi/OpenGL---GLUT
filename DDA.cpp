#include<stdio.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<math.h>

void display_line_dda(void)
{
    glClearColor(1.0,1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    double x1 = 50, x2 = 400, y1 = 50, y2 = 400;
    double dy, dx, step, x, y, incX, incY;
    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy))
    {
        step = abs(dx);
    }
    else
    {
        step = abs(dy);
    }

    incX = dx / step;
    incY = dy / step;

    x = x1;
    y = y1;

    for (int i = 1; i <= step; i++)
    {
        glColor3f(0,0,1);
        glPointSize(5);
        glBegin(GL_POINTS);
        glVertex2f(x, y); //plot all the point till the last point
        glEnd();

        x = x + incX;
        y = y + incY;

    }

    glFlush();

}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line");
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
    glutDisplayFunc(display_line_dda);
    glutMainLoop();

    return 0;
}
