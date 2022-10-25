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
#include "DS.h"

/* GLUT callback Handlers */
// point struct

// randomly generate array of points x y are float
point *arrayOfPoints;
Heap *heap;

point *generatePoints(int n)
{
    point *points = (point *)malloc(n * sizeof(point));
    for (int i = 0; i < n; i++)
    {
        // random floating points between -90 to +90
        points[i].x = (float)(rand() % 180) - 90;
        points[i].y = (float)(rand() % 180) - 90;

        // random radius between 1-10
        points[i].radius = (float)(rand() % 10) + 1;
        // random speed via x,y between -0.5 to +0.5 not including 0
        points[i].speedX = (float)(rand() % 10) / 10 - 0.5;
        points[i].speedY = (float)(rand() % 10) / 10 - 0.5;
        if (points[i].speedX == 0)
        {
            points[i].speedX = 0.5;
        }
        if (points[i].speedY == 0)
        {
            points[i].speedY = 0.5;
        }
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

// calculate collision using heap then draw the points
void drawCollision(point *points, int numPoints)
{
    // collision
    // create heap
    heap->heap.len = 0;
    // create array of messages
    Msg messages;
    // create array of messages
    for (int i = 0; i < numPoints; i++)
    {
        messages.a = &points[i];
        // collision time calculator for each wall
        float timeX = (points[i].speedX > 0) ? (100 - points[i].x - points[i].radius / 2) / points[i].speedX : (-100 - (points[i].x - points[i].radius / 2)) / points[i].speedX;
        float timeY = (points[i].speedY > 0) ? (100 - points[i].y - points[i].radius / 2) / points[i].speedY : (-100 - (points[i].y - points[i].radius / 2)) / points[i].speedY;
        if (timeX > timeY)
        {
            if (timeY < 0)
            {
                messages.collisionTime = timeY;
                points[i].speedY = -points[i].speedY;
            }
        }
        else
        {
            if (timeX < 0)
            {
                messages.collisionTime = timeX;
                points[i].speedX = -points[i].speedX;
            }
        }
        if (i == 0)
        {
            printf("%f\t%f\t%f\n", timeY, points[i].speedY);
        }

        // insert(heap, messages);
    }
    // insert messages into heap

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
    // draw collision
    // glColor3f(0.0, 1.0, 0.0);
    // for (int i = 0; i < numPoints; i++)
    // {
    //     Msg msg = delMin(heap);
    //     if (msg.collisionTime == 0)
    //     {
    //         continue;
    //     }
    //     else
    //     {
    //         glPointSize(msg.a->radius);
    //         glBegin(GL_POINTS);
    //         glVertex2f(msg.a->x, msg.a->y);
    //         glEnd();
    //     }
    // }
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100, 100, -100, 100, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

// tweening

static void display(void)
{
    // glColor3d(1,0,0);
    //    glCLear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT);
    globalTimeChange += dt;
    drawCollision(arrayOfPoints, 500);
    glutSwapBuffers();
}

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
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
    heap = (Heap *)malloc(sizeof(Heap));
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("GLUT Shapes");
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glClearColor(0, 0, 0, 1);
    arrayOfPoints = generatePoints(500);
    init();
    glutMainLoop();

    return EXIT_SUCCESS;
}
