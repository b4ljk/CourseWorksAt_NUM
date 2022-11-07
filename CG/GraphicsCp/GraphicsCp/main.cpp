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
  FILE *fp;
  int read, i = 1;
  GLfloat x, y, z;
  char ch;
  fp = fopen("/Users/baljinnyamdayan/Downloads/dragon.obj", "r");
  if (!fp) {
    printf("file-g neej chasangui \n");
    exit(1);
  }
  {
    while (!(feof(fp))) {
      read = fscanf(fp, "%c %f %f %f", &ch, &x, &y, &z);
      if (ch == 'v') {
        p[i].x = x;
        p[i].y = y;
        p[i].z = z;
        i++;
      }
    }
  }
  glEndList();
}

void face() {
  FILE *fp;
  int read, i = 1, a, b, c;
  char ch;
  fp = fopen("/Users/baljinnyamdayan/Downloads/dragon.obj", "r");
  if (!fp) {
    printf("file alga bna\n");
    exit(1);
  }
  {
    while (!(feof(fp))) {
      read = fscanf(fp, "%s %d %d %d", &ch, &a, &b, &c);
      if (ch == 'f') {
        f[i].a = a;
        f[i].b = b;
        f[i].c = c;
        i++;
      }
    }
  }
  glEndList();
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

  glBegin(GL_TRIANGLE_FAN);
  for (int i = 1; i < 100001; i++) {
    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(p[f[i].a].x, p[f[i].a].y, p[f[i].a].z);
    glVertex3f(p[f[i].b].x, p[f[i].b].y, p[f[i].b].z);
    glVertex3f(p[f[i].c].x, p[f[i].c].y, p[f[i].c].z);
  }
  glEnd();
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
  face();
  glutDisplayFunc(display);
  // Init();
  glutMouseFunc(mouse);
  glutMotionFunc(mouseMotion);
  glutMainLoop();
  return 0;
}
