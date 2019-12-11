#include <GL/freeglut.h>
#include <math.h>

const double PI = 3.141592654;
int frameNumber = 0;

void drawfeathers(int a)
{
    glRotated(a, 0, 0, 1);
    glBegin(GL_POLYGON);
    glColor3f(0,0.7,0.1);
    glVertex2f(0,1);
    glVertex2f(-.15,.75);
    glVertex2f(0,0);
    glColor3f(0,1,0.7);
    glVertex2f(.15, .75);
    glVertex2f(0,1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0,0.4);
    glVertex2f(0,.9);
    glVertex2f(-.1,.75);
    glVertex2f(0,.5);
    glVertex2f(.1, .75);
    glVertex2f(0,.9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0.4,1);
    glVertex2f(0,.9);
    glVertex2f(-.1,.75);
    glVertex2f(0,.8);
    glVertex2f(.1, .75);
    glVertex2f(0,.9);
    glEnd();

}


void drawPeacock()
{
    glPushMatrix();
    drawfeathers(0);
    glPopMatrix();
    glPushMatrix();
    drawfeathers(45);
    glPopMatrix();
    glPushMatrix();
    drawfeathers(22.5);
    glPopMatrix();
    glPushMatrix();
    drawfeathers(90);
    glPopMatrix();
    glPushMatrix();
    drawfeathers(67.5);
    glPopMatrix();
    glPushMatrix();
    drawfeathers(-45);
    glPopMatrix();
    glPushMatrix();
    drawfeathers(-22.5);
    glPopMatrix();
    glPushMatrix();
    drawfeathers(-90);
    glPopMatrix();
    glPushMatrix();
    drawfeathers(-67.5);
    glPopMatrix();
    //head something
    glBegin(GL_TRIANGLES);
    glColor3f(0.1f, 0.66f, 0.9f);
    glVertex2f(-.02,.6);
    glVertex2f(.02,.6);
    glVertex2f(0,.75);
    glVertex2f(-.035,.6);
    glEnd();
    //head
    glBegin(GL_POLYGON);
    glColor3f(0.1,0.6,1);
    glVertex2f(-.03,.6);
    glVertex2f(-.09,.5);
    glVertex2f(-.03,.4);
    glVertex2f(.03, .4);
    glVertex2f(.09,.5);
    glVertex2f(.03,.6);
    glVertex2f(-.03,.6);
    glEnd();
    //beak
    glBegin(GL_TRIANGLES);
    glColor3f(0.9,0.9,0.1);
    glVertex2f(-.05,.5);
    glVertex2f(0,.4);
    glVertex2f(.05,.5);
    glVertex2f(-.05,.5);
    glEnd();
    //eyes
    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3f(0.1,0,1);
    glVertex2f(-.035,.53);
    glEnd();

    glBegin(GL_POINTS);
    glColor3f(0.1,0,1);
    glVertex2f(.035,.53);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.2f, 0.63f, 0.1f);
    glVertex2f(-.05,.5);
    glVertex2f(0,.4);
    glVertex2f(.05,.5);
    glVertex2f(-.05,.5);
    glEnd();
    //body
    glBegin(GL_QUADS);
    glColor3f(0.1,0.6,.9);
    glVertex2f(-.03,.4);
    glColor3f(0.1,0.5,0.9);
    glVertex2f(-.05,-.15);
    glVertex2f(.05,-.15);
    glColor3f(0.1,0.6,.9);
    glVertex2f(.03,.4);
    glVertex2f(-.03,.4);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.1,0.5,0.9);
    glVertex2f(-.03,.4);
    glVertex2f(-.18,-.05);
    glVertex2f(-.05,-.15);
    glVertex2f(-.03,.4);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.1,0.5,0.9);
    glVertex2f(.03,.4);
    glVertex2f(.18,-.05);
    glVertex2f(.05,-.15);
    glVertex2f(.03,.4);
    glEnd();
    //leg
    glBegin(GL_TRIANGLES);
    glVertex2f(-.05,-.15);
    glVertex2f(-.14,-.05);
    glVertex2f(-.05,-.3);
    glVertex2f(-.05,-.25);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(-.05,-.3);
    glVertex2f(-.15,-.28);
    glVertex2f(-.15,-.3);
    glVertex2f(-.05,-.3);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(.05,-.15);
    glVertex2f(.14,-.05);
    glVertex2f(.05,-.3);
    glVertex2f(.05,-.25);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(.05,-.3);
    glVertex2f(.15,-.28);
    glVertex2f(.15,-.3);
    glVertex2f(.05,-.3);
    glEnd();



}


