#include <GL/glut.h>  
#include <math.h>
#define pi 3.142857
#include "Header.h"

// rotaion varables
GLfloat animXRot, animYRot, animZRot = 0;

//camera variables
GLfloat camX = 0, camY = 0, camZ = 0;

//mover plane
GLfloat movePlaneX = 0, movePlaneY = 0, movePlaneZ = 60, helpPlane = 0;

//plane rotation
GLfloat planeRotateX, planeRotateY, planeRotateZ = 0;

//Crain variables - operating Room
//GLfloat crainY = 0;
//GLfloat crainWidth = 9;
//GLfloat crainArm = 0;

// boa6t variables
//GLfloat boatY = 360;

//scene variables
GLfloat sceX = 0, sceY = 0, sceZ = 0;

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    //glOrtho(-40, 40, -40, 40, -40, 40);
}

void drawGrid() {
    GLint line;
    GLfloat step = 1.0f;

    glLineWidth(2);
    glBegin(GL_LINES);

    for (line = -30; line <= 30; line += step) {
        glVertex3f(line, 0, 30);
        glVertex3f(line, 0, -30);

        glVertex3f(30, 0, line);
        glVertex3f(-30, 0, line);
    }
    glEnd();

}

//void drawSea() {
//    glBegin(GL_POLYGON);
//    glVertex3f(-10, 0, -10);
//    glVertex3f(10, 0, -10);
//    glVertex3f(10, 0, 10);
//    glVertex3f(-10, 0, 10);
//    glEnd();
//}

void drawAxes() {
    //z-axis
    glBegin(GL_LINES);
    glColor3f(1.0, 0, .0);
    glVertex3f(0, 0, 10);
    glVertex3f(0, 0, -10);
    glEnd();

    //y-axis
    glBegin(GL_LINES);
    glColor3f(0, 1.0, 0);
    glVertex3f(0, 10, 0);
    glVertex3f(0, -10, -0);
    glEnd();

    //x-axis
    glBegin(GL_LINES);
    glColor3f(0, 0, 1.0);
    glVertex3f(-10, 0, 0);
    glVertex3f(10, 0, 0);
    glEnd();
}
void runPlane() {
    //runaway plane
    glPushMatrix();
    glScalef(0.45, 0.45, 0.45);
    glTranslatef(0, 2.4+ movePlaneY, movePlaneZ);
    glRotatef(planeRotateX, 1, 0, 0);
    glRotatef(planeRotateY, 0, 1, 0);
    glRotatef(planeRotateZ, 0, 0, 1);


    glRotatef(180, 0, 1, 0);
    placePlane(0, 1, 0);
    glPopMatrix();
}

