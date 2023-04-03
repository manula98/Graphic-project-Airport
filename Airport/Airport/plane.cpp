#include "Header.h"
#include <GL/glut.h>  
#include <math.h>
#define pi 3.142857



void drawCircle(float radius) {
	int d;
	glBegin(GL_POLYGON);
	for (d = 0; d < 32; d++) {
		double angle = 2 * pi / 32 * d;
		glVertex2d(radius * cos(angle), radius * sin(angle));
	}
	glEnd();
}

void drawCylinder(float r, float h) {
	glPushMatrix();
	//glColor3f(1, 1, 0);
	glTranslatef(0, 0, -h / 2);
	glPushMatrix();
	GLUquadricObj* qaudratic;
	qaudratic = gluNewQuadric();
	gluCylinder(qaudratic, r, r, h, 100, 100);
	drawCircle(r);
	glTranslatef(0, 0, h);
	drawCircle(r);
	glPopMatrix();
	glPopMatrix();

}

void drawSphere(double r) {
	glPushMatrix();
	//glColor3f(1, 1, 0);
	glutSolidSphere(r, 100, 100);
	glPopMatrix();
}

void drawBackPlane(float r,float g,float b) {
	glPushMatrix();
	glColor3f(r, g, b);
	glPushMatrix();

	glEnable(GL_CLIP_PLANE0);


	double planeEquation[] = { 0.0, 1.0, 1.0, 0.6 }; 
	glClipPlane(GL_CLIP_PLANE0, planeEquation);

	glPushMatrix();
	drawCylinder(1, 5);
	glPopMatrix();
	glDisable(GL_CLIP_PLANE0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -0.7);
	glRotatef(13, 1, 0, 0);
	glScalef(1, 0.85, 2.5);
	drawSphere(1);
	glPopMatrix();
	glPopMatrix();
}

void drawCube(){
	glPushMatrix();
	glScalef(8, 1, 4);
	glutSolidCube(1);
	glPopMatrix();
}

void drawPlaneLeftWin(float r,float g,float b) {
	glPushMatrix();

	glPushMatrix();
	glTranslatef(0.2, 0, 0.4);
	glRotatef(23, 0, 1, 0);
	glRotatef(90, 0, 1, 0);

	glEnable(GL_CLIP_PLANE0);

	double planeEquation0[] = { 1.0, 0.0, 0.0, -0.8 };
	glClipPlane(GL_CLIP_PLANE0, planeEquation0);

	glPushMatrix();
	drawCylinder(0.95, 8.55);
	glPopMatrix();

	glDisable(GL_CLIP_PLANE0);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_CLIP_PLANE1);
	glEnable(GL_CLIP_PLANE2);

	double planeEquation1[] = { 3.5, 0.0, 8.0, 4.0 };
	double planeEquation2[] = { 0.0, -4.0, -0.9, 0.2 };
	glClipPlane(GL_CLIP_PLANE1, planeEquation1);
	glClipPlane(GL_CLIP_PLANE2, planeEquation2);

	glPushMatrix();
	//glTranslatef(1, 0, 2);
	drawCube();
	glPopMatrix();

	glDisable(GL_CLIP_PLANE1);
	glDisable(GL_CLIP_PLANE2);
	glPopMatrix();


	glPushMatrix();
	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	glVertex3f(3.5, 0.5, -2);
	glVertex3f(4, 0.5, -2);
	glVertex3f(4, -0.4, 2);
	glVertex3f(-4, -0.4,2);
	glVertex3f(-4, -0.3, 1.2);
	glEnd();
	glPopMatrix();

	glPopMatrix();
}
void drawLeftWin(float r, float g, float b) {
	glPushMatrix();
	glEnable(GL_CLIP_PLANE1);
	double planeEquation2[] = { 0.0, -4.0, -0.9, 0.2 };
	glClipPlane(GL_CLIP_PLANE1, planeEquation2);
	drawPlaneLeftWin(r, g, b);
	glDisable(GL_CLIP_PLANE1);
	glPopMatrix();
}

