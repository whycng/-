// 
//#include <GL/glut.h>
//#include <math.h>
//#include <cstdio>
//const GLfloat Pi = 3.141592f;  //����Piֵ
//
//GLfloat X[5], Y[5], SX[5], SY[5];  //����������5������
//int R = 1;  //����뾶
//float r = 0.3;
//float X0 = 0;
//float Y0 = 0;
//
//void init() //��ʼ������
//{
//	glClearColor(1.0, 1.0, 1.0, 0.0);  //���ñ�����ɫ
//	for (int i = 0; i <= 4; i++)
//	{
//		//��Բ�ϳ�ʼ��5�������
//		X[i] = R * cos((2 * Pi * i / 5));
//		Y[i] = R * sin((2 * Pi * i / 5));
//		SX[i] = r * cos((2 * Pi * i / 5) + (Pi / 5));
//		SY[i] = r * sin((2 * Pi * i / 5) + (Pi / 5));
//	}
//}
//
//void myDisplay(void)  //��ʾ����
//{
//	int flag = 3;     //flag=1 �ߣ�flag=2 ��ɫ�� flag=3 ˫ɫ��
//	glClear(GL_COLOR_BUFFER_BIT);  //�����ɫ
//	if (flag == 1)   //flag=1 �ߣ�
//	{
//		glColor3f(1.0, 0.0, 0.0);  //����������ɫ
//		glBegin(GL_LINE_LOOP); //����˳��ʼ���ߣ�AC->CE->EB->BD->DA
//		for (int i = 0; i <= 4; i++)
//		{
//			glVertex2f(X[i], Y[i]);
//			glVertex2f(X0, Y0);
//			glVertex2f(SX[i], SY[i]);
//		}
//		for (int i = 0; i <= 4; i++)
//		{
//			glVertex2f(X0, Y0);
//			glVertex2f(X[i], Y[i]);
//			glVertex2f(SX[i], SY[i]);
//		}
//	}
//	else
//	{
//		glColor3f(1, 0, 0);
//		glBegin(GL_TRIANGLES);
//		for (int i = 0; i <= 4; i++)
//		{
//			glVertex2f(X[i], Y[i]);
//			glVertex2f(X0, Y0);
//			glVertex2f(SX[i], SY[i]);
//		}
//		if (flag == 2)          glColor3f(1, 0, 0);   //flag = 2 ��ɫ��
//		else if (flag == 3)  glColor3f(0, 0, 1);   //flag = 3 ˫ɫ��
//		glBegin(GL_TRIANGLES);
//
//		for (int i = 0; i <= 4; i++)
//		{
//			if (i <= 3)
//			{
//				glVertex2f(X0, Y0);
//				glVertex2f(X[i + 1], Y[i + 1]);
//				glVertex2f(SX[i], SY[i]);
//			}
//			else
//			{
//				glVertex2f(X0, Y0);
//				glVertex2f(X[0], Y[0]);
//				glVertex2f(SX[i], SY[i]);
//			}
//		}
//	}
//	glEnd();
//	glFlush();  //��֤ǰ�����������ִ��
//}
//
//int main(int argc, char* argv[])
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
//	glutInitWindowPosition(100, 100);  //������ʾλ��
//	glutInitWindowSize(400, 400);   //���ô��ڴ�С
//	glutCreateWindow("�����ͼ��");  //���ô��ڱ���
//	init();                          //���г�ʼ������
//	glutDisplayFunc(&myDisplay);     //������ʾ����
//	glutMainLoop();
//	return 0;
//}
//
//
//
