
#include <iostream>
#include <windows.h>
#include<gl/glut.h>
#include<math.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

float col=0,sun=0,clup1=0,clup2=0,cgo=0,clgo=0;

void line(int X[],int Y[],int n){
    glBegin(GL_LINES);
    for(int i=0;i<n;i++){
        glVertex2i(X[i],Y[i]);
    glEnd();
    }
}

void tri(int X[],int Y[],int n=3){
    glBegin(GL_TRIANGLES);
    for(int i=0;i<n;i++){
        glVertex2i(X[i],Y[i]);
    }
    glEnd();
}

void rec(int X[],int Y[],int n=4){
    glBegin(GL_POLYGON);
    for(int i=0;i<n;i++){
        glVertex2i(X[i],Y[i]);
    }
    glEnd();
}

void poly(int X[],int Y[],int n){
    glBegin(GL_POLYGON);
    for(int i=0;i<n;i++){
        glVertex2i(X[i],Y[i]);
    }
    glEnd();
}

void cir(int x,int y,int radius){
    glBegin(GL_POLYGON);
    for(int i=0;i<360;i++){
        float theta=i*3.1416/180;
        glVertex2i(x+radius*cos(theta),y+radius*sin(theta));
    }
    glEnd();
}

void oval(int x,int y,int rx,int ry){
    glBegin(GL_POLYGON);
    for(int i=0;i<360;i++){
        float theta=i*3.1416/180;
        glVertex2i(x+rx*cos(theta),y+ry*sin(theta));
    }
    glEnd();
}

void timer(int){
    glutPostRedisplay();
    glutTimerFunc(2500/60,timer,0);
    if(cgo<220){
        cgo++;
        clgo--;
        clup1+=.3;
        clup2+=.15;
        sun-=.2;
        col-=.003;
    }
}


