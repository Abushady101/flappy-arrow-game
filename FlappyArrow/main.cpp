#include<GL/glut.h>
#include <stdio.h>
#include <cstdio>
#include <math.h>
#include <cstring>
int phyWidth= 700;
int phyHeight= 700;
int logWidth=100;
int logHeight=100;
int centerX=logWidth/2;
int centerY=logHeight/2;
int mouseXX,mouseYY;
int mouseX=centerX, mouseY=centerY;
int sqWid=20;
int sqHight=10;
int cx1=48,cy1=70,cx2=48,cy2=50,cx3=48,cy3=30;
int status=0;
int h = 60;
int ax1=20, ay1=50, atx1=35, atx2=30;
int awidth=10;
int atheight=20;
float arrowdelta=0;
float r1=0.52, r2=0.52, r3=0.52 , g1=0.36, g2=0.36, g3=0.36, b1= 0.25, b2=0.25, b3=0.25;
int a=0;
int ox1=50, ox2=100;
int oheight1=30,oheight2=70,o2height1=40,o2height2=80, cheight=30,cheight1=50,cheight2=80;
float ospeed=0,ospeed1=0,cspeed=0,cspeed2=0,cspeed3=0;
int score=0;
char scoretxt= score;
void init()
{

glClearColor( 1, 1, 1.0, 0); // COLOR


glMatrixMode( GL_PROJECTION);
gluOrtho2D( 0.0, logWidth, 0.0, logHeight);

}
//function to reset all variables
void restartgame(){
status=0;
arrowdelta=0;
oheight1=30;
oheight2=70;
o2height1=40;
o2height2=80;
cheight=30;
ospeed=0;
ospeed1=0;
cspeed=0;
status=1;}

void printSome(char *str,int x,int y) {
glColor3f (0, 1, 1);
glRasterPos2d(x,y);
for (int i=0;i<strlen(str);i++)

glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str[i]);

glFlush();
}
void printSome2(char *str,int x,int y) {
glColor3f (1, 0, 1);
glRasterPos2d(x,y);
for (int i=0;i<strlen(str);i++)

glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);

