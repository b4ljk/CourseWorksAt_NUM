/*
 * GLUT Shapes Demo Updated
 */

#include <GL/freeglut_std.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
// #include <window.h>
#else
#include <GL/glut.h>
#endif

#define PI 3.141592654

#include "DS.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
float globalTime = 0.0;
float prevGlobalTime = 0.0;

point *arrayOfPoints;
Heap *heap;

point *generatePoints(int n) {
  printf("fucker2\n");
  point *points = (point *)malloc(n * sizeof(point));
  for (int i = 0; i < n; i++) {
    // random floating points between -90 to +90
    points[i].x = (float)(rand() % 180) - 90;
    points[i].y = (float)(rand() % 180) - 90;

    // random radius between 1-10
    points[i].radius = (float)(rand() % 10) + 1;
    // random speed via x,y between -0.5 to +0.5 not including 0
    points[i].speedX = (float)(rand() % 10) / 10 - 0.5;
    points[i].speedY = (float)(rand() % 10) / 10 - 0.5;
    if (points[i].speedX == 0) {
      points[i].speedX = 0.5;
    }
    if (points[i].speedY == 0) {
      points[i].speedY = 0.5;
    }
  }
  return points;
}

void redraw(point *points, int numPoints) {
  for (int i = 0; i < numPoints; i++) {
    if (points[i].x + points[i].radius / 2 > 100) {
      points[i].speedX = -points[i].speedX;
    }
    if (points[i].x - points[i].radius / 2 < -100) {
      points[i].speedX = -points[i].speedX;
    }
    if (points[i].y + points[i].radius / 2 > 100) {
      points[i].speedY = -points[i].speedY;
    }
    if (points[i].y - points[i].radius / 2 < -100) {
      points[i].speedY = -points[i].speedY;
    }
    glPointSize(points[i].radius);
    glBegin(GL_POINTS);
    glVertex2f(points[i].x, points[i].y);
    points[i].x += points[i].speedX;
    points[i].y += points[i].speedY;
    glEnd();
  }
}

void drawCollision(point *points, int numPoints) { redraw(points, numPoints); }

//! UNIMPORTANT CODE
void reshape(int w, int h) {
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-100, 100, -100, 100, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
}

static void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  drawCollision(arrayOfPoints, 10000);
  glutSwapBuffers();
}

void init() {
  heap->heap.len = 0;
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  reshape(1000, 1000);
  glEnable(GL_POINT_SMOOTH);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glColor3d(0, 0, 0.9);
}

void timer(int value) {
  glutPostRedisplay();
  printf("fucker1\n");
  glutTimerFunc(1000 / 20, timer, 0);
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  heap = (Heap *)malloc(sizeof(Heap));
  glutInitWindowSize(1000, 1000);
  glutInitWindowPosition(0, 0);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutCreateWindow("GLUT Shapes");
  glutDisplayFunc(display);
  glutTimerFunc(0, timer, 0);
  glClearColor(0, 0, 0, 1);
  arrayOfPoints = generatePoints(10000);
  init();
  glutMainLoop();
  return EXIT_SUCCESS;
}
