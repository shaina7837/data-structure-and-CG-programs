#include <iostream>
#include <GL/glut.h>
using namespace std;

unsigned char get_col[50][50][3];
void init(void)
{
  glClearColor(1.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glOrtho(0.0,100.0,0.0,100.0,0.0,100.0);
}
void readbuffervalue(GLint start, GLint end)
{
  for(int i=start; i<=end; i++){
    for(int j=start; j<=end; j++){
	glReadPixels(i, j, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, get_col[i][j]);
}}}
bool checkcolor(GLint x, GLint y)
{
  int r = get_col[x][y][0];
  int g = get_col[x][y][1];
  int b = get_col[x][y][2];
  if((r!=255)&&(g==255)&&(b!=255))
  return true;
  else
  return false;
}
void putpoint(int x, int y)
{
  get_col[x][y][0] = 0;
  get_col[x][y][1] = 0;
  get_col[x][y][2] = 255;
  glColor3f(0.0,0.0,1.0);
  glPointSize(2);
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
//  glFlush();
}
void filling(int x, int y)
{
 bool value = checkcolor(x,y);
 if(value == true)
  {putpoint(x,y);
 
  filling(x+1,y);
  filling(x-1,y);
  filling(x,y+1);
  filling(x,y-1);
}}
void displayfunc()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0,1.0,0.0);
  glRecti(0,0,50,50);
  glFlush();
  readbuffervalue(0,49);
  filling(40,40);
  glFlush();
}

 
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(300,300);
  glutInitWindowPosition(100,100);
  glutCreateWindow("color-filling");
  init();
  glutDisplayFunc(displayfunc);
 glutMainLoop();
 return 0;
} 
