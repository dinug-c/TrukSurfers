int skor = 0;

void gerbangTol(int x ,float *z){
    glPushMatrix();
        // Tol
        glColor3d(1,1,0);
        glTranslated(cubePosX[x],1,*z);
        glScaled(0.5,4,0.5);
        glutSolidCube(1);

        glColor3d(1,0,0);
        glTranslated(2.5,0.45,0);
        glScaled(5,0.15,1.1);
        glutSolidCube(1);
    glPopMatrix();

    //Fungsi mendeteksi poin
    if(cubePosX[x]+tX > -0.2 && cubePosX[x]+tX < 2.2){
        if(*z > 0 && *z < 1){
            skor += 10;
        }
    }
    *z += speed;
    if(*z > 20){
        *z -= 110;
    }
}