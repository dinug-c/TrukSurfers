/*
Truk Surfers Project
Made by	: 	1. Agung Surya Permana
			2. Muhamad Aditya Yusuf Jatikusumo
			3. Resma Adi Nugroho
			4. Ririn Indah Cahyani
*/
#include <iostream> 
#include <math.h> 
#include <GL/glut.h> 
#include <GL/glu.h>
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <windows.h>
#include "lib/imageloader.h"
#define EN_SIZE 20
#define PHI 3.14159265358979323846 

float angle=0.0, deltaAngle = 0.0, ratio; 
float x=0.0f,y=20.75f,z=80.0f; // posisi awal kamera 
float tX=0,tY=0,tZ=-8,rX=0,rY=0,rZ=4;
float tZ1=-20,tZ2=-40,tZ3=-60,tZ4=-80,tZ5=-100,tZ6=-120;
float lx=0.0f,ly=0.0f,lz=-1.0f; 
float zoom=4;
float rotX=0,rotY=0,rotZ=0;
float cosX=0,cosY=1,cosZ=0;
float xEye=0.0f,yEye=5.0f,zEye=30.0f;
float cenX=0,cenY=0,cenZ=0,roll=0;
float radius=0;
int tola[5000][5000];
float theta=0,slope=0;
float speed = 0.3;
float angleBackFrac = 0.2;
float r[] = {0.1,0.4,0.0,0.9,0.2,0.5,0.0,0.7,0.5,0.0};
float g[] = {0.2,0.0,0.4,0.5,0.2,0.0,0.3,0.9,0.0,0.2};
float b[] = {0.4,0.5,0.0,0.7,0.9,0.0,0.1,0.2,0.5,0.0};
int TIME=0;
float torusPosX[7] = {1,-2,3,-4,-2,0,2};
float torusPosY[7] = {2,3,10,6,7,4,1};
bool rot = false;
int deltaMove = 0,h,w; 
int bitmapHeight=12; 
int screen = 1; // 1 = mainscreen, 2 = gamescreen, 3 = gameover
GLuint _textureId, _textureId2, _textureId3;          // tekstur 2
;           //ID OpenGL untuk tekstur

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

