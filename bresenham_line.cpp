#include "GL/glut.h"
void render(float x, float y)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glPointSize(2.0f);
    glBegin(GL_POINTS);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glVertex2f(x,y);    
	
}
void line()
{
    int steps;
    float x1=0, y1=0, x2=0.5, y2=0.7;
    float dx = x2-x1;
    float dy = y2-y1;
    float p=2*dy-dx;

   float x=x1, y=y1;
   render(x,y);
   while(x<x2)
   {
	if(p<0)
	p=p+2*dy;
	else
	{p=p+2*(dy-dx);
	y=y+0.003;}
    x=x+0.003;
    render(x,y);
   }
   glEnd();
   glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(300,300);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL - Sec window demo");
    glutDisplayFunc(line);
    glutMainLoop();    
    return 0;
}

