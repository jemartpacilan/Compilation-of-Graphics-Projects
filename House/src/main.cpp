#include <GL/freeglut.h>
#include <iostream>
#include <string.h>

#include "imageloader.h"

using namespace std;

#define WINW 800
#define WINH 600

bool tumble = false;
bool track = false;

bool isOrtho = false;
bool isWireframe = false;
bool isTurnTable = false;
bool isFullscreen = false;

int window_x, window_y;
int menu = 0;

float translate_x = 0.0f, translate_y = 0.0f, translate_z = 0.0f;
float rot_x = 0.0f, rot_y = 0.0f, rot_z = 0.0f;
float scale_x = 1.0f, scale_y = 1.0f, scale_z = 1.0f;
float previousX = 0.0f, previousY = 0.0f, previousZ = 0.0f;
static GLboolean keys[256];
GLuint loadTexture(Image*);


//materials
void material0 (void);

//using 3 point lighting
void light0 (void);
void light1 (void);
void light0 (void);

//textures
GLuint textureId[10];


//draw primitives here
void drawObject(void)
{

    glBindTexture(GL_TEXTURE_2D, textureId[0]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBegin(GL_QUADS);
        glTexCoord2f(0, 1);     glVertex3f(-1, 0, 1);
        glTexCoord2f(1, 1);     glVertex3f(-1, 0, -1);
        glTexCoord2f(1, 0);     glVertex3f(1, 0, -1);
        glTexCoord2f(0, 0);     glVertex3f(1, 0, 1);
    glEnd();



    glBindTexture(GL_TEXTURE_2D, textureId[1]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBegin(GL_QUADS);
        glTexCoord2f(0, 1);     glVertex3f(0.3, .3, 0.25);
        glTexCoord2f(1, 1);     glVertex3f(0.3, .3, -0.25);
        glTexCoord2f(1, 0);     glVertex3f(0.3, 0, -0.25);
        glTexCoord2f(0, 0);     glVertex3f(0.3, 0, 0.25);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, textureId[2]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBegin(GL_QUADS);
        glTexCoord2f(0, 1);     glVertex3f(0.3, .3, -0.25);
        glTexCoord2f(1, 1);     glVertex3f(-0.3, .3, -0.25);
        glTexCoord2f(1, 0);     glVertex3f(-0.3, 0, -0.25);
        glTexCoord2f(0, 0);     glVertex3f(0.3, 0, -0.25);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, textureId[2]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBegin(GL_QUADS);
        glTexCoord2f(0, 1);     glVertex3f(0.3, .3, 0.25);
        glTexCoord2f(1, 1);     glVertex3f(-0.3, .3, 0.25);
        glTexCoord2f(1, 0);     glVertex3f(-0.3, 0, 0.25);
        glTexCoord2f(0, 0);     glVertex3f(0.3, 0, 0.25);
    glEnd();


    glBindTexture(GL_TEXTURE_2D, textureId[3]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBegin(GL_QUADS);
        glTexCoord2f(0, 1);     glVertex3f(0.05, .25, 0.255);
        glTexCoord2f(1, 1);     glVertex3f(-0.05, .25, 0.255);
        glTexCoord2f(1, 0);     glVertex3f(-0.05, 0, 0.255);
        glTexCoord2f(0, 0);     glVertex3f(0.05, 0, 0.255);
    glEnd();


    glBindTexture(GL_TEXTURE_2D, textureId[1]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBegin(GL_QUADS);
        glTexCoord2f(0, 1);     glVertex3f(-0.3, .3, 0.25);
        glTexCoord2f(1, 1);     glVertex3f(-0.3, .3, -0.25);
        glTexCoord2f(1, 0);     glVertex3f(-0.3, 0, -0.25);
        glTexCoord2f(0, 0);     glVertex3f(-0.3, 0, 0.25);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, textureId[4]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBegin(GL_QUADS);
        glTexCoord2f(0, 1);     glVertex3f(0, .5, 0.25);
        glTexCoord2f(1, 1);     glVertex3f(0, .5, -0.25);
        glTexCoord2f(1, 0);     glVertex3f(0.3, .3, -0.25);
        glTexCoord2f(0, 0);     glVertex3f(0.3, .3, 0.25);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, textureId[4]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBegin(GL_QUADS);
        glTexCoord2f(0, 1);     glVertex3f(0, .5, 0.25);
        glTexCoord2f(1, 1);     glVertex3f(0, .5, -0.25);
        glTexCoord2f(1, 0);     glVertex3f(-0.3, .3, -0.25);
        glTexCoord2f(0, 0);     glVertex3f(-0.3, .3, 0.25);
    glEnd();


    glBindTexture(GL_TEXTURE_2D, textureId[2]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBegin(GL_TRIANGLES);
        glTexCoord2f(0, 1);     glVertex3f(0, .5, -0.25);
        glTexCoord2f(1, 1);     glVertex3f(-0.3, .3, -0.25);
        glTexCoord2f(1, 0);     glVertex3f(0.3, .3, -0.25);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, textureId[2]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBegin(GL_TRIANGLES);
        glTexCoord2f(0, 1);     glVertex3f(0, .5, 0.25);
        glTexCoord2f(1, 1);     glVertex3f(-0.3, .3, 0.25);
        glTexCoord2f(1, 0);     glVertex3f(0.3, .3, 0.25);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, textureId[5]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    for(float x = 0; x < 15; x++){
    glBegin(GL_QUADS);

        glTexCoord2f(0, 1);     glVertex3f(.05, 0.001, .07 + (x*.06));
        glTexCoord2f(1, 1);     glVertex3f(.05, 0.001, .03 + (x*.06));
        glTexCoord2f(1, 0);     glVertex3f(-.05, 0.001, .03 + (x*.06));
        glTexCoord2f(0, 0);     glVertex3f(-.05, 0.001, .07 + (x*.06));
    glEnd();
    }



    glBindTexture(GL_TEXTURE_2D, textureId[6]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBegin(GL_QUADS);

        glTexCoord2f(0, 1);     glVertex3f(-.3, 0.002, .25);
        glTexCoord2f(1, 1);     glVertex3f(.3, 0.002, .25);
        glTexCoord2f(1, 0);     glVertex3f(.3, 0.002, -.25 );
        glTexCoord2f(0, 0);     glVertex3f(-.3, 0.002, -.25);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, textureId[6]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    for(float x = 0; x < 25; x++){
    glBegin(GL_QUADS);

        glTexCoord2f(0, 1);     glVertex3f(.5, 0, -1 + (x*.06));
        glTexCoord2f(1, 1);     glVertex3f(.5, 0.1, -1 + (x*.06));
        glTexCoord2f(1, 0);     glVertex3f(.5, 0.1,-.98 + (x*.06));
        glTexCoord2f(0, 0);     glVertex3f(.5, 0,-.98 + (x*.06));
    glEnd();
    }

    glBindTexture(GL_TEXTURE_2D, textureId[6]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    for(float x = 0; x < 25; x++){
    glBegin(GL_QUADS);

        glTexCoord2f(0, 1);     glVertex3f(-.5, 0, -1 + (x*.06));
        glTexCoord2f(1, 1);     glVertex3f(-.5, 0.1, -1 + (x*.06));
        glTexCoord2f(1, 0);     glVertex3f(-.5, 0.1,-.98 + (x*.06));
        glTexCoord2f(0, 0);     glVertex3f(-.5, 0,-.98 + (x*.06));
    glEnd();
    }

}

 void material0 ()
{
    GLfloat mat_amb[]  = {0.25, 0.25, 0.25, 1.0};
    GLfloat mat_dif[]  = {0.4, 0.4, 0.4, 1.0};
    GLfloat mat_spec[] = {0.774597, 0.774597, 0.774597, 1.0};
    GLfloat mat_emit[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat mat_shine  = 50;

    glMaterialfv(GL_FRONT,GL_AMBIENT, mat_amb);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE, mat_dif);
    glMaterialfv(GL_FRONT,GL_SPECULAR, mat_spec);
    glMaterialfv(GL_FRONT,GL_EMISSION, mat_emit);
    glMaterialf(GL_FRONT,GL_SHININESS, mat_shine);
}


void light0 ()
{
    GLfloat light_pos[]  = {-5.0, 5.0, 10.0, 1.0};
    GLfloat light_amb[]  = {1.0, 1.0, 1.0, 0.0};
    GLfloat light_dif[]  = {0.8, 0.8, 0.8, 1.0};
    GLfloat light_spec[] = {0.5, 0.5, 0.5, 1.0};

    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_amb);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_dif);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_spec);
}

void light1 ()
{
    GLfloat light_pos[]  = {5.0, 3.0, 5.0, 1.0};
    GLfloat light_amb[]  = {1.0, 1.0, 1.0, 0.0};
    GLfloat light_dif[]  = {0.8, 0.8, 0.8, 1.0};
    GLfloat light_spec[] = {1.0, 1.0, 1.0, 1.0};

    glLightfv(GL_LIGHT1, GL_POSITION, light_pos);
    glLightfv(GL_LIGHT1, GL_AMBIENT, light_amb);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_dif);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_spec);
}

void light2 ()
{
    GLfloat light_pos[]  = {0.0, -3.0, -5.0, 1.0};
    GLfloat light_amb[]  = {1.0, 1.0, 1.0, 0.0};
    GLfloat light_dif[]  = {0.5, 0.5, 0.5, 1.0};
    GLfloat light_spec[] = {1.0, 1.0, 1.0, 1.0};

    glLightfv(GL_LIGHT2, GL_POSITION, light_pos);
    glLightfv(GL_LIGHT2, GL_AMBIENT, light_amb);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, light_dif);
    glLightfv(GL_LIGHT2, GL_SPECULAR, light_spec);
}

void renderBitmapString()
{
    string px="+x";
    string py="+y";
    string pz="+z";

    glColor3f(1.0, 0.0, 0.0);
	glRasterPos3f(.2,0,0);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)px.c_str());

	glColor3f(0.0, 1.0, 0.0);
	glRasterPos3f(0,.2,0);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)py.c_str());

	glColor3f(0.0, 0.0, 1.0);
	glRasterPos3f(0,0,0.2);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)pz.c_str());

}


