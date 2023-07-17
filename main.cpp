#include<windows.h>
#include<GL/glut.h>
#include<math.h>

void display(void)
{

    glClearColor(0.89, 0.906, 0.922, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);


    //home
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.7f, -0.7f);
    glVertex2f(-0.7f, 0.2f);
    glVertex2f(0.0f, 0.6f);
    glVertex2f(0.7f, 0.2f);
    glVertex2f(0.7f, -0.7f);
    glEnd();

    //door
    glBegin(GL_QUADS);
    glColor3f(1, 0.773, 0.141);
    glVertex2f(-0.55f, -0.7f);
    glVertex2f(-0.55f, 0.1f);
    glVertex2f(-0.1f, 0.1f);
    glVertex2f(-0.1f, -0.7f);
    glEnd();

    //door knob 
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    GLfloat radius = 0.027f;
    GLfloat X = -0.195f;
    GLfloat Y = -0.245f;
    int numSegments = 100;

    for (int i = 0; i <= numSegments; ++i) {
        GLfloat angle = static_cast<GLfloat>(i) * (2.0f * M_PI / numSegments);
        GLfloat x = X + radius * cos(angle);
        GLfloat y = Y + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();


    //window1
    glBegin(GL_QUADS);
    glColor3f(1, 0.714, 0);
    glVertex2f(0.1f, -0.1f);
    glVertex2f(0.1f, 0.1f);
    glVertex2f(0.3f, 0.1f);
    glVertex2f(0.3f, -0.1f);
    glEnd();

    //window2
    glBegin(GL_QUADS);
    glVertex2f(0.4f, -0.1f);
    glVertex2f(0.4f, 0.1f);
    glVertex2f(0.6f, 0.1f);
    glVertex2f(0.6f, -0.1f);
    glEnd();


    //window3
    glBegin(GL_QUADS);
    glVertex2f(0.1f, -0.4f);
    glVertex2f(0.1f, -0.2f);
    glVertex2f(0.3f, -0.2f);
    glVertex2f(0.3f, -0.4f);
    glEnd();

    //window4
    glBegin(GL_QUADS);
    glVertex2f(0.4f, -0.4f);
    glVertex2f(0.4f, -0.2f);
    glVertex2f(0.6f, -0.2f);
    glVertex2f(0.6f, -0.4f);
    glEnd();


    //roofLeft
    glBegin(GL_QUADS);
    glColor3f(0.918, 0.031, 0.153);
    glVertex2f(-0.85f, 0.15f);
    glVertex2f(-0.9f, 0.215f);
    glVertex2f(0.0f, 0.752f);
    glVertex2f(0.0f, 0.64f);
    glEnd();

    //roofRight
    glBegin(GL_QUADS);
    glVertex2f(0.85f, 0.15f);
    glVertex2f(0.9f, 0.215f);
    glVertex2f(0.0f, 0.752f);
    glVertex2f(0.0f, 0.64f);
    glEnd();





    //bottom left grass


    glBegin(GL_TRIANGLES);
    glColor3f(0.553, 0.776, 0.243);
    glVertex2f(-0.90f, -0.7f);
    glVertex2f(-0.75f, -0.57f);
    glVertex2f(-0.60f, -0.7f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glVertex2f(-0.75f, -0.7f);
    glVertex2f(-0.6f, -0.57f);
    glVertex2f(-0.45f, -0.7f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glVertex2f(-0.60f, -0.7f);
    glVertex2f(-0.45, -0.57f);
    glVertex2f(-0.30f, -0.7f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(-0.45f, -0.7f);
    glVertex2f(-0.30, -0.57f);
    glVertex2f(-0.15f, -0.7f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(-0.30f, -0.7f);
    glVertex2f(-0.15, -0.57f);
    glVertex2f(-0.0f, -0.7f);
    glEnd();



    //bottom right grass


    glBegin(GL_TRIANGLES);
    glVertex2f(0.90f, -0.7f);
    glVertex2f(0.75f, -0.57f);
    glVertex2f(0.60f, -0.7f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glVertex2f(0.75f, -0.7f);
    glVertex2f(0.6f, -0.57f);
    glVertex2f(0.45f, -0.7f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glVertex2f(0.60f, -0.7f);
    glVertex2f(0.45, -0.57f);
    glVertex2f(0.30f, -0.7f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(0.45f, -0.7f);
    glVertex2f(0.30, -0.57f);
    glVertex2f(0.15f, -0.7f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(0.30f, -0.7f);
    glVertex2f(0.15, -0.57f);
    glVertex2f(0.0f, -0.7f);
    glEnd();



    //bottom center grass

    glBegin(GL_TRIANGLES);
    glVertex2f(-0.15f, -0.7f);
    glVertex2f(0.0, -0.57f);
    glVertex2f(0.15f, -0.7f);
    glEnd();


    glFlush();

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(709, 784);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Home_201-115-075");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}