void displayScene() {

    //draw Flow
    glPushMatrix();
    drawFlow(0.678, 0.675, 0.404, 60, 60);
    glPopMatrix();

    //Place Plane
    //1st plane yard plane
    glPushMatrix();
    glScalef(0.45, 0.45, 0.45);
    glTranslatef(-27, 2.4, 0);
    glRotatef(-45, 0, 1, 0);
    placePlane(0, 1, 0);
    glPopMatrix();

    //2nd plane yard plane
    glPushMatrix();
    glScalef(0.45, 0.45, 0.45);
    glTranslatef(-27, 2.4, 31.5);
    glRotatef(-45, 0, 1, 0);
    placePlane(0, 1, 0);
    glPopMatrix();

    //3rd plane yard plane
    glPushMatrix();
    glScalef(0.45, 0.45, 0.45);
    glTranslatef(-22, 2.4, 58);
    glRotatef(-45, 0, 1, 0);
    placePlane(0, 1, 0);
    glPopMatrix();

    //1nd plane
    glPushMatrix();
    glScalef(0.45, 0.45, 0.45);
    glTranslatef(27, 2.4, 0);
    glRotatef(45, 0, 1, 0);
    placePlane(0, 1, 0);
    glPopMatrix();

    //2nd plane
    glPushMatrix();
    glScalef(0.45, 0.45, 0.45);
    glTranslatef(27, 2.4, 31.5);
    glRotatef(45, 0, 1, 0);
    placePlane(0, 1, 0);
    glPopMatrix();

    //movin plane
    runPlane();

    //Place Building
    //departure
    glPushMatrix();
    glTranslatef(20, 0, 0);
    glScalef(2, 2.5, 3);
    drawBuilding();
    glPopMatrix();

    //Place Yard
    //1st plane yard
    glPushMatrix();
    glTranslatef(-13.25, 0.25, 1.25);
    glRotatef(135, 0, 1, 0);
    placeYard();
    glPopMatrix();

    //2nd plane yard
    glPushMatrix();
    glTranslatef(-13.25, 0.25, 15.25);
    glRotatef(135, 0, 1, 0);
    placeYard();
    glPopMatrix();

    //3rd plane yard
    glPushMatrix();
    glTranslatef(-11.25, 0.25, 27.25);
    glRotatef(135, 0, 1, 0);
    placeYard();
    glPopMatrix();

    //Place Bus
    //2nd bus
    glPushMatrix();
    glScalef(0.6, 0.6, 0.6);
    glTranslatef(25, 2.25, -20);
    placeBus(1, 0, 0, 0, 0, 0);
    glPopMatrix();

    //1st bus
    glPushMatrix();
    glScalef(0.6, 0.6, 0.6);
    glTranslatef(25, 2.25, -35);
    placeBus(0.6, 0.1, 0.8, 0, 0, 0);
    glPopMatrix();

    //flow
    glPushMatrix();
    drawFlow(0.5, 0.5, 0.5, 10, 10);
    glPopMatrix();

    //runaway
    glPushMatrix();
    drawRunaway(1, 1, 1, 10, 60);
    glPopMatrix();
    
    //short 1st yard runaway
    glPushMatrix();
    glTranslatef(-6, -0.02, -6);
    glRotatef(-45, 0, 1, 0);
    drawRunaway(1, 1, 1, 7, 15);
    glPopMatrix();

    //short 1st runaway no yard
    glPushMatrix();
    glTranslatef(6, -0.02, -6);
    glRotatef(45, 0, 1, 0);
    drawRunaway(1, 1, 1, 7, 15);
    glPopMatrix();

    //short 2nd runaway no yard
    glPushMatrix();
    glTranslatef(6, -0.02, 8);
    glRotatef(45, 0, 1, 0);
    drawRunaway(1, 1, 1, 7, 15);
    glPopMatrix();

    //short 2nd yard runaway
    glPushMatrix();
    glTranslatef(-6, -0.02, 8);
    glRotatef(-45, 0, 1, 0);
    drawRunaway(1, 1, 1, 7, 15);
    glPopMatrix();

    //short 3rd yard runaway
    glPushMatrix();
    glTranslatef(-4, -0.02, 20);
    glRotatef(-45, 0, 1, 0);
    drawRunaway(1, 1, 1, 7, 15);
    glPopMatrix();

    //short 3rd runaway no yard 
    glPushMatrix();
    glTranslatef(4, -0.02, 20);
    glRotatef(45, 0, 1, 0);
    drawRunaway(1, 1, 1, 7, 15);
    glPopMatrix();
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(-30 + camX, 30 + camY, -30 + camZ, 0, 0, 0, 0, 1, 0);

    /* set material parameters */
    const GLfloat blue[4] = { 0.3, 0.3, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);
    const GLfloat matwhite[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glMaterialfv(GL_FRONT, GL_SPECULAR, matwhite);
    glMaterialf(GL_FRONT, GL_SHININESS, 128.0f);

    /* positioned the light source 1 */
    GLfloat position0[] = { 20.0,2.0,20.0,1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, position0);

    /* set light intensities for light source 1 */
    GLfloat paleYellow[] = { 1.0,1.0,0.75,1.0 };
    glLightfv(GL_LIGHT0, GL_DIFFUSE, paleYellow);
    GLfloat white[] = { 1.0,1.0,1.0,1.0 };
    glLightfv(GL_LIGHT0, GL_SPECULAR, white);
    glEnable(GL_LIGHT0);

    /* positioned the light source 2 */
    GLfloat position1[] = { -20.0,2.0,-20.0,1.0 };
    glLightfv(GL_LIGHT1, GL_POSITION, position1);

    /* set light intensities for light source 2 */
    glLightfv(GL_LIGHT1, GL_DIFFUSE, paleYellow);
    GLfloat green[] = { 0.0,1.0,0.0,1.0 };
    glLightfv(GL_LIGHT1, GL_SPECULAR, green);
    glEnable(GL_LIGHT1);




    glTranslatef(sceX, sceY, sceZ);
    glRotatef(animYRot, 0, 1, 0);
    glPushMatrix();
    drawAxes();

    glPushMatrix();
    glColor3f(1.0, 1, 1);
    drawGrid();
    glPopMatrix();

    glPushMatrix();
    displayScene();
    //drawBuilding();
    glPopMatrix();

    glutSwapBuffers();
    glFlush();
}

 //animation timer function
void Timer(int v) {
  
    helpPlane++;
    if (helpPlane < 40) {
        movePlaneZ -= 2;
    }
    if (helpPlane > 40) {
        movePlaneZ -= 2;
       
        if (helpPlane > 40 && helpPlane < 50) {
            planeRotateX += 2;
        }
    }
    if (helpPlane > 44) {
        movePlaneY += 1;
    }

 /*   if (helpPlane > 60) {
        planeRotateY = -180;
        movePlaneZ += 2;
        
        if (helpPlane > 70 && helpPlane < 80) {
            planeRotateX -= 1;
        }
        if (helpPlane > 85) {
            movePlaneY = 0;
        }
    }
    if (helpPlane > 70) {
        movePlaneY -= 1;
    }
    if (helpPlane > 90) {
        planeRotateY += 1;
    }*/

    glutPostRedisplay();
    glutTimerFunc(60, Timer, 0);
}

// keyboardSpecial
void keyboardSpecial(int key, int x, int y) {
    // camera up and down
    if (key == GLUT_KEY_UP) {
        camY += 1;
    }
    if (key == GLUT_KEY_DOWN) {
        camY -= 1;
    }

    // camera left and right
    if (key == GLUT_KEY_LEFT) {
        camX -= 1;
    }
    if (key == GLUT_KEY_RIGHT) {
        camX += 1;
    }
    // camera front and back
    if (key == GLUT_KEY_HOME) {
        camZ -= 1;
    }
    if (key == GLUT_KEY_END) {
        camZ += 1;
    }

    glutPostRedisplay();
}

// keyboard move object 
void keyboard(unsigned char key, int x, int y) {
    // rotate snow man
    if (key == 'l') {
        animYRot += 1;
    }
    if (key == 'r') {
        animYRot -= 1;
    }
    if (key == 'c') {
        camX = 0;
        camY = 0;
        camZ = 0;
        animYRot = 0;
    }

    // operating room
    /*if (key == 'C') {
        if (crainY == 360) {
            crainY = 0;
        }
        else {
            crainY += 1;
        }
    }
    if (key == 'c') {
        if (crainY == 0) {
            crainY = 360;
        }
        else {
            crainY -= 1;
        }
    }*/

    // Crain arm
    /*if (key == 'a') {
        if (crainArm >= 85) {
            crainArm = 85;
        }
        else {
            crainArm += 1;
        }
    }
    if (key == 'A') {
        if (crainArm <= 0) {
            crainArm = 0;
        }
        else {
            crainArm -= 1;
        }
    }
    if (key == 'w') {
        if (crainWidth >= 9) {
            crainWidth = 9;
        }
        else {
            crainWidth += 0.02;
        }
    }
    if (key == 'W') {
        if (crainWidth <= 5.5) {
            crainWidth = 5.5;
        }
        else {
            crainWidth -= 0.02;
        }
    }*/

    // Move Scene along X axis
    if (key == 'X') {
        sceX -= 1;
    }
    if (key == 'x') {
        sceX += 1;
    }
    // Move Scene along Y axis
    if (key == 'Y') {
        sceY -= 1;
    }
    if (key == 'y') {
        sceY += 1;
    }
    //Move Scene along Z axis
    if (key == 'Z') {
        sceZ -= 1;
    }
    if (key == 'z') {
        sceZ += 1;
    }

    // Control light source 1
    if (key == '1') {
        glEnable(GL_LIGHT0);
    }
    if (key == '!') {
        glDisable(GL_LIGHT0);
    }

    // Control light source 2
    if (key == '2') {
        glEnable(GL_LIGHT1);
    }
    if (key == '@') {
        glDisable(GL_LIGHT1);
    }

    glutPostRedisplay();
}


void reshape(GLsizei w, GLsizei h) {
    glViewport(0, 0, w, h);
    GLfloat aspect_ratio = h == 0 ? w / 1 : (GLfloat)w / (GLfloat)h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(50.0, aspect_ratio, 1.0, 100.0);

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(150, 150);
    glutCreateWindow("S17372 Project Air Port");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    // keyboard function activation
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(keyboardSpecial);

    glutTimerFunc(200, Timer, 0);

    glutMainLoop();

    return 0;
}
