#include <stdio.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>

void display_line_direct(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    double x1 = 50, x2 = 400, y1 = 50, y2 = 400;

    glColor3f(0, 0, 1);
    glBegin(GL_POINTS);

    if (x1 == x2)
    {
        for (double y = y1; y <= y2; y++)
        {
            glVertex2f(x1, y);
        }
    }
    else
    {
        double m = (y2 - y1) / (x2 - x1);
        double c = y1 - m * x1;

        for (double x = x1; x <= x2; x++)
        {
            double y = m * x + c;
            glVertex2f(x, y);
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
    glutCreateWindow("direct-eq-201-115-075");
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
    glutDisplayFunc(display_line_direct);
    glutMainLoop();

    return 0;
}
