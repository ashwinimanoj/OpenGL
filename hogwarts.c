#include<GLUT/glut.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

void letter();
void frontscreen();
void myinit();
void harry();
void door();
void castle();
void goInside();
void ground();
void sky();
void broomstick();
void snitch(int,int,int);
void score();

int i,j;
int clickCount=0;
int dispCastle=0,dispPerson=0,dispLetter=1,dispFrontScreen=0,goIn=0,gameWon=0,gameLost=0,gameInst=0,moveS=1;
int dispGame=0;
int x1=0,x2=0,y2=0;
float x3=500.0;
int WIDTH = 900;
int HEIGHT = 900;
int snitchCount=7;
int showSnitch[7]={0};
int points=0,pointCount[7]={0};
float randval;
int tries=0;
int set=0;
int snitchCoord[7] = {230,270,350,420,190,250,290};	
int sY=0;

void frontscreen()
{
char collegeName[]="Gopalan College of Engineering and Management";
char dept[]="Department of";
char deptName[]="Computer Science and Engineering";
char miniProj[]="A mini project on";
char projTitle[]="A Day with Harry Potter ";
char by[]="By";
char name[]="Name: ";
char authName[]="Ashwini Manoj";
char usn[]="USN: ";
char USN[]="1GD12CS004";
char guided[]="Guided by";
char guideName[]="Manju V";
char start[]="Press Enter to start!";

glColor3d(1,1,1);
//Letter triangle
glBegin(GL_POLYGON);
glVertex2d(50,360);
glVertex2d((450+50)/2,500);
glVertex2d(450,360);
glEnd();
glColor3d(1,1,1);
//Letter body
glBegin(GL_POLYGON);
glVertex2d(50,0);
glVertex2d(450,0);
glVertex2d(450,360);
glVertex2d(50,360);
glEnd();

glColor3d(0,0,0);
glRasterPos2d(130,320+20);
for(i=0;i<sizeof(collegeName);i++)
{
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,collegeName[i]);
}
glColor3d(0.4,0.3,0.6);
glRasterPos2d(130+80,320-10);
for(i=0;i<sizeof(dept);i++)
{
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,dept[i]);
}
glRasterPos2d(130+35,320-28);
for(i=0;i<sizeof(deptName);i++)
{
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,deptName[i]);
}
glColor3d(0.9,0.1,0.5);
glRasterPos2d(130+75,320-88);
for(i=0;i<sizeof(miniProj);i++)
{
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,miniProj[i]);
}
glColor3d(1,0.0,0.1);
glRasterPos2d(130+60,320-108);
for(i=0;i<sizeof(projTitle);i++)
{
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,projTitle[i]);
}
glColor3d(0.5,0.1,5);
glRasterPos2d(130+105,320-170);
for(i=0;i<sizeof(by);i++)
{
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,by[i]);
}
glColor3d(0.2,0.3,1);
glRasterPos2d(130+65,320-188);
for(i=0;i<sizeof(name);i++)
{
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,name[i]);
}
glRasterPos2d(130+100,320-188);
for(i=0;i<sizeof(authName);i++)
{
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,authName[i]);
}
glRasterPos2d(130+70,320-208);
for(i=0;i<sizeof(usn);i++)
{
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,usn[i]);
}
glRasterPos2d(130+100,320-208);
for(i=0;i<sizeof(USN);i++)
{
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,USN[i]);
}
glColor3d(0.9,0.5,0.1);
glRasterPos2d(130+89,320-245);
for(i=0;i<sizeof(guided);i++)
{
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,guided[i]);
}
glRasterPos2d(130+92,320-263);
for(i=0;i<sizeof(guideName);i++)
{
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,guideName[i]);
}

glColor3d(1,0.2,0.2);
glRasterPos2d(130+65,320-290);
for(i=0;i<sizeof(start);i++)
{
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,start[i]);
}

}

void rectmesh(int m,int n)
{
glPushMatrix();
glTranslatef(0,100,0);
  int i,j;
  for(i=0;i<m;i+=30)
    for(j=0;j<n;j+=20)
    {
      glBegin(GL_POLYGON);
      glColor3d(0.8,0.8,0.8);
      glVertex2d(i,j);
      glColor3d(0.9,0.9,0.9);
      glVertex2d(i+30,j);
      glColor3d(0.9,0.9,0.9);
      glVertex2d(i+30,j+20);
    glColor3d(0.7,0.7,0.7);
      glVertex2d(i,j+20);
      glEnd();
    }
glPopMatrix();
}

