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
#include <math.h>

 


/* GLUT callback Handlers */

 


static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0,0,1);

 


    glPointSize(3.0);
    glBegin(GL_QUADS);
    glVertex2f(-1.0, -0.6);
    glVertex2f(1.0, -0.6);
    glVertex2f(1.0, -0.7);
    glVertex2f(-1.0, -0.7);
    
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex2f(-0.73, -0.6);
    glVertex2f(-0.8, -0.6);
    glVertex2f(-0.8, 0.0);
    glVertex2f(-0.73, 0.0);
    glEnd();
    

    glBegin(GL_QUADS);
    glVertex2f(-0.93, -0.6);
    glVertex2f(-1.0, -0.6);
    glVertex2f(-1.0, -0.2);
    glVertex2f(-0.93, -0.2);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex2f(-0.51, -0.6);
    glVertex2f(-0.6, -0.6);
    glVertex2f(-0.6, 0.4);
    glVertex2f(-0.51, 0.4);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex2f(-0.8, -0.3);
    glVertex2f(-1.0, -0.2);
    glVertex2f(-1.0, -0.1);
    glVertex2f(-0.8, -0.2);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex2f(-0.51, -0.1);
    glVertex2f(-0.8, 0.0);
    glVertex2f(-0.8, 0.1);
    glVertex2f(-0.51, 0.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex2f(-0.51, -0.1);
    glVertex2f(-0.8, 0.0);
    glVertex2f(-0.8, 0.1);
    glVertex2f(-0.51, 0.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex2f(-0.0, 0.05);
    glVertex2f(-0.6, 0.4);
    glVertex2f(-0.6, 0.5);
    glVertex2f(-0.0, 0.15);
    glEnd();
 
    glBegin(GL_QUADS);
        glVertex2f(0.73, -0.6);
        glVertex2f(0.8, -0.6);
        glVertex2f(0.8, 0.0);
        glVertex2f(0.73, 0.0);
        glEnd();
        

        glBegin(GL_QUADS);
        glVertex2f(0.93, -0.6);
        glVertex2f(1.0, -0.6);
        glVertex2f(1.0, -0.2);
        glVertex2f(0.93, -0.2);
        glEnd();
        
        glBegin(GL_QUADS);
        glVertex2f(0.51, -0.6);
        glVertex2f(0.6, -0.6);
        glVertex2f(0.6, 0.4);
        glVertex2f(0.51, 0.4);
        glEnd();
        
        glBegin(GL_QUADS);
        glVertex2f(0.8, -0.3);
        glVertex2f(1.0, -0.2);
        glVertex2f(1.0, -0.1);
        glVertex2f(0.8, -0.2);
        glEnd();
        
        glBegin(GL_QUADS);
        glVertex2f(0.51, -0.1);
        glVertex2f(0.8, 0.0);
        glVertex2f(0.8, 0.1);
        glVertex2f(0.51, 0.0);
        glEnd();
        
        glBegin(GL_QUADS);
        glVertex2f(0.51, -0.1);
        glVertex2f(0.8, 0.0);
        glVertex2f(0.8, 0.1);
        glVertex2f(0.51, 0.0);
        glEnd();
        
        glBegin(GL_QUADS);
        glVertex2f(0.0, 0.05);
        glVertex2f(0.6, 0.4);
        glVertex2f(0.6, 0.5);
        glVertex2f(0.0, 0.15);
        glEnd();
         
        glBegin(GL_QUADS);
        glVertex2f(0.30, -0.6);
        glVertex2f(0.45, -0.6);
        glVertex2f(0.45, -0.1);
        glVertex2f(0.30, -0.1);
        glEnd();
    
    glBegin(GL_QUADS);
    glVertex2f(0.0, -0.35);
    glVertex2f(0.45, -0.1);
    glVertex2f(0.45, 0.1);
    glVertex2f(0.0, -0.15);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex2f(-0.0, -0.35);
    glVertex2f(-0.45, -0.1);
    glVertex2f(-0.45, 0.1);
    glVertex2f(-0.0, -0.15);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex2f(-0.30, -0.6);
    glVertex2f(-0.45, -0.6);
    glVertex2f(-0.45, -0.1);
    glVertex2f(-0.30, -0.1);
    glEnd();
    
    
    glBegin(GL_QUADS);
    glVertex2f(-0.05, 0.98);
    glVertex2f(0.00, 0.98);
    glVertex2f(0.00, 0.65);
    glVertex2f(-0.05, 0.65);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex2f(-0.05, 1.0);
    glVertex2f(0.3, 0.90);
    glVertex2f(0.3, 0.75);
    glVertex2f(-0.05, 0.85);
    glEnd();
    
    
    int count;
    for(count=40;count<140;count++){
        double arg = count, x,y;

           // Converting to radian
           arg = (arg * PI) / 180;
            x = (cos(arg)-0.05)*0.5;
            y = sin(arg)-0.35;


        
        glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x, y+0.05);
        glVertex2f(x+0.05, y+0.05);
        glVertex2f(x+0.05, y);
        glEnd();
    }

    
    
    glFlush();
}

 


/* Program entry point */

 


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1024,768);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("GLUT Shapes");
    glutDisplayFunc(display);
    glClearColor(0,0,0,1);
    glutMainLoop();

 


    return EXIT_SUCCESS;
}