glFlush();
}
void DrawCircle(float cx, float cy, float r, int num_segments)
{
glBegin(GL_POLYGON);
for (int i = 0; i < num_segments; i++) {
float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle
float x = r * cosf(theta);//calculate the x component
float y = r * sinf(theta);//calculate the y component
glVertex2f(x + cx, y + cy);//output vertex
}
glEnd();
}
void level(){
    glClearColor( 0, 1, 1.0, 0);
//clouds random generator
glColor3f(1,1,1);
if(cspeed3<=-100){
    cheight=20+(rand()%60);
    cspeed3=100;
    DrawCircle(80+cspeed3,cheight+5,4,100);
    DrawCircle(77+cspeed3,cheight,4,100);
    DrawCircle(83+cspeed3,cheight,4,100);
}
if(cspeed2<=-40){
    cheight1=20+(rand()%60);
    cspeed2=100;
    DrawCircle(30+cspeed2,cheight1+5,4,100);
    DrawCircle(27+cspeed2,cheight1,4,100);
    DrawCircle(33+cspeed2,cheight1,4,100);
}
if(cspeed<=-70){
    cheight2=20+(rand()%60);
    cspeed=100;
    DrawCircle(50+cspeed,cheight2+5,4,100);
    DrawCircle(47+cspeed,cheight2,4,100);
    DrawCircle(53+cspeed,cheight2,4,100);
}
//intial clouds
DrawCircle(80+cspeed3,cheight+5,4,100);
DrawCircle(77+cspeed3,cheight,4,100);
DrawCircle(83+cspeed3,cheight,4,100);

DrawCircle(30+cspeed2,cheight1+5,4,100);
DrawCircle(27+cspeed2,cheight1,4,100);
DrawCircle(33+cspeed2,cheight1,4,100);

DrawCircle(50+cspeed,cheight2+5,4,100);
DrawCircle(47+cspeed,cheight2,4,100);
DrawCircle(53+cspeed,cheight2,4,100);
//obstacles random generator
glColor3f(0.4,0.4,0.4);
if (ospeed<=-55){
oheight1=(rand() % 30);
oheight2=50+(rand() % 30);
ospeed =70;
glBegin(GL_POLYGON);
glVertex2f(ox2-awidth/2+ospeed,0);
glVertex2f(ox2+awidth/2+ospeed,0);
glVertex2f(ox2+awidth/2+ospeed,oheight1);
glVertex2f(ox2-awidth/2+ospeed,oheight1);
glEnd();
glBegin(GL_POLYGON);
glVertex2f(ox2-awidth/2+ospeed,100);
glVertex2f(ox2+awidth/2+ospeed,100);
glVertex2f(ox2+awidth/2+ospeed,oheight2);
glVertex2f(ox2-awidth/2+ospeed,oheight2);
glEnd();
}
else if (ospeed1<=-110){
o2height1=(rand() % 30);
o2height2=50+(rand() % 30);
ospeed1 =20;
glBegin(GL_POLYGON);
glVertex2f(ox2-awidth/2+ospeed,0);
glVertex2f(ox2+awidth/2+ospeed,0);
glVertex2f(ox2+awidth/2+ospeed,o2height1);
glVertex2f(ox2-awidth/2+ospeed,o2height1);
glEnd();
glBegin(GL_POLYGON);
glVertex2f(ox2-awidth/2+ospeed,100);
glVertex2f(ox2+awidth/2+ospeed,100);
glVertex2f(ox2+awidth/2+ospeed,o2height2);
glVertex2f(ox2-awidth/2+ospeed,o2height2);
glEnd();
}

//intial obstacles
//obstacles 1
glBegin(GL_POLYGON);
glVertex2f((ox1-awidth/2)+ospeed,0);
glVertex2f((ox1+awidth/2)+ospeed,0);
glVertex2f((ox1+awidth/2)+ospeed,oheight1);
glVertex2f((ox1-awidth/2)+ospeed,oheight1);
glEnd();
glBegin(GL_POLYGON);
glVertex2f((ox1-awidth/2)+ospeed,100);
glVertex2f((ox1+awidth/2)+ospeed,100);
glVertex2f((ox1+awidth/2)+ospeed,oheight2);
glVertex2f((ox1-awidth/2)+ospeed,oheight2);
glEnd();
//obstacles 2
glBegin(GL_POLYGON);
glVertex2f((ox2-awidth/2)+ospeed1,0);
glVertex2f((ox2+awidth/2)+ospeed1,0);
glVertex2f((ox2+awidth/2)+ospeed1,o2height1);
glVertex2f((ox2-awidth/2)+ospeed1,o2height1);
glEnd();
glBegin(GL_POLYGON);
glVertex2f((ox2-awidth/2)+ospeed1,100);
glVertex2f((ox2+awidth/2)+ospeed1,100);
glVertex2f((ox2+awidth/2)+ospeed1,o2height2);
glVertex2f((ox2-awidth/2)+ospeed1,o2height2);
glEnd();
//arrow
glColor3f(1,0, 1);
glBegin(GL_POLYGON);
glVertex2f(ax1-awidth/2,ay1-awidth/2+arrowdelta);
glVertex2f(ax1+awidth/2,ay1-awidth/2+arrowdelta);
glVertex2f(ax1+awidth/2,ay1+awidth/2+arrowdelta);
glVertex2f(ax1-awidth/2,ay1+awidth/2+arrowdelta);
glEnd();
glColor3f(1,0, 1);
glBegin(GL_POLYGON);
glVertex2f(atx1,ay1+arrowdelta);
glVertex2f(ax1+awidth/2,ay1+atheight/2+arrowdelta);
glVertex2f(ax1+awidth/2,ay1-atheight/2+arrowdelta);
glEnd();

arrowdelta-=0.2 ;
ospeed-=0.2;
ospeed1-=0.2;
cspeed-=0.4;
cspeed2-=0.4;
cspeed3-=0.4;
if ((ax1+awidth/2)>=((ox1-awidth/2)+ospeed) && ((ox1-awidth/2)+ospeed)>=10){
    if (((ay1+atheight/2+arrowdelta)+1)>=oheight2||((ay1-atheight/2+arrowdelta)+1)<=oheight1){
        status=4;
        printf("%d",score);
    }
    else {
        score+=1;

    }
}
else if ((ax1+awidth/2)>=((ox2-awidth/2)+ospeed1) && ((ox2-awidth/2)+ospeed1)>=10){
    if (((ay1+atheight/2+arrowdelta)+1)>=o2height2||((ay1-atheight/2+arrowdelta)+1)<=o2height1){
        status=4;
        printf("%d",score);
    }
    else {
        score+=1;

    }
}
glColor3f(1,0,0);
printSome(&scoretxt,10,90);

}
//buttons
void drawSquares(){
glClearColor( 1, 1, 1.0, 0);
glColor3f(0.33,0.41, 0.18); //
glBegin(GL_POLYGON);
glVertex2f(0, 0); // x, y
glVertex2f(100, 0); // x, y
glVertex2f(100, 50); // x, y
glVertex2f(0, 50); // x, y
glEnd();
glColor3f(r1, g1,b1); //
glBegin(GL_POLYGON);
glVertex2f(cx1-sqWid/2, cy1-sqHight/2); // x, y
glVertex2f(cx1+sqWid/2, cy1-sqHight/2); // x, y
glVertex2f(cx1+sqWid/2, cy1+sqHight/2); // x, y
glVertex2f(cx1-sqWid/2, cy1+sqHight/2); // x, y
glEnd();
glColor3f(r2, g2,b2); //
glBegin(GL_POLYGON);
glVertex2f(cx2-sqWid/2, cy2-sqHight/2); // x, y
glVertex2f(cx2+sqWid/2, cy2-sqHight/2); // x, y
glVertex2f(cx2+sqWid/2, cy2+sqHight/2); // x, y
glVertex2f(cx2-sqWid/2, cy2+sqHight/2); // x, y
glEnd();

glColor3f(r3, g3,b3); //
glBegin(GL_POLYGON);
glVertex2f(cx3-sqWid/2, cy3-sqHight/2); // x, y
glVertex2f(cx3+sqWid/2, cy3-sqHight/2); // x, y
glVertex2f(cx3+sqWid/2, cy3+sqHight/2); // x, y
glVertex2f(cx3-sqWid/2, cy3+sqHight/2); // x, y
glEnd();
glColor3f(0,1,1); //
glBegin(GL_POLYGON);
glVertex2f(30, 90); // x, y
glVertex2f(35, 80); // x, y
glVertex2f(25, 80); // x, y
glEnd();
glColor3f(0,1,1); //
glBegin(GL_POLYGON);
glVertex2f(65, 90); // x, y
glVertex2f(70, 80); // x, y
glVertex2f(60, 80); // x, y
glEnd();
printSome("play",cx1-2,cy1);
printSome("High Scores",cx2-7,cy2);
printSome("exit",cx3-2,cy3);
printSome2("Flappy Arrow",38,83);}

