#include "Header.h"
#include <GL/glut.h>  
#include <math.h>
#define pi 3.142857

void drawCircle1(double radius) {
	int d;
	glBegin(GL_POLYGON);
	for (d = 0; d < 32; d++) {
		double angle = 2 * pi / 32 * d;
		glVertex2d(radius * cos(angle), radius * sin(angle));
	}
	glEnd();
}

void drawCylinder1(float r, float h) {
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(0, 0, -h / 2);
	glPushMatrix();
	GLUquadricObj* qaudratic;
	qaudratic = gluNewQuadric();
	gluCylinder(qaudratic, r, r, h, 100, 100);
	drawCircle1(r);
	glTranslatef(0, 0, h);
	drawCircle1(r);
	glPopMatrix();
	glPopMatrix();

}

void drawsphere(double r) {
	glPushMatrix();
	glColor3f(1, 1, 0);
	glutSolidSphere(r, 100, 100);
	glPopMatrix();
}

void drawHarfGoal() {

	glPushMatrix();
	glEnable(GL_CLIP_PLANE1);
	double planeEquation1[] = { 0.0, 1.0, 0.0, 0.0 };
	glClipPlane(GL_CLIP_PLANE1, planeEquation1);

	drawsphere(3);
	glDisable(GL_CLIP_PLANE1);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	drawCircle1(3);
	glPopMatrix();
}

void drawCube1(double i) {
	glPushMatrix();
	//glColor3f(1, 0, 0);
	glutSolidCube(i);
	glPopMatrix();
}

void drawWindowBar(){
	glPushMatrix();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1, 1, 1, 0.7);

	glPushMatrix();
	glTranslatef(0.3, 1.4, 0);
	glScalef(0.1, 2.8, 0.1);
	drawCube1(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3, 1.3, 1);
	glScalef(0.1, 2.6, 0.1);
	drawCube1(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3, 1.3, -1);
	glScalef(0.1, 2.6, 0.1);
	drawCube1(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3, 1.05, 2);
	glScalef(0.1, 2.1, 0.1);
	drawCube1(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3, 1.05, -2);
	glScalef(0.1, 2.1, 0.1);
	drawCube1(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3, 1, 0);
	glScalef(0.1, 0.1, 5.2);
	drawCube1(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3, 2, 0);
	glScalef(0.1, 0.1, 4.1);
	drawCube1(1);
	glPopMatrix();

	glPopMatrix();
}

void drawRoofBorder() {

	glPushMatrix();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1, 1, 1, 0.7);

	glEnable(GL_CLIP_PLANE0);
	double planeEquation[] = { 0.0, 1.0, 0.0, 0.0 };
	glClipPlane(GL_CLIP_PLANE0, planeEquation);
	
	glTranslatef(0.3, 0, 0);
	glRotatef(90, 0, 1, 0);
	glutSolidTorus(0.1,2.8,100,100);
	glDisable(GL_CLIP_PLANE0);

	glPopMatrix();
}

void drawHarfGoalBuilding() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_CLIP_PLANE0);
	double planeEquation0[] = { 1.0, 0.0, 0.0, 0.0 };
	glClipPlane(GL_CLIP_PLANE0, planeEquation0);
	drawHarfGoal();
	glDisable(GL_CLIP_PLANE0);

	glPushMatrix();
	glEnable(GL_CLIP_PLANE1);
	double planeEquation1[] = { 0.0, 1.0, 0.0, 0.0 };
	glClipPlane(GL_CLIP_PLANE1, planeEquation1);

	glTranslatef(0.3, 0, 0);
	glRotatef(90, 0, 1, 0);
	glColor4f(0, 0, 1,0.5);
	drawCircle1(2.8);
	glDisable(GL_CLIP_PLANE1);
	glPopMatrix();

	drawWindowBar();
	drawRoofBorder();
}

void drawControllRoom() {
	glPushMatrix();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	drawCylinder1(1.2, 8);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(0, 5, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidCone(2, 6, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 5, 0);
	glRotatef(90, 1, 0, 0);
	glColor3f(0, 0, 0);
	glutSolidTorus(0.45, 2, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 6, 0);
	glColor4f(1, 1, 1, 0.5);
	glutSolidSphere(2,100,100);
	glPopMatrix();

	glPopMatrix();
}

void drawBuildingWindowBar() {
	glPushMatrix();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1, 1, 1, 0.7);
	drawCube1(1);
	glPopMatrix();
}

