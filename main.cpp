/*
Truk Surfers Project
Made by	: 	1. Agung Surya Permana
			2. Muhamad Aditya Yusuf Jatikusumo
			3. Resma Adi Nugroho
			4. Ririn Indah Cahyani
*/

#include <math.h> 
#include <GL/glut.h> 
#include <GL/glu.h>
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

#define PHI 3.14159265358979323846 

float angle=0.0, deltaAngle = 0.0, ratio; 
float x=0.0f,y=1.75f,z=15.0f; // posisi awal kamera 
float lx=0.0f,ly=0.0f,lz=-1.0f; 
int deltaMove = 0,h,w; 
int bitmapHeight=12; 
int screen = 1; // 1 = mainscreen, 2 = gamescreen, 3 = gameover

GLUquadricObj *quadObj; //parameter kuadratik silinder

void Reshape(int w1, int h1) 
{ 
 // Fungsi reshape 
 if(h1 == 0) h1 = 1; 
 w = w1; 
 h = h1; 
 ratio = 1.0f * w / h; 
 glMatrixMode(GL_PROJECTION); 
 glLoadIdentity(); 
 glViewport(0, 0, w, h); 
 gluPerspective(45,ratio,0.1,1000); 
 glMatrixMode(GL_MODELVIEW); 
 glLoadIdentity(); 
 gluLookAt(
 x, y, z, 
 x + lx,y + ly,z + lz, 
 0.0f,1.0f,0.0f); 
} 
void orientMe(float ang) 
{ 
 // Fungsi ini untuk memutar arah kamera (tengok kiri/kanan) 
 lx = sin(ang); 
 lz = -cos(ang); 
 glLoadIdentity(); 
 gluLookAt(x, y, z, 
 x + lx,y + ly,z + lz, 
 0.0f,1.0f,0.0f); 
} 
void moveMeFlat(int i) 
{ 
 // Fungsi ini untuk maju mundur kamera 
 x = x + i*(lx)*0.1; 
 z = z + i*(lz)*0.1; 
 glLoadIdentity();
 gluLookAt(x, y, z, 
 x + lx,y + ly,z + lz, 
 0.0f,1.0f,0.0f); 
} 
void Jalan(){
	glColor3f(1.0,0.75,0.0);
	glBegin(GL_QUADS);
	
	// Kanan
	glPushMatrix();
	glTranslatef(0.0,0.0,0.0);
	glColor3f(0.0,0.7,0.0);
	glVertex3f(-150,-0.1,-100);
	glVertex3f(-150,-0.1,-10.0);
	glVertex3f(150,-0.1,-10.0);
	glVertex3f(150,-0.1,-100);
	
	// Jalan utama
	glColor3f(0.1,0.1,0.1);
	glVertex3f(-150,-0.1,-10.0);
	glVertex3f(-150,-0.1,0.1);
	glVertex3f(150,-0.1,0.1);
	glVertex3f(150,-0.1,-10.0);
	
	glColor3f(0.1,0.1,0.1);
	glVertex3f(-150,-0.1,0.25);
	glVertex3f(-150,-0.1,10.0);
	glVertex3f(150,-0.1,10.0);
	glVertex3f(150,-0.1,0.25);
	
	// Garis Tengah
	glColor3f(1.0,1.0,1.0);
	glVertex3f(-150,-0.1,0.1);
	glVertex3f(-150,-0.1,0.25);
	glVertex3f(150,-0.1,0.25);
	glVertex3f(150,-0.1,0.1);
	
	// Kiri
	glColor3f(0.0,0.7,0.0);
	glVertex3f(-150,-0.1,10.0);
	glVertex3f(-150,-0.1,100);
	glVertex3f(150,-0.1,100);
	glVertex3f(150,-0.1,10.0);
	glPopMatrix();
	
	glEnd();
}
void Pohon(){
	glPushMatrix();
    glRotated(360,0,1,0);
    glTranslatef(0.0,0.0,0.0);
    GLUquadricObj * pObj;
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj,GLU_SMOOTH);
	int ww = 1;
	int qq = 1;
			//batang
            glPushMatrix();
                glColor3ub(122,61,31);
                glRotated(270,1,0,0);
                glTranslatef(-40 + (ww*20),-40+(qq*20),0);
                gluCylinder(pObj,1.5,0.5,8,25,25);
            glPopMatrix();

            //daun
            glPushMatrix();
                glColor3ub(25,148,19);
                glScaled(2,2,2);
                glRotated(90,0,1,0);
                glTranslatef(-20 + (qq*10),6,-10+((ww-1)*10));
                glutSolidDodecahedron();
            glPopMatrix();
            glPushMatrix();
                glColor3ub(18,118,13);
                glScaled(2,2,2);
                glRotated(90,0,1,0);
                glTranslatef(-20 + (qq*10),5,-9+((ww-1)*10));
                glutSolidDodecahedron();
            glPopMatrix();
            glPushMatrix();
                glColor3ub(30,130,25);
                glScaled(2,2,2);
                glRotated(90,0,1,0);
                glTranslatef(-20 + (qq*10),5,-11+((ww-1)*10));
                glutSolidDodecahedron();
            glPopMatrix();
    glPopMatrix();
}
void Truk() 
{ 
	/* KEPALA */
	
	//Alas bawah
	glPushMatrix();
		glRotated(270,1,0,0);
		glTranslatef(0,0,0.5);
		glColor3f(0.937, 0.666, 0.203);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-2.0f,0.0f);
			glVertex3f(4.0f,-2.0f,0.0f);
			glVertex3f(4.0f,2.0f,0.0f);
			glVertex3f(1.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas belakang
	glPushMatrix();
		glRotated(90,0,1,0);
		glTranslatef(-2,2.5,1);
		glBegin(GL_QUADS);
			glVertex3f(0.0f,-2.0f,0.0f);
			glVertex3f(4.0f,-2.0f,0.0f);
			glVertex3f(4.0f,2.0f,0.0f);
			glVertex3f(0.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas atas
	glPushMatrix();
		glRotated(270,1,0,0);
		glTranslatef(0,0,4.5);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-2.0f,0.0f);
			glVertex3f(3.5f,-2.0f,0.0f);
			glVertex3f(3.5f,2.0f,0.0f);
			glVertex3f(1.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas depan
	glPushMatrix();
		glRotated(90,0,1,0);
		glTranslatef(-2,2.5,4);
		glBegin(GL_QUADS);
			glVertex3f(0.0f,-2.0f,0.0f);
			glVertex3f(4.0f,-2.0f,0.0f);
			glVertex3f(4.0f,0.25f,0.0f);
			glVertex3f(0.0f,0.25f,0.0f);
		glEnd();
	glPopMatrix();
	
	// kaca depan
	glPushMatrix();
		glRotated(90,0,1,0);
		glTranslatef(-2,4.75,4);
		glBegin(GL_QUADS);
			glVertex3f(0.0f,-2.0f,0.0f);
			glVertex3f(4.0f,-2.0f,0.0f);
			glVertex3f(4.0f,-0.25f,-0.5f);
			glVertex3f(0.0f,-0.25f,-0.5f);
		glEnd();
	glPopMatrix();
	
	// Alas samping kanan bawah
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,2);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-2.0f,0.0f);
			glVertex3f(4.0f,-2.0f,0.0f);
			glVertex3f(4.0f,0.25f,0.0f);
			glVertex3f(1.0f,0.25f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas samping kanan atas
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,2);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,0.25f,0.0f);
			glVertex3f(4.0f,0.25f,0.0f);
			glVertex3f(3.5f,2.0f,0.0f);
			glVertex3f(1.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas samping kiri bawah
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,-2);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-2.0f,0.0f);
			glVertex3f(4.0f,-2.0f,0.0f);
			glVertex3f(4.0f,0.25f,0.0f);
			glVertex3f(1.0f,0.25f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas samping kiri atas
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,-2);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,0.25f,0.0f);
			glVertex3f(4.0f,0.25f,0.0f);
			glVertex3f(3.5f,2.0f,0.0f);
			glVertex3f(1.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Jendela kiri
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,2.001);
		glColor3f(0.5,0.5,0.5);
		glBegin(GL_QUADS);
			glVertex3f(2.0f,0.3f,0.0f);
			glVertex3f(3.75f,0.3f,0.0f);
			glVertex3f(3.365f,1.75f,0.0f);
			glVertex3f(2.0f,1.75f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Tangga
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,2.001);
		glColor3f(0.737, 0.466, 0.003);
		glBegin(GL_QUADS);
			glVertex3f(1.25f,-1.3f,0.0f);
			glVertex3f(1.9f,-1.3f,0.0f);
			glVertex3f(1.9f,1.75f,0.0f);
			glVertex3f(1.25f,1.75f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,2.002);
		glColor3f(0.937, 0.666, 0.203);
		glBegin(GL_QUADS);
			glVertex3f(1.35f,-1.2f,0.0f);
			glVertex3f(1.8f,-1.2f,0.0f);
			glVertex3f(1.8f,-0.73f,0.0f);
			glVertex3f(1.35f,-0.73f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,2.002);
		glColor3f(0.937, 0.666, 0.203);
		glBegin(GL_QUADS);
			glVertex3f(1.35f,-0.63f,0.0f);
			glVertex3f(1.8f,-0.63f,0.0f);
			glVertex3f(1.8f,-0.16f,0.0f);
			glVertex3f(1.35f,-0.16f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,2.002);
		glColor3f(0.937, 0.666, 0.203);
		glBegin(GL_QUADS);
			glVertex3f(1.35f,-0.06f,0.0f);
			glVertex3f(1.8f,-0.06f,0.0f);
			glVertex3f(1.8f,0.41f,0.0f);
			glVertex3f(1.35f,0.41f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,2.002);
		glColor3f(0.937, 0.666, 0.203);
		glBegin(GL_QUADS);
			glVertex3f(1.35f,0.51f,0.0f);
			glVertex3f(1.8f,0.51f,0.0f);
			glVertex3f(1.8f,0.98f,0.0f);
			glVertex3f(1.35f,0.98f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,2.002);
		glColor3f(0.937, 0.666, 0.203);
		glBegin(GL_QUADS);
			glVertex3f(1.35f,1.08f,0.0f);
			glVertex3f(1.8f,1.08f,0.0f);
			glVertex3f(1.8f,1.55f,0.0f);
			glVertex3f(1.35f,1.55f,0.0f);
		glEnd();
	glPopMatrix();
	
	//Pintu kiri
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,2.001);
		glColor3f(0.837, 0.566, 0.103);
		glBegin(GL_QUADS);
			glVertex3f(2.0f,-1.75f,0.0f);
			glVertex3f(3.75f,-1.75f,0.0f);
			glVertex3f(3.75f,0.25f,0.0f);
			glVertex3f(2.0f,0.25f,0.0f);
		glEnd();
	glPopMatrix();
	
	//Pegangan kiri
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,2.003);
		glColor3f(0.5,0.5,0.3);
		glBegin(GL_QUADS);
			glVertex3f(2.1f,-0.35f,0.0f);
			glVertex3f(2.6f,-0.35f,0.0f);
			glVertex3f(2.6f,-0.25f,0.0f);
			glVertex3f(2.1f,-0.25f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,2.002);
		glColor3f(0.5,0.5,0.7);
		glBegin(GL_QUADS);
			glVertex3f(2.15f,-0.4f,0.0f);
			glVertex3f(2.55f,-0.4f,0.0f);
			glVertex3f(2.55f,-0.2f,0.0f);
			glVertex3f(2.15f,-0.2f,0.0f);
		glEnd();
	glPopMatrix();
	
	//Jendela kanan
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,-2.001);
		glColor3f(0.5,0.5,0.5);
		glBegin(GL_QUADS);
			glVertex3f(2.0f,0.3f,0.0f);
			glVertex3f(3.75f,0.3f,0.0f);
			glVertex3f(3.365f,1.75f,0.0f);
			glVertex3f(2.0f,1.75f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Tangga
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,-2.001);
		glColor3f(0.737, 0.466, 0.003);
		glBegin(GL_QUADS);
			glVertex3f(1.25f,-1.3f,0.0f);
			glVertex3f(1.9f,-1.3f,0.0f);
			glVertex3f(1.9f,1.75f,0.0f);
			glVertex3f(1.25f,1.75f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,-2.002);
		glColor3f(0.937, 0.666, 0.203);
		glBegin(GL_QUADS);
			glVertex3f(1.35f,-1.2f,0.0f);
			glVertex3f(1.8f,-1.2f,0.0f);
			glVertex3f(1.8f,-0.73f,0.0f);
			glVertex3f(1.35f,-0.73f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,-2.002);
		glColor3f(0.937, 0.666, 0.203);
		glBegin(GL_QUADS);
			glVertex3f(1.35f,-0.63f,0.0f);
			glVertex3f(1.8f,-0.63f,0.0f);
			glVertex3f(1.8f,-0.16f,0.0f);
			glVertex3f(1.35f,-0.16f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,-2.002);
		glColor3f(0.937, 0.666, 0.203);
		glBegin(GL_QUADS);
			glVertex3f(1.35f,-0.06f,0.0f);
			glVertex3f(1.8f,-0.06f,0.0f);
			glVertex3f(1.8f,0.41f,0.0f);
			glVertex3f(1.35f,0.41f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,-2.002);
		glColor3f(0.937, 0.666, 0.203);
		glBegin(GL_QUADS);
			glVertex3f(1.35f,0.51f,0.0f);
			glVertex3f(1.8f,0.51f,0.0f);
			glVertex3f(1.8f,0.98f,0.0f);
			glVertex3f(1.35f,0.98f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,-2.002);
		glColor3f(0.937, 0.666, 0.203);
		glBegin(GL_QUADS);
			glVertex3f(1.35f,1.08f,0.0f);
			glVertex3f(1.8f,1.08f,0.0f);
			glVertex3f(1.8f,1.55f,0.0f);
			glVertex3f(1.35f,1.55f,0.0f);
		glEnd();
	glPopMatrix();
	
	//Pintu kanan
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,-2.001);
		glColor3f(0.837, 0.566, 0.103);
		glBegin(GL_QUADS);
			glVertex3f(2.0f,-1.75f,0.0f);
			glVertex3f(3.75f,-1.75f,0.0f);
			glVertex3f(3.75f,0.25f,0.0f);
			glVertex3f(2.0f,0.25f,0.0f);
		glEnd();
	glPopMatrix();
	
	//Pegangan kanan
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,-2.003);
		glColor3f(0.5,0.5,0.3);
		glBegin(GL_QUADS);
			glVertex3f(2.1f,-0.35f,0.0f);
			glVertex3f(2.6f,-0.35f,0.0f);
			glVertex3f(2.6f,-0.25f,0.0f);
			glVertex3f(2.1f,-0.25f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,-2.002);
		glColor3f(0.5,0.5,0.7);
		glBegin(GL_QUADS);
			glVertex3f(2.15f,-0.4f,0.0f);
			glVertex3f(2.55f,-0.4f,0.0f);
			glVertex3f(2.55f,-0.2f,0.0f);
			glVertex3f(2.15f,-0.2f,0.0f);
		glEnd();
	glPopMatrix();
	
	//Kaca depan
	glPushMatrix();
		glRotated(90,0,1,0);
		glTranslatef(-2,4.75,4.005);
		glColor3f(0.5,0.5,0.5);
		glBegin(GL_QUADS);
			glVertex3f(0.25f,-2.0f,0.0f);
			glVertex3f(3.75f,-2.0f,0.0f);
			glVertex3f(3.75f,-0.5f,-0.43f);
			glVertex3f(0.25f,-0.5f,-0.43f);
		glEnd();
	glPopMatrix();
	
	//dekor depan
	glPushMatrix();
		glRotated(90,0,1,0);
		glTranslatef(-2,2.5,4.001);
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-1.5f,0.0f);
			glVertex3f(3.0f,-1.5f,0.0f);
			glVertex3f(3.25f,-1.0f,0.0f);
			glVertex3f(0.75f,-1.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(90,0,1,0);
		glTranslatef(-2,2.5,4.001);
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_QUADS);
			glVertex3f(0.75f,-0.9f,0.0f);
			glVertex3f(3.25f,-0.9f,0.0f);
			glVertex3f(3.5f,-0.4f,0.0f);
			glVertex3f(0.5f,-0.4f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(90,0,1,0);
		glTranslatef(-2,2.5,4.002);
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_QUADS);
			glVertex3f(1.7f,-1.2f,0.0f);
			glVertex3f(2.3f,-1.2f,0.0f);
			glVertex3f(2.0f,-0.6f,0.0f);
			glVertex3f(1.7f,-1.2f,0.0f);
		glEnd();
	glPopMatrix();
	
	//Lampu
	glPushMatrix();
		glRotated(90,0,1,0);
		glTranslatef(-2,2.5,4.001);
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_QUADS);
			glVertex3f(0.0f,-1.5f,0.0f);
			glVertex3f(0.8f,-1.5f,0.0f);
			glVertex3f(0.55f,-1.0f,0.0f);
			glVertex3f(0.0f,-1.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(90,0,1,0);
		glTranslatef(-2,2.5,4.002);
		glColor3f(1.0,1.0,0.0);
		glBegin(GL_QUADS);
			glVertex3f(0.3f,-1.5f,0.0f);
			glVertex3f(0.8f,-1.5f,0.0f);
			glVertex3f(0.55f,-1.0f,0.0f);
			glVertex3f(0.3f,-1.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(90,0,1,0);
		glTranslatef(-2,2.5,4.001);
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_QUADS);
			glVertex3f(3.2f,-1.5f,0.0f);
			glVertex3f(4.0f,-1.5f,0.0f);
			glVertex3f(4.0f,-1.0f,0.0f);
			glVertex3f(3.45f,-1.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glPushMatrix();
		glRotated(90,0,1,0);
		glTranslatef(-2,2.5,4.002);
		glColor3f(1.0,1.0,0.0);
		glBegin(GL_QUADS);
			glVertex3f(3.2f,-1.5f,0.0f);
			glVertex3f(3.7f,-1.5f,0.0f);
			glVertex3f(3.7f,-1.0f,0.0f);
			glVertex3f(3.45f,-1.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	/*Muatan Depan*/
	
	/*Alas muatan depan*/
	
	//Alas bawah
	glPushMatrix();
		glRotated(270,1,0,0);
		glTranslatef(0,0,0.5);
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-2.0f,0.0f);
			glVertex3f(-7.0f,-2.0f,0.0f);
			glVertex3f(-7.0f,2.0f,0.0f);
			glVertex3f(1.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	//Alas atas
	glPushMatrix();
		glRotated(270,1,0,0);
		glTranslatef(0,0,1.0);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-2.0f,0.0f);
			glVertex3f(-7.0f,-2.0f,0.0f);
			glVertex3f(-7.0f,2.0f,0.0f);
			glVertex3f(1.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	//Alas kanan
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,2);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-2.0f,0.0f);
			glVertex3f(-7.0f,-2.0f,0.0f);
			glVertex3f(-7.0f,-1.5f,0.0f);
			glVertex3f(1.0f,-1.5f,0.0f);
		glEnd();
	glPopMatrix();
	
	//Alas kiri
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,-2);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-2.0f,0.0f);
			glVertex3f(-7.0f,-2.0f,0.0f);
			glVertex3f(-7.0f,-1.5f,0.0f);
			glVertex3f(1.0f,-1.5f,0.0f);
		glEnd();
	glPopMatrix();
	
	//Alas belakang
	glPushMatrix();
		glRotated(90,0,1,0);
		glTranslatef(-2,2.5,-7);
		glBegin(GL_QUADS);
			glVertex3f(0.0f,-2.0f,0.0f);
			glVertex3f(4.0f,-2.0f,0.0f);
			glVertex3f(4.0f,-1.5f,0.0f);
			glVertex3f(0.0f,-1.5f,0.0f);
		glEnd();
	glPopMatrix();
	
	/* Muatan depan */
	
	//Alas bawah
	glPushMatrix();
		glRotated(270,1,0,0);
		glTranslatef(0,0,1.0);
		glColor3f(0.937, 0.666, 0.203);
		glBegin(GL_QUADS);
			glVertex3f(0.75f,-2.0f,0.0f);
			glVertex3f(-7.5f,-2.0f,0.0f);
			glVertex3f(-7.5f,2.0f,0.0f);
			glVertex3f(0.75f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	//Alas atas
	glPushMatrix();
		glRotated(270,1,0,0);
		glTranslatef(0,0,5.5);
		glBegin(GL_QUADS);
			glVertex3f(0.75f,-2.0f,0.0f);
			glVertex3f(-7.5f,-2.0f,0.0f);
			glVertex3f(-7.5f,2.0f,0.0f);
			glVertex3f(0.75f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	//Alas kanan
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,2);
		glBegin(GL_QUADS);
			glVertex3f(0.75f,-1.5f,0.0f);
			glVertex3f(-7.5f,-1.5f,0.0f);
			glVertex3f(-7.5f,3.0f,0.0f);
			glVertex3f(0.75f,3.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,2.01);
		glColor3f(0.737, 0.466, 0.003);
		glBegin(GL_QUADS);
			glVertex3f(0.45f,-1.5f,0.0f);
			glVertex3f(0.75f,-1.5f,0.0f);
			glVertex3f(0.7f,3.0f,0.0f);
			glVertex3f(0.45f,3.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,2.01);
		glColor3f(0.737, 0.466, 0.003);
		glBegin(GL_QUADS);
			glVertex3f(-7.2f,-1.5f,0.0f);
			glVertex3f(-7.5f,-1.5f,0.0f);
			glVertex3f(-7.5f,3.0f,0.0f);
			glVertex3f(-7.2f,3.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	//Alas kiri
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,-2);
		glBegin(GL_QUADS);
			glVertex3f(0.75f,-1.5f,0.0f);
			glVertex3f(-7.5f,-1.5f,0.0f);
			glVertex3f(-7.5f,3.0f,0.0f);
			glVertex3f(0.75f,3.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,-2.01);
		glColor3f(0.737, 0.466, 0.003);
		glBegin(GL_QUADS);
			glVertex3f(0.45f,-1.5f,0.0f);
			glVertex3f(0.75f,-1.5f,0.0f);
			glVertex3f(0.7f,3.0f,0.0f);
			glVertex3f(0.45f,3.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,-2.01);
		glColor3f(0.737, 0.466, 0.003);
		glBegin(GL_QUADS);
			glVertex3f(-7.2f,-1.5f,0.0f);
			glVertex3f(-7.5f,-1.5f,0.0f);
			glVertex3f(-7.5f,3.0f,0.0f);
			glVertex3f(-7.2f,3.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	//Alas belakang
	glPushMatrix();
		glRotated(90,0,1,0);
		glTranslatef(-2,2.5,-7.5);
		glColor3f(0.937, 0.666, 0.203);
		glBegin(GL_QUADS);
			glVertex3f(0.0f,-1.5f,0.0f);
			glVertex3f(4.0f,-1.5f,0.0f);
			glVertex3f(4.0f,3.0f,0.0f);
			glVertex3f(0.0f,3.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	//Alas depan
	glPushMatrix();
		glRotated(90,0,1,0);
		glTranslatef(-2,2.5,0.75);
		glColor3f(0.937, 0.666, 0.203);
		glBegin(GL_QUADS);
			glVertex3f(0.0f,-1.5f,0.0f);
			glVertex3f(4.0f,-1.5f,0.0f);
			glVertex3f(4.0f,3.0f,0.0f);
			glVertex3f(0.0f,3.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	//Dekor belakang
	glPushMatrix();
		glRotated(90,0,1,0);
		glTranslatef(-2,2.5,-7.501);
		glColor3f(0.737, 0.466, 0.003);
		glBegin(GL_QUADS);
			glVertex3f(0.1f,-1.5f,0.0f);
			glVertex3f(0.2f,-1.5f,0.0f);
			glVertex3f(0.2f,3.0f,0.0f);
			glVertex3f(0.1f,3.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(90,0,1,0);
		glTranslatef(-2,2.5,-7.502);
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_QUADS);
			glVertex3f(4.0f,0.1f,0.0f);
			glVertex3f(3.75f,0.1f,0.0f);
			glVertex3f(3.75f,0.3f,0.0f);
			glVertex3f(4.0f,0.3f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(90,0,1,0);
		glTranslatef(-2,2.5,-7.502);
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_QUADS);
			glVertex3f(4.0f,1.2f,0.0f);
			glVertex3f(3.75f,1.2f,0.0f);
			glVertex3f(3.75f,1.4f,0.0f);
			glVertex3f(4.0f,1.4f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(90,0,1,0);
		glTranslatef(-2,2.5,-7.502);
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_QUADS);
			glVertex3f(4.0f,2.3f,0.0f);
			glVertex3f(3.75f,2.3f,0.0f);
			glVertex3f(3.75f,2.5f,0.0f);
			glVertex3f(4.0f,2.5f,0.0f);
		glEnd();
	glPopMatrix();
	
	/* Muatan belakang */
	
	/*Alas muatan depan*/
	
	//Alas bawah
	glPushMatrix();
		glRotated(270,1,0,0);
		glTranslatef(-10,0,0.5);
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-2.0f,0.0f);
			glVertex3f(-7.0f,-2.0f,0.0f);
			glVertex3f(-7.0f,2.0f,0.0f);
			glVertex3f(1.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	//Alas atas
	glPushMatrix();
		glRotated(270,1,0,0);
		glTranslatef(-10,0,1.0);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-2.0f,0.0f);
			glVertex3f(-7.0f,-2.0f,0.0f);
			glVertex3f(-7.0f,2.0f,0.0f);
			glVertex3f(1.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	//Alas kanan
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(-10,2.5,2);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-2.0f,0.0f);
			glVertex3f(-7.0f,-2.0f,0.0f);
			glVertex3f(-7.0f,-1.5f,0.0f);
			glVertex3f(1.0f,-1.5f,0.0f);
		glEnd();
	glPopMatrix();
	
	//Alas kiri
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(-10,2.5,-2);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-2.0f,0.0f);
			glVertex3f(-7.0f,-2.0f,0.0f);
			glVertex3f(-7.0f,-1.5f,0.0f);
			glVertex3f(1.0f,-1.5f,0.0f);
		glEnd();
	glPopMatrix();
	
	//Alas belakang
	glPushMatrix();
		glRotated(90,0,1,0);
		glTranslatef(-2,2.5,-17);
		glBegin(GL_QUADS);
			glVertex3f(0.0f,-2.0f,0.0f);
			glVertex3f(4.0f,-2.0f,0.0f);
			glVertex3f(4.0f,-1.5f,0.0f);
			glVertex3f(0.0f,-1.5f,0.0f);
		glEnd();
	glPopMatrix();
	
	
	/*Container*/
	
	//Alas bawah
	glPushMatrix();
		glRotated(270,1,0,0);
		glTranslatef(-10,0,1.0);
		glColor3f(0.937, 0.666, 0.203);
		glBegin(GL_QUADS);
			glVertex3f(0.75f,-2.0f,0.0f);
			glVertex3f(-7.5f,-2.0f,0.0f);
			glVertex3f(-7.5f,2.0f,0.0f);
			glVertex3f(0.75f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	//Alas atas
	glPushMatrix();
		glRotated(270,1,0,0);
		glTranslatef(-10,0,5.5);
		glBegin(GL_QUADS);
			glVertex3f(0.75f,-2.0f,0.0f);
			glVertex3f(-7.5f,-2.0f,0.0f);
			glVertex3f(-7.5f,2.0f,0.0f);
			glVertex3f(0.75f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	//Alas kanan
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(-10,2.5,2);
		glBegin(GL_QUADS);
			glVertex3f(0.75f,-1.5f,0.0f);
			glVertex3f(-7.5f,-1.5f,0.0f);
			glVertex3f(-7.5f,3.0f,0.0f);
			glVertex3f(0.75f,3.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,2.01);
		glColor3f(0.737, 0.466, 0.003);
		glBegin(GL_QUADS);
			glVertex3f(0.45f,-1.5f,0.0f);
			glVertex3f(0.75f,-1.5f,0.0f);
			glVertex3f(0.7f,3.0f,0.0f);
			glVertex3f(0.45f,3.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,2.01);
		glColor3f(0.737, 0.466, 0.003);
		glBegin(GL_QUADS);
			glVertex3f(-7.2f,-1.5f,0.0f);
			glVertex3f(-7.5f,-1.5f,0.0f);
			glVertex3f(-7.5f,3.0f,0.0f);
			glVertex3f(-7.2f,3.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	//Alas kiri
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(-10,2.5,-2);
		glBegin(GL_QUADS);
			glVertex3f(0.75f,-1.5f,0.0f);
			glVertex3f(-7.5f,-1.5f,0.0f);
			glVertex3f(-7.5f,3.0f,0.0f);
			glVertex3f(0.75f,3.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,-2.01);
		glColor3f(0.737, 0.466, 0.003);
		glBegin(GL_QUADS);
			glVertex3f(0.45f,-1.5f,0.0f);
			glVertex3f(0.75f,-1.5f,0.0f);
			glVertex3f(0.7f,3.0f,0.0f);
			glVertex3f(0.45f,3.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,-2.01);
		glColor3f(0.737, 0.466, 0.003);
		glBegin(GL_QUADS);
			glVertex3f(-7.2f,-1.5f,0.0f);
			glVertex3f(-7.5f,-1.5f,0.0f);
			glVertex3f(-7.5f,3.0f,0.0f);
			glVertex3f(-7.2f,3.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	//Alas belakang
	glPushMatrix();
		glRotated(90,0,1,0);
		glTranslatef(-2,2.5,-17.5);
		glColor3f(0.937, 0.666, 0.203);
		glBegin(GL_QUADS);
			glVertex3f(0.0f,-1.5f,0.0f);
			glVertex3f(4.0f,-1.5f,0.0f);
			glVertex3f(4.0f,3.0f,0.0f);
			glVertex3f(0.0f,3.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	//Alas depan
	glPushMatrix();
		glRotated(90,0,1,0);
		glTranslatef(-2,2.5,-9.25);
		glColor3f(0.937, 0.666, 0.203);
		glBegin(GL_QUADS);
			glVertex3f(0.0f,-1.5f,0.0f);
			glVertex3f(4.0f,-1.5f,0.0f);
			glVertex3f(4.0f,3.0f,0.0f);
			glVertex3f(0.0f,3.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	//Dekor belakang
	glPushMatrix();
		glRotated(90,0,1,0);
		glTranslatef(-2,2.5,-17.501);
		glColor3f(0.0,0.3,0.0);
		glBegin(GL_QUADS);
			glVertex3f(0.1f,-1.5f,0.0f);
			glVertex3f(0.2f,-1.5f,0.0f);
			glVertex3f(0.2f,3.0f,0.0f);
			glVertex3f(0.1f,3.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(90,0,1,0);
		glTranslatef(-2,2.5,-17.502);
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_QUADS);
			glVertex3f(4.0f,0.1f,0.0f);
			glVertex3f(3.75f,0.1f,0.0f);
			glVertex3f(3.75f,0.3f,0.0f);
			glVertex3f(4.0f,0.3f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(90,0,1,0);
		glTranslatef(-2,2.5,-17.502);
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_QUADS);
			glVertex3f(4.0f,1.2f,0.0f);
			glVertex3f(3.75f,1.2f,0.0f);
			glVertex3f(3.75f,1.4f,0.0f);
			glVertex3f(4.0f,1.4f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(90,0,1,0);
		glTranslatef(-2,2.5,-17.502);
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_QUADS);
			glVertex3f(4.0f,2.3f,0.0f);
			glVertex3f(3.75f,2.3f,0.0f);
			glVertex3f(3.75f,2.5f,0.0f);
			glVertex3f(4.0f,2.5f,0.0f);
		glEnd();
	glPopMatrix();
	
	/* Sambungan muatan */
	
	//Alas bawah
	glPushMatrix();
		glRotated(270,1,0,0);
		glTranslatef(-8.0,0,0.6);
		glColor3f(0.1,0.1,0.1);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-0.5f,0.0f);
			glVertex3f(-1.0f,-0.5f,0.0f);
			glVertex3f(-1.0f,0.5f,0.0f);
			glVertex3f(1.0f,0.5f,0.0f);
		glEnd();
	glPopMatrix();
	
	//Alas atas
	glPushMatrix();
		glRotated(270,1,0,0);
		glTranslatef(-8.0,0,0.9);
		glColor3f(0.1,0.1,0.1);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-0.5f,0.0f);
			glVertex3f(-1.0f,-0.5f,0.0f);
			glVertex3f(-1.0f,0.5f,0.0f);
			glVertex3f(1.0f,0.5f,0.0f);
		glEnd();
	glPopMatrix();
	
	//Alas kanan
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(-8.0,0.8,0.5);
		glColor3f(0.1,0.1,0.1);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-0.2f,0.0f);
			glVertex3f(-1.0f,-0.2f,0.0f);
			glVertex3f(-1.0f,0.1f,0.0f);
			glVertex3f(1.0f,0.1f,0.0f);
		glEnd();
	glPopMatrix();
	
	//Alas kiri
	glPushMatrix();
		glRotated(0,0,1,0);
		glTranslatef(-8.0,0.8,-0.5);
		glColor3f(0.1,0.1,0.1);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-0.2f,0.0f);
			glVertex3f(-1.0f,-0.2f,0.0f);
			glVertex3f(-1.0f,0.1f,0.0f);
			glVertex3f(1.0f,0.1f,0.0f);
		glEnd();
	glPopMatrix();
	
	/* Roda Truk */
	// Roda depan
	glColor3f(0.0,0.0,0.0);
	glPushMatrix();
		glTranslatef(2.0,0.5,2);
		glutSolidTorus(0.4, 0.5, 100, 100);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(2.0,0.5,-2);
		glutSolidTorus(0.4, 0.5, 100, 100);
	glPopMatrix();
	
	// Roda Tengah
	glColor3f(0.0,0.0,0.0);
	glPushMatrix();
		glTranslatef(-4.5,0.5,2);
		glutSolidTorus(0.4, 0.5, 100, 100);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-6.5,0.5,2);
		glutSolidTorus(0.4, 0.5, 100, 100);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-4.5,0.5,-2);
		glutSolidTorus(0.4, 0.5, 100, 100);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-6.5,0.5,-2);
		glutSolidTorus(0.4, 0.5, 100, 100);
	glPopMatrix();
	
	// Roda Tengah 2
	glColor3f(0.0,0.0,0.0);
	glPushMatrix();
		glTranslatef(-10.5,0.5,2);
		glutSolidTorus(0.4, 0.5, 100, 100);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-12.5,0.5,2);
		glutSolidTorus(0.4, 0.5, 100, 100);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-10.5,0.5,-2);
		glutSolidTorus(0.4, 0.5, 100, 100);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-12.5,0.5,-2);
		glutSolidTorus(0.4, 0.5, 100, 100);
	glPopMatrix();
	
	// Roda Belakang 
	glColor3f(0.0,0.0,0.0);
	glPushMatrix();
		glTranslatef(-16.5,0.5,2);
		glutSolidTorus(0.4, 0.5, 100, 100);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-16.5,0.5,-2);
		glutSolidTorus(0.4, 0.5, 100, 100);
	glPopMatrix();
	
} 