void drawMountain()
{
    glColor3f(0,0.5,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-1.0, 0);
    glVertex2f(-0.5, 1.0);
    glVertex2f(-0.5, 0);
    glVertex2f(-1.0, 0);
    glEnd();

    glColor3f(0,0.4,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5, 1.0);
    glVertex2f(0, 0);
    glVertex2f(-0.5, 0);
    glVertex2f(-0.5, 1.0);
    glEnd();

}


void drawWindmill()
{
    int i;
    glColor3f(0.8f, 0.8f, 0.9f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.05f, 0);
    glVertex2f(0.05f, 0);
    glVertex2f(0.05f, 3);
    glVertex2f(-0.05f, 3);
    glEnd();
    glTranslatef(0, 3, 0);
    glRotated(frameNumber * (180.0/46), 0, 0, 1);
    glColor3f(0.4f, 0.4f, 0.8f);
    for (i = 0; i < 3; i++)
    {
        glRotated(120, 0, 0, 1);  // Note: These rotations accumulate.
        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(0.5f, 0.1f);
        glVertex2f(1.5f,0);
        glVertex2f(0.5f, -0.1f);
        glEnd();
    }
}

void drawHill()
{
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.4,1,0);
    glVertex2f (0.0,0.0);
    for (int i = 0; i <=90; i++)
    {
        glVertex2f(-.5*cos(i*PI/180), .5*sin(i*PI/180));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.4,0.9,0.1);
    glVertex2f (0.0,0.0);
    for (int i = 0; i <=90; i++)
    {
        glVertex2f(.5*cos(i*PI/180), .5*sin(i*PI/180));
    }
    glEnd();
}

void drawHill1()
{
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.7,1,0.1);
    glVertex2f (0.0,0.0);
    for (int i = 0; i <=90; i++)
    {
        glVertex2f(-.5*cos(i*PI/180), .5*sin(i*PI/180));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.7,0.9,0.2);
    glVertex2f (0.0,0.0);
    for (int i = 0; i <=90; i++)
    {
        glVertex2f(.5*cos(i*PI/180), .5*sin(i*PI/180));
    }
    glEnd();
}

void drawTree()
{
    glColor3f(0.5,0.2,0);
    glBegin(GL_QUADS);
    glVertex2f(-.03, .9);
    glVertex2f(-.03, .2);
    glVertex2f(.03, .2);
    glVertex2f(.03, .9);
    glVertex2f(-.03, .9);
    glEnd();

    glColor3f(0,0.5,0.2);
    glBegin(GL_TRIANGLES);
    glVertex2f(0, 1);
    glVertex2f(-0.1, .8);
    glVertex2f(0.1, .8);
    glVertex2f(0, 1);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(0, .9);
    glVertex2f(-0.15, .6);
    glVertex2f(0.15, .6);
    glVertex2f(0, .9);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(0, .8);
    glVertex2f(-0.2, .4);
    glVertex2f(0.2, .4);
    glVertex2f(0, .8);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glBegin(GL_QUADS);
    glColor3f(0.2,0.4,0.8);
    glVertex2f(-1,1);
    glColor3f(0.1,0.6,0.1);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glColor3f(0.2,0.4,0.8);
    glVertex2f(1,1);
    glVertex2f(-1,1);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.2,0.4,0.8);
    glVertex2f(0,1);
    glColor3f(1,1,1);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glVertex2f(0,1);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f (0,.4);
    for (int i = 0; i <=360; i++)
    {
        glColor3f(0.2,0.7,1);
        glVertex2f(.59*cos(i*PI/180), .65*sin(i*PI/180));
    }
    glEnd();