void highscores (){
    printSome2("High Scores",40, 80);
FILE* ptr = fopen("HS.txt", "r+");
    if (ptr == NULL) {
        printf("no such file.");

    }
    char s[100];
    char s2[100];
    while (fscanf(ptr, "%s %s",s,s2) == 1){
        printSome(s,40,h);
        printSome(s2,55,h);
        h-=1;

    }

}

void myDisplay()
{

glClear( GL_COLOR_BUFFER_BIT);
if(status==0){
drawSquares();
}
else if(status==1){
    level();

}
if(status==2){
    highscores();
}
if (status==3){
    exit(1);
}
if (status==4){
    printSome2("GAME OVER",40,50);
}
glFlush();
glutSwapBuffers();


}
void passiveMouse (int x,int y){
mouseX = x;
mouseX=0.5+1.0*mouseX*logWidth/phyWidth;
mouseY = phyHeight - y;
mouseY=0.5+1.0*mouseY*logHeight/phyHeight;
if( mouseX>=(cx1-sqWid/2) && mouseX<=(cx1+sqWid/2) && mouseY >=(cy1-sqHight/2) && mouseY <=(cy1+sqHight/2))
{
r1=1;
g1=0.5;
b1=1;
}
else if( mouseX>=(cx2-sqWid/2) && mouseX<=(cx2+sqWid/2) && mouseY >=(cy2-sqHight/2) && mouseY <=(cy2+sqHight/2))
{
r2=1;
g2=0.5;
b2=1;
}
else if( mouseX>=(cx3-sqWid/2) && mouseX<=(cx3+sqWid/2) && mouseY >=(cy3-sqHight/2) && mouseY <=(cy3+sqHight/2))
{
r3=1;
g3=0.5;
b3=1;
}
else{
    r1=0.52;
    r2=0.52;
    r3=0.52;
    g1=0.36;
    g2=0.36;
    g3=0.36;
    b1=0.25;
    b2=0.25;
    b3=0.25;
}



}
void mouseClick(int btn, int state, int x, int y)
{if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
{ mouseXX = x;
mouseXX=0.5+1.0*mouseXX*logWidth/phyWidth;
mouseYY = phyHeight - y;
mouseYY=0.5+1.0*mouseYY*logHeight/phyHeight;
if( mouseXX>=(cx1-sqWid/2) && mouseXX<=(cx1+sqWid/2) && mouseYY >=(cy1-sqHight/2) && mouseYY <=(cy1+sqHight/2))
{
status=1;
}
if( mouseXX>=(cx2-sqWid/2) && mouseXX<=(cx2+sqWid/2) && mouseYY >=(cy2-sqHight/2) && mouseYY <=(cy2+sqHight/2))
{
status=2;
}
if( mouseXX>=(cx3-sqWid/2) && mouseXX<=(cx3+sqWid/2) && mouseYY >=(cy3-sqHight/2) && mouseYY <=(cy3+sqHight/2))
{
status=3;
}

}}
void specialKeyboard(int key, int x, int y)
{
    if(key==GLUT_KEY_F2){
        restartgame();
        status=0;
}
    if(key==GLUT_KEY_F1){
        if(status==1||status==4){
            restartgame();
        }
    else{
        status=0;
        }
    }
}


void Timer(int value) {

    glutTimerFunc(10, Timer, value);
    glutPostRedisplay();

}
    void Keyboard(unsigned char key, int x, int y) {
        if(key==' ')
        arrowdelta+=10;
    }

int main( int argc, char ** argv)
{
glutInit( &argc, argv);
glutInitDisplayMode( GLUT_DOUBLE |GLUT_RGB);
glutInitWindowPosition( 100, 100);
glutInitWindowSize(phyWidth, phyHeight);
glutCreateWindow( "Flappy Arrow");
init();
glutDisplayFunc( myDisplay);
glutSpecialFunc(specialKeyboard);
glutKeyboardFunc(Keyboard);
Timer(0);
glutPassiveMotionFunc(passiveMouse);
glutMouseFunc(mouseClick);
glutMainLoop();

}
