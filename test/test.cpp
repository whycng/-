//#include <stdio.h>
//#include <Windows.h>
//#include <gl/glut.h>
//
///*
// ����������ʹ��OpenGL�򵥻�һ������ˮ��
// ���ű任����glScalef
// */
//
// //���ģʽ��0-������ģʽ����0˫����ģʽ
//#define OUTPUT_MODE 1
//
//float scale = 0.0;
//bool add = true;
//
//unsigned char axle = 'x';
//
//void init(void)
//{
//	//glClearColor�������ú������ɫ��glClear����glClearColor�������úõĵ�ǰ�����ɫ���ô�����ɫ
//	glClearColor(1.0, 1.0, 0.8, 1.0);
//}
//
//void display(void)
//{
//	printf("scale=%f, axle=%c\n", scale, axle);
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	//�������ű�����Сscale
//	scale = (add ? scale + 0.1 : scale - 0.1);
//	if (scale >= 2.0)
//	{
//		add = false;
//	}
//	else if (scale <= 0.0) {
//		add = true;
//	}
//	//��ʼ�滭
//	glPushMatrix();
//	{
//		if (axle == 'x') {
//			glScalef(scale, 1, 1);
//		}
//		else if (axle == 'y') {
//			glScalef(1, scale, 1);
//		}
//		else if (axle == 'z') {
//			glScalef(1, 1, scale);
//		}
//		else {
//			glScalef(scale, scale, scale);
//		}
//		glColor3f(1.0, 0.0, 1.0); //����÷��ɫ
//		glBegin(GL_POLYGON);
//		glVertex2f(-0.2, -0.2);
//		glVertex2f(-0.2, 0.2);
//		glVertex2f(0.2, 0.2);
//		glVertex2f(0.2, -0.2);
//		glEnd();
//	}
//	glPopMatrix();
//
//	glLoadIdentity();  //���ص�λ����
//	glColor3f(0.0, 0.0, 1.0); //������ɫ
//	//--------��ֱ��START--------
//	//��ֱ��
//	glBegin(GL_LINES);
//	glVertex2f(-0.5, 0);
//	glVertex2f(0.5, 0);
//	glVertex2f(0, 0.5);
//	glVertex2f(0, -0.5);
//	glEnd();
//	//--------��ֱ��E N D--------
//
//	if (OUTPUT_MODE == 0) {
//		glFlush();//������GLUT_SINGLEʱʹ��
//	}
//	else {
//		glutSwapBuffers();//��Ϊʹ�õ���˫����GLUT_DOUBLE�������������Ҫ��������Ż���ʾ
//	}
//
//	Sleep(50);
//}
//
//void reshape(int w, int h)
//{
//	int offset = 50;
//	int dis = (w > h ? h : w) - offset * 2;
//
//	//������ʾ������Ļ�Ĵ�С
//	glViewport(offset, offset, (GLsizei)dis, (GLsizei)dis);
//	printf("reshape: w=%d, h=%d, dis=%d\n", w, h, dis);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//
//	glOrtho(-1.5, 1.5, -1.5, 1.5, 0, 10);
//	//gluOrtho2D(-1.5, 1.5, -1.5, 1.5);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//void keyboard(unsigned char key, int x, int y)
//{
//	switch (key) {
//	case 'x':
//	case 'X':
//		axle = 'x';
//		glutPostRedisplay();
//		break;
//	case 'y':
//	case 'Y':
//		axle = 'y';
//		glutPostRedisplay();
//		break;
//	case 'z':
//	case 'Z':
//		axle = 'z';
//		glutPostRedisplay();
//		break;
//	case 'a':
//	case 'A':
//		axle = 'a';
//		glutPostRedisplay();
//		break;
//	default:
//		break;
//	}
//	printf("����%c\n", key);
//}
//
//int main(int argc, char *argv[])
//{
//	printf("��ͨ������xyza����ͼ�ΰ���һ������\n");
//	glutInit(&argc, argv);
//
//	glutInitDisplayMode(GLUT_RGB | (OUTPUT_MODE == 0 ? GLUT_SINGLE : GLUT_DOUBLE));
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(400, 400);
//	glutCreateWindow("��һ�� OpenGL ����");
//
//	init();
//	glutDisplayFunc(&display);
//	glutIdleFunc(display);  //���ò��ϵ�����ʾ����
//	glutReshapeFunc(reshape);
//	glutKeyboardFunc(keyboard);
//	glutMainLoop();
//	return 0;
//}


















