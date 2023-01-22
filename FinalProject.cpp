#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>
#define PI          3.141516
#include<math.h>

void idle();
int dayCheck;
float boatx = 30;
void sun(int dayCheck);
void circle(GLfloat p1, GLfloat q1, GLfloat r1, int r, int g, int b);

void stick(int a, int bb, int c, int d, int r, int g, int b){
    int x1 = a, y1 = bb, xx = c, yy = d;
    glBegin(GL_QUADS);
    glColor3ub(r, g, b);
    glVertex2i(x1, y1+yy);
    glVertex2i(x1, y1);
    glVertex2i(x1+xx, y1);
    glVertex2i(x1+xx, y1+yy);
    glEnd();
}
void areaBorder(int a){
    for(int i=10; i<370; i+=a){
        stick(i, 0, 5, 25, 0, 0, 0);
    }
    for(int i = 370, j= 0; i>=245 && j<=67; i-= 10, j += 5){
        stick(i, j, 4, 25, 0, 0, 0);
    }
}

void sun( int dayCheck){
    int r = 255, g = 255, b = 0;
    if( dayCheck == 1 ) b = 255;
    circle(470.f, 280.f, 33.f, r, g, b);
}

int decress(int a){
    return (a - 60>= 0 )? (a-60) : 0;
}

void leaf(int check){
    int r = 0, g = 102, b = 0;
    if(check == 1){
        r = decress(r);
        g = decress(g);
        b = decress(b);
    }
    circle(20.f, 300.f, 70.f, r ,g ,b);
    circle(80.f, 300.f, 50.f, r ,g ,b);
    circle(120.f, 320.f, 50.f, r ,g ,b);
}

void tree(){
    int g = 50;
    if(dayCheck == 1) g = 0;
    circle(55.f, 205.f, 20.f, 0, g, 0);
    circle(30.f, 200.f, 15.f, 0, g, 0);
    circle(80.f, 200.f, 15.f, 0, g, 0);
    circle(100.f, 195.f, 10.f, 0, g, 0);
    circle(115.f, 195.f, 10.f, 0, g, 0);

    circle(575.f, 205.f, 20.f, 0, g, 0);
    circle(600.f, 200.f, 15.f, 0, g, 0);
    circle(550.f, 200.f, 15.f, 0, g, 0);
    circle(530.f, 195.f, 10.f, 0, g, 0);
    circle(515.f, 195.f, 10.f, 0, g, 0);

    circle(165.f, 205.f, 20.f, 0, g, 0);
    circle(135.f, 200.f, 15.f, 0, g, 0);
    circle(190.f, 200.f, 15.f, 0, g, 0);
    circle(210.f, 195.f, 10.f, 0, g, 0);
    circle(225.f, 195.f, 10.f, 0, g, 0);

    circle(270.f, 205.f, 20.f, 0, g, 0);
    circle(245.f, 200.f, 15.f, 0, g, 0);
    circle(295.f, 200.f, 15.f, 0, g, 0);
    circle(315.f, 195.f, 10.f, 0, g, 0);
    circle(330.f, 195.f, 10.f, 0, g, 0);

    circle(375.f, 205.f, 20.f, 0, g, 0);
    circle(350.f, 200.f, 15.f, 0, g, 0);
    circle(400.f, 200.f, 15.f, 0, g, 0);
    circle(420.f, 195.f, 10.f, 0, g, 0);
    circle(430.f, 195.f, 10.f, 0, g, 0);

    circle(475.f, 205.f, 20.f, 0, g, 0);
    circle(450.f, 200.f, 15.f, 0, g, 0);
    circle(500.f, 200.f, 15.f, 0, g, 0);
    circle(520.f, 195.f, 10.f, 0, g, 0);
    circle(435.f, 195.f, 10.f, 0, g, 0);
}

