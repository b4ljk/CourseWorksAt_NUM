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
} point;
// array of points which are the vertices of the triangle
point points[] = {
    {-2.5, -3},
    {-1.5, -3},
    {-1.5, -1},
    {1.5, -1},
    {1.5, -3},
    {2.5, -3},
    {2.5, 1},
    {4, 1}, //--->
    {4, 2.5},
    {2.5, 2.5},
    {2.5, 3.9},
    {-2.5, 3.9},
    {-2.5, 2.5}, //
    {-4, 2.5},
    {-4, 1},
    {-2.5, 1},
    {-2.5, -3},

};
point latePoints[] = {
    {-2.5, -3},
    {-1.5, -3},
    {-1.5, -2.5},
    {1.5, -2.5},
    {1.5, -3},
    {2.5, -3},
    {2.5, -2.5},
    {4, -2.5}, //-->
    {3.5, -1.0},
    {2.5, -1.0},
    {1.5, 1.0},
    {-1.5, 1.0},
    {-2.5, -1.0},
    {-3.5, -1.0},
    {-4, -2.5}, //-->
    {-2.5, -2.5},
    {-2.5, -2.5},

};
// points to draw car
// robot points

// draw triangle
void drawFunction()
{
    if (globalTimeChange > 1)
    {
        globalBoolean = 1;
    }
    else if (globalTimeChange < 0.1)
    {
        globalBoolean = 0;
    }
    if (globalBoolean)
    {
        globalTimeChange -= 0.1;
    }
    else
    {
        globalTimeChange += 0.1;
    }

    glClear(GL_COLOR_BUFFER_BIT);
    point a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q;
    a.x = (1 - globalTimeChange) * points[0].x + globalTimeChange * latePoints[0].x;
    a.y = (1 - globalTimeChange) * points[0].y + globalTimeChange * latePoints[0].y;
    b.x = (1 - globalTimeChange) * points[1].x + globalTimeChange * latePoints[1].x;
    b.y = (1 - globalTimeChange) * points[1].y + globalTimeChange * latePoints[1].y;
    c.x = (1 - globalTimeChange) * points[2].x + globalTimeChange * latePoints[2].x;
    c.y = (1 - globalTimeChange) * points[2].y + globalTimeChange * latePoints[2].y;
    d.x = (1 - globalTimeChange) * points[3].x + globalTimeChange * latePoints[3].x;
    d.y = (1 - globalTimeChange) * points[3].y + globalTimeChange * latePoints[3].y;
    e.x = (1 - globalTimeChange) * points[4].x + globalTimeChange * latePoints[4].x;
    e.y = (1 - globalTimeChange) * points[4].y + globalTimeChange * latePoints[4].y;
    f.x = (1 - globalTimeChange) * points[5].x + globalTimeChange * latePoints[5].x;
    f.y = (1 - globalTimeChange) * points[5].y + globalTimeChange * latePoints[5].y;
    g.x = (1 - globalTimeChange) * points[6].x + globalTimeChange * latePoints[6].x;
    g.y = (1 - globalTimeChange) * points[6].y + globalTimeChange * latePoints[6].y;
    h.x = (1 - globalTimeChange) * points[7].x + globalTimeChange * latePoints[7].x;
    h.y = (1 - globalTimeChange) * points[7].y + globalTimeChange * latePoints[7].y;
    i.x = (1 - globalTimeChange) * points[8].x + globalTimeChange * latePoints[8].x;
    i.y = (1 - globalTimeChange) * points[8].y + globalTimeChange * latePoints[8].y;
    j.x = (1 - globalTimeChange) * points[9].x + globalTimeChange * latePoints[9].x;
    j.y = (1 - globalTimeChange) * points[9].y + globalTimeChange * latePoints[9].y;
    k.x = (1 - globalTimeChange) * points[10].x + globalTimeChange * latePoints[10].x;
    k.y = (1 - globalTimeChange) * points[10].y + globalTimeChange * latePoints[10].y;
    l.x = (1 - globalTimeChange) * points[11].x + globalTimeChange * latePoints[11].x;
    l.y = (1 - globalTimeChange) * points[11].y + globalTimeChange * latePoints[11].y;
    m.x = (1 - globalTimeChange) * points[12].x + globalTimeChange * latePoints[12].x;
    m.y = (1 - globalTimeChange) * points[12].y + globalTimeChange * latePoints[12].y;
    n.x = (1 - globalTimeChange) * points[13].x + globalTimeChange * latePoints[13].x;
    n.y = (1 - globalTimeChange) * points[13].y + globalTimeChange * latePoints[13].y;
    o.x = (1 - globalTimeChange) * points[14].x + globalTimeChange * latePoints[14].x;
    o.y = (1 - globalTimeChange) * points[14].y + globalTimeChange * latePoints[14].y;
    p.x = (1 - globalTimeChange) * points[15].x + globalTimeChange * latePoints[15].x;
    p.y = (1 - globalTimeChange) * points[15].y + globalTimeChange * latePoints[15].y;
    q.x = (1 - globalTimeChange) * points[16].x + globalTimeChange * latePoints[16].x;
    q.y = (1 - globalTimeChange) * points[16].y + globalTimeChange * latePoints[16].y;
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glVertex2f(a.x, a.y);
    glVertex2f(b.x, b.y);
    glVertex2f(c.x, c.y);
    glVertex2f(d.x, d.y);
    glVertex2f(e.x, e.y);
    glVertex2f(f.x, f.y);
    glVertex2f(g.x, g.y);
    glVertex2f(h.x, h.y);
    glVertex2f(i.x, i.y);
    glVertex2f(j.x, j.y);
    glVertex2f(k.x, k.y);
    glVertex2f(l.x, l.y);
    glVertex2f(m.x, m.y);
    glVertex2f(n.x, n.y);
    glVertex2f(o.x, o.y);
    glVertex2f(p.x, p.y);
    glVertex2f(q.x, q.y);

    glEnd();
}
// tweening

static void display(void)
{
    // glColor3d(1,0,0);
    //    glCLear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT);
    int i, j, p = 6, q = 6;
    glPointSize(5.0);
    glColor3d(0, 0, 0.9);
    // use tweening function to draw
    drawFunction();
    glutSwapBuffers();
}

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // get big screen
    glOrtho(-4, 4, -4, 4, -1, 1);
}

/* Program entry point */
// timer
void timer(int value)
{

    printf("%f\n", points[0].x);

    // printf("%f\n", globalRadius);
    glutPostRedisplay();
    glutTimerFunc(1000 / 2, timer, value += 1);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("GLUT Shapes");
    glutTimerFunc(
        1000,  // milliseconds
        timer, // function to call
        1      // value to pass to function
    );

    glutDisplayFunc(display);
    glClearColor(0, 0, 0, 1);

    init();
    glutMainLoop();

    return EXIT_SUCCESS;
}
