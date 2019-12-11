#include <GL/freeglut.h>

void display(){
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(1,1,1);

        glBegin(GL_QUADS);
            glVertex2f(-.5, .5);
            glVertex2f(-.5,.05);
            glVertex2f(-.05,.05);
            glVertex2f(-.05,.55);
            glVertex2f(-.5,.5);
        glEnd();

        glBegin(GL_QUADS);
            glVertex2f(0, .56);
            glVertex2f(0,.05);
            glVertex2f(.5,.05);
            glVertex2f(.5,.63);
            glVertex2f(0,.55);
        glEnd();

        glBegin(GL_QUADS);
            glVertex2f(-.5, -.5);
            glVertex2f(-.5,-.01);
            glVertex2f(-.05,-.01);
            glVertex2f(-.05,-.55);
            glVertex2f(-.5,-.5);
        glEnd();

        glBegin(GL_QUADS);
            glVertex2f(0, -.56);
            glVertex2f(0,-.01);
            glVertex2f(.5,-.01);
            glVertex2f(.5,-.63);
            glVertex2f(0,-.55);
        glEnd();

        glFlush();
}



int main(int argc, char**argv){
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
        glutInitWindowSize(1080,690);
        glutInitWindowPosition(0,0);
        glutCreateWindow("windows");

        glClearColor(0.2,0.7,1,1);
        glutDisplayFunc(display);

        glutMainLoop();
        return 0;
}