////////////////////////////////////////////mountain
    glPushMatrix();
    glTranslated(0,-.15,0);
    glScaled(.1,.1,1);
    drawMountain();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-.05,-.15,0);
    glScaled(.2,.2,1);
    drawMountain();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-.15,-.15,0);
    glScaled(.25,.3,1);
    drawMountain();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-.28,-.15,0);
    glScaled(.25,.23,1);
    drawMountain();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-.48,-.15,0);
    glScaled(.1,.1,1);
    drawMountain();
    glPopMatrix();

/////////////////////2nd
    glPushMatrix();
    glTranslated(.19,-.15,0);
    glScaled(.2,.15,1);
    drawMountain();
    glPopMatrix();

    glPushMatrix();
    glTranslated(.3,-.15,0);
    glScaled(.2,.2,1);
    drawMountain();
    glPopMatrix();

    glPushMatrix();
    glTranslated(.5,-.15,0);
    glScaled(.3,.3,1);
    drawMountain();
    glPopMatrix();

    glPushMatrix();
    glTranslated(.58,-.15,0);
    glScaled(.2,.2,1);
    drawMountain();
    glPopMatrix();
////////////////////////////////////////////////
    glPushMatrix();
    glTranslated(0,-.15,0);
    glScaled(.09,.09,1);
    drawWindmill();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-.5,-.15,0);
    glScaled(.06,.06,1);
    drawWindmill();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-.195,-.15,0);
    glScaled(.05,.06,1);
    drawWindmill();
    glPopMatrix();

    glPushMatrix();
    glTranslated(.44,-.15,0);
    glScaled(.08,.08,1);
    drawWindmill();
    glPopMatrix();

    glPushMatrix();
    glTranslated(.25,-.15,0);
    glScaled(.06,.06,1);
    drawWindmill();
    glPopMatrix();
///////////////////////////////////////////////////
    glBegin(GL_QUADS);
    glColor3f(0.1,.9,0.2);
    glVertex2f(-.58,-.15);
    glColor3f(1,1,1);
    glVertex2f(-.58,-1);
    glVertex2f(.58,-1);
    glColor3f(0.1,.9,0.2);
    glVertex2f(.58,-.15);
    glVertex2f(-.58,-.15);
    glEnd();
/////////////////////////////////////
    glBegin(GL_TRIANGLES);
    glColor3f(0,0.5,0.7);
    glVertex2f(0,-.15);
    glColor3f(1,1,1);
    glVertex2f(-.85,-1);
    glVertex2f(.85,-1);
    glVertex2f(0,-.15);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.7,0.5,0.2);
    glVertex2f(-.58,-.6);
    glColor3f(0.1,0.8,0.4);
    glVertex2f(-.58,-1);
    glVertex2f(.58,-1);
    glColor3f(0.9,1,0.2);
    glVertex2f(.58,-.6);
    glVertex2f(-.58,-.6);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0,0.7,0.2);
    glVertex2f(-.575,-.15);
    glColor3f(0.1,0.6,0.1);
    glVertex2f(-1,-1);
    glColor3f(0,.7,0.2);
    glVertex2f(0,-1);
    glVertex2f(-.575,-.15);
    glEnd();



    glBegin(GL_TRIANGLES);
    glColor3f(0,0.7,0.2);
    glVertex2f(.575,-.15);
    glColor3f(0.1,0.6,0.1);
    glVertex2f(1,-1);
    glColor3f(0,0.7,0.2);
    glVertex2f(0,-1);
    glVertex2f(-.575,-.15);
    glEnd();



///////////////////////////////////////////////////
    glPushMatrix();
    glTranslated(-.5,-.15,0);
    glScaled(.15,.1,1);
    drawHill();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-.5,-.17,0);
    glScaled(.15,.15,1);
    drawHill();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-.4,-.17,0);
    glScaled(.13,.17,1);
    drawHill();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-.32,-.17,0);
    glScaled(.14,.11,1);
    drawHill();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-.2,-.17,0);
    glScaled(.16,.2,1);
    drawHill();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-.07,-.17,0);
    glScaled(.15,.14,1);
    drawHill();
    glPopMatrix();
