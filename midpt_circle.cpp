#include <GL/glut.h>
#include <cmath>
void render(float x, float y)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glPointSize(2.0f);
    glBegin(GL_POINTS);
        glVertex2f(x,y);    
	
}
void line()
{
   float x=0; float r=0.5; float y=r; double p=5/4-r;
   render (r,0);
   render(-r,0);
render(0,r);
render(0,-r);
 do
 {
if(p<0)
p=p+2*x+3;
else
{p=p+2*(x-y)+4;
y=sqrt(r*r-x*x); }
x=x+0.01;
render(x,y);
render(x,-y);
render(-x,y);
render(-x,-y);
render(y,x);
render(-y,x);
render(y,-x);
render(-y,-x);
}while(x<=y);
    
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

