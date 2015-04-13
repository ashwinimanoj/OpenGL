#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include <time.h>
void myinit();
void person();
void harry();
void door();
int i,j;
float x1=0,x2=0;

void door()
{
//Main Door
glColor3d(0.6,0.3,0);
glBegin(GL_POLYGON);
glVertex2d(200.0,100.0);
glVertex2d(300.0,100.0);
glVertex2d(300.0,300.0);
glVertex2d(250.0,400.0);
glVertex2d(200.0,300.0);
glEnd();
}

void letter()
{
float theta,x,y,r;
r=30;
char c[]="H";
myinit();
glColor3d(1,1,1);
//Rectangle part of letter
glBegin(GL_POLYGON);
glVertex2d(0.0,100.0);
glVertex2d(500.0,100.0);
glVertex2d(500.0,300.0);
glVertex2d(0.0,300.0);
glEnd();

glColor3d(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2d(1.0,100.0);
glVertex2d(500.0-1,100.0);
glVertex2d(500.0-1,300.0);
glVertex2d(1.0,300.0);
glEnd();
//Triangle part of letter
glColor3d(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2d(0.0,300.0);
glVertex2d(250.0,200.0);
glVertex2d(500.0,300.0);
glEnd();
//For Circle part of Logo
glColor3f(0.8,0.0,0.0);
glBegin(GL_POLYGON);
for(i = 0; i <= 360; i++)
{
        theta = (3.1415926f/180) * i ;//get the current angle

        x = r * cos(theta);//calculate the x component
        y = r * sinf(theta);//calculate the y component

        glVertex2f(x + 250, y + 200);//output vertex

}
glEnd();
//For H of logo
glColor3d(1,1,1);
glRasterPos2d(240,200);
for(i=0;i<sizeof(c);i++)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c[i]);

glutSwapBuffers();
glutPostRedisplay();

}


void castle()
{
int k;
//Sky  
glColor3d(0.2,0.2,1);
glBegin(GL_POLYGON);
glVertex2d(0.0,300.0);
glVertex2d(500.0,30.0);
glVertex2d(500.0,500.0);
glVertex2d(0.0,500.0);
glEnd();

//Castle ground
glColor3d(0.0,0.8,0);
glBegin(GL_POLYGON);
glVertex2d(0.0,0.0);
glVertex2d(500.0,0.0);
glVertex2d(500.0,100.0);
glVertex2d(0.0,100.0);
glEnd();

//Main castle wall
glColor3d(0.7,0.7,0.7);
glBegin(GL_POLYGON);
glVertex2d(0.0,100.0);
glVertex2d(500.0,100.0);
glVertex2d(500.0,300.0);
glVertex2d(0.0,300.0);
glEnd();

//Tomb structure(left)
glColor3d(0.8,0.8,0.8);
glBegin(GL_POLYGON);
glVertex2d(50,100.0);
glVertex2d(50.0,320.0);
glVertex2d(0.0,320.0);
glVertex2d(0.0,100.0);
glEnd(); 

glBegin(GL_POLYGON);
glVertex2d(50.0,320.0);
glVertex2d(60.0,320.0);
glVertex2d(60.0,380.0);
glVertex2d(50.0,380.0);
glEnd();

glBegin(GL_POLYGON);
glVertex2d(50.0,320.0);
glVertex2d(50.0,350.0);
glVertex2d(40.0,350.0);
glVertex2d(40.0,320.0);
glEnd();

glBegin(GL_POLYGON);
glVertex2d(40.0,320.0);
glVertex2d(40.0,380.0);
glVertex2d(25.0,380.0);
glVertex2d(25.0,320.0);
glEnd();


glBegin(GL_POLYGON);
glVertex2d(25.0,320.0);
glVertex2d(25.0,350.0);
glVertex2d(15.0,350.0);
glVertex2d(15.0,320.0);
glEnd();

glBegin(GL_POLYGON);
glVertex2d(15.0,320.0);
glVertex2d(15.0,380.0);
glVertex2d(0.0,380.0);
glVertex2d(0.0,320.0);
glEnd();


//Tomb structure(right)
glColor3d(0.8,0.8,0.8);
glBegin(GL_POLYGON);
glVertex2d(500-50,100.0);
glVertex2d(500-50.0,320.0);
glVertex2d(500.0,320.0);
glVertex2d(500.0,100.0);
glEnd(); 

glBegin(GL_POLYGON);
glVertex2d(500-50.0,320.0);
glVertex2d(500-60.0,320.0);
glVertex2d(500-60.0,380.0);
glVertex2d(500-50.0,380.0);
glEnd();

glBegin(GL_POLYGON);
glVertex2d(500-50.0,320.0);
glVertex2d(500-50.0,350.0);
glVertex2d(500-40.0,350.0);
glVertex2d(500-40.0,320.0);
glEnd();

glBegin(GL_POLYGON);
glVertex2d(500-40.0,320.0);
glVertex2d(500-40.0,380.0);
glVertex2d(500-25.0,380.0);
glVertex2d(500-25.0,320.0);
glEnd();


glBegin(GL_POLYGON);
glVertex2d(500-25.0,320.0);
glVertex2d(500-25.0,350.0);
glVertex2d(500-15.0,350.0);
glVertex2d(500-15.0,320.0);
glEnd();

glBegin(GL_POLYGON);
glVertex2d(500-15.0,320.0);
glVertex2d(500-15.0,380.0);
glVertex2d(500.0,380.0);
glVertex2d(500.0,320.0);
glEnd();


//Tomb(big) structure(left)
glColor3d(0.8,0.8,0.8);
glBegin(GL_POLYGON);
glVertex2d(100,300.0);
glVertex2d(100.0,400.0);
glVertex2d(100.0+50,400.0);
glVertex2d(100.0+50,300.0);
glEnd();
glBegin(GL_TRIANGLES);
glVertex2d(100.0,400.0);
glVertex2d(100+25.0,500.0);
glVertex2d(100+50.0,400.0);
glEnd();

//Tomb(big) structure(left)
glColor3d(0.8,0.8,0.8);
glBegin(GL_POLYGON);
glVertex2d(450-100,300.0);
glVertex2d(450-100.0,400.0);
glVertex2d(450-100.0+50,400.0);
glVertex2d(450-100.0+50,300.0);
glEnd();
glBegin(GL_TRIANGLES);
glVertex2d(450-100.0,400.0);
glVertex2d(450-100+25.0,500.0);
glVertex2d(450-100+50.0,400.0);
glEnd();

door();
//windows
glColor3d(0.2,0.2,0.2);
glPointSize(15);
glBegin(GL_POINTS);
glVertex2d(25,200);
glVertex2d(25,250);
glVertex2d(475,200);
glVertex2d(475,250);
glEnd();
  
}

void myinit()
{
glClearColor(0,0,0,1);
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
gluOrtho2D(0.0,500.0,0.0,500.0); 
}

void harry()
{
//Leg
glColor3f(0,0,0);
glBegin(GL_POLYGON);
glVertex2d(0,10);
glVertex2d(10,10);
glVertex2d(10,20);
glVertex2d(0,20);
glEnd();
glColor3f(0,0,0);
glBegin(GL_POLYGON);
glVertex2d(0,10);
glVertex2d(25,10);
glVertex2d(20,20);
glVertex2d(0,20);
glEnd();
//Socks 
glColor3d(0.9,0.8,0.8);
glBegin(GL_POLYGON);
glVertex2d(0.0,20.0);
glVertex2d(10.0,20.0);
glVertex2d(10.0,40.0);
glVertex2d(0.0,40.0);
glEnd();
glColor3d(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2d(0.0,20.0);
glVertex2d(10.0,20.0);
glVertex2d(10.0,40.0);
glVertex2d(0.0,40.0);
glEnd();

glColor3d(0.9,0.8,0.8);
glBegin(GL_POLYGON);
glVertex2d(10.0,20.0);
glVertex2d(20.0,20.0);
glVertex2d(20.0,40.0);
glVertex2d(10.0,40.0);
glEnd();
glColor3d(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2d(10.0,20.0);
glVertex2d(20.0,20.0);
glVertex2d(20.0,40.0);
glVertex2d(10.0,40.0);
glEnd();

//Trousers
glColor3f(0.1,0.2,0.3);
glBegin(GL_POLYGON);
glVertex2d(0,40);
glVertex2d(20,40);
glVertex2d(20,50);
glVertex2d(0,50);
glEnd();
//Shirt
glColor3f(1,0,0);
glBegin(GL_POLYGON);
glVertex2d(0,50);
glVertex2d(20,50);
glVertex2d(20,70);
glVertex2d(0,70);
glEnd();

//Head
glColor3f(0.9,0.6,0.6);
glBegin(GL_POLYGON);
glVertex2d(0,70);
glVertex2d(20,70);
glVertex2d(20,90);
glVertex2d(0,90);
glEnd();
//Hair
glColor3f(0,0,0);
glBegin(GL_POLYGON);
glVertex2d(0,70);
glVertex2d(5,70);
glVertex2d(5,90);
glVertex2d(0,90);
glEnd();

glColor3f(0,0,0);
glBegin(GL_POLYGON);
glVertex2d(0,90);
glVertex2d(20,90);
glVertex2d(20,100);
glVertex2d(0,100);
glEnd();
//Eye
glPointSize(5);
glBegin(GL_POINTS);
glVertex2d(15,85);
glEnd();


}

void person()
{
glPushMatrix();
glTranslatef(x1,0,0);
harry();
glFlush();
glPopMatrix();
if(x1<200)
	x1+=1;
glutSwapBuffers();
glutPostRedisplay();

}

void myKey(unsigned char key, int x,int y)
{
  if(key=='r');
  {
  harry();
  }
}

void display()
{
myinit();
//letter();
castle();
person();
glFlush();
}


int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitWindowSize(900,900);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
glutCreateWindow("My Game");
glutDisplayFunc(display);
glutKeyboardFunc(myKey);
glutIdleFunc(display);
glutMainLoop();
}