void drawPlaneRightWin(float r, float g, float b) {
	glPushMatrix();

	glPushMatrix();
	glTranslatef(0.3, 0, -0.5);
	glRotatef(-23, 0, 1, 0);
	glRotatef(-90, 0, 1, 0);

	glEnable(GL_CLIP_PLANE0);

	double planeEquation0[] = { 1.0, 0.0, 0.0, -0.8 };
	glClipPlane(GL_CLIP_PLANE0, planeEquation0);

	glPushMatrix();
	drawCylinder(0.95, 8.55);
	glPopMatrix();

	glDisable(GL_CLIP_PLANE0);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_CLIP_PLANE1);
	glEnable(GL_CLIP_PLANE2);

	double planeEquation1[] = { 3.5, 0.0, -8.0, 4.0 };
	double planeEquation2[] = { 0.0, -4.0, 0.9, 0.2 };
	glClipPlane(GL_CLIP_PLANE1, planeEquation1);
	glClipPlane(GL_CLIP_PLANE2, planeEquation2);

	glPushMatrix();
	//glTranslatef(1, 0, 2);
	drawCube();
	glPopMatrix();

	glDisable(GL_CLIP_PLANE1);
	glDisable(GL_CLIP_PLANE2);
	glPopMatrix();


	glPushMatrix();
	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	glVertex3f(4, -0.4, -2);
	glVertex3f(3.5, 0.5, 2);
	glVertex3f(4, 0.5, 2);
	glVertex3f(-4, -0.3, -1.3);
	glVertex3f(-4, -0.4, -2);
	glEnd();
	glPopMatrix();

	glPopMatrix();
}

void drawRightWin(float r, float g, float b) {
	glPushMatrix();
	glEnable(GL_CLIP_PLANE1);
	double planeEquation2[] = { 0.0, -4.0, 0.9, 0.2 };
	glClipPlane(GL_CLIP_PLANE1, planeEquation2);
	drawPlaneRightWin(r, g, b);
	glDisable(GL_CLIP_PLANE1);
	glPopMatrix();
}

void drawBackWin(float r, float g, float b) {
	glPushMatrix();

	glPushMatrix();
	glRotatef(-90, 0, 0, 1);
	glScalef(0.4, 0.4, 0.4);
	drawRightWin(r, g, b);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.7, 0, -0.4);
	glRotatef(180, 0, 1, 0);
	glScalef(0.2, 0.2, 0.2);
	drawLeftWin(r, g, b);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.8, 0, -0.4);
	glScalef(0.2, 0.2, 0.2);
	drawRightWin(r, g, b);
	glPopMatrix();

	glPopMatrix();
}

void drawWeel() {
	glPushMatrix();

	glPushMatrix();
	glTranslatef(0, -1.5, 0);
	glScalef(2, 2, 1);
	glRotatef(90, 0, 1, 0);

	glPushMatrix();
	glEnable(GL_CLIP_PLANE0);
	glEnable(GL_CLIP_PLANE1);

	double planeEquation[] = { 1.0, 0.0, 0.0, 0.8 };
	double planeEquation1[] = { -1.0, 0.0, 0.0, 0.8 };

	glClipPlane(GL_CLIP_PLANE0, planeEquation);
	glClipPlane(GL_CLIP_PLANE1, planeEquation1);

	glPushMatrix();
	glColor3f(0, 0, 0);
	//glScalef(1, 2, 2);
	drawSphere(1);
	glPopMatrix();
	glDisable(GL_CLIP_PLANE0);
	glDisable(GL_CLIP_PLANE1);

	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glRotatef(90, 0, 1, 0);
	drawCylinder(0.6, 1.5);
	glPopMatrix();

	//weel bar
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(0, 2, 0);
	glRotatef(90, 1, 0, 0);
	drawCylinder(0.3, 1);
	glPopMatrix();

	glPopMatrix();


	//axsel
	glPushMatrix();
	for(int i = 0; i < 360; i += 90) {
		glPushMatrix();
		glRotatef(i, 1, 0, 0);
		glTranslatef(0, 1.5, 0);
		glEnable(GL_CLIP_PLANE2);
		glEnable(GL_CLIP_PLANE3);

		double planeEquation2[] = { 0.0, 1.0, 1.0, 1.5 };
		double planeEquation3[] = { 0.0, 1.0, -1.0, 1.5 };

		glClipPlane(GL_CLIP_PLANE2, planeEquation2);
		glClipPlane(GL_CLIP_PLANE3, planeEquation3);

		glPushMatrix();
		glColor3f(1, 1, 1);
		drawCylinder(0.5, 4);
		glPopMatrix();
		glDisable(GL_CLIP_PLANE2);
		glDisable(GL_CLIP_PLANE3);

		glPopMatrix();
	}
	glPopMatrix();

	glPopMatrix();
}

