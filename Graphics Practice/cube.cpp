#include <GL/freeglut.h>

void display(){
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(.7,.7,.7);
        glBegin(GL_QUADS);
            glVertex2f(0,.2);
            glVertex2f(-.7,-.15);
            glVertex2f(-.6, -.55);
            glVertex2f(0,-.75);
            glVertex2f(0,.5);
        glEnd();

        glColor3f(0.9,1,0);
        glBegin(GL_QUADS);
            glVertex2f(0,.75);
            glVertex2f(-.4,.3);
            glVertex2f(0,-.1);
            glVertex2f(.4,.3);
            glVertex2f(0,.8);
        glEnd();

        glColor3f(.9,0,0);
        glBegin(GL_QUADS);
            glVertex2f(0,-.1);
            glVertex2f(-.4,.3);
            glVertex2f(-.4, -.3);
            glVertex2f(0,-.75);
            glVertex2f(0,-.1);
        glEnd();

        glColor3f(0,0.7,0.2);
        glBegin(GL_QUADS);
            glVertex2f(0,-.1);
            glVertex2f(0,-.75);
            glVertex2f(.4, -.3);
            glVertex2f(.4,.3);
            glVertex2f(0,-.1);
        glEnd();

        glFlush();
}



int main(int argc, char**argv){
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
        glutInitWindowSize(1080,690);
        glutInitWindowPosition(0,0);
        glutCreateWindow("cube");

        glClearColor(1,1,1,1);
        glutDisplayFunc(display);

        glutMainLoop();
        return 0;
}