void gameInstruction()
{
glColor3d(0,0,0);
glBegin(GL_POLYGON);
glVertex2d(100-2,200-2);
glVertex2d(100-2,400+2);
glVertex2d(400+2,400+2);
glVertex2d(400+2,200-2);
glEnd();
glColor3d(1,1,1);
glBegin(GL_POLYGON);
glVertex2d(100,200);
glVertex2d(100,400);
glVertex2d(400,400);
glVertex2d(400,200);
glEnd();
char str1[]="Move up or down and press C to capture ";
char str2[]="the snitch when you are in front of it ";
char str3[]="Remember, you have 10 tries to capture 7 snitches.";
char str4[]="Press Enter to start playing";
glColor3d(0,0,0);
glRasterPos2d(150,350);
for(i=0;i<sizeof(str1);i++)
	{
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str1[i]);
	}
glRasterPos2d(155,350-20);
for(i=0;i<sizeof(str2);i++)
	{
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str2[i]);
	}
glRasterPos2d(130,280);
for(i=0;i<sizeof(str3);i++)
	{
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str3[i]);
	}
glRasterPos2d(180,250);
for(i=0;i<sizeof(str4);i++)
	{
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str4[i]);
	}

}



void endGame(int val)
{
char lost[]="Sorry, you lost!";
char won[]="Yay! You Won!";
char game[]="GAME OVER";
glColor3d(1,1,1);

if(val)
{
 glRasterPos2d(205,210);
 for(i=0;i<sizeof(won);i++)
 {
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,won[i]);
 }
}
else
{
 glRasterPos2d(205,210);
 for(i=0;i<sizeof(lost);i++)
  {
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,lost[i]);
  }
}
glRasterPos2d(210,250);
for(i=0;i<sizeof(game);i++)
{
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,game[i]);
}

}

void snitchMove()
{
  glColor3f(0.9,0.9,0);
  glTranslatef(x3,0,0);
  if(x3>=-300)	
  {
       x3=x3-0.9+randval;
   if(snitchCount<=3)
      x3=x3+randval-0.9;
   if(snitchCount==1)
      x3=x3-2.6;
  }
else
 {
 x3=500;
 }
}

void snitch(int i,int PosX,int PosY)
{

glPushMatrix();
if(moveS)
  snitchMove();
int r=8;
float x,y,theta;
glPushMatrix();
glColor3d(1,1,1);
glBegin(GL_TRIANGLES);
glVertex2d(PosX,PosY);
glVertex2d(PosX-20,PosY);
glVertex2d(PosX-10,PosY+10);
glEnd();
glBegin(GL_TRIANGLES);
glVertex2d(PosX,PosY);
glVertex2d(PosX+20,PosY);
glVertex2d(PosX+10,PosY+10);
glPopMatrix();
glEnd();
        glColor3d(1,1,0);
	glBegin(GL_POLYGON);
	for(i = 0; i <= 360; i++)
	{
	        theta = (3.1415926f/180) * i ;//get the current angle
	
	        x = r * cos(theta);//calculate the x component
	        y = r * sinf(theta);//calculate the y component
	
	        glVertex2f(x+PosX, y+PosY);//output vertex
	
	}
	glEnd();
glPopMatrix();

}

void score()
{
 
if(y2>=snitchCoord[0]-90-30 && y2<=snitchCoord[0]-90+10)
	{
	showSnitch[0]=0;
	if(!pointCount[0])
		{points+=10;
		snitchCount--;}
	pointCount[0]=1;
	}
	     
if(y2>=snitchCoord[1]-90-30 && y2<=snitchCoord[1]-90+10)
	{
	showSnitch[1]=0;
	if(!pointCount[1])
		{points+=10;
		snitchCount--;}
	pointCount[1]=1;
	
	}
	     
if(y2>=snitchCoord[2]-90-30 && y2<=snitchCoord[2]-90+10)
	{
	showSnitch[2]=0;
	if(!pointCount[2])
		{points+=10;
		snitchCount--;}
	pointCount[2]=1;
	}
	     
if(y2>=snitchCoord[3]-90-30 && y2<=snitchCoord[3]-90+10)
	{
	showSnitch[3]=0;
	if(!pointCount[3])
		{points+=10;
		snitchCount--;}
	pointCount[3]=1;
	
	}

	     
if(y2>=snitchCoord[4]-90-30 && y2<=snitchCoord[4]-90+10)
	{
	showSnitch[4]=0;
	if(!pointCount[4])
		{points+=10;
		snitchCount--;}
	pointCount[4]=1;

	}
	     
if(y2>=snitchCoord[5]-90-30 && y2<=snitchCoord[5]-90+10)
	{
	showSnitch[5]=0;
	if(!pointCount[5])
		{points+=10;
		snitchCount--;}
	pointCount[5]=1;
	}
	
	     
if(y2>=snitchCoord[6]-90-30 && y2<=snitchCoord[6]-90+10)
	{
	showSnitch[6]=0;
	if(!pointCount[6])
		{points+=10;
		snitchCount--;}
	pointCount[6]=1;

	}

if(tries>=10)
   {
   gameLost=1;
   dispGame=0;
   }
if(points==70)
   {
   gameWon=1;
   dispGame=0;
   }
}

