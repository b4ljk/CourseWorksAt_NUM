/*
 * GLUT Shapes Demo Updated
 */

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
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

float globalTime = 0.0;
float prevTime = 0.0;
int fpsNum = 30;
point *arrayOfPoints;
Heap *heap;
int particleNum = 4;
point *generatePoints(int n) {
  point *points = (point *)malloc(n * sizeof(point));
  for (int i = 0; i < n; i++) {
    // random floating points between -90 to +90
    points[i].x = (float)(rand() % 180) - 90;
    points[i].y = (float)(rand() % 180) - 90;

    // random radius between 7-12
    points[i].radius = (float)(rand() % 6) + 7;
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
void DrawCircle(float cx, float cy, float r, int num_segments) {
  glBegin(GL_LINE_LOOP);
  for (float ii = 0; ii < num_segments; ii += 1) {
    float theta =
        2.0f * 3.1415926f * (ii) / (num_segments); // get the current angle

    float x = r * cosf(theta); // calculate the x component
    float y = r * sinf(theta); // calculate the y component

    glVertex2f(x + cx, y + cy); // output vertex
  }
  glEnd();
}
void predict(point *a) {
  if (a == NULL)
    return;
  for (int i = 0; i < particleNum; i++) {
    if (a == &arrayOfPoints[i])
      continue;
    float time = timeToHit(a, &arrayOfPoints[i]);
    if (time > 0) {
      Event event;
      event.collisionTime = time;
      event.a = a;
      event.b = &arrayOfPoints[i];
      event.countA = a->count;
      event.countB = arrayOfPoints[i].count;
      // printf("time to hit: %f %f %f\n", time, a->x, arrayOfPoints[i].x);
      insert(heap, event);
    }
  }
}

int isValid(Event event) {
  if (event.a->count != event.countA)
    return 0;
  if (event.b->count != event.countB)
    return 0;
  return 1;
}

// bounce off
void bounceOff(point *a, point *b) {
  a->speedX = -a->speedX;
  a->speedY = -a->speedY;
  b->speedX = -b->speedX;
  b->speedY = -b->speedY;

  a->count++;
  b->count++;
}

void update(point *a, float dt) {
  a->x += a->speedX * dt;
  a->y += a->speedY * dt;
}
// ! USE PREVIOUS GLOBAL TIME PLEASE !!!
void redraw(point *points, int numPoints) {
  Event event;
  if (heap->heap.len > 0) {
    event = delMin(heap);
    printf("time to hit: %f %f %f \n", event.collisionTime, event.a->x,
           event.b->x);
    for (int i = 0; i < heap->heap.len; i++) {
      heap->heap.a[i].collisionTime -= prevTime;
    }
    if (event.collisionTime < 0.5) {
      if (isValid(event)) {
        // bounce off
        bounceOff(event.a, event.b);
      }
    }
    predict(event.a);
    predict(event.b);
  }
  printf("%d", heap->heap.len);
  prevTime = globalTime;
  globalTime = event.collisionTime;
  // TODO 1: bumbug oihgui bol zursaar baina
  // TODO 2: bumbug orood irvel oilgo
  // TODO 3: bumbug oihgui bol zursnii daraa daraagin zuraltiig heap ruu hii
  for (int i = 0; i < numPoints; i++) {
    // collid with wall
    if (points[i].x + points[i].radius / 2 > 100) {
      points[i].speedX = -points[i].speedX;
      predict(&points[i]);
      points[i].count++;
    }
    if (points[i].x - points[i].radius / 2 < -100) {
      points[i].speedX = -points[i].speedX;
      predict(&points[i]);
      points[i].count++;
    }
    if (points[i].y + points[i].radius / 2 > 100) {
      points[i].speedY = -points[i].speedY;
      predict(&points[i]);
      points[i].count++;
    }
    if (points[i].y - points[i].radius / 2 < -100) {
      points[i].speedY = -points[i].speedY;
      predict(&points[i]);
      points[i].count++;
    }
    DrawCircle(points->x, points->y, points->radius, 365);
  }
}

void drawCollision(point *points, int numPoints) { redraw(points, numPoints); }

//! UNIMPORTANT CODE
void reshape(int w, int h) {
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1000, 1000, -1000, 1000, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
}

static void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  drawCollision(arrayOfPoints, particleNum);
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
  for (int i = 0; i < particleNum; i++) {
    predict(&arrayOfPoints[i]);
  }
}

void timer(int value) {
  glutPostRedisplay();
  glutTimerFunc(1000 / fpsNum, timer, 0);
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
  arrayOfPoints = generatePoints(particleNum);
  init();
  glutMainLoop();
  return EXIT_SUCCESS;
}