void drawWeelSet() {
	glPushMatrix();

	glPushMatrix();
	glTranslatef(0, -1.6, 3);
	glScalef(0.2, 0.2, 0.2);
	glRotatef(90, 0, 1, 0);
	drawWeel();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5, -1.4, -3);
	glScalef(0.2, 0.2, 0.2);
	glRotatef(90, 0, 1, 0);
	drawWeel();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, -1.4, -3);
	glScalef(0.2, 0.2, 0.2);
	glRotatef(90, 0, 1, 0);
	drawWeel();
	glPopMatrix();

	glPopMatrix();
}

void drawFrontWindow() {

	glPushMatrix();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(0, 0, 0, 1);
	
	glEnable(GL_CLIP_PLANE0);
	glEnable(GL_CLIP_PLANE1);
	glEnable(GL_CLIP_PLANE2);
	glEnable(GL_CLIP_PLANE3);

	double planeEquation0[] = { 0.0, 0.0, -1.0, 0.0 };
	double planeEquation1[] = { 0.0, -1.0, 0.0, 0.7 };
	double planeEquation2[] = { 0.0, 1.0, 0.0, -0.15 };
	double planeEquation3[] = { 0.0, 0.0, -0.1, 1 };

	glClipPlane(GL_CLIP_PLANE0, planeEquation0);
	glClipPlane(GL_CLIP_PLANE1, planeEquation1);
	glClipPlane(GL_CLIP_PLANE2, planeEquation2);
	glClipPlane(GL_CLIP_PLANE3, planeEquation3);

	glPushMatrix();
	glScalef(1, 1, 2);
	drawSphere(1);
	glPopMatrix();

	glDisable(GL_CLIP_PLANE0);
	glDisable(GL_CLIP_PLANE1);
	glDisable(GL_CLIP_PLANE2);
	glDisable(GL_CLIP_PLANE3);
	glPopMatrix();

}

void drawSideWindow1() {

	glPushMatrix();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(0, 0, 0, 1);

	glEnable(GL_CLIP_PLANE0);
	glEnable(GL_CLIP_PLANE1);
	glEnable(GL_CLIP_PLANE2);
	glEnable(GL_CLIP_PLANE3);
	glEnable(GL_CLIP_PLANE4);

	double planeEquation0[] = { -1.0, 0.0, 0.0, -0.3 };
	double planeEquation1[] = { 0.0, 1.0, 0.0, -0.4 };
	double planeEquation2[] = { 0.0, 1.0, 1.0, 4 };
	double planeEquation3[] = { 0.0, -1.0, -1.0, 2 };
	double planeEquation4[] = { 0.0, -1.0, 0.0, 0.8 };

	glClipPlane(GL_CLIP_PLANE0, planeEquation0);
	glClipPlane(GL_CLIP_PLANE1, planeEquation1);
	glClipPlane(GL_CLIP_PLANE2, planeEquation2);
	glClipPlane(GL_CLIP_PLANE3, planeEquation3);
	glClipPlane(GL_CLIP_PLANE4, planeEquation4);

	glPushMatrix();
	glScalef(1, 1, 2);
	drawCylinder(1, 6);
	glPopMatrix();

	glDisable(GL_CLIP_PLANE0);
	glDisable(GL_CLIP_PLANE1);
	glDisable(GL_CLIP_PLANE2);
	glDisable(GL_CLIP_PLANE3);
	glDisable(GL_CLIP_PLANE4);
	glPopMatrix();
}

void drawSideWindow2() {
	glPushMatrix();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(0, 0, 0, 1);

	glEnable(GL_CLIP_PLANE0);
	glEnable(GL_CLIP_PLANE1);
	glEnable(GL_CLIP_PLANE2);
	glEnable(GL_CLIP_PLANE3);
	glEnable(GL_CLIP_PLANE4);

	double planeEquation0[] = { 1.0, 0.0, 0.0, -0.3 };
	double planeEquation1[] = { 0.0, 1.0, 0.0, -0.4 };
	double planeEquation2[] = { 0.0, 1.0, 1.0, 4 };
	double planeEquation3[] = { 0.0, -1.0, -1.0, 2 };
	double planeEquation4[] = { 0.0, -1.0, 0.0, 0.8 };

	glClipPlane(GL_CLIP_PLANE0, planeEquation0);
	glClipPlane(GL_CLIP_PLANE1, planeEquation1);
	glClipPlane(GL_CLIP_PLANE2, planeEquation2);
	glClipPlane(GL_CLIP_PLANE3, planeEquation3);
	glClipPlane(GL_CLIP_PLANE4, planeEquation4);

	glPushMatrix();
	glScalef(1, 1, 2);
	drawCylinder(1, 6);
	glPopMatrix();

	glDisable(GL_CLIP_PLANE0);
	glDisable(GL_CLIP_PLANE1);
	glDisable(GL_CLIP_PLANE2);
	glDisable(GL_CLIP_PLANE3);
	glDisable(GL_CLIP_PLANE4);
	glPopMatrix();
}

