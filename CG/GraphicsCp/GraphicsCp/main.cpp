#include <cstdio>
#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

#include <cmath>
#include <cstring>
#include <iostream>
#include <string.h>

using namespace std;

// mouse-r hodolgohod hereglegdeh variable-uud
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;
bool mouseDown = false;
float xdiff = 0.0f;
float ydiff = 0.0f;

// tsegiin medeelliig struct torliin butetsen
struct point {
  GLfloat x, y, z;
};

struct face {
  int a, b, c;
};

struct face f[100001];
struct point p[50001];

void points() {
  // read file line by line, if first character is v save it to points array if
  // f save it to faces array
  FILE *file = fopen("/home/eggs/Downloads/dragon.obj", "r");
  char line[128];
  int i = 0;
  int j = 0;
  while (fgets(line, sizeof(line), file)) {
    if (line[0] == 'v') {
      sscanf(line, "v %f %f %f", &p[i].x, &p[i].y, &p[i].z);
      i++;
    } else if (line[0] == 'f') {
      sscanf(line, "f %d %d %d", &f[j].a, &f[j].b, &f[j].c);
      j++;
    }
  }
  fclose(file);
}

// zurah uildel hiigdene
void display(void) {
  glClearColor(0.0, 0.0, 0.0, 2);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3f(0.3f, 0.5f, 0.3f);
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();

  // mouse ashiglan erguuleh
  glRotatef(xRot, 1.0f, 0.0f, 0.0f);
  glRotatef(yRot, 0.0f, 0.0f, 1.0f);

  for (int i = 0; i < 100001; i++) {
    glBegin(GL_TRIANGLE_STRIP);
    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(p[f[i].a - 1].x, p[f[i].a - 1].y, p[f[i].a - 1].z);
    glVertex3f(p[f[i].b - 1].x, p[f[i].b - 1].y, p[f[i].b - 1].z);
    glVertex3f(p[f[i].c - 1].x, p[f[i].c - 1].y, p[f[i].c - 1].z);

    glEnd();
  }
  glPopMatrix();
  glutSwapBuffers();
}

// mouse ashiglaj hodolgono
void mouse(int button, int state, int x, int y) {
  if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON) {
    mouseDown = true;
    xdiff = x - yRot;
    ydiff = -y + xRot;
  } else
    mouseDown = false;
}

void mouseMotion(int x, int y) {
  if (mouseDown) {
    yRot = x - xdiff;
    xRot = y + ydiff;
    glutPostRedisplay();
  }
}

// gerel & suuderlelt hiigdene
void Init() {

  // Light values and coordinates
  GLfloat whiteLight[] = {0.05f, 0.05f, 0.05f, 1.0f};
  GLfloat sourceLight[] = {0.25f, 0.25f, 0.25f, 1.0f};
  GLfloat white[] = {1.0, 1.0, 1.0, 1.0};
  // tusaj baigaa gerliin bairshil
  GLfloat lightPos[] = {-10.f, 5.0f, 5.0f, 1.0f};

  // Enable lighting
  glEnable(GL_LIGHTING);

  // Setup and enable light 0
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, whiteLight);
  glLightfv(GL_LIGHT0, GL_AMBIENT, sourceLight);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, sourceLight);
  glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
  glEnable(GL_LIGHT0);

  // Set Material properties to follow glColor values
  glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
  glMaterialfv(GL_FRONT, GL_SPECULAR, white);

  // Black blue background
  glClearColor(0.25f, 0.25f, 0.50f, 1.0f);
}

// main function ajillana
int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitWindowSize(900, 900);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutCreateWindow("never let you gonna down");
  points();
  // face();
  glutDisplayFunc(display);
  // Init();
  glutMouseFunc(mouse);
  glutMotionFunc(mouseMotion);
  glutMainLoop();
  return 0;
}