void broomstick()
{
if(x2>0&&x2<290&&!set)
	{
	x2=x2-2;
	if(x2==0)
	  set=1;
	}
glTranslatef(0,90,0);
glPushMatrix();
glTranslatef(50.0,0.0,0.0);
  harry();
glPopMatrix();
glColor3d(0.6,0.3,0);
glBegin(GL_POLYGON);
  glVertex2d(20,30);
  glVertex2d(100,30);
  glVertex2d(100,40);
  glVertex2d(20,40);
glEnd();
glColor3d(0,0,0);
glBegin(GL_LINE_LOOP);
  glVertex2d(20,30);
  glVertex2d(100,30);
  glVertex2d(100,40);
  glVertex2d(20,40);
glEnd();
glColor3d(1,1,0);
glBegin(GL_POLYGON);
  glVertex2d(20,40);
  glVertex2d(0,60);
  glVertex2d(0,20);
  glVertex2d(20,30);
glEnd();
glColor3d(0,0,0);
glBegin(GL_LINE_LOOP);
  glVertex2d(20,40);
  glVertex2d(0,60);
  glVertex2d(0,20);
  glVertex2d(20,30);
glEnd();
}

void HPgame()
{
char str1[10];
char str2[8];
char str3[8];
ground();
sky();
glPushMatrix();
glTranslatef(0,70,0);
glScalef(0.3,0.3,0);
castle();
glPopMatrix();
glPushMatrix();
glTranslatef(x2,y2,0);
broomstick();
glPopMatrix();
sprintf(str1,"Points: %d",points);
sprintf(str2,"Tries: %d",tries);
glColor3d(1,1,1);
glRasterPos2d(440,485);
for(i=0;i<sizeof(str1);i++)
 {
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str1[i]);
 }
glRasterPos2d(440,470);
for(i=0;i<sizeof(str2);i++)
 {
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str2[i]);
 }
glRasterPos2d(440,450);

}

void ground()
{
  glColor3d(0.0,0.8,0);
glBegin(GL_POLYGON);
glVertex2d(0.0,0.0);
glVertex2d(500.0,0.0);
glVertex2d(500.0,100.0);
glVertex2d(0.0,100.0);
glEnd();
}


/*void design()
{
glColor3d(0,0,0);
glPointSize(2);
glBegin(GL_POINTS);
for(j=300;j<400;j++)
 for(i=100;i<150;i+=5)
{
 glVertex2d(i,j); 
}

glEnd();
}
*/

void door()
{
//Main Door
/*
glVertex2d(200.0,100.0);
glVertex2d(300.0,100.0)
glVertex2d(300.0,300.0);
glVertex2d(250.0,400.0);
glVertex2d(200.0,300.0);
*/
glLineWidth(2);
glColor3d(0.6,0.3,0);
glBegin(GL_POLYGON);
glVertex2d(200,100);
glVertex2d(200,300);
glVertex2d(250,400);
glVertex2d(250,100);
glEnd();
glColor3d(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2d(200,100);
glVertex2d(200,300);
glVertex2d(250,400);
glVertex2d(250,100);
glEnd();
glColor3d(0.6,0.3,0);
glBegin(GL_POLYGON);
glVertex2d(300,100);
glVertex2d(300,300);
glVertex2d(250,400);
glVertex2d(250,100);
glEnd();
glColor3d(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2d(300,100);
glVertex2d(300,300);
glVertex2d(250,400);
glVertex2d(250,100);
glEnd();
glLineWidth(1);
//design();
}


void goInside()
{
char sen1[]="Click",sen2[]="to play!";
glColor3f(0.6,0.1,0.1);
glBegin(GL_POLYGON);
glVertex2d(310,200);
glVertex2d(310,210);
glVertex2d(390,210);
glVertex2d(390,200);
glEnd();
glColor3f(0.6,0.1,0.1);
glBegin(GL_POLYGON);
glVertex2d(310,130);
glVertex2d(310,120);
glVertex2d(390,120);
glVertex2d(390,130);
glEnd();
glColor3f(0.9,0.9,0.9);
glBegin(GL_POLYGON);
glVertex2d(320,130);
glVertex2d(320,200);
glVertex2d(380,200);
glVertex2d(380,130);
glEnd();
glColor3f(0,0,0.1);
glRasterPos2d(330,180);
for(i=0;i<sizeof(sen1);i++)
{
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,sen1[i]);
}
glRasterPos2d(330,160);
for(i=0;i<sizeof(sen2);i++)
{
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,sen2[i]);
}

}


