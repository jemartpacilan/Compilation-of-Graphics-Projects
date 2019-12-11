#include <GL/freeglut.h>

void display(){
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(0,0.7,1);

        glBegin(GL_QUADS);
            glVertex2f(-.35,.5);
            glVertex2f(-.35,-.5);
            glVertex2f(.35,-.5);
            glVertex2f(.35,.5);
            glVertex2f(-.35,.5);
        glEnd();

        glBegin(GL_QUADS);
            glVertex2f(-.1, -.5);
            glVertex2f(-.1, -1);
            glVertex2f(.1, -1);
            glVertex2f(.1, -.5);
            glVertex2f(-.1, -.5);
        glEnd();

        glBegin(GL_QUADS);
            glVertex2f(-.55,-.7);
            glVertex2f(-.55,-1);
            glVertex2f(.55,-1);
            glVertex2f(.55,-.7);
            glVertex2f(-.55,-.7);
        glEnd();

        glColor3f(1,1,1);

        glBegin(GL_QUADS);
            glVertex2f(-.17,.17);
            glVertex2f(-.17,.07);
            glVertex2f(-.09,.07);
            glVertex2f(-.09,.17);
            glVertex2f(-.17,.17);
        glEnd();

        glBegin(GL_QUADS);
            glVertex2f(-.17,-.25);
            glVertex2f(-.17,-.35);
            glVertex2f(.17,-.35);
            glVertex2f(.17,-.25);
            glVertex2f(-.17,-.25);
        glEnd();

        glBegin(GL_QUADS);
            glVertex2f(.17,.17);
            glVertex2f(.17,.07);
            glVertex2f(.09,.07);
            glVertex2f(.09,.17);
            glVertex2f(.17,.17);
        glEnd();

        glFlush();
}



int main(int argc, char**argv){
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
        glutInitWindowSize(1080,690);
        glutInitWindowPosition(0,0);
        glutCreateWindow("blue man");

        glClearColor(1,1,1,1);
        glutDisplayFunc(display);

        glutMainLoop();
        return 0;
}
