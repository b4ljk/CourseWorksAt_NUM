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
#include "DS.h"
float globalTime = 0.0;
float prevGlobalTime = 0.0;
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

void calculateCollision(point *points, int numPoints)
{
    Msg messages;
    for (int i = 0; i < numPoints; i++)
    {
        messages.a = &points[i];
        // collision time calculator for each wall
        float timeX = (points[i].speedX > 0) ? (100 - points[i].x - points[i].radius / 2) / points[i].speedX : (-100 - (points[i].x - points[i].radius / 2)) / points[i].speedX;
        float timeY = (points[i].speedY > 0) ? (100 - points[i].y - points[i].radius / 2) / points[i].speedY : (-100 - (points[i].y - points[i].radius / 2)) / points[i].speedY;
        if (timeX > timeY)
        {
            messages.collisionTime = timeY;
            messages.whichWall = 1;
            if (timeY < 0)
            {

                points[i].speedY = -points[i].speedY;
            }
        }
        else
        {
            messages.collisionTime = timeX;
            messages.whichWall = 0;
            if (timeX < 0)
            {

                points[i].speedX = -points[i].speedX;
            }
        }
        if (i == 0)
        {
            printf("%f\t%f\t%f\n", messages.collisionTime, points[i].speedY);
        }

        insert(heap, messages);
    }
}

// calculate collision using heap then draw the points
void drawCollision(point *points, int numPoints)
{
    // collision
    // create heap
    // create array of messages

    // create array of messages

    // insert messages into heap
    // calculateCollision(points, numPoints);
    globalTime -= 1;
    printf("%f\t%d\n", globalTime, heap->heap.len);
    if (globalTime < 0)
    {
        Msg *temp;
        temp = &heap->heap.a[0];
        int wall = heap->heap.a[0].whichWall;
        if (wall == 0)
        {
            // X wall
            heap->heap.a[0].a->speedX = -heap->heap.a[0].a->speedX;
        }
        else
        {
            // Y wall
            heap->heap.a[0].a->speedY = -heap->heap.a[0].a->speedY;
        }

        //
        float timeX = (temp->a->speedX > 0) ? (100 - temp->a->x - temp->a->radius / 2) / temp->a->speedX : (-100 - (temp->a->x - temp->a->radius / 2)) / temp->a->speedX;
        float timeY = (temp->a->speedY > 0) ? (100 - temp->a->y - temp->a->radius / 2) / temp->a->speedY : (-100 - (temp->a->y - temp->a->radius / 2)) / temp->a->speedY;
        if (timeX > timeY)
        {
            temp->collisionTime = timeY;
            temp->whichWall = 1;
            if (timeY < 0)
            {

                temp->a->speedY = -temp->a->speedY;
            }
        }
        else
        {
            temp->collisionTime = timeX;
            temp->whichWall = 0;
            if (timeX < 0)
            {

                temp->a->speedX = -temp->a->speedX;
            }
        }
        for (int index = 1; index < heap->heap.len; index++)
        {
            heap->heap.a[index].collisionTime -= prevGlobalTime;
        }
        sink(heap, 0);
        prevGlobalTime = heap->heap.a[0].collisionTime;
        globalTime = heap->heap.a[0].collisionTime;
        //
    }
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
    glOrtho(-100, 100, -100, 100, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

// tweening

static void display(void)
{
    // glColor3d(1,0,0);
    //    glCLear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT);
    drawCollision(arrayOfPoints, 10000);
    glutSwapBuffers();
}

void init()
{
    heap->heap.len = 0;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    reshape(1000, 1000);
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor3d(0, 0, 0.9);
    calculateCollision(arrayOfPoints, 10000);
    globalTime = heap->heap.a[0].collisionTime;
    prevGlobalTime = heap->heap.a[0].collisionTime;
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
    arrayOfPoints = generatePoints(10000);
    init();
    glutMainLoop();

    return EXIT_SUCCESS;
}
