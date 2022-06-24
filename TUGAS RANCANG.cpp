#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;

#define FPS 120
#define TO_RADIANS 3.14/180.0

//  Anggota Kelompok 5
//  Jordan Briandika (672020040)
//  Refli Bob Sippan (672020076)
//  Santika Widyaningtyas (672020155)
//  Ramadhandi Leksono (672020315)


const int width = 1280;
const int height = 720;
int i;
float sudut;
double x_geser, y_geser, z_geser;

float pitch = 0.0, yaw = 0.0;
float camX = 0.0, camZ = 0.0, terbang = 25.0;

void display();
void reshape(int w, int h);
void timer(int);
void passive_motion(int, int);
void camera();
void keyboard(unsigned char key, int x, int y);
void keyboard_up(unsigned char key, int x, int y);

struct Motion{
    bool Forward, Backward, Left, Right, Naik, Turun;
};
Motion motion = { false,false,false,false,false,false };

void init(){
    glClearColor(0.529, 0.807, 0.921, 0.0);
    glutSetCursor(GLUT_CURSOR_NONE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthFunc(GL_LEQUAL);
    glutWarpPointer(width / 2, height / 2);
}

void matahari() {
	glPushMatrix();
	glColor3f(1.0, 0.68, 0.0);
	glTranslatef(40.0, 140.0, 500.0);
	glutSolidSphere(50.0, 40, 40);
	glPopMatrix();
	/*
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(40.0, 140.0, 500.0);
	glutSolidSphere(60.0, 50, 50);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(40.0, 140.0, 500.0);
	glutSolidSphere(70.0, 60, 60);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(40.0, 140.0, 500.0);
	glutSolidSphere(80.0, 70, 70);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(40.0, 140.0, 500.0);
	glutSolidSphere(90.0, 80, 80);
	glPopMatrix();
	*/
}

//awan
void awan(){
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(40.0, 140.0, 500.0);
	glutSolidSphere(50.0, 40, 40);
	glPopMatrix();
		
	glPushMatrix();
	glTranslatef(-40.0, 140.0, 500.0);
	glutSolidSphere(50.0, 40, 40);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0.0, 160.0, 500.0);
	glutSolidSphere(50.0, 40, 40);
	glPopMatrix();
	
	/*
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glutSolidSphere(7, 50, 50);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(-75, 2110, -120);
	glutSolidSphere(12, 270, 50);
	glScalef(10.8, 5.0, 16.0);
	glPopMatrix();
 
	glPushMatrix();
	glTranslatef(-75, 2110, -115);
	glutSolidSphere(7, 50, 10);
	glScalef(15.8, 50.0, 17.0);
	glPopMatrix();
 
	glPushMatrix();
	glTranslatef(-75, 2520, -120);
	glutSolidSphere(20, 50, 30);
	glScalef(25.8, 8.0, 13.0);
	glPopMatrix();
 
	glPushMatrix();
	glTranslatef(-75, 2190, -120);
	glutSolidSphere(7, 20, 50);
	glScalef(7.8, 35.0, 19.0);
	glPopMatrix();
	*/
}

void pohon() {
	glPushMatrix();
	glTranslatef(0.0, 120.0, 500.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glColor3f(0.41, 0.21, 0.21);
	gluCylinder(gluNewQuadric(), 10.0f, 10.0f, 120.0f, 52, 52);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.14, 0.38, 0.04);
	glTranslatef(40.0, 140.0, 500.0);
	glutSolidSphere(50.0, 40, 40);
	glPopMatrix();
		
	glPushMatrix();
	glTranslatef(-40.0, 140.0, 500.0);
	glutSolidSphere(50.0, 40, 40);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0.0, 200.0, 500.0);
	glutSolidSphere(50.0, 40, 40);
	glPopMatrix();
}

//Teko
void teko(){

    glutSolidTeapot(10);
    glColor3f(0.71, 0.71, 0.71);
    glTranslatef(0.0, -40.0, -30.0);
    glColor3f(0.54, 0.54, 0.54);
}

//Meja Kursi
void meja() {
        // Alas Meja
    glBegin(GL_POLYGON);//ATAS
    glColor3f(0.36, 0.16, 0);
    glVertex3f(-100, 30, 80);
    glVertex3f(100, 30, 80);
    glVertex3f(100, 30, -20);
    glVertex3f(-100, 30, -20);
    glEnd();
    glBegin(GL_POLYGON);//BAWAH
    glColor3f(0.36, 0.16, 0);
    glVertex3f(-100, 20, 80);
    glVertex3f(100, 20, 80);
    glVertex3f(100, 20, -20);
    glVertex3f(-100, 20, -20);
    glEnd();
    glBegin(GL_POLYGON);//SAMPING KANAN
    glColor3f(0.36, 0.16, 0);
    glVertex3f(100, 20, 80);
    glVertex3f(100, 30, 80);
    glVertex3f(100, 30, -20);
    glVertex3f(100, 20, -20);
    glEnd();
    glBegin(GL_POLYGON);//SAMPING KIRI
    glColor3f(0.36, 0.16, 0);
    glVertex3f(-100, 30, 80);
    glVertex3f(-100, 30, 80);
    glVertex3f(-100, 30, -20);
    glVertex3f(-100, 20, -20);
    glEnd();
    glBegin(GL_POLYGON);//DEPAN
    glColor3f(0.36, 0.16, 0);
    glVertex3f(-100, 20, 80);
    glVertex3f(-100, 30, 80);
    glVertex3f(100, 30, 80);
    glVertex3f(100, 20, 80);
    glEnd();
    glBegin(GL_POLYGON);//BELAKANG
    glColor3f(0.36, 0.16, 0);
    glVertex3f(-100, 20, -20);
    glVertex3f(-100, 30, -20);
    glVertex3f(100, 30, -20);
    glVertex3f(100, 20, -20);
    glEnd();

    //KAKI MEJA 1
    glBegin(GL_POLYGON);//DEPAN
    glColor3f(0.48, 0.25, 0.0);
    glVertex3f(-100, 20, 80);
    glVertex3f(-80, 20, 80);
    glVertex3f(-80, -10, 80);
    glVertex3f(-100, -10, 80);
    glEnd();
    glBegin(GL_POLYGON);//BELAKANG
    glColor3f(0.48, 0.25, 0.0);
    glVertex3f(-100, 20, 60);
    glVertex3f(-80, 20, 60);
    glVertex3f(-80, -10, 60);
    glVertex3f(-100, -10, 60);
    glEnd();
    glBegin(GL_POLYGON);//KIRI
    glColor3f(0.48, 0.25, 0.0);
    glVertex3f(-100, 20, 60);
    glVertex3f(-100, -10, 60);
    glVertex3f(-100, -10, 80);
    glVertex3f(-100, 20, 80);
    glEnd();
    glBegin(GL_POLYGON);//KANAN
    glColor3f(0.48, 0.25, 0.0);
    glVertex3f(-80, 20, 60);
    glVertex3f(-80, -10, 60);
    glVertex3f(-80, -10, 80);
    glVertex3f(-80, 20, 80);
    glEnd();

    //KAKI MEJA 2
    glBegin(GL_POLYGON);//DEPAN
    glColor3f(0.48, 0.25, 0.0);
    glVertex3f(100, 20, 80);
    glVertex3f(80, 20, 80);
    glVertex3f(80, -10, 80);
    glVertex3f(100, -10, 80);
    glEnd();
    glBegin(GL_POLYGON);//BELAKANG
    glColor3f(0.48, 0.25, 0.0);
    glVertex3f(100, 20, 60);
    glVertex3f(80, 20, 60);
    glVertex3f(80, -10, 60);
    glVertex3f(100, -10, 60);
    glEnd();
    glBegin(GL_POLYGON);//KIRI
    glColor3f(0.48, 0.25, 0.0);
    glVertex3f(100, 20, 60);
    glVertex3f(100, -10, 60);
    glVertex3f(100, -10, 80);
    glVertex3f(100, 20, 80);
    glEnd();
    glBegin(GL_POLYGON);//KANAN
    glColor3f(0.48, 0.25, 0.0);
    glVertex3f(80, 20, 60);
    glVertex3f(80, -10, 60);
    glVertex3f(80, -10, 80);
    glVertex3f(80, 20, 80);
    glEnd();

    //KAKI MEJA 3
    glBegin(GL_POLYGON);//DEPAN
    glColor3f(0.48, 0.25, 0.0);
    glVertex3f(-100, 20, 0);
    glVertex3f(-80, 20, 0);
    glVertex3f(-80, -10, 0);
    glVertex3f(-100, -10, 0);
    glEnd();
    glBegin(GL_POLYGON);//BELAKANG
    glColor3f(0.48, 0.25, 0.0);
    glVertex3f(-100, 20, -20);
    glVertex3f(-80, 20, -20);
    glVertex3f(-80, -10, -20);
    glVertex3f(-100, -10, -20);
    glEnd();
    glBegin(GL_POLYGON);//KIRI
    glColor3f(0.48, 0.25, 0.0);
    glVertex3f(-100, 20, 0);
    glVertex3f(-100, -10, 0);
    glVertex3f(-100, -10, -20);
    glVertex3f(-100, 20, -20);
    glEnd();
    glBegin(GL_POLYGON);//KANAN
    glColor3f(0.48, 0.25, 0.0);
    glVertex3f(-80, 20, 0);
    glVertex3f(-80, -10, 0);
    glVertex3f(-80, -10, -20);
    glVertex3f(-80, 20, -20);
    glEnd();

    //KAKI MEJA 4
    glBegin(GL_POLYGON);//DEPAN
    glColor3f(0.48, 0.25, 0.0);
    glVertex3f(100, 20, 0);
    glVertex3f(80, 20, 0);
    glVertex3f(80, -10, 0);
    glVertex3f(100, -10, 0);
    glEnd();
    glBegin(GL_POLYGON);//BELAKANG
    glColor3f(0.48, 0.25, 0.0);
    glVertex3f(100, 20, -20);
    glVertex3f(80, 20, -20);
    glVertex3f(80, -10, -20);
    glVertex3f(100, -10, -20);
    glEnd();
    glBegin(GL_POLYGON);//KIRI
    glColor3f(0.48, 0.25, 0.0);
    glVertex3f(100, 20, 0);
    glVertex3f(100, -10, 0);
    glVertex3f(100, -10, -20);
    glVertex3f(100, 20, -20);
    glEnd();
    glBegin(GL_POLYGON);//KANAN
    glColor3f(0.48, 0.25, 0.0);
    glVertex3f(80, 20, 0);
    glVertex3f(80, -10, 0);
    glVertex3f(80, -10, -20);
    glVertex3f(80, 20, -20);
    glEnd();
}

void ground() {
    glBegin(GL_QUADS);
    glColor3f(0.06, 0.46, 0.13);
    glVertex3f(-2000.0, 0, -2000.0);

    //glColor3f(0.6f, 0.6f, 0.6f);
    glVertex3f(2000.0, 0, -2000.0);

    //glColor3f(0.6f, 0.6f, 0.6f);
    glVertex3f(2000.0, 0, 2000.0);

    //glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-2000.0, 0, 2000.0);
    glEnd();
}

		//RUANG 1
void hias_blkg(float x,float y,float z,float x1,float y1,float z1,float x2,float y2,float z2,float x3,float y3,float z3) {
	for(int e = 0; e < 5; e++) {
   		glBegin(GL_POLYGON); 
    	glColor3f(1.0, 0.14, 0.14);
    	glVertex3f(x,y,z);
    	glVertex3f(x1,y1,z1);
    	glVertex3f(x2,y2,z2);
    	glVertex3f(x3,y3,z3);
    	glEnd();
    	x+=116; x1+=116; x2+=116; x3+=116;
    }
}
void hias_samping(float x,float y,float z,float x1,float y1,float z1,float x2,float y2,float z2,float x3,float y3,float z3) {
	for(int e = 0; e < 4; e++) {
   		glBegin(GL_POLYGON); 
    	glColor3f(1.0, 0.14, 0.14);
    	glVertex3f(x,y,z);
    	glVertex3f(x1,y1,z1);
    	glVertex3f(x2,y2,z2);
    	glVertex3f(x3,y3,z3);
    	glEnd();
    	z-=100; z1-=100; z2-=100; z3-=100;
    }
}

		//RUANG 2
void hias_horizontal(float x,float y,float z,float x1,float y1,float z1,float x2,float y2,float z2,float x3,float y3,float z3) {
	for(int e = 0; e < 2; e++) {
   		glBegin(GL_POLYGON); 
    	glColor3f(1.0, 0.14, 0.14);
    	glVertex3f(x,y,z);
    	glVertex3f(x1,y1,z1);
    	glVertex3f(x2,y2,z2);
    	glVertex3f(x3,y3,z3);
    	glEnd();
    	y+=20; y1+=20; y2+=20; y3+=20;
    }
}

		//ruang 4
void hias_hrzntl(float x,float y,float z,float x1,float y1,float z1,float x2,float y2,float z2,float x3,float y3,float z3) {
	for(int e = 0; e < 2; e++) {
   		glBegin(GL_POLYGON); 
    	glColor3f(1.0, 0.14, 0.14);
    	glVertex3f(x,y,z);
    	glVertex3f(x1,y1,z1);
    	glVertex3f(x2,y2,z2);
    	glVertex3f(x3,y3,z3);
    	glEnd();
    	y+=10; y1+=10; y2+=10; y3+=10;
    }
}

void tiang(float x,float y,float z,float x1,float y1,float z1,float x2,float y2,float z2,float x3,float y3,float z3) {
	for(int e = 0; e < 2; e++) {
   		glBegin(GL_POLYGON); 
    	glColor3f(1.0, 0.14, 0.14);
    	glVertex3f(x,y,z);
    	glVertex3f(x1,y1,z1);
    	glVertex3f(x2,y2,z2);
    	glVertex3f(x3,y3,z3);
    	glEnd();
    	x-= x*2; x1-= x1*2; x2-= x2*2; x3-=x3*2;
    }
}

void lantai() {
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.18, 0.16, 0.16);
	glVertex3f(-700.0, 0.0, 50.0);
	glVertex3f(-700.0, 100.0, 50.0);
	glVertex3f(700.0, 100.0, 50.0);
	glVertex3f(700.0, 0.0, 50.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-700.0, 0.0, -850.0);
	glVertex3f(-700.0, 100.0, -850.0);
	glVertex3f(700.0, 100.0, -850.0);
	glVertex3f(700.0, 0.0, -850.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-700.0, 100.0, -850.0);
	glVertex3f(-700.0, 100.0, 50.0);
	glVertex3f(700.0, 100.0, 50.0);
	glVertex3f(700.0, 100.0, -850.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(700.0, 0.0, 50.0);
	glVertex3f(700.0, 100.0, 50.0);
	glVertex3f(700.0, 100.0, -850.0);
	glVertex3f(700.0, 0.0, -850.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-700.0, 0.0, 50.0);
	glVertex3f(-700.0, 100.0, 50.0);
	glVertex3f(-700.0, 100.0, -850.0);
	glVertex3f(-700.0, 0.0, -850.0);
	glEnd();
}

void karpet() {
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.17, 0.2, 0.22);
	glVertex3f(-390.0, 100.0, -110.0);
	glVertex3f(-390.0, 105.0, -110.0);
	glVertex3f(390.0, 105.0, -110.0);
	glVertex3f(390.0, 100.0, -110.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-390.0, 100.0, -690.0);
	glVertex3f(-390.0, 105.0, -690.0);
	glVertex3f(390.0, 105.0, -690.0);
	glVertex3f(390.0, 100.0, -690.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-390.0, 105.0, -690.0);
	glVertex3f(-390.0, 105.0, -110.0);
	glVertex3f(390.0, 105.0, -110.0);
	glVertex3f(390.0, 105.0, -690.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(390.0, 100.0, -110.0);
	glVertex3f(390.0, 105.0, -110.0);
	glVertex3f(390.0, 105.0, -690.0);
	glVertex3f(390.0, 100.0, -690.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-390.0, 100.0, -110.0);
	glVertex3f(-390.0, 105.0, -110.0);
	glVertex3f(-390.0, 105.0, -690.0);
	glVertex3f(-390.0, 100.0, -690.0);
	glEnd();
}