void draw(){
    glClear(GL_COLOR_BUFFER_BIT);

///background
    glColor3f(0,0.6+col,1+col);//sky
    int skyx[]={-50,300,300,-50},skyy[]={150,150,110,110};
    rec(skyx,skyy);

///sun
    glColor3f(1.000,0.000,0.000);
    cir(250+sun,129+sun,15);
///clouds
//cloud1
    glColor3f(1,1,1);
    cir(90+clgo,130+clup2,5);
    cir(70+clgo,130+clup2,5);
    cir(80+clgo,132+clup2,10);
    cir(98+clgo,130+clup2,5);
//cloud2
    oval(130+clgo,135+clup1,2,5);
    oval(130+clgo,135+clup1,8,3);

///deserts
//deser2
    glColor3f(.9,0.9,.7);//2nddesert
    int d1x[]={-50,300,250,300,-50},d1y[]={110,110,125,-20,-20};
    poly(d1x,d1y,5);
//desert1
    int d2x[]={-50,300,300,-50},d2y[]={-60,-60,-120,-120};
    rec(d2x,d2y);

//bird
    glColor3f(1,1,0);
	glBegin(GL_TRIANGLES);
		glVertex2f(-22+cgo,134-(clgo/10));
		glVertex2f(-15+cgo,134-(clgo/10));
		glVertex2f(-15+cgo,130-(clgo/10));
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex2f(-15+cgo,138-(clgo/10));
		glVertex2f(-12+cgo,138-(clgo/10));
		glVertex2f(-15+cgo,134-(clgo/10));
	glEnd();


//chair
    glColor3f(0.5,0.5,0.3);//head
    glBegin(GL_POLYGON);
        glVertex3f(0,-75,0);
        glVertex3f(40,-75,0);
        glVertex3f(40,-90,0);
        glVertex3f(0,-90,0);
    glEnd();//bottom
    glBegin(GL_POLYGON);
        glVertex3f(10,-95,0);
        glVertex3f(50,-95,0);
        glVertex3f(50,-105,0);
        glVertex3f(10,-105,0);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
        glVertex3f(1,-90,0);
        glVertex3f(1,-100,0);
    glEnd();;//head2
    glBegin(GL_POLYGON);
        glVertex3f(200,-75,0);
        glVertex3f(240,-75,0);
        glVertex3f(240,-90,0);
        glVertex3f(200,-90,0);
    glEnd();//bottom2
    glBegin(GL_POLYGON);
        glVertex3f(210,-95,0);
        glVertex3f(250,-95,0);
        glVertex3f(250,-105,0);
        glVertex3f(210,-105,0);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
        glVertex3f(201,-90,0);
        glVertex3f(201,-100,0);
    glEnd();

    glColor3f(.5,.5,.4);//seat2
    glBegin(GL_POLYGON);
        glVertex3f(200,-90,0);
        glVertex3f(240,-90,0);
        glVertex3f(250,-95,0);
        glVertex3f(210,-95,0);
    glEnd();
    //seat1
    glBegin(GL_POLYGON);
        glVertex3f(0,-90,0);
        glVertex3f(40,-90,0);
        glVertex3f(50,-95,0);
        glVertex3f(10,-95,0);
    glEnd();


//catrus1
    glColor3f(0,1,0);
    glLineWidth(10);
    glBegin(GL_LINES);
        glVertex3f(101,-90,0);
        glVertex3f(101,-100,0);
    glEnd();
    glLineWidth(10);
    glBegin(GL_LINES);
        glVertex3f(105,-80,0);
        glVertex3f(105,-100,0);
    glEnd();
    glLineWidth(10);
    glBegin(GL_LINES);
        glVertex3f(108,-90,0);
        glVertex3f(108,-100,0);
    glEnd();
    glLineWidth(10);
    glBegin(GL_LINES);
        glVertex3f(98,-95,0);
        glVertex3f(98,-100,0);
    glEnd();

//catrus2
    glColor3f(0,1,0);//main
    glLineWidth(10);
    glBegin(GL_LINES);
        glVertex3f(135,-75,0);
        glVertex3f(135,-110,0);
    glEnd();
    glBegin(GL_LINES);//rightside
        glVertex3f(135,-90,0);
        glVertex3f(140,-90,0);
    glEnd();
    glBegin(GL_LINES);//right
        glVertex3f(140,-80,0);
        glVertex3f(140,-90,0);
    glEnd();
    glBegin(GL_LINES);//lrftside
        glVertex3f(135,-100,0);
        glVertex3f(130,-100,0);
    glEnd();
    glBegin(GL_LINES);//left
        glVertex3f(130,-85,0);
        glVertex3f(130,-100,0);
    glEnd();

//catrus2
    glColor3f(0,1,0);//main
    glLineWidth(10);
    glBegin(GL_LINES);
        glVertex3f(-35,-75,0);
        glVertex3f(-35,-110,0);
    glEnd();
    glBegin(GL_LINES);//rightside
        glVertex3f(-35,-90,0);
        glVertex3f(-40,-90,0);
    glEnd();
    glBegin(GL_LINES);//right
        glVertex3f(-40,-80,0);
        glVertex3f(-40,-90,0);
    glEnd();
    glBegin(GL_LINES);//leftside
        glVertex3f(-35,-100,0);
        glVertex3f(-30,-100,0);
    glEnd();
    glBegin(GL_LINES);//left
        glVertex3f(-30,-85,0);
        glVertex3f(-30,-100,0);
    glEnd();

//road
     glColor3f(0,0,0);//smallroadcolor
    glBegin(GL_POLYGON);
        glVertex3f(100-150,-60,0);
        glVertex3f(200-150,-60,0);
        glVertex3f(350-150,83+40,0);
        glVertex3f(300-150,80+40,0);
    glEnd();
    glColor3f(1,1,1);//roadline(new)
        glLineWidth(3);
    glBegin(GL_LINES);
        glVertex3f(150-150,-90+40,0);
        glVertex3f(320-150,80+40,0);
    glEnd();
     glColor3f(0,0,0);//mainroadcolor
    glBegin(GL_POLYGON);
        glVertex3f(-50,-15,0);
        glVertex3f(300,-15,0);
        glVertex3f(300,-65,0);
        glVertex3f(-50,-65,0);
    glEnd();
     glColor3f(1,1,1);//roadline
        glLineWidth(3);
    glBegin(GL_LINES);
        glVertex3f(-50,-40,0);
        glVertex3f(-40,-40,0);
        glVertex3f(-20,-40,0);
        glVertex3f(20,-40,0);
        glVertex3f(40,-40,0);
        glVertex3f(80,-40,0);
        glVertex3f(100,-40,0);
        glVertex3f(140,-40,0);
        glVertex3f(160,-40,0);
        glVertex3f(200,-40,0);
        glVertex3f(220,-40,0);
        glVertex3f(260,-40,0);
        glVertex3f(280,-40,0);
        glVertex3f(300,-40,0);
        glEnd();

//windfan
        glColor3f(.3,.3,.2);//fanstand
    glBegin(GL_POLYGON);
        glVertex3f(278,-8,0);
        glVertex3f(272,-8,0);
        glVertex3f(272,88,0);
        glVertex3f(278,88,0);
    glEnd();
    glColor3f(.3,.3,.2);//fan
        glLineWidth(10);
    glBegin(GL_LINES);
        glVertex3f(255,70,0);
        glVertex3f(295,100,0);
        glVertex3f(295,70,0);
        glVertex3f(255,100,0);
    glEnd();

//mountain
     glColor3f(.6,0.5,.1);//small
    glBegin(GL_TRIANGLES);
        glVertex3f(-5,148,0);
        glVertex3f(40,90,0);
        glVertex3f(-50,90,0);
    glEnd();
    glColor3f(.7,0.5,.1);//big
    glBegin(GL_TRIANGLES);
        glVertex3f(-40,140,0);
        glVertex3f(40,40,0);
        glVertex3f(-120,30,0);
    glEnd();

//house
         glColor3f(.3,0,0);//rooftop
    glBegin(GL_POLYGON);
        glVertex3f(100+80,100,0);
        glVertex3f(150+80,100,0);
        glVertex3f(160+80,80,0);
        glVertex3f(90+80,80,0);
    glEnd();
    glColor3f(.5,.5,.5);//roofpipe
    glBegin(GL_POLYGON);
        glVertex3f(138+80,105,0);
        glVertex3f(144+80,105,0);
        glVertex3f(144+80,90,0);
        glVertex3f(138+80,90,0);
    glEnd();
        glColor3f(0,.5,0);//2ndfloor
    glBegin(GL_POLYGON);
        glVertex3f(95+80,80,0);
        glVertex3f(155+80,80,0);
        glVertex3f(155+80,40,0);
        glVertex3f(95+80,40,0);
    glEnd();
        glColor3f(.8,.2,.2);//2nddoor
    glBegin(GL_POLYGON);
        glVertex3f(100+80,70,0);
        glVertex3f(120+80,70,0);
        glVertex3f(120+80,40,0);
        glVertex3f(100+80,40,0);
    glEnd();
        glColor3f(.7,.7,1);//2ndhandle
    glBegin(GL_POLYGON);
        glVertex3f(104+80,60,0);
        glVertex3f(106+80,60,0);
        glVertex3f(106+80,54,0);
        glVertex3f(104+80,54,0);
    glEnd();
    glColor3f(.8,.2,.2);//window
    glBegin(GL_POLYGON);
        glVertex3f(135+80,75,0);
        glVertex3f(150+80,75,0);
        glVertex3f(150+80,60,0);
        glVertex3f(135+80,60,0);
    glEnd();
    glColor3f(.8,.8,1);//windowline
        glLineWidth(3);
        glBegin(GL_LINES);
        glVertex3f(135+80,68,0);
        glVertex3f(150+80,68,0);
        glVertex3f(142+80,75,0);
        glVertex3f(142+80,60,0);
        glEnd();
    glColor3f(.3,0,0);//1stroof
    glBegin(GL_POLYGON);
        glVertex3f(92+80,40,0);
        glVertex3f(159+80,40,0);
        glVertex3f(159+80,35,0);
        glVertex3f(92+80,35,0);
    glEnd();
    glColor3f(0,0,0);//roofboundries
    glBegin(GL_POLYGON);
        glVertex3f(92+80,55,0);
        glVertex3f(159+80,55,0);
        glVertex3f(159+80,53,0);
        glVertex3f(92+80,53,0);
    glEnd();
    glColor3f(0,0,0);//boundriesblock
    glLineWidth(2);
        glBegin(GL_LINES);
            glVertex3f(93+80,53,0);
            glVertex3f(93+80,40,0);
            glVertex3f(103+80,53,0);
            glVertex3f(103+80,40,0);
            glVertex3f(113+80,53,0);
            glVertex3f(113+80,40,0);
            glVertex3f(123+80,53,0);
            glVertex3f(123+80,40,0);
            glVertex3f(133+80,53,0);
            glVertex3f(133+80,40,0);
            glVertex3f(143+80,53,0);
            glVertex3f(143+80,40,0);
            glVertex3f(153+80,53,0);
            glVertex3f(153+80,40,0);
            glVertex3f(158+80,53,0);
            glVertex3f(158+80,40,0);
        glEnd();
        glColor3f(.2,0,1);//1stfloor
    glBegin(GL_POLYGON);
        glVertex3f(93+80,35,0);
        glVertex3f(158+80,35,0);
        glVertex3f(158+80,-5,0);
        glVertex3f(93+80,-5,0);
    glEnd();
    glColor3f(0,0,.1);//1stpiller
    glBegin(GL_POLYGON);
        glVertex3f(97+80,35,0);
        glVertex3f(101+80,35,0);
        glVertex3f(101+80,-5,0);
        glVertex3f(97+80,-5,0);
    glEnd();
    glColor3f(0,0,.1);//2ndpiller
    glBegin(GL_POLYGON);
        glVertex3f(150+80,35,0);
        glVertex3f(154+80,35,0);
        glVertex3f(154+80,-5,0);
        glVertex3f(150+80,-5,0);
    glEnd();
    glColor3f(1,1,0);//1stdoor
    glBegin(GL_POLYGON);
        glVertex3f(110+80,25,0);
        glVertex3f(140+80,25,0);
        glVertex3f(140+80,-5,0);
        glVertex3f(110+80,-5,0);
    glEnd();
    glColor3f(.5,.5,0);//doorline
        glBegin(GL_LINES);
        glVertex3f(126+80,25,0);
        glVertex3f(126+80,-5,0);
        glEnd();
    glColor3f(.7,.7,1);//2ndboundries
    glBegin(GL_POLYGON);
        glVertex3f(92+80,-5,0);
        glVertex3f(159+80,-5,0);
        glVertex3f(159+80,-8,0);
        glVertex3f(92+80,-8,0);
    glEnd();
    glColor3f(.5,.5,1);//2ndboundries
    glBegin(GL_POLYGON);
        glVertex3f(90+80,-8,0);
        glVertex3f(161+80,-8,0);
        glVertex3f(161+80,-10,0);
        glVertex3f(90+80,-10,0);
    glEnd();


//car
    glBegin(GL_POLYGON);//bottom part
    {
        glColor3f(1,0,0);
       glVertex3f(10+cgo,-40,0);
       glVertex3f(10+cgo,-26,0);
       glVertex3f(68+cgo,-26,0);
       glVertex3f(68+cgo,-40,0);
       glEnd();

    }
    glBegin(GL_POLYGON);//top part
    {
        glColor3f(0.5,1,0);
       glVertex3f(15+cgo,-26,0);
       glVertex3f(20+cgo,-12,0);
       glVertex3f(34+cgo,-12,0);
       glVertex3f(34+cgo,-26,0);
       glEnd();

    }
    glLineWidth(6);//cabin
    glBegin(GL_LINES);
    glColor3f(1,0,0);
    {
       glVertex3f(34+cgo,-12,0);
       glVertex3f(34+cgo,-26,0);
    }
    glEnd();
    glBegin(GL_POLYGON);//top part
    {
        glColor3f(0.5,1,0);
       glVertex3f(34+cgo,-12,0);
       glVertex3f(34+cgo,-26,0);
       glVertex3f(58+cgo,-26,0);
       glVertex3f(50+cgo,-12,0);
       glEnd();

    }

    glColor3f(.5,.5,.5);
    glBegin(GL_POLYGON);//wheel1
    for(int i=0;i<360;i++) {
      float theta=i*3.1416/180;
      glVertex2f(20+cgo+6*cos(theta),-41+6*sin(theta));
      }
    glEnd();
    glBegin(GL_POLYGON);//wheel2
    for(int i=0;i<360;i++) {
      float theta=i*3.1416/180;
      glVertex2f(50+cgo+6*cos(theta),-41+6*sin(theta));
      }
    glEnd();

//river
    glColor3f(0.5,0.5,1);
    glBegin(GL_POLYGON);
        glVertex3f(-50,-150,0);
        glVertex3f(300,-150,0);
        glVertex3f(300,-110,0);
        glVertex3f(-50,-120,0);
    glEnd();

    glutSwapBuffers();
}

void initialize(){
    glClearColor(1,1,1,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50,300,-150,150,-1,1);
}

int main(int Argc,char **Argv){
    glutInit(&Argc,Argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(900,600);
    glutInitWindowPosition(450,80);
    glutCreateWindow("Motels in the desert");
    initialize();
    sndPlaySound("sound.wav",SND_ASYNC);
    glutDisplayFunc(draw);
    glutTimerFunc(1000,timer,0);
    glutMainLoop();
    return 0;
}