void singleTolaHouse(int R,int G,int B){
    glColor3d(r[R%11],g[G%11],b[B%11]);
    glPushMatrix();
        glTranslated(0,0,0);
        glutSolidCube(1);
    glPopMatrix();

    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(0.2,0,0);
        glScaled(0.3,0.3,1.001);
        glutSolidCube(1);
    glPopMatrix();

    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(-0.2,0,0);
        glScaled(0.3,0.3,1.001);
        glutSolidCube(1);
    glPopMatrix();

    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(0,0,0.2);
        glScaled(1.001,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(0,0,-0.2);
        glScaled(1.001,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

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
void house(int n,int R,int G){
    for(int i=0;i<n;i++){
        glPushMatrix();
            glTranslated(0,0.8+i,0);
            singleTolaHouse(G,R,i);
        glPopMatrix();
    }
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
void environment(int n){
/// Ground
    glColor3d(0,0.5,0.1);
    glPushMatrix();
        glTranslated(0,0,0);
        glScaled(EN_SIZE*3,0.3,EN_SIZE*3);
        glutSolidCube(1);
    glPopMatrix();


    glColor3d(0,1,0.1);
    glPushMatrix();
        glTranslated(torusPosX[n],torusPosY[n],0);
        glScaled(0.3,0.3,0.3);
        glutSolidTorus(1,3,30,30);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0f,1.0f,1.0f);
    glRotatef(90,0.0f,1.0f,0.0f);
    glScalef(0.4f,0.4f,0.4f);
    glBegin(GL_QUADS);
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
	glEnd();
	glPopMatrix();
	
	Pohon();
	
	
	for(int i=-(EN_SIZE/2)+1;i<(EN_SIZE/2);i+=2){
            for(int j=-(EN_SIZE/2)+1;j<(EN_SIZE/2);j+=2){
                if(tola[i+(EN_SIZE/2)+1][j+(EN_SIZE/2)+1]!=0){
                    glPushMatrix();
                        glTranslated(i,0,j);
                        house(tola[i+(EN_SIZE/2)+1][j+(EN_SIZE/2)+1],i,j);
                        
                    glPopMatrix();
                }else if(i>=-5&&i<=5){}
                else{
                    tola[i+(EN_SIZE/2)+1][j+(EN_SIZE/2)+1]=(rand()%5)+1;
                    glPushMatrix();
                        glTranslated(i,0,j);
                        house(tola[i+(EN_SIZE/2)+1][j+(EN_SIZE/2)+1],i,j);
                        
                    glPopMatrix();
                }
            }
    }
	
	
}


void Truk() 
{ 
	const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t*90.0;
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

	glBindTexture(GL_TEXTURE_2D, _textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); 
		glRotated(0,0,1,0);
		glTranslatef(0,2.5,2);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.75f,-1.5f,0.0f);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-7.5f,-1.5f,0.0f);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-7.5f,3.0f,0.0f);
			glTexCoord2f(0.0f, 1.0f);
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



void drawShohidMinar(){

    glColor3d(0.4,0.2,0.2);
	glPushMatrix();
        glTranslated(0,1.55,0);
        glScaled(2,0.05,1.5);
        glutSolidCube(1);
    glPopMatrix();

    glColor3d(0.4,0.2,0.2);
	glPushMatrix();
        glTranslated(0,1.6,0);
        glScaled(1.9,0.05,1.4);
        glutSolidCube(1);
    glPopMatrix();

    //glColor3d(0.4,0.2,0.2);
    //glColor3d(1,0.8,0.7);
    glColor3d(0.4,0.2,0.2);
	glPushMatrix();
        glTranslated(0,1.65,0);
        glScaled(1.8,0.05,1.3);
        glutSolidCube(1);
    glPopMatrix();

    /// pataton

    glColor3d(1,1,1);
	glPushMatrix();
        glTranslated(0,1.68,-0.4);
        glScaled(0.5,0.02,0.08);
        glutSolidCube(1);
    glPopMatrix();

    /// Piller

	glPushMatrix();
        glTranslated(0,1.99,-0.4);
        glScaled(0.06,0.7,0.04);
        glutSolidCube(1);
    glPopMatrix();

    /// ROD

    glColor3d(0,0,0);

    glPushMatrix();
        glTranslated(0.07,1.99,-0.4);
        glScaled(0.003,0.7,0.003);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0.11,1.99,-0.4);
        glScaled(0.003,0.7,0.003);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0.15,1.99,-0.4);
        glScaled(0.003,0.7,0.003);
        glutSolidCube(1);
    glPopMatrix();

    ///
    glPushMatrix();
    glTranslated(-0.22,0,0);
        glPushMatrix();
            glTranslated(0.07,1.99,-0.4);
            glScaled(0.003,0.7,0.003);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(0.11,1.99,-0.4);
            glScaled(0.003,0.7,0.003);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(0.15,1.99,-0.4);
            glScaled(0.003,0.7,0.003);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();

    ///Horizontal rod
        glPushMatrix();
            glTranslated(2.2,0,-0.1);
            glScaled(4.2,1,1);
                glColor3d(0,0,0);
                glPushMatrix();
                    glTranslated(-0.528,1.85,-0.3);
                    glScaled(0.1,0.003,0.003);
                    glutSolidCube(1);
                glPopMatrix();

                glPushMatrix();
                    glTranslated(-0.528,2.02,-0.3);
                    glScaled(0.1,0.003,0.003);
                    glutSolidCube(1);
                glPopMatrix();

                glPushMatrix();
                    glTranslated(-0.528,2.18,-0.3);
                    glScaled(0.1,0.003,0.003);
                    glutSolidCube(1);
                glPopMatrix();
                glColor3d(1,1,1);
            glPopMatrix();

    /// ROD END

    glColor3d(1,1,1);
    glPushMatrix();
        glTranslated(-0.22,1.99,-0.4);
        glScaled(0.06,0.7,0.04);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0.22,1.99,-0.4);
        glScaled(0.06,0.7,0.04);
        glutSolidCube(1);
    glPopMatrix();

    /// Uporer piller

    glPushMatrix();
        glTranslated(0,0.743,-1.424);
        glRotated(45,1,0,0);

        //glColor3d(1,0,1);
        glPushMatrix();
            glTranslated(0,1.99,-0.4);
            glScaled(0.06,0.3,0.04);
            glutSolidCube(1);
        glPopMatrix();
        //glColor3d(1,1,1);

        glPushMatrix();
            glTranslated(-0.22,1.99,-0.4);
            glScaled(0.06,0.3,0.04);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(0.22,1.99,-0.4);
            glScaled(0.06,0.3,0.04);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(0,2.15,-0.4);
            glScaled(0.5,0.04,0.04);
            glutSolidCube(1);
        glPopMatrix();

        /// ROD

        glColor3d(0,0,0);

        glPushMatrix();
            glTranslated(0.07,1.99,-0.4);
            glScaled(0.003,0.277,0.003);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(0.11,1.99,-0.4);
            glScaled(0.003,0.277,0.003);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(0.15,1.99,-0.4);
            glScaled(0.003,0.277,0.003);
            glutSolidCube(1);
        glPopMatrix();

        ///

        glColor3d(0,0,0);
        glPushMatrix();
        glTranslated(-0.22,0,0);
            glPushMatrix();
                glTranslated(0.07,1.99,-0.4);
                glScaled(0.003,0.277,0.003);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslated(0.11,1.99,-0.4);
                glScaled(0.003,0.277,0.003);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslated(0.15,1.99,-0.4);
                glScaled(0.003,0.277,0.003);
                glutSolidCube(1);
            glPopMatrix();
        glPopMatrix();
        /// ROD END

        ///Horizontal rod
        glPushMatrix();
            glTranslated(2.2,0,-0.1);
            glScaled(4.2,1,1);
                glColor3d(0,0,0);
                glPushMatrix();
                    glTranslated(-0.528,1.85,-0.3);
                    glScaled(0.1,0.003,0.003);
                    glutSolidCube(1);
                glPopMatrix();

                glPushMatrix();
                    glTranslated(-0.528,2,-0.3);
                    glScaled(0.1,0.003,0.003);
                    glutSolidCube(1);
                glPopMatrix();

                glPushMatrix();
                    glTranslated(-0.528,2.15,-0.3);
                    glScaled(0.1,0.003,0.003);
                    glutSolidCube(1);
                glPopMatrix();
                glColor3d(1,1,1);
        glPopMatrix();

    glPopMatrix();


    /// pasher piller left 1
    glColor3d(1,1,1);
    glPushMatrix();
        glTranslated(0.1,0,-0.4);
        glRotated(45,0,1,0);

        glPushMatrix();
            glTranslated(-0.605,1.94,-0.3);
            glScaled(0.045,0.65,0.03);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-0.45,1.94,-0.3);
            glScaled(0.045,0.65,0.03);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-0.528,2.258,-0.3);
            glScaled(0.199,0.04,0.03);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-0.528,1.68,-0.3);
            glScaled(0.199,0.02,0.06);
            glutSolidCube(1);
        glPopMatrix();

        /// ROD
        glColor3d(0,0,0);
        glPushMatrix();
            glTranslated(-0.64,-0.05,0.1);
            glScaled(1,1.02,1);
            glPushMatrix();
                glTranslated(0.078,1.99,-0.4);
                glScaled(0.003,0.56,0.003);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslated(0.11,1.99,-0.4);
                glScaled(0.003,0.56,0.003);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslated(0.145,1.99,-0.4);
                glScaled(0.003,0.56,0.003);
                glutSolidCube(1);
            glPopMatrix();
        glPopMatrix();

        ///
        glColor3d(1,1,1);

        ///Horizontal rod
            glColor3d(0,0,0);
            glPushMatrix();
                glTranslated(-0.528,1.85,-0.3);
                glScaled(0.1,0.003,0.003);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslated(-0.528,2,-0.3);
                glScaled(0.1,0.003,0.003);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslated(-0.528,2.15,-0.3);
                glScaled(0.1,0.003,0.003);
                glutSolidCube(1);
            glPopMatrix();
            glColor3d(1,1,1);
    glPopMatrix();

    /// pasher piller left 2
    glPushMatrix();
        glTranslated(0.65,0,0.3);
        glRotated(-45,0,1,0);

        glPushMatrix();
            glTranslated(-0.605,1.94,-0.3);
            glScaled(0.045,0.65,0.03);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-0.45,1.94,-0.3);
            glScaled(0.045,0.65,0.03);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-0.528,2.258,-0.3);
            glScaled(0.199,0.04,0.03);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-0.528,1.68,-0.3);
            glScaled(0.199,0.02,0.06);
            glutSolidCube(1);
        glPopMatrix();

        ///ROD
        glColor3d(0,0,0);
        glPushMatrix();
        glTranslated(-0.64,-0.05,0.1);
            glScaled(1,1.02,1);
            glPushMatrix();
                glTranslated(0.078,1.99,-0.4);
                glScaled(0.003,0.56,0.003);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslated(0.11,1.99,-0.4);
                glScaled(0.003,0.56,0.003);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslated(0.145,1.99,-0.4);
                glScaled(0.003,0.56,0.003);
                glutSolidCube(1);
            glPopMatrix();
        glPopMatrix();
        glColor3d(1,1,1);
        ///ROD

        ///Horizontal rod
            glColor3d(0,0,0);
            glPushMatrix();
                glTranslated(-0.528,1.85,-0.3);
                glScaled(0.1,0.003,0.003);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslated(-0.528,2,-0.3);
                glScaled(0.1,0.003,0.003);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslated(-0.528,2.15,-0.3);
                glScaled(0.1,0.003,0.003);
                glutSolidCube(1);
            glPopMatrix();
            glColor3d(1,1,1);

    glPopMatrix();


    ///Choto pillers

    glPushMatrix();
        /// pasher piller left 1
        glTranslated(0.06,0,0.14);
        glPushMatrix();

            glTranslated(-0.2,0,-0.31);
            glRotated(45,0,1,0);

            glPushMatrix();
                glTranslated(-0.605,1.88,-0.3);
                glScaled(0.045,0.4,0.03);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslated(-0.45,1.88,-0.3);
                glScaled(0.045,0.4,0.03);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslated(-0.528,2.08,-0.3);
                glScaled(0.2,0.04,0.03);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslated(-0.528,1.68,-0.3);
                glScaled(0.199,0.02,0.06);
                glutSolidCube(1);
            glPopMatrix();

        ///ROD
        glColor3d(0,0,0);
        glPushMatrix();
        glTranslated(-0.641,0.43,0.1);
        glScaled(1,0.73,1);
            glPushMatrix();
                glTranslated(0.078,1.99,-0.4);
                glScaled(0.003,0.56,0.003);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslated(0.11,1.99,-0.4);
                glScaled(0.003,0.56,0.003);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslated(0.145,1.99,-0.4);
                glScaled(0.003,0.56,0.003);
                glutSolidCube(1);
            glPopMatrix();
        glPopMatrix();

        ///Horizontal rod
            glColor3d(0,0,0);
            glPushMatrix();
                glTranslated(-0.528,1.8,-0.3);
                glScaled(0.1,0.003,0.003);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslated(-0.528,1.96,-0.3);
                glScaled(0.1,0.003,0.003);
                glutSolidCube(1);
            glPopMatrix();
            glColor3d(1,1,1);
        ///ROD

        glPopMatrix();

        /// pasher piller left 2
        glPushMatrix();
            glTranslated(0.83,0,0.39);
            glRotated(-45,0,1,0);

            glPushMatrix();
                glTranslated(-0.605,1.88,-0.3);
                glScaled(0.045,0.4,0.03);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslated(-0.45,1.88,-0.3);
                glScaled(0.045,0.4,0.03);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslated(-0.528,2.1,-0.3);
                glScaled(0.199,0.04,0.03);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslated(-0.528,1.68,-0.3);
                glScaled(0.199,0.02,0.06);
                glutSolidCube(1);
            glPopMatrix();


            ///Horizontal rod
            glColor3d(0,0,0);
            glPushMatrix();
                glTranslated(-0.528,1.8,-0.3);
                glScaled(0.1,0.003,0.003);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslated(-0.528,1.96,-0.3);
                glScaled(0.1,0.003,0.003);
                glutSolidCube(1);
            glPopMatrix();
            glColor3d(1,1,1);

            ///ROD
        glColor3d(0,0,0);
        glPushMatrix();
        glTranslated(-0.641,0.43,0.1);
        glScaled(1,0.73,1);
            glPushMatrix();
                glTranslated(0.078,1.99,-0.4);
                glScaled(0.003,0.56,0.003);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslated(0.11,1.99,-0.4);
                glScaled(0.003,0.56,0.003);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslated(0.145,1.99,-0.4);
                glScaled(0.003,0.56,0.003);
                glutSolidCube(1);
            glPopMatrix();
        glPopMatrix();
        glColor3d(1,1,1);
        ///ROD

        glPopMatrix();


    glPopMatrix();

    /// Circle

    glColor3d(1,0,0);
    glPushMatrix();
        glTranslated(0,2.1,-0.44);
        glScaled(0.35,0.35,0.01);
        glutSolidSphere(1,50,50);
    glPopMatrix();

    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(-0.18,1.9,-0.45);
        glScaled(0.01,0.5,0.01);
        glutSolidCube(1);
    glPopMatrix();

    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(0.18,1.9,-0.45);
        glScaled(0.01,0.5,0.01);
        glutSolidCube(1);
    glPopMatrix();


}