void textOverlay(string s)
{
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0.0, WINW, 0.0, WINH);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(.7 ,.7 ,.7 );
    glRasterPos2f(10,10);


    void * font = GLUT_BITMAP_9_BY_15;
    for (string::iterator i = s.begin(); i != s.end(); ++i)
    {
        char c = *i;
        glutBitmapCharacter(font, c);

        glDisable(GL_COLOR_MATERIAL);

        glMatrixMode(GL_MODELVIEW);
        glPopMatrix();

        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
    }
}

void displayOverlay()
{
    if (!isOrtho)
    {
        if (isTurnTable)
            textOverlay("Perspective (Turn Table)");
        else
            textOverlay("Perspective");
    }

    else
    {
        if (isTurnTable)
            textOverlay("Orthographic (Turn Table)");
        else
         textOverlay("Orthographic");
    }


}

void reset()
{
    translate_x = translate_y = translate_z = 0.0f;
    rot_x = rot_y = rot_z = 0.0f;
    scale_x = scale_y = scale_z = 1.0f;
    previousX = previousY = previousZ = 0;
    glutPostRedisplay ();
    cout << "transformation reset!" <<endl;
}

void turnTableMode ()
{
    rot_x = 33.5;

    int start_time = glutGet(GLUT_ELAPSED_TIME);
    rot_y = rot_y - 0.5;
    while(glutGet(GLUT_ELAPSED_TIME) - start_time < 30);


}

