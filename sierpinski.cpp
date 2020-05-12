#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>

struct GLintPoint {
  GLfloat x, y;
};

//color 1 = white; 0 = black

void myInit(void)
{
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);//background color 
  glColor3f(1.0,1.0,1.0);//color of subject
  glPointSize(5.0);//diameter of point
  glMatrixMode(GL_PROJECTION);//matrix projection
  glLoadIdentity();
  gluOrtho2D(0.0, 640.0, 0.0, 640.0); //dimmension of space; left right bottom top
}

void drawDot (GLint x, GLint y)
{
 //glClear(GL_COLOR_BUFFER_BIT);//clear subject from background
  glBegin(GL_POINTS);
  glVertex2i(x, y);
 glEnd();//end function
 glFlush();//clear
 }

void Sierpinski(void) 
{
	glClear(GL_COLOR_BUFFER_BIT);
	GLintPoint T[3]= {{10,10},{600,10},{300, 600}};

	int index = rand() % 3;         // 0, 1, or 2 equally likely 
	GLintPoint point = T[index]; 	 // initial point 
	drawDot(point.x, point.y);     // draw initial point
	for(int i = 0; i < 1000; i++)  // draw 1000 dots
	{
		float a = rand() % 100;
		a = a/100;
		float b=rand() % 100;
		b = b/100;
		float c =rand() % 100;
		c = c/100;
		
		glColor3f(a, b, c);
	     index = rand() % 3; 	
		 point.x = (point.x + T[index].x) / 2;
		 point.y = (point.y + T[index].y) / 2;
		 drawDot(point.x,point.y);
	} 
	glFlush(); 	
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);//initial display mode
  glutInitWindowSize(640, 640); //window pixel size row, column
  glutInitWindowPosition(100, 150);
  glutCreateWindow("Sierpinky");
  glutDisplayFunc(Sierpinski);
  myInit();
  glutMainLoop();
  return 0;
}
    