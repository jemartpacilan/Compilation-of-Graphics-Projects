#include <GL/freeglut.h>

void display(){
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(1,1,1);
        glBegin(GL_QUADS);
            glVertex2f(0,.6);
            glVertex2f(-.2,.6);
            glVertex2f(-.2, -.6);
            glVertex2f(0, -.6);
            glVertex2f(0, .6);
        glEnd();

        glBegin(GL_QUADS);
            glVertex2f(0,.6);
            glVertex2f(0,.28);
            glVertex2f(.25,.28);
            glVertex2f(.25,.6);
            glVertex2f(0,.6);
        glEnd();

        glBegin(GL_QUADS);
            glVertex2f(0,.15);
            glVertex2f(0,-.15);
            glVertex2f(.13,-.15);
            glVertex2f(.13,.15);
            glVertex2f(0,.15);
        glEnd();

        glFlush();
}



int main(int argc, char**argv){
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
        glutInitWindowSize(1080,690);
        glutInitWindowPosition(0,0);
        glutCreateWindow("f");

        glClearColor(.9,0,0,1);
        glutDisplayFunc(display);

        glutMainLoop();
        return 0;
}
