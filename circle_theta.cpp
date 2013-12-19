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
   float y=0; float r=0.5; float x=r; double theta=0;
   double theta1 = 1/r;
   float c=cos(theta1);
   float s=sin(theta1);
   render (x,y);
 do
 {
  theta = theta+theta1;
  float xtemp=x;
  x=x*c-y*s;
  y=y*c+xtemp*s;
  render(x,y);
  render(x,-y);
  render(-x,y);
  render(-x,-y);
  render(y,x);
  render(-y,x);
  render(y,-x);
  render(-y,-x);
} while(theta<=170);
    
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