//#include<GL/glut.h>
//#include <windows.h>
// 
//static GLfloat spin=0.0;				//��ת��
//static GLfloat move=0.0;				//ƽ����
//static GLfloat size=1.0;				//������
// 
//void init(void)
//{
//	glClearColor(0.0,0.0,0.0,0.0);		//ָ�������ɫ����ɫ������������ɫ
//	glShadeModel(GL_FLAT);
//}
// 
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);		//������е�����
//	glPushMatrix();
//	glTranslatef(move,0,0);				//�ƶ�����������(x��λ��,y��λ��,z��λ��)
//	glRotatef(spin,0,0,1);				//��ת����������(��ת��,x��,y��,z��)
//	glScalef(size,size,1);				//���ţ���������(x�ᱶ��,y�ᱶ��,z�ᱶ��)
//	glColor3f(0.0,1.0,0.0);				//������ɫRGB
//	glRectf(-25.0,-25.0,25.0,25.0);		//���ƾ���
//	glPopMatrix();
//	glutSwapBuffers();
//}
// 
//void reshape(int w,int h)
//{
//	glViewport(0,0,w,h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-50.0,50.0,-50.0,50.0,-1.0,1.0);
//}
// 
//void spinAndSizeDisplay()
//{
//	spin>360?spin-=360:spin+=2;
//	size>2?size-=2:size+=0.003;
//	glutPostRedisplay();				//��ǵ�ǰ������Ҫ�ػ棬���򲻻���ת
//	Sleep(10);
//}
// 
//void moveDisplay()
//{
//	move=move>20?move-=20:move+=1;
//	glutPostRedisplay();				//��ǵ�ǰ������Ҫ�ػ棬���򲻻���ת
//	Sleep(10);
//}
// 
//int main(int argc,char* argv[])
//{
//	glutInit(&argc,argv);							//��ʼ��GLUT�����������в���
//	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);		//ָ��ģʽ��˫���棻RGBģʽ
//	glutInitWindowSize(250,250);					//ָ�����ڴ�С�����أ�
//	glutInitWindowPosition(300,200);				//ָ���������Ͻ�����Ļ�ϵ�λ��
//	glutCreateWindow(argv[0]);						//ʹ��OpenGL��������һ�����ڣ�����Ϊ��������
//	init();											//���ó�ʼ������
//	glutDisplayFunc(display);						//��ʾ
//	glutReshapeFunc(reshape);						//�ػ�
//	glutIdleFunc(spinAndSizeDisplay);				//��ת&����
//	//glutIdleFunc(moveDisplay);						//�ƶ�(���ϱߺ���ֻ����һ����Ч)
//	glutMainLoop();									//������ѭ���������¼�����ʱ���������д��ڶ�����ʾ����������Ⱦ����Щ�����е�����Ҳ����ʾ����������ʼ�����¼���ע�����ʾ�ص�����������
//	return 0;										//ANSI CҪ����main()����һ��intֵ
//}


