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
  glClearColor(1.0,1.0,1.0,0.0);//background color 
  glColor3f(0.0f, 0.0f, 0.0f);//color of subject
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
 
 printf("\nX: %d\nY: %d\n", x, y);
 }
 
 void drawLine (GLint x, GLint y, GLint a, GLint b)
{
	glBegin (GL_LINES);  //draws one line
		glVertex2d (x, y);    // between 2 vertices
		glVertex2d (a, b);
	glEnd ();
	glFlush();
 printf("\nX: %d\nY: %d", a, b);
 printf("\nX: %d\nY: %d\n", x, y);
 }
 
 /*
 void asdf(GLint v1, GLint v2, p1, p2)
 {
	 
	x = (point.x + T[index].x) / 2;
	y = (point.y + T[index].y) / 2;
	 
 }
 */
 
 void asdf(GLintPoint T[3], int level)
{
	//int index = rand() % 3; //randomly choose vector
	
	printf("\nLevel: %d\n", level);
	GLintPoint B1;
	B1.x = (T[0].x + T[1].x) / 2;//find halfway between other vectors
	B1.y = (T[0].y + T[1].y) / 2;//find halfway between other vectors
	GLintPoint C1;
	C1.x = (T[0].x + T[2].x) / 2;//find halfway between other vectors
	C1.y = (T[0].y + T[2].y) / 2;//find halfway between other vectors
	
	drawLine(B1.x, B1.y, T[0].x, T[0].y);
	drawLine(C1.x, C1.y, T[0].x, T[0].y);
	drawLine(C1.x, C1.y, B1.x, B1.y);
	
	GLintPoint Q[3] = {T[0], B1, C1};//put vector into array
	if(level >= 1)
	{
	asdf(Q, level - 1);
	}
	
	
	//**************************************************
	//printf("\n*****************************************************************\n");
	GLintPoint B2;
	B2.x = (T[1].x + T[0].x) / 2;//find halfway between other vectors
	B2.y = (T[1].y + T[0].y) / 2;//find halfway between other vectors
	GLintPoint C2;
	C2.x = (T[1].x + T[2].x) / 2;//find halfway between other vectors
	C2.y = (T[1].y + T[2].y) / 2;//find halfway between other vectors
	
	drawLine(B2.x, B2.y, T[1].x, T[1].y);
	drawLine(C2.x, C2.y, T[1].x, T[1].y);
	drawLine(C2.x, C2.y, B2.x, B2.y);
	
	GLintPoint Q1[3] = {T[1], B2, C2};//put vector into array
	if(level >= 1)
	{
	asdf(Q1, level-1);
	}
	//**************************************************
	
	GLintPoint B3;
	B3.x = (T[2].x + T[1].x) / 2;//find halfway between other vectors
	B3.y = (T[2].y + T[1].y) / 2;//find halfway between other vectors
	GLintPoint C3;
	C3.x = (T[2].x + T[0].x) / 2;//find halfway between other vectors
	C3.y = (T[2].y + T[0].y) / 2;//find halfway between other vectors
	
	drawLine(B3.x, B3.y, T[2].x, T[2].y);
	drawLine(C3.x, C3.y, T[2].x, T[2].y);
	drawLine(C3.x, C3.y, B3.x, B3.y);
	
	GLintPoint Q2[3] = {T[2], B3, C3};//put vector into array
	if(level >= 1)
	{
	asdf(Q2, level-1);
	}

}

void asdf2(GLintPoint T[3], int level)
{
	//int index = rand() % 3; //randomly choose vector
	
	//printf("\nLevel: %d\n", level);
	GLintPoint B1;
	B1.x = (T[0].x + T[1].x) / 2;//find halfway between other vectors
	B1.y = (T[0].y + T[1].y) / 2;//find halfway between other vectors
	GLintPoint C1;
	C1.x = (T[0].x + T[2].x) / 2;//find halfway between other vectors
	C1.y = (T[0].y + T[2].y) / 2;//find halfway between other vectors
	
	
	//glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(B1.x, B1.y, level);
        glVertex3f(T[0].x, T[0].y, level);
        glVertex3f(C1.x, C1.y, level);
    glEnd();
    glFlush();
	
	GLintPoint Q[3] = {T[0], B1, C1};//put points into array
	if(level >= 1)
	{
	asdf2(Q, level - 1);
	}
	
	
	//**************************************************
	//printf("\n*****************************************************************\n");
	
	GLintPoint B2;
	B2.x = (T[1].x + T[0].x) / 2;//find halfway between other vectors
	B2.y = (T[1].y + T[0].y) / 2;//find halfway between other vectors
	GLintPoint C2;
	C2.x = (T[1].x + T[2].x) / 2;//find halfway between other vectors
	C2.y = (T[1].y + T[2].y) / 2;//find halfway between other vectors
	
	
	//glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(B2.x, B2.y, level);
        glVertex3f(T[1].x, T[1].y, level);
        glVertex3f(C2.x, C2.y, level);
    glEnd();
    glFlush();
	
	GLintPoint Q1[3] = {T[1], B2, C2};//put points into array
	if(level >= 1)
	{
	asdf2(Q1, level - 1);
	}
	//**************************************************
	
	GLintPoint B3;
	B3.x = (T[2].x + T[1].x) / 2;//find halfway between other vectors
	B3.y = (T[2].y + T[1].y) / 2;//find halfway between other vectors
	GLintPoint C3;
	C3.x = (T[2].x + T[0].x) / 2;//find halfway between other vectors
	C3.y = (T[2].y + T[0].y) / 2;//find halfway between other vectors
	
	
	//glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(B3.x, B3.y, level);
        glVertex3f(T[2].x, T[2].y, level);
        glVertex3f(C3.x, C3.y, level);
    glEnd();
    glFlush();
	
	GLintPoint Q2[3] = {T[2], B3, C3};//put points into array
	if(level >= 1)
	{
	asdf2(Q2, level - 1);
	}

}

void Sierpinski(void) 
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glClear(GL_COLOR_BUFFER_BIT);
	GLintPoint T[3]= {{10,10},{600,10},{300, 600}};//array of points for triangle
	drawLine(T[0].x, T[0].y, T[2].x, T[2].y);
	drawLine(T[1].x, T[1].y, T[2].x, T[2].y);
	drawLine(T[0].x, T[0].y, T[1].x, T[1].y);
	asdf2(T, 6);
	
	glFlush(); 	

}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);//initial display mode
  glutInitWindowSize(640, 480); //window pixel size row, column
  glutInitWindowPosition(100, 150);
  glutCreateWindow("Sierpinky");
  glutDisplayFunc(Sierpinski);
  myInit();
  glutMainLoop();
  return 0;
}
    