void ruang1() {
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.92, 0.88, 0.8);
	glVertex3f(-50.0, 105.0, -150.0);
	glVertex3f(-50.0, 400.0, -150.0);
	glVertex3f(-350.0, 400.0, -150.0);
	glVertex3f(-350.0, 105.0, -150.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.92, 0.88, 0.8);
	glVertex3f(50.0, 105.0, -150.0);
	glVertex3f(50.0, 400.0, -150.0);
	glVertex3f(350.0, 400.0, -150.0);
	glVertex3f(350.0, 105.0, -150.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.92, 0.88, 0.8);
	glVertex3f(-50.0, 300.0, -150.0);
	glVertex3f(-50.0, 400.0, -150.0);
	glVertex3f(50.0, 400.0, -150.0);
	glVertex3f(50.0, 300.0, -150.0);
	glEnd();
	
	//belakang
	glBegin(GL_POLYGON);
	glColor3f(0.92, 0.88, 0.8);
	glVertex3f(-350.0, 105.0, -650.0);
	glVertex3f(-350.0, 400.0, -650.0);
	glVertex3f(350.0, 400.0, -650.0);
	glVertex3f(350.0, 105.0, -650.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.0, 0.0);
	glVertex3f(-350.0, 399.0, -650.0);
	glVertex3f(-350.0, 399.0, -150.0);
	glVertex3f(350.0, 399.0, -150.0);
	glVertex3f(350.0, 399.0, -650.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.0, 0.0);
	glVertex3f(-350.0, 106.0, -650.0);
	glVertex3f(-350.0, 106.0, -150.0);
	glVertex3f(350.0, 106.0, -150.0);
	glVertex3f(350.0, 106.0, -650.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glColor3f(0.92, 0.88, 0.8);
	glVertex3f(350.0, 105.0, -150.0);
	glVertex3f(350.0, 400.0, -150.0);
	glVertex3f(350.0, 400.0, -650.0);
	glVertex3f(350.0, 105.0, -650.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(0.92, 0.88, 0.8);
	glVertex3f(-350.0, 105.0, -150.0);
	glVertex3f(-350.0, 400.0, -150.0);
	glVertex3f(-350.0, 400.0, -650.0);
	glVertex3f(-350.0, 105.0, -650.0);
	glEnd();
}

void cagak_ruang1() {
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-50.0, 300.0, -140.0);
	glVertex3f(-50.0, 310.0, -140.0);
	glVertex3f(50.0, 310.0, -140.0);
	glVertex3f(50.0, 300.0, -140.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-50.0, 300.0, -140.0);
	glVertex3f(-50.0, 300.0, -150.0);
	glVertex3f(50.0, 300.0, -150.0);
	glVertex3f(50.0, 300.0, -140.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-50.0, 310.0, -140.0);
	glVertex3f(-50.0, 310.0, -150.0);
	glVertex3f(50.0, 310.0, -150.0);
	glVertex3f(50.0, 310.0, -140.0);
	glEnd();
		//HORIZONTAL
	//depan
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-330.0, 390.0, -140.0);
	glVertex3f(-330.0, 400.0, -140.0);
	glVertex3f(330.0, 400.0, -140.0);
	glVertex3f(330.0, 390.0, -140.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-330.0, 390.0, -140.0);
	glVertex3f(-330.0, 390.0, -150.0);
	glVertex3f(330.0, 390.0, -150.0);
	glVertex3f(330.0, 390.0, -140.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-330.0, 390.0, -660.0);
	glVertex3f(-330.0, 400.0, -660.0);
	glVertex3f(330.0, 400.0, -660.0);
	glVertex3f(330.0, 390.0, -660.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-330.0, 390.0, -660.0);
	glVertex3f(-330.0, 390.0, -650.0);
	glVertex3f(330.0, 390.0, -650.0);
	glVertex3f(330.0, 390.0, -660.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-360.0, 390.0, -140.0);
	glVertex3f(-360.0, 400.0, -140.0);
	glVertex3f(-360.0, 400.0, -660.0);
	glVertex3f(-360.0, 390.0, -660.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-350.0, 390.0, -650.0);
	glVertex3f(-350.0, 390.0, -150.0);
	glVertex3f(-360.0, 390.0, -150.0);
	glVertex3f(-360.0, 390.0, -650.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(360.0, 390.0, -140.0);
	glVertex3f(360.0, 400.0, -140.0);
	glVertex3f(360.0, 400.0, -660.0);
	glVertex3f(360.0, 390.0, -660.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(350.0, 390.0, -650.0);
	glVertex3f(350.0, 390.0, -150.0);
	glVertex3f(360.0, 390.0, -150.0);
	glVertex3f(360.0, 390.0, -650.0);
	glEnd();
	
		//TIGA
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(70.0, 105.0, -140.0);
	glVertex3f(70.0, 400.0, -140.0);
	glVertex3f(50.0, 400.0, -140.0);
	glVertex3f(50.0, 105.0, -140.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(70.0, 105.0, -140.0);
	glVertex3f(70.0, 400.0, -140.0);
	glVertex3f(70.0, 400.0, -150.0);
	glVertex3f(70.0, 105.0, -150.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(50.0, 105.0, -140.0);
	glVertex3f(50.0, 400.0, -140.0);
	glVertex3f(50.0, 400.0, -150.0);
	glVertex3f(50.0, 105.0, -150.0);
	glEnd();
			//EMPAT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-70.0, 105.0, -140.0);
	glVertex3f(-70.0, 400.0, -140.0);
	glVertex3f(-50.0, 400.0, -140.0);
	glVertex3f(-50.0, 105.0, -140.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-70.0, 105.0, -140.0);
	glVertex3f(-70.0, 400.0, -140.0);
	glVertex3f(-70.0, 400.0, -150.0);
	glVertex3f(-70.0, 105.0, -150.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-50.0, 105.0, -140.0);
	glVertex3f(-50.0, 400.0, -140.0);
	glVertex3f(-50.0, 400.0, -150.0);
	glVertex3f(-50.0, 105.0, -150.0);
	glEnd();
	
}

void atap_lantai1() {
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.35, 0.15, 0.15);
	glVertex3f(-450.0, 450.0, -100.0);
	glVertex3f(-360.0, 400.0, -140.0);
	glVertex3f(360.0, 400.0, -140.0);
	glVertex3f(450.0, 450.0, -100.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-450.0, 450.0, -700.0);
	glVertex3f(-360.0, 400.0, -660.0);
	glVertex3f(360.0, 400.0, -660.0);
	glVertex3f(450.0, 450.0, -700.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-450.0, 450.0, -700.0);
	glVertex3f(-450.0, 450.0, -100.0);
	glVertex3f(450.0, 450.0, -100.0);
	glVertex3f(450.0, 450.0, -700.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-360.0, 400.0, -660.0);
	glVertex3f(-360.0, 400.0, -140.0);
	glVertex3f(360.0, 400.0, -140.0);
	glVertex3f(360.0, 400.0, -660.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(450.0, 450.0, -100.0);
	glVertex3f(360.0, 400.0, -140.0);
	glVertex3f(360.0, 400.0, -660.0);
	glVertex3f(450.0, 450.0, -700.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-450.0, 450.0, -100.0);
	glVertex3f(-360.0, 400.0, -140.0);
	glVertex3f(-360.0, 400.0, -660.0);
	glVertex3f(-450.0, 450.0, -700.0);
	glEnd();
}

void lantai2() {
	//depan
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-450.0, 450.0, -100.0);
	glVertex3f(-450.0, 470.0, -100.0);
	glVertex3f(450.0, 470.0, -100.0);
	glVertex3f(450.0, 450.0, -100.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-450.0, 450.0, -700.0);
	glVertex3f(-450.0, 470.0, -700.0);
	glVertex3f(450.0, 470.0, -700.0);
	glVertex3f(450.0, 450.0, -700.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-450.0, 470.0, -700.0);
	glVertex3f(-450.0, 470.0, -100.0);
	glVertex3f(450.0, 470.0, -100.0);
	glVertex3f(450.0, 470.0, -700.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(450.0, 450.0, -100.0);
	glVertex3f(450.0, 470.0, -100.0);
	glVertex3f(450.0, 470.0, -700.0);
	glVertex3f(450.0, 450.0, -700.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-450.0, 450.0, -100.0);
	glVertex3f(-450.0, 470.0, -100.0);
	glVertex3f(-450.0, 470.0, -700.0);
	glVertex3f(-450.0, 450.0, -700.0);
	glEnd();
}


void karpet2() {
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.17, 0.2, 0.22);
	glVertex3f(-250.0, 470.0, -150.0);
	glVertex3f(-250.0, 480.0, -150.0);
	glVertex3f(250.0, 480.0, -150.0);
	glVertex3f(250.0, 470.0, -150.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-250.0, 470.0, -650.0);
	glVertex3f(-250.0, 480.0, -650.0);
	glVertex3f(250.0, 480.0, -650.0);
	glVertex3f(250.0, 470.0, -650.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-250.0, 480.0, -650.0);
	glVertex3f(-250.0, 480.0, -150.0);
	glVertex3f(250.0, 480.0, -150.0);
	glVertex3f(250.0, 480.0, -650.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(250.0, 470.0, -150.0);
	glVertex3f(250.0, 480.0, -150.0);
	glVertex3f(250.0, 480.0, -650.0);
	glVertex3f(250.0, 470.0, -650.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-250.0, 470.0, -150.0);
	glVertex3f(-250.0, 480.0, -150.0);
	glVertex3f(-250.0, 480.0, -650.0);
	glVertex3f(-250.0, 470.0, -650.0);
	glEnd();
}

void ruang2() {
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.92, 0.88, 0.8);
	glVertex3f(-210.0, 480.0, -200.0);
	glVertex3f(-210.0, 700.0, -200.0);
	glVertex3f(210.0, 700.0, -200.0);
	glVertex3f(210.0, 480.0, -200.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-210.0, 480.0, -600.0);
	glVertex3f(-210.0, 700.0, -600.0);
	glVertex3f(210.0, 700.0, -600.0);
	glVertex3f(210.0, 480.0, -600.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-210.0, 700.0, -600.0);
	glVertex3f(-210.0, 700.0, -200.0);
	glVertex3f(210.0, 700.0, -200.0);
	glVertex3f(210.0, 700.0, -600.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-210.0, 480.0, -600.0);
	glVertex3f(-210.0, 480.0, -200.0);
	glVertex3f(210.0, 480.0, -200.0);
	glVertex3f(210.0, 480.0, -600.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(210.0, 480.0, -200.0);
	glVertex3f(210.0, 700.0, -200.0);
	glVertex3f(210.0, 700.0, -600.0);
	glVertex3f(210.0, 480.0, -600.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-210.0, 480.0, -200.0);
	glVertex3f(-210.0, 700.0, -200.0);
	glVertex3f(-210.0, 700.0, -600.0);
	glVertex3f(-210.0, 480.0, -600.0);
	glEnd();
}

void cagak_ruang2() {
	//pintu
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-30.0, 480.0, -199.0);
	glVertex3f(-30.0, 600.0, -199.0);
	glVertex3f(30.0, 600.0, -199.0);
	glVertex3f(30.0, 480.0, -199.0);
	glEnd();
		//GARIS TENGAH
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-3.0, 630.0, -190.0);
	glVertex3f(-3.0, 700.0, -190.0);
	glVertex3f(-3.0, 700.0, -200.0);
	glVertex3f(-3.0, 630.0, -200.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(3.0, 630.0, -200.0);
	glVertex3f(3.0, 700.0, -200.0);
	glVertex3f(3.0, 700.0, -190.0);
	glVertex3f(3.0, 630.0, -190.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-3.0, 630.0, -190.0);
	glVertex3f(-3.0, 700.0, -190.0);
	glVertex3f(3.0, 700.0, -190.0);
	glVertex3f(3.0, 630.0, -190.0);
	glEnd();
		//samping kiri pintu
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-30.0, 480.0, -190.0);
	glVertex3f(-30.0, 600.0, -190.0);
	glVertex3f(-35.0, 600.0, -190.0);
	glVertex3f(-35.0, 480.0, -190.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-30.0, 480.0, -200.0);
	glVertex3f(-30.0, 600.0, -200.0);
	glVertex3f(-30.0, 600.0, -190.0);
	glVertex3f(-30.0, 480.0, -190.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-35.0, 480.0, -200.0);
	glVertex3f(-35.0, 605.0, -200.0);
	glVertex3f(-35.0, 605.0, -190.0);
	glVertex3f(-35.0, 480.0, -190.0);
	glEnd();
		//samping kanan pintu
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(30.0, 480.0, -190.0);
	glVertex3f(30.0, 600.0, -190.0);
	glVertex3f(35.0, 600.0, -190.0);
	glVertex3f(35.0, 480.0, -190.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(30.0, 480.0, -200.0);
	glVertex3f(30.0, 600.0, -200.0);
	glVertex3f(30.0, 600.0, -190.0);
	glVertex3f(30.0, 480.0, -190.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(35.0, 480.0, -200.0);
	glVertex3f(35.0, 605.0, -200.0);
	glVertex3f(35.0, 605.0, -190.0);
	glVertex3f(35.0, 480.0, -190.0);
	glEnd();
		//samping atas pintu
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(35.0, 600.0, -190.0);
	glVertex3f(35.0, 605.0, -190.0);
	glVertex3f(-35.0, 605.0, -190.0);
	glVertex3f(-35.0, 600.0, -190.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(35.0, 605.0, -190.0);
	glVertex3f(35.0, 605.0, -200.0);
	glVertex3f(-35.0, 605.0, -200.0);
	glVertex3f(-35.0, 605.0, -190.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(35.0, 600.0, -190.0);
	glVertex3f(35.0, 605.0, -200.0);
	glVertex3f(-35.0, 605.0, -200.0);
	glVertex3f(-35.0, 600.0, -190.0);
	glEnd();
	
	//cagak KIRI
		//SATU TIDUR
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-210.0, 535.0, -190.0);
	glVertex3f(-210.0, 545.0, -190.0);
	glVertex3f(-35.0, 545.0, -190.0);
	glVertex3f(-35.0, 535.0, -190.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-210.0, 545.0, -190.0);
	glVertex3f(-210.0, 545.0, -200.0);
	glVertex3f(-35.0, 545.0, -200.0);
	glVertex3f(-35.0, 545.0, -190.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-210.0, 535.0, -190.0);
	glVertex3f(-210.0, 535.0, -200.0);
	glVertex3f(-35.0, 535.0, -200.0);
	glVertex3f(-35.0, 535.0, -190.0);
	glEnd();
	
	
	//cagak KANAN
		//SATU TIDUR
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(210.0, 535.0, -190.0);
	glVertex3f(210.0, 545.0, -190.0);
	glVertex3f(35.0, 545.0, -190.0);
	glVertex3f(35.0, 535.0, -190.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(210.0, 545.0, -190.0);
	glVertex3f(210.0, 545.0, -200.0);
	glVertex3f(35.0, 545.0, -200.0);
	glVertex3f(35.0, 545.0, -190.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(210.0, 535.0, -190.0);
	glVertex3f(210.0, 535.0, -200.0);
	glVertex3f(35.0, 535.0, -200.0);
	glVertex3f(35.0, 535.0, -190.0);
	glEnd();
}

void bawah_atap2() {
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.25, 0.11, 0.11);
	glVertex3f(-225.0, 700.0, -195.0);
	glVertex3f(-225.0, 720.0, -195.0);
	glVertex3f(225.0, 720.0, -195.0);
	glVertex3f(225.0, 700.0, -195.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-225.0, 700.0, -605.0);
	glVertex3f(-225.0, 720.0, -605.0);
	glVertex3f(225.0, 720.0, -605.0);
	glVertex3f(225.0, 700.0, -605.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-225.0, 719.0, -605.0);
	glVertex3f(-225.0, 719.0, -195.0);
	glVertex3f(225.0, 719.0, -195.0);
	glVertex3f(225.0, 719.0, -605.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-225.0, 700.0, -605.0);
	glVertex3f(-225.0, 700.0, -195.0);
	glVertex3f(225.0, 700.0, -195.0);
	glVertex3f(225.0, 700.0, -605.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(225.0, 700.0, -195.0);
	glVertex3f(225.0, 720.0, -195.0);
	glVertex3f(225.0, 720.0, -605.0);
	glVertex3f(225.0, 700.0, -605.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-225.0, 700.0, -195.0);
	glVertex3f(-225.0, 720.0, -195.0);
	glVertex3f(-225.0, 720.0, -605.0);
	glVertex3f(-225.0, 700.0, -605.0);
	glEnd();
}

void atap2() {
	//bawah
	glBegin(GL_POLYGON);
	//glColor3f(0.35, 0.15, 0.15);
	glColor3f(0.47, 0.19, 0.19);
	glVertex3f(-350.0, 720.0, -100.0);
	glVertex3f(-350.0, 720.0, -700.0);
	glVertex3f(350.0, 720.0, -700.0);
	glVertex3f(350.0, 720.0, -100.0);
	glEnd();
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.47, 0.19, 0.19);
	glVertex3f(-350.0, 720.0, -100.0);
	glVertex3f(-250.0, 760.0, -150.0);
	glVertex3f(250.0, 760.0, -150.0);
	glVertex3f(350.0, 720.0, -100.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-350.0, 720.0, -700.0);
	glVertex3f(-250.0, 760.0, -650.0);
	glVertex3f(250.0, 760.0, -650.0);
	glVertex3f(350.0, 720.0, -700.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-250.0, 760.0, -150.0);
	glVertex3f(-250.0, 760.0, -650.0);
	glVertex3f(250.0, 760.0, -650.0);
	glVertex3f(250.0, 760.0, -150.0);
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(350.0, 720.0, -100.0);
	glVertex3f(250.0, 760.0, -150.0);
	glVertex3f(250.0, 760.0, -650.0);
	glVertex3f(350.0, 720.0, -700.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-350.0, 720.0, -100.0);
	glVertex3f(-250.0, 760.0, -150.0);
	glVertex3f(-250.0, 760.0, -650.0);
	glVertex3f(-350.0, 720.0, -700.0);
	glEnd();
	
	//tingkat 2
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.47, 0.19, 0.19);
	glVertex3f(-250.0, 760.0, -150.0);
	glVertex3f(-220.0, 800.0, -180.0);
	glVertex3f(220.0, 800.0, -180.0);
	glVertex3f(250.0, 760.0, -150.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-250.0, 760.0, -650.0);
	glVertex3f(-220.0, 800.0, -630.0);
	glVertex3f(220.0, 800.0, -630.0);
	glVertex3f(250.0, 760.0, -650.0);
	glEnd();	
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-250.0, 760.0, -150.0);
	glVertex3f(-250.0, 760.0, -650.0);
	glVertex3f(250.0, 760.0, -650.0);
	glVertex3f(250.0, 760.0, -150.0);
	glEnd();
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-220.0, 800.0, -180.0);
	glVertex3f(-220.0, 800.0, -630.0);
	glVertex3f(220.0, 800.0, -630.0);
	glVertex3f(220.0, 800.0, -180.0);
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(250.0, 760.0, -150.0);
	glVertex3f(220.0, 800.0, -180.0);
	glVertex3f(220.0, 800.0, -630.0);
	glVertex3f(250.0, 760.0, -650.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-250.0, 760.0, -150.0);
	glVertex3f(-220.0, 800.0, -180.0);
	glVertex3f(-220.0, 800.0, -630.0);
	glVertex3f(-250.0, 760.0, -650.0);
	glEnd();
}

void atap_lantai2() {
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.35, 0.15, 0.15);
	glVertex3f(-300.0, 830.0, -150.0);
	glVertex3f(-220.0, 800.0, -180.0);
	glVertex3f(220.0, 800.0, -180.0);
	glVertex3f(300.0, 830.0, -150.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-300.0, 830.0, -660.0);
	glVertex3f(-220.0, 800.0, -630.0);
	glVertex3f(220.0, 800.0, -630.0);
	glVertex3f(300.0, 830.0, -660.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-300.0, 830.0, -660.0);
	glVertex3f(-300.0, 830.0, -150.0);
	glVertex3f(300.0, 830.0, -150.0);
	glVertex3f(300.0, 830.0, -660.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(300.0, 830.0, -150.0);
	glVertex3f(220.0, 800.0, -180.0);
	glVertex3f(220.0, 800.0, -630.0);
	glVertex3f(300.0, 830.0, -660.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-300.0, 830.0, -150.0);
	glVertex3f(-220.0, 800.0, -180.0);
	glVertex3f(-220.0, 800.0, -630.0);
	glVertex3f(-300.0, 830.0, -660.0);
	glEnd();
}

void lantai3() {
	//depan
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-300.0, 830.0, -150.0);
	glVertex3f(-300.0, 840.0, -150.0);
	glVertex3f(300.0, 840.0, -150.0);
	glVertex3f(300.0, 830.0, -150.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-300.0, 830.0, -660.0);
	glVertex3f(-300.0, 840.0, -660.0);
	glVertex3f(300.0, 840.0, -660.0);
	glVertex3f(300.0, 830.0, -660.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-300.0, 840.0, -660.0);
	glVertex3f(-300.0, 840.0, -150.0);
	glVertex3f(300.0, 840.0, -150.0);
	glVertex3f(300.0, 840.0, -660.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-300.0, 830.0, -660.0);
	glVertex3f(-300.0, 830.0, -150.0);
	glVertex3f(300.0, 830.0, -150.0);
	glVertex3f(300.0, 830.0, -660.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(300.0, 830.0, -660.0);
	glVertex3f(300.0, 840.0, -150.0);
	glVertex3f(300.0, 840.0, -660.0);
	glVertex3f(300.0, 830.0, -150.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-300.0, 830.0, -660.0);
	glVertex3f(-300.0, 840.0, -150.0);
	glVertex3f(-300.0, 840.0, -660.0);
	glVertex3f(-300.0, 830.0, -150.0);
	glEnd();
}

void karpet3() {
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-180.0, 840.0, -230.0);
	glVertex3f(-180.0, 850.0, -230.0);
	glVertex3f(180.0, 850.0, -230.0);
	glVertex3f(180.0, 840.0, -230.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-180.0, 840.0, -570.0);
	glVertex3f(-180.0, 850.0, -570.0);
	glVertex3f(180.0, 850.0, -570.0);
	glVertex3f(180.0, 840.0, -570.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-180.0, 850.0, -570.0);
	glVertex3f(-180.0, 850.0, -230.0);
	glVertex3f(180.0, 850.0, -230.0);
	glVertex3f(180.0, 850.0, -570.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(180.0, 840.0, -230.0);
	glVertex3f(180.0, 850.0, -230.0);
	glVertex3f(180.0, 850.0, -570.0);
	glVertex3f(180.0, 840.0, -570.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-180.0, 840.0, -230.0);
	glVertex3f(-180.0, 850.0, -230.0);
	glVertex3f(-180.0, 850.0, -570.0);
	glVertex3f(-180.0, 840.0, -570.0);
	glEnd();
}

void ruang3() {
		//depan
	glBegin(GL_POLYGON);
	glColor3f(0.92, 0.88, 0.8);
	glVertex3f(-170.0, 850.0, -240.0);
	glVertex3f(-170.0, 1040.0, -240.0);
	glVertex3f(170.0, 1040.0, -240.0);
	glVertex3f(170.0, 850.0, -240.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-170.0, 850.0, -560.0);
	glVertex3f(-170.0, 1040.0, -560.0);
	glVertex3f(170.0, 1040.0, -560.0);
	glVertex3f(170.0, 850.0, -560.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-170.0, 1040.0, -560.0);
	glVertex3f(-170.0, 1040.0, -240.0);
	glVertex3f(170.0, 1040.0, -240.0);
	glVertex3f(170.0, 1040.0, -560.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-170.0, 850.0, -560.0);
	glVertex3f(-170.0, 850.0, -240.0);
	glVertex3f(170.0, 850.0, -240.0);
	glVertex3f(170.0, 850.0, -560.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(170.0, 850.0, -240.0);
	glVertex3f(170.0, 1040.0, -240.0);
	glVertex3f(170.0, 1040.0, -560.0);
	glVertex3f(170.0, 850.0, -560.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-170.0, 850.0, -240.0);
	glVertex3f(-170.0, 1040.0, -240.0);
	glVertex3f(-170.0, 1040.0, -560.0);
	glVertex3f(-170.0, 850.0, -560.0);
	glEnd();
}

void cagak_ruang3() {
	//pintu
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-20.0, 850.0, -239.0);
	glVertex3f(-20.0, 940.0, -239.0);
	glVertex3f(20.0, 940.0, -239.0);
	glVertex3f(20.0, 850.0, -239.0);
	glEnd();
		//samping kiri pintu
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-20.0, 850.0, -230.0);
	glVertex3f(-20.0, 940.0, -230.0);
	glVertex3f(-25.0, 940.0, -230.0);
	glVertex3f(-25.0, 850.0, -230.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-20.0, 850.0, -240.0);
	glVertex3f(-20.0, 940.0, -240.0);
	glVertex3f(-20.0, 940.0, -230.0);
	glVertex3f(-20.0, 850.0, -230.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-25.0, 850.0, -240.0);
	glVertex3f(-25.0, 945.0, -240.0);
	glVertex3f(-25.0, 945.0, -230.0);
	glVertex3f(-25.0, 850.0, -230.0);
	glEnd();
		//samping kanan pintu
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(20.0, 850.0, -230.0);
	glVertex3f(20.0, 940.0, -230.0);
	glVertex3f(25.0, 940.0, -230.0);
	glVertex3f(25.0, 850.0, -230.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(20.0, 850.0, -240.0);
	glVertex3f(20.0, 940.0, -240.0);
	glVertex3f(20.0, 940.0, -230.0);
	glVertex3f(20.0, 850.0, -230.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(25.0, 850.0, -240.0);
	glVertex3f(25.0, 945.0, -240.0);
	glVertex3f(25.0, 945.0, -230.0);
	glVertex3f(25.0, 850.0, -230.0);
	glEnd();
		//samping atas pintu
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(25.0, 940.0, -230.0);
	glVertex3f(25.0, 945.0, -230.0);
	glVertex3f(-25.0, 945.0, -230.0);
	glVertex3f(-25.0, 940.0, -230.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(25.0, 945.0, -230.0);
	glVertex3f(25.0, 945.0, -240.0);
	glVertex3f(-25.0, 945.0, -240.0);
	glVertex3f(-25.0, 945.0, -230.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(25.0, 940.0, -230.0);
	glVertex3f(25.0, 945.0, -240.0);
	glVertex3f(-25.0, 945.0, -240.0);
	glVertex3f(-25.0, 940.0, -230.0);
	glEnd();
	
	//cagak KIRI
		//SATU TIDUR
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-170.0, 890.0, -230.0);
	glVertex3f(-170.0, 895.0, -230.0);
	glVertex3f(-25.0, 895.0, -230.0);
	glVertex3f(-25.0, 890.0, -230.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-170.0, 895.0, -230.0);
	glVertex3f(-170.0, 895.0, -240.0);
	glVertex3f(-25.0, 895.0, -240.0);
	glVertex3f(-25.0, 895.0, -230.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-170.0, 890.0, -230.0);
	glVertex3f(-170.0, 890.0, -240.0);
	glVertex3f(-25.0, 890.0, -240.0);
	glVertex3f(-25.0, 890.0, -230.0);
	glEnd();
	
	//cagak KANAN
		//SATU TIDUR
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(170.0, 890.0, -230.0);
	glVertex3f(170.0, 895.0, -230.0);
	glVertex3f(25.0, 895.0, -230.0);
	glVertex3f(25.0, 890.0, -230.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(170.0, 895.0, -230.0);
	glVertex3f(170.0, 895.0, -240.0);
	glVertex3f(25.0, 895.0, -240.0);
	glVertex3f(25.0, 895.0, -230.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(170.0, 890.0, -230.0);
	glVertex3f(170.0, 890.0, -240.0);
	glVertex3f(25.0, 890.0, -240.0);
	glVertex3f(25.0, 890.0, -230.0);
	glEnd();
}


void bawah_atap3() {
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.25, 0.11, 0.11);
	glVertex3f(-180.0, 1040.0, -185.0);
	glVertex3f(-180.0, 1050.0, -185.0);
	glVertex3f(180.0, 1050.0, -185.0);
	glVertex3f(180.0, 1040.0, -185.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-180.0, 1040.0, -615.0);
	glVertex3f(-180.0, 1050.0, -615.0);
	glVertex3f(180.0, 1050.0, -615.0);
	glVertex3f(180.0, 1040.0, -615.0);
	glEnd();	
	/*
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-180.0, 1049.0, -615.0);
	glVertex3f(-180.0, 1049.0, -185.0);
	glVertex3f(180.0, 1049.0, -185.0);
	glVertex3f(180.0, 1049.0, -615.0);
	glEnd();
	*/
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-180.0, 1040.0, -615.0);
	glVertex3f(-180.0, 1040.0, -185.0);
	glVertex3f(180.0, 1040.0, -185.0);
	glVertex3f(180.0, 1040.0, -615.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(180.0, 1040.0, -185.0);
	glVertex3f(180.0, 1050.0, -185.0);
	glVertex3f(180.0, 1050.0, -615.0);
	glVertex3f(180.0, 1040.0, -615.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-180.0, 1040.0, -185.0);
	glVertex3f(-180.0, 1050.0, -185.0);
	glVertex3f(-180.0, 1050.0, -615.0);
	glVertex3f(-180.0, 1040.0, -615.0);
	glEnd();
}

void atap3 () {
	//bawah
	glBegin(GL_POLYGON);
	//glColor3f(0.35, 0.15, 0.15);
	glColor3f(0.47, 0.19, 0.19);
	glVertex3f(-300.0, 1050.0, -150.0);
	glVertex3f(-300.0, 1050.0, -650.0);
	glVertex3f(300.0, 1050.0, -650.0);
	glVertex3f(300.0, 1050.0, -150.0);
	glEnd();
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.47, 0.19, 0.19);
	glVertex3f(-300.0, 1050.0, -150.0);
	glVertex3f(-200.0, 1090.0, -200.0);
	glVertex3f(200.0, 1090.0, -200.0);
	glVertex3f(300.0, 1050.0, -150.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-300.0, 1050.0, -650.0);
	glVertex3f(-200.0, 1090.0, -600.0);
	glVertex3f(200.0, 1090.0, -600.0);
	glVertex3f(300.0, 1050.0, -650.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-200.0, 1090.0, -200.0);
	glVertex3f(-200.0, 1090.0, -600.0);
	glVertex3f(200.0, 1090.0, -600.0);
	glVertex3f(200.0, 1090.0, -200.0);
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(300.0, 1050.0, -150.0);
	glVertex3f(200.0, 1090.0, -200.0);
	glVertex3f(200.0, 1090.0, -600.0);
	glVertex3f(300.0, 1050.0, -650.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-300.0, 1050.0, -150.0);
	glVertex3f(-200.0, 1090.0, -200.0);
	glVertex3f(-200.0, 1090.0, -600.0);
	glVertex3f(-300.0, 1050.0, -650.0);
	glEnd();
	
	//tingkat 2
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.47, 0.19, 0.19);
	glVertex3f(-200.0, 1090.0, -200.0);
	glVertex3f(-170.0, 1130.0, -230.0);
	glVertex3f(170.0, 1130.0, -230.0);
	glVertex3f(200.0, 1090.0, -200.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-200.0, 1090.0, -600.0);
	glVertex3f(-170.0, 1130.0, -570.0);
	glVertex3f(170.0, 1130.0, -570.0);
	glVertex3f(200.0, 1090.0, -600.0);
	glEnd();	
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-200.0, 1090.0, -200.0);
	glVertex3f(-200.0, 1090.0, -600.0);
	glVertex3f(200.0, 1090.0, -600.0);
	glVertex3f(200.0, 1090.0, -200.0);
	glEnd();
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-170.0, 1130.0, -230.0);
	glVertex3f(-170.0, 1130.0, -570.0);
	glVertex3f(170.0, 1130.0, -570.0);
	glVertex3f(170.0, 1130.0, -230.0);
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(200.0, 1090.0, -200.0);
	glVertex3f(170.0, 1130.0, -230.0);
	glVertex3f(170.0, 1130.0, -570.0);
	glVertex3f(200.0, 1090.0, -600.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-200.0, 1090.0, -200.0);
	glVertex3f(-170.0, 1130.0, -230.0);
	glVertex3f(-170.0, 1130.0, -570.0);
	glVertex3f(-200.0, 1090.0, -600.0);
	glEnd();
}

void atap_lantai3() {
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.35, 0.15, 0.15);
	glVertex3f(-250.0, 1160.0, -200.0);
	glVertex3f(-170.0, 1130.0, -230.0);
	glVertex3f(170.0, 1130.0, -230.0);
	glVertex3f(250.0, 1160.0, -200.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-250.0, 1160.0, -600.0);
	glVertex3f(-170.0, 1130.0, -570.0);
	glVertex3f(170.0, 1130.0, -570.0);
	glVertex3f(250.0, 1160.0, -600.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-250.0, 1160.0, -600.0);
	glVertex3f(-250.0, 1160.0, -200.0);
	glVertex3f(250.0, 1160.0, -200.0);
	glVertex3f(250.0, 1160.0, -600.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(250.0, 1160.0, -200.0);
	glVertex3f(170.0, 1130.0, -230.0);
	glVertex3f(170.0, 1130.0, -570.0);
	glVertex3f(250.0, 1160.0, -600.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-250.0, 1160.0, -200.0);
	glVertex3f(-170.0, 1130.0, -230.0);
	glVertex3f(-170.0, 1130.0, -570.0);
	glVertex3f(-250.0, 1160.0, -600.0);
	glEnd();
}

void lantai4() {
	//depan
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-250.0, 1160.0, -200.0);
	glVertex3f(-250.0, 1170.0, -200.0);
	glVertex3f(250.0, 1170.0, -200.0);
	glVertex3f(250.0, 1160.0, -200.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-250.0, 1160.0, -600.0);
	glVertex3f(-250.0, 1170.0, -600.0);
	glVertex3f(250.0, 1170.0, -600.0);
	glVertex3f(250.0, 1160.0, -600.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-250.0, 1170.0, -600.0);
	glVertex3f(-250.0, 1170.0, -200.0);
	glVertex3f(250.0, 1170.0, -200.0);
	glVertex3f(250.0, 1170.0, -600.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(250.0, 1160.0, -200.0);
	glVertex3f(250.0, 1170.0, -200.0);
	glVertex3f(250.0, 1170.0, -600.0);
	glVertex3f(250.0, 1160.0, -600.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-250.0, 1160.0, -200.0);
	glVertex3f(-250.0, 1170.0, -200.0);
	glVertex3f(-250.0, 1170.0, -600.0);
	glVertex3f(-250.0, 1160.0, -600.0);
	glEnd();
}

void karpet4() {
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-130.0, 1170.0, -280.0);
	glVertex3f(-130.0, 1175.0, -280.0);
	glVertex3f(130.0, 1175.0, -280.0);
	glVertex3f(130.0, 1170.0, -280.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-130.0, 1170.0, -520.0);
	glVertex3f(-130.0, 1175.0, -520.0);
	glVertex3f(130.0, 1175.0, -520.0);
	glVertex3f(130.0, 1170.0, -520.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-130.0, 1175.0, -520.0);
	glVertex3f(-130.0, 1175.0, -280.0);
	glVertex3f(130.0, 1175.0, -280.0);
	glVertex3f(130.0, 1175.0, -520.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(130.0, 1170.0, -280.0);
	glVertex3f(130.0, 1175.0, -280.0);
	glVertex3f(130.0, 1175.0, -520.0);
	glVertex3f(130.0, 1170.0, -520.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-130.0, 1170.0, -280.0);
	glVertex3f(-130.0, 1175.0, -280.0);
	glVertex3f(-130.0, 1175.0, -520.0);
	glVertex3f(-130.0, 1170.0, -520.0);
	glEnd();
}

void ruang4() {
		//depan
	glBegin(GL_POLYGON);
	glColor3f(0.92, 0.88, 0.8);
	glVertex3f(-120.0, 1175.0, -290.0);
	glVertex3f(-120.0, 1300.0, -290.0);
	glVertex3f(120.0, 1300.0, -290.0);
	glVertex3f(120.0, 1175.0, -290.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-120.0, 1175.0, -510.0);
	glVertex3f(-120.0, 1300.0, -510.0);
	glVertex3f(120.0, 1300.0, -510.0);
	glVertex3f(120.0, 1175.0, -510.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-120.0, 1295.0, -510.0);
	glVertex3f(-120.0, 1295.0, -290.0);
	glVertex3f(120.0, 1295.0, -290.0);
	glVertex3f(120.0, 1295.0, -510.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-120.0, 1175.0, -510.0);
	glVertex3f(-120.0, 1175.0, -290.0);
	glVertex3f(120.0, 1175.0, -290.0);
	glVertex3f(120.0, 1175.0, -510.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(120.0, 1175.0, -290.0);
	glVertex3f(120.0, 1300.0, -290.0);
	glVertex3f(120.0, 1300.0, -510.0);
	glVertex3f(120.0, 1175.0, -510.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-120.0, 1175.0, -290.0);
	glVertex3f(-120.0, 1300.0, -290.0);
	glVertex3f(-120.0, 1300.0, -510.0);
	glVertex3f(-120.0, 1175.0, -510.0);
	glEnd();
}

void cagak_ruang4() {
		//pintu
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-15.0, 1175.0, -289.0);
	glVertex3f(-15.0, 1225.0, -289.0);
	glVertex3f(15.0, 1225.0, -289.0);
	glVertex3f(15.0, 1175.0, -289.0);
	glEnd();
		//luaran pintu
	//samping kiri pintu
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-15.0, 1175.0, -280.0);
	glVertex3f(-15.0, 1225.0, -280.0);
	glVertex3f(-20.0, 1225.0, -280.0);
	glVertex3f(-20.0, 1175.0, -280.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-15.0, 1175.0, -290.0);
	glVertex3f(-15.0, 1225.0, -290.0);
	glVertex3f(-15.0, 1225.0, -280.0);
	glVertex3f(-15.0, 1175.0, -280.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-20.0, 1175.0, -290.0);
	glVertex3f(-20.0, 1230.0, -290.0);
	glVertex3f(-20.0, 1230.0, -280.0);
	glVertex3f(-20.0, 1175.0, -280.0);
	glEnd();
		//samping kanan pintu
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(15.0, 1175.0, -280.0);
	glVertex3f(15.0, 1225.0, -280.0);
	glVertex3f(20.0, 1225.0, -280.0);
	glVertex3f(20.0, 1175.0, -280.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(15.0, 1175.0, -290.0);
	glVertex3f(15.0, 1225.0, -290.0);
	glVertex3f(15.0, 1225.0, -280.0);
	glVertex3f(15.0, 1175.0, -280.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(20.0, 1175.0, -290.0);
	glVertex3f(20.0, 1230.0, -290.0);
	glVertex3f(20.0, 1230.0, -280.0);
	glVertex3f(20.0, 1175.0, -280.0);
	glEnd();
		//samping atas pintu
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(20.0, 1225.0, -280.0);
	glVertex3f(20.0, 1230.0, -280.0);
	glVertex3f(-20.0, 1230.0, -280.0);
	glVertex3f(-20.0, 1225.0, -280.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(20.0, 1230.0, -280.0);
	glVertex3f(20.0, 1230.0, -290.0);
	glVertex3f(-20.0, 1230.0, -290.0);
	glVertex3f(-20.0, 1230.0, -280.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(20.0, 1225.0, -280.0);
	glVertex3f(20.0, 1230.0, -290.0);
	glVertex3f(-20.0, 1230.0, -290.0);
	glVertex3f(-20.0, 1225.0, -280.0);
	glEnd();
}

void atap4 () {
	//bawah
	glBegin(GL_POLYGON);
	//glColor3f(0.35, 0.15, 0.15);
	glColor3f(0.47, 0.19, 0.19);
	glVertex3f(-250.0, 1300.0, -200.0);
	glVertex3f(-250.0, 1300.0, -600.0);
	glVertex3f(250.0, 1300.0, -600.0);
	glVertex3f(250.0, 1300.0, -200.0);
	glEnd();
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.47, 0.19, 0.19);
	glVertex3f(-250.0, 1300.0, -200.0);
	glVertex3f(-150.0, 1330.0, -250.0);
	glVertex3f(150.0, 1330.0, -250.0);
	glVertex3f(250.0, 1300.0, -200.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-250.0, 1300.0, -600.0);
	glVertex3f(-150.0, 1330.0, -550.0);
	glVertex3f(150.0, 1330.0, -550.0);
	glVertex3f(250.0, 1300.0, -600.0);
	glEnd();
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-150.0, 1330.0, -250.0);
	glVertex3f(-150.0, 1330.0, -550.0);
	glVertex3f(150.0, 1330.0, -550.0);
	glVertex3f(150.0, 1330.0, -250.0);
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(250.0, 1300.0, -200.0);
	glVertex3f(150.0, 1330.0, -250.0);
	glVertex3f(150.0, 1330.0, -550.0);
	glVertex3f(250.0, 1300.0, -600.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-250.0, 1300.0, -200.0);
	glVertex3f(-150.0, 1330.0, -250.0);
	glVertex3f(-150.0, 1330.0, -550.0);
	glVertex3f(-250.0, 1300.0, -600.0);
	glEnd();
	
	//tingkat 2
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.47, 0.19, 0.19);
	glVertex3f(-150.0, 1330.0, -250.0);
	glVertex3f(-100.0, 1360.0, -280.0);
	glVertex3f(100.0, 1360.0, -280.0);
	glVertex3f(150.0, 1330.0, -250.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-150.0, 1330.0, -550.0);
	glVertex3f(-100.0, 1360.0, -520.0);
	glVertex3f(100.0, 1360.0, -520.0);
	glVertex3f(150.0, 1330.0, -550.0);
	glEnd();	
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-150.0, 1330.0, -250.0);
	glVertex3f(-150.0, 1330.0, -550.0);
	glVertex3f(150.0, 1330.0, -550.0);
	glVertex3f(150.0, 1330.0, -250.0);
	glEnd();
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-100.0, 1360.0, -280.0);
	glVertex3f(-100.0, 1360.0, -520.0);
	glVertex3f(100.0, 1360.0, -520.0);
	glVertex3f(100.0, 1360.0, -280.0);
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(150.0, 1330.0, -250.0);
	glVertex3f(100.0, 1360.0, -280.0);
	glVertex3f(100.0, 1360.0, -520.0);
	glVertex3f(150.0, 1330.0, -550.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-150.0, 1330.0, -250.0);
	glVertex3f(-100.0, 1360.0, -280.0);
	glVertex3f(-100.0, 1360.0, -520.0);
	glVertex3f(-150.0, 1330.0, -550.0);
	glEnd();
	
	//tingkat 3
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.47, 0.19, 0.19);
	glVertex3f(-100.0, 1360.0, -280.0);
	glVertex3f(-60.0, 1390.0, -310.0);
	glVertex3f(60.0, 1390.0, -310.0);
	glVertex3f(100.0, 1360.0, -280.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-100.0, 1360.0, -520.0);
	glVertex3f(-60.0, 1390.0, -490.0);
	glVertex3f(60.0, 1390.0, -490.0);
	glVertex3f(100.0, 1360.0, -520.0);
	glEnd();	
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-100.0, 1360.0, -280.0);
	glVertex3f(-100.0, 1360.0, -520.0);
	glVertex3f(100.0, 1360.0, -520.0);
	glVertex3f(100.0, 1360.0, -280.0);
	glEnd();
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-60.0, 1390.0, -310.0);
	glVertex3f(-60.0, 1390.0, -490.0);
	glVertex3f(60.0, 1390.0, -490.0);
	glVertex3f(60.0, 1390.0, -310.0);
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(100.0, 1360.0, -280.0);
	glVertex3f(60.0, 1390.0, -310.0);
	glVertex3f(60.0, 1390.0, -490.0);
	glVertex3f(100.0, 1360.0, -520.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-100.0, 1360.0, -280.0);
	glVertex3f(-60.0, 1390.0, -310.0);
	glVertex3f(-60.0, 1390.0, -490.0);
	glVertex3f(-100.0, 1360.0, -520.0);
	glEnd();
	
		//tingkat 4
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.47, 0.19, 0.19);
	glVertex3f(-60.0, 1390.0, -310.0);
	glVertex3f(-30.0, 1420.0, -340.0);
	glVertex3f(30.0, 1420.0, -340.0);
	glVertex3f(60.0, 1390.0, -310.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-60.0, 1390.0, -490.0);
	glVertex3f(-30.0, 1420.0, -460.0);
	glVertex3f(30.0, 1420.0, -460.0);
	glVertex3f(60.0, 1390.0, -490.0);
	glEnd();	
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-60.0, 1390.0, -310.0);
	glVertex3f(-60.0, 1390.0, -490.0);
	glVertex3f(60.0, 1390.0, -490.0);
	glVertex3f(60.0, 1390.0, -310.0);
	glEnd();
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-30.0, 1420.0, -340.0);
	glVertex3f(-30.0, 1420.0, -460.0);
	glVertex3f(30.0, 1420.0, -460.0);
	glVertex3f(30.0, 1420.0, -340.0);
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(60.0, 1390.0, -310.0);
	glVertex3f(30.0, 1420.0, -340.0);
	glVertex3f(30.0, 1420.0, -460.0);
	glVertex3f(60.0, 1390.0, -490.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-60.0, 1390.0, -310.0);
	glVertex3f(-30.0, 1420.0, -340.0);
	glVertex3f(-30.0, 1420.0, -460.0);
	glVertex3f(-60.0, 1390.0, -490.0);
	glEnd();
}

void antena() {
	glPushMatrix();
	glColor3f(1.0, 0.81, 0.3);
	glTranslatef(0.0, 1420.0, -400.0);
	glRotatef(90.0, -1.0, 0.0, 0.0);
	glutSolidCone(15.0, 300.0, 20, 20);
	glPopMatrix();
}

