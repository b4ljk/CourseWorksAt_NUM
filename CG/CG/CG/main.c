/*
 * GLUT Shapes Demo Updated
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
//#include <window.h>
#else
#include <GL/glut.h>
#endif

#define PI 3.141592654

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int counter = 0;
int selectedShape = 2;
int isMouseDown = 0;
int currentX, currentY;
int firstX, firstY;
int idiot = 0;
/* GLUT callback Handlers */

// void DrawerFunction (int color){
void drawCrap(int left, int right, int bottom, int top)
{
    glOrtho(left, right, bottom, top, -1, 1);
}
static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0, 0, 0);
    glPointSize(3.0);
    // for (int zet = 1; zet < 10; zet++)
    // {

    //     if (zet % 2 == 0)
    //     {
    //         glViewport(zet * 100, 0, 100, 100);
    //         drawCrap(0, zet, 0, zet);
    //     }
    //     else
    //     {
    //         glViewport(0, zet * 100, 100, 100);

    //         drawCrap(zet, 0, zet, 0);
    //     }
    // }
    // draw cricle
  
    glPointSize(3.0);
    double count;
    counter=6;
    double arg = count, x, y;

    // Converting to radian

    glBegin(GL_LINE_LOOP);
    for (int j = 0; j < counter; j++)
    {
        arg = (j * PI) / counter * 2;
        printf("%f", arg);
        printf("%f\n", arg);
        x = (cos(arg));
        y = sin(arg);
        glVertex2f(x, y);
    }

    glEnd();
    
//    drawCrap(1, 0, 0, 1);
//
//    glViewport(200, 200, 200, 200);
//    drawCrap(1, 0, 1, 0);
//    glViewport(0, 200, 200, 200);
//    drawCrap(-50, -50, -52, -50);

    // glViewport(0, 200, 200, 200);
    // drawCrap(1, 1, 1, 1);
    // glViewport(100, 100, 100, 100);

    glFlush();
}

/* Program entry point */

int main(int argc, char *argv[])
{

    glutInit(&argc, argv);
    glutInitWindowSize(768, 768);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("GLUT Shapes");
    glutDisplayFunc(display);
    glClearColor(1, 1, 1, 1);

    glutMainLoop();

    return EXIT_SUCCESS;
}