void keyboard (unsigned char key, int x, int y)
{

    keys[key] = true;
    switch(key)
    {
    case 'r': case 'R':
        reset();
        break;
    case 'f':case 'F':
        glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
        if (isFullscreen)
            isFullscreen = false;
        else
            isFullscreen = true;
        glutFullScreenToggle();
        break;

    case 27:
        glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);

        if(isFullscreen)
        {
             glutFullScreenToggle();
             isFullscreen = false;
        }

        else
        glutLeaveMainLoop();
        break;

    case 'w':  case 'W':
        glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
        if (isWireframe)
            isWireframe = false;
        else
            isWireframe = true;
        break;

    case 't': case 'T':
        glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
        if (isTurnTable)
            isTurnTable = false;
        else
              isTurnTable = true;
        break;
    default: break;
    }
}

void keyboardUp (unsigned char key, int x, int y)
{
     keys[key] = false;
}

void mouse (int button, int state, int x, int y)
{
    //  checks if the user presses the left button
    if (button == GLUT_LEFT_BUTTON)
    {
        tumble = state == GLUT_DOWN;
    }
    // this is used to move the object with relative to the Z axis
    else if (button == GLUT_MIDDLE_BUTTON)
    {
        // if the mouse is pressed
        track = state == GLUT_DOWN;
    }

    previousX = x;
    previousY = y;
    previousZ = y;
}

