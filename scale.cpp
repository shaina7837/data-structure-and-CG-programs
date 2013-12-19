#include <GL/glut.h>
#include <Glui2.h>
void scale(float *x, float *y, float sx, float sy); 
void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0); //defining for background color
    
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);//representing the real world dimensions in 2D screen and defining the coordinate limits
}
void pixel1(float x, float y)
{
    glClear(GL_COLOR_BUFFER_BIT); //assigning the defined color to background
    glColor3f(0.0, 0.0, 0.0); // color of the object to be displayed
        glBegin(GL_POLYGON); //start drawing polygon
        glVertex2f(x,y); //defining the vertex of polygon
	glVertex2f(x+0.2,y);
	glVertex2f(x+0.2,y+0.2);
}
void pixel2(float x, float y)
{
    glClear(GL_COLOR_BUFFER_BIT); //assigning the defined color to background
    glColor3f(0.0, 0.0, 0.0); // color of the object to be displayed
	glBegin(GL_POLYGON);
	glVertex2f(x,y);
	scale(&x, &y, 2, 2);
	glVertex2f(x+0.2,y);    
	glVertex2f(x+0.2,y+0.2);
	
}

void show()
{
float a = 0.1, b = 0.1;
pixel1(a,b);
g2Button *button = GluiHandle->AddButton();
button->SetPos(-0.5,-0.5);
button->Width(0.5);
button->SetText("Scale");
glEnd(); //ending the drawing
glFlush(); // for execution
}
void scale(float *x, float *y, float sx, float sy)
{
    *x = (*x) * (sx);
    *y = (*y) * (sy);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);//initiate library functions
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);//defining display window size
    glutInitWindowPosition(100,100);//defining display window position on the screen
    glutCreateWindow("OpenGL - Sec window demo");//defining the title of display window
    glutDisplayFunc(show);//calling the object drawing function
    glutMainLoop();    //put the program in infinite loop
    return 0;
}

