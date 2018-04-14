#include <GL/glut.h>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>  
GLuint TextFont;
#define MAX_CHAR       128
static int joint = 0;

void XPrintString(char *s)
{
	glPushAttrib(GL_LIST_BIT);

	//调用每个字符对应的显示列表，绘制每个字符
	for (; *s != '\0'; ++s)
		glCallList(TextFont + *s);

	glPopAttrib();
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

	//申请MAX_CHAR个连续的显示列表编号
	TextFont = glGenLists(MAX_CHAR);

	//把每个字符的绘制命令都装到对应的显示列表中
	wglUseFontBitmaps(wglGetCurrentDC(), 0, MAX_CHAR, TextFont);
}

void display(void)
{

	glClear(GL_COLOR_BUFFER_BIT);
	//glLoadIdentity();  
	glPushMatrix();//画手掌
	glTranslatef(-1.5, 0.0, 0.0);
	glScalef(2.0, 2.0, 0.4);
	glutWireCube(1.0);
	glPopMatrix();
	//先画大拇指
	glPushMatrix();//画大拇指第一节
	glTranslatef(-2.3, 1.0, 0.0);
	glRotatef((GLfloat)joint, -1.0, -1.0, 0.0);
	glPushMatrix();
	glTranslatef(0.0, 0.4, 0.0);
	glScalef(0.4, 0.8, 0.4);
	glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();//画大拇指第二节
	glTranslatef(0.0, 0.8, 0.0);
	glRotatef((GLfloat)joint, -1.0, -1.0, 0.0);
	glTranslatef(0.0, 0.3, 0.0);
	glPushMatrix();
	glScalef(0.4, 0.6, 0.4); 
	glutWireCube(1.0);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5, 0.0, 0.0);//绕着z=-1在转  
	glRotatef((GLfloat)joint, 0.0, 1.0, 0.0);
	glTranslatef(0.5, 0.0, 0.0);//坐标回到原点  
	//glTranslatef(-1.0, 0.0, 0.0);

	glPushMatrix();//讲这个原点坐标保存起来 
	glTranslatef(0.0, 0.28, 0);
	glScalef(1.0, 0.3, 0.3);//  
	glutWireCube(1.0);//画中指第一节
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.84, 0);//上移画食指第一节
	glScalef(1.0, 0.3, 0.3);//  
	glutWireCube(1.0);//
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -0.28, 0);//下移画无名指第一节
	glScalef(1.0, 0.3, 0.3);//  
	glutWireCube(1.0);//
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -0.84, 0);//下移画小拇指第一节
	glScalef(1.0, 0.3, 0.3);//  
	glutWireCube(1.0);//
	glPopMatrix();

	glPushMatrix();//画食指第二节
	glTranslatef(0.5, 0.84, 0.0);
	glRotatef((GLfloat)joint, 0.0, 1.0, 0.0);
	glTranslatef(0.4, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.8, 0.3, 0.3); 
	glutWireCube(1.0);
	glPopMatrix();

	glTranslatef(0.40, 0.0, 0.0);//画食指第三节
	glRotatef((GLfloat)joint, 0.0, 1.0, 0.0);
	glTranslatef(0.40, 0.0, 0.0);
	glScalef(0.8, 0.3, 0.3);
	glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();//中指第二节
	glTranslatef(0.5, 0.28, 0.0);
	glRotatef((GLfloat)joint, 0.0, 1.0, 0.0);
	glTranslatef(0.5, 0.0, 0.0);
	glPushMatrix();
	glScalef(1.0, 0.3, 0.3); 
	glutWireCube(1.0);
	glPopMatrix();

	glTranslatef(0.50, 0.0, 0.0);//中指第三节  
	glRotatef((GLfloat)joint, 0.0, 1.0, 0.0);
	glTranslatef(0.50, 0.0, 0.0);
	glScalef(1.0, 0.3, 0.3);
	glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();//无名指第一节
	glTranslatef(0.5, -0.28, 0.0);
	glRotatef((GLfloat)joint, 0.0, 1.0, 0.0);
	glTranslatef(0.45, 0.0, 0.0);
	glPushMatrix();
	//glScalef(1.0, 0.2, 0.2);
	glScalef(0.9, 0.3, 0.3);
	//glScalef (2.0, 0.4, 1.0);  
	glutWireCube(1.0);
	glPopMatrix();

	glTranslatef(0.45, 0.0, 0.0);//无名指第二节
	glRotatef((GLfloat)joint, 0.0, 1.0, 0.0);
	glTranslatef(0.45, 0.0, 0.0);
	glScalef(0.9, 0.3, 0.3);
	glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();//小拇指第一节
	glTranslatef(0.5, -0.84, 0.0);
	glRotatef((GLfloat)joint, 0.0, 1.0, 0.0);
	glTranslatef(0.3, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.6, 0.3, 0.3);
	glutWireCube(1.0);
	glPopMatrix();

	glTranslatef(0.3, 0.0, 0.0);//小拇指第二节
	glRotatef((GLfloat)joint, 0.0, 1.0, 0.0);
	glTranslatef(0.3, 0.0, 0.0);
	glScalef(0.6, 0.3, 0.3);
	glutWireCube(1.0);
	glPopMatrix();

	glPopMatrix();

	glRasterPos3f(2.0, 2.0, 0.0);
	
	XPrintString("keep entering 'e' to make a fist");
	glRasterPos3f(2.0, 1.8, 0.0);
	XPrintString("keep entering 'd' to flatten the fist");
	
	glFlush();
	glutSwapBuffers();

}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y)
{
	static int angle = 5;
	switch (key) {
	case 'd':  //摊平
		if(joint < 0){
		joint = (joint + angle);
		glutPostRedisplay();
		}
		break;
	case 'e':  //握拳
		if(joint >= -90){
			joint = (joint - angle) ;
			glutPostRedisplay();
		}
		break;
	default:
		break;
	}
}

int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1270, 635);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Robot Hand");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}