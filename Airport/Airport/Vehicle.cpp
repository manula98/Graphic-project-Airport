#include "Header.h"
#include <GL/glut.h>  
#include <math.h>
#define pi 3.142857

void drawCircle2(double radius) {
	int d;
	glBegin(GL_POLYGON);
	for (d = 0; d < 32; d++) {
		double angle = 2 * pi / 32 * d;
		glVertex2d(radius * cos(angle), radius * sin(angle));
	}
	glEnd();
}

void drawCylinder2(float r, float h) {
	glPushMatrix();
	glTranslatef(0, 0, -h / 2);
	glPushMatrix();
	GLUquadricObj* qaudratic;
	qaudratic = gluNewQuadric();
	gluCylinder(qaudratic, r, r, h, 100, 100);
	drawCircle2(r);
	glTranslatef(0, 0, h);
	drawCircle2(r);
	glPopMatrix();
	glPopMatrix();

}

void drawSphere1(double r) {
	glPushMatrix();
	glutSolidSphere(r, 100, 100);
	glPopMatrix();
}

void drawCube2(float i) {
	glPushMatrix();
	glutSolidCube(i);
	glPopMatrix();
}

void drawBusSideWindow(int r,int g,int b) {
	
	glPushMatrix();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPushMatrix();
	glTranslatef(0, -0.75, 0);
	glBegin(GL_POLYGON);
	glColor3f(r, g, b);
	glVertex3f(0, 0.75, 1.25);
	glVertex3f(0, 0.75, -1.25);
	glVertex3f(0, -0.75, -1.25);
	glVertex3f(0, -0.75, 1.25);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.75, 1.125);
	glBegin(GL_POLYGON);
	glColor3f(r, g, b);
	glVertex3f(0, 0.75, 0.125);
	glVertex3f(0, 0.75, -0.125);
	glVertex3f(0, -0.75, -0.125);
	glVertex3f(0, -0.75, 0.125);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.75, -1.125);
	glBegin(GL_POLYGON);
	glColor3f(r, g, b);
	glVertex3f(0, 0.75, 0.125);
	glVertex3f(0, 0.75, -0.125);
	glVertex3f(0, -0.75, -0.125);
	glVertex3f(0, -0.75, 0.125);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1.38, 0);
	glBegin(GL_POLYGON);
	glColor3f(r, g, b);
	glVertex3f(0, 0.125, 1.25);
	glVertex3f(0, 0.125, -1.25);
	glVertex3f(0, -0.125, -1.25);
	glVertex3f(0, -0.125, 1.25);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.65, 0);
	glBegin(GL_POLYGON);
	glColor4f(0, 0, 1, 0.5);
	glVertex3f(0, 0.65, 1.0);
	glVertex3f(0, 0.65, -1.0);
	glVertex3f(0, -0.65, -1.0);
	glVertex3f(0, -0.65, 1.0);
	glEnd();
	glPopMatrix();

	glPopMatrix();
}

void drawFrontGlass(int r,int g,int b) {

	glPushMatrix();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_CLIP_PLANE0);
	double planeEquation[] = { 0.0, -1.0, 0.0, 1.5 };
	//glClipPlane(GL_CLIP_PLANE0, planeEquation);

	glPushMatrix();

	glScalef(1.1, 1.9, 1);
	glTranslatef(0, 0.28, -4.48);
	glRotatef(45, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex3f(0, 0.75, 1.25);
	glVertex3f(0, 0.75, -1.25);
	glVertex3f(0, -0.75, -1.25);
	glVertex3f(0, -0.75, 1.25);
	glEnd();
	glDisable(GL_CLIP_PLANE0);
	glPopMatrix();

	glPopMatrix();
}

void drawBusdoor(int r,int g,int b) {
	glPushMatrix();

	glPushMatrix();
	 glEnable(GL_CLIP_PLANE0);
	double planeEquation[] = { 0.0, 1.0, 0.0, 0,0 };
	glClipPlane(GL_CLIP_PLANE0, planeEquation);
	 
	glEnable(GL_CLIP_PLANE1);
	double planeEquation1[] = { 0.0, 0.5, -1.5, -0.75 };
	glClipPlane(GL_CLIP_PLANE1, planeEquation1);

	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	glVertex3f(0, 1.5, -0.25);
	glVertex3f(0, 1.5, 1.25);
	glVertex3f(0, -1.5, 1.25);
	glVertex3f(0, -1.5, -1.25);
	glVertex3f(0, -0.5, -1.25);
	glEnd();
	 glDisable(GL_CLIP_PLANE0);
	 glDisable(GL_CLIP_PLANE1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.65, 0.4);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glColor4f(0, 0, 1, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(0, 0.65, -0.475);
	glVertex3f(0, 0.65, 0.875);
	glVertex3f(0, -0.65, 0.875);
	glVertex3f(0, -0.65, -0.875);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_CLIP_PLANE2);
	double planeEquation2[] = { 0.0, 1.0, 0.0, -1.3 };
	glClipPlane(GL_CLIP_PLANE2, planeEquation2);

	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	glVertex3f(0, 1.5, -0.25);
	glVertex3f(0, 1.5, 1.25);
	glVertex3f(0, -1.5, 1.25);
	glVertex3f(0, -1.5, -1.25);
	glVertex3f(0, -0.5, -1.25);
	glEnd();
	glDisable(GL_CLIP_PLANE2);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_CLIP_PLANE3);
	double planeEquation3[] = { 0.0, -1.0, 0.0, 0,0 };
	glClipPlane(GL_CLIP_PLANE3, planeEquation3);

	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	glVertex3f(0, 1.5, -0.25);
	glVertex3f(0, 1.5, 1.25);
	glVertex3f(0, -1.5, 1.25);
	glVertex3f(0, -1.5, -1.25);
	glVertex3f(0, -0.5, -1.25);
	glEnd();
	glDisable(GL_CLIP_PLANE3);
	glPopMatrix();

	glPopMatrix();
}