void drawEngineWin() {
	glPushMatrix();
	glScalef(0.2, 1, 0.4);
	drawCircle(0.5);
	glPopMatrix();
}

void drawEngine(float r,float g,float b) {
	glPushMatrix();
	
	glPushMatrix();

	glEnable(GL_CLIP_PLANE0);
	double planeEquation[] = { 0.0, 0.0, 1.0, 0.5 };
	glClipPlane(GL_CLIP_PLANE0, planeEquation);

	glPushMatrix();
	glColor3f(r, g, b);
	glScalef(1, 1, 4);
	drawSphere(1);
	glPopMatrix();
	glDisable(GL_CLIP_PLANE0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(r, g, b);
	glTranslatef(0, 0, -0.5);
	for (int i = 0; i < 360; i += 60) {
		glPushMatrix();
		glRotatef(i, 0, 0, 1);
		glTranslatef(0, 0.5, 0);
		drawEngineWin();
		glPopMatrix();
	}
	glPopMatrix();

	glPushMatrix();
	glColor3f(r, g, b);
	glTranslatef(0, 0, -0.5);
	glRotatef(30, 0, 0, 1);
	for (int i = 0; i < 360; i += 60) {
		glPushMatrix();
		glRotatef(i, 0, 0, 1);
		glTranslatef(0, 0.5, 0);
		drawEngineWin();
		glPopMatrix();
	}
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	drawCircle(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -0.5);
	drawCylinder(0.3, 0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0, 0, -0.25);
	drawCylinder(0.1, 0.5);
	glPopMatrix();

	glPopMatrix();
}

void drawEngineSet() {
	glPushMatrix();

	glPushMatrix();
	glScalef(0.5, 0.5, 0.75);
	glTranslatef(5, -1.8, 1);
	glRotatef(180, 1, 0, 0);
	drawEngine(1,1,1);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.5, 0.5, 0.75);
	glTranslatef(-5, -1.8, 1);
	glRotatef(180, 1, 0, 0);
	drawEngine(1,1,1);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.3, 0.3, 0.5);
	glTranslatef(16, -2.2, 0);
	glRotatef(180, 1, 0, 0);
	drawEngine(1,1,1);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.3, 0.3, 0.5);
	glTranslatef(-16, -2.2, 0);
	glRotatef(180, 1, 0, 0);
	drawEngine(1,1,1);
	glPopMatrix();

	glPopMatrix();
}

void drawPlane(float r,float g,float b) {
	glPushMatrix();

	glPushMatrix();
	glColor3f(r, g, b);
	glScalef(1, 1, 2);
	glTranslatef(0, 0, 1.5);
	drawSphere(1);
	glPopMatrix();

	glPushMatrix();
	//glColor3f(r, g, b);
	//glColor3f(0, 0, 1);
	glTranslatef(0, 0, -4);
	drawBackPlane(r,g,b);
	glPopMatrix();

	glPushMatrix();
	drawCylinder(1, 6);
	glPopMatrix();
	
	float c = 0.8;

	glPushMatrix();
	glTranslatef(4, 0, 0);
	glScalef(c, c, c);
	glRotatef(180, 0, 1, 0);
	drawLeftWin(r,g,b);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4, 0, 0);
	glScalef(c, c, c);
	drawRightWin(r,g,b);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1.5, -5.8);
	drawBackWin(r,g,b);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 3.01);
	glRotatef(180, 0, 1, 0);
	drawFrontWindow();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.1, 0, 0);
	drawSideWindow1();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.1, 0, 0);
	drawSideWindow2();
	glPopMatrix();

	glPushMatrix();
	drawEngineSet();
	glPopMatrix();

	glPushMatrix();
	drawWeelSet();
	glPopMatrix();

	glPopMatrix();
	
}

void placePlane(float r,float g,float b) {
	
	glPushMatrix();
	//glTranslatef(x, y, z);
	drawPlane(r, g, b);
	glPopMatrix();
}