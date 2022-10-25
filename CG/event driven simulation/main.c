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
int radius = 0;
float dt = 0.1;
float globalTimeChange = -0.1;
int globalBoolean = 0;
/* GLUT callback Handlers */
// point struct
typedef struct
{
    float x;
    float y;
    float radius;
    float speedX;
    float speedY;
} point;

// randomly generate array of points x y are float
point *arrayOfPoints;

point *generatePoints(int n)
{
    point *points = (point *)malloc(n * sizeof(point));
    for (int i = 0; i < n; i++)
    {
        // random floating points between -50 to +50
        points[i].x = (float)(rand() % 100) - 50;
        points[i].y = (float)(rand() % 100) - 50;
        // random radius between 1-10
        points[i].radius = (float)(rand() % 10) + 1;
        // random speed via x,y between -0.5 to +0.5
        points[i].speedX = (float)(rand() % 10) / 10 - 0.5;
        points[i].speedY = (float)(rand() % 10) / 10 - 0.5;
    }
    return points;
}

// draw the points in the array
void drawPoints(point *points, int numPoints)
{
    // random points

    glColor3f(1.0, 0.0, 0.0);
    for (int i = 0; i < numPoints; i++)
    {
        glPointSize(points[i].radius);
        glBegin(GL_POINTS);
        glVertex2f(points[i].x, points[i].y);
        points[i].x += points[i].speedX;
        points[i].y += points[i].speedY;
        glEnd();
    }
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50, 50, -50, 50, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void drawFunction()
{
    // randomly generate balls
    glBegin(GL_POINTS);
    for (int i = 0; i < 100; i++)
    {
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(rand() % 10, rand() % 10);
    }
    glEnd();
    // glFlush();
}
// tweening

static void display(void)
{
    // glColor3d(1,0,0);
    //    glCLear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT);
    globalTimeChange += dt;
    drawPoints(arrayOfPoints, 10000);
    printf("globalTimeChange: %f", globalTimeChange);
    glutSwapBuffers();
}

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // get big screen
    // glOrtho(-50, 50, -50, 50, -1, 1);
    reshape(1000, 1000);

    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor3d(0, 0, 0.9);
}

/* Program entry point */
// timer

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("GLUT Shapes");
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glClearColor(0, 0, 0, 1);
    arrayOfPoints = generatePoints(10000);
    init();
    glutMainLoop();

    return EXIT_SUCCESS;
}