void tangga() {
		//TANGGA 1
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.31, 0.29, 0.29);
	glVertex3f(-200.0, 0.0 , 70.0);
	glVertex3f(-200.0, 100.0, 70.0);
	glVertex3f(200.0, 100.0, 70.0);
	glVertex3f(200.0, 0.0, 70.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glColor3f(0.18, 0.16, 0.16);
	glVertex3f(200.0, 0.0, 70.0);
	glVertex3f(200.0, 100.0, 70.0);
	glVertex3f(200.0, 100.0, 50.0);
	glVertex3f(200.0, 0.0, 50.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	//glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-200.0, 0.0, 70.0);
	glVertex3f(-200.0, 100.0, 70.0);
	glVertex3f(-200.0, 100.0, 50.0);
	glVertex3f(-200.0, 0.0, 50.0);
	glEnd();
	//atas
	glBegin(GL_POLYGON);
	glColor3f(0.18, 0.16, 0.16);
	glVertex3f(-200.0, 100.0, 50.0);
	glVertex3f(-200.0, 100.0, 70.0);
	glVertex3f(200.0, 100.0, 70.0);
	glVertex3f(200.0, 100.0, 50.0);
	glEnd();
		//TANGGA 2
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.31, 0.29, 0.29);
	glVertex3f(-200.0, 0.0 , 90.0);
	glVertex3f(-200.0, 80.0, 90.0);
	glVertex3f(200.0, 80.0, 90.0);
	glVertex3f(200.0, 0.0, 90.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glColor3f(0.18, 0.16, 0.16);
	glVertex3f(200.0, 0.0, 90.0);
	glVertex3f(200.0, 80.0, 90.0);
	glVertex3f(200.0, 80.0, 70.0);
	glVertex3f(200.0, 0.0, 70.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	//glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-200.0, 0.0, 90.0);
	glVertex3f(-200.0, 80.0, 90.0);
	glVertex3f(-200.0, 80.0, 70.0);
	glVertex3f(-200.0, 0.0, 70.0);
	glEnd();
	//atas
	glBegin(GL_POLYGON);
	glColor3f(0.18, 0.16, 0.16);
	glVertex3f(-200.0, 80.0, 70.0);
	glVertex3f(-200.0, 80.0, 90.0);
	glVertex3f(200.0, 80.0, 90.0);
	glVertex3f(200.0, 80.0, 70.0);
	glEnd();
		//TANGGA 3
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.31, 0.29, 0.29);
	glVertex3f(-200.0, 0.0 , 110.0);
	glVertex3f(-200.0, 60.0, 110.0);
	glVertex3f(200.0, 60.0, 110.0);
	glVertex3f(200.0, 0.0, 110.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glColor3f(0.18, 0.16, 0.16);
	glVertex3f(200.0, 0.0, 110.0);
	glVertex3f(200.0, 60.0, 110.0);
	glVertex3f(200.0, 60.0, 90.0);
	glVertex3f(200.0, 0.0, 90.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	//glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-200.0, 0.0, 110.0);
	glVertex3f(-200.0, 60.0, 110.0);
	glVertex3f(-200.0, 60.0, 90.0);
	glVertex3f(-200.0, 0.0, 90.0);
	glEnd();
	//atas
	glBegin(GL_POLYGON);
	glColor3f(0.18, 0.16, 0.16);
	glVertex3f(-200.0, 60.0, 90.0);
	glVertex3f(-200.0, 60.0, 110.0);
	glVertex3f(200.0, 60.0, 110.0);
	glVertex3f(200.0, 60.0, 90.0);
	glEnd();
		//TANGGA 4
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.31, 0.29, 0.29);
	glVertex3f(-200.0, 0.0 , 130.0);
	glVertex3f(-200.0, 40.0, 130.0);
	glVertex3f(200.0, 40.0, 130.0);
	glVertex3f(200.0, 0.0, 130.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glColor3f(0.18, 0.16, 0.16);
	glVertex3f(200.0, 0.0, 130.0);
	glVertex3f(200.0, 40.0, 130.0);
	glVertex3f(200.0, 40.0, 110.0);
	glVertex3f(200.0, 0.0, 110.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	//glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-200.0, 0.0, 130.0);
	glVertex3f(-200.0, 40.0, 130.0);
	glVertex3f(-200.0, 40.0, 110.0);
	glVertex3f(-200.0, 0.0, 110.0);
	glEnd();
	//atas
	glBegin(GL_POLYGON);
	glColor3f(0.18, 0.16, 0.16);
	glVertex3f(-200.0, 40.0, 110.0);
	glVertex3f(-200.0, 40.0, 130.0);
	glVertex3f(200.0, 40.0, 130.0);
	glVertex3f(200.0, 40.0, 110.0);
	glEnd();
		//TANGGA 5
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.31, 0.29, 0.29);
	glVertex3f(-200.0, 0.0 , 150.0);
	glVertex3f(-200.0, 20.0, 150.0);
	glVertex3f(200.0, 20.0, 150.0);
	glVertex3f(200.0, 0.0, 150.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glColor3f(0.18, 0.16, 0.16);
	glVertex3f(200.0, 0.0, 150.0);
	glVertex3f(200.0, 20.0, 150.0);
	glVertex3f(200.0, 20.0, 130.0);
	glVertex3f(200.0, 0.0, 130.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	//glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-200.0, 0.0, 150.0);
	glVertex3f(-200.0, 20.0, 150.0);
	glVertex3f(-200.0, 20.0, 130.0);
	glVertex3f(-200.0, 0.0, 130.0);
	glEnd();
	//atas
	glBegin(GL_POLYGON);
	glColor3f(0.18, 0.16, 0.16);
	glVertex3f(-200.0, 20.0, 130.0);
	glVertex3f(-200.0, 20.0, 150.0);
	glVertex3f(200.0, 20.0, 150.0);
	glVertex3f(200.0, 20.0, 130.0);
	glEnd();
}

void jalan() {
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.62, 0.62, 0.62);
	glVertex3f(-200.0, 0.0, 150.0);
	glVertex3f(-200.0, 5.0, 150.0);
	glVertex3f(200.0, 5.0, 150.0);
	glVertex3f(200.0, 0.0, 150.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-200.0, 0.0, 1500.0);
	glVertex3f(-200.0, 5.0, 1500.0);
	glVertex3f(200.0, 5.0, 1500.0);
	glVertex3f(200.0, 0.0, 1500.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-200.0, 5.0, 1500.0);
	glVertex3f(-200.0, 5.0, 150.0);
	glVertex3f(200.0, 5.0, 150.0);
	glVertex3f(200.0, 5.0, 1500.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-200.0, 0.0, 1500.0);
	glVertex3f(-200.0, 0.0, 150.0);
	glVertex3f(200.0, 0.0, 150.0);
	glVertex3f(200.0, 0.0, 1500.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(200.0, 0.0, 150.0);
	glVertex3f(200.0, 5.0, 150.0);
	glVertex3f(200.0, 5.0, 1500.0);
	glVertex3f(200.0, 0.0, 1500.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-200.0, 0.0, 150.0);
	glVertex3f(-200.0, 5.0, 150.0);
	glVertex3f(-200.0, 5.0, 1500.0);
	glVertex3f(-200.0, 0.0, 1500.0);
	glEnd();
}

void jalan2() {
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.62, 0.62, 0.62);
	glVertex3f(-1200.0, 0.0, 800.0);
	glVertex3f(-1200.0, 5.0, 800.0);
	glVertex3f(1200.0, 5.0, 800.0);
	glVertex3f(1200.0, 0.0, 800.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-1200.0, 0.0, -1260.0);
	glVertex3f(-1200.0, 5.0, -1260.0);
	glVertex3f(1200.0, 5.0, -1260.0);
	glVertex3f(1200.0, 0.0, -1260.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-1200.0, 5.0, -1260.0);
	glVertex3f(-1200.0, 5.0, 800.0);
	glVertex3f(1200.0, 5.0, 800.0);
	glVertex3f(1200.0, 5.0, -1260.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-1200.0, 0.0, -1260.0);
	glVertex3f(-1200.0, 0.0, 800.0);
	glVertex3f(1200.0, 0.0, 800.0);
	glVertex3f(1200.0, 0.0, -1260.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(1200.0, 0.0, 800.0);
	glVertex3f(1200.0, 5.0, 800.0);
	glVertex3f(1200.0, 5.0, -1260.0);
	glVertex3f(1200.0, 0.0, -1260.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-1200.0, 0.0, 800.0);
	glVertex3f(-1200.0, 5.0, 800.0);
	glVertex3f(-1200.0, 5.0, -1260.0);
	glVertex3f(-1200.0, 0.0, -1260.0);
	glEnd();
}

void gapura() {
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.72, 0.06, 0.04);
	glVertex3f(-250.0, 0.0, 1550.0);
	glVertex3f(-250.0, 500.0, 1550.0);
	glVertex3f(-200.0, 500.0, 1550.0);
	glVertex3f(-200.0, 0.0, 1550.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-250.0, 0.0, 1500.0);
	glVertex3f(-250.0, 500.0, 1500.0);
	glVertex3f(-200.0, 500.0, 1500.0);
	glVertex3f(-200.0, 0.0, 1500.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-250.0, 500.0, 1500.0);
	glVertex3f(-250.0, 500.0, 1550.0);
	glVertex3f(-200.0, 500.0, 1550.0);
	glVertex3f(-200.0, 500.0, 1500.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-200.0, 0.0, 1550.0);
	glVertex3f(-200.0, 500.0, 1550.0);
	glVertex3f(-200.0, 500.0, 1500.0);
	glVertex3f(-200.0, 0.0, 1500.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-250.0, 0.0, 1550.0);
	glVertex3f(-250.0, 500.0, 1550.0);
	glVertex3f(-250.0, 500.0, 1500.0);
	glVertex3f(-250.0, 0.0, 1500.0);
	glEnd();
}

void gapura1() {
	glBegin(GL_POLYGON);
	glColor3f(0.72, 0.06, 0.04);
	glVertex3f(250.0, 0.0, 1550.0);
	glVertex3f(250.0, 500.0, 1550.0);
	glVertex3f(200.0, 500.0, 1550.0);
	glVertex3f(200.0, 0.0, 1550.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(250.0, 0.0, 1500.0);
	glVertex3f(250.0, 500.0, 1500.0);
	glVertex3f(200.0, 500.0, 1500.0);
	glVertex3f(200.0, 0.0, 1500.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(250.0, 500.0, 1500.0);
	glVertex3f(250.0, 500.0, 1550.0);
	glVertex3f(200.0, 500.0, 1550.0);
	glVertex3f(200.0, 500.0, 1500.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(200.0, 0.0, 1550.0);
	glVertex3f(200.0, 500.0, 1550.0);
	glVertex3f(200.0, 500.0, 1500.0);
	glVertex3f(200.0, 0.0, 1500.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(250.0, 0.0, 1550.0);
	glVertex3f(250.0, 500.0, 1550.0);
	glVertex3f(250.0, 500.0, 1500.0);
	glVertex3f(250.0, 0.0, 1500.0);
	glEnd();

}

void atasgpr(){

	glBegin(GL_POLYGON);
	glColor3f(0.72, 0.06, 0.04);
	glVertex3f(-350.0, 390.0, 1550.0);
	glVertex3f(-350.0, 370.0, 1550.0);
	glVertex3f(350.0, 370.0, 1550.0);
	glVertex3f(350.0, 390.0, 1550.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-350.0, 390.0, 1500.0);
	glVertex3f(-350.0, 370.0, 1500.0);
	glVertex3f(350.0, 370.0, 1500.0);
	glVertex3f(350.0, 390.0, 1500.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-350.0, 370.0, 1500.0);
	glVertex3f(-350.0, 370.0, 1550.0);
	glVertex3f(350.0, 370.0, 1550.0);
	glVertex3f(350.0, 370.0, 1500.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(350.0, 390.0, 1550.0);
	glVertex3f(350.0, 370.0, 1550.0);
	glVertex3f(350.0, 370.0, 1500.0);
	glVertex3f(350.0, 390.0, 1500.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-350.0, 390.0, 1550.0);
	glVertex3f(-350.0, 370.0, 1550.0);
	glVertex3f(-350.0, 370.0, 1500.0);
	glVertex3f(-350.0, 390.0, 1500.0);
	glEnd();

}

void atasgpr1(){

	glBegin(GL_POLYGON);
	glColor3f(0.72, 0.06, 0.04);
	glVertex3f(-320.0, 400.0, 1550.0);
	glVertex3f(-320.0, 390.0, 1550.0);
	glVertex3f(320.0, 390.0, 1550.0);
	glVertex3f(320.0, 400.0, 1550.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-320.0, 400.0, 1500.0);
	glVertex3f(-320.0, 390.0, 1500.0);
	glVertex3f(320.0, 390.0, 1500.0);
	glVertex3f(320.0, 400.0, 1500.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-320.0, 390.0, 1500.0);
	glVertex3f(-320.0, 390.0, 1550.0);
	glVertex3f(320.0, 390.0, 1550.0);
	glVertex3f(320.0, 390.0, 1500.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(320.0, 400.0, 1550.0);
	glVertex3f(320.0, 390.0, 1550.0);
	glVertex3f(320.0, 390.0, 1500.0);
	glVertex3f(320.0, 400.0, 1500.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-320.0, 400.0, 1550.0);
	glVertex3f(-320.0, 390.0, 1550.0);
	glVertex3f(-320.0, 390.0, 1500.0);
	glVertex3f(-320.0, 400.0, 1500.0);
	glEnd();

}

void atasgpr2(){

	glBegin(GL_POLYGON);
	glColor3f(0.72, 0.06, 0.04);
	glVertex3f(-300.0, 410.0, 1550.0);
	glVertex3f(-300.0, 400.0, 1550.0);
	glVertex3f(300.0, 400.0, 1550.0);
	glVertex3f(300.0, 410.0, 1550.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-300.0, 410.0, 1500.0);
	glVertex3f(-300.0, 400.0, 1500.0);
	glVertex3f(300.0, 400.0, 1500.0);
	glVertex3f(300.0, 410.0, 1500.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-300.0, 400.0, 1500.0);
	glVertex3f(-300.0, 400.0, 1550.0);
	glVertex3f(300.0, 400.0, 1550.0);
	glVertex3f(300.0, 400.0, 1500.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(300.0, 410.0, 1550.0);
	glVertex3f(300.0, 400.0, 1550.0);
	glVertex3f(300.0, 400.0, 1500.0);
	glVertex3f(300.0, 410.0, 1500.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-300.0, 410.0, 1550.0);
	glVertex3f(-300.0, 400.0, 1550.0);
	glVertex3f(-300.0, 400.0, 1500.0);
	glVertex3f(-300.0, 410.0, 1500.0);
	glEnd();

}

void pucukgpr(){

	glBegin(GL_POLYGON);
	glColor3f(0.72, 0.06, 0.04);
	glVertex3f(-400.0, 510.0, 1550.0);
	glVertex3f(-400.0, 500.0, 1550.0);
	glVertex3f(400.0, 500.0, 1550.0);
	glVertex3f(400.0, 510.0, 1550.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-400.0, 510.0, 1500.0);
	glVertex3f(-400.0, 500.0, 1500.0);
	glVertex3f(400.0, 500.0, 1500.0);
	glVertex3f(400.0, 510.0, 1500.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-400.0, 500.0, 1500.0);
	glVertex3f(-400.0, 500.0, 1550.0);
	glVertex3f(400.0, 500.0, 1550.0);
	glVertex3f(400.0, 500.0, 1500.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(400.0, 510.0, 1550.0);
	glVertex3f(400.0, 500.0, 1550.0);
	glVertex3f(400.0, 500.0, 1500.0);
	glVertex3f(400.0, 510.0, 1500.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-400.0, 510.0, 1550.0);
	glVertex3f(-400.0, 500.0, 1550.0);
	glVertex3f(-400.0, 500.0, 1500.0);
	glVertex3f(-400.0, 510.0, 1500.0);
	glEnd();

}

void atap_gpr() {
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.72, 0.06, 0.04);
	glVertex3f(-450.0, 560.0, 1460.0);
	glVertex3f(-360.0, 500.0, 1500.0);
	glVertex3f(360.0, 500.0, 1500.0);
	glVertex3f(450.0, 560.0, 1460.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-450.0, 560.0, 1590.0);
	glVertex3f(-360.0, 500.0, 1550.0);
	glVertex3f(360.0, 500.0, 1550.0);
	glVertex3f(450.0, 560.0, 1590.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-450.0, 560.0, 1590.0);
	glVertex3f(-450.0, 560.0, 1460.0);
	glVertex3f(450.0, 560.0, 1460.0);
	glVertex3f(450.0, 560.0, 1590.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-360.0, 500.0, 1550.0);
	glVertex3f(-360.0, 500.0, 1500.0);
	glVertex3f(360.0, 500.0, 1500.0);
	glVertex3f(360.0, 500.0, 1550.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(450.0, 560.0, 1460.0);
	glVertex3f(360.0, 500.0, 1500.0);
	glVertex3f(360.0, 500.0, 1550.0);
	glVertex3f(450.0, 560.0, 1590.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-450.0, 560.0, 1460.0);
	glVertex3f(-360.0, 500.0, 1500.0);
	glVertex3f(-360.0, 500.0, 1550.0);
	glVertex3f(-450.0, 560.0, 1590.0);
	glEnd();

}

void kendi(){
	glPushMatrix();
	glTranslatef(350.0, 150.0, 1570.0);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidSphere(60.0, 70, 70);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(350.0, 210.0, 1570.0);
	glutSolidSphere(45.0, 60, 60);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(350.0, 250.0, 1570.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glColor3f(1.0, 0.81, 0.3);
	glutSolidTorus(10.0, 20.0, 20, 20);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(350.0, 270.0, 1570.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	gluCylinder(gluNewQuadric(), 20.0f, 20.0f, 20.0f, 32, 32);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(350.0, 50.0, 1570.0);
	glutSolidCube(120.0);
	glPopMatrix();	
}
void lamp() {
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(450.0, 470.0, -102.0);
	glVertex3f(450.0, 412.0, -100.0);
	glVertex3f(448.0, 412.0, -100.0);
	glVertex3f(448.0, 470.0, -102.0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(450.0, 470.0, -698.0);
	glVertex3f(450.0, 412.0, -700.0);
	glVertex3f(448.0, 412.0, -700.0);
	glVertex3f(448.0, 470.0, -698.0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-450.0, 470.0, -698.0);
	glVertex3f(-450.0, 412.0, -700.0);
	glVertex3f(-448.0, 412.0, -700.0);
	glVertex3f(-448.0, 470.0, -698.0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-450.0, 470.0, -102.0);
	glVertex3f(-450.0, 412.0, -100.0);
	glVertex3f(-448.0, 412.0, -100.0);
	glVertex3f(-448.0, 470.0, -102.0);
	glEnd();
}

void lampion(){
	glPushMatrix();
	glTranslatef(449.0, 432.0, -101.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	gluCylinder(gluNewQuadric(), 1.0f, 1.0f, 44.0f, 32, 32);
	glPopMatrix();
	
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(449.0, 390.0, -101.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glutSolidSphere(20.0, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(449.0, 412.0, -101.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 0.0);
	gluCylinder(gluNewQuadric(), 5.0f, 5.0f, 5.0f, 32, 32);
	glPopMatrix();	
	
	glPushMatrix();
	glTranslatef(449.0, 372.0, -101.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 0.0);
	gluCylinder(gluNewQuadric(), 5.0f, 5.0f, 5.0f, 32, 32);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(449.0, 372.0, -101.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 0.0);
	gluCylinder(gluNewQuadric(), 1.0f, 1.0f, 44.0f, 32, 32);
	glPopMatrix();
}


void pagar1() {
	//SATU
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-680.0, 100.0, 30.0);
	glVertex3f(-680.0, 200.0, 30.0);
	glVertex3f(-650.0, 200.0, 30.0);
	glVertex3f(-650.0, 100.0, 30.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-680.0, 100.0, 10.0);
	glVertex3f(-680.0, 200.0, 10.0);
	glVertex3f(-650.0, 200.0, 10.0);
	glVertex3f(-650.0, 100.0, 10.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-680.0, 200.0, 10.0);
	glVertex3f(-680.0, 200.0, 30.0);
	glVertex3f(-650.0, 200.0, 30.0);
	glVertex3f(-650.0, 200.0, 10.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-680.0, 100.0, 30.0);
	glVertex3f(-680.0, 200.0, 30.0);
	glVertex3f(-680.0, 200.0, 10.0);
	glVertex3f(-680.0, 100.0, 10.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-650.0, 100.0, 30.0);
	glVertex3f(-650.0, 200.0, 30.0);
	glVertex3f(-650.0, 200.0, 10.0);
	glVertex3f(-650.0, 100.0, 10.0);
	glEnd();
	
	//SATU a (samping)
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-219.0, 100.0, 30.0);
	glVertex3f(-219.0, 200.0, 30.0);
	glVertex3f(-190.0, 200.0, 30.0);
	glVertex3f(-190.0, 100.0, 30.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-219.0, 100.0, 10.0);
	glVertex3f(-219.0, 200.0, 10.0);
	glVertex3f(-190.0, 200.0, 10.0);
	glVertex3f(-190.0, 100.0, 10.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-219.0, 200.0, 10.0);
	glVertex3f(-219.0, 200.0, 30.0);
	glVertex3f(-190.0, 200.0, 30.0);
	glVertex3f(-190.0, 200.0, 10.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-219.0, 100.0, 30.0);
	glVertex3f(-219.0, 200.0, 30.0);
	glVertex3f(-219.0, 200.0, 10.0);
	glVertex3f(-219.0, 100.0, 10.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-190.0, 100.0, 30.0);
	glVertex3f(-190.0, 200.0, 30.0);
	glVertex3f(-190.0, 200.0, 10.0);
	glVertex3f(-190.0, 100.0, 10.0);
	glEnd();
	
	//SATU b (samping)
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-420.0, 100.0, 30.0);
	glVertex3f(-420.0, 200.0, 30.0);
	glVertex3f(-390.0, 200.0, 30.0);
	glVertex3f(-390.0, 100.0, 30.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-420.0, 100.0, 10.0);
	glVertex3f(-420.0, 200.0, 10.0);
	glVertex3f(-390.0, 200.0, 10.0);
	glVertex3f(-390.0, 100.0, 10.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-420.0, 200.0, 10.0);
	glVertex3f(-420.0, 200.0, 30.0);
	glVertex3f(-390.0, 200.0, 30.0);
	glVertex3f(-390.0, 200.0, 10.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-420.0, 100.0, 30.0);
	glVertex3f(-420.0, 200.0, 30.0);
	glVertex3f(-420.0, 200.0, 10.0);
	glVertex3f(-420.0, 100.0, 10.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-390.0, 100.0, 30.0);
	glVertex3f(-390.0, 200.0, 30.0);
	glVertex3f(-390.0, 200.0, 10.0);
	glVertex3f(-390.0, 100.0, 10.0);
	glEnd();
	
	//SATU c (samping)
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-219.0, 0.0, 180.0);
	glVertex3f(-219.0, 100.0, 180.0);
	glVertex3f(-190.0, 100.0, 180.0);
	glVertex3f(-190.0, 0.0, 180.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-219.0, 0.0, 150.0);
	glVertex3f(-219.0, 100.0, 150.0);
	glVertex3f(-190.0, 100.0, 150.0);
	glVertex3f(-190.0, 0.0, 150.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-219.0, 100.0, 150.0);
	glVertex3f(-219.0, 100.0, 180.0);
	glVertex3f(-190.0, 100.0, 180.0);
	glVertex3f(-190.0, 100.0, 150.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-190.0, 0.0, 180.0);
	glVertex3f(-190.0, 100.0, 180.0);
	glVertex3f(-190.0, 100.0, 150.0);
	glVertex3f(-190.0, 0.0, 150.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-219.0, 0.0, 180.0);
	glVertex3f(-219.0, 100.0, 180.0);
	glVertex3f(-219.0, 100.0, 150.0);
	glVertex3f(-219.0, 0.0, 150.0);
	glEnd();
	
	//SATU d
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-680.0, 100.0, -230.0);
	glVertex3f(-680.0, 200.0, -230.0);
	glVertex3f(-650.0, 200.0, -230.0);
	glVertex3f(-650.0, 100.0, -230.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-680.0, 100.0, -210.0);
	glVertex3f(-680.0, 200.0, -210.0);
	glVertex3f(-650.0, 200.0, -210.0);
	glVertex3f(-650.0, 100.0, -210.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-680.0, 200.0, -210.0);
	glVertex3f(-680.0, 200.0, -230.0);
	glVertex3f(-650.0, 200.0, -230.0);
	glVertex3f(-650.0, 200.0, -210.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-680.0, 100.0, -230.0);
	glVertex3f(-680.0, 200.0, -230.0);
	glVertex3f(-680.0, 200.0, -210.0);
	glVertex3f(-680.0, 100.0, -210.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-650.0, 100.0, -230.0);
	glVertex3f(-650.0, 200.0, -230.0);
	glVertex3f(-650.0, 200.0, -210.0);
	glVertex3f(-650.0, 100.0, -210.0);
	glEnd();
	
	//SATU e
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-680.0, 100.0, -430.0);
	glVertex3f(-680.0, 200.0, -430.0);
	glVertex3f(-650.0, 200.0, -430.0);
	glVertex3f(-650.0, 100.0, -430.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-680.0, 100.0, -410.0);
	glVertex3f(-680.0, 200.0, -410.0);
	glVertex3f(-650.0, 200.0, -410.0);
	glVertex3f(-650.0, 100.0, -410.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-680.0, 200.0, -410.0);
	glVertex3f(-680.0, 200.0, -430.0);
	glVertex3f(-650.0, 200.0, -430.0);
	glVertex3f(-650.0, 200.0, -410.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-680.0, 100.0, -430.0);
	glVertex3f(-680.0, 200.0, -430.0);
	glVertex3f(-680.0, 200.0, -410.0);
	glVertex3f(-680.0, 100.0, -410.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-650.0, 100.0, -430.0);
	glVertex3f(-650.0, 200.0, -430.0);
	glVertex3f(-650.0, 200.0, -410.0);
	glVertex3f(-650.0, 100.0, -410.0);
	glEnd();
	
	//SATU f
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-680.0, 100.0, -630.0);
	glVertex3f(-680.0, 200.0, -630.0);
	glVertex3f(-650.0, 200.0, -630.0);
	glVertex3f(-650.0, 100.0, -630.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-680.0, 100.0, -610.0);
	glVertex3f(-680.0, 200.0, -610.0);
	glVertex3f(-650.0, 200.0, -610.0);
	glVertex3f(-650.0, 100.0, -610.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-680.0, 200.0, -610.0);
	glVertex3f(-680.0, 200.0, -630.0);
	glVertex3f(-650.0, 200.0, -630.0);
	glVertex3f(-650.0, 200.0, -610.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-680.0, 100.0, -630.0);
	glVertex3f(-680.0, 200.0, -630.0);
	glVertex3f(-680.0, 200.0, -610.0);
	glVertex3f(-680.0, 100.0, -610.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-650.0, 100.0, -630.0);
	glVertex3f(-650.0, 200.0, -630.0);
	glVertex3f(-650.0, 200.0, -610.0);
	glVertex3f(-650.0, 100.0, -610.0);
	glEnd();
	
	//DUA
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(680.0, 100.0, 30.0);
	glVertex3f(680.0, 200.0, 30.0);
	glVertex3f(650.0, 200.0, 30.0);
	glVertex3f(650.0, 100.0, 30.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(680.0, 100.0, 10.0);
	glVertex3f(680.0, 200.0, 10.0);
	glVertex3f(650.0, 200.0, 10.0);
	glVertex3f(650.0, 100.0, 10.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(680.0, 200.0, 10.0);
	glVertex3f(680.0, 200.0, 30.0);
	glVertex3f(650.0, 200.0, 30.0);
	glVertex3f(650.0, 200.0, 10.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(680.0, 100.0, 30.0);
	glVertex3f(680.0, 200.0, 30.0);
	glVertex3f(680.0, 200.0, 10.0);
	glVertex3f(680.0, 100.0, 10.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(650.0, 100.0, 30.0);
	glVertex3f(650.0, 200.0, 30.0);
	glVertex3f(650.0, 200.0, 10.0);
	glVertex3f(650.0, 100.0, 10.0);
	glEnd();
	
	//DUA a (samping)
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(219.0, 100.0, 30.0);
	glVertex3f(219.0, 200.0, 30.0);
	glVertex3f(190.0, 200.0, 30.0);
	glVertex3f(190.0, 100.0, 30.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(219.0, 100.0, 10.0);
	glVertex3f(219.0, 200.0, 10.0);
	glVertex3f(190.0, 200.0, 10.0);
	glVertex3f(190.0, 100.0, 10.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(219.0, 200.0, 10.0);
	glVertex3f(219.0, 200.0, 30.0);
	glVertex3f(190.0, 200.0, 30.0);
	glVertex3f(190.0, 200.0, 10.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(219.0, 100.0, 30.0);
	glVertex3f(219.0, 200.0, 30.0);
	glVertex3f(219.0, 200.0, 10.0);
	glVertex3f(219.0, 100.0, 10.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(190.0, 100.0, 30.0);
	glVertex3f(190.0, 200.0, 30.0);
	glVertex3f(190.0, 200.0, 10.0);
	glVertex3f(190.0, 100.0, 10.0);
	glEnd();
	
	//DUA b (samping)
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(420.0, 100.0, 30.0);
	glVertex3f(420.0, 200.0, 30.0);
	glVertex3f(390.0, 200.0, 30.0);
	glVertex3f(390.0, 100.0, 30.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(420.0, 100.0, 10.0);
	glVertex3f(420.0, 200.0, 10.0);
	glVertex3f(390.0, 200.0, 10.0);
	glVertex3f(390.0, 100.0, 10.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(420.0, 200.0, 10.0);
	glVertex3f(420.0, 200.0, 30.0);
	glVertex3f(390.0, 200.0, 30.0);
	glVertex3f(390.0, 200.0, 10.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(420.0, 100.0, 30.0);
	glVertex3f(420.0, 200.0, 30.0);
	glVertex3f(420.0, 200.0, 10.0);
	glVertex3f(420.0, 100.0, 10.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(390.0, 100.0, 30.0);
	glVertex3f(390.0, 200.0, 30.0);
	glVertex3f(390.0, 200.0, 10.0);
	glVertex3f(390.0, 100.0, 10.0);
	glEnd();
	
	//DUA c (samping)
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(219.0, 0.0, 180.0);
	glVertex3f(219.0, 100.0, 180.0);
	glVertex3f(190.0, 100.0, 180.0);
	glVertex3f(190.0, 0.0, 180.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(219.0, 0.0, 150.0);
	glVertex3f(219.0, 100.0, 150.0);
	glVertex3f(190.0, 100.0, 150.0);
	glVertex3f(190.0, 0.0, 150.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(219.0, 100.0, 150.0);
	glVertex3f(219.0, 100.0, 180.0);
	glVertex3f(190.0, 100.0, 180.0);
	glVertex3f(190.0, 100.0, 150.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(219.0, 0.0, 180.0);
	glVertex3f(219.0, 100.0, 180.0);
	glVertex3f(219.0, 100.0, 150.0);
	glVertex3f(219.0, 0.0, 150.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(190.0, 0.0, 180.0);
	glVertex3f(190.0, 100.0, 180.0);
	glVertex3f(190.0, 100.0, 150.0);
	glVertex3f(190.0, 0.0, 150.0);
	glEnd();
	
	//DUA d
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(680.0, 100.0, -230.0);
	glVertex3f(680.0, 200.0, -230.0);
	glVertex3f(650.0, 200.0, -230.0);
	glVertex3f(650.0, 100.0, -230.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(680.0, 100.0, -210.0);
	glVertex3f(680.0, 200.0, -210.0);
	glVertex3f(650.0, 200.0, -210.0);
	glVertex3f(650.0, 100.0, -210.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(680.0, 200.0, -210.0);
	glVertex3f(680.0, 200.0, -230.0);
	glVertex3f(650.0, 200.0, -230.0);
	glVertex3f(650.0, 200.0, -210.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(680.0, 100.0, -230.0);
	glVertex3f(680.0, 200.0, -230.0);
	glVertex3f(680.0, 200.0, -210.0);
	glVertex3f(680.0, 100.0, -210.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(650.0, 100.0, -230.0);
	glVertex3f(650.0, 200.0, -230.0);
	glVertex3f(650.0, 200.0, -210.0);
	glVertex3f(650.0, 100.0, -210.0);
	glEnd();
	
	//DUA e
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(680.0, 100.0, -430.0);
	glVertex3f(680.0, 200.0, -430.0);
	glVertex3f(650.0, 200.0, -430.0);
	glVertex3f(650.0, 100.0, -430.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(680.0, 100.0, -410.0);
	glVertex3f(680.0, 200.0, -410.0);
	glVertex3f(650.0, 200.0, -410.0);
	glVertex3f(650.0, 100.0, -410.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(680.0, 200.0, -410.0);
	glVertex3f(680.0, 200.0, -430.0);
	glVertex3f(650.0, 200.0, -430.0);
	glVertex3f(650.0, 200.0, -410.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(680.0, 100.0, -430.0);
	glVertex3f(680.0, 200.0, -430.0);
	glVertex3f(680.0, 200.0, -410.0);
	glVertex3f(680.0, 100.0, -410.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(650.0, 100.0, -430.0);
	glVertex3f(650.0, 200.0, -430.0);
	glVertex3f(650.0, 200.0, -410.0);
	glVertex3f(650.0, 100.0, -410.0);
	glEnd();
	
	//DUA f
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(680.0, 100.0, -630.0);
	glVertex3f(680.0, 200.0, -630.0);
	glVertex3f(650.0, 200.0, -630.0);
	glVertex3f(650.0, 100.0, -630.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(680.0, 100.0, -610.0);
	glVertex3f(680.0, 200.0, -610.0);
	glVertex3f(650.0, 200.0, -610.0);
	glVertex3f(650.0, 100.0, -610.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(680.0, 200.0, -610.0);
	glVertex3f(680.0, 200.0, -630.0);
	glVertex3f(650.0, 200.0, -630.0);
	glVertex3f(650.0, 200.0, -610.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(680.0, 100.0, -630.0);
	glVertex3f(680.0, 200.0, -630.0);
	glVertex3f(680.0, 200.0, -610.0);
	glVertex3f(680.0, 100.0, -610.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(650.0, 100.0, -630.0);
	glVertex3f(650.0, 200.0, -630.0);
	glVertex3f(650.0, 200.0, -610.0);
	glVertex3f(650.0, 100.0, -610.0);
	glEnd();
	
	//TIGA
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(680.0, 100.0, -830.0);
	glVertex3f(680.0, 200.0, -830.0);
	glVertex3f(650.0, 200.0, -830.0);
	glVertex3f(650.0, 100.0, -830.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(680.0, 100.0, -810.0);
	glVertex3f(680.0, 200.0, -810.0);
	glVertex3f(650.0, 200.0, -810.0);
	glVertex3f(650.0, 100.0, -810.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(680.0, 200.0, -810.0);
	glVertex3f(680.0, 200.0, -830.0);
	glVertex3f(650.0, 200.0, -830.0);
	glVertex3f(650.0, 200.0, -810.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(680.0, 100.0, -830.0);
	glVertex3f(680.0, 200.0, -830.0);
	glVertex3f(680.0, 200.0, -810.0);
	glVertex3f(680.0, 100.0, -810.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(650.0, 100.0, -830.0);
	glVertex3f(650.0, 200.0, -830.0);
	glVertex3f(650.0, 200.0, -810.0);
	glVertex3f(650.0, 100.0, -810.0);
	glEnd();
	
	//TIGA a
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(420.0, 100.0, -830.0);
	glVertex3f(420.0, 200.0, -830.0);
	glVertex3f(390.0, 200.0, -830.0);
	glVertex3f(390.0, 100.0, -830.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(420.0, 100.0, -810.0);
	glVertex3f(420.0, 200.0, -810.0);
	glVertex3f(390.0, 200.0, -810.0);
	glVertex3f(390.0, 100.0, -810.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(420.0, 200.0, -810.0);
	glVertex3f(420.0, 200.0, -830.0);
	glVertex3f(390.0, 200.0, -830.0);
	glVertex3f(390.0, 200.0, -810.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(420.0, 100.0, -830.0);
	glVertex3f(420.0, 200.0, -830.0);
	glVertex3f(420.0, 200.0, -810.0);
	glVertex3f(420.0, 100.0, -810.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(390.0, 100.0, -830.0);
	glVertex3f(390.0, 200.0, -830.0);
	glVertex3f(390.0, 200.0, -810.0);
	glVertex3f(390.0, 100.0, -810.0);
	glEnd();
	
	//TIGA b
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(180.0, 100.0, -830.0);
	glVertex3f(180.0, 200.0, -830.0);
	glVertex3f(150.0, 200.0, -830.0);
	glVertex3f(150.0, 100.0, -830.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(180.0, 100.0, -810.0);
	glVertex3f(180.0, 200.0, -810.0);
	glVertex3f(150.0, 200.0, -810.0);
	glVertex3f(150.0, 100.0, -810.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(180.0, 200.0, -810.0);
	glVertex3f(180.0, 200.0, -830.0);
	glVertex3f(150.0, 200.0, -830.0);
	glVertex3f(150.0, 200.0, -810.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(180.0, 100.0, -830.0);
	glVertex3f(180.0, 200.0, -830.0);
	glVertex3f(180.0, 200.0, -810.0);
	glVertex3f(180.0, 100.0, -810.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(150.0, 100.0, -830.0);
	glVertex3f(150.0, 200.0, -830.0);
	glVertex3f(150.0, 200.0, -810.0);
	glVertex3f(150.0, 100.0, -810.0);
	glEnd();
	
	
	//EMPAT a
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-680.0, 100.0, -830.0);
	glVertex3f(-680.0, 200.0, -830.0);
	glVertex3f(-650.0, 200.0, -830.0);
	glVertex3f(-650.0, 100.0, -830.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-680.0, 100.0, -810.0);
	glVertex3f(-680.0, 200.0, -810.0);
	glVertex3f(-650.0, 200.0, -810.0);
	glVertex3f(-650.0, 100.0, -810.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-680.0, 200.0, -810.0);
	glVertex3f(-680.0, 200.0, -830.0);
	glVertex3f(-650.0, 200.0, -830.0);
	glVertex3f(-650.0, 200.0, -810.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-680.0, 100.0, -830.0);
	glVertex3f(-680.0, 200.0, -830.0);
	glVertex3f(-680.0, 200.0, -810.0);
	glVertex3f(-680.0, 100.0, -810.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-650.0, 100.0, -830.0);
	glVertex3f(-650.0, 200.0, -830.0);
	glVertex3f(-650.0, 200.0, -810.0);
	glVertex3f(-650.0, 100.0, -810.0);
	glEnd();
	
	//EMPAT b
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-420.0, 100.0, -830.0);
	glVertex3f(-420.0, 200.0, -830.0);
	glVertex3f(-390.0, 200.0, -830.0);
	glVertex3f(-390.0, 100.0, -830.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-420.0, 100.0, -810.0);
	glVertex3f(-420.0, 200.0, -810.0);
	glVertex3f(-390.0, 200.0, -810.0);
	glVertex3f(-390.0, 100.0, -810.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-420.0, 200.0, -810.0);
	glVertex3f(-420.0, 200.0, -830.0);
	glVertex3f(-390.0, 200.0, -830.0);
	glVertex3f(-390.0, 200.0, -810.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-420.0, 100.0, -830.0);
	glVertex3f(-420.0, 200.0, -830.0);
	glVertex3f(-420.0, 200.0, -810.0);
	glVertex3f(-420.0, 100.0, -810.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-390.0, 100.0, -830.0);
	glVertex3f(-390.0, 200.0, -830.0);
	glVertex3f(-390.0, 200.0, -810.0);
	glVertex3f(-390.0, 100.0, -810.0);
	glEnd();
	
	//EMPAT c
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-180.0, 100.0, -830.0);
	glVertex3f(-180.0, 200.0, -830.0);
	glVertex3f(-150.0, 200.0, -830.0);
	glVertex3f(-150.0, 100.0, -830.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-180.0, 100.0, -810.0);
	glVertex3f(-180.0, 200.0, -810.0);
	glVertex3f(-150.0, 200.0, -810.0);
	glVertex3f(-150.0, 100.0, -810.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-180.0, 200.0, -810.0);
	glVertex3f(-180.0, 200.0, -830.0);
	glVertex3f(-150.0, 200.0, -830.0);
	glVertex3f(-150.0, 200.0, -810.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-180.0, 100.0, -830.0);
	glVertex3f(-180.0, 200.0, -830.0);
	glVertex3f(-180.0, 200.0, -810.0);
	glVertex3f(-180.0, 100.0, -810.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-150.0, 100.0, -830.0);
	glVertex3f(-150.0, 200.0, -830.0);
	glVertex3f(-150.0, 200.0, -810.0);
	glVertex3f(-150.0, 100.0, -810.0);
	glEnd();
	
	//HORIZONTAL 1 atas
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-650.0, 185.0, -815.0);
	glVertex3f(-650.0, 190.0, -815.0);
	glVertex3f(650.0, 190.0, -815.0);
	glVertex3f(650.0, 185.0, -815.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-650.0, 190.0, -825.0);
	glVertex3f(-650.0, 185.0, -825.0);
	glVertex3f(650.0, 185.0, -825.0);
	glVertex3f(650.0, 190.0, -825.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-650.0, 190.0, -815.0);
	glVertex3f(-650.0, 190.0, -825.0);
	glVertex3f(650.0, 190.0, -825.0);
	glVertex3f(650.0, 190.0, -815.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-650.0, 185.0, -815.0);
	glVertex3f(-650.0, 185.0, -825.0);
	glVertex3f(650.0, 185.0, -825.0);
	glVertex3f(650.0, 185.0, -815.0);
	glEnd();
	
	//HORIZONTAL 1 tengah
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-650.0, 145.0, -815.0);
	glVertex3f(-650.0, 150.0, -815.0);
	glVertex3f(650.0, 150.0, -815.0);
	glVertex3f(650.0, 145.0, -815.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-650.0, 150.0, -825.0);
	glVertex3f(-650.0, 145.0, -825.0);
	glVertex3f(650.0, 145.0, -825.0);
	glVertex3f(650.0, 150.0, -825.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-650.0, 150.0, -815.0);
	glVertex3f(-650.0, 150.0, -825.0);
	glVertex3f(650.0, 150.0, -825.0);
	glVertex3f(650.0, 150.0, -815.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-650.0, 145.0, -815.0);
	glVertex3f(-650.0, 145.0, -825.0);
	glVertex3f(650.0, 145.0, -825.0);
	glVertex3f(650.0, 145.0, -815.0);
	glEnd();
	
	//HORIZONTAL 1 bawah
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-650.0, 100.0, -815.0);
	glVertex3f(-650.0, 105.0, -815.0);
	glVertex3f(650.0, 105.0, -815.0);
	glVertex3f(650.0, 100.0, -815.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-650.0, 105.0, -825.0);
	glVertex3f(-650.0, 100.0, -825.0);
	glVertex3f(650.0, 100.0, -825.0);
	glVertex3f(650.0, 105.0, -825.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-650.0, 105.0, -815.0);
	glVertex3f(-650.0, 105.0, -825.0);
	glVertex3f(650.0, 105.0, -825.0);
	glVertex3f(650.0, 105.0, -815.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-650.0, 100.0, -815.0);
	glVertex3f(-650.0, 100.0, -825.0);
	glVertex3f(650.0, 100.0, -825.0);
	glVertex3f(650.0, 100.0, -815.0);
	glEnd();
	
	//HORIZONTAL 2 a atas (kanan)
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(190.0, 185.0, 15.0);
	glVertex3f(190.0, 190.0, 15.0);
	glVertex3f(680.0, 190.0, 15.0);
	glVertex3f(680.0, 185.0, 15.0);
	glEnd();	
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(190.0, 190.0, 25.0);
	glVertex3f(190.0, 185.0, 25.0);
	glVertex3f(680.0, 185.0, 25.0);
	glVertex3f(680.0, 190.0, 25.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(190.0, 190.0, 15.0);
	glVertex3f(190.0, 190.0, 25.0);
	glVertex3f(680.0, 190.0, 25.0);
	glVertex3f(680.0, 190.0, 15.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(190.0, 185.0, 15.0);
	glVertex3f(190.0, 185.0, 25.0);
	glVertex3f(680.0, 185.0, 25.0);
	glVertex3f(680.0, 185.0, 15.0);
	glEnd();
	
	//HORIZONTAL 2 b tengah (kanan)
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(190.0, 145.0, 15.0);
	glVertex3f(190.0, 150.0, 15.0);
	glVertex3f(680.0, 150.0, 15.0);
	glVertex3f(680.0, 145.0, 15.0);
	glEnd();	
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(190.0, 150.0, 25.0);
	glVertex3f(190.0, 145.0, 25.0);
	glVertex3f(680.0, 145.0, 25.0);
	glVertex3f(680.0, 150.0, 25.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(190.0, 150.0, 15.0);
	glVertex3f(190.0, 150.0, 25.0);
	glVertex3f(680.0, 150.0, 25.0);
	glVertex3f(680.0, 150.0, 15.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(190.0, 145.0, 15.0);
	glVertex3f(190.0, 145.0, 25.0);
	glVertex3f(680.0, 145.0, 25.0);
	glVertex3f(680.0, 145.0, 15.0);
	glEnd();
	
	//HORIZONTAL 2 c bawah (kanan)
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(190.0, 100.0, 15.0);
	glVertex3f(190.0, 105.0, 15.0);
	glVertex3f(680.0, 105.0, 15.0);
	glVertex3f(680.0, 100.0, 15.0);
	glEnd();	
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(190.0, 105.0, 25.0);
	glVertex3f(190.0, 100.0, 25.0);
	glVertex3f(680.0, 100.0, 25.0);
	glVertex3f(680.0, 105.0, 25.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(190.0, 105.0, 15.0);
	glVertex3f(190.0, 105.0, 25.0);
	glVertex3f(680.0, 105.0, 25.0);
	glVertex3f(680.0, 105.0, 15.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(190.0, 100.0, 15.0);
	glVertex3f(190.0, 100.0, 25.0);
	glVertex3f(680.0, 100.0, 25.0);
	glVertex3f(680.0, 100.0, 15.0);
	glEnd();
	
	//HORIZONTAL 3 a atas (kiri)
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-190.0, 185.0, 15.0);
	glVertex3f(-190.0, 190.0, 15.0);
	glVertex3f(-680.0, 190.0, 15.0);
	glVertex3f(-680.0, 185.0, 15.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-190.0, 190.0, 25.0);
	glVertex3f(-190.0, 185.0, 25.0);
	glVertex3f(-680.0, 185.0, 25.0);
	glVertex3f(-680.0, 190.0, 25.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-190.0, 190.0, 15.0);
	glVertex3f(-190.0, 190.0, 25.0);
	glVertex3f(-680.0, 190.0, 25.0);
	glVertex3f(-680.0, 190.0, 15.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-190.0, 185.0, 15.0);
	glVertex3f(-190.0, 185.0, 25.0);
	glVertex3f(-680.0, 185.0, 25.0);
	glVertex3f(-680.0, 185.0, 15.0);
	glEnd();
	
	//HORIZONTAL 3 b tengah (kiri)
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-190.0, 145.0, 15.0);
	glVertex3f(-190.0, 150.0, 15.0);
	glVertex3f(-680.0, 150.0, 15.0);
	glVertex3f(-680.0, 145.0, 15.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-190.0, 150.0, 25.0);
	glVertex3f(-190.0, 145.0, 25.0);
	glVertex3f(-680.0, 145.0, 25.0);
	glVertex3f(-680.0, 150.0, 25.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-190.0, 150.0, 15.0);
	glVertex3f(-190.0, 150.0, 25.0);
	glVertex3f(-680.0, 150.0, 25.0);
	glVertex3f(-680.0, 150.0, 15.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-190.0, 145.0, 15.0);
	glVertex3f(-190.0, 145.0, 25.0);
	glVertex3f(-680.0, 145.0, 25.0);
	glVertex3f(-680.0, 145.0, 15.0);
	glEnd();
	
	//HORIZONTAL 3 c bawah (kiri)
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-190.0, 100.0, 15.0);
	glVertex3f(-190.0, 105.0, 15.0);
	glVertex3f(-680.0, 105.0, 15.0);
	glVertex3f(-680.0, 100.0, 15.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-190.0, 105.0, 25.0);
	glVertex3f(-190.0, 100.0, 25.0);
	glVertex3f(-680.0, 100.0, 25.0);
	glVertex3f(-680.0, 105.0, 25.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-190.0, 105.0, 15.0);
	glVertex3f(-190.0, 105.0, 25.0);
	glVertex3f(-680.0, 105.0, 25.0);
	glVertex3f(-680.0, 105.0, 15.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-190.0, 100.0, 15.0);
	glVertex3f(-190.0, 100.0, 25.0);
	glVertex3f(-680.0, 100.0, 25.0);
	glVertex3f(-680.0, 100.0, 15.0);
	glEnd();
	
	//HORIZONTAL 4 kiri a
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-670.0, 185.0, -830.0);
	glVertex3f(-670.0, 190.0, -830.0);
	glVertex3f(-670.0, 190.0, 30.0);
	glVertex3f(-670.0, 185.0, 30.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-660.0, 190.0, -830.0);
	glVertex3f(-660.0, 185.0, -830.0);
	glVertex3f(-660.0, 185.0, 30.0);
	glVertex3f(-660.0, 190.0, 30.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-670.0, 190.0, -830.0);
	glVertex3f(-670.0, 190.0, 30.0);
	glVertex3f(-660.0, 190.0, 30.0);
	glVertex3f(-660.0, 190.0, -830.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-670.0, 185.0, -830.0);
	glVertex3f(-670.0, 185.0, 30.0);
	glVertex3f(-660.0, 185.0, 30.0);
	glVertex3f(-660.0, 185.0, -830.0);
	glEnd();
	
	//HORIZONTAL 4 kiri b
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-670.0, 145.0, -830.0);
	glVertex3f(-670.0, 150.0, -830.0);
	glVertex3f(-670.0, 150.0, 30.0);
	glVertex3f(-670.0, 145.0, 30.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-660.0, 150.0, -830.0);
	glVertex3f(-660.0, 145.0, -830.0);
	glVertex3f(-660.0, 145.0, 30.0);
	glVertex3f(-660.0, 150.0, 30.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-670.0, 150.0, -830.0);
	glVertex3f(-670.0, 150.0, 30.0);
	glVertex3f(-660.0, 150.0, 30.0);
	glVertex3f(-660.0, 150.0, -830.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-670.0, 145.0, -830.0);
	glVertex3f(-670.0, 145.0, 30.0);
	glVertex3f(-660.0, 145.0, 30.0);
	glVertex3f(-660.0, 145.0, -830.0);
	glEnd();
	
	//HORIZONTAL 4 kiri c
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-670.0, 100.0, -830.0);
	glVertex3f(-670.0, 105.0, -830.0);
	glVertex3f(-670.0, 105.0, 30.0);
	glVertex3f(-670.0, 100.0, 30.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-660.0, 105.0, -830.0);
	glVertex3f(-660.0, 100.0, -830.0);
	glVertex3f(-660.0, 100.0, 30.0);
	glVertex3f(-660.0, 105.0, 30.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-670.0, 105.0, -830.0);
	glVertex3f(-670.0, 105.0, 30.0);
	glVertex3f(-660.0, 105.0, 30.0);
	glVertex3f(-660.0, 105.0, -830.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-670.0, 100.0, -830.0);
	glVertex3f(-670.0, 100.0, 30.0);
	glVertex3f(-660.0, 100.0, 30.0);
	glVertex3f(-660.0, 100.0, -830.0);
	glEnd();
	
	//HORIZONTAL 5 kanan a
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(670.0, 185.0, -830.0);
	glVertex3f(670.0, 190.0, -830.0);
	glVertex3f(670.0, 190.0, 30.0);
	glVertex3f(670.0, 185.0, 30.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(660.0, 190.0, -830.0);
	glVertex3f(660.0, 185.0, -830.0);
	glVertex3f(660.0, 185.0, 30.0);
	glVertex3f(660.0, 190.0, 30.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(670.0, 190.0, -830.0);
	glVertex3f(670.0, 190.0, 30.0);
	glVertex3f(660.0, 190.0, 30.0);
	glVertex3f(660.0, 190.0, -830.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(670.0, 185.0, -830.0);
	glVertex3f(670.0, 185.0, 30.0);
	glVertex3f(660.0, 185.0, 30.0);
	glVertex3f(660.0, 185.0, -830.0);
	glEnd();
	
	//HORIZONTAL 5 kanan b
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(670.0, 145.0, -830.0);
	glVertex3f(670.0, 150.0, -830.0);
	glVertex3f(670.0, 150.0, 30.0);
	glVertex3f(670.0, 145.0, 30.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(660.0, 150.0, -830.0);
	glVertex3f(660.0, 145.0, -830.0);
	glVertex3f(660.0, 145.0, 30.0);
	glVertex3f(660.0, 150.0, 30.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(670.0, 150.0, -830.0);
	glVertex3f(670.0, 150.0, 30.0);
	glVertex3f(660.0, 150.0, 30.0);
	glVertex3f(660.0, 150.0, -830.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(670.0, 145.0, -830.0);
	glVertex3f(670.0, 145.0, 30.0);
	glVertex3f(660.0, 145.0, 30.0);
	glVertex3f(660.0, 145.0, -830.0);
	glEnd();
	
	//HORIZONTAL 5 kanan c
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(670.0, 100.0, -830.0);
	glVertex3f(670.0, 105.0, -830.0);
	glVertex3f(670.0, 105.0, 30.0);
	glVertex3f(670.0, 100.0, 30.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(660.0, 105.0, -830.0);
	glVertex3f(660.0, 100.0, -830.0);
	glVertex3f(660.0, 100.0, 30.0);
	glVertex3f(660.0, 105.0, 30.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(670.0, 105.0, -830.0);
	glVertex3f(670.0, 105.0, 30.0);
	glVertex3f(660.0, 105.0, 30.0);
	glVertex3f(660.0, 105.0, -830.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(670.0, 100.0, -830.0);
	glVertex3f(670.0, 100.0, 30.0);
	glVertex3f(660.0, 100.0, 30.0);
	glVertex3f(660.0, 100.0, -830.0);
	glEnd();
	
	//HORIZONTAL 6 (depan kanan)
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(210.0, 65.0, 173.0);
	glVertex3f(210.0, 70.0, 173.0);
	glVertex3f(210.0, 190.0, 30.0);
	glVertex3f(210.0, 185.0, 30.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(200.0, 70.0, 173.0);
	glVertex3f(200.0, 65.0, 173.0);
	glVertex3f(200.0, 185.0, 30.0);
	glVertex3f(200.0, 190.0, 30.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(210.0, 70.0, 173.0);
	glVertex3f(210.0, 190.0, 30.0);
	glVertex3f(200.0, 190.0, 30.0);
	glVertex3f(200.0, 70.0, 173.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(210.0, 65.0, 173.0);
	glVertex3f(210.0, 185.0, 30.0);
	glVertex3f(200.0, 185.0, 30.0);
	glVertex3f(200.0, 65.0, 173.0);
	glEnd();
	
	//HORIZONTAL 6 (depan kiri)
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-210.0, 65.0, 173.0);
	glVertex3f(-210.0, 70.0, 173.0);
	glVertex3f(-210.0, 190.0, 30.0);
	glVertex3f(-210.0, 185.0, 30.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-200.0, 70.0, 173.0);
	glVertex3f(-200.0, 65.0, 173.0);
	glVertex3f(-200.0, 185.0, 30.0);
	glVertex3f(-200.0, 190.0, 30.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-210.0, 70.0, 173.0);
	glVertex3f(-210.0, 190.0, 30.0);
	glVertex3f(-200.0, 190.0, 30.0);
	glVertex3f(-200.0, 70.0, 173.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-210.0, 65.0, 173.0);
	glVertex3f(-210.0, 185.0, 30.0);
	glVertex3f(-200.0, 185.0, 30.0);
	glVertex3f(-200.0, 65.0, 173.0);
	glEnd();
	
}


void pagar2() {
	//SATU a 
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-440.0, 470.0, -110.0);
	glVertex3f(-440.0, 570.0, -110.0);
	glVertex3f(-410.0, 570.0, -110.0);
	glVertex3f(-410.0, 470.0, -110.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-440.0, 470.0, -130.0);
	glVertex3f(-440.0, 570.0, -130.0);
	glVertex3f(-410.0, 570.0, -130.0);
	glVertex3f(-410.0, 470.0, -130.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-440.0, 570.0, -130.0);
	glVertex3f(-440.0, 570.0, -110.0);
	glVertex3f(-410.0, 570.0, -110.0);
	glVertex3f(-410.0, 570.0, -130.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-440.0, 470.0, -110.0);
	glVertex3f(-440.0, 570.0, -110.0);
	glVertex3f(-440.0, 570.0, -130.0);
	glVertex3f(-440.0, 470.0, -130.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-410.0, 470.0, -110.0);
	glVertex3f(-410.0, 570.0, -110.0);
	glVertex3f(-410.0, 570.0, -130.0);
	glVertex3f(-410.0, 470.0, -130.0);
	glEnd();
	
	//SATU b
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-140.0, 470.0, -110.0);
	glVertex3f(-140.0, 570.0, -110.0);
	glVertex3f(-110.0, 570.0, -110.0);
	glVertex3f(-110.0, 470.0, -110.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-140.0, 470.0, -130.0);
	glVertex3f(-140.0, 570.0, -130.0);
	glVertex3f(-110.0, 570.0, -130.0);
	glVertex3f(-110.0, 470.0, -130.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-140.0, 570.0, -130.0);
	glVertex3f(-140.0, 570.0, -110.0);
	glVertex3f(-110.0, 570.0, -110.0);
	glVertex3f(-110.0, 570.0, -130.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-140.0, 470.0, -110.0);
	glVertex3f(-140.0, 570.0, -110.0);
	glVertex3f(-140.0, 570.0, -130.0);
	glVertex3f(-140.0, 470.0, -130.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-110.0, 470.0, -110.0);
	glVertex3f(-110.0, 570.0, -110.0);
	glVertex3f(-110.0, 570.0, -130.0);
	glVertex3f(-110.0, 470.0, -130.0);
	glEnd();
	
	//SATU c 
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-440.0, 470.0, -310.0);
	glVertex3f(-440.0, 570.0, -310.0);
	glVertex3f(-410.0, 570.0, -310.0);
	glVertex3f(-410.0, 470.0, -310.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-440.0, 470.0, -330.0);
	glVertex3f(-440.0, 570.0, -330.0);
	glVertex3f(-410.0, 570.0, -330.0);
	glVertex3f(-410.0, 470.0, -330.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-440.0, 570.0, -330.0);
	glVertex3f(-440.0, 570.0, -310.0);
	glVertex3f(-410.0, 570.0, -310.0);
	glVertex3f(-410.0, 570.0, -330.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-440.0, 470.0, -310.0);
	glVertex3f(-440.0, 570.0, -310.0);
	glVertex3f(-440.0, 570.0, -330.0);
	glVertex3f(-440.0, 470.0, -330.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-410.0, 470.0, -310.0);
	glVertex3f(-410.0, 570.0, -310.0);
	glVertex3f(-410.0, 570.0, -330.0);
	glVertex3f(-410.0, 470.0, -330.0);
	glEnd();
	
	//SATU d 
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-440.0, 470.0, -500.0);
	glVertex3f(-440.0, 570.0, -500.0);
	glVertex3f(-410.0, 570.0, -500.0);
	glVertex3f(-410.0, 470.0, -500.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-440.0, 470.0, -520.0);
	glVertex3f(-440.0, 570.0, -520.0);
	glVertex3f(-410.0, 570.0, -520.0);
	glVertex3f(-410.0, 470.0, -520.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-440.0, 570.0, -520.0);
	glVertex3f(-440.0, 570.0, -500.0);
	glVertex3f(-410.0, 570.0, -500.0);
	glVertex3f(-410.0, 570.0, -520.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-440.0, 470.0, -500.0);
	glVertex3f(-440.0, 570.0, -500.0);
	glVertex3f(-440.0, 570.0, -520.0);
	glVertex3f(-440.0, 470.0, -520.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-410.0, 470.0, -500.0);
	glVertex3f(-410.0, 570.0, -500.0);
	glVertex3f(-410.0, 570.0, -520.0);
	glVertex3f(-410.0, 470.0, -520.0);
	glEnd();
	
	//DUA a
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(440.0, 470.0, -110.0);
	glVertex3f(440.0, 570.0, -110.0);
	glVertex3f(410.0, 570.0, -110.0);
	glVertex3f(410.0, 470.0, -110.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(440.0, 470.0, -130.0);
	glVertex3f(440.0, 570.0, -130.0);
	glVertex3f(410.0, 570.0, -130.0);
	glVertex3f(410.0, 470.0, -130.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(440.0, 570.0, -130.0);
	glVertex3f(440.0, 570.0, -110.0);
	glVertex3f(410.0, 570.0, -110.0);
	glVertex3f(410.0, 570.0, -130.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(440.0, 470.0, -110.0);
	glVertex3f(440.0, 570.0, -110.0);
	glVertex3f(440.0, 570.0, -130.0);
	glVertex3f(440.0, 470.0, -130.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(410.0, 470.0, -110.0);
	glVertex3f(410.0, 570.0, -110.0);
	glVertex3f(410.0, 570.0, -130.0);
	glVertex3f(410.0, 470.0, -130.0);
	glEnd();
	
	//DUA b
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(140.0, 470.0, -110.0);
	glVertex3f(140.0, 570.0, -110.0);
	glVertex3f(110.0, 570.0, -110.0);
	glVertex3f(110.0, 470.0, -110.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(140.0, 470.0, -130.0);
	glVertex3f(140.0, 570.0, -130.0);
	glVertex3f(110.0, 570.0, -130.0);
	glVertex3f(110.0, 470.0, -130.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(140.0, 570.0, -130.0);
	glVertex3f(140.0, 570.0, -110.0);
	glVertex3f(110.0, 570.0, -110.0);
	glVertex3f(110.0, 570.0, -130.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(140.0, 470.0, -110.0);
	glVertex3f(140.0, 570.0, -110.0);
	glVertex3f(140.0, 570.0, -130.0);
	glVertex3f(140.0, 470.0, -130.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(110.0, 470.0, -110.0);
	glVertex3f(110.0, 570.0, -110.0);
	glVertex3f(110.0, 570.0, -130.0);
	glVertex3f(110.0, 470.0, -130.0);
	glEnd();
	
	//DUA c 
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(440.0, 470.0, -310.0);
	glVertex3f(440.0, 570.0, -310.0);
	glVertex3f(410.0, 570.0, -310.0);
	glVertex3f(410.0, 470.0, -310.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(440.0, 470.0, -330.0);
	glVertex3f(440.0, 570.0, -330.0);
	glVertex3f(410.0, 570.0, -330.0);
	glVertex3f(410.0, 470.0, -330.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(440.0, 570.0, -330.0);
	glVertex3f(440.0, 570.0, -310.0);
	glVertex3f(410.0, 570.0, -310.0);
	glVertex3f(410.0, 570.0, -330.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(440.0, 470.0, -310.0);
	glVertex3f(440.0, 570.0, -310.0);
	glVertex3f(440.0, 570.0, -330.0);
	glVertex3f(440.0, 470.0, -330.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(410.0, 470.0, -310.0);
	glVertex3f(410.0, 570.0, -310.0);
	glVertex3f(410.0, 570.0, -330.0);
	glVertex3f(410.0, 470.0, -330.0);
	glEnd();
	
	//DUA d 
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(440.0, 470.0, -500.0);
	glVertex3f(440.0, 570.0, -500.0);
	glVertex3f(410.0, 570.0, -500.0);
	glVertex3f(410.0, 470.0, -500.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(440.0, 470.0, -520.0);
	glVertex3f(440.0, 570.0, -520.0);
	glVertex3f(410.0, 570.0, -520.0);
	glVertex3f(410.0, 470.0, -520.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(440.0, 570.0, -520.0);
	glVertex3f(440.0, 570.0, -500.0);
	glVertex3f(410.0, 570.0, -500.0);
	glVertex3f(410.0, 570.0, -520.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(440.0, 470.0, -500.0);
	glVertex3f(440.0, 570.0, -500.0);
	glVertex3f(440.0, 570.0, -520.0);
	glVertex3f(440.0, 470.0, -520.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(410.0, 470.0, -500.0);
	glVertex3f(410.0, 570.0, -500.0);
	glVertex3f(410.0, 570.0, -520.0);
	glVertex3f(410.0, 470.0, -520.0);
	glEnd();
	
	
	//TIGA a
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(440.0, 470.0, -670.0);
	glVertex3f(440.0, 570.0, -670.0);
	glVertex3f(410.0, 570.0, -670.0);
	glVertex3f(410.0, 470.0, -670.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(440.0, 470.0, -690.0);
	glVertex3f(440.0, 570.0, -690.0);
	glVertex3f(410.0, 570.0, -690.0);
	glVertex3f(410.0, 470.0, -690.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(440.0, 570.0, -690.0);
	glVertex3f(440.0, 570.0, -670.0);
	glVertex3f(410.0, 570.0, -670.0);
	glVertex3f(410.0, 570.0, -690.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(440.0, 470.0, -670.0);
	glVertex3f(440.0, 570.0, -670.0);
	glVertex3f(440.0, 570.0, -690.0);
	glVertex3f(440.0, 470.0, -690.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(410.0, 470.0, -670.0);
	glVertex3f(410.0, 570.0, -670.0);
	glVertex3f(410.0, 570.0, -690.0);
	glVertex3f(410.0, 470.0, -690.0);
	glEnd();
	
	//TIGA b
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(140.0, 470.0, -670.0);
	glVertex3f(140.0, 570.0, -670.0);
	glVertex3f(110.0, 570.0, -670.0);
	glVertex3f(110.0, 470.0, -670.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(140.0, 470.0, -690.0);
	glVertex3f(140.0, 570.0, -690.0);
	glVertex3f(110.0, 570.0, -690.0);
	glVertex3f(110.0, 470.0, -690.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(140.0, 570.0, -690.0);
	glVertex3f(140.0, 570.0, -670.0);
	glVertex3f(110.0, 570.0, -670.0);
	glVertex3f(110.0, 570.0, -690.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(140.0, 470.0, -670.0);
	glVertex3f(140.0, 570.0, -670.0);
	glVertex3f(140.0, 570.0, -690.0);
	glVertex3f(140.0, 470.0, -690.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(110.0, 470.0, -670.0);
	glVertex3f(110.0, 570.0, -670.0);
	glVertex3f(110.0, 570.0, -690.0);
	glVertex3f(110.0, 470.0, -690.0);
	glEnd();
	
	//EMPAT a
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-440.0, 470.0, -670.0);
	glVertex3f(-440.0, 570.0, -670.0);
	glVertex3f(-410.0, 570.0, -670.0);
	glVertex3f(-410.0, 470.0, -670.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-440.0, 470.0, -690.0);
	glVertex3f(-440.0, 570.0, -690.0);
	glVertex3f(-410.0, 570.0, -690.0);
	glVertex3f(-410.0, 470.0, -690.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-440.0, 570.0, -690.0);
	glVertex3f(-440.0, 570.0, -670.0);
	glVertex3f(-410.0, 570.0, -670.0);
	glVertex3f(-410.0, 570.0, -690.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-440.0, 470.0, -670.0);
	glVertex3f(-440.0, 570.0, -670.0);
	glVertex3f(-440.0, 570.0, -690.0);
	glVertex3f(-440.0, 470.0, -690.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-410.0, 470.0, -670.0);
	glVertex3f(-410.0, 570.0, -670.0);
	glVertex3f(-410.0, 570.0, -690.0);
	glVertex3f(-410.0, 470.0, -690.0);
	glEnd();
	
	//EMPAT b
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-140.0, 470.0, -670.0);
	glVertex3f(-140.0, 570.0, -670.0);
	glVertex3f(-110.0, 570.0, -670.0);
	glVertex3f(-110.0, 470.0, -670.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-140.0, 470.0, -690.0);
	glVertex3f(-140.0, 570.0, -690.0);
	glVertex3f(-110.0, 570.0, -690.0);
	glVertex3f(-110.0, 470.0, -690.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-140.0, 570.0, -690.0);
	glVertex3f(-140.0, 570.0, -670.0);
	glVertex3f(-110.0, 570.0, -670.0);
	glVertex3f(-110.0, 570.0, -690.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-140.0, 470.0, -670.0);
	glVertex3f(-140.0, 570.0, -670.0);
	glVertex3f(-140.0, 570.0, -690.0);
	glVertex3f(-140.0, 470.0, -690.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-110.0, 470.0, -670.0);
	glVertex3f(-110.0, 570.0, -670.0);
	glVertex3f(-110.0, 570.0, -690.0);
	glVertex3f(-110.0, 470.0, -690.0);
	glEnd();
	
	//HORIZONTAL 1 atas
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-410.0, 565.0, -685.0);
	glVertex3f(-410.0, 570.0, -685.0);
	glVertex3f(410.0, 570.0, -685.0);
	glVertex3f(410.0, 565.0, -685.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-410.0, 570.0, -675.0);
	glVertex3f(-410.0, 565.0, -675.0);
	glVertex3f(410.0, 565.0, -675.0);
	glVertex3f(410.0, 570.0, -675.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-410.0, 570.0, -685.0);
	glVertex3f(-410.0, 570.0, -675.0);
	glVertex3f(410.0, 570.0, -675.0);
	glVertex3f(410.0, 570.0, -685.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-410.0, 565.0, -685.0);
	glVertex3f(-410.0, 565.0, -675.0);
	glVertex3f(410.0, 565.0, -675.0);
	glVertex3f(410.0, 565.0, -685.0);
	glEnd();
	
	//HORIZONTAL 1 bawah
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-410.0, 470.0, -685.0);
	glVertex3f(-410.0, 475.0, -685.0);
	glVertex3f(410.0, 475.0, -685.0);
	glVertex3f(410.0, 470.0, -685.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-410.0, 475.0, -675.0);
	glVertex3f(-410.0, 470.0, -675.0);
	glVertex3f(410.0, 470.0, -675.0);
	glVertex3f(410.0, 475.0, -675.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-410.0, 475.0, -685.0);
	glVertex3f(-410.0, 475.0, -675.0);
	glVertex3f(410.0, 475.0, -675.0);
	glVertex3f(410.0, 475.0, -685.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-410.0, 470.0, -685.0);
	glVertex3f(-410.0, 470.0, -675.0);
	glVertex3f(410.0, 470.0, -675.0);
	glVertex3f(410.0, 470.0, -685.0);
	glEnd();
	
	//HORIZONTAL 2 atas
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-410.0, 565.0, -115.0);
	glVertex3f(-410.0, 570.0, -115.0);
	glVertex3f(410.0, 570.0, -115.0);
	glVertex3f(410.0, 565.0, -115.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-410.0, 570.0, -125.0);
	glVertex3f(-410.0, 565.0, -125.0);
	glVertex3f(410.0, 565.0, -125.0);
	glVertex3f(410.0, 570.0, -125.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-410.0, 570.0, -115.0);
	glVertex3f(-410.0, 570.0, -125.0);
	glVertex3f(410.0, 570.0, -125.0);
	glVertex3f(410.0, 570.0, -115.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-410.0, 565.0, -115.0);
	glVertex3f(-410.0, 565.0, -125.0);
	glVertex3f(410.0, 565.0, -125.0);
	glVertex3f(410.0, 565.0, -115.0);
	glEnd();
	
	//HORIZONTAL 2 bawah
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-410.0, 470.0, -115.0);
	glVertex3f(-410.0, 475.0, -115.0);
	glVertex3f(410.0, 475.0, -115.0);
	glVertex3f(410.0, 470.0, -115.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-410.0, 475.0, -125.0);
	glVertex3f(-410.0, 470.0, -125.0);
	glVertex3f(410.0, 470.0, -125.0);
	glVertex3f(410.0, 475.0, -125.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-410.0, 475.0, -115.0);
	glVertex3f(-410.0, 475.0, -125.0);
	glVertex3f(410.0, 475.0, -125.0);
	glVertex3f(410.0, 475.0, -115.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-410.0, 470.0, -115.0);
	glVertex3f(-410.0, 470.0, -125.0);
	glVertex3f(410.0, 470.0, -125.0);
	glVertex3f(410.0, 470.0, -115.0);
	glEnd();
	
	//HORIZONTAL 3 atas
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-430.0, 565.0, -110.0);
	glVertex3f(-430.0, 570.0, -110.0);
	glVertex3f(-430.0, 570.0, -670.0);
	glVertex3f(-430.0, 565.0, -670.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-420.0, 570.0, -110.0);
	glVertex3f(-420.0, 565.0, -110.0);
	glVertex3f(-420.0, 565.0, -670.0);
	glVertex3f(-420.0, 570.0, -670.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-430.0, 570.0, -110.0);
	glVertex3f(-430.0, 570.0, -670.0);
	glVertex3f(-420.0, 570.0, -670.0);
	glVertex3f(-420.0, 570.0, -110.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-430.0, 565.0, -110.0);
	glVertex3f(-430.0, 565.0, -670.0);
	glVertex3f(-420.0, 565.0, -670.0);
	glVertex3f(-420.0, 565.0, -110.0);
	glEnd();
	
	//HORIZONTAL 3 bawah
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-430.0, 470.0, -110.0);
	glVertex3f(-430.0, 475.0, -110.0);
	glVertex3f(-430.0, 475.0, -670.0);
	glVertex3f(-430.0, 470.0, -670.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-420.0, 475.0, -110.0);
	glVertex3f(-420.0, 470.0, -110.0);
	glVertex3f(-420.0, 470.0, -670.0);
	glVertex3f(-420.0, 475.0, -670.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-430.0, 475.0, -110.0);
	glVertex3f(-430.0, 475.0, -670.0);
	glVertex3f(-420.0, 475.0, -670.0);
	glVertex3f(-420.0, 475.0, -110.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-430.0, 470.0, -110.0);
	glVertex3f(-430.0, 470.0, -670.0);
	glVertex3f(-420.0, 470.0, -670.0);
	glVertex3f(-420.0, 470.0, -110.0);
	glEnd();
	
	//HORIZONTAL 4 atas
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(430.0, 565.0, -110.0);
	glVertex3f(430.0, 570.0, -110.0);
	glVertex3f(430.0, 570.0, -670.0);
	glVertex3f(430.0, 565.0, -670.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(420.0, 570.0, -110.0);
	glVertex3f(420.0, 565.0, -110.0);
	glVertex3f(420.0, 565.0, -670.0);
	glVertex3f(420.0, 570.0, -670.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(430.0, 570.0, -110.0);
	glVertex3f(430.0, 570.0, -670.0);
	glVertex3f(420.0, 570.0, -670.0);
	glVertex3f(420.0, 570.0, -110.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(430.0, 565.0, -110.0);
	glVertex3f(430.0, 565.0, -670.0);
	glVertex3f(420.0, 565.0, -670.0);
	glVertex3f(420.0, 565.0, -110.0);
	glEnd();
	
	//HORIZONTAL 4 bawah
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(430.0, 470.0, -110.0);
	glVertex3f(430.0, 475.0, -110.0);
	glVertex3f(430.0, 475.0, -670.0);
	glVertex3f(430.0, 470.0, -670.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(420.0, 475.0, -110.0);
	glVertex3f(420.0, 470.0, -110.0);
	glVertex3f(420.0, 470.0, -670.0);
	glVertex3f(420.0, 475.0, -670.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(430.0, 475.0, -110.0);
	glVertex3f(430.0, 475.0, -670.0);
	glVertex3f(420.0, 475.0, -670.0);
	glVertex3f(420.0, 475.0, -110.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(430.0, 470.0, -110.0);
	glVertex3f(430.0, 470.0, -670.0);
	glVertex3f(420.0, 470.0, -670.0);
	glVertex3f(420.0, 470.0, -110.0);
	glEnd();
}



	void pagar3() {
	//SATU a
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-290.0, 840.0, -160.0);
	glVertex3f(-290.0, 910.0, -160.0);
	glVertex3f(-260.0, 910.0, -160.0);
	glVertex3f(-260.0, 840.0, -160.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-290.0, 840.0, -180.0);
	glVertex3f(-290.0, 910.0, -180.0);
	glVertex3f(-260.0, 910.0, -180.0);
	glVertex3f(-260.0, 840.0, -180.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-290.0, 910.0, -180.0);
	glVertex3f(-290.0, 910.0, -160.0);
	glVertex3f(-260.0, 910.0, -160.0);
	glVertex3f(-260.0, 910.0, -180.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-290.0, 840.0, -160.0);
	glVertex3f(-290.0, 910.0, -160.0);
	glVertex3f(-290.0, 910.0, -180.0);
	glVertex3f(-290.0, 840.0, -180.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-260.0, 840.0, -160.0);
	glVertex3f(-260.0, 910.0, -160.0);
	glVertex3f(-260.0, 910.0, -180.0);
	glVertex3f(-260.0, 840.0, -180.0);
	glEnd();
	
	//SATU b
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-90.0, 840.0, -160.0);
	glVertex3f(-90.0, 910.0, -160.0);
	glVertex3f(-60.0, 910.0, -160.0);
	glVertex3f(-60.0, 840.0, -160.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-90.0, 840.0, -180.0);
	glVertex3f(-90.0, 910.0, -180.0);
	glVertex3f(-60.0, 910.0, -180.0);
	glVertex3f(-60.0, 840.0, -180.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-90.0, 910.0, -180.0);
	glVertex3f(-90.0, 910.0, -160.0);
	glVertex3f(-60.0, 910.0, -160.0);
	glVertex3f(-60.0, 910.0, -180.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-90.0, 840.0, -160.0);
	glVertex3f(-90.0, 910.0, -160.0);
	glVertex3f(-90.0, 910.0, -180.0);
	glVertex3f(-90.0, 840.0, -180.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-60.0, 840.0, -160.0);
	glVertex3f(-60.0, 910.0, -160.0);
	glVertex3f(-60.0, 910.0, -180.0);
	glVertex3f(-60.0, 840.0, -180.0);
	glEnd();
	
	//SATU c 
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-290.0, 840.0, -320.0);
	glVertex3f(-290.0, 910.0, -320.0);
	glVertex3f(-260.0, 910.0, -320.0);
	glVertex3f(-260.0, 840.0, -320.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-290.0, 840.0, -340.0);
	glVertex3f(-290.0, 910.0, -340.0);
	glVertex3f(-260.0, 910.0, -340.0);
	glVertex3f(-260.0, 840.0, -340.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-290.0, 910.0, -340.0);
	glVertex3f(-290.0, 910.0, -320.0);
	glVertex3f(-260.0, 910.0, -320.0);
	glVertex3f(-260.0, 910.0, -340.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-290.0, 840.0, -320.0);
	glVertex3f(-290.0, 910.0, -320.0);
	glVertex3f(-290.0, 910.0, -340.0);
	glVertex3f(-290.0, 840.0, -340.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-260.0, 840.0, -320.0);
	glVertex3f(-260.0, 910.0, -320.0);
	glVertex3f(-260.0, 910.0, -340.0);
	glVertex3f(-260.0, 840.0, -340.0);
	glEnd();
	
	//SATU d 
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-290.0, 840.0, -460.0);
	glVertex3f(-290.0, 910.0, -460.0);
	glVertex3f(-260.0, 910.0, -460.0);
	glVertex3f(-260.0, 840.0, -460.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-290.0, 840.0, -480.0);
	glVertex3f(-290.0, 910.0, -480.0);
	glVertex3f(-260.0, 910.0, -480.0);
	glVertex3f(-260.0, 840.0, -480.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-290.0, 910.0, -480.0);
	glVertex3f(-290.0, 910.0, -460.0);
	glVertex3f(-260.0, 910.0, -460.0);
	glVertex3f(-260.0, 910.0, -480.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-290.0, 840.0, -460.0);
	glVertex3f(-290.0, 910.0, -460.0);
	glVertex3f(-290.0, 910.0, -480.0);
	glVertex3f(-290.0, 840.0, -480.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-260.0, 840.0, -460.0);
	glVertex3f(-260.0, 910.0, -460.0);
	glVertex3f(-260.0, 910.0, -480.0);
	glVertex3f(-260.0, 840.0, -480.0);
	glEnd();
	
	//SATU e 
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-290.0, 840.0, -630.0);
	glVertex3f(-290.0, 910.0, -630.0);
	glVertex3f(-260.0, 910.0, -630.0);
	glVertex3f(-260.0, 840.0, -630.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-290.0, 840.0, -650.0);
	glVertex3f(-290.0, 910.0, -650.0);
	glVertex3f(-260.0, 910.0, -650.0);
	glVertex3f(-260.0, 840.0, -650.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-290.0, 910.0, -650.0);
	glVertex3f(-290.0, 910.0, -630.0);
	glVertex3f(-260.0, 910.0, -630.0);
	glVertex3f(-260.0, 910.0, -650.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-290.0, 840.0, -630.0);
	glVertex3f(-290.0, 910.0, -630.0);
	glVertex3f(-290.0, 910.0, -650.0);
	glVertex3f(-290.0, 840.0, -650.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-260.0, 840.0, -630.0);
	glVertex3f(-260.0, 910.0, -630.0);
	glVertex3f(-260.0, 910.0, -650.0);
	glVertex3f(-260.0, 840.0, -650.0);
	glEnd();
	
	//SATU f
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-90.0, 840.0, -630.0);
	glVertex3f(-90.0, 910.0, -630.0);
	glVertex3f(-60.0, 910.0, -630.0);
	glVertex3f(-60.0, 840.0, -630.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-90.0, 840.0, -650.0);
	glVertex3f(-90.0, 910.0, -650.0);
	glVertex3f(-60.0, 910.0, -650.0);
	glVertex3f(-60.0, 840.0, -650.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-90.0, 910.0, -650.0);
	glVertex3f(-90.0, 910.0, -630.0);
	glVertex3f(-60.0, 910.0, -630.0);
	glVertex3f(-60.0, 910.0, -650.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-90.0, 840.0, -630.0);
	glVertex3f(-90.0, 910.0, -630.0);
	glVertex3f(-90.0, 910.0, -650.0);
	glVertex3f(-90.0, 840.0, -650.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-60.0, 840.0, -630.0);
	glVertex3f(-60.0, 910.0, -630.0);
	glVertex3f(-60.0, 910.0, -650.0);
	glVertex3f(-60.0, 840.0, -650.0);
	glEnd();
	
	
	//DUA a
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(290.0, 840.0, -160.0);
	glVertex3f(290.0, 910.0, -160.0);
	glVertex3f(260.0, 910.0, -160.0);
	glVertex3f(260.0, 840.0, -160.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(290.0, 840.0, -180.0);
	glVertex3f(290.0, 910.0, -180.0);
	glVertex3f(260.0, 910.0, -180.0);
	glVertex3f(260.0, 840.0, -180.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(290.0, 910.0, -180.0);
	glVertex3f(290.0, 910.0, -160.0);
	glVertex3f(260.0, 910.0, -160.0);
	glVertex3f(260.0, 910.0, -180.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(290.0, 840.0, -160.0);
	glVertex3f(290.0, 910.0, -160.0);
	glVertex3f(290.0, 910.0, -180.0);
	glVertex3f(290.0, 840.0, -180.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(260.0, 840.0, -160.0);
	glVertex3f(260.0, 910.0, -160.0);
	glVertex3f(260.0, 910.0, -180.0);
	glVertex3f(260.0, 840.0, -180.0);
	glEnd();
	
	//DUA b 
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(90.0, 840.0, -160.0);
	glVertex3f(90.0, 910.0, -160.0);
	glVertex3f(60.0, 910.0, -160.0);
	glVertex3f(60.0, 840.0, -160.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(90.0, 840.0, -180.0);
	glVertex3f(90.0, 910.0, -180.0);
	glVertex3f(60.0, 910.0, -180.0);
	glVertex3f(60.0, 840.0, -180.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(90.0, 910.0, -180.0);
	glVertex3f(90.0, 910.0, -160.0);
	glVertex3f(60.0, 910.0, -160.0);
	glVertex3f(60.0, 910.0, -180.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(90.0, 840.0, -160.0);
	glVertex3f(90.0, 910.0, -160.0);
	glVertex3f(90.0, 910.0, -180.0);
	glVertex3f(90.0, 840.0, -180.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(60.0, 840.0, -160.0);
	glVertex3f(60.0, 910.0, -160.0);
	glVertex3f(60.0, 910.0, -180.0);
	glVertex3f(60.0, 840.0, -180.0);
	glEnd();
	
	//DUA c 
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(290.0, 840.0, -300.0);
	glVertex3f(290.0, 910.0, -300.0);
	glVertex3f(260.0, 910.0, -300.0);
	glVertex3f(260.0, 840.0, -300.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(290.0, 840.0, -320.0);
	glVertex3f(290.0, 910.0, -320.0);
	glVertex3f(260.0, 910.0, -320.0);
	glVertex3f(260.0, 840.0, -320.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(290.0, 910.0, -320.0);
	glVertex3f(290.0, 910.0, -300.0);
	glVertex3f(260.0, 910.0, -300.0);
	glVertex3f(260.0, 910.0, -320.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(290.0, 840.0, -300.0);
	glVertex3f(290.0, 910.0, -300.0);
	glVertex3f(290.0, 910.0, -320.0);
	glVertex3f(290.0, 840.0, -320.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(260.0, 840.0, -300.0);
	glVertex3f(260.0, 910.0, -300.0);
	glVertex3f(260.0, 910.0, -320.0);
	glVertex3f(260.0, 840.0, -320.0);
	glEnd();
	
	//DUA d 
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(290.0, 840.0, -460.0);
	glVertex3f(290.0, 910.0, -460.0);
	glVertex3f(260.0, 910.0, -460.0);
	glVertex3f(260.0, 840.0, -460.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(290.0, 840.0, -480.0);
	glVertex3f(290.0, 910.0, -480.0);
	glVertex3f(260.0, 910.0, -480.0);
	glVertex3f(260.0, 840.0, -480.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(290.0, 910.0, -480.0);
	glVertex3f(290.0, 910.0, -460.0);
	glVertex3f(260.0, 910.0, -460.0);
	glVertex3f(260.0, 910.0, -480.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(290.0, 840.0, -460.0);
	glVertex3f(290.0, 910.0, -460.0);
	glVertex3f(290.0, 910.0, -480.0);
	glVertex3f(290.0, 840.0, -480.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(260.0, 840.0, -460.0);
	glVertex3f(260.0, 910.0, -460.0);
	glVertex3f(260.0, 910.0, -480.0);
	glVertex3f(260.0, 840.0, -480.0);
	glEnd();
	
	//DUA e 
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(290.0, 840.0, -630.0);
	glVertex3f(290.0, 910.0, -630.0);
	glVertex3f(260.0, 910.0, -630.0);
	glVertex3f(260.0, 840.0, -630.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(290.0, 840.0, -650.0);
	glVertex3f(290.0, 910.0, -650.0);
	glVertex3f(260.0, 910.0, -650.0);
	glVertex3f(260.0, 840.0, -650.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(290.0, 910.0, -650.0);
	glVertex3f(290.0, 910.0, -630.0);
	glVertex3f(260.0, 910.0, -630.0);
	glVertex3f(260.0, 910.0, -650.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(290.0, 840.0, -630.0);
	glVertex3f(290.0, 910.0, -630.0);
	glVertex3f(290.0, 910.0, -650.0);
	glVertex3f(290.0, 840.0, -650.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(260.0, 840.0, -630.0);
	glVertex3f(260.0, 910.0, -630.0);
	glVertex3f(260.0, 910.0, -650.0);
	glVertex3f(260.0, 840.0, -650.0);
	glEnd();
	
	//DUA f
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(90.0, 840.0, -630.0);
	glVertex3f(90.0, 910.0, -630.0);
	glVertex3f(60.0, 910.0, -630.0);
	glVertex3f(60.0, 840.0, -630.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(90.0, 840.0, -650.0);
	glVertex3f(90.0, 910.0, -650.0);
	glVertex3f(60.0, 910.0, -650.0);
	glVertex3f(60.0, 840.0, -650.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(90.0, 910.0, -650.0);
	glVertex3f(90.0, 910.0, -630.0);
	glVertex3f(60.0, 910.0, -630.0);
	glVertex3f(60.0, 910.0, -650.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(90.0, 840.0, -630.0);
	glVertex3f(90.0, 910.0, -630.0);
	glVertex3f(90.0, 910.0, -650.0);
	glVertex3f(90.0, 840.0, -650.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(60.0, 840.0, -630.0);
	glVertex3f(60.0, 910.0, -630.0);
	glVertex3f(60.0, 910.0, -650.0);
	glVertex3f(60.0, 840.0, -650.0);
	glEnd();
	
	//HORIZONTAL 1 atas
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-290.0, 905.0, -645.0);
	glVertex3f(-290.0, 910.0, -645.0);
	glVertex3f(290.0, 910.0, -645.0);
	glVertex3f(290.0, 905.0, -645.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-290.0, 910.0, -635.0);
	glVertex3f(-290.0, 905.0, -635.0);
	glVertex3f(290.0, 905.0, -635.0);
	glVertex3f(290.0, 910.0, -635.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-290.0, 910.0, -645.0);
	glVertex3f(-290.0, 910.0, -635.0);
	glVertex3f(290.0, 910.0, -635.0);
	glVertex3f(290.0, 910.0, -645.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-290.0, 905.0, -645.0);
	glVertex3f(-290.0, 905.0, -635.0);
	glVertex3f(290.0, 905.0, -635.0);
	glVertex3f(290.0, 905.0, -645.0);
	glEnd();
	
	//HORIZONTAL 1 bawah
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-290.0, 840.0, -645.0);
	glVertex3f(-290.0, 845.0, -645.0);
	glVertex3f(290.0, 845.0, -645.0);
	glVertex3f(290.0, 840.0, -645.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-290.0, 840.0, -635.0);
	glVertex3f(-290.0, 845.0, -635.0);
	glVertex3f(290.0, 845.0, -635.0);
	glVertex3f(290.0, 840.0, -635.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-290.0, 845.0, -645.0);
	glVertex3f(-290.0, 845.0, -635.0);
	glVertex3f(290.0, 845.0, -635.0);
	glVertex3f(290.0, 845.0, -645.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-290.0, 840.0, -645.0);
	glVertex3f(-290.0, 840.0, -635.0);
	glVertex3f(290.0, 840.0, -635.0);
	glVertex3f(290.0, 840.0, -645.0);
	glEnd();
	
	//HORIZONTAL 2 atas
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-290.0, 905.0, -175.0);
	glVertex3f(-290.0, 910.0, -175.0);
	glVertex3f(290.0, 910.0, -175.0);
	glVertex3f(290.0, 905.0, -175.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-290.0, 910.0, -165.0);
	glVertex3f(-290.0, 905.0, -165.0);
	glVertex3f(290.0, 905.0, -165.0);
	glVertex3f(290.0, 910.0, -165.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-290.0, 910.0, -175.0);
	glVertex3f(-290.0, 910.0, -165.0);
	glVertex3f(290.0, 910.0, -175.0);
	glVertex3f(290.0, 910.0, -165.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-290.0, 905.0, -175.0);
	glVertex3f(-290.0, 905.0, -165.0);
	glVertex3f(290.0, 905.0, -165.0);
	glVertex3f(290.0, 905.0, -175.0);
	glEnd();
	
	//HORIZONTAL 2 bawah
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-290.0, 845.0, -175.0);
	glVertex3f(-290.0, 840.0, -175.0);
	glVertex3f(290.0, 840.0, -175.0);
	glVertex3f(290.0, 845.0, -175.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-290.0, 840.0, -165.0);
	glVertex3f(-290.0, 845.0, -165.0);
	glVertex3f(290.0, 845.0, -165.0);
	glVertex3f(290.0, 840.0, -165.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-290.0, 840.0, -175.0);
	glVertex3f(-290.0, 840.0, -165.0);
	glVertex3f(290.0, 840.0, -175.0);
	glVertex3f(290.0, 840.0, -165.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-290.0, 845.0, -175.0);
	glVertex3f(-290.0, 845.0, -165.0);
	glVertex3f(290.0, 845.0, -165.0);
	glVertex3f(290.0, 845.0, -175.0);
	glEnd();
	
	//HORIZONTAL 3 atas
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-280.0, 905.0, -180.0);
	glVertex3f(-280.0, 910.0, -180.0);
	glVertex3f(-280.0, 910.0, -650.0);
	glVertex3f(-280.0, 905.0, -650.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-270.0, 910.0, -180.0);
	glVertex3f(-270.0, 905.0, -180.0);
	glVertex3f(-270.0, 905.0, -650.0);
	glVertex3f(-270.0, 910.0, -650.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-280.0, 910.0, -180.0);
	glVertex3f(-280.0, 910.0, -650.0);
	glVertex3f(-270.0, 910.0, -650.0);
	glVertex3f(-270.0, 910.0, -180.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-280.0, 905.0, -180.0);
	glVertex3f(-280.0, 905.0, -650.0);
	glVertex3f(-270.0, 905.0, -650.0);
	glVertex3f(-270.0, 905.0, -180.0);
	glEnd();
	
	//HORIZONTAL 3 bawah
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-280.0, 840.0, -180.0);
	glVertex3f(-280.0, 845.0, -180.0);
	glVertex3f(-280.0, 845.0, -650.0);
	glVertex3f(-280.0, 840.0, -650.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-270.0, 845.0, -180.0);
	glVertex3f(-270.0, 840.0, -180.0);
	glVertex3f(-270.0, 840.0, -650.0);
	glVertex3f(-270.0, 845.0, -650.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-280.0, 845.0, -180.0);
	glVertex3f(-280.0, 845.0, -650.0);
	glVertex3f(-270.0, 845.0, -650.0);
	glVertex3f(-270.0, 845.0, -180.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-280.0, 840.0, -180.0);
	glVertex3f(-280.0, 840.0, -650.0);
	glVertex3f(-270.0, 840.0, -650.0);
	glVertex3f(-270.0, 840.0, -180.0);
	glEnd();
	
	//HORIZONTAL 4 atas
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(280.0, 905.0, -180.0);
	glVertex3f(280.0, 910.0, -180.0);
	glVertex3f(280.0, 910.0, -650.0);
	glVertex3f(280.0, 905.0, -650.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(270.0, 910.0, -180.0);
	glVertex3f(270.0, 905.0, -180.0);
	glVertex3f(270.0, 905.0, -650.0);
	glVertex3f(270.0, 910.0, -650.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(280.0, 910.0, -180.0);
	glVertex3f(280.0, 910.0, -650.0);
	glVertex3f(270.0, 910.0, -650.0);
	glVertex3f(270.0, 910.0, -180.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(280.0, 905.0, -180.0);
	glVertex3f(280.0, 905.0, -650.0);
	glVertex3f(270.0, 905.0, -650.0);
	glVertex3f(270.0, 905.0, -180.0);
	glEnd();
	
	//HORIZONTAL 4 bawah
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(280.0, 840.0, -180.0);
	glVertex3f(280.0, 845.0, -180.0);
	glVertex3f(280.0, 845.0, -650.0);
	glVertex3f(280.0, 840.0, -650.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(270.0, 845.0, -180.0);
	glVertex3f(270.0, 840.0, -180.0);
	glVertex3f(270.0, 840.0, -650.0);
	glVertex3f(270.0, 845.0, -650.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(280.0, 845.0, -180.0);
	glVertex3f(280.0, 845.0, -650.0);
	glVertex3f(270.0, 845.0, -650.0);
	glVertex3f(270.0, 845.0, -180.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(280.0, 840.0, -180.0);
	glVertex3f(280.0, 840.0, -650.0);
	glVertex3f(270.0, 840.0, -650.0);
	glVertex3f(270.0, 840.0, -180.0);
	glEnd();
}



void pagar4() {
	//SATU a
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-240.0, 1220.0, -210.0);
	glVertex3f(-240.0, 1170.0, -210.0);
	glVertex3f(-210.0, 1170.0, -210.0);
	glVertex3f(-210.0, 1220.0, -210.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 1170.0, -230.0);
	glVertex3f(-240.0, 1220.0, -230.0);
	glVertex3f(-210.0, 1220.0, -230.0);
	glVertex3f(-210.0, 1170.0, -230.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 1220.0, -230.0);
	glVertex3f(-240.0, 1220.0, -210.0);
	glVertex3f(-210.0, 1220.0, -210.0);
	glVertex3f(-210.0, 1220.0, -230.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 1170.0, -210.0);
	glVertex3f(-240.0, 1220.0, -210.0);
	glVertex3f(-240.0, 1220.0, -230.0);
	glVertex3f(-240.0, 1170.0, -230.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-210.0, 1170.0, -210.0);
	glVertex3f(-210.0, 1220.0, -210.0);
	glVertex3f(-210.0, 1220.0, -230.0);
	glVertex3f(-210.0, 1170.0, -230.0);
	glEnd();
	
	//SATU b
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-90.0, 1220.0, -210.0);
	glVertex3f(-90.0, 1170.0, -210.0);
	glVertex3f(-60.0, 1170.0, -210.0);
	glVertex3f(-60.0, 1220.0, -210.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-90.0, 1170.0, -230.0);
	glVertex3f(-90.0, 1220.0, -230.0);
	glVertex3f(-60.0, 1220.0, -230.0);
	glVertex3f(-60.0, 1170.0, -230.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-90.0, 1220.0, -230.0);
	glVertex3f(-90.0, 1220.0, -210.0);
	glVertex3f(-60.0, 1220.0, -210.0);
	glVertex3f(-60.0, 1220.0, -230.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-90.0, 1170.0, -210.0);
	glVertex3f(-90.0, 1220.0, -210.0);
	glVertex3f(-90.0, 1220.0, -230.0);
	glVertex3f(-90.0, 1170.0, -230.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-60.0, 1170.0, -210.0);
	glVertex3f(-60.0, 1220.0, -210.0);
	glVertex3f(-60.0, 1220.0, -230.0);
	glVertex3f(-60.0, 1170.0, -230.0);
	glEnd();
	
	//SATU c
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-240.0, 1220.0, -330.0);
	glVertex3f(-240.0, 1170.0, -330.0);
	glVertex3f(-210.0, 1170.0, -330.0);
	glVertex3f(-210.0, 1220.0, -330.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 1170.0, -350.0);
	glVertex3f(-240.0, 1220.0, -350.0);
	glVertex3f(-210.0, 1220.0, -350.0);
	glVertex3f(-210.0, 1170.0, -350.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 1220.0, -350.0);
	glVertex3f(-240.0, 1220.0, -330.0);
	glVertex3f(-210.0, 1220.0, -330.0);
	glVertex3f(-210.0, 1220.0, -350.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 1170.0, -330.0);
	glVertex3f(-240.0, 1220.0, -330.0);
	glVertex3f(-240.0, 1220.0, -350.0);
	glVertex3f(-240.0, 1170.0, -350.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-210.0, 1170.0, -330.0);
	glVertex3f(-210.0, 1220.0, -330.0);
	glVertex3f(-210.0, 1220.0, -350.0);
	glVertex3f(-210.0, 1170.0, -350.0);
	glEnd();
	
	//SATU d
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-240.0, 1220.0, -440.0);
	glVertex3f(-240.0, 1170.0, -440.0);
	glVertex3f(-210.0, 1170.0, -440.0);
	glVertex3f(-210.0, 1220.0, -440.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 1170.0, -460.0);
	glVertex3f(-240.0, 1220.0, -460.0);
	glVertex3f(-210.0, 1220.0, -460.0);
	glVertex3f(-210.0, 1170.0, -460.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 1220.0, -440.0);
	glVertex3f(-240.0, 1220.0, -440.0);
	glVertex3f(-210.0, 1220.0, -460.0);
	glVertex3f(-210.0, 1220.0, -460.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 1170.0, -440.0);
	glVertex3f(-240.0, 1220.0, -440.0);
	glVertex3f(-240.0, 1220.0, -460.0);
	glVertex3f(-240.0, 1170.0, -460.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-210.0, 1170.0, -440.0);
	glVertex3f(-210.0, 1220.0, -440.0);
	glVertex3f(-210.0, 1220.0, -460.0);
	glVertex3f(-210.0, 1170.0, -460.0);
	glEnd();
	
	//SATU e
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-240.0, 1220.0, -570.0);
	glVertex3f(-240.0, 1170.0, -570.0);
	glVertex3f(-210.0, 1170.0, -570.0);
	glVertex3f(-210.0, 1220.0, -570.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 1170.0, -590.0);
	glVertex3f(-240.0, 1220.0, -590.0);
	glVertex3f(-210.0, 1220.0, -590.0);
	glVertex3f(-210.0, 1170.0, -590.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 1220.0, -570.0);
	glVertex3f(-240.0, 1220.0, -570.0);
	glVertex3f(-210.0, 1220.0, -590.0);
	glVertex3f(-210.0, 1220.0, -590.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 1170.0, -570.0);
	glVertex3f(-240.0, 1220.0, -570.0);
	glVertex3f(-240.0, 1220.0, -590.0);
	glVertex3f(-240.0, 1170.0, -590.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-210.0, 1170.0, -570.0);
	glVertex3f(-210.0, 1220.0, -570.0);
	glVertex3f(-210.0, 1220.0, -590.0);
	glVertex3f(-210.0, 1170.0, -590.0);
	glEnd();
	
	//SATU f
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-90.0, 1220.0, -570.0);
	glVertex3f(-90.0, 1170.0, -570.0);
	glVertex3f(-60.0, 1170.0, -570.0);
	glVertex3f(-60.0, 1220.0, -570.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-90.0, 1170.0, -590.0);
	glVertex3f(-90.0, 1220.0, -590.0);
	glVertex3f(-60.0, 1220.0, -590.0);
	glVertex3f(-60.0, 1170.0, -590.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-90.0, 1220.0, -570.0);
	glVertex3f(-90.0, 1220.0, -570.0);
	glVertex3f(-60.0, 1220.0, -590.0);
	glVertex3f(-60.0, 1220.0, -590.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-90.0, 1170.0, -570.0);
	glVertex3f(-90.0, 1220.0, -570.0);
	glVertex3f(-90.0, 1220.0, -590.0);
	glVertex3f(-90.0, 1170.0, -590.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-60.0, 1170.0, -570.0);
	glVertex3f(-60.0, 1220.0, -570.0);
	glVertex3f(-60.0, 1220.0, -590.0);
	glVertex3f(-60.0, 1170.0, -590.0);
	glEnd();
	
	//DUA a
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(240.0, 1220.0, -210.0);
	glVertex3f(240.0, 1170.0, -210.0);
	glVertex3f(210.0, 1170.0, -210.0);
	glVertex3f(210.0, 1220.0, -210.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(240.0, 1170.0, -230.0);
	glVertex3f(240.0, 1220.0, -230.0);
	glVertex3f(210.0, 1220.0, -230.0);
	glVertex3f(210.0, 1170.0, -230.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(240.0, 1220.0, -230.0);
	glVertex3f(240.0, 1220.0, -210.0);
	glVertex3f(210.0, 1220.0, -210.0);
	glVertex3f(210.0, 1220.0, -230.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(240.0, 1170.0, -210.0);
	glVertex3f(240.0, 1220.0, -210.0);
	glVertex3f(240.0, 1220.0, -230.0);
	glVertex3f(240.0, 1170.0, -230.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(210.0, 1170.0, -210.0);
	glVertex3f(210.0, 1220.0, -210.0);
	glVertex3f(210.0, 1220.0, -230.0);
	glVertex3f(210.0, 1170.0, -230.0);
	glEnd();
	
	//DUA b
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(90.0, 1220.0, -210.0);
	glVertex3f(90.0, 1170.0, -210.0);
	glVertex3f(60.0, 1170.0, -210.0);
	glVertex3f(60.0, 1220.0, -210.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(90.0, 1170.0, -230.0);
	glVertex3f(90.0, 1220.0, -230.0);
	glVertex3f(60.0, 1220.0, -230.0);
	glVertex3f(60.0, 1170.0, -230.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(90.0, 1220.0, -230.0);
	glVertex3f(90.0, 1220.0, -210.0);
	glVertex3f(60.0, 1220.0, -210.0);
	glVertex3f(60.0, 1220.0, -230.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(90.0, 1170.0, -210.0);
	glVertex3f(90.0, 1220.0, -210.0);
	glVertex3f(90.0, 1220.0, -230.0);
	glVertex3f(90.0, 1170.0, -230.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(60.0, 1170.0, -210.0);
	glVertex3f(60.0, 1220.0, -210.0);
	glVertex3f(60.0, 1220.0, -230.0);
	glVertex3f(60.0, 1170.0, -230.0);
	glEnd();
	
	//DUA c
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(240.0, 1220.0, -330.0);
	glVertex3f(240.0, 1170.0, -330.0);
	glVertex3f(210.0, 1170.0, -330.0);
	glVertex3f(210.0, 1220.0, -330.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(240.0, 1170.0, -350.0);
	glVertex3f(240.0, 1220.0, -350.0);
	glVertex3f(210.0, 1220.0, -350.0);
	glVertex3f(210.0, 1170.0, -350.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(240.0, 1220.0, -350.0);
	glVertex3f(240.0, 1220.0, -330.0);
	glVertex3f(210.0, 1220.0, -330.0);
	glVertex3f(210.0, 1220.0, -350.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(240.0, 1170.0, -330.0);
	glVertex3f(240.0, 1220.0, -330.0);
	glVertex3f(240.0, 1220.0, -350.0);
	glVertex3f(240.0, 1170.0, -350.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(210.0, 1170.0, -330.0);
	glVertex3f(210.0, 1220.0, -330.0);
	glVertex3f(210.0, 1220.0, -350.0);
	glVertex3f(210.0, 1170.0, -350.0);
	glEnd();
	
	//DUA d
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(240.0, 1220.0, -440.0);
	glVertex3f(240.0, 1170.0, -440.0);
	glVertex3f(210.0, 1170.0, -440.0);
	glVertex3f(210.0, 1220.0, -440.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(240.0, 1170.0, -460.0);
	glVertex3f(240.0, 1220.0, -460.0);
	glVertex3f(210.0, 1220.0, -460.0);
	glVertex3f(210.0, 1170.0, -460.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(240.0, 1220.0, -440.0);
	glVertex3f(240.0, 1220.0, -440.0);
	glVertex3f(210.0, 1220.0, -460.0);
	glVertex3f(210.0, 1220.0, -460.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(240.0, 1170.0, -440.0);
	glVertex3f(240.0, 1220.0, -440.0);
	glVertex3f(240.0, 1220.0, -460.0);
	glVertex3f(240.0, 1170.0, -460.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(210.0, 1170.0, -440.0);
	glVertex3f(210.0, 1220.0, -440.0);
	glVertex3f(210.0, 1220.0, -460.0);
	glVertex3f(210.0, 1170.0, -460.0);
	glEnd();
	
	//DUA e
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(240.0, 1220.0, -570.0);
	glVertex3f(240.0, 1170.0, -570.0);
	glVertex3f(210.0, 1170.0, -570.0);
	glVertex3f(210.0, 1220.0, -570.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(240.0, 1170.0, -590.0);
	glVertex3f(240.0, 1220.0, -590.0);
	glVertex3f(210.0, 1220.0, -590.0);
	glVertex3f(210.0, 1170.0, -590.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(240.0, 1220.0, -570.0);
	glVertex3f(240.0, 1220.0, -570.0);
	glVertex3f(210.0, 1220.0, -590.0);
	glVertex3f(210.0, 1220.0, -590.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(240.0, 1170.0, -570.0);
	glVertex3f(240.0, 1220.0, -570.0);
	glVertex3f(240.0, 1220.0, -590.0);
	glVertex3f(240.0, 1170.0, -590.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(210.0, 1170.0, -570.0);
	glVertex3f(210.0, 1220.0, -570.0);
	glVertex3f(210.0, 1220.0, -590.0);
	glVertex3f(210.0, 1170.0, -590.0);
	glEnd();
	
	
	//DUA f
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(90.0, 1220.0, -570.0);
	glVertex3f(90.0, 1170.0, -570.0);
	glVertex3f(60.0, 1170.0, -570.0);
	glVertex3f(60.0, 1220.0, -570.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(90.0, 1170.0, -590.0);
	glVertex3f(90.0, 1220.0, -590.0);
	glVertex3f(60.0, 1220.0, -590.0);
	glVertex3f(60.0, 1170.0, -590.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(90.0, 1220.0, -570.0);
	glVertex3f(90.0, 1220.0, -570.0);
	glVertex3f(60.0, 1220.0, -590.0);
	glVertex3f(60.0, 1220.0, -590.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(90.0, 1170.0, -570.0);
	glVertex3f(90.0, 1220.0, -570.0);
	glVertex3f(90.0, 1220.0, -590.0);
	glVertex3f(90.0, 1170.0, -590.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(60.0, 1170.0, -570.0);
	glVertex3f(60.0, 1220.0, -570.0);
	glVertex3f(60.0, 1220.0, -590.0);
	glVertex3f(60.0, 1170.0, -590.0);
	glEnd();
	
	//HORIZONTAL 1 atas
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-240.0, 1215.0, -585.0);
	glVertex3f(-240.0, 1220.0, -585.0);
	glVertex3f(240.0, 1220.0, -585.0);
	glVertex3f(240.0, 1215.0, -585.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 1220.0, -575.0);
	glVertex3f(-240.0, 1215.0, -575.0);
	glVertex3f(240.0, 1215.0, -575.0);
	glVertex3f(240.0, 1220.0, -575.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 1220.0, -585.0);
	glVertex3f(-240.0, 1220.0, -575.0);
	glVertex3f(240.0, 1220.0, -575.0);
	glVertex3f(240.0, 1220.0, -585.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 1215.0, -585.0);
	glVertex3f(-240.0, 1215.0, -575.0);
	glVertex3f(240.0, 1215.0, -575.0);
	glVertex3f(240.0, 1215.0, -585.0);
	glEnd();
	
	//HORIZONTAL 1 bawah
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-240.0, 1170.0, -585.0);
	glVertex3f(-240.0, 1175.0, -585.0);
	glVertex3f(240.0, 1175.0, -585.0);
	glVertex3f(240.0, 1170.0, -585.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 1175.0, -575.0);
	glVertex3f(-240.0, 1170.0, -575.0);
	glVertex3f(240.0, 1170.0, -575.0);
	glVertex3f(240.0, 1175.0, -575.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 1175.0, -585.0);
	glVertex3f(-240.0, 1175.0, -575.0);
	glVertex3f(240.0, 1175.0, -575.0);
	glVertex3f(240.0, 1175.0, -585.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 1170.0, -585.0);
	glVertex3f(-240.0, 1170.0, -575.0);
	glVertex3f(240.0, 1170.0, -575.0);
	glVertex3f(240.0, 1170.0, -585.0);
	glEnd();
	
	//HORIZONTAL 2 atas
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-240.0, 1215.0, -225.0);
	glVertex3f(-240.0, 1220.0, -225.0);
	glVertex3f(240.0, 1220.0, -225.0);
	glVertex3f(240.0, 1215.0, -225.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 1220.0, -215.0);
	glVertex3f(-240.0, 1215.0, -215.0);
	glVertex3f(240.0, 1215.0, -215.0);
	glVertex3f(240.0, 1220.0, -215.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 1220.0, -225.0);
	glVertex3f(-240.0, 1220.0, -215.0);
	glVertex3f(240.0, 1220.0, -215.0);
	glVertex3f(240.0, 1220.0, -225.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 1215.0, -225.0);
	glVertex3f(-240.0, 1215.0, -215.0);
	glVertex3f(240.0, 1215.0, -215.0);
	glVertex3f(240.0, 1215.0, -225.0);
	glEnd();
	
	//HORIZONTAL 2 bawah
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-240.0, 1170.0, -225.0);
	glVertex3f(-240.0, 1175.0, -225.0);
	glVertex3f(240.0, 1175.0, -225.0);
	glVertex3f(240.0, 1170.0, -225.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 1175.0, -215.0);
	glVertex3f(-240.0, 1170.0, -215.0);
	glVertex3f(240.0, 1170.0, -215.0);
	glVertex3f(240.0, 1175.0, -215.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 1175.0, -225.0);
	glVertex3f(-240.0, 1175.0, -215.0);
	glVertex3f(240.0, 1175.0, -215.0);
	glVertex3f(240.0, 1175.0, -225.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 1170.0, -225.0);
	glVertex3f(-240.0, 1170.0, -215.0);
	glVertex3f(240.0, 1170.0, -215.0);
	glVertex3f(240.0, 1170.0, -225.0);
	glEnd();
	
	//HORIZONTAL 3 atas
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-230.0, 1215.0, -210.0);
	glVertex3f(-230.0, 1220.0, -210.0);
	glVertex3f(-230.0, 1220.0, -550.0);
	glVertex3f(-230.0, 1215.0, -550.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-220.0, 1220.0, -210.0);
	glVertex3f(-220.0, 1215.0, -210.0);
	glVertex3f(-220.0, 1215.0, -550.0);
	glVertex3f(-220.0, 1220.0, -550.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-230.0, 1220.0, -210.0);
	glVertex3f(-230.0, 1220.0, -550.0);
	glVertex3f(-220.0, 1220.0, -550.0);
	glVertex3f(-220.0, 1220.0, -210.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-230.0, 1215.0, -210.0);
	glVertex3f(-230.0, 1215.0, -550.0);
	glVertex3f(-220.0, 1215.0, -550.0);
	glVertex3f(-220.0, 1215.0, -210.0);
	glEnd();
	
	//HORIZONTAL 3 atas
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-230.0, 1215.0, -230.0);
	glVertex3f(-230.0, 1220.0, -230.0);
	glVertex3f(-230.0, 1220.0, -570.0);
	glVertex3f(-230.0, 1215.0, -570.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-220.0, 1220.0, -230.0);
	glVertex3f(-220.0, 1215.0, -230.0);
	glVertex3f(-220.0, 1215.0, -570.0);
	glVertex3f(-220.0, 1220.0, -570.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-230.0, 1220.0, -230.0);
	glVertex3f(-230.0, 1220.0, -570.0);
	glVertex3f(-220.0, 1220.0, -570.0);
	glVertex3f(-220.0, 1220.0, -230.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-230.0, 1215.0, -230.0);
	glVertex3f(-230.0, 1215.0, -570.0);
	glVertex3f(-220.0, 1215.0, -570.0);
	glVertex3f(-220.0, 1215.0, -230.0);
	glEnd();
	
	//HORIZONTAL 3 bawah
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(-230.0, 1170.0, -230.0);
	glVertex3f(-230.0, 1175.0, -230.0);
	glVertex3f(-230.0, 1175.0, -570.0);
	glVertex3f(-230.0, 1170.0, -570.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-220.0, 1175.0, -230.0);
	glVertex3f(-220.0, 1170.0, -230.0);
	glVertex3f(-220.0, 1170.0, -570.0);
	glVertex3f(-220.0, 1175.0, -570.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-230.0, 1175.0, -230.0);
	glVertex3f(-230.0, 1175.0, -570.0);
	glVertex3f(-220.0, 1175.0, -570.0);
	glVertex3f(-220.0, 1175.0, -230.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-230.0, 1170.0, -230.0);
	glVertex3f(-230.0, 1170.0, -570.0);
	glVertex3f(-220.0, 1170.0, -570.0);
	glVertex3f(-220.0, 1170.0, -230.0);
	glEnd();
	
	//HORIZONTAL 4 atas
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(230.0, 1215.0, -230.0);
	glVertex3f(230.0, 1220.0, -230.0);
	glVertex3f(230.0, 1220.0, -570.0);
	glVertex3f(230.0, 1215.0, -570.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(220.0, 1220.0, -230.0);
	glVertex3f(220.0, 1215.0, -230.0);
	glVertex3f(220.0, 1215.0, -570.0);
	glVertex3f(220.0, 1220.0, -570.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(230.0, 1220.0, -230.0);
	glVertex3f(230.0, 1220.0, -570.0);
	glVertex3f(220.0, 1220.0, -570.0);
	glVertex3f(220.0, 1220.0, -230.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(230.0, 1215.0, -230.0);
	glVertex3f(230.0, 1215.0, -570.0);
	glVertex3f(220.0, 1215.0, -570.0);
	glVertex3f(220.0, 1215.0, -230.0);
	glEnd();
	
	//HORIZONTAL 4 bawah
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(0.64, 0.21, 0.21);
	glVertex3f(230.0, 1170.0, -230.0);
	glVertex3f(230.0, 1175.0, -230.0);
	glVertex3f(230.0, 1175.0, -570.0);
	glVertex3f(230.0, 1170.0, -570.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(220.0, 1175.0, -230.0);
	glVertex3f(220.0, 1170.0, -230.0);
	glVertex3f(220.0, 1170.0, -570.0);
	glVertex3f(220.0, 1175.0, -570.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(230.0, 1175.0, -230.0);
	glVertex3f(230.0, 1175.0, -570.0);
	glVertex3f(220.0, 1175.0, -570.0);
	glVertex3f(220.0, 1175.0, -230.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(230.0, 1170.0, -230.0);
	glVertex3f(230.0, 1170.0, -570.0);
	glVertex3f(220.0, 1170.0, -570.0);
	glVertex3f(220.0, 1170.0, -230.0);
	glEnd();
}




void pagarluar() {
	
	//Tiang luar
	//deret kiri a
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(-1240.0, 0.0, 810.0);
	glVertex3f(-1240.0, 90.0, 810.0);
	glVertex3f(-1210.0, 90.0, 810.0);
	glVertex3f(-1210.0, 0.0, 810.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-1240.0, 0.0, 830.0);
	glVertex3f(-1240.0, 90.0, 830.0);
	glVertex3f(-1210.0, 90.0, 830.0);
	glVertex3f(-1210.0, 0.0, 830.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-1240.0, 90.0, 830.0);
	glVertex3f(-1240.0, 90.0, 810.0);
	glVertex3f(-1210.0, 90.0, 810.0);
	glVertex3f(-1210.0, 90.0, 830.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-1240.0, 0.0, 810.0);
	glVertex3f(-1240.0, 90.0, 810.0);
	glVertex3f(-1240.0, 90.0, 830.0);
	glVertex3f(-1240.0, 0.0, 830.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-1210.0, 0.0, 810.0);
	glVertex3f(-1210.0, 90.0, 810.0);
	glVertex3f(-1210.0, 90.0, 830.0);
	glVertex3f(-1210.0, 0.0, 830.0);
	glEnd();
	
	//deret kiri b
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(-1040.0, 0.0, 810.0);
	glVertex3f(-1040.0, 90.0, 810.0);
	glVertex3f(-1010.0, 90.0, 810.0);
	glVertex3f(-1010.0, 0.0, 810.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-1040.0, 0.0, 830.0);
	glVertex3f(-1040.0, 90.0, 830.0);
	glVertex3f(-1010.0, 90.0, 830.0);
	glVertex3f(-1010.0, 0.0, 830.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-1040.0, 90.0, 830.0);
	glVertex3f(-1040.0, 90.0, 810.0);
	glVertex3f(-1010.0, 90.0, 810.0);
	glVertex3f(-1010.0, 90.0, 830.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-1040.0, 0.0, 810.0);
	glVertex3f(-1040.0, 90.0, 810.0);
	glVertex3f(-1040.0, 90.0, 830.0);
	glVertex3f(-1040.0, 0.0, 830.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-1010.0, 0.0, 810.0);
	glVertex3f(-1010.0, 90.0, 810.0);
	glVertex3f(-1010.0, 90.0, 830.0);
	glVertex3f(-1010.0, 0.0, 830.0);
	glEnd();
	
	//glBegin(GL_POLYGON);
	//glColor3f(1.0, 1.0, 0.0);
	//glVertex3f(-840.0, 470.0, -110.0);
//	glVertex3f(-840.0, 570.0, -110.0);
	//glVertex3f(-810.0, 570.0, -110.0);
//	glVertex3f(-810.0, 470.0, -110.0);
	//glEnd();
	
	//deret kiri c
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(-840.0, 0.0, 810.0);
	glVertex3f(-840.0, 90.0, 810.0);
	glVertex3f(-810.0, 90.0, 810.0);
	glVertex3f(-810.0, 0.0, 810.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-840.0, 0.0, 830.0);
	glVertex3f(-840.0, 90.0, 830.0);
	glVertex3f(-810.0, 90.0, 830.0);
	glVertex3f(-810.0, 0.0, 830.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-840.0, 90.0, 830.0);
	glVertex3f(-840.0, 90.0, 810.0);
	glVertex3f(-810.0, 90.0, 810.0);
	glVertex3f(-810.0, 90.0, 830.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-840.0, 0.0, 810.0);
	glVertex3f(-840.0, 90.0, 810.0);
	glVertex3f(-840.0, 90.0, 830.0);
	glVertex3f(-840.0, 0.0, 830.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-810.0, 0.0, 810.0);
	glVertex3f(-810.0, 90.0, 810.0);
	glVertex3f(-810.0, 90.0, 830.0);
	glVertex3f(-810.0, 0.0, 830.0);
	glEnd();
	
	//deret kiri d
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(-1240.0, 0.0, 610.0);
	glVertex3f(-1240.0, 90.0, 610.0);
	glVertex3f(-1210.0, 90.0, 610.0);
	glVertex3f(-1210.0, 0.0, 610.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-1240.0, 0.0, 630.0);
	glVertex3f(-1240.0, 90.0, 630.0);
	glVertex3f(-1210.0, 90.0, 630.0);
	glVertex3f(-1210.0, 0.0, 630.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-1240.0, 90.0, 630.0);
	glVertex3f(-1240.0, 90.0, 610.0);
	glVertex3f(-1210.0, 90.0, 610.0);
	glVertex3f(-1210.0, 90.0, 630.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-1240.0, 0.0, 610.0);
	glVertex3f(-1240.0, 90.0, 610.0);
	glVertex3f(-1240.0, 90.0, 630.0);
	glVertex3f(-1240.0, 0.0, 630.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-1210.0, 0.0, 610.0);
	glVertex3f(-1210.0, 90.0, 610.0);
	glVertex3f(-1210.0, 90.0, 630.0);
	glVertex3f(-1210.0, 0.0, 630.0);
	glEnd();
	
	//deret kiri e
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(-1240.0, 0.0, 410.0);
	glVertex3f(-1240.0, 90.0, 410.0);
	glVertex3f(-1210.0, 90.0, 410.0);
	glVertex3f(-1210.0, 0.0, 410.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-1240.0, 0.0, 430.0);
	glVertex3f(-1240.0, 90.0, 430.0);
	glVertex3f(-1210.0, 90.0, 430.0);
	glVertex3f(-1210.0, 0.0, 430.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-1240.0, 90.0, 430.0);
	glVertex3f(-1240.0, 90.0, 410.0);
	glVertex3f(-1210.0, 90.0, 410.0);
	glVertex3f(-1210.0, 90.0, 430.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-1240.0, 0.0, 410.0);
	glVertex3f(-1240.0, 90.0, 410.0);
	glVertex3f(-1240.0, 90.0, 430.0);
	glVertex3f(-1240.0, 0.0, 430.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-1210.0, 0.0, 410.0);
	glVertex3f(-1210.0, 90.0, 410.0);
	glVertex3f(-1210.0, 90.0, 430.0);
	glVertex3f(-1210.0, 0.0, 430.0);
	glEnd();
	
	//deret kiri f
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(-1240.0, 0.0, 210.0);
	glVertex3f(-1240.0, 90.0, 210.0);
	glVertex3f(-1210.0, 90.0, 210.0);
	glVertex3f(-1210.0, 0.0, 210.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-1240.0, 0.0, 230.0);
	glVertex3f(-1240.0, 90.0, 230.0);
	glVertex3f(-1210.0, 90.0, 230.0);
	glVertex3f(-1210.0, 0.0, 230.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-1240.0, 90.0, 230.0);
	glVertex3f(-1240.0, 90.0, 210.0);
	glVertex3f(-1210.0, 90.0, 210.0);
	glVertex3f(-1210.0, 90.0, 230.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-1240.0, 0.0, 210.0);
	glVertex3f(-1240.0, 90.0, 210.0);
	glVertex3f(-1240.0, 90.0, 230.0);
	glVertex3f(-1240.0, 0.0, 230.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-1210.0, 0.0, 210.0);
	glVertex3f(-1210.0, 90.0, 210.0);
	glVertex3f(-1210.0, 90.0, 230.0);
	glVertex3f(-1210.0, 0.0, 230.0);
	glEnd();
	
	//deret kiri g
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(-1240.0, 0.0, 10.0);
	glVertex3f(-1240.0, 90.0, 10.0);
	glVertex3f(-1210.0, 90.0, 10.0);
	glVertex3f(-1210.0, 0.0, 10.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-1240.0, 0.0, 30.0);
	glVertex3f(-1240.0, 90.0, 30.0);
	glVertex3f(-1210.0, 90.0, 30.0);
	glVertex3f(-1210.0, 0.0, 30.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-1240.0, 90.0, 30.0);
	glVertex3f(-1240.0, 90.0, 10.0);
	glVertex3f(-1210.0, 90.0, 10.0);
	glVertex3f(-1210.0, 90.0, 30.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-1240.0, 0.0, 10.0);
	glVertex3f(-1240.0, 90.0, 10.0);
	glVertex3f(-1240.0, 90.0, 30.0);
	glVertex3f(-1240.0, 0.0, 30.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-1210.0, 0.0, 10.0);
	glVertex3f(-1210.0, 90.0, 10.0);
	glVertex3f(-1210.0, 90.0, 30.0);
	glVertex3f(-1210.0, 0.0, 30.0);
	glEnd();
	
	//deret kiri h
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(-1240.0, 0.0, -210.0);
	glVertex3f(-1240.0, 90.0, -210.0);
	glVertex3f(-1210.0, 90.0, -210.0);
	glVertex3f(-1210.0, 0.0, -210.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-1240.0, 0.0, -230.0);
	glVertex3f(-1240.0, 90.0, -230.0);
	glVertex3f(-1210.0, 90.0, -230.0);
	glVertex3f(-1210.0, 0.0, -230.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-1240.0, 90.0, -230.0);
	glVertex3f(-1240.0, 90.0, -210.0);
	glVertex3f(-1210.0, 90.0, -210.0);
	glVertex3f(-1210.0, 90.0, -230.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-1240.0, 0.0, -210.0);
	glVertex3f(-1240.0, 90.0, -210.0);
	glVertex3f(-1240.0, 90.0, -230.0);
	glVertex3f(-1240.0, 0.0, -230.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-1210.0, 0.0, -210.0);
	glVertex3f(-1210.0, 90.0, -210.0);
	glVertex3f(-1210.0, 90.0, -230.0);
	glVertex3f(-1210.0, 0.0, -230.0);
	glEnd();
	
	//deret kiri i
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(-1240.0, 0.0, -410.0);
	glVertex3f(-1240.0, 90.0, -410.0);
	glVertex3f(-1210.0, 90.0, -410.0);
	glVertex3f(-1210.0, 0.0, -410.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-1240.0, 0.0, -430.0);
	glVertex3f(-1240.0, 90.0, -430.0);
	glVertex3f(-1210.0, 90.0, -430.0);
	glVertex3f(-1210.0, 0.0, -430.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-1240.0, 90.0, -430.0);
	glVertex3f(-1240.0, 90.0, -410.0);
	glVertex3f(-1210.0, 90.0, -410.0);
	glVertex3f(-1210.0, 90.0, -430.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-1240.0, 0.0, -410.0);
	glVertex3f(-1240.0, 90.0, -410.0);
	glVertex3f(-1240.0, 90.0, -430.0);
	glVertex3f(-1240.0, 0.0, -430.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-1210.0, 0.0, -410.0);
	glVertex3f(-1210.0, 90.0, -410.0);
	glVertex3f(-1210.0, 90.0, -430.0);
	glVertex3f(-1210.0, 0.0, -430.0);
	glEnd();
	
	//deret kiri j
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(-1240.0, 0.0, -610.0);
	glVertex3f(-1240.0, 90.0, -610.0);
	glVertex3f(-1210.0, 90.0, -610.0);
	glVertex3f(-1210.0, 0.0, -610.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-1240.0, 0.0, -630.0);
	glVertex3f(-1240.0, 90.0, -630.0);
	glVertex3f(-1210.0, 90.0, -630.0);
	glVertex3f(-1210.0, 0.0, -630.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-1240.0, 90.0, -630.0);
	glVertex3f(-1240.0, 90.0, -610.0);
	glVertex3f(-1210.0, 90.0, -610.0);
	glVertex3f(-1210.0, 90.0, -630.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-1240.0, 0.0, -610.0);
	glVertex3f(-1240.0, 90.0, -610.0);
	glVertex3f(-1240.0, 90.0, -630.0);
	glVertex3f(-1240.0, 0.0, -630.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-1210.0, 0.0, -610.0);
	glVertex3f(-1210.0, 90.0, -610.0);
	glVertex3f(-1210.0, 90.0, -630.0);
	glVertex3f(-1210.0, 0.0, -630.0);
	glEnd();
	
	//deret kiri k
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(-1240.0, 0.0, -810.0);
	glVertex3f(-1240.0, 90.0, -810.0);
	glVertex3f(-1210.0, 90.0, -810.0);
	glVertex3f(-1210.0, 0.0, -810.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-1240.0, 0.0, -830.0);
	glVertex3f(-1240.0, 90.0, -830.0);
	glVertex3f(-1210.0, 90.0, -830.0);
	glVertex3f(-1210.0, 0.0, -830.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-1240.0, 90.0, -830.0);
	glVertex3f(-1240.0, 90.0, -810.0);
	glVertex3f(-1210.0, 90.0, -810.0);
	glVertex3f(-1210.0, 90.0, -830.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-1240.0, 0.0, -810.0);
	glVertex3f(-1240.0, 90.0, -810.0);
	glVertex3f(-1240.0, 90.0, -830.0);
	glVertex3f(-1240.0, 0.0, -830.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-1210.0, 0.0, -810.0);
	glVertex3f(-1210.0, 90.0, -810.0);
	glVertex3f(-1210.0, 90.0, -830.0);
	glVertex3f(-1210.0, 0.0, -830.0);
	glEnd();
	
	//deret kiri l
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(-1240.0, 0.0, -1010.0);
	glVertex3f(-1240.0, 90.0, -1010.0);
	glVertex3f(-1210.0, 90.0, -1010.0);
	glVertex3f(-1210.0, 0.0, -1010.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-1240.0, 0.0, -1030.0);
	glVertex3f(-1240.0, 90.0, -1030.0);
	glVertex3f(-1210.0, 90.0, -1030.0);
	glVertex3f(-1210.0, 0.0, -1030.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-1240.0, 90.0, -1030.0);
	glVertex3f(-1240.0, 90.0, -1010.0);
	glVertex3f(-1210.0, 90.0, -1010.0);
	glVertex3f(-1210.0, 90.0, -1030.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-1240.0, 0.0, -1010.0);
	glVertex3f(-1240.0, 90.0, -1010.0);
	glVertex3f(-1240.0, 90.0, -1030.0);
	glVertex3f(-1240.0, 0.0, -1030.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-1210.0, 0.0, -1010.0);
	glVertex3f(-1210.0, 90.0, -1010.0);
	glVertex3f(-1210.0, 90.0, -1030.0);
	glVertex3f(-1210.0, 0.0, -1030.0);
	glEnd();
	
	//DUA
	//deret kanan a
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(1240.0, 0.0, 810.0);
	glVertex3f(1240.0, 90.0, 810.0);
	glVertex3f(1210.0, 90.0, 810.0);
	glVertex3f(1210.0, 0.0, 810.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(1240.0, 0.0, 830.0);
	glVertex3f(1240.0, 90.0, 830.0);
	glVertex3f(1210.0, 90.0, 830.0);
	glVertex3f(1210.0, 0.0, 830.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(1240.0, 90.0, 830.0);
	glVertex3f(1240.0, 90.0, 810.0);
	glVertex3f(1210.0, 90.0, 810.0);
	glVertex3f(1210.0, 90.0, 830.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(1240.0, 0.0, 810.0);
	glVertex3f(1240.0, 90.0, 810.0);
	glVertex3f(1240.0, 90.0, 830.0);
	glVertex3f(1240.0, 0.0, 830.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(1210.0, 0.0, 810.0);
	glVertex3f(1210.0, 90.0, 810.0);
	glVertex3f(1210.0, 90.0, 830.0);
	glVertex3f(1210.0, 0.0, 830.0);
	glEnd();
	
	//deret kanan b
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(1040.0, 0.0, 810.0);
	glVertex3f(1040.0, 90.0, 810.0);
	glVertex3f(1010.0, 90.0, 810.0);
	glVertex3f(1010.0, 0.0, 810.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(1040.0, 0.0, 830.0);
	glVertex3f(1040.0, 90.0, 830.0);
	glVertex3f(1010.0, 90.0, 830.0);
	glVertex3f(1010.0, 0.0, 830.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(1040.0, 90.0, 830.0);
	glVertex3f(1040.0, 90.0, 810.0);
	glVertex3f(1010.0, 90.0, 810.0);
	glVertex3f(1010.0, 90.0, 830.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(1040.0, 0.0, 810.0);
	glVertex3f(1040.0, 90.0, 810.0);
	glVertex3f(1040.0, 90.0, 830.0);
	glVertex3f(1040.0, 0.0, 830.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(1010.0, 0.0, 810.0);
	glVertex3f(1010.0, 90.0, 810.0);
	glVertex3f(1010.0, 90.0, 830.0);
	glVertex3f(1010.0, 0.0, 830.0);
	glEnd();
	
	//deret kanan c
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(840.0, 0.0, 810.0);
	glVertex3f(840.0, 90.0, 810.0);
	glVertex3f(810.0, 90.0, 810.0);
	glVertex3f(810.0, 0.0, 810.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(840.0, 0.0, 830.0);
	glVertex3f(840.0, 90.0, 830.0);
	glVertex3f(810.0, 90.0, 830.0);
	glVertex3f(810.0, 0.0, 830.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(840.0, 90.0, 830.0);
	glVertex3f(840.0, 90.0, 810.0);
	glVertex3f(810.0, 90.0, 810.0);
	glVertex3f(810.0, 90.0, 830.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(840.0, 0.0, 810.0);
	glVertex3f(840.0, 90.0, 810.0);
	glVertex3f(840.0, 90.0, 830.0);
	glVertex3f(840.0, 0.0, 830.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(810.0, 0.0, 810.0);
	glVertex3f(810.0, 90.0, 810.0);
	glVertex3f(810.0, 90.0, 830.0);
	glVertex3f(810.0, 0.0, 830.0);
	glEnd();
	
	// deret kanan d
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(1240.0, 0.0, 610.0);
	glVertex3f(1240.0, 90.0, 610.0);
	glVertex3f(1210.0, 90.0, 610.0);
	glVertex3f(1210.0, 0.0, 610.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(1240.0, 0.0, 630.0);
	glVertex3f(1240.0, 90.0, 630.0);
	glVertex3f(1210.0, 90.0, 630.0);
	glVertex3f(1210.0, 0.0, 630.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(1240.0, 90.0, 630.0);
	glVertex3f(1240.0, 90.0, 610.0);
	glVertex3f(1210.0, 90.0, 610.0);
	glVertex3f(1210.0, 90.0, 630.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(1240.0, 0.0, 610.0);
	glVertex3f(1240.0, 90.0, 610.0);
	glVertex3f(1240.0, 90.0, 630.0);
	glVertex3f(1240.0, 0.0, 630.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(1210.0, 0.0, 610.0);
	glVertex3f(1210.0, 90.0, 610.0);
	glVertex3f(1210.0, 90.0, 630.0);
	glVertex3f(1210.0, 0.0, 630.0);
	glEnd();
	
	//deret kanan e
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(1240.0, 0.0, 410.0);
	glVertex3f(1240.0, 90.0, 410.0);
	glVertex3f(1210.0, 90.0, 410.0);
	glVertex3f(1210.0, 0.0, 410.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(1240.0, 0.0, 430.0);
	glVertex3f(1240.0, 90.0, 430.0);
	glVertex3f(1210.0, 90.0, 430.0);
	glVertex3f(1210.0, 0.0, 430.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(1240.0, 90.0, 430.0);
	glVertex3f(1240.0, 90.0, 410.0);
	glVertex3f(1210.0, 90.0, 410.0);
	glVertex3f(1210.0, 90.0, 430.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(1240.0, 0.0, 410.0);
	glVertex3f(1240.0, 90.0, 410.0);
	glVertex3f(1240.0, 90.0, 430.0);
	glVertex3f(1240.0, 0.0, 430.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(1210.0, 0.0, 410.0);
	glVertex3f(1210.0, 90.0, 410.0);
	glVertex3f(1210.0, 90.0, 430.0);
	glVertex3f(1210.0, 0.0, 430.0);
	glEnd();
	
	//deret kanan f
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(1240.0, 0.0, 210.0);
	glVertex3f(1240.0, 90.0, 210.0);
	glVertex3f(1210.0, 90.0, 210.0);
	glVertex3f(1210.0, 0.0, 210.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(1240.0, 0.0, 230.0);
	glVertex3f(1240.0, 90.0, 230.0);
	glVertex3f(1210.0, 90.0, 230.0);
	glVertex3f(1210.0, 0.0, 230.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(1240.0, 90.0, 230.0);
	glVertex3f(1240.0, 90.0, 210.0);
	glVertex3f(1210.0, 90.0, 210.0);
	glVertex3f(1210.0, 90.0, 230.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(1240.0, 0.0, 210.0);
	glVertex3f(1240.0, 90.0, 210.0);
	glVertex3f(1240.0, 90.0, 230.0);
	glVertex3f(1240.0, 0.0, 230.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(1210.0, 0.0, 210.0);
	glVertex3f(1210.0, 90.0, 210.0);
	glVertex3f(1210.0, 90.0, 230.0);
	glVertex3f(1210.0, 0.0, 230.0);
	glEnd();
	
	//deret kanan g
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(1240.0, 0.0, 10.0);
	glVertex3f(1240.0, 90.0, 10.0);
	glVertex3f(1210.0, 90.0, 10.0);
	glVertex3f(1210.0, 0.0, 10.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(1240.0, 0.0, 30.0);
	glVertex3f(1240.0, 90.0, 30.0);
	glVertex3f(1210.0, 90.0, 30.0);
	glVertex3f(1210.0, 0.0, 30.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(1240.0, 90.0, 30.0);
	glVertex3f(1240.0, 90.0, 10.0);
	glVertex3f(1210.0, 90.0, 10.0);
	glVertex3f(1210.0, 90.0, 30.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(1240.0, 0.0, 10.0);
	glVertex3f(1240.0, 90.0, 10.0);
	glVertex3f(1240.0, 90.0, 30.0);
	glVertex3f(1240.0, 0.0, 30.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(1210.0, 0.0, 10.0);
	glVertex3f(1210.0, 90.0, 10.0);
	glVertex3f(1210.0, 90.0, 30.0);
	glVertex3f(1210.0, 0.0, 30.0);
	glEnd();
	
	//deret kanan h
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(1240.0, 0.0, -210.0);
	glVertex3f(1240.0, 90.0, -210.0);
	glVertex3f(1210.0, 90.0, -210.0);
	glVertex3f(1210.0, 0.0, -210.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(1240.0, 0.0, -230.0);
	glVertex3f(1240.0, 90.0, -230.0);
	glVertex3f(1210.0, 90.0, -230.0);
	glVertex3f(1210.0, 0.0, -230.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(1240.0, 90.0, -230.0);
	glVertex3f(1240.0, 90.0, -210.0);
	glVertex3f(1210.0, 90.0, -210.0);
	glVertex3f(1210.0, 90.0, -230.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(1240.0, 0.0, -210.0);
	glVertex3f(1240.0, 90.0, -210.0);
	glVertex3f(1240.0, 90.0, -230.0);
	glVertex3f(1240.0, 0.0, -230.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(1210.0, 0.0, -210.0);
	glVertex3f(1210.0, 90.0, -210.0);
	glVertex3f(1210.0, 90.0, -230.0);
	glVertex3f(1210.0, 0.0, -230.0);
	glEnd();
	
	//deret kanan i
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(1240.0, 0.0, -410.0);
	glVertex3f(1240.0, 90.0, -410.0);
	glVertex3f(1210.0, 90.0, -410.0);
	glVertex3f(1210.0, 0.0, -410.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(1240.0, 0.0, -430.0);
	glVertex3f(1240.0, 90.0, -430.0);
	glVertex3f(1210.0, 90.0, -430.0);
	glVertex3f(1210.0, 0.0, -430.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(1240.0, 90.0, -430.0);
	glVertex3f(1240.0, 90.0, -410.0);
	glVertex3f(1210.0, 90.0, -410.0);
	glVertex3f(1210.0, 90.0, -430.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(1240.0, 0.0, -410.0);
	glVertex3f(1240.0, 90.0, -410.0);
	glVertex3f(1240.0, 90.0, -430.0);
	glVertex3f(1240.0, 0.0, -430.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(1210.0, 0.0, -410.0);
	glVertex3f(1210.0, 90.0, -410.0);
	glVertex3f(1210.0, 90.0, -430.0);
	glVertex3f(1210.0, 0.0, -430.0);
	glEnd();
	
	//deret kanan j
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(1240.0, 0.0, -610.0);
	glVertex3f(1240.0, 90.0, -610.0);
	glVertex3f(1210.0, 90.0, -610.0);
	glVertex3f(1210.0, 0.0, -610.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(1240.0, 0.0, -630.0);
	glVertex3f(1240.0, 90.0, -630.0);
	glVertex3f(1210.0, 90.0, -630.0);
	glVertex3f(1210.0, 0.0, -630.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(1240.0, 90.0, -630.0);
	glVertex3f(1240.0, 90.0, -610.0);
	glVertex3f(1210.0, 90.0, -610.0);
	glVertex3f(1210.0, 90.0, -630.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(1240.0, 0.0, -610.0);
	glVertex3f(1240.0, 90.0, -610.0);
	glVertex3f(1240.0, 90.0, -630.0);
	glVertex3f(1240.0, 0.0, -630.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(1210.0, 0.0, -610.0);
	glVertex3f(1210.0, 90.0, -610.0);
	glVertex3f(1210.0, 90.0, -630.0);
	glVertex3f(1210.0, 0.0, -630.0);
	glEnd();
	
	//deret kanan k
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(1240.0, 0.0, -810.0);
	glVertex3f(1240.0, 90.0, -810.0);
	glVertex3f(1210.0, 90.0, -810.0);
	glVertex3f(1210.0, 0.0, -810.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(1240.0, 0.0, -830.0);
	glVertex3f(1240.0, 90.0, -830.0);
	glVertex3f(1210.0, 90.0, -830.0);
	glVertex3f(1210.0, 0.0, -830.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(1240.0, 90.0, -830.0);
	glVertex3f(1240.0, 90.0, -810.0);
	glVertex3f(1210.0, 90.0, -810.0);
	glVertex3f(1210.0, 90.0, -830.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(1240.0, 0.0, -810.0);
	glVertex3f(1240.0, 90.0, -810.0);
	glVertex3f(1240.0, 90.0, -830.0);
	glVertex3f(1240.0, 0.0, -830.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(1210.0, 0.0, -810.0);
	glVertex3f(1210.0, 90.0, -810.0);
	glVertex3f(1210.0, 90.0, -830.0);
	glVertex3f(1210.0, 0.0, -830.0);
	glEnd();
	
	//deret kanan l
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(1240.0, 0.0, -1010.0);
	glVertex3f(1240.0, 90.0, -1010.0);
	glVertex3f(1210.0, 90.0, -1010.0);
	glVertex3f(1210.0, 0.0, -1010.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(1240.0, 0.0, -1030.0);
	glVertex3f(1240.0, 90.0, -1030.0);
	glVertex3f(1210.0, 90.0, -1030.0);
	glVertex3f(1210.0, 0.0, -1030.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(1240.0, 90.0, -1030.0);
	glVertex3f(1240.0, 90.0, -1010.0);
	glVertex3f(1210.0, 90.0, -1010.0);
	glVertex3f(1210.0, 90.0, -1030.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(1240.0, 0.0, -1010.0);
	glVertex3f(1240.0, 90.0, -1010.0);
	glVertex3f(1240.0, 90.0, -1030.0);
	glVertex3f(1240.0, 0.0, -1030.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(1210.0, 0.0, -1010.0);
	glVertex3f(1210.0, 90.0, -1010.0);
	glVertex3f(1210.0, 90.0, -1030.0);
	glVertex3f(1210.0, 0.0, -1030.0);
	glEnd();
	
	
	//TIGA
	//deret belakang a
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(1240.0, 0.0,	-1270.0);
	glVertex3f(1240.0, 90.0,	-1270.0);
	glVertex3f(1210.0, 90.0,	-1270.0);
	glVertex3f(1210.0, 0.0, -1270.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(1240.0, 0.0, -1290.0);
	glVertex3f(1240.0, 90.0, -1290.0);
	glVertex3f(1210.0, 90.0, -1290.0);
	glVertex3f(1210.0, 0.0, -1290.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(1240.0, 90.0, -1290.0);
	glVertex3f(1240.0, 90.0, -1270.0);
	glVertex3f(1210.0, 90.0, -1270.0);
	glVertex3f(1210.0, 90.0, -1290.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(1240.0, 0.0, -1270.0);
	glVertex3f(1240.0, 90.0, -1270.0);
	glVertex3f(1240.0, 90.0, -1290.0);
	glVertex3f(1240.0, 0.0, -1290.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(1210.0, 0.0, -1270.0);
	glVertex3f(1210.0, 90.0, -1270.0);
	glVertex3f(1210.0, 90.0, -1290.0);
	glVertex3f(1210.0, 0.0, -1290.0);
	glEnd();
	
	//deret belakang b
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(1040.0, 0.0,	-1270.0);
	glVertex3f(1040.0, 90.0,	-1270.0);
	glVertex3f(1010.0, 90.0,	-1270.0);
	glVertex3f(1010.0, 0.0, -1270.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(1040.0, 0.0, -1290.0);
	glVertex3f(1040.0, 90.0, -1290.0);
	glVertex3f(1010.0, 90.0, -1290.0);
	glVertex3f(1010.0, 0.0, -1290.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(1040.0, 90.0, -1290.0);
	glVertex3f(1040.0, 90.0, -1270.0);
	glVertex3f(1010.0, 90.0, -1270.0);
	glVertex3f(1010.0, 90.0, -1290.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(1040.0, 0.0, -1270.0);
	glVertex3f(1040.0, 90.0, -1270.0);
	glVertex3f(1040.0, 90.0, -1290.0);
	glVertex3f(1040.0, 0.0, -1290.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(1010.0, 0.0, -1270.0);
	glVertex3f(1010.0, 90.0, -1270.0);
	glVertex3f(1010.0, 90.0, -1290.0);
	glVertex3f(1010.0, 0.0, -1290.0);
	glEnd();
	
	//deret belakang c
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(840.0, 0.0,	-1270.0);
	glVertex3f(840.0, 90.0,	-1270.0);
	glVertex3f(810.0, 90.0,	-1270.0);
	glVertex3f(810.0, 0.0, -1270.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(840.0, 0.0, -1290.0);
	glVertex3f(840.0, 90.0, -1290.0);
	glVertex3f(810.0, 90.0, -1290.0);
	glVertex3f(810.0, 0.0, -1290.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(840.0, 90.0, -1290.0);
	glVertex3f(840.0, 90.0, -1270.0);
	glVertex3f(810.0, 90.0, -1270.0);
	glVertex3f(810.0, 90.0, -1290.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(840.0, 0.0, -1270.0);
	glVertex3f(840.0, 90.0, -1270.0);
	glVertex3f(840.0, 90.0, -1290.0);
	glVertex3f(840.0, 0.0, -1290.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(810.0, 0.0, -1270.0);
	glVertex3f(810.0, 90.0, -1270.0);
	glVertex3f(810.0, 90.0, -1290.0);
	glVertex3f(810.0, 0.0, -1290.0);
	glEnd();
	
	//deret belakang d
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(640.0, 0.0,	-1270.0);
	glVertex3f(640.0, 90.0,	-1270.0);
	glVertex3f(610.0, 90.0,	-1270.0);
	glVertex3f(610.0, 0.0, -1270.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(640.0, 0.0, -1290.0);
	glVertex3f(640.0, 90.0, -1290.0);
	glVertex3f(610.0, 90.0, -1290.0);
	glVertex3f(610.0, 0.0, -1290.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(640.0, 90.0, -1290.0);
	glVertex3f(640.0, 90.0, -1270.0);
	glVertex3f(610.0, 90.0, -1270.0);
	glVertex3f(610.0, 90.0, -1290.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(640.0, 0.0, -1270.0);
	glVertex3f(640.0, 90.0, -1270.0);
	glVertex3f(640.0, 90.0, -1290.0);
	glVertex3f(640.0, 0.0, -1290.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(610.0, 0.0, -1270.0);
	glVertex3f(610.0, 90.0, -1270.0);
	glVertex3f(610.0, 90.0, -1290.0);
	glVertex3f(610.0, 0.0, -1290.0);
	glEnd();
	
	//deret belakang e
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(440.0, 0.0,	-1270.0);
	glVertex3f(440.0, 90.0,	-1270.0);
	glVertex3f(410.0, 90.0,	-1270.0);
	glVertex3f(410.0, 0.0, -1270.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(440.0, 0.0, -1290.0);
	glVertex3f(440.0, 90.0, -1290.0);
	glVertex3f(410.0, 90.0, -1290.0);
	glVertex3f(410.0, 0.0, -1290.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(440.0, 90.0, -1290.0);
	glVertex3f(440.0, 90.0, -1270.0);
	glVertex3f(410.0, 90.0, -1270.0);
	glVertex3f(410.0, 90.0, -1290.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(440.0, 0.0, -1270.0);
	glVertex3f(440.0, 90.0, -1270.0);
	glVertex3f(440.0, 90.0, -1290.0);
	glVertex3f(440.0, 0.0, -1290.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(410.0, 0.0, -1270.0);
	glVertex3f(410.0, 90.0, -1270.0);
	glVertex3f(410.0, 90.0, -1290.0);
	glVertex3f(410.0, 0.0, -1290.0);
	glEnd();
	
	//deret belakang f
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(240.0, 0.0,	-1270.0);
	glVertex3f(240.0, 90.0,	-1270.0);
	glVertex3f(210.0, 90.0,	-1270.0);
	glVertex3f(210.0, 0.0, -1270.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(240.0, 0.0, -1290.0);
	glVertex3f(240.0, 90.0, -1290.0);
	glVertex3f(210.0, 90.0, -1290.0);
	glVertex3f(210.0, 0.0, -1290.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(240.0, 90.0, -1290.0);
	glVertex3f(240.0, 90.0, -1270.0);
	glVertex3f(210.0, 90.0, -1270.0);
	glVertex3f(210.0, 90.0, -1290.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(240.0, 0.0, -1270.0);
	glVertex3f(240.0, 90.0, -1270.0);
	glVertex3f(240.0, 90.0, -1290.0);
	glVertex3f(240.0, 0.0, -1290.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(210.0, 0.0, -1270.0);
	glVertex3f(210.0, 90.0, -1270.0);
	glVertex3f(210.0, 90.0, -1290.0);
	glVertex3f(210.0, 0.0, -1290.0);
	glEnd();
	
	//deret belakang g
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(20.0, 0.0,	-1270.0);
	glVertex3f(20.0, 90.0,	-1270.0);
	glVertex3f(-10.0, 90.0,	-1270.0);
	glVertex3f(-10.0, 0.0, -1270.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(20.0, 0.0, -1290.0);
	glVertex3f(20.0, 90.0, -1290.0);
	glVertex3f(-10.0, 90.0, -1290.0);
	glVertex3f(-10.0, 0.0, -1290.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(20.0, 90.0, -1290.0);
	glVertex3f(20.0, 90.0, -1270.0);
	glVertex3f(-10.0, 90.0, -1270.0);
	glVertex3f(-10.0, 90.0, -1290.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(20.0, 0.0, -1270.0);
	glVertex3f(20.0, 90.0, -1270.0);
	glVertex3f(20.0, 90.0, -1290.0);
	glVertex3f(20.0, 0.0, -1290.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-10.0, 0.0, -1270.0);
	glVertex3f(-10.0, 90.0, -1270.0);
	glVertex3f(-10.0, 90.0, -1290.0);
	glVertex3f(-10.0, 0.0, -1290.0);
	glEnd();
	
	//deret belakang h
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(-240.0, 0.0,	-1270.0);
	glVertex3f(-240.0, 90.0,	-1270.0);
	glVertex3f(-210.0, 90.0,	-1270.0);
	glVertex3f(-210.0, 0.0, -1270.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 0.0, -1290.0);
	glVertex3f(-240.0, 90.0, -1290.0);
	glVertex3f(-210.0, 90.0, -1290.0);
	glVertex3f(-210.0, 0.0, -1290.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 90.0, -1290.0);
	glVertex3f(-240.0, 90.0, -1270.0);
	glVertex3f(-210.0, 90.0, -1270.0);
	glVertex3f(-210.0, 90.0, -1290.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 0.0, -1270.0);
	glVertex3f(-240.0, 90.0, -1270.0);
	glVertex3f(-240.0, 90.0, -1290.0);
	glVertex3f(-240.0, 0.0, -1290.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-210.0, 0.0, -1270.0);
	glVertex3f(-210.0, 90.0, -1270.0);
	glVertex3f(-210.0, 90.0, -1290.0);
	glVertex3f(-210.0, 0.0, -1290.0);
	glEnd();
	
	//deret belakang i
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(-440.0, 0.0,	-1270.0);
	glVertex3f(-440.0, 90.0,	-1270.0);
	glVertex3f(-410.0, 90.0,	-1270.0);
	glVertex3f(-410.0, 0.0, -1270.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-440.0, 0.0, -1290.0);
	glVertex3f(-440.0, 90.0, -1290.0);
	glVertex3f(-410.0, 90.0, -1290.0);
	glVertex3f(-410.0, 0.0, -1290.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-440.0, 90.0, -1290.0);
	glVertex3f(-440.0, 90.0, -1270.0);
	glVertex3f(-410.0, 90.0, -1270.0);
	glVertex3f(-410.0, 90.0, -1290.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-440.0, 0.0, -1270.0);
	glVertex3f(-440.0, 90.0, -1270.0);
	glVertex3f(-440.0, 90.0, -1290.0);
	glVertex3f(-440.0, 0.0, -1290.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-410.0, 0.0, -1270.0);
	glVertex3f(-410.0, 90.0, -1270.0);
	glVertex3f(-410.0, 90.0, -1290.0);
	glVertex3f(-410.0, 0.0, -1290.0);
	glEnd();
	
	//deret belakang j
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(-640.0, 0.0,	-1270.0);
	glVertex3f(-640.0, 90.0,	-1270.0);
	glVertex3f(-610.0, 90.0,	-1270.0);
	glVertex3f(-610.0, 0.0, -1270.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-640.0, 0.0, -1290.0);
	glVertex3f(-640.0, 90.0, -1290.0);
	glVertex3f(-610.0, 90.0, -1290.0);
	glVertex3f(-610.0, 0.0, -1290.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-640.0, 90.0, -1290.0);
	glVertex3f(-640.0, 90.0, -1270.0);
	glVertex3f(-610.0, 90.0, -1270.0);
	glVertex3f(-610.0, 90.0, -1290.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-640.0, 0.0, -1270.0);
	glVertex3f(-640.0, 90.0, -1270.0);
	glVertex3f(-640.0, 90.0, -1290.0);
	glVertex3f(-640.0, 0.0, -1290.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-610.0, 0.0, -1270.0);
	glVertex3f(-610.0, 90.0, -1270.0);
	glVertex3f(-610.0, 90.0, -1290.0);
	glVertex3f(-610.0, 0.0, -1290.0);
	glEnd();
	
	//deret belakang k
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(-840.0, 0.0, -1270.0);
	glVertex3f(-840.0, 90.0, -1270.0);
	glVertex3f(-810.0, 90.0, -1270.0);
	glVertex3f(-810.0, 0.0, -1270.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-840.0, 0.0, -1290.0);
	glVertex3f(-840.0, 90.0, -1290.0);
	glVertex3f(-810.0, 90.0, -1290.0);
	glVertex3f(-810.0, 0.0, -1290.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-840.0, 90.0, -1290.0);
	glVertex3f(-840.0, 90.0, -1270.0);
	glVertex3f(-810.0, 90.0, -1270.0);
	glVertex3f(-810.0, 90.0, -1290.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-840.0, 0.0, -1270.0);
	glVertex3f(-840.0, 90.0, -1270.0);
	glVertex3f(-840.0, 90.0, -1290.0);
	glVertex3f(-840.0, 0.0, -1290.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-810.0, 0.0, -1270.0);
	glVertex3f(-810.0, 90.0, -1270.0);
	glVertex3f(-810.0, 90.0, -1290.0);
	glVertex3f(-810.0, 9.0, -1290.0);
	glEnd();
	
	//deret belakang l
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(-1040.0, 0.0, -1270.0);
	glVertex3f(-1040.0, 90.0, -1270.0);
	glVertex3f(-1010.0, 90.0, -1270.0);
	glVertex3f(-1010.0, 0.0, -1270.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-1040.0, 0.0, -1290.0);
	glVertex3f(-1040.0, 90.0, -1290.0);
	glVertex3f(-1010.0, 90.0, -1290.0);
	glVertex3f(-1010.0, 0.0, -1290.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-1040.0, 90.0, -1290.0);
	glVertex3f(-1040.0, 90.0, -1270.0);
	glVertex3f(-1010.0, 90.0, -1270.0);
	glVertex3f(-1010.0, 90.0, -1290.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-1040.0, 0.0, -1270.0);
	glVertex3f(-1040.0, 90.0, -1270.0);
	glVertex3f(-1040.0, 90.0, -1290.0);
	glVertex3f(-1040.0, 0.0, -1290.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-1010.0, 0.0, -1270.0);
	glVertex3f(-1010.0, 90.0, -1270.0);
	glVertex3f(-1010.0, 90.0, -1290.0);
	glVertex3f(-1010.0, 9.0, -1290.0);
	glEnd();
	
	//deret belakang m
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(-1240.0, 0.0, -1270.0);
	glVertex3f(-1240.0, 90.0, -1270.0);
	glVertex3f(-1210.0, 90.0, -1270.0);
	glVertex3f(-1210.0, 0.0, -1270.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-1240.0, 0.0, -1290.0);
	glVertex3f(-1240.0, 90.0, -1290.0);
	glVertex3f(-1210.0, 90.0, -1290.0);
	glVertex3f(-1210.0, 0.0, -1290.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-1240.0, 90.0, -1290.0);
	glVertex3f(-1240.0, 90.0, -1270.0);
	glVertex3f(-1210.0, 90.0, -1270.0);
	glVertex3f(-1210.0, 90.0, -1290.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-1240.0, 0.0, -1270.0);
	glVertex3f(-1240.0, 90.0, -1270.0);
	glVertex3f(-1240.0, 90.0, -1290.0);
	glVertex3f(-1240.0, 0.0, -1290.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-1210.0, 0.0, -1270.0);
	glVertex3f(-1210.0, 90.0, -1270.0);
	glVertex3f(-1210.0, 90.0, -1290.0);
	glVertex3f(-1210.0, 9.0, -1290.0);
	glEnd();
	
	//EMPAT
	//deret depan a
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(-640.0, 0.0, 810.0);
	glVertex3f(-640.0, 90.0, 810.0);
	glVertex3f(-610.0, 90.0, 810.0);
	glVertex3f(-610.0, 0.0, 810.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-640.0, 0.0, 830.0);
	glVertex3f(-640.0, 90.0, 830.0);
	glVertex3f(-610.0, 90.0, 830.0);
	glVertex3f(-610.0, 0.0, 830.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-640.0, 90.0, 830.0);
	glVertex3f(-640.0, 90.0, 810.0);
	glVertex3f(-610.0, 90.0, 810.0);
	glVertex3f(-610.0, 90.0, 830.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-640.0, 0.0, 810.0);
	glVertex3f(-640.0, 90.0, 810.0);
	glVertex3f(-640.0, 90.0, 830.0);
	glVertex3f(-640.0, 0.0, 830.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-610.0, 0.0, 810.0);
	glVertex3f(-610.0, 90.0, 810.0);
	glVertex3f(-610.0, 90.0, 830.0);
	glVertex3f(-610.0, 0.0, 830.0);
	glEnd();
	
	//deret depan b
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(-440.0, 0.0, 810.0);
	glVertex3f(-440.0, 90.0, 810.0);
	glVertex3f(-410.0, 90.0, 810.0);
	glVertex3f(-410.0, 0.0, 810.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-440.0, 0.0, 830.0);
	glVertex3f(-440.0, 90.0, 830.0);
	glVertex3f(-410.0, 90.0, 830.0);
	glVertex3f(-410.0, 0.0, 830.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-440.0, 90.0, 830.0);
	glVertex3f(-440.0, 90.0, 810.0);
	glVertex3f(-410.0, 90.0, 810.0);
	glVertex3f(-410.0, 90.0, 830.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-440.0, 0.0, 810.0);
	glVertex3f(-440.0, 90.0, 810.0);
	glVertex3f(-440.0, 90.0, 830.0);
	glVertex3f(-440.0, 0.0, 830.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-410.0, 0.0, 810.0);
	glVertex3f(-410.0, 90.0, 810.0);
	glVertex3f(-410.0, 90.0, 830.0);
	glVertex3f(-410.0, 0.0, 830.0);
	glEnd();
	
	//deret depan c
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(-240.0, 0.0, 810.0);
	glVertex3f(-240.0, 90.0, 810.0);
	glVertex3f(-210.0, 90.0, 810.0);
	glVertex3f(-210.0, 0.0, 810.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 0.0, 830.0);
	glVertex3f(-240.0, 90.0, 830.0);
	glVertex3f(-210.0, 90.0, 830.0);
	glVertex3f(-210.0, 0.0, 830.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 90.0, 830.0);
	glVertex3f(-240.0, 90.0, 810.0);
	glVertex3f(-210.0, 90.0, 810.0);
	glVertex3f(-210.0, 90.0, 830.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 0.0, 810.0);
	glVertex3f(-240.0, 90.0, 810.0);
	glVertex3f(-240.0, 90.0, 830.0);
	glVertex3f(-240.0, 0.0, 830.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-210.0, 0.0, 810.0);
	glVertex3f(-210.0, 90.0, 810.0);
	glVertex3f(-210.0, 90.0, 830.0);
	glVertex3f(-210.0, 0.0, 830.0);
	glEnd();
	
	//deret depan d
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(-640.0, 0.0, 810.0);
	glVertex3f(-640.0, 90.0, 810.0);
	glVertex3f(-610.0, 90.0, 810.0);
	glVertex3f(-610.0, 0.0, 810.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-640.0, 0.0, 830.0);
	glVertex3f(-640.0, 90.0, 830.0);
	glVertex3f(-610.0, 90.0, 830.0);
	glVertex3f(-610.0, 0.0, 830.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-640.0, 90.0, 830.0);
	glVertex3f(-640.0, 90.0, 810.0);
	glVertex3f(-610.0, 90.0, 810.0);
	glVertex3f(-610.0, 90.0, 830.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-640.0, 0.0, 810.0);
	glVertex3f(-640.0, 90.0, 810.0);
	glVertex3f(-640.0, 90.0, 830.0);
	glVertex3f(-640.0, 0.0, 830.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-610.0, 0.0, 810.0);
	glVertex3f(-610.0, 90.0, 810.0);
	glVertex3f(-610.0, 90.0, 830.0);
	glVertex3f(-610.0, 0.0, 830.0);
	glEnd();
	
	//deret depan e
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(-440.0, 0.0, 810.0);
	glVertex3f(-440.0, 90.0, 810.0);
	glVertex3f(-410.0, 90.0, 810.0);
	glVertex3f(-410.0, 0.0, 810.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-440.0, 0.0, 830.0);
	glVertex3f(-440.0, 90.0, 830.0);
	glVertex3f(-410.0, 90.0, 830.0);
	glVertex3f(-410.0, 0.0, 830.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-440.0, 90.0, 830.0);
	glVertex3f(-440.0, 90.0, 810.0);
	glVertex3f(-410.0, 90.0, 810.0);
	glVertex3f(-410.0, 90.0, 830.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-440.0, 0.0, 810.0);
	glVertex3f(-440.0, 90.0, 810.0);
	glVertex3f(-440.0, 90.0, 830.0);
	glVertex3f(-440.0, 0.0, 830.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-410.0, 0.0, 810.0);
	glVertex3f(-410.0, 90.0, 810.0);
	glVertex3f(-410.0, 90.0, 830.0);
	glVertex3f(-410.0, 0.0, 830.0);
	glEnd();
	
	//deret depan f
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(-240.0, 0.0, 810.0);
	glVertex3f(-240.0, 90.0, 810.0);
	glVertex3f(-210.0, 90.0, 810.0);
	glVertex3f(-210.0, 0.0, 810.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 0.0, 830.0);
	glVertex3f(-240.0, 90.0, 830.0);
	glVertex3f(-210.0, 90.0, 830.0);
	glVertex3f(-210.0, 0.0, 830.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 90.0, 830.0);
	glVertex3f(-240.0, 90.0, 810.0);
	glVertex3f(-210.0, 90.0, 810.0);
	glVertex3f(-210.0, 90.0, 830.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 0.0, 810.0);
	glVertex3f(-240.0, 90.0, 810.0);
	glVertex3f(-240.0, 90.0, 830.0);
	glVertex3f(-240.0, 0.0, 830.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-210.0, 0.0, 810.0);
	glVertex3f(-210.0, 90.0, 810.0);
	glVertex3f(-210.0, 90.0, 830.0);
	glVertex3f(-210.0, 0.0, 830.0);
	glEnd();
	
	//deret depan g
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(440.0, 0.0, 810.0);
	glVertex3f(440.0, 90.0, 810.0);
	glVertex3f(410.0, 90.0, 810.0);
	glVertex3f(410.0, 0.0, 810.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(440.0, 0.0, 830.0);
	glVertex3f(440.0, 90.0, 830.0);
	glVertex3f(410.0, 90.0, 830.0);
	glVertex3f(410.0, 0.0, 830.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(440.0, 90.0, 830.0);
	glVertex3f(440.0, 90.0, 810.0);
	glVertex3f(410.0, 90.0, 810.0);
	glVertex3f(410.0, 90.0, 830.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(440.0, 0.0, 810.0);
	glVertex3f(440.0, 90.0, 810.0);
	glVertex3f(440.0, 90.0, 830.0);
	glVertex3f(440.0, 0.0, 830.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(410.0, 0.0, 810.0);
	glVertex3f(410.0, 90.0, 810.0);
	glVertex3f(410.0, 90.0, 830.0);
	glVertex3f(410.0, 0.0, 830.0);
	glEnd();
	
	//deret depan h
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(240.0, 0.0, 810.0);
	glVertex3f(240.0, 90.0, 810.0);
	glVertex3f(210.0, 90.0, 810.0);
	glVertex3f(210.0, 0.0, 810.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(240.0, 0.0, 830.0);
	glVertex3f(240.0, 90.0, 830.0);
	glVertex3f(210.0, 90.0, 830.0);
	glVertex3f(210.0, 0.0, 830.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(240.0, 90.0, 830.0);
	glVertex3f(240.0, 90.0, 810.0);
	glVertex3f(210.0, 90.0, 810.0);
	glVertex3f(210.0, 90.0, 830.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(240.0, 0.0, 810.0);
	glVertex3f(240.0, 90.0, 810.0);
	glVertex3f(240.0, 90.0, 830.0);
	glVertex3f(240.0, 0.0, 830.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(210.0, 0.0, 810.0);
	glVertex3f(210.0, 90.0, 810.0);
	glVertex3f(210.0, 90.0, 830.0);
	glVertex3f(210.0, 0.0, 830.0);
	glEnd();
	
	//deret depan i
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(640.0, 0.0, 810.0);
	glVertex3f(640.0, 90.0, 810.0);
	glVertex3f(610.0, 90.0, 810.0);
	glVertex3f(610.0, 0.0, 810.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(640.0, 0.0, 830.0);
	glVertex3f(640.0, 90.0, 830.0);
	glVertex3f(610.0, 90.0, 830.0);
	glVertex3f(610.0, 0.0, 830.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(640.0, 90.0, 830.0);
	glVertex3f(640.0, 90.0, 810.0);
	glVertex3f(610.0, 90.0, 810.0);
	glVertex3f(610.0, 90.0, 830.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(640.0, 0.0, 810.0);
	glVertex3f(640.0, 90.0, 810.0);
	glVertex3f(640.0, 90.0, 830.0);
	glVertex3f(640.0, 0.0, 830.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(610.0, 0.0, 810.0);
	glVertex3f(610.0, 90.0, 810.0);
	glVertex3f(610.0, 90.0, 830.0);
	glVertex3f(610.0, 0.0, 830.0);
	glEnd();
	
	//deret depan j
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(440.0, 0.0, 810.0);
	glVertex3f(440.0, 90.0, 810.0);
	glVertex3f(410.0, 90.0, 810.0);
	glVertex3f(410.0, 0.0, 810.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(440.0, 0.0, 830.0);
	glVertex3f(440.0, 90.0, 830.0);
	glVertex3f(410.0, 90.0, 830.0);
	glVertex3f(410.0, 0.0, 830.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(440.0, 90.0, 830.0);
	glVertex3f(440.0, 90.0, 810.0);
	glVertex3f(410.0, 90.0, 810.0);
	glVertex3f(410.0, 90.0, 830.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(440.0, 0.0, 810.0);
	glVertex3f(440.0, 90.0, 810.0);
	glVertex3f(440.0, 90.0, 830.0);
	glVertex3f(440.0, 0.0, 830.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(410.0, 0.0, 810.0);
	glVertex3f(410.0, 90.0, 810.0);
	glVertex3f(410.0, 90.0, 830.0);
	glVertex3f(410.0, 0.0, 830.0);
	glEnd();
	
	//deret depan k
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(240.0, 0.0, 810.0);
	glVertex3f(240.0, 90.0, 810.0);
	glVertex3f(210.0, 90.0, 810.0);
	glVertex3f(210.0, 0.0, 810.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(240.0, 0.0, 830.0);
	glVertex3f(240.0, 90.0, 830.0);
	glVertex3f(210.0, 90.0, 830.0);
	glVertex3f(210.0, 0.0, 830.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(240.0, 90.0, 830.0);
	glVertex3f(240.0, 90.0, 810.0);
	glVertex3f(210.0, 90.0, 810.0);
	glVertex3f(210.0, 90.0, 830.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(240.0, 0.0, 810.0);
	glVertex3f(240.0, 90.0, 810.0);
	glVertex3f(240.0, 90.0, 830.0);
	glVertex3f(240.0, 0.0, 830.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(210.0, 0.0, 810.0);
	glVertex3f(210.0, 90.0, 810.0);
	glVertex3f(210.0, 90.0, 830.0);
	glVertex3f(210.0, 0.0, 830.0);
	glEnd();
	
	//deret depan l
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(240.0, 0.0, 1040.0);
	glVertex3f(240.0, 90.0, 1040.0);
	glVertex3f(210.0, 90.0, 1040.0);
	glVertex3f(210.0, 0.0, 1040.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(240.0, 0.0, 1060.0);
	glVertex3f(240.0, 90.0, 1060.0);
	glVertex3f(210.0, 90.0, 1060.0);
	glVertex3f(210.0, 0.0, 1060.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(240.0, 90.0, 1060.0);
	glVertex3f(240.0, 90.0, 1040.0);
	glVertex3f(210.0, 90.0, 1040.0);
	glVertex3f(210.0, 90.0, 1060.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(240.0, 0.0, 1040.0);
	glVertex3f(240.0, 90.0, 1040.0);
	glVertex3f(240.0, 90.0, 1060.0);
	glVertex3f(240.0, 0.0, 1060.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(210.0, 0.0, 1040.0);
	glVertex3f(210.0, 90.0, 1040.0);
	glVertex3f(210.0, 90.0, 1060.0);
	glVertex3f(210.0, 0.0, 1060.0);
	glEnd();
	
	//deret depan m
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(240.0, 0.0, 1230.0);
	glVertex3f(240.0, 90.0, 1230.0);
	glVertex3f(210.0, 90.0, 1230.0);
	glVertex3f(210.0, 0.0, 1230.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(240.0, 0.0, 1250.0);
	glVertex3f(240.0, 90.0, 1250.0);
	glVertex3f(210.0, 90.0, 1250.0);
	glVertex3f(210.0, 0.0, 1250.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(240.0, 90.0, 1250.0);
	glVertex3f(240.0, 90.0, 1230.0);
	glVertex3f(210.0, 90.0, 1230.0);
	glVertex3f(210.0, 90.0, 1250.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(240.0, 0.0, 1230.0);
	glVertex3f(240.0, 90.0, 1230.0);
	glVertex3f(240.0, 90.0, 1250.0);
	glVertex3f(240.0, 0.0, 1250.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(210.0, 0.0, 1230.0);
	glVertex3f(210.0, 90.0, 1230.0);
	glVertex3f(210.0, 90.0, 1250.0);
	glVertex3f(210.0, 0.0, 1250.0);
	glEnd();
	
	//deret depan n
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(-240.0, 0.0, 1040.0);
	glVertex3f(-240.0, 90.0, 1040.0);
	glVertex3f(-210.0, 90.0, 1040.0);
	glVertex3f(-210.0, 0.0, 1040.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 0.0, 1060.0);
	glVertex3f(-240.0, 90.0, 1060.0);
	glVertex3f(-210.0, 90.0, 1060.0);
	glVertex3f(-210.0, 0.0, 1060.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 90.0, 1060.0);
	glVertex3f(-240.0, 90.0, 1040.0);
	glVertex3f(-210.0, 90.0, 1040.0);
	glVertex3f(-210.0, 90.0, 1060.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 0.0, 1040.0);
	glVertex3f(-240.0, 90.0, 1040.0);
	glVertex3f(-240.0, 90.0, 1060.0);
	glVertex3f(-240.0, 0.0, 1060.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-210.0, 0.0, 1040.0);
	glVertex3f(-210.0, 90.0, 1040.0);
	glVertex3f(-210.0, 90.0, 1060.0);
	glVertex3f(-210.0, 0.0, 1060.0);
	glEnd();
	
	//deret depan 0
	//depan
	glBegin(GL_POLYGON);
	glColor3f(0.64,	0.21, 0.21);
	glVertex3f(-240.0, 0.0, 1230.0);
	glVertex3f(-240.0, 90.0, 1230.0);
	glVertex3f(-210.0, 90.0, 1230.0);
	glVertex3f(-210.0, 0.0, 1230.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 0.0, 1250.0);
	glVertex3f(-240.0, 90.0, 1250.0);
	glVertex3f(-210.0, 90.0, 1250.0);
	glVertex3f(-210.0, 0.0, 1250.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 90.0, 1250.0);
	glVertex3f(-240.0, 90.0, 1230.0);
	glVertex3f(-210.0, 90.0, 1230.0);
	glVertex3f(-210.0, 90.0, 1250.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-240.0, 0.0, 1230.0);
	glVertex3f(-240.0, 90.0, 1230.0);
	glVertex3f(-240.0, 90.0, 1250.0);
	glVertex3f(-240.0, 0.0, 1250.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-210.0, 0.0, 1230.0);
	glVertex3f(-210.0, 90.0, 1230.0);
	glVertex3f(-210.0, 90.0, 1250.0);
	glVertex3f(-210.0, 0.0, 1250.0);
	glEnd();
	
	
	//horizontal kiri depan atas
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-230.0, 65.0, 810.0);
	glVertex3f(-230.0, 70.0, 810.0);
	glVertex3f(-230.0, 70.0, 1550.0);
	glVertex3f(-230.0, 65.0, 1550.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-220.0, 70.0, 810.0);
	glVertex3f(-220.0, 65.0, 810.0);
	glVertex3f(-220.0, 65.0, 1550.0);
	glVertex3f(-220.0, 70.0, 1550.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-230.0, 70.0, 810.0);
	glVertex3f(-230.0, 70.0, 1550.0);
	glVertex3f(-220.0, 70.0, 1550.0);
	glVertex3f(-220.0, 70.0, 810.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-230.0, 65.0, 810.0);
	glVertex3f(-230.0, 65.0, 1550.0);
	glVertex3f(-220.0, 65.0, 1550.0);
	glVertex3f(-220.0, 65.0, 810.0);
	glEnd();
	
	//horizontal kiri depan bawah
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-230.0, 0.0, 810.0);
	glVertex3f(-230.0, 50.0, 810.0);
	glVertex3f(-230.0, 50.0, 1550.0);
	glVertex3f(-230.0, 0.0, 1550.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-220.0, 50.0, 810.0);
	glVertex3f(-220.0, 0.0, 810.0);
	glVertex3f(-220.0, 0.0, 1550.0);
	glVertex3f(-220.0, 50.0, 1550.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-230.0, 50.0, 810.0);
	glVertex3f(-230.0, 50.0, 1550.0);
	glVertex3f(-220.0, 50.0, 1550.0);
	glVertex3f(-220.0, 50.0, 810.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-230.0, 0.0, 810.0);
	glVertex3f(-230.0, 0.0, 1550.0);
	glVertex3f(-220.0, 0.0, 1550.0);
	glVertex3f(-220.0, 0.0, 810.0);
	glEnd();
	
	
	//horizontal kanan depan atas
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(230.0, 65.0, 810.0);
	glVertex3f(230.0, 70.0, 810.0);
	glVertex3f(230.0, 70.0, 1550.0);
	glVertex3f(230.0, 65.0, 1550.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(220.0, 70.0, 810.0);
	glVertex3f(220.0, 65.0, 810.0);
	glVertex3f(220.0, 65.0, 1550.0);
	glVertex3f(220.0, 70.0, 1550.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(230.0, 70.0, 810.0);
	glVertex3f(230.0, 70.0, 1550.0);
	glVertex3f(220.0, 70.0, 1550.0);
	glVertex3f(220.0, 70.0, 810.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(230.0, 65.0, 810.0);
	glVertex3f(230.0, 65.0, 1550.0);
	glVertex3f(220.0, 65.0, 1550.0);
	glVertex3f(220.0, 65.0, 810.0);
	glEnd();
	
	//horizontal kanan depan bawah
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(230.0, 0.0, 810.0);
	glVertex3f(230.0, 50.0, 810.0);
	glVertex3f(230.0, 50.0, 1550.0);
	glVertex3f(230.0, 0.0, 1550.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(220.0, 50.0, 810.0);
	glVertex3f(220.0, 0.0, 810.0);
	glVertex3f(220.0, 0.0, 1550.0);
	glVertex3f(220.0, 50.0, 1550.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(230.0, 50.0, 810.0);
	glVertex3f(230.0, 50.0, 1550.0);
	glVertex3f(220.0, 50.0, 1550.0);
	glVertex3f(220.0, 50.0, 810.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(230.0, 0.0, 810.0);
	glVertex3f(230.0, 0.0, 1550.0);
	glVertex3f(220.0, 0.0, 1550.0);
	glVertex3f(220.0, 0.0, 810.0);
	glEnd();
	
	
		//HORIZONTAL 1
	//depan
	//lBegin(GL_POLYGON);
	//lColor3f(1.0, 0.0, 0.0);
	//lVertex3f(-810.0, 565.0, -685.0);
	//lVertex3f(-810.0, 570.0, -685.0);
	//lVertex3f(810.0, 570.0, -685.0);
	//lVertex3f(810.0, 565.0, -685.0);
	//lEnd();
	
	//horizontal belakang atas
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-1210.0, 65.0, -1285.0);
	glVertex3f(-1210.0, 70.0, -1285.0);
	glVertex3f(1210.0, 70.0, -1285.0);
	glVertex3f(1210.0, 65.0, -1285.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-1210.0, 70.0, -1275.0);
	glVertex3f(-1210.0, 65.0, -1275.0);
	glVertex3f(1210.0, 65.0, -1275.0);
	glVertex3f(1210.0, 70.0, -1275.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-1210.0, 70.0, -1285.0);
	glVertex3f(-1210.0, 70.0, -1275.0);
	glVertex3f(1210.0, 70.0, -1275.0);
	glVertex3f(1210.0, 70.0, -1285.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-1210.0, 65.0, -1285.0);
	glVertex3f(-1210.0, 65.0, -1275.0);
	glVertex3f(1210.0, 65.0, -1275.0);
	glVertex3f(1210.0, 65.0, -1285.0);
	glEnd();
	
	//horizontal belakang bawah
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-1210.0, 0.0, -1285.0);
	glVertex3f(-1210.0, 50.0, -1285.0);
	glVertex3f(1210.0, 50.0, -1285.0);
	glVertex3f(1210.0, 0.0, -1285.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-1210.0, 50.0, -1275.0);
	glVertex3f(-1210.0, 0.0, -1275.0);
	glVertex3f(1210.0, 0.0, -1275.0);
	glVertex3f(1210.0, 50.0, -1275.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-1210.0, 50.0, -1285.0);
	glVertex3f(-1210.0, 50.0, -1275.0);
	glVertex3f(1210.0, 50.0, -1275.0);
	glVertex3f(1210.0, 50.0, -1285.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-1210.0, 0.0, -1285.0);
	glVertex3f(-1210.0, 0.0, -1275.0);
	glVertex3f(1210.0, 0.0, -1275.0);
	glVertex3f(1210.0, 0.0, -1285.0);
	glEnd();
	
	//horizontal depan kanan atas
	//depan
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(210.0, 65.0, 815.0);
	glVertex3f(210.0, 70.0, 815.0);
	glVertex3f(1210.0, 70.0, 815.0);
	glVertex3f(1210.0, 65.0, 815.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(210.0, 70.0, 825.0);
	glVertex3f(210.0, 65.0, 825.0);
	glVertex3f(1210.0, 65.0, 825.0);
	glVertex3f(1210.0, 70.0, 825.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(210.0, 70.0, 815.0);
	glVertex3f(210.0, 70.0, 825.0);
	glVertex3f(1210.0, 70.0, 825.0);
	glVertex3f(1210.0, 70.0, 815.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(210.0, 65.0, 815.0);
	glVertex3f(210.0, 65.0, 825.0);
	glVertex3f(1210.0, 65.0, 825.0);
	glVertex3f(1210.0, 65.0, 815.0);
	glEnd();
	
	//horizontal depan kanan bawah
	//depan
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(210.0, 0.0, 815.0);
	glVertex3f(210.0, 50.0, 815.0);
	glVertex3f(1210.0, 50.0, 815.0);
	glVertex3f(1210.0, 0.0, 815.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(210.0, 50.0, 825.0);
	glVertex3f(210.0, 0.0, 825.0);
	glVertex3f(1210.0, 0.0, 825.0);
	glVertex3f(1210.0, 50.0, 825.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(210.0, 50.0, 815.0);
	glVertex3f(210.0, 50.0, 825.0);
	glVertex3f(1210.0, 50.0, 825.0);
	glVertex3f(1210.0, 50.0, 815.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(210.0, 0.0, 815.0);
	glVertex3f(210.0, 0.0, 825.0);
	glVertex3f(1210.0, 0.0, 825.0);
	glVertex3f(1210.0, 0.0, 815.0);
	glEnd();
	
	//horizontal depan kiri atas
	//depan
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-210.0, 65.0, 815.0);
	glVertex3f(-210.0, 70.0, 815.0);
	glVertex3f(-1210.0, 70.0, 815.0);
	glVertex3f(-1210.0, 65.0, 815.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-210.0, 70.0, 825.0);
	glVertex3f(-210.0, 65.0, 825.0);
	glVertex3f(-1210.0, 65.0, 825.0);
	glVertex3f(-1210.0, 70.0, 825.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-210.0, 70.0, 815.0);
	glVertex3f(-210.0, 70.0, 825.0);
	glVertex3f(-1210.0, 70.0, 825.0);
	glVertex3f(-1210.0, 70.0, 815.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-210.0, 65.0, 815.0);
	glVertex3f(-210.0, 65.0, 825.0);
	glVertex3f(-1210.0, 65.0, 825.0);
	glVertex3f(-1210.0, 65.0, 815.0);
	glEnd();
	
	//horizontal depan kiri bawah
	//depan
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-210.0, 0.0, 815.0);
	glVertex3f(-210.0, 50.0, 815.0);
	glVertex3f(-1210.0, 50.0, 815.0);
	glVertex3f(-1210.0, 0.0, 815.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-210.0, 50.0, 825.0);
	glVertex3f(-210.0, 0.0, 825.0);
	glVertex3f(-1210.0, 0.0, 825.0);
	glVertex3f(-1210.0, 50.0, 825.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-210.0, 50.0, 815.0);
	glVertex3f(-210.0, 50.0, 825.0);
	glVertex3f(-1210.0, 50.0, 825.0);
	glVertex3f(-1210.0, 50.0, 815.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-210.0, 0.0, 815.0);
	glVertex3f(-210.0, 0.0, 825.0);
	glVertex3f(-1210.0, 0.0, 825.0);
	glVertex3f(-1210.0, 0.0, 815.0);
	glEnd();
	
	//horizontal kiri atas
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-1230.0, 65.0, -1275.0);
	glVertex3f(-1230.0, 70.0, -1275.0);
	glVertex3f(-1230.0, 70.0, 810.0);
	glVertex3f(-1230.0, 65.0, 810.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-1220.0, 70.0, -1275.0);
	glVertex3f(-1220.0, 65.0, -1275.0);
	glVertex3f(-1220.0, 65.0, 810.0);
	glVertex3f(-1220.0, 70.0, 810.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-1230.0, 70.0, -1275.0);
	glVertex3f(-1230.0, 70.0, 810.0);
	glVertex3f(-1220.0, 70.0, 810.0);
	glVertex3f(-1220.0, 70.0, -1275.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-1230.0, 65.0, -1275.0);
	glVertex3f(-1230.0, 65.0, 810.0);
	glVertex3f(-1220.0, 65.0, 810.0);
	glVertex3f(-1220.0, 65.0, -1275.0);
	glEnd();
	
	//horizontal kiri bawah
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-1230.0, 0.0, -1275.0);
	glVertex3f(-1230.0, 50.0, -1275.0);
	glVertex3f(-1230.0, 50.0, 810.0);
	glVertex3f(-1230.0, 0.0, 810.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-1220.0, 50.0, -1275.0);
	glVertex3f(-1220.0, 0.0, -1275.0);
	glVertex3f(-1220.0, 0.0, 810.0);
	glVertex3f(-1220.0, 50.0, 810.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-1230.0, 50.0, -1275.0);
	glVertex3f(-1230.0, 50.0, 810.0);
	glVertex3f(-1220.0, 50.0, 810.0);
	glVertex3f(-1220.0, 50.0, -1275.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-1230.0, 0.0, -1275.0);
	glVertex3f(-1230.0, 0.0, 810.0);
	glVertex3f(-1220.0, 0.0, 810.0);
	glVertex3f(-1220.0, 0.0, -1275.0);
	glEnd();
	
	//horizontal kanan atas
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(1230.0, 65.0, -1275.0);
	glVertex3f(1230.0, 70.0, -1275.0);
	glVertex3f(1230.0, 70.0, 810.0);
	glVertex3f(1230.0, 65.0, 810.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(1220.0, 70.0, -1275.0);
	glVertex3f(1220.0, 65.0, -1275.0);
	glVertex3f(1220.0, 65.0, 810.0);
	glVertex3f(1220.0, 70.0, 810.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(1230.0, 70.0, -1275.0);
	glVertex3f(1230.0, 70.0, 810.0);
	glVertex3f(1220.0, 70.0, 810.0);
	glVertex3f(1220.0, 70.0, -1275.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(1230.0, 65.0, -1275.0);
	glVertex3f(1230.0, 65.0, 810.0);
	glVertex3f(1220.0, 65.0, 810.0);
	glVertex3f(1220.0, 65.0, -1275.0);
	glEnd();
	
	//horizontal kanan bawah
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(1230.0, 0.0, -1275.0);
	glVertex3f(1230.0, 50.0, -1275.0);
	glVertex3f(1230.0, 50.0, 810.0);
	glVertex3f(1230.0, 0.0, 810.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(1220.0, 50.0, -1275.0);
	glVertex3f(1220.0, 0.0, -1275.0);
	glVertex3f(1220.0, 0.0, 810.0);
	glVertex3f(1220.0, 50.0, 810.0);
	glEnd();	
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(1230.0, 50.0, -1275.0);
	glVertex3f(1230.0, 50.0, 810.0);
	glVertex3f(1220.0, 50.0, 810.0);
	glVertex3f(1220.0, 50.0, -1275.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(1230.0, 0.0, -1275.0);
	glVertex3f(1230.0, 0.0, 810.0);
	glVertex3f(1220.0, 0.0, 810.0);
	glVertex3f(1220.0, 0.0, -1275.0);
	glEnd();
	
}


void draw() {
    // Mulai tuliskan isi pikiranmu disini
    glPushMatrix();
    glTranslatef(0.0, 2000.0, 0.0);
    matahari();
    glPopMatrix();
    
    lantai();
    karpet();
	ruang1();
	atap_lantai1();
	//hiasan
	cagak_ruang1();
	hias_blkg(-234.0,105.0,-660.0, -234.0,400.0,-660.0, -214.0,400.0,-660.0, -214.0,105.0,-660.0);
	hias_blkg(-234.0,105.0,-660.0, -234.0,400.0,-660.0, -234.0,400.0,-650.0, -234.0,105.0,-650.0);
	hias_blkg(-214.0,105.0,-660.0, -214.0,400.0,-660.0, -214.0,400.0,-650.0, -214.0,105.0,-650.0);
	hias_samping(-360.0, 105.0, -260.0, -360.0, 400.0, -260.0, -360.0, 400.0, -240.0, -360.0, 105.0, -240.0);
	hias_samping(-350.0, 105.0, -240.0, -350.0, 400.0, -240.0, -360.0, 400.0, -240.0, -360.0, 105.0, -240.0);
	hias_samping(-350.0, 105.0, -260.0, -350.0, 400.0, -260.0, -360.0, 400.0, -260.0, -360.0, 105.0, -260.0);
	hias_samping(360.0, 105.0, -260.0, 360.0, 400.0, -260.0, 360.0, 400.0, -240.0, 360.0, 105.0, -240.0);
	hias_samping(350.0, 105.0, -240.0, 350.0, 400.0, -240.0, 360.0, 400.0, -240.0, 360.0, 105.0, -240.0);
	hias_samping(350.0, 105.0, -260.0, 350.0, 400.0, -260.0, 360.0, 400.0, -260.0, 360.0, 105.0, -260.0);
	
	tiang(350.0, 105.0, -140.0, 350.0, 400.0, -140.0, 330.0, 400.0, -140.0, 330.0, 105.0, -140.0);
	tiang(350.0, 105.0, -140.0, 350.0, 400.0, -140.0, 350.0, 400.0, -150.0, 350.0, 105.0, -150.0);
	tiang(330.0, 105.0, -140.0, 330.0, 400.0, -140.0, 330.0, 400.0, -150.0, 330.0, 105.0, -150.0);

	tiang(350.0, 105.0, -660.0, 350.0, 400.0, -660.0, 330.0, 400.0, -660.0, 330.0, 105.0, -660.0);
	tiang(350.0, 105.0, -660.0, 350.0, 400.0, -660.0, 350.0, 400.0, -650.0, 350.0, 105.0, -650.0);
	tiang(330.0, 105.0, -660.0, 330.0, 400.0, -660.0, 330.0, 400.0, -650.0, 330.0, 105.0, -650.0);

	tiang(350.0, 105.0, -140.0, 350.0, 400.0, -140.0, 360.0, 400.0, -140.0, 360.0, 105.0, -140.0);	
	tiang(360.0, 105.0, -140.0, 360.0, 400.0, -140.0, 360.0, 400.0, -170.0, 360.0, 105.0, -170.0);
	tiang(350.0, 105.0, -170.0, 350.0, 400.0, -170.0, 360.0, 400.0, -170.0, 360.0, 105.0, -170.0);

	tiang(350.0, 105.0, -660.0, 350.0, 400.0, -660.0, 360.0, 400.0, -660.0, 360.0, 105.0, -660.0);
	tiang(360.0, 105.0, -660.0, 360.0, 400.0, -660.0, 360.0, 400.0, -630.0, 360.0, 105.0, -630.0);
	tiang(350.0, 105.0, -630.0, 350.0, 400.0, -630.0, 360.0, 400.0, -630.0, 360.0, 105.0, -630.0);
	
	lantai2();
	karpet2();
	ruang2();
	bawah_atap2();
	atap2();
	//hiasan
	cagak_ruang2();
	hias_horizontal(-220.0, 615.0, -190.0, -220.0, 605.0, -190.0, 220.0, 605.0, -190.0, 220.0, 615.0, -190.0);
	hias_horizontal(-220.0, 615.0, -190.0, -220.0, 615.0, -200.0, 220.0, 615.0, -200.0, 220.0, 615.0, -190.0);
	hias_horizontal(-220.0, 605.0, -190.0, -220.0, 605.0, -200.0, 220.0, 605.0, -200.0, 220.0, 605.0, -190.0);
	hias_horizontal(-220.0, 615.0, -610.0, -220.0, 605.0, -610.0, 220.0, 605.0, -610.0, 220.0, 615.0, -610.0);
	hias_horizontal(-220.0, 615.0, -610.0, -220.0, 615.0, -600.0, 220.0, 615.0, -600.0, 220.0, 615.0, -610.0);
	hias_horizontal(-220.0, 605.0, -610.0, -220.0, 605.0, -600.0, 220.0, 605.0, -600.0, 220.0, 605.0, -610.0);
	
	hias_horizontal(-220.0, 605.0, -610.0, -220.0, 615.0, -610.0, -220.0, 615.0, -190.0, -220.0, 605.0, -190.0);
	hias_horizontal(-210.0, 605.0, -610.0, -210.0, 605.0, -190.0, -220.0, 605.0, -190.0, -220.0, 605.0, -610.0);	
	hias_horizontal(-210.0, 615.0, -610.0, -210.0, 615.0, -190.0, -220.0, 615.0, -190.0, -220.0, 615.0, -610.0);
	hias_horizontal(220.0, 605.0, -610.0, 220.0, 615.0, -610.0, 220.0, 615.0, -190.0, 220.0, 605.0, -190.0);
	hias_horizontal(210.0, 605.0, -610.0, 210.0, 605.0, -190.0, 220.0, 605.0, -190.0, 220.0, 605.0, -610.0);	
	hias_horizontal(210.0, 615.0, -610.0, 210.0, 615.0, -190.0, 220.0, 615.0, -190.0, 220.0, 615.0, -610.0);
	
	tiang(200.0, 480.0, -190.0, 200.0, 615.0, -190.0, 195.0, 615.0, -190.0, 195.0, 480.0, -190.0);
	tiang(200.0, 480.0, -190.0, 200.0, 615.0, -190.0, 200.0, 615.0, -200.0, 200.0, 480.0, -200.0);
	tiang(195.0, 480.0, -190.0, 195.0, 615.0, -190.0, 195.0, 615.0, -200.0, 195.0, 480.0, -200.0);

	tiang(200.0, 480.0, -610.0, 200.0, 615.0, -610.0, 195.0, 615.0, -610.0, 195.0, 480.0, -610.0);
	tiang(200.0, 480.0, -610.0, 200.0, 615.0, -610.0, 200.0, 615.0, -600.0, 200.0, 480.0, -600.0);
	tiang(195.0, 480.0, -610.0, 195.0, 615.0, -610.0, 195.0, 615.0, -600.0, 195.0, 480.0, -600.0);

	tiang(200.0, 480.0, -190.0, 200.0, 615.0, -190.0, 220.0, 615.0, -190.0, 220.0, 480.0, -190.0);
	tiang(220.0, 480.0, -190.0, 220.0, 615.0, -190.0, 220.0, 615.0, -210.0, 220.0, 480.0, -210.0);
	tiang(200.0, 480.0, -210.0, 200.0, 615.0, -210.0, 220.0, 615.0, -210.0, 220.0, 480.0, -210.0);

	tiang(200.0, 480.0, -610.0, 200.0, 615.0, -610.0, 220.0, 615.0, -610.0, 220.0, 480.0, -610.0);
	tiang(220.0, 480.0, -610.0, 220.0, 615.0, -610.0, 220.0, 615.0, -590.0, 220.0, 480.0, -590.0);
	tiang(200.0, 480.0, -590.0, 200.0, 615.0, -590.0, 220.0, 615.0, -590.0, 220.0, 480.0, -590.0);

	//PAGAR
	pagarluar();
	pagar1();
	pagar2();
	pagar3();
	pagar4();
	
	atap_lantai2();
	lantai3();
	karpet3();
	ruang3();
	bawah_atap3();
	atap3();
	//hiasan
	cagak_ruang3();
	hias_horizontal(-175.0, 955.0, -230.0, -175.0, 945.0, -230.0, 175.0, 945.0, -230.0, 175.0, 955.0, -230.0);
	hias_horizontal(-175.0, 955.0, -230.0, -175.0, 955.0, -240.0, 175.0, 955.0, -240.0, 175.0, 955.0, -230.0);
	hias_horizontal(-175.0, 945.0, -230.0, -175.0, 945.0, -240.0, 175.0, 945.0, -240.0, 175.0, 945.0, -230.0);
	hias_horizontal(-175.0, 955.0, -570.0, -175.0, 945.0, -570.0, 175.0, 945.0, -570.0, 175.0, 955.0, -570.0);
	hias_horizontal(-175.0, 955.0, -570.0, -175.0, 955.0, -560.0, 175.0, 955.0, -560.0, 175.0, 955.0, -570.0);
	hias_horizontal(-175.0, 945.0, -570.0, -175.0, 945.0, -560.0, 175.0, 945.0, -560.0, 175.0, 945.0, -570.0);
	
	hias_horizontal(-175.0, 945.0, -570.0, -175.0, 955.0, -570.0, -175.0, 955.0, -230.0, -175.0, 945.0, -230.0);
	hias_horizontal(-170.0, 945.0, -570.0, -170.0, 945.0, -230.0, -175.0, 945.0, -230.0, -175.0, 945.0, -570.0);	
	hias_horizontal(-170.0, 955.0, -570.0, -170.0, 955.0, -230.0, -175.0, 955.0, -230.0, -175.0, 955.0, -570.0);
	hias_horizontal(175.0, 945.0, -570.0, 175.0, 955.0, -570.0, 175.0, 955.0, -230.0, 175.0, 945.0, -230.0);
	hias_horizontal(170.0, 945.0, -570.0, 170.0, 945.0, -230.0, 175.0, 945.0, -230.0, 175.0, 945.0, -570.0);	
	hias_horizontal(170.0, 955.0, -570.0, 170.0, 955.0, -230.0, 175.0, 955.0, -230.0, 175.0, 955.0, -570.0);
	
	atap_lantai3();
	lantai4();
	karpet4();
	ruang4();
	atap4();
	
	//hiasan
	cagak_ruang4();
	hias_hrzntl(-125.0, 1235.0, -280.0, -125.0, 1230.0, -280.0, 125.0, 1230.0, -280.0, 125.0, 1235.0, -280.0);
	hias_hrzntl(-125.0, 1235.0, -280.0, -125.0, 1235.0, -290.0, 125.0, 1235.0, -290.0, 125.0, 1235.0, -280.0);
	hias_hrzntl(-125.0, 1230.0, -280.0, -125.0, 1230.0, -290.0, 125.0, 1230.0, -290.0, 125.0, 1230.0, -280.0);
	hias_hrzntl(-125.0, 1235.0, -510.0, -125.0, 1230.0, -510.0, 125.0, 1230.0, -510.0, 125.0, 1235.0, -510.0);
	hias_hrzntl(-125.0, 1235.0, -510.0, -125.0, 1235.0, -520.0, 125.0, 1235.0, -520.0, 125.0, 1235.0, -510.0);
	hias_hrzntl(-125.0, 1230.0, -510.0, -125.0, 1230.0, -520.0, 125.0, 1230.0, -520.0, 125.0, 1230.0, -510.0);
	
	hias_hrzntl(-125.0, 1230.0, -520.0, -125.0, 1235.0, -520.0, -125.0, 1235.0, -280.0, -125.0, 1230.0, -280.0);
	hias_hrzntl(-120.0, 1230.0, -520.0, -120.0, 1230.0, -280.0, -125.0, 1230.0, -280.0, -125.0, 1230.0, -520.0);	
	hias_hrzntl(-120.0, 1235.0, -520.0, -120.0, 1235.0, -280.0, -125.0, 1235.0, -280.0, -125.0, 1235.0, -520.0);
	hias_hrzntl(125.0, 1230.0, -520.0, 125.0, 1235.0, -520.0, 125.0, 1235.0, -280.0, 125.0, 1230.0, -280.0);
	hias_hrzntl(120.0, 1230.0, -520.0, 120.0, 1230.0, -280.0, 125.0, 1230.0, -280.0, 125.0, 1230.0, -520.0);	
	hias_hrzntl(120.0, 1235.0, -520.0, 120.0, 1235.0, -280.0, 125.0, 1235.0, -280.0, 125.0, 1235.0, -520.0);
	
	//SELAIN KUIL
	for (int a = 0; a < 5; a++) {
		glPushMatrix();
			glScalef(5.0, 5.0, 5.0);
			glTranslatef(-395.0+ a*200, 800.0, -2325.0+ a*470);
			awan();
		glPopMatrix();
	};
	for (int a = 0; a < 5; a++) {
		glPushMatrix();
			glScalef(5.0, 5.0, 5.0);
			glTranslatef(394.0+ a*-200, 800.0, -2325.0+ a*470);
			awan();
		glPopMatrix();
	};
	for (int a = 0; a < 5; a++) {
		glPushMatrix();
			glScalef(5.0, 5.0, 5.0);
			glTranslatef(-385.0+ a*800, 800.0, 0.0);
			awan();
		glPopMatrix();
	};
	for (int a = 0; a < 5; a++) {
		glPushMatrix();
			glScalef(5.0, 5.0, 5.0);
			glTranslatef(-385.0+ a*800, 800.0, -2000.0);
			awan();
		glPopMatrix();
	};
	
	
	tangga();
	jalan();
	jalan2();
	gapura();
	gapura1();
	atasgpr();
	atasgpr1();
	atasgpr2();
	pucukgpr();
	atap_gpr();
	kendi();
	glPushMatrix();
		glTranslatef(-700.0, 0.0, 0.0);
		kendi();
	glPopMatrix();
	//lampion lantai satu 
	lamp();
	glPushMatrix();
		glTranslatef(0.0, 0.0, -599.0);
		lampion();
	glPopMatrix();
	glPushMatrix();
		lampion();
		glTranslatef(-898.0, 0.0, 0.0);
		lampion();
		glTranslatef(0.0, 0.0, -599.0);
		lampion();
	glPopMatrix();
	//lampion lantai dua
	glPushMatrix();
		glTranslatef(-120.0, 290.0, -10.0);
		lampion();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-780.0, 290.0, -10.0);
		lampion();
	glPopMatrix();
	//lampion lantai 3
	glPushMatrix();
		glTranslatef(-730.0, 620.0, -70.0);
		lampion();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-170.0, 620.0, -70.0);
		lampion();
	glPopMatrix();
	
	//pohon luar pagar
	for (int a = 0; a < 5; a++) {
		glPushMatrix();
			glScalef(3.0, 3.0, 3.0);
			glTranslatef(-395.0+ a*200, 0.0, -1000.0);
			pohon();
		glPopMatrix();
	};
	
	glPushMatrix();
		glTranslatef(0.0, 105.0, -400.0);
		meja();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0, 142.0, -380.0);
		teko();
	glPopMatrix();
	
	antena();
	lampion();
    ground();
    glFlush();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    camera();
    draw();

    glutSwapBuffers();
}

void reshape(int w, int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50, 16.0 / 9.0, 2, 10000);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int){
    glutPostRedisplay();
    glutWarpPointer(width / 2, height / 2);
    glutTimerFunc(1000 / FPS, timer, 0);
}

void passive_motion(int x, int y){
    int dev_x, dev_y;
    dev_x = (width / 2) - x;
    dev_y = (height / 2) - y;
    yaw += (float)dev_x / 20.0;
    pitch += (float)dev_y / 20.0;
}

void camera(){
    if (motion.Forward){
        camX += cos((yaw + 90) * TO_RADIANS) * 2;
        camZ -= sin((yaw + 90) * TO_RADIANS) * 2;
    }
    if (motion.Backward){
        camX += cos((yaw + 90 + 180) * TO_RADIANS) * 2;
        camZ -= sin((yaw + 90 + 180) * TO_RADIANS) * 2;
    }
    if (motion.Left){
        camX += cos((yaw + 90 + 90) * TO_RADIANS) * 2;
        camZ -= sin((yaw + 90 + 90) * TO_RADIANS) * 2;
    }
    if (motion.Right){
        camX += cos((yaw + 90 - 90) * TO_RADIANS) * 2;
        camZ -= sin((yaw + 90 - 90) * TO_RADIANS) * 2;
    }
    if (motion.Naik){
        terbang -= 2.0;
    }
    if (motion.Turun){
        terbang += 2.0;
    }

    if (pitch >= 70)
        pitch = 70;
    if (pitch <= -90)
        pitch = -90;


    glRotatef(-pitch, 1.0, 0.0, 0.0);
    glRotatef(-yaw, 0.0, 1.0, 0.0);

    glTranslatef(-camX, -terbang, -350 - camZ);
    if (terbang < 25)
        terbang = 24;
}

void keyboard(unsigned char key, int x, int y){
    switch (key){
    case 'W':
    case 'w':
        motion.Forward = true;
        break;
    case 'A':
    case 'a':
        motion.Left = true;
        break;
    case 'S':
    case 's':
        motion.Backward = true;
        break;
    case 'D':
    case 'd':
        motion.Right = true;
        break;
    case 'E':
    case 'e':
        motion.Naik = true;
        break;
    case 'Q':
    case 'q':
        motion.Turun = true;
        break;
    case '6':
        x_geser += 0.5;
        break;
    case '4':
        x_geser -= 0.5;
        break;
    case '8':
        y_geser += 0.5;
        break;
    case '2':
        y_geser -= 0.5;
        break;
    case '9':
        z_geser -= 0.5;
        break;
    case '1':
        z_geser += 0.5;
        break;
    case '`': // KELUAR DARI PROGRAM
        exit(1);
    }
}

void keyboard_up(unsigned char key, int x, int y){
    switch (key){
    case 'W':
    case 'w':
        motion.Forward = false;
        break;
    case 'A':
    case 'a':
        motion.Left = false;
        break;
    case 'S':
    case 's':
        motion.Backward = false;
        break;
    case 'D':
    case 'd':
        motion.Right = false;
        break;
    case 'E':
    case 'e':
        motion.Naik = false;
        break;
    case 'Q':
    case 'q':
        motion.Turun = false;
        break;
    }
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow("TR GRAFKOM KELOMPOK 5");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutPassiveMotionFunc(passive_motion);
    glutTimerFunc(0, timer, 0);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard_up);

    glutMainLoop();
    return 0;
}