//#include <stdio.h>
//#include <Windows.h>
//#include <gl/glut.h>
//
///*
// ����������ʹ��OpenGL�򵥻�һ������ˮ��
// ���ű任����glScalef
// */
//
// //���ģʽ��0-������ģʽ����0˫����ģʽ
//#define OUTPUT_MODE 1
//
//float scale = 0.0;
//bool add = true;
//
//unsigned char axle = 'x';
//
//void init(void)
//{
//	//glClearColor�������ú������ɫ��glClear����glClearColor�������úõĵ�ǰ�����ɫ���ô�����ɫ
//	glClearColor(1.0, 1.0, 0.8, 1.0);
//}
//
//void display(void)
//{
//	printf("scale=%f, axle=%c\n", scale, axle);
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	//�������ű�����Сscale
//	scale = (add ? scale + 0.1 : scale - 0.1);
//	if (scale >= 2.0)
//	{
//		add = false;
//	}
//	else if (scale <= 0.0) {
//		add = true;
//	}
//	//��ʼ�滭
//	glPushMatrix();
//	{
//		if (axle == 'x') {
//			glScalef(scale, 1, 1);
//		}
//		else if (axle == 'y') {
//			glScalef(1, scale, 1);
//		}
//		else if (axle == 'z') {
//			glScalef(1, 1, scale);
//		}
//		else {
//			glScalef(scale, scale, scale);
//		}
//		glColor3f(1.0, 0.0, 1.0); //����÷��ɫ
//		glBegin(GL_POLYGON);
//		glVertex2f(-0.2, -0.2);
//		glVertex2f(-0.2, 0.2);
//		glVertex2f(0.2, 0.2);
//		glVertex2f(0.2, -0.2);
//		glEnd();
//	}
//	glPopMatrix();
//
//	glLoadIdentity();  //���ص�λ����
//	glColor3f(0.0, 0.0, 1.0); //������ɫ
//	//--------��ֱ��START--------
//	//��ֱ��
//	glBegin(GL_LINES);
//	glVertex2f(-0.5, 0);
//	glVertex2f(0.5, 0);
//	glVertex2f(0, 0.5);
//	glVertex2f(0, -0.5);
//	glEnd();
//	//--------��ֱ��E N D--------
//
//	if (OUTPUT_MODE == 0) {
//		glFlush();//������GLUT_SINGLEʱʹ��
//	}
//	else {
//		glutSwapBuffers();//��Ϊʹ�õ���˫����GLUT_DOUBLE�������������Ҫ��������Ż���ʾ
//	}
//
//	Sleep(50);
//}
//
//void reshape(int w, int h)
//{
//	int offset = 50;
//	int dis = (w > h ? h : w) - offset * 2;
//
//	//������ʾ������Ļ�Ĵ�С
//	glViewport(offset, offset, (GLsizei)dis, (GLsizei)dis);
//	printf("reshape: w=%d, h=%d, dis=%d\n", w, h, dis);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//
//	glOrtho(-1.5, 1.5, -1.5, 1.5, 0, 10);
//	//gluOrtho2D(-1.5, 1.5, -1.5, 1.5);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//void keyboard(unsigned char key, int x, int y)
//{
//	switch (key) {
//	case 'x':
//	case 'X':
//		axle = 'x';
//		glutPostRedisplay();
//		break;
//	case 'y':
//	case 'Y':
//		axle = 'y';
//		glutPostRedisplay();
//		break;
//	case 'z':
//	case 'Z':
//		axle = 'z';
//		glutPostRedisplay();
//		break;
//	case 'a':
//	case 'A':
//		axle = 'a';
//		glutPostRedisplay();
//		break;
//	default:
//		break;
//	}
//	printf("����%c\n", key);
//}
//
//int main(int argc, char *argv[])
//{
//	printf("��ͨ������xyza����ͼ�ΰ���һ������\n");
//	glutInit(&argc, argv);
//
//	glutInitDisplayMode(GLUT_RGB | (OUTPUT_MODE == 0 ? GLUT_SINGLE : GLUT_DOUBLE));
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(400, 400);
//	glutCreateWindow("��һ�� OpenGL ����");
//
//	init();
//	glutDisplayFunc(&display);
//	glutIdleFunc(display);  //���ò��ϵ�����ʾ����
//	glutReshapeFunc(reshape);
//	glutKeyboardFunc(keyboard);
//	glutMainLoop();
//	return 0;
//}


















