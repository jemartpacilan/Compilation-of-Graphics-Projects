#include <GL/freeglut.h>

void display(){
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(0.9,0,0);

        glBegin(GL_TRIANGLES);
            glVertex2f(0, -.1);
            glVertex2f(-.2,-.5);
            glVertex2f(.2,-.5);
            glVertex2f(0, -.1);
        glEnd();

        glColor3f(1,1,1);
        glBegin(GL_QUADS);
            glVertex2f(-.08, .5);
            glVertex2f(-.08,-.5);
            glVertex2f(.08,-.5);
            glVertex2f(.08,.5);
            glVertex2f(-.08, .5);
        glEnd();

        glColor3f(0.9,1,0);
        glBegin(GL_QUADS);
            glVertex2f(-.04,.4);
            glVertex2f(-.04,.28);
            glVertex2f(.04,.28);
            glVertex2f(.04,.4);
            glVertex2f(-.04,.4);
        glEnd();

        glColor3f(0.9,0,0);
        glBegin(GL_TRIANGLES);
            glVertex2f(-.08, .5);
            glVertex2f(.08,.5);
            glVertex2f(0, .8);
            glVertex2f(-.08, .5);
        glEnd();

        glFlush();
}



int main(int argc, char**argv){
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
        glutInitWindowSize(1080,690);
        glutInitWindowPosition(0,0);
        glutCreateWindow("rocket");

        glClearColor(0.1,0.2,0.6,1);
        glutDisplayFunc(display);

        glutMainLoop();
        return 0;
}
