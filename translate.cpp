#include <GL/glut.h>
void pixel(float x, float y)
{
    glClearColor(1.0, 1.0, 1.0, 1.0); //defining for background color
    glClear(GL_COLOR_BUFFER_BIT); //assigning the defined color to background
    glColor3f(0.0, 0.0, 0.0); // color of the object to be displayed
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);//representing the real world dimensions in 2D screen and defining the coordinate limits
    glBegin(GL_POLYGON); //start drawing polygon
        glVertex2f(x,y); //defining the vertex of polygon
	glVertex2f(x+0.2,y);
	glVertex2f(x+0.2,y+0.2);    
	
}
void translate(float *x, float *y, float tx, float ty); 
void show()
{
float a = 0, b = 0;
//pixel(a,b);
translate(&a,&b,0.6,0.6); //calling translation function
pixel(a,b); //calling function to draw one pixel
glEnd(); //ending the drawing
glFlush(); // for execution
}
void translate(float *x, float *y, float tx, float ty)
{
    *x = *x + tx;
    *y = *y + ty;
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);//initiate library functions
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(300,300);//defining display window size
    glutInitWindowPosition(100,100);//defining display window position on the screen
    glutCreateWindow("OpenGL - Sec window demo");//defining the title of display window
    glutDisplayFunc(show);//calling the object drawing function
    glutMainLoop();    //put the program in infinite loop
    return 0;
}