//#include<GL/glut.h>
//#include <windows.h>
//#include <cmath> 
//static GLfloat spin=0.0;				//��ת��
//static GLfloat move=0.0;				//ƽ����
//static GLfloat size=1.0;				//������
// 
//void init(void)
//{
//	glClearColor(0.0,0.0,0.0,0.0);		//ָ�������ɫ����ɫ������������ɫ
//	glShadeModel(GL_FLAT);
//}
// 
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);		//������е�����
//	glPushMatrix();
//	glTranslatef(move,0,0);				//�ƶ�����������(x��λ��,y��λ��,z��λ��)
//	glRotatef(spin,0,0,1);				//��ת����������(��ת��,x��,y��,z��)
//	glScalef(size,size,1);				//���ţ���������(x�ᱶ��,y�ᱶ��,z�ᱶ��)
//
//
//	// ���ƿɼ�����
//	float len = 400,a,R,G,B,xx1 = -45,xx2 = -30,yy1 = -44.7,yy2 = 30;
//	int i;
//	for ( ; len <= 700 ; len += 0.1 ) {
//		if (len >= 380 && len <= 440) {
//			a = 0.3 + 0.7 * (len - 380) / (440 - 380);
//			R = ((-(len - 440) / (440 - 380)) * a);
//			R = pow(R, 0.8);
//			G = 0.0;
//			B = (1.0 * a);
//			B = pow(B, 0.8);
//		}
//		else if (len >= 440 && len <= 490) {
//			R = 0.0;
//			G = ((len - 440) / (490 - 440));
//			G = pow(G, 0.8);
//			B = 1.0;
//		}
//		else if (len >= 490 && len <= 510) {
//			R = 0.0;
//			G = 1.0;
//			B = (-(len - 510) / (510 - 490));
//			B = pow(B, 0.8);
//		}
//		else if (len >= 510 && len <= 580) {
//			R = ((len - 510) / (580 - 510));
//			R = pow(R, 0.8);
//			G = 1.0;
//			B = 0.0;
//		}
//		else if (len >= 580 && len <= 645) {
//			R = 1.0;
//			G = (-(len - 645) / (645 - 580));
//			G = pow(G, 0.8);
//			B = 0.0;
//		}
//		else if (len >= 645 && len <= 750) {
//			a = 0.3 + 0.7 * (750 - len) / (750 - 645);
//			R = 1 * a;
//			R = pow(R, 0.8);
//			G = 0.0;
//			B = 0.0;
//		}
//		else {
//			R = 0;
//			B = 0;
//			G = 0;
//		}
//		/*R *= 255;
//		B *= 255;
//		G *= 255;*/
//
//		glColor3f(R, G, B);
//		glRectf(xx1,xx2,yy1,yy2);
//
//		yy1 += 0.03;
//		xx1 += 0.03;
//
//		 
//	}
//
//	//glColor3f(0.0,1.0,0.0);				//������ɫRGB
//	//glRectf(-25.0,-25.0,25.0,25.0);		//���ƾ���
//	//glColor3f(1.0, 0, 0.0);				//������ɫRGB
//	//glRectf(25.0,-25.0,50.0,25.0);
//
//	glPopMatrix();
//	glutSwapBuffers();
//}
// 
//void reshape(int w,int h)
//{
//	glViewport(0,0,w,h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-50.0,50.0,-50.0,50.0,-1.0,1.0);
//}
// 
//void spinAndSizeDisplay()
//{
//	spin>360?spin-=360:spin+=2;
//	size>2?size-=2:size+=0.003;
//	glutPostRedisplay();				//��ǵ�ǰ������Ҫ�ػ棬���򲻻���ת
//	Sleep(10);
//}
// 
//void moveDisplay()
//{
//	move=move>20?move-=20:move+=1;
//	glutPostRedisplay();				//��ǵ�ǰ������Ҫ�ػ棬���򲻻���ת
//	Sleep(10);
//}
// 
//int main(int argc,char* argv[])
//{
//	glutInit(&argc,argv);							//��ʼ��GLUT�����������в���
//	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);		//ָ��ģʽ��˫���棻RGBģʽ
//	glutInitWindowSize(250,250);					//ָ�����ڴ�С�����أ�
//	glutInitWindowPosition(300,200);				//ָ���������Ͻ�����Ļ�ϵ�λ��
//	glutCreateWindow(argv[0]);						//ʹ��OpenGL��������һ�����ڣ�����Ϊ��������
//	init();											//���ó�ʼ������
//	glutDisplayFunc(display);						//��ʾ
//	glutReshapeFunc(reshape);						//�ػ�
//	//glutIdleFunc(spinAndSizeDisplay);				//��ת&����
//	//glutIdleFunc(moveDisplay);						//�ƶ�(���ϱߺ���ֻ����һ����Ч)
//	glutMainLoop();									//������ѭ���������¼�����ʱ���������д��ڶ�����ʾ����������Ⱦ����Щ�����е�����Ҳ����ʾ����������ʼ�����¼���ע�����ʾ�ص�����������
//	return 0;										//ANSI CҪ����main()����һ��intֵ
//}