void soheedMinarEnv(){
    /// Ground
    glColor3d(0,0.5,0.1);
    glPushMatrix();
        glTranslated(0,0,0);
        glScaled(EN_SIZE*2,0.3,EN_SIZE*2);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-8,-2.7,-5);
        glRotated(65,0,1,0);
        //glRotated(15,0,1,0);
        glScaled(2,2,2);
        drawShohidMinar();
    glPopMatrix();

    glPushMatrix();
        glTranslated(8,-2.7,-5);
        glRotated(-65,0,1,0);
        //glRotated(15,0,1,0);
        glScaled(2,2,2);
        drawShohidMinar();
    glPopMatrix();
}

void draw(){
    double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t*90.0;

    TIME = t;

    ///Plane
    if(rotX>11)rotX=11;
    if(rotX<-11)rotX=-11;
    if(rotZ>10)rotZ=10;
    if(rotZ<-15)rotZ=-15;

    glPushMatrix();
        glTranslated(0,1,0);
        glRotated(90,0,1,0);
        glRotated(5,0,0,1);
        glRotated(rotX,1,0,0);
        glRotated(rotY,0,1,0);
        glRotated(rotZ,0,0,1);

        glScaled(0.4,0.4,0.4);
        glTranslatef(0.0f,0.5f,0.0f);
        Truk();
    glPopMatrix();

    ///Environment
    if(tX>=4.1)tX=4.1;
    if(tX<=-4.1)tX=-4.1;
    if(tY>0.1)tY= 0.1;
    if(tY<-15)tY= -15;

    glPushMatrix();
        glTranslated(tX,tY,tZ);
        environment(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX,tY,tZ1);
        soheedMinarEnv();
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX,tY,tZ2);
        environment(3);
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX,tY,tZ3);
        environment(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX,tY,tZ4);
        environment(5);
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX,tY,tZ5);
        environment(4);
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX,tY,tZ6);
        environment(2);
    glPopMatrix();

    tZ+=speed;
    tZ1+=speed;
    tZ2+=speed;
    tZ3+=speed;
    tZ4+=speed;
    tZ5+=speed;
    tZ6+=speed;

    if(tZ>=20)tZ=-110;
    if(tZ1>=20)tZ1=-110;
    if(tZ2>=20)tZ2=-110;
    if(tZ3>=20)tZ3=-110;
    if(tZ4>=20)tZ4=-110;
    if(tZ5>=20)tZ5=-110;
    if(tZ6>=20)tZ6=-110;

    if(rotX>0)rotX-=angleBackFrac;
    if(rotX<0)rotX+=angleBackFrac;
    if(rotY>0)rotY-=angleBackFrac;
    if(rotY<0)rotY+=angleBackFrac;
    if(rotZ>0)rotZ-=angleBackFrac;
    if(rotZ<0)rotZ+=angleBackFrac;

    speed += 0.0002;
    if(speed>=0.7)speed=0.7;
}


