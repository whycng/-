#include<gl/glut.h>
#include <windows.h>
#include <iostream>
#include<cmath>

static GLfloat spin = 0.0;				//��ת��
static GLfloat move = -30.0,move2=-30;				//ƽ����
static GLfloat size = 1.0;				//������

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);		//ָ�������ɫ����ɫ������������ɫ
	glShadeModel(GL_FLAT);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);		//������е�����
	glPushMatrix();
	glTranslatef(move, move2, 0);				//�ƶ�����������(x��λ��,y��λ��,z��λ��)
	glRotatef(spin, 0, 0, 1);				//��ת����������(��ת��,x��,y��,z��)
	glScalef(size, size, 1);				//���ţ���������(x�ᱶ��,y�ᱶ��,z�ᱶ��)
	glColor3f(0.0, 1.0, 0.0);				//������ɫRGB
	//glRectf(-25.0, -25.0, 25.0, 25.0);		//���ƾ���
	//����
	//glBegin(GL_LINES);//ʮ�ּ�
	//glColor3f(10, 0, 0);
	//glVertex3f(-10, 0, 0);
	//glVertex3f(0, 10, 0);
	//glVertex3f(0, -10, 0);
	//glEnd();
	//�����
	glBegin(GL_LINE_LOOP);
		double x, y, zx, zy, pi = 3.1416, m = pi / 2 - 2 * pi / 5, n, r1, p, r;
		p = pi / 2 - pi / 5;
		//n = 2 * m;
		r1 = 1 * sin(m);
		r = r1 / sin(p);
	
		int i, j;
	
		for (i = 0; i < 5; i++) {
			zx = r * cos(p);
			zy = r * sin(p);
			x = 1 * cos(m);
			y = 1 * sin(m);
			glVertex2f(x, y);
			glVertex2f(zx, zy);
			m += 2 * pi / 5;
			p += 2 * pi / 5;
	
		}
		glEnd();

	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
}
int k = 1;
void spinAndSizeDisplay()
{
	//spin > 360 ? spin -= 360 : spin += 2;
	//size > 50 ? size -= 20 : size += 0.3;
	move = 0;
	move2 = 0;
	if (size > 50)k = 0;
	if (size < 1)k = 1;
	if (k) {
		size += 0.3;
	}
	else {
		size -= 0.3;
	}

	glutPostRedisplay();				//��ǵ�ǰ������Ҫ�ػ棬���򲻻���ת
	Sleep(10);
}
int kk = 1;
void moveDisplay()
{
	spin > 360 ? spin -= 360 : spin += 2;
	size = 20;
	if (kk == 1) {
		move += 1;
		if (move == 30 && move2 == -30)kk = 2;
	}
	if (kk == 2) {
		move2 += 1;
		if (move == 30 && move2 == 30)kk = 3;
	}
	if (kk == 3) {
		move -= 1;
		if (move == -30 && move2 == 30)kk = 4;
	}
	if (kk == 4) {
		move2 -= 1;
		if (move == -30 && move2 == -30)kk = 1;
	}
	//move = move > 20 ? move -= 20 : move += 1;
	glutPostRedisplay();				//��ǵ�ǰ������Ҫ�ػ棬���򲻻���ת
	Sleep(10);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);							//��ʼ��GLUT�����������в���
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);		//ָ��ģʽ��˫���棻RGBģʽ
	glutInitWindowSize(250, 250);					//ָ�����ڴ�С�����أ�
	glutInitWindowPosition(300, 200);				//ָ���������Ͻ�����Ļ�ϵ�λ��
	glutCreateWindow(argv[0]);						//ʹ��OpenGL��������һ�����ڣ�����Ϊ��������
	init();											//���ó�ʼ������
	glutDisplayFunc(display);						//��ʾ
	glutReshapeFunc(reshape);						//�ػ�
	glutIdleFunc(spinAndSizeDisplay);				//��ת&����
	//glutIdleFunc(moveDisplay);						//�ƶ�(���ϱߺ���ֻ����һ����Ч)
	glutMainLoop();									//������ѭ���������¼�����ʱ���������д��ڶ�����ʾ����������Ⱦ����Щ�����е�����Ҳ����ʾ����������ʼ�����¼���ע�����ʾ�ص�����������
	return 0;										//ANSI CҪ����main()����һ��intֵ
}