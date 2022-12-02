#include <GLUT/glut.h>

#include <math.h>

#include <stdio.h>

GLfloat winWidth, winHeight;

float ver[50000][3];

int flat[100000][3];

static GLfloat xRot = 0.0f;

static GLfloat yRot = 0.0f;

void normalize(float *v) {

  float length = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);

  for (int i = 0; i < 3; i++)

  {

    v[i] = v[i] / length;
  }
}

float *cross_product(float *a, float *b)

{

  float result[] = {a[1] * b[2] - a[2] * b[1], -(a[0] * b[2] - a[2] * b[0]),
                    a[0] * b[1] - a[1] * b[0]};

  normalize(result);

  return result;
}

float *calculate_normal(float *a, float *b, float *c)

{

  float x[] = {b[0] - a[0], b[1] - a[1], b[2] - a[2]};

  float y[] = {c[0] - a[0], c[1] - a[1], c[2] - a[2]};

  float *result = cross_product(x, y);

  return result;
}

#define SIL GLU_SILHOUETTE

#define FILL GLU_LINE

void init()

{

  glClearColor(1, 1, 1, 1);

  GLfloat ambient[] = {0, 0, 0, 1};

  GLfloat diffuse[] = {1, 1, 1, 1};

  GLfloat specular[] = {1, 1, 1, 1};

  GLfloat position[] = {0, 3, 3, 0};

  GLfloat lmodel_ambient[] = {0.2, 0.2, 0.2, 1};

  GLfloat local_view[] = {0.0};

  glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

  glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

  glLightfv(GL_LIGHT0, GL_POSITION, position);

  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

  glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);

  glFrontFace(GL_CW);

  glEnable(GL_LIGHTING);

  glEnable(GL_LIGHT0);

  glEnable(GL_AUTO_NORMAL);

  glEnable(GL_NORMALIZE);

  glEnable(GL_DEPTH_TEST);
}

void display()

{

  glClearColor(0, 0, 0, 1);

  int i;

  float normal[3];

  glMatrixMode(GL_PROJECTION);

  glLoadIdentity();

  glOrtho(-2, 2, -2, 2, 1, -1);

  glViewport(0, 0, 1000, 1000);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glRotatef(xRot, 1.0f, 0.0f, 0.0f);

  glRotatef(yRot, 0.0f, 0.0f, 1.0f);

  int v = 0;

  int f = 0;

  char key;

  FILE *fin;

  fin = fopen("/Users/tsenguunotgonbaatar/Documents/computer_graphics/cg_lab9/"
              "dragon.obj",
              "r");

  if (fin == NULL)

    printf("\ncan't open input file\n");

  while (!feof(fin)) {

    fscanf(fin, "%c", &key);

    if (key == 'v')

    {

      fscanf(fin, "%f", &ver[v][0]);

      fscanf(fin, "%f", &ver[v][1]);

      fscanf(fin, "%f", &ver[v][2]);

      v = v + 1;

    }

    else if (key == 'f')

    {

      fscanf(fin, "%d", &flat[f][0]);

      fscanf(fin, "%d", &flat[f][1]);

      fscanf(fin, "%d", &flat[f][2]);

      f = f + 1;
    }
  }

  // glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

  glBegin(GL_TRIANGLES);

  for (i = 0; i < 100000; ++i)

  {

    // glColor3f(1,1,1);

    glNormal3fv(calculate_normal(ver[flat[i][0] - 1], ver[flat[i][1] - 1],
                                 ver[flat[i][2] - 1]));

    glVertex3fv(ver[flat[i][0] - 1]);

    glVertex3fv(ver[flat[i][1] - 1]);

    glVertex3fv(ver[flat[i][2] - 1]);
  }

  glEnd();

  glutSwapBuffers();
}

void reshape(int w, int h)

{

  if (h == 0)

    h = 1;

  glViewport(0, 0, w, h);

  glMatrixMode(GL_PROJECTION);

  glLoadIdentity();

  if (w <= h)

  {

    winHeight = 250 * h / w;

    winWidth = 250;

  } else

  {

    winWidth = 250 * w / h;

    winHeight = 250;
  }

  glOrtho(0, winWidth, 0, winHeight, 1, -1);

  glMatrixMode(GL_MODELVIEW);

  glLoadIdentity();
}

void SpecialKeys(int key, int x, int y)

{

  if (key == GLUT_KEY_UP)

    xRot -= 5.0f;

  if (key == GLUT_KEY_DOWN)

    xRot += 5.0f;

  if (key == GLUT_KEY_LEFT)

    yRot -= 5.0f;

  if (key == GLUT_KEY_RIGHT)

    yRot += 5.0f;

  if (key > 356.0f)

    xRot = 0.0f;

  if (key < -1.0f)

    xRot = 355.0f;

  if (key > 356.0f)

    yRot = 0.0f;

  if (key < -1.0f)

    yRot = 355.0f;

  glutPostRedisplay();
}

int main(int args, char **argv)

{

  glutInit(&args, argv);

  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

  glutInitWindowPosition(400, 0);

  glutInitWindowSize(1000, 1000);

  //    glutInitWindowPosition(100, 100);

  glutCreateWindow("Window");

  glutDisplayFunc(display);

  glutSpecialFunc(SpecialKeys);

  glutReshapeFunc(reshape);

  init();

  glutMainLoop();
}