void Awan(){
    glPushMatrix();
    glRotated(360,0,1,0);
    glTranslatef(0,0,0);
    GLUquadricObj * pObj;
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj,GLU_SMOOTH);
    
	    glPushMatrix();
	    	// awan 1
		    glTranslatef(10,15,25);
		    glPushMatrix();
		                glColor3ub(252, 253, 253);
		                glScaled(2,2,2);
		                glTranslatef(-10,6,0);
		                glutSolidDodecahedron();
		            glPopMatrix();
		            glPushMatrix();
		                glColor3ub(232, 241, 242);
		                glScaled(2,2,2);
		                glTranslatef(-10,5,1);
		                glutSolidDodecahedron();
		            glPopMatrix();
		            glPushMatrix();
		                glColor3ub(235, 244, 243);
		                glScaled(2,2,2);
		                glTranslatef(-10,5,-1);
		                glutSolidDodecahedron();
		            glPopMatrix();
		    glPopMatrix();
		    
		    glTranslatef(-45,13,-45);
		    glPushMatrix();
		                glColor3ub(252, 253, 253);
		                glScaled(2,2,2);
		                glTranslatef(-10,6,0);
		                glutSolidDodecahedron();
		            glPopMatrix();
		            glPushMatrix();
		                glColor3ub(232, 241, 242);
		                glScaled(2,2,2);
		                glTranslatef(-10,5,1);
		                glutSolidDodecahedron();
		            glPopMatrix();
		            glPushMatrix();
		                glColor3ub(235, 244, 243);
		                glScaled(2,2,2);
		                glTranslatef(-10,5,-1);
		                glutSolidDodecahedron();
		            glPopMatrix();
		    glPopMatrix();
			
			glTranslatef(35,10,-35);
		    glPushMatrix();
		                glColor3ub(252, 253, 253);
		                glScaled(2,2,2);
		                glTranslatef(-10,6,0);
		                glutSolidDodecahedron();
		            glPopMatrix();
		            glPushMatrix();
		                glColor3ub(232, 241, 242);
		                glScaled(2,2,2);
		                glTranslatef(-10,5,1);
		                glutSolidDodecahedron();
		            glPopMatrix();
		            glPushMatrix();
		                glColor3ub(235, 244, 243);
		                glScaled(2,2,2);
		                glTranslatef(-10,5,-1);
		                glutSolidDodecahedron();
		            glPopMatrix();
		    // awan 1 
		            
		    // awan 2        
		    glTranslatef(15,10,30);
		    glPushMatrix();
		                glColor3ub(252, 253, 253);
		                glScaled(2,2,2);
		                glTranslatef(-10,6,0);
		                glutSolidDodecahedron();
		            glPopMatrix();
		            glPushMatrix();
		                glColor3ub(252, 253, 253);
		                glScaled(2,2,2);
		                glTranslatef(-10,6,2);
		                glutSolidDodecahedron();
		            glPopMatrix();
		            glPushMatrix();
		                glColor3ub(232, 241, 242);
		                glScaled(2,2,2);
		                glTranslatef(-10,5,1);
		                glutSolidDodecahedron();
		            glPopMatrix();
		            glPushMatrix();
		                glColor3ub(235, 244, 243);
		                glScaled(2,2,2);
		                glTranslatef(-10,5,-1);
		                glutSolidDodecahedron();
		            glPopMatrix();
		            glPushMatrix();
		                glColor3ub(235, 244, 243);
		                glScaled(2,2,2);
		                glTranslatef(-10,5,3);
		                glutSolidDodecahedron();
		            glPopMatrix();
		            
		    glTranslatef(-85,-5,20);
		    glPushMatrix();
		                glColor3ub(252, 253, 253);
		                glScaled(2,2,2);
		                glTranslatef(-10,6,0);
		                glutSolidDodecahedron();
		            glPopMatrix();
		            glPushMatrix();
		                glColor3ub(252, 253, 253);
		                glScaled(2,2,2);
		                glTranslatef(-10,6,2);
		                glutSolidDodecahedron();
		            glPopMatrix();
		            glPushMatrix();
		                glColor3ub(232, 241, 242);
		                glScaled(2,2,2);
		                glTranslatef(-10,5,1);
		                glutSolidDodecahedron();
		            glPopMatrix();
		            glPushMatrix();
		                glColor3ub(235, 244, 243);
		                glScaled(2,2,2);
		                glTranslatef(-10,5,-1);
		                glutSolidDodecahedron();
		            glPopMatrix();
		            glPushMatrix();
		                glColor3ub(235, 244, 243);
		                glScaled(2,2,2);
		                glTranslatef(-10,5,3);
		                glutSolidDodecahedron();
		            glPopMatrix();
		    // awan 2
		glPopMatrix();
			       
    glPopMatrix();
}


