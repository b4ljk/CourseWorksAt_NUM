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

int counter = 0;
int selectedShape = 2;
int isMouseDown = 0;
int currentX, currentY;
int firstX, firstY;
int idiot = 0;
/* GLUT callback Handlers */

// void DrawerFunction (int color){

// //        printf("%d",counter);
//     glClear(GL_COLOR_BUFFER_BIT);
//     if(color==1){
//         glColor3d(0,0,1);
//     }else if(color==2){
//         glColor3d(0,1,0);
//     }else if(color==3){
//         glColor3d(1,0,0);
//     }

//         glPointSize(3.0);
//     double count;

//             double arg = count, x,y;

//                // Converting to radian

//             glBegin(GL_TRIANGLE_FAN);
//         for(int j=0;j<counter;j++){
//             arg = (j * PI)/counter*2;
//             printf("%f",arg);
//             printf("%f\n",arg);
//              x = (cos(arg));
//              y = sin(arg);
//             glVertex2f(x, y);
//         }

//             glEnd();

//         glFlush();
// }

void mouseHandlerFunction(int button, int state, int x, int y)
{
    // printf("Mouse button %d", button);
    // printf("Mouse state %d", state);
    printf("\n>>>>>>>Mouse x %d\n", x);
    printf(">>>>>>>Mouse y %d\n", y);
    printf("%d\n", currentX);
    printf("%d\n", currentY);

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        isMouseDown = 0;
        if (x >= 22 && x <= 44 && y >= 40 && y <= 70)
        {
            printf("LINE IS READY TO FUCK !!!");
            selectedShape = 2;
        }
        else if (x >= 80 && x <= 110 && y >= 40 && y <= 70)
        {
            printf("QUADS IS READY TO FUCK !!!");
            selectedShape = 4;
        }
        else if (x >= 150 && x <= 180 && y >= 40 && y <= 70)
        {
            printf("TRIANGLE IS READY TO FUCK !!!");
            selectedShape = 3;
        }
        else if (currentX + 10 >= x && currentX - 10 <= x && currentY + 10 >= y && currentY - 10 <= y)
        {
            printf("FUCKING CUCRRENTAJODIHJALKSD ");
            glClear(GL_COLOR_BUFFER_BIT);
            glutPostRedisplay();
            glFlush();
            idiot = 1;
        }
        printf("first key down");
        glColor3d(0, 0, 1);
        glPointSize(3.0);
        if (selectedShape == 2 && idiot == 0)
        {
            glBegin(GL_LINES);
            glVertex2f(x, 768 - y);
            firstX = x;
            firstY = 768 - y;
            // idiot = 0;
        }
        else if (selectedShape == 3)
        {
            glBegin(GL_LINE_LOOP);
            glVertex2f(x, 768 - y);
            currentX = x;
            currentY = 768 - y;
        }
        else if (selectedShape == 4)
        {
            glBegin(GL_LINE_LOOP);
            glVertex2f(x, 768 - y);
            currentX = x;
            currentY = 768 - y;
        }
    }
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
        isMouseDown = 1;
        printf("%d", idiot);
        if (selectedShape == 2)
        {
            if (idiot == 1)
            {
                // glutPostRedisplay();
                glBegin(GL_LINES);
                glVertex2f(firstX, firstY);
            }
            glVertex2f(x, 768 - y);
            currentX = x;
            currentY = y;
        }
        else if (selectedShape == 4)
        {
            glVertex2f(currentX, 768 - y);
            glVertex2f(x, 768 - y);
            glVertex2f(x, currentY);
        }
        else if (selectedShape == 3)
        {
            glVertex2f(x, currentY);
            glVertex2f(x, 768 - y);
        }
        glEnd();
        glFlush();
    }

    {
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        printf("secondkeydown");
        // DrawerFunction(2);
        glClear(GL_COLOR_ARRAY);
        glutPostRedisplay();
    }
}

void mouseMotionHandlerFunction(int x, int y)
{
    // printf("Mouse x %d", x);
    // printf("Mouse y %d", y);
    // glBegin(GL_LINES);
    // glVertex2f(x, 768 - y);
    // glVertex2f(x + 30, 768 - y - 30);
    // glEnd();
    // glFlush();
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0, 0, 0);
    glPointSize(3.0);
    glBegin(GL_QUADS);
    glVertex2f(22, 768 - 40);
    glVertex2f(26, 768 - 40);
    glVertex2f(44, 768 - 70);
    glVertex2f(40, 768 - 70);

    glEnd();
    // quads
    glBegin(GL_QUADS);
    glVertex2f(80, 768 - 40);
    glVertex2f(110, 768 - 40);
    glVertex2f(110, 768 - 70);
    glVertex2f(80, 768 - 70);
    glEnd();

    // triangle

    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(150, 768 - 40);
    glVertex2f(150, 768 - 70);
    glVertex2f(180, 768 - 70);
    glEnd();
    glFlush();
}

/* Program entry point */

int main(int argc, char *argv[])
{

    glutInit(&argc, argv);
    glutInitWindowSize(768, 768);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("GLUT Shapes");
    glutDisplayFunc(display);
    glutMouseFunc(mouseHandlerFunction);
    glutMotionFunc(mouseMotionHandlerFunction);
    glClearColor(1, 1, 1, 1);
    glOrtho(-1, 768, -1, 768, -1, 1);
    glutMainLoop();

    return EXIT_SUCCESS;
}
