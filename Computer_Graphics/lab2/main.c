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

/* GLUT callback Handlers */

void DrawerFunction(int color)
{

    //        printf("%d",counter);
    glClear(GL_COLOR_BUFFER_BIT);
    if (color == 1)
    {
        glColor3d(0, 0, 1);
    }
    else if (color == 2)
    {
        glColor3d(0, 1, 0);
    }
    else if (color == 3)
    {
        glColor3d(1, 0, 0);
    }

    glPointSize(3.0);
    double count;

    double arg = count, x, y;

    // Converting to radian

    glBegin(GL_TRIANGLE_FAN);
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

    glFlush();
}

void SpecialKeyHandler(int key, int x, int y)
{

    if (key == 101)
    {

        counter += 1;
        //        printf("%d",counter);
        DrawerFunction(1);
    }

    if (key == 103)
    {
        counter -= 1;
        //        printf("%d",counter);
        DrawerFunction(1);
    }
}

void NormalKeyHandler(unsigned char key, int x, int y)
{
    printf("%c", key);
    if (key == 'r')
    {
        DrawerFunction(3);
    }
    else if (key == 'g')
    {
        DrawerFunction(2);
    }
    else if (key == 'b')
    {
        DrawerFunction(1);
    }
    // do other stuff
    // and so on...
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0, 0, 1);

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
    glutSpecialFunc(SpecialKeyHandler);
    glutKeyboardFunc(NormalKeyHandler);
    glClearColor(0, 1, 0, 1);

    glutMainLoop();

    return EXIT_SUCCESS;
}
