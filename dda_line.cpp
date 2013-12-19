#include <GL/glut.h>

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
    int steps;
    float x1=0, y1=0, x2=2, y2=3;
    float dx = x2-x1;
    float dy = y2-y1;
    float m=dy/dx;
    if(int(dx) > int(dy))
	steps = int(dx);
    else 
	steps = int(dy);
    float xinc = (dx/steps)*0.001;
    float yinc = (dy/steps)*0.001;

   float x=x1, y=y1;
   render(x,y);
   for(float k=0; k<=steps; k=k+0.01)
   {
	x=x+xinc;
	y=y+yinc;
	render(x,y);
   }
   glEnd();
   glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL - Sec window demo");
    glutDisplayFunc(line);
    glutMainLoop();    
    return 0;
}

