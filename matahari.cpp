 int year = 0, day = 0;
void matahari()
{
    glClear (GL_COLOR_BUFFER_BIT);
     glColor3f (1.0, 1.0, 0.0);
     glPushMatrix();
     glutWireSphere(1.0, 40, 16); /* gambar matahari */
     glRotatef ((GLfloat) year, 0.0, 1.0, 0.0);
     glTranslatef (2.0, 0.0, 0.0);
     glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
    
     glColor3f (1.0, 0.4, 0.3);
     glutWireSphere(0.2, 50, 20); /* gambar planet kecil */
    
        glRotated(80.5,9,6,0);
        glutWireTorus(0.3,0.4,1,30);
    glPopMatrix();
        
    /*glPushMatrix();
        glTranslated(0,0,-6);
        glRotated(95.0,12.0,0,0);
        glRotated(a,0,0,1);
        glutWireTorus(5,0,1,50);
    glPopMatrix();*/
    
     glutSwapBuffers();
}
