#include <stdio.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>

void display(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    int center_x = 320, center_y = 240;
    int radius = 100;
    glColor3f(0, 0, 1);
    glBegin(GL_POINTS);

    int x = 0;
    int y = radius;
    int decision = 1 - radius;

    while (y >= x)
    {
        glVertex2i(center_x + x, center_y + y);
        glVertex2i(center_x - x, center_y + y);
        glVertex2i(center_x + x, center_y - y);
        glVertex2i(center_x - x, center_y - y);
        glVertex2i(center_x + y, center_y + x);
        glVertex2i(center_x - y, center_y + x);
        glVertex2i(center_x + y, center_y - x);
        glVertex2i(center_x - y, center_y - x);

        x++;

        if (decision <= 0)
        {
            decision += 2 * x + 1;
        }
        else
        {
            y--;
            decision += 2 * (x - y) + 1;
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
    glutInitWindowPosition(400, 350);
    glutCreateWindow("Midpoint-Circle_201-115-075");
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