void drawBitmapText(char *str,float x,float y,float z)
{
	char *c;
	glRasterPos3f(x,y+8,z);

	for (c=str; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c);
	}
}

void drawStrokeText(char* str,int x,int y,int z)
{
	  char *c;
	  glPushMatrix();
	  glTranslatef(x, y+8,z);
	  glScalef(0.002f,0.002f,z);

	  for (c=str; *c != '\0'; c++)
	  {
    		glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
	  }
	  glPopMatrix();
}

void drawStrokeText2(char* str,int x,int y,int z)
{
	  char *c;
	  glPushMatrix();
	  glTranslatef(x, y+8,z);
	  glScalef(0.005f,0.005f,z);

	  for (c=str; *c != '\0'; c++)
	  {
    		glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
	  }
	  glPopMatrix();
}
void drawStrokeChar(char c,float x,float y,float z)
{
	  glPushMatrix();
          	glTranslatef(x, y+8,z);
          	glScalef(0.002f,0.002f,z);
          	glutStrokeCharacter(GLUT_STROKE_ROMAN , c);
	  glPopMatrix();
}

void Home(){ // homescreen atau tampilan awal game
	// masukan kode menunya disini
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
		glNormal3f(0.0, 1.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex2f(-1.0f, -1.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex2f(1.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex2f(1.0f, 1.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex2f(-1.0f, 1.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	
	drawStrokeText("Press SPACE to Start",-1,-1,0);
        drawStrokeText2("Truck Surfers",-2,0,0);
	//glutSwapBuffers();
}

void GameOver(){
	// masukan kode game overnya disini
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId3);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
		glNormal3f(0.0, 1.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex2f(-1.0f, -1.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex2f(1.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex2f(1.0f, 1.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex2f(-1.0f, 1.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	//glutSwapBuffers();

}

void display() { 
	const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t*90.0;
    double aa=a;

    if(!rot){
        a=0;
    }

 // Kalau move dan angle tidak nol, gerakkan kamera... 
 if (deltaMove) 
 moveMeFlat(deltaMove); 
 if (deltaAngle) { 
 angle += deltaAngle; 
 orientMe(angle); 
 } 
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
 if(screen == 2) { // screen 2 = gamescreen
  	glPushMatrix();
            glTranslated(0,0,0);
            glScaled(zoom,zoom,zoom);
            glRotated(a,0,1,0);
            draw();
        glPopMatrix();
	
	glPushMatrix();
	 glTranslatef(0,9,-2);
	 glRotated(60,1,0,0);
	 glColorf(1,0.5,0);
	 glScalef(25,0.001,1.5);
	 glutSolidCube(1);
	glPopMatrix();
	
	drawStrokeText("LEFT : A,RIGHT : D",-8,0.9,0);
	
        drawStrokeText("TIME : ",3,0,0);
        int mod,number=0;
        while(TIME){
            mod=TIME%10;
            number=number*10+mod;
            TIME/=10;
        }
        float tmp=0;
        while(number){
            mod=number%10;
            drawStrokeChar(mod+48,4+tmp,0,0);
            number/=10;
            tmp+=0.2;
        }
 } else if (screen == 1) { // screen 1 = homescreen
 	Home();
 } else { // screen 3 = gameover
 	GameOver();
 }
 
 glutSwapBuffers(); 
 glFlush(); 
} 

static void idle(void)
{
    glutPostRedisplay();
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
	float frac = 0.3;
	float rotfrac = 1;
	switch(key)
	{
		case 'a' :
			tY = -frac;
			rotZ += rotfrac;
			break;
		case 'd' :
			tX -= frac;
			rotX += rotfrac*3;
			rotY += rotfrac/2;
			break;
	}
	glutPostRedisplay();	
	
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
const GLfloat light_position[] = { 0.0f, 120.0f, 30.0f, 1.0f }; 
const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f }; 
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f }; 
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; 
const GLfloat high_shininess[] = { 100.0f }; 

//Membuat gambar menjadi tekstur kemudian berikan ID pada tekstur
GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 
	0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
	return textureId;
}

void initRender(){ 
 // Fungsi mengaktifkan pencahayaan dan inisialisasi rendering
 glEnable(GL_DEPTH_TEST); 
 glEnable(GL_TEXTURE_2D);
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
 
 Image* image = loadBMP("img/yae.bmp");
 _textureId = loadTexture(image);
 delete image;
	
Image* image2 = loadBMP("img/start.bmp"); 
_textureId2 = loadTexture(image2);
delete image2;

Image* image3= loadBMP("img/gameover.bmp");
_textureId3= loadTexture(image3);
delete image3;
	
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
 //PlaySound("music/bgm.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP); // Filenya gamuat wokwowok
 glutIgnoreKeyRepeat(1); // Mengabaikan key repeat (saat tombol ditekan terus menerus)
 glutSpecialFunc(pressKey);
 glutSpecialUpFunc(releaseKey); 
 glutKeyboardFunc(keyboard);
 glutDisplayFunc(display); 
 glClearColor(0.619f, 0.886f, 1.0f, 0.0f);
 glutIdleFunc(display); // Fungsi display-nya dipanggil terusmenerus 
 glutReshapeFunc(Reshape); 
 initRender(); 
 init(); 
 glutMainLoop(); 
 return(0); 
}