void DrawBuildingBorder() {
	
	glPushMatrix();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(0, 0, 0, 0.7);
	drawCube1(1);

	glPopMatrix();
}

void drawBuilding1() {

	glPushMatrix();
	glTranslatef(1.3, 1, -6);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPushMatrix();
	glEnable(GL_CLIP_PLANE0);
	double planeEquation[] = { 1.0, 0.0, 0.0, 0.9 };
	glClipPlane(GL_CLIP_PLANE0, planeEquation);

	glPushMatrix();
	glColor3f(1, 0, 0);
	glScalef(2, 2, 8);
	drawCube1(1);
	glPopMatrix();
	glDisable(GL_CLIP_PLANE0);

	glPopMatrix();

	glPushMatrix();

	glColor4f(0, 0, 1, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(-0.9, 1, 4);
	glVertex3f(-0.9, -1, 4);
	glVertex3f(-0.9, -1, -4);
	glVertex3f(-0.9, 1, -4);
	glEnd();

	glPopMatrix();

	glPushMatrix();
	for (int i = -3; i < 4; i++) {
		glPushMatrix();
		glTranslatef(-0.9, 0, i);
		glScalef(0.1, 2, 0.1);
		drawBuildingWindowBar();
		glPopMatrix();
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.9, 0, 0);
	glColor4f(1, 1, 1, 0.7);
	glScalef(0.1, 0.1, 8);
	drawCube1(1);
	glPopMatrix();

	glPushMatrix();
	for (int i = -1; i <= 2; i += 2) {
		glPushMatrix();
		glTranslatef(-0.9, i, 0);
		glScalef(0.1, 0.2, 8);
		DrawBuildingBorder();
		glPopMatrix();
	}
	glPopMatrix();

	glPushMatrix();
	for (int i = -4; i <= 9; i += 8) {
		glPushMatrix();
		glTranslatef(-0.9, 0, i);
		glScalef(0.1, 2.2, 0.2);
		DrawBuildingBorder();
		glPopMatrix();
	}
	glPopMatrix();

	glPopMatrix();
}

void drawBuilding2() {
	glPushMatrix();
	glTranslatef(2, 1.5, -4);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPushMatrix();
	glEnable(GL_CLIP_PLANE0);
	double planeEquation[] = { 1.0, 0.0, 0.0, 0.9 };
	glClipPlane(GL_CLIP_PLANE0, planeEquation);

	glColor3f(1, 0, 0);
	glScalef(2, 3, 7);
	drawCube1(1);
	glDisable(GL_CLIP_PLANE0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-0.9, 0.5, 3.5);
	glVertex3f(-0.9, -1.5, 3.5);
	glVertex3f(-0.9, -1.5, -3.5);
	glVertex3f(-0.9, 0.5, -3.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor4f(0, 0, 1, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(-0.9, 1.5, 3.5);
	glVertex3f(-0.9, 0.5, 3.5);
	glVertex3f(-0.9, 0.5, -3.5);
	glVertex3f(-0.9, 1.5, -3.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	for (int i = -3; i <= 3; i++) {
		glPushMatrix();
		glTranslatef(-0.9, 1, i);
		glScalef(0.1, 1, 0.1);
		drawBuildingWindowBar();
		glPopMatrix();
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.9, 1.05, 0);
	glScalef(0.1, 0.1, 7);
	drawBuildingWindowBar();
	glPopMatrix();

	glPushMatrix();
	for (int i = 0.5; i <= 1.5; i += 1) {
		glPushMatrix();
		glTranslatef(-0.9, 0.5+i, 0);
		glScalef(0.1, 0.2, 7);
		DrawBuildingBorder();
		glPopMatrix();
	}
	glPopMatrix();

	glPushMatrix();
	for (int i = -3.5; i <= 8.5; i += 7) {
		glPushMatrix();
		glTranslatef(-0.9, 1, i-0.5);
		glScalef(0.1, 1.2, 0.2);
		DrawBuildingBorder();
		glPopMatrix();
	}
	glPopMatrix();

	glPopMatrix();
}

void drawBuildingSeat() {
	glPushMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	drawCube1(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(0, 1, 0.4);
	glScalef(1, 1, 0.2);
	drawCube1(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(0, 1.6, 0.4);
	glScalef(0.5, 0.2, 0.2);
	drawCube1(1);
	glPopMatrix();

	glPopMatrix();
}

void drawAirPlaneYard() {
	glPushMatrix();
	glEnable(GL_CLIP_PLANE1);
	double planeEquation1[] = { 0.0, 0.0, -1.0, 2.9 };
	glClipPlane(GL_CLIP_PLANE1, planeEquation1);

	glPushMatrix();
	glEnable(GL_CLIP_PLANE0);
	double planeEquation[] = { 0.0, 1.0, 0.0, 0.0 };
	glClipPlane(GL_CLIP_PLANE0, planeEquation);
	
	glPushMatrix();
	drawCylinder1(4, 6);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0, 0, 2.9);
	glutSolidTorus(0.1, 3.9, 100, 100);
	glPopMatrix();

	glDisable(GL_CLIP_PLANE0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex3f(4, 0, 4);
	glVertex3f(4, 0, -3);
	glVertex3f(-4, 0, -3);
	glVertex3f(-4, 0, 4);
	glEnd();
	glPopMatrix();
	glDisable(GL_CLIP_PLANE1);

	glPopMatrix();
}

void drawBuildingSeatRow() {
	glPushMatrix();

	glPushMatrix();
	for (float i = -5; i > -20; i--) {
		glPushMatrix();
		glScalef(0.5, 0.5, 0.5);
		glTranslatef(2, 0.5, i);
		glRotatef(90, 0, 1, 0);
		drawBuildingSeat();
		glPopMatrix();
	}
	glPopMatrix();

	glPushMatrix();
	for (float i = -5; i > -20; i--) {
		glPushMatrix();
		glScalef(0.5, 0.5, 0.5);
		glTranslatef(3.5, 0.5, i);
		glRotatef(90, 0, 1, 0);
		drawBuildingSeat();
		glPopMatrix();
	}
	glPopMatrix();

	glPopMatrix();
}

void drawBuilding3() {

	glPushMatrix();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPushMatrix();
	glEnable(GL_CLIP_PLANE0);
	double planeEquation[] = { 1.0, 0.0, 0.0, 1.4 };
	glClipPlane(GL_CLIP_PLANE0, planeEquation);

	glScalef(3, 4, 8);
	drawCube1(1);
	glDisable(GL_CLIP_PLANE0);

	glPopMatrix();

	glPushMatrix();
	glColor4f(0, 0, 1, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(-1.4, 2, 4);
	glVertex3f(-1.4, -2, 4);
	glVertex3f(-1.4, -2, -4);
	glVertex3f(-1.4, 2, -4);
	glEnd();
	glPopMatrix();

	//window bar
	glPushMatrix();
	for (int i = -3; i <= 3; i++) {
		glPushMatrix();
		glTranslatef(-1.4, 0, i);
		glScalef(0.1, 4, 0.1);
		drawBuildingWindowBar();
		glPopMatrix();
	}
	glPopMatrix();

	//window bar
	glPushMatrix();
	for (int j = -1; j <= 1; j++) {
		glPushMatrix();
		glTranslatef(-1.4, j, 0);
		glScalef(0.1, 0.1, 8);
		drawBuildingWindowBar();
		glPopMatrix();
	}
	glPopMatrix();

	//border
	glPushMatrix();
	for (int i = -4; i <= 4; i += 8) {
		glPushMatrix();
		glTranslatef(-1.4, 0, i);
		glScalef(0.1, 4, 0.2);
		DrawBuildingBorder();
		glPopMatrix();
	}
	glPopMatrix();

	//border
	glPushMatrix();
	for (int j = -2; j <= 2; j += 4) {
		glPushMatrix();
		glTranslatef(-1.4, j, 0);
		glScalef(0.1, 0.2, 8);
		DrawBuildingBorder();
		glPopMatrix();
	}
	glPopMatrix();

	glPopMatrix();
}

void drawA() {
	glPushMatrix();
	glScalef(1, 0.9, 1);
	//letter A
	glPushMatrix();
	glTranslatef(0, 0, -0.5);
	glRotatef(-70, 1, 0, 0);
	drawCylinder1(0.3, 3);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 0.5);
	glRotatef(70, 1, 0, 0);
	drawCylinder1(0.3, 3);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1.2, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.37, 1, 100, 100);
	glPopMatrix();

	glPushMatrix();
	drawCylinder1(0.3, 1);
	glPopMatrix();

	glPopMatrix();
}

void drawI() {

	glPushMatrix();
	//letter I
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	drawCylinder1(0.3, 2.6);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1.3, 0);
	drawCylinder1(0.3, 2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1.3, 0);
	drawCylinder1(0.3, 2);
	glPopMatrix();

	glPopMatrix();
}

void drawR() {

	glPushMatrix();
	//letter R
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	drawCylinder1(0.3, 3);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_CLIP_PLANE0);
	double planeEquation[] = { 1.0, 0.0, 0.0, 0.1 };
	glClipPlane(GL_CLIP_PLANE0, planeEquation);
	glTranslatef(0.5, 0.6, 0);
	glScalef(1, 0.8, 1);
	glutSolidTorus(0.3, 1, 100, 100);
	glDisable(GL_CLIP_PLANE0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, -0.7, 0);
	glRotatef(30, 0, 0, 1);
	glRotatef(90, 1, 0, 0);
	drawCylinder1(0.3, 1.5);
	glPopMatrix();

	glPopMatrix();
}

void drawP() {

	glPushMatrix();
	//letter p
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	drawCylinder1(0.3, 3);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_CLIP_PLANE0);
	double planeEquation[] = { 1.0, 0.0, 0.0, 0.1 };
	glClipPlane(GL_CLIP_PLANE0, planeEquation);
	glTranslatef(0.5, 0.6, 0);
	glScalef(1, 0.8, 1);
	glutSolidTorus(0.3, 1, 100, 100);
	glDisable(GL_CLIP_PLANE0);
	glPopMatrix();

	glPopMatrix();
}

void drawO() {
	glPushMatrix();
	//letter o
	glPushMatrix();
	glScalef(0.8, 1, 1);
	glutSolidTorus(0.3, 1.5, 100, 100);
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
}

void drawT() {
	glPushMatrix();
	//letter T
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	drawCylinder1(0.3, 2.6);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1.3, 0);
	//glRotatef(90, 1, 0, 0);
	drawCylinder1(0.3, 2.5);
	glPopMatrix();

	glPopMatrix();
}

void drawAirport() {

	glPushMatrix();
	//draw AIR PORT
	
	glPushMatrix();
	drawA();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 2.5);
	drawI();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0, 0, 4.2);
	glRotatef(-90, 0, 1, 0);
	drawR();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 8);
	glRotatef(-90, 0, 1, 0);
	drawP();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 11.5);
	glRotatef(-90, 0, 1, 0);
	drawO();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 14);
	glRotatef(-90, 0, 1, 0);
	drawR();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 17.5);
	drawT();
	glPopMatrix();

	glPopMatrix();
}

void drawBuilding() {
	drawHarfGoalBuilding();

	glPushMatrix();
	glTranslatef(0, 2, -3);
	glScalef(0.5, 0.5, 0.5);
	drawControllRoom();
	glPopMatrix();

	glPushMatrix();
	drawBuilding1();
	drawBuilding2();
	glPopMatrix();

	glPushMatrix();
	drawBuildingSeatRow();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3, 2, 5);
	drawBuilding3();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3, 4.5, 3);
	glScalef(0.3, 0.3, 0.3);
	drawAirport();
	glPopMatrix();

}

void placeYard() {
	glPushMatrix();
	//glTranslatef(4, 0, 8);
	//glRotatef(-90, 0, 1, 0);
	drawAirPlaneYard();
	glPopMatrix();
}