void Home(){ // homescreen atau tampilan awal game
	// masukan kode menunya disini
}

void GameOver(){
	// masukan kode game overnya disini
}

void display() { 
 // Kalau move dan angle tidak nol, gerakkan kamera... 
 if (deltaMove) 
 moveMeFlat(deltaMove); 
 if (deltaAngle) { 
 angle += deltaAngle; 
 orientMe(angle); 
 } 
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
 if(screen == 2) { // screen 2 = gamescreen
 	Jalan();
 	Truk(); 
 	Awan();
 	Pohon();
 } else if (screen == 1) { // screen 1 = homescreen
 	Home();
 } else { // screen 3 = gameover
 	GameOver();
 }
 
 glutSwapBuffers(); 
 glFlush(); 
} 
void pressKey(int key, int x, int y) { 
 // Fungsi ini akan dijalankan saat tombol keyboard ditekan dan 
 // Selama tombol ditekan, variabel angle dan move diubah => kamera 
 if(screen == 2){
 	switch (key) { 
 	case GLUT_KEY_LEFT : deltaAngle = -0.05f;break; 
 	case GLUT_KEY_RIGHT : deltaAngle = 0.05f;break; 
 	case GLUT_KEY_UP : deltaMove = 2;break; 
 	case GLUT_KEY_DOWN : deltaMove = -2;break; 
	} 
 } 
} 
void keyboard(unsigned char key, int x, int y) {
	if(screen == 1){
		switch(key){
			case ' ': // tekan spacebar untuk memulai
				screen = 2;
				break;
		}
	} else { // fungsi keyboard ketika berada di gamescreen
		
	}
}
void releaseKey(int key, int x, int y) { 
 // Fungsi ini akan dijalankan saat tekanan tombol keyboard dilepas 
 // Saat tombol dilepas, variabel angle dan move diset nol =>
 if(screen = 2){
 	switch (key) { 
	 case GLUT_KEY_LEFT : 
	 if (deltaAngle < 0.0f) 
	 deltaAngle = 0.0f; 
	 break; 
	 case GLUT_KEY_RIGHT : if (deltaAngle > 0.0f) 
	 deltaAngle = 0.0f; 
	 break; 
	 case GLUT_KEY_UP : if (deltaMove > 0) 
	 deltaMove = 0; 
	 break; 
	 case GLUT_KEY_DOWN : if (deltaMove < 0) 
	 deltaMove = 0; 
	 break; 
	 } 
 }
} 
// Variable untuk pencahayaan 
const GLfloat light_ambient[] = { 0.5f, 0.5f, 0.5f, 0.0f }; 
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f }; 
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; 
const GLfloat light_position[] = { 0.0f, 20.0f, 10.0f, 1.0f }; 
const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f }; 
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f }; 
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; 
const GLfloat high_shininess[] = { 100.0f }; 
void lighting(){ 
 // Fungsi mengaktifkan pencahayaan 
 glEnable(GL_DEPTH_TEST); 
 glDepthFunc(GL_LESS); 
 glEnable(GL_LIGHT0); 
 glEnable(GL_NORMALIZE); 
 glEnable(GL_COLOR_MATERIAL); 
 glEnable(GL_LIGHTING); 
 glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient); 
 glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse); 
 glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular); 
 glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
 glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient); 
 glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse); 
 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular); 
 glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess); 
} 
void init(void) 
{ 
 glEnable (GL_DEPTH_TEST); 
 glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); 
} 
int main(int argc, char **argv) 
{ 
 glutInit(&argc, argv); 
 glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA); 
 glutInitWindowPosition(100,100); 
 glutInitWindowSize(640,480); 
 glutCreateWindow("Truk Surfers"); 
 glutIgnoreKeyRepeat(1); // Mengabaikan key repeat (saat tombol ditekan terus menerus)
 glutSpecialFunc(pressKey);
 glutSpecialUpFunc(releaseKey); 
 glutKeyboardFunc(keyboard);
 glutDisplayFunc(display); 
 glClearColor(0.619f, 0.886f, 1.0f, 0.0f);
 glutIdleFunc(display); // Fungsi display-nya dipanggil terusmenerus 
 glutReshapeFunc(Reshape); 
 lighting(); 
 init(); 
 glutMainLoop(); 
 return(0); 
}



