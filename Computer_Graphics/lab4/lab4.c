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
#define pi 3.1415926

/* GLUT callback Handlers */

void SetWindow(float left, float right, float bottom, float top)
{
    //        glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(left, right, bottom, top, 1.0f, -1.0f);
    // glMatrixMode(GL_MODELVIEW);
    // glLoadIdentity();
}

void drawHexagon()
{
    float x, y, alpha, radius, spin = 0.0;
    for (radius = 0.05; radius < 1.5; radius += 0.1)
    {
        glColor3d(0, 0, radius);
        spin += 0.1;
        glBegin(GL_LINE_LOOP);
        for (alpha = spin; alpha < 2 * pi + spin; alpha += pi / 3)
        {
            x = radius * cos(alpha);
            y = radius * sin(alpha);
            glVertex2f(x, y);
        }
        glEnd();
    }
}

static void display(void)
{
    // glColor3d(1,0,0);

    int i, j, p = 6, q = 6;
    glPointSize(5.0);
    glColor3d(0, 0, 0.9);

    for (i = 0; i < p; i++)
    {
        for (j = 0; j < q; j++)
        {
            if ((i + j) % 2 == 0)
                SetWindow(0.8, -0.8, 0.8, -0.8);
            else
                SetWindow(-0.8, 0.8, 0.8, -0.8);

            glViewport(i * 100, j * 100, 100, 100);
            drawHexagon();
        }
    }

    // glViewport(0, 0, 150, 150);
    // glOrtho(0.0, 0.5, 0, 0.5, -1.0, 1.0);
    // SetWindow(0.0, 0.5, 0.0, 0.5);

    // glViewport(150, 0, 150, 150);
    // glOrtho(0.5, 0.0, 0, 0.5, -1.0, 1.0);
    // SetWindow(0.5, 0.0, 0.0, 0.5);

    glFlush();
}

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("GLUT Shapes");
    glutDisplayFunc(display);
    glClearColor(0, 0, 0, 1);
    glutMainLoop();

    return EXIT_SUCCESS;
}