////////////////////////////////////////
    glPushMatrix();
    glTranslated(.07,-.17,0);
    glScaled(.15,.14,1);
    drawHill();
    glPopMatrix();

    glPushMatrix();
    glTranslated(.2,-.17,0);
    glScaled(.16,.2,1);
    drawHill();
    glPopMatrix();

    glPushMatrix();
    glTranslated(.32,-.17,0);
    glScaled(.14,.11,1);
    drawHill();
    glPopMatrix();

    glPushMatrix();
    glTranslated(.4,-.17,0);
    glScaled(.13,.17,1);
    drawHill();
    glPopMatrix();

    glPushMatrix();
    glTranslated(.5,-.17,0);
    glScaled(.15,.15,1);
    drawHill();
    glPopMatrix();
/////////////////////////////////lower

    glPushMatrix();
    glTranslated(-.545,-.2,0);
    glScaled(.1,.1,1);
    drawHill1();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-.45,-.2,0);
    glScaled(.1,.15,1);
    drawHill1();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-.39,-.2,0);
    glScaled(.13,.12,1);
    drawHill1();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-.27,-.2,0);
    glScaled(.14,.11,1);
    drawHill1();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-.15,-.2,0);
    glScaled(.16,.15,1);
    drawHill1();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-.07,-.2,0);
    glScaled(.15,.14,1);
    drawHill1();
    glPopMatrix();

    glPushMatrix();
    glTranslated(.545,-.2,0);
    glScaled(.1,.1,1);
    drawHill1();
    glPopMatrix();

    glPushMatrix();
    glTranslated(.45,-.2,0);
    glScaled(.1,.15,1);
    drawHill1();
    glPopMatrix();

    glPushMatrix();
    glTranslated(.39,-.2,0);
    glScaled(.13,.12,1);
    drawHill1();
    glPopMatrix();

    glPushMatrix();
    glTranslated(.27,-.2,0);
    glScaled(.14,.11,1);
    drawHill1();
    glPopMatrix();

    glPushMatrix();
    glTranslated(.15,-.2,0);
    glScaled(.16,.15,1);
    drawHill1();
    glPopMatrix();

    glPushMatrix();
    glTranslated(.07,-.2,0);
    glScaled(.15,.14,1);
    drawHill1();
    glPopMatrix();

///////////////////////////
    glPushMatrix();
    glTranslated(-.2,-.35,0);
    glScaled(.15,.14,1);
    drawTree();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-.32,-.35,0);
    glScaled(.15,.14,1);
    drawTree();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-.43,-.35,0);
    glScaled(.15,.14,1);
    drawTree();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-.37,-.45,0);
    glScaled(.12,.13,1);
    drawTree();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-.27,-.44,0);
    glScaled(.12,.12,1);
    drawTree();
    glPopMatrix();

    glPushMatrix();
    glTranslated(.2,-.35,0);
    glScaled(.15,.14,1);
    drawTree();
    glPopMatrix();

    glPushMatrix();
    glTranslated(.32,-.35,0);
    glScaled(.15,.14,1);
    drawTree();
    glPopMatrix();

    glPushMatrix();
    glTranslated(.43,-.35,0);
    glScaled(.15,.14,1);
    drawTree();
    glPopMatrix();

    glPushMatrix();
    glTranslated(.37,-.45,0);
    glScaled(.12,.13,1);
    drawTree();
    glPopMatrix();

    glPushMatrix();
    glTranslated(.27,-.44,0);
    glScaled(.12,.12,1);
    drawTree();
    glPopMatrix();

///////////////////////////
    glPushMatrix();
    glTranslated(0,-.6,0);
    glScaled(.3,.3,1);
    drawPeacock();
    glPopMatrix();


    glFlush();
    glutSwapBuffers();

}
void init()
{
    glClearColor(0.3,0.5,0.9, 1.0f);
}

void doFrame(int v)
{
    frameNumber++;
    glutPostRedisplay();
    glutTimerFunc(30,doFrame,0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
    glutInitWindowSize(790,690);
    glutInitWindowPosition(300,0);
    glutCreateWindow("Scenery");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(200,doFrame,0);

    glutMainLoop();
    return 0;
}
