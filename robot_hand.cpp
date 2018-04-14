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

	//����ÿ���ַ���Ӧ����ʾ�б�����ÿ���ַ�
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

	//����MAX_CHAR����������ʾ�б���
	TextFont = glGenLists(MAX_CHAR);

	//��ÿ���ַ��Ļ������װ����Ӧ����ʾ�б���
	wglUseFontBitmaps(wglGetCurrentDC(), 0, MAX_CHAR, TextFont);
}

void display(void)
{

	glClear(GL_COLOR_BUFFER_BIT);
	//glLoadIdentity();  
	glPushMatrix();//������
	glTranslatef(-1.5, 0.0, 0.0);
	glScalef(2.0, 2.0, 0.4);
	glutWireCube(1.0);
	glPopMatrix();
	//�Ȼ���Ĵָ
	glPushMatrix();//����Ĵָ��һ��
	glTranslatef(-2.3, 1.0, 0.0);
	glRotatef((GLfloat)joint, -1.0, -1.0, 0.0);
	glPushMatrix();
	glTranslatef(0.0, 0.4, 0.0);
	glScalef(0.4, 0.8, 0.4);
	glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();//����Ĵָ�ڶ���
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
	glTranslatef(-0.5, 0.0, 0.0);//����z=-1��ת  
	glRotatef((GLfloat)joint, 0.0, 1.0, 0.0);
	glTranslatef(0.5, 0.0, 0.0);//����ص�ԭ��  
	//glTranslatef(-1.0, 0.0, 0.0);

	glPushMatrix();//�����ԭ�����걣������ 
	glTranslatef(0.0, 0.28, 0);
	glScalef(1.0, 0.3, 0.3);//  
	glutWireCube(1.0);//����ָ��һ��
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.84, 0);//���ƻ�ʳָ��һ��
	glScalef(1.0, 0.3, 0.3);//  
	glutWireCube(1.0);//
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -0.28, 0);//���ƻ�����ָ��һ��
	glScalef(1.0, 0.3, 0.3);//  
	glutWireCube(1.0);//
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -0.84, 0);//���ƻ�СĴָ��һ��
	glScalef(1.0, 0.3, 0.3);//  
	glutWireCube(1.0);//
	glPopMatrix();

	glPushMatrix();//��ʳָ�ڶ���
	glTranslatef(0.5, 0.84, 0.0);
	glRotatef((GLfloat)joint, 0.0, 1.0, 0.0);
	glTranslatef(0.4, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.8, 0.3, 0.3); 
	glutWireCube(1.0);
	glPopMatrix();

	glTranslatef(0.40, 0.0, 0.0);//��ʳָ������
	glRotatef((GLfloat)joint, 0.0, 1.0, 0.0);
	glTranslatef(0.40, 0.0, 0.0);
	glScalef(0.8, 0.3, 0.3);
	glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();//��ָ�ڶ���
	glTranslatef(0.5, 0.28, 0.0);
	glRotatef((GLfloat)joint, 0.0, 1.0, 0.0);
	glTranslatef(0.5, 0.0, 0.0);
	glPushMatrix();
	glScalef(1.0, 0.3, 0.3); 
	glutWireCube(1.0);
	glPopMatrix();

	glTranslatef(0.50, 0.0, 0.0);//��ָ������  
	glRotatef((GLfloat)joint, 0.0, 1.0, 0.0);
	glTranslatef(0.50, 0.0, 0.0);
	glScalef(1.0, 0.3, 0.3);
	glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();//����ָ��һ��
	glTranslatef(0.5, -0.28, 0.0);
	glRotatef((GLfloat)joint, 0.0, 1.0, 0.0);
	glTranslatef(0.45, 0.0, 0.0);
	glPushMatrix();
	//glScalef(1.0, 0.2, 0.2);
	glScalef(0.9, 0.3, 0.3);
	//glScalef (2.0, 0.4, 1.0);  
	glutWireCube(1.0);
	glPopMatrix();

	glTranslatef(0.45, 0.0, 0.0);//����ָ�ڶ���
	glRotatef((GLfloat)joint, 0.0, 1.0, 0.0);
	glTranslatef(0.45, 0.0, 0.0);
	glScalef(0.9, 0.3, 0.3);
	glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();//СĴָ��һ��
	glTranslatef(0.5, -0.84, 0.0);
	glRotatef((GLfloat)joint, 0.0, 1.0, 0.0);
	glTranslatef(0.3, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.6, 0.3, 0.3);
	glutWireCube(1.0);
	glPopMatrix();

	glTranslatef(0.3, 0.0, 0.0);//СĴָ�ڶ���
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
	case 'd':  //̯ƽ
		if(joint < 0){
		joint = (joint + angle);
		glutPostRedisplay();
		}
		break;
	case 'e':  //��ȭ
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