void letter()
{
glTranslatef(0,30,0);
glPushMatrix();
float t1,t2;
float theta,x,y,r;
r=30;
char c[]="H";
char press[]="Press Enter to start";
glPushMatrix();
moveS=0;
glTranslatef(0,sY,0);
glColor3d(1,1,0.1);
snitch(1,450,300);
showSnitch[1]=1;

snitch(1,40,500);
showSnitch[1]=1;

snitch(1,70,700);
showSnitch[1]=1;

snitch(1,400,950);
showSnitch[1]=1;

snitch(1,150,1000);
showSnitch[1]=1;

snitch(1,190,650);
showSnitch[1]=1;

snitch(1,260,700);
showSnitch[1]=1;
if(sY<=-1000)
  sY=0;
sY-=3;	
glPopMatrix();

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
glRasterPos2d(245,200-5);
for(i=0;i<sizeof(c);i++)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c[i]);
glPopMatrix();

glColor3d(1,1,1);	
glRasterPos2d(210,80);
for(i=0;i<sizeof(press);i++)
{
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,press[i]);
}

}

void sky()
{
  glColor3d(0.2,0.2,1);
glBegin(GL_POLYGON);
glVertex2d(0.0,100.0);
glVertex2d(500.0,100.0);
glVertex2d(500.0,500.0);
glVertex2d(0.0,500.0);
glEnd();
}