void mouseWheel(int button, int dir, int x, int y)
{

        if (dir > -1)
        {
            scale_x = scale_x + 0.025;
            scale_y = scale_y + 0.025;
            scale_z = scale_z + 0.025;
        }
        else
        {
            if (scale_x > 0.1)
            {
            scale_x = scale_x - 0.025;
            scale_y = scale_y - 0.025;
            scale_z = scale_z - 0.025;
            }


        }

        cout << "zoom: " << scale_x << "x"<< endl;

}

void motion (int x, int y)
{

    //  Scale
    if (track && !isTurnTable)
    {
        translate_x += (x - previousX) * 0.0025;
        translate_y -= (y - previousY) * 0.0025;

        cout << "x origin: " << translate_x <<" | y origin: " <<translate_y << endl;
    }

    //  Rotate
    if (tumble && !isTurnTable)
    {
        if ((y - previousY) >= 0)
            rot_x += (y - previousY)* 0.5;
        else
            rot_x += (y - previousY)* 0.5;
        if ((x - previousX) >= 0 )
            rot_y += (x - previousX)* 0.5;
        else
            rot_y += (x - previousX)* 0.5;

        cout << "x_rot: " << rot_x <<" | y_rot: "<< rot_y <<endl;

    }

    // reset the previousX, previousY, and previousZ to the current position of the mouse
    previousX = (float)x;
    previousY = (float)y;
    previousZ = (float)y;

    glutPostRedisplay();
}

void draw_axes(void)
{
    glBegin(GL_LINES);
       glColor3f(1.0, 0.0, 0.0);    // draw x axis
       glVertex3f(-1.0, 0.0, 0.0);
       glVertex3f(1.0, 0.0, 0.0);

       glColor3f(0.0, 1.0, 0.0);    // draw y axis
       glVertex3f(0.0, -1.0, 0.0);
       glVertex3f(0.0, 1.0, 0.0);

       glColor3f(0.0, 0.0, 1.0);    // draw z axis
       glVertex3f(0.0, 0.0, -1.0);
       glVertex3f(0.0, 0.0, 1.0);
    glEnd();
}

void draw_grid(void)
{
    glBegin(GL_LINES);
    for(GLfloat a =-1; a <= 1;){
        glColor4f(.3, .3, .3 ,.5);
        glVertex3f(-1,0,(float)a);
        glVertex3f(1,0,(float)a);
        a = a+0.08;
    }
    glEnd();

    glBegin(GL_LINES);
    for(GLfloat b =-1; b <= 1;){
        glColor4f(.3, .3, .3,.5);
        glVertex3f((float)b,0,-1);
        glVertex3f((float)b,0,1);
        b = b+0.08;
    }
    glEnd();
}

void projection (int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(h==0) h=1;
    if(isOrtho)
        glOrtho(-1.0*w/h, 1.0*w/h, -1.0, 1.0, -2, 3.50);
    else
        gluPerspective(60.0, (GLfloat)w/(GLfloat)h, 0.05, 20.0);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void event_display (void)
{

    glClearColor(.15, .15, .15, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //  Set camera position and view vector
    glMatrixMode (GL_MODELVIEW);
    gluLookAt (0, 0, 1,
               0, 0, 0,
               0, 1, 0);

    //  apply translation
    glTranslatef (translate_x, translate_y, translate_z);
    // apply rotation
    glRotatef (rot_x, 1.0f, 0.0f, 0.0f);
    glRotatef (rot_y, 0.0f, 1.0f, 0.0f);
    glRotatef (rot_z, 0.0f, 0.0f, 1.0f);
    //  apply scaling
    glScalef (scale_x, scale_y, scale_z);


    if(isTurnTable)
        turnTableMode();

    glDisable(GL_LIGHTING);
    draw_axes ();
    draw_grid ();
    renderBitmapString();
    glEnable(GL_NORMALIZE);

    if(isWireframe)
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    //enable lighting here
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);

    glEnable(GL_TEXTURE_2D);

    light0();
    light1();
    light2();


    //drawmaterial
    material0();

    //draw objects
    drawObject ();


    //disable lighting here
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT2);
    glDisable(GL_LIGHT1);
    glDisable(GL_LIGHT0);

    glDisable(GL_TEXTURE_2D);

    glLoadIdentity ();

    displayOverlay();

    glutSwapBuffers ();
}


