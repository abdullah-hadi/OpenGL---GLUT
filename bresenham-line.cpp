#include <stdio.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>

void display(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    int x1 = 50, x2 = 400, y1 = 50, y2 = 400;
    glColor3f(0, 0, 1);
    glBegin(GL_POINTS);
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int two_dy = 2 * dy;
    int two_dx = 2 * dx;
    int slope_error = 0;
    int x = x1, y = y1;

    if (dx >= dy)
    {
        int y_step = (y2 > y1) ? 1 : -1;
        int y_end = (y2 > y1) ? y2 : y1;

        if (x2 < x1)
        {
            x = x2;
            y = y2;
            x2 = x1;
        }
        for (; x <= x2; x++)
        {
            glVertex2i(x, y);
            slope_error += two_dy;
            if (slope_error >= dx)
            {
                y += y_step;
                slope_error -= two_dx;
            }
        }
    }
    else
    {
        int x_step = (x2 > x1) ? 1 : -1;
        int x_end = (x2 > x1) ? x2 : x1;

        if (y2 < y1)
        {
            x = x2;
            y = y2;
            y2 = y1;
        }

        for (; y <= y2; y++)
        {
            glVertex2i(x, y);
            slope_error += two_dx;
            if (slope_error >= dy)
            {
                x += x_step;
                slope_error -= two_dy;
            }
        }
    }

    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham-line-201-115-075");
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