void sky(int dayCheck){
    int r1 = 147, g1 = 236, b1 = 244;
    int r2 = 243, g2 = 240, b2 = 189;
    if( dayCheck == 1 ){
        r1 = 0;
        g1 = 0;
        b1 = 53;

        r2 = 0;
        g2 = 0;
        b2 = 204;
    }
    glBegin(GL_QUADS);
    glColor3ub(r1, g1, b1);
    glVertex2i(0, 200);
    glVertex2i(600, 200);
    glColor3ub(r2, g2, b2);
    glVertex2i(600, 300);
    glVertex2i(0, 300);
}
void boat(float a, int b, int c, int d, bool check, bool dayCheck){

    float x1 = a, y1 = b, xx = c, yy = d;
    float r1 = 204, g1 = 102, b1 = 0;
    if( check == 1 ){
        r1 = decress(r1);
        g1 = decress(g1);
        b1 = decress(b1);
    }
    glBegin(GL_TRIANGLES);
    glColor3ub(r1, g1, b1);
    glVertex2i(x1, y1);
    glVertex2i(x1+xx, y1-yy);
    glVertex2i(x1+xx, y1-yy*2-1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(r1, g1, b1);
    glVertex2i(x1+xx, y1-yy);
    glVertex2i(x1+xx*3, y1-yy);
    glVertex2i(x1+xx*3, y1-yy*2-1);
    glVertex2i(x1+xx, y1-yy*2-1);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(r1, g1, b1);
    glVertex2i(x1+xx*3, y1-yy);
    glVertex2i(x1+xx*3, y1-yy*2-1);
    glVertex2i(x1+xx*4, y1);
    glEnd();

    if(check){
        //house on boat
        glBegin(GL_POLYGON);
        glColor3ub(102, 51, 0);
        glVertex2i(x1+xx-5, y1-yy);
        glVertex2i(x1+xx-5, y1+yy*2);
        glVertex2i(x1+xx-3, y1+yy*2+2);
        glVertex2i(x1+xx, y1+yy*2);
        glVertex2i(x1+xx, y1-yy*2-1);
        glEnd();

        if(dayCheck == 0) circle(x1+xx*3.2, y1-yy*0.9, yy*1.8, 200, 200, 200);

        glBegin(GL_POLYGON);
        glColor3ub(204, 0, 0);
        glVertex2i(x1+xx, y1+yy*2);
        glVertex2i(x1+xx-3, y1+yy*2+2);
        glVertex2i(x1+xx*3-3, y1+yy*2+2);
        glVertex2i(x1+xx*3, y1+yy*2);
        glVertex2i(x1+xx*3, y1-yy*2-1);
        glVertex2i(x1+xx, y1-yy*2-1);
        glEnd();
    }
    //part of below
    glBegin(GL_TRIANGLES);
    glColor3ub(51, 25, 0);
    glVertex2i(x1, y1);
    glVertex2i(x1+xx, y1-yy*4-2);
    glVertex2i(x1+xx, y1-yy*2-1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(51, 25, 0);
    glVertex2i(x1+xx, y1-yy*2-1);
    glVertex2i(x1+xx*3, y1-yy*2-1);
    glVertex2i(x1+xx*3, y1-yy*4-2);
    glVertex2i(x1+xx, y1-yy*4-2);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(51, 25, 0);
    glVertex2i(x1+xx*3, y1-yy*2-1);
    glVertex2i(x1+xx*3, y1-yy*4-2);
    glVertex2i(x1+xx*4, y1);
    glEnd();
}
void window(){
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2i(120, 95);
    glVertex2i(120, 70);
    glVertex2i(130, 80);
    glVertex2i(130, 105);
    glEnd();
    //door
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2i(27, 70);
    glVertex2i(27, 37);
    glVertex2i(50, 37);
    glVertex2i(50, 70);
    glEnd();
}
void circle(GLfloat p1, GLfloat q1, GLfloat r1, int r, int g, int b)
{
    int i;
    int tringle2=40;

    GLfloat tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( r, g, b);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }

    glEnd ();
}

void myDisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glPointSize(5.0);

//sky
    sky(dayCheck);

//tree
    tree();

//Water
    glBegin(GL_QUADS);
    if(dayCheck == 0)glColor3ub (72, 118, 255);
    else glColor3ub(decress(71-30), decress(118-30), decress(255-30));
    glVertex2i(0, 200);
    glVertex2i(600, 200);
    if(dayCheck == 0) glColor3ub(135, 206, 255);
    else glColor3ub(decress(135-30), decress(206-30), decress(255-30));
    glVertex2i(600, 0);
    glVertex2i(0, 0);
    glEnd();

//par er back
    //1st
    glBegin(GL_TRIANGLES);
    glColor3ub (120, 76, 10);
    glVertex2i(265, 140);
    glVertex2i(265, 120);
    glVertex2i(240, 140);
    glEnd();
    //2nd
    glBegin(GL_TRIANGLES);
    glColor3ub (120, 76, 10);
    glVertex2i(266, 120);
    glVertex2i(290, 120);
    glVertex2i(290, 90);
    glEnd();
    //3rd
    glBegin(GL_TRIANGLES);
    glColor3ub (120, 76, 10);
    glVertex2i(305, 90);
    glVertex2i(330, 90);
    glVertex2i(330, 50);
    glEnd();
    //4th
    glBegin(GL_TRIANGLES);
    glColor3ub (120, 76, 10);
    glVertex2i(360, 50);
    glVertex2i(390, 50);
    glVertex2i(390, 0);
    glEnd();

//par
    //1st par
    glBegin(GL_TRIANGLES);
    if(dayCheck == 0) glColor3ub (50,140,49);
    else glColor3ub(decress(50), decress(140), decress(49));
    glVertex2i(0, 140);
    glVertex2i(265, 140);
    glVertex2i(0, 170);
    glEnd();
    //5th par
    glBegin(GL_QUADS);
    if(dayCheck == 0) glColor3ub (50,140,49);
    else glColor3ub(decress(50), decress(140), decress(49));
    glVertex2i(0, 0);
    glVertex2i(550, 0);
    glVertex2i(365, 50);
    glVertex2i(0, 50);
    glEnd();

//4th par
glBegin(GL_QUADS);
if(dayCheck == 0) glColor3ub (50,140,49);
else glColor3ub(decress(50), decress(140), decress(49));
glVertex2i(0, 50);
glVertex2i(390, 50);
glVertex2i(305, 90);
glVertex2i(0, 90);
glEnd();

//3rd par
glBegin(GL_QUADS);
if(dayCheck == 0) glColor3ub (50,140,49);
else glColor3ub(decress(50), decress(140), decress(49));
glVertex2i(0, 90);
glVertex2i(330, 90);
glVertex2i(266, 120);
glVertex2i(0, 120);
glEnd();

//2nd par
glBegin(GL_QUADS);
if(dayCheck == 0) glColor3ub (50,140,49);
else glColor3ub(decress(50), decress(140), decress(49));
glVertex2i(0, 120);
glVertex2i(290, 120);
glVertex2i(240, 140);
glVertex2i(0, 140);
glEnd();

//House

//House 2 front
glBegin(GL_QUADS);
if(dayCheck == 0) glColor3ub(204, 204, 0);
else glColor3ub(decress(204), decress(204), 0);
glVertex2i(140, 115);
glVertex2i(200, 115);
glVertex2i(200, 77);
glVertex2i(140, 77);
glEnd();
//House 2 top
glBegin(GL_POLYGON);
if(dayCheck == 0)glColor3ub(102, 51, 0);
else glColor3ub(decress(102), decress(51), 0);
glVertex2i(145, 135);
glVertex2i(180, 135);
glVertex2i(215, 105);
glVertex2i(200, 112);
glVertex2i(190, 115);
glVertex2i(140, 115);
glVertex2i(135, 125);
glEnd();
//House 2 below
glBegin(GL_QUADS);
if(dayCheck == 0) glColor3ub(120, 76, 10);
else glColor3ub(decress(120), decress(76), decress(10));
glVertex2i(140, 77);
glVertex2i(200, 77);
glVertex2i(206, 73);
glVertex2i(140, 73);
glEnd();
//House 2 door
glBegin(GL_QUADS);
glColor3ub(120, 76, 10);
glVertex2i(155, 100);
glVertex2i(155, 77);
glVertex2i(170, 77);
glVertex2i(170, 100);
glEnd();

//House 1
//Front part
glBegin(GL_QUADS);
 glColor3ub(190, 90, 0);
glVertex2i(0, 105);
glVertex2i(110, 105);
glVertex2i(110, 37);
glVertex2i(0, 37);
glEnd();
//Right Part
glBegin(GL_POLYGON);
if(dayCheck == 0) glColor3ub (238, 118, 0);
else glColor3ub(decress(238), decress(118), decress(0));
glVertex2i(125, 130);
glVertex2i(140, 109);
glVertex2i(140, 67);
glVertex2i(110, 37);
glVertex2i(110, 105);
glEnd();
//Top Back
glBegin(GL_POLYGON);
if(dayCheck == 0) glColor3ub (115, 70, 10);
else glColor3ub(decress(115), decress(70), decress(10));
glVertex2i(125, 130);
glVertex2i(140, 109);
glVertex2i(145, 97);
glVertex2i(152, 97);
glVertex2i(130, 135);
glEnd();
//top front
glBegin(GL_QUADS);
if(dayCheck == 0) glColor3ub (255, 173, 0);
else glColor3ub(decress(255), decress(173), decress(0));
glVertex2i(0, 135);
glVertex2i(130,135);
glVertex2i(91, 75);
glVertex2i(0,75);
glEnd();
//house low border
glBegin(GL_QUADS);
glColor3ub(110, 66, 10);
glVertex2i(110, 37);
glVertex2i(110, 28);
glVertex2i(146, 63);
glVertex2i(140, 67);
glEnd();
//front part
glBegin(GL_QUADS);
glColor3ub(153, 76, 0);
glVertex2i(0, 37);
glVertex2i(110, 37);
glVertex2i(91, 18);
glVertex2i(0, 18);
glEnd();
//front below border
glBegin(GL_QUADS);
glColor3ub(110, 66, 10);
glVertex2i(91, 18);
glVertex2i(110, 37);
glVertex2i(110, 28);
glVertex2i(91, 9);
glEnd();
//front upper border
glBegin(GL_QUADS);
glColor3ub(110, 66, 10);
glVertex2i(0, 18);
glVertex2i(0, 9);
glVertex2i(91, 9);
glVertex2i(91, 18);
glEnd();
//stick with house top

stick(81, 18, 5, 57, 110, 66, 10);

//window
window();
//Door
glBegin(GL_QUADS);
glColor3ub(122, 71, 20);
glVertex2i(34, 37);
glVertex2i(34, 63);
glVertex2i(50, 70);
glVertex2i(50, 37);
glEnd();

//khor
    glBegin(GL_QUADS);
    glColor3ub(205, 173, 0);
    glVertex2i(204, 63);
    glVertex2i(252, 63);
    glVertex2i(244, 105);
    glVertex2i(210, 105);
    glEnd();
    circle(227.f, 105.f, 17.f, 205, 173, 0);

//leaf
    leaf(dayCheck);

//Tree
    //wood
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2i(0, 0);
    glVertex2i(100, 0);
    glVertex2i(75, 3);
    glVertex2i(45, 10);
    glVertex2i(30, 25);
    //strict line
    glVertex2i(23, 90);
    glVertex2i(23, 125);
    glVertex2i(27, 170);
    glVertex2i(20, 240);
    //glVertex2i(20, 250);
    glVertex2i(0, 240);
    glEnd();

    //sakha
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2i(0, 240);
    glVertex2i(20, 240);
    glVertex2i(80, 300);
    glVertex2i(55, 300);
    glVertex2i(20, 270);
    glVertex2i(20, 300);
    glVertex2i(0, 300);
    glEnd();

    //front leaf
    if(dayCheck == 0) circle(80.f, 300.f, 10.f, 0 ,102 ,0);
    else circle(80.f, 300.f, 10.f, 0, decress(102), 0);

//boat
    boat(320, 100, 40, 5, 0, dayCheck);
    boat(347, 90, 40, 5, 0, dayCheck);
    boat(boatx, 190, 20, 2, 1, dayCheck);
    boat(435, 150, 25, 3, 1, dayCheck);

    //stick with boat
    glBegin(GL_QUADS);
    glColor3ub(153, 76, 0);
    glVertex2i(347, 120);
    glVertex2i(350, 120);
    glVertex2i(350, 60);
    glVertex2i(347, 60);
    glEnd();

//sun
    sun(dayCheck);
    areaBorder(15);

    glFlush ();
}

void myInit (void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    gluOrtho2D(0.0, 600.0, 0.0, 300.0);
}

void keyboard(int key, int x, int y){
    switch(key){
    case GLUT_KEY_RIGHT:
        if(dayCheck == 1)
            dayCheck = 0;
        else dayCheck = 1;
        glutPostRedisplay();
            break;
    default:
        break;
    }
}

unsigned long long lastFrameTime = 0;

void idle()
{
    float frameTime = 1000 / 60.0, currentTime = 0;
    float factor = 0.04f;
    if(dayCheck == 0){
        if (boatx <= 600 )
        {
            boatx += factor;
        }
        else
        {
            boatx = 20;
        }
    }
    else boatx = 600;
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (600, 300);
    glutInitWindowPosition (100, 150);
    glutCreateWindow ("");
    glutSpecialFunc(keyboard);
    glutIdleFunc(idle);
    glutDisplayFunc(myDisplay);
    myInit ();
    glutMainLoop();
}