void drawSide(int r,int g,int b) {

	glPushMatrix();

	glPushMatrix();
	glPushMatrix();
	glEnable(GL_CLIP_PLANE0);
	glEnable(GL_CLIP_PLANE1);
	glEnable(GL_CLIP_PLANE2);
	glEnable(GL_CLIP_PLANE3);

	double planeEquation0[] = { -1.0, 0.0, 0.0, 1.4 };
	double planeEquation1[] = { 1.0, 0.0, 0.0, 1.4 };
	double planeEquation2[] = { 0.0, -1.0, 2.0, 9.5 };
	double planeEquation3[] = { 0.0, 0.0, -1.0, 4.9 };
	glClipPlane(GL_CLIP_PLANE0, planeEquation0);
	glClipPlane(GL_CLIP_PLANE1, planeEquation1);
	glClipPlane(GL_CLIP_PLANE2, planeEquation2);
	glClipPlane(GL_CLIP_PLANE3, planeEquation3);

	glScalef(3, 3, 10);
	glColor3f(r, g, b);
	drawCube2(1);
	glDisable(GL_CLIP_PLANE0);
	glDisable(GL_CLIP_PLANE1);
	glDisable(GL_CLIP_PLANE2);

	glPopMatrix();

	glPushMatrix();
	for (float i = 3.75; i > -2.5; i -= 2.5) {
		glPushMatrix();
		glTranslatef(-1.4, 0, i);
		drawBusSideWindow(r, g, b);
		glPopMatrix();
	}
	glPopMatrix();

	glPushMatrix();
	for (float i = 3.75; i > -2.5; i -= 2.5) {
		glPushMatrix();
		glTranslatef(1.4, 0, i);
		drawBusSideWindow(r, g, b);
		glPopMatrix();
	}
	glPopMatrix();
	glDisable(GL_CLIP_PLANE3);
	
	glPopMatrix();

	glPushMatrix();
	glScalef(1.15, 1, 1);
	glTranslatef(0, 0, 4.9);
	glRotatef(90, 0, 1, 0);
	drawBusSideWindow(r, g, b);
	glPopMatrix();

	glPushMatrix();
	drawFrontGlass(r, g, b);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.4, 0, -3.75);
	drawBusdoor(r, g, b);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.4, 0, -3.75);
	drawBusdoor(r, g, b);
	glPopMatrix();

	glPopMatrix();
}

void drawBusFlow() {

	glPushMatrix();
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(1.4, 0, 5);
	glVertex3f(1.4, 0, -5);
	glVertex3f(-1.4, 0, -5);
	glVertex3f(-1.4, 0, 5);
	glEnd();
	glPopMatrix();
}

void drawSeat(){
	glPushMatrix();
	glColor3f(1, 1, 1);
	drawCube2(1);

	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(0, 1, 0.4);
	glScalef(1, 1, 0.2);
	drawCube2(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(0, 1.6, 0.4);
	glScalef(0.5, 0.2, 0.2);
	drawCube2(1);
	glPopMatrix();
	
	glPopMatrix();
}

void drawSeatRow() {
	glPushMatrix();

	glPushMatrix();
	for (float i = 4.5; i >= -2.5; i--) {
		glPushMatrix();
		glTranslatef(0.7, -0.3, i);
		glScalef(0.6, 0.6, 0.6);
		drawSeat();
		glPopMatrix();
	}
	glPopMatrix();

	glPushMatrix();
	for (float i = 4.5; i >= -2.5; i--) {
		glPushMatrix();
		glTranslatef(-0.7, -0.3, i);
		glScalef(0.6, 0.6, 0.6);
		drawSeat();
		glPopMatrix();
	}
	glPopMatrix();

	glPopMatrix();
}

void drawWheel() {
	
	glPushMatrix();

	glPushMatrix();
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
	drawSphere1(1);
	glPopMatrix();
	glDisable(GL_CLIP_PLANE0);
	glDisable(GL_CLIP_PLANE1);

	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glRotatef(90, 0, 1, 0);
	drawCylinder2(0.7, 1);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
}

void drawWhellSet() {
	glPushMatrix();

	glPushMatrix();
	glScalef(0.3, 0.4, 0.4);
	glTranslatef(5, -3.5, 7);
	glRotatef(90, 0, 1, 0);
	drawWheel();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.3, 0.4, 0.4);
	glTranslatef(5, -3.5, -7);
	glRotatef(90, 0, 1, 0);
	drawWheel();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.3, 0.4, 0.4);
	glTranslatef(-5, -3.5, 7);
	glRotatef(90, 0, 1, 0);
	drawWheel();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.3, 0.4, 0.4);
	glTranslatef(-5, -3.5, -7);
	glRotatef(90, 0, 1, 0);
	drawWheel();
	glPopMatrix();

	glPopMatrix();
}

void drawVehicle(int r, int g,int b) {
	glPushMatrix();
	
	glPushMatrix();
	drawSide(r,g,b);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	drawBusFlow();
	glPopMatrix();

	glPushMatrix();
	drawSeatRow();
	glPopMatrix();

	glPushMatrix();
	drawWhellSet();
	glPopMatrix();

	glPopMatrix();
}

void placeBus(int r, int g, int b, int x, int y, int z) {
	
	glPushMatrix();
	glTranslatef(x, y, z);
	drawVehicle(r, g, b);
	glPopMatrix();
}