#include "Header.h"
#include <GL/glut.h>  
#include <math.h>
#define pi 3.142857

void drawCube3(float i) {
	glPushMatrix();
	glutSolidCube(i);
	glPopMatrix();
}

void drawRoadCube(float r,float g,float b) {
	glPushMatrix();
	glColor3f(r, g, b);
	glScalef(1, 0.05, 1);
	drawCube3(1);
	glPopMatrix();
}

void drawFlow(float r, float g, float b, int x, int y) {
	glPushMatrix();
	for (int i = -x / 2; i <= x / 2; i++) {
		for (int j = -y / 2; j <= y / 2; j++) {
			glPushMatrix();
			glTranslatef(i, 0.025, j);
			drawRoadCube(r, g, b);
			glPopMatrix();
		}
	}
	glPopMatrix(); 
}

void drawLine(float r,float g,float b) {
	glPushMatrix();
	glColor3f(1, 1, 0);
	glScalef(0.1, 0.02, 1.2);
	drawCube3(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 1);
	glColor3f(r, g, b);
	glScalef(0.2, 0.2, 0.2);
	glutSolidSphere(1, 100, 100);
	glPopMatrix();
}

void drawRoad(float r,float g,float b,int x,int y) {
	glPushMatrix();

	glPushMatrix();
	for (int i = -x/2; i <= x/2; i++) {
		for (int j = -y/2; j <= y/2; j++) {
			glPushMatrix();
			glTranslatef(i, 0.05, j);
			drawRoadCube(r, g, b);
			glPopMatrix();
		}
	}
	glPopMatrix();

	glPopMatrix();
}

void drawLineAndBulb(float r,float g,float b,int x,int y) {
	glPushMatrix();

	//draw Roads Lines
	glPushMatrix();
	for (float i = -y / 2; i <= y / 2; i += 2) {
		glPushMatrix();
		glTranslatef(x / 2, 0.1, i);
		drawLine(r, g, b);
		glPopMatrix();
	}
	glPopMatrix();

	glPushMatrix();
	for (float i = -y / 2; i <= y / 2; i += 2) {
		glPushMatrix();
		glTranslatef(-x / 2, 0.1, i);
		drawLine(r, g, b);
		glPopMatrix();
	}
	glPopMatrix();

	glPopMatrix();
}


void drawRunaway(float r,float g,float b,int x,int y) {
	glPushMatrix();
	drawRoad(r, g, b, x, y);
	glPopMatrix();
}