void castle()
{

int k;
//Sky  
sky();

//Castle ground
ground();

//Main castle wall
glColor3d(0.7,0.7,0.7);
glBegin(GL_POLYGON);
glVertex2d(0.0,100.0);
glVertex2d(500.0,100.0);
glVertex2d(500.0,300.0);
glVertex2d(0.0,300.0);
glEnd();
rectmesh(480,200);

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
glVertex2d(100.0-10,400.0);
glVertex2d(100+25.0,500.0);
glVertex2d(100+50.0+10,400.0);
glEnd();
glColor3d(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2d(100.0-10,400.0);
glVertex2d(100+25.0,500.0);
glVertex2d(100+50.0+10,400.0);
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
glVertex2d(450-100.0-10,400.0);
glVertex2d(450-100+25.0,500.0);
glVertex2d(450-100+50.0+10,400.0);
glEnd();
glColor3d(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2d(450-100.0-10,400.0);
glVertex2d(450-100+25.0,500.0);
glVertex2d(450-100+50.0+10,400.0);
glEnd();



glPushMatrix();
door();
glPopMatrix();
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
//Hand()
glColor3f(0.9,0.6,0.6);
glBegin(GL_POLYGON);
glVertex2d(5,50);
glVertex2d(10,50);
glVertex2d(10,65);
glVertex2d(5,65);
glEnd();


//Head
glColor3f(0.9,0.6,0.6);
glBegin(GL_POLYGON);
glVertex2d(0,70);
glVertex2d(20,70);
glVertex2d(20,85);
glVertex2d(0,85);
glEnd();


//Hair
glColor3f(0,0,0);
glBegin(GL_POLYGON);
glVertex2d(0,70);
glVertex2d(5,70);
glVertex2d(5,85);
glVertex2d(0,85);
glEnd();


glColor3f(0,0,0);
glBegin(GL_POLYGON);
glVertex2d(0,85);
glVertex2d(20,85);
glVertex2d(20,92);
glVertex2d(0,92);
glEnd();

//Eye
glColor3d(0,0,0);
glPointSize(8);
glBegin(GL_POINTS);
glVertex2d(18,15+64);
glEnd();
glColor3d(0,0,0);
glBegin(GL_POLYGON);
glVertex2d(0,15+65);
glVertex2d(20,15+65);
glVertex2d(20,15+68);
glVertex2d(0,15+68);
glEnd();
glColor3d(1,1,1);
glPointSize(6);
glBegin(GL_POINTS);
glVertex2d(19,15+64);
glEnd();


}


void keyPressed(unsigned char key, int x,int y)
{
int i;
switch(key)
{
  case 'd':  
	if(x1<200)
	   {
	   x1+=3;
	   }
	if(x2<=500)
	   x2+=3;
	else
	   x2=0;
		break;
  case 'w' :
    y2+=3; 
    break;
  case 'a': if(x1>=0)
		x1-=3;
	  if(x2>=0)
	  	x2-=3;
	  break;
  case 's': if(y2>=0)
		y2-=3;
	break;
  case 13:
        if(clickCount<2)
             clickCount++;
	else if(clickCount==2)
	  { if(x1>=190)
	      clickCount++;
	   }
	else
	   clickCount++;
	if(clickCount==1)
	{
	dispLetter=0;
	dispFrontScreen=1;
	}
	if(clickCount==2)
	{
	dispFrontScreen=0;
	dispCastle=1;
	}  
	if(clickCount==3)
	{
	dispCastle=0;
	dispGame=1;
	gameInst=1;
	for(i=0;i<7;i++)
  		showSnitch[i]=1;
	}
	if(clickCount==4)
	{
	gameInst=0;
	}
     break;

  case 'c':
      tries++;
      score();
     break;
  case 'q':
   exit(0);
  }

}

void splKey(int key, int x,int y)
{
 
switch(key)
{

case GLUT_KEY_RIGHT:  
	if(x1<200)
	   {
	   x1+=3;
	   }
	if(x2<=500)
	   x2+=3;
	else
	   x2=0;
	   
		break;
case GLUT_KEY_UP :
    y2+=3; 
    break;

case GLUT_KEY_LEFT: if(x1>=0)
		x1-=3;
	  if(x2>=0)
	  	x2-=3;
	  break;

case GLUT_KEY_DOWN: if(y2>=0)
		y2-=3;
	break;
}
}


void keyClicked(int button,int state,int x,int y)
{
  
  if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
	
	}
}


void display()
{
  myinit();
  if(dispLetter)
        {
	  letter();
	  moveS=1;
	}
  if(dispFrontScreen)
	frontscreen();
  if(dispCastle)
   {
	castle();
	
	glTranslatef(10.0,90.0,0.0);
	glPushMatrix();
	glTranslatef(x1,0,0);
	harry();
	glPopMatrix();
	if(x1>=190)
	     goIn=1;
	if(goIn)
    	goInside();
   } 

  if(dispGame)
        {
	   HPgame();
	 glPushMatrix();
	  if(showSnitch[0])
	     snitch(0,150,snitchCoord[0]);
	  if(showSnitch[1])
	     snitch(1,230,snitchCoord[1]);
	  if(showSnitch[2])
	     snitch(2,270,snitchCoord[2]);
	  if(showSnitch[3])
	     snitch(3,320,snitchCoord[3]);
	  if(showSnitch[4]&&!showSnitch[0])
	     snitch(4,120,snitchCoord[4]);
	  if(showSnitch[5]&&!showSnitch[1])
	     snitch(5,240,snitchCoord[5]);
	  if(showSnitch[6]&&!showSnitch[2])
	     snitch(6,330,snitchCoord[6]);
	 glPopMatrix();

	}

  if(gameInst)
    gameInstruction();
  if(gameLost)
    endGame(0);
  if(gameWon)
    endGame(1);
   
  glutSwapBuffers();
  glutPostRedisplay();
  glFlush();
}

void mainmenu(int val)
{
switch(val)
 {
 case 1:
 case 2:
 case 3:
 break;
 }
}

void menu()
{
glutCreateMenu(mainmenu);
glutAddMenuEntry("Key Instructions",1);
glutAddMenuEntry("Use the arrow keys to move left, right, up or down appropriately.",2);
glutAddMenuEntry("Press enter to move to next screen",3);
glutAddMenuEntry(" ",4);
glutAddMenuEntry("Game Instructions",5);
glutAddMenuEntry("Move up or down and press C to capture the snitch when you are in front of it",6);
glutAddMenuEntry("Remember, you have 10 tried to capture 7 snitches. Good luck!",7);
glutAttachMenu(GLUT_RIGHT_BUTTON);

}

int main(int argc,char **argv)
{
randval = (rand()%2)-0.7;
glutInit(&argc,argv);
glutInitWindowSize(900,900);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
glutCreateWindow("A day in Hogwarts");
glutDisplayFunc(display);
glutKeyboardFunc(keyPressed);
glutMouseFunc(keyClicked);
glutSpecialFunc(splKey);
glutIdleFunc(display);
menu();
glutMainLoop();
}