void init (void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    Image* image = loadBMP("house/grass.bmp");
	textureId[0] = loadTexture(image);
	delete image;

	Image* image1 = loadBMP("house/wall.bmp");
	textureId[1] = loadTexture(image);
	delete image;

	Image* image2 = loadBMP("house/wall2.bmp");
	textureId[2] = loadTexture(image);
	delete image;

    Image* image3 = loadBMP("house/door.bmp");
	textureId[3] = loadTexture(image);
	delete image;

	Image* image4 = loadBMP("house/roof.bmp");
	textureId[4] = loadTexture(image);
	delete image;

	Image* image5 = loadBMP("house/path.bmp");
	textureId[5] = loadTexture(image);
	delete image;

	Image* image6 = loadBMP("house/floor.bmp");
	textureId[6] = loadTexture(image);
	delete image;

    Image* image7 = loadBMP("house/fence.bmp");
	textureId[7] = loadTexture(image);
	delete image;
}


void event_reshape(int w, int h)
{
    //set Viewport
    cout << "window size: "<< w<<"x "<<h<<endl;
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    projection(w,h);
}

void centerOnScreen ()
{
    window_x = (glutGet (GLUT_SCREEN_WIDTH) - WINW)/2;
    window_y = (glutGet (GLUT_SCREEN_HEIGHT) - WINH)/2;
}

void idle (void)
{

     if (keys[45])
     {
         int start_time = glutGet(GLUT_ELAPSED_TIME);
          if (scale_x > 0.1)
            {
                scale_x = scale_x - 0.025;
                scale_y = scale_y - 0.025;
                scale_z = scale_z - 0.025;
            }
        while(glutGet(GLUT_ELAPSED_TIME) - start_time < 20);
        cout << "zoom: " << scale_x << "x"<< endl;
     }

     if (keys[43] || keys[61])
     {
        int start_time = glutGet(GLUT_ELAPSED_TIME);

        scale_x = scale_x + 0.025;
        scale_y = scale_y + 0.025;
        scale_z = scale_z + 0.025;

        while(glutGet(GLUT_ELAPSED_TIME) - start_time < 20);
        cout << "zoom: " << scale_x << "x"<< endl;
     }


     glutPostRedisplay();
}

void processMenuEvents(int option) {
    switch (option)
    {
    case 1:
        isOrtho = true;
        cout <<"projection: orthographic " <<endl;
        break;
    case 2:
        isOrtho = false;
        cout <<"projection: perspective " <<endl;
        break;
    }

    int const w = glutGet(GLUT_WINDOW_WIDTH);
    int const h = glutGet(GLUT_WINDOW_HEIGHT);
    projection(w,h);
}

void createGLUTMenus()
{

	menu = glutCreateMenu(processMenuEvents);

	glutAddMenuEntry("Orthographic",1);
	glutAddMenuEntry("Perspective",2);

	// attach the menu to the right button
	glutAttachMenu(GLUT_RIGHT_BUTTON);

}

GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
				 0,                            //0 for now
				 GL_RGB,                       //Format OpenGL uses for image
				 image->width, image->height,  //Width and height
				 0,                            //The border of the image
				 GL_RGB, //GL_RGB, because pixels are stored in RGB format
				 GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
				                   //as unsigned numbers
				 image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}



int main(int argc, char** argv)
{

    // create window
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINW, WINH);
    centerOnScreen ();
    glutInitWindowPosition(window_x,window_y);
    //glutFullScreen();
    glutCreateWindow("OpenGL");
    init();

    // register callbacks
    glutReshapeFunc(event_reshape);
    glutDisplayFunc(event_display);
    glutMouseFunc (mouse);
    glutMouseWheelFunc(mouseWheel);
    glutMotionFunc (motion);
    glutKeyboardFunc (keyboard);
    glutKeyboardUpFunc (keyboardUp);

    glutIdleFunc(idle);
    createGLUTMenus();
    glutMainLoop();
    return 0;
}
