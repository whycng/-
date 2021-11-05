//#include <stdio.h>
//#include <Windows.h>
//#include <gl/glut.h>
//
///*
// 功能描述：使用OpenGL简单画一个虚心水壶
// 缩放变换函数glScalef
// */
//
// //输出模式，0-单缓存模式；非0双缓存模式
//#define OUTPUT_MODE 1
//
//float scale = 0.0;
//bool add = true;
//
//unsigned char axle = 'x';
//
//void init(void)
//{
//	//glClearColor函数设置好清除颜色，glClear利用glClearColor函数设置好的当前清除颜色设置窗口颜色
//	glClearColor(1.0, 1.0, 0.8, 1.0);
//}
//
//void display(void)
//{
//	printf("scale=%f, axle=%c\n", scale, axle);
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	//配置缩放比例大小scale
//	scale = (add ? scale + 0.1 : scale - 0.1);
//	if (scale >= 2.0)
//	{
//		add = false;
//	}
//	else if (scale <= 0.0) {
//		add = true;
//	}
//	//开始绘画
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
//		glColor3f(1.0, 0.0, 1.0); //画笔梅红色
//		glBegin(GL_POLYGON);
//		glVertex2f(-0.2, -0.2);
//		glVertex2f(-0.2, 0.2);
//		glVertex2f(0.2, 0.2);
//		glVertex2f(0.2, -0.2);
//		glEnd();
//	}
//	glPopMatrix();
//
//	glLoadIdentity();  //加载单位矩阵
//	glColor3f(0.0, 0.0, 1.0); //画笔蓝色
//	//--------画直线START--------
//	//画直线
//	glBegin(GL_LINES);
//	glVertex2f(-0.5, 0);
//	glVertex2f(0.5, 0);
//	glVertex2f(0, 0.5);
//	glVertex2f(0, -0.5);
//	glEnd();
//	//--------画直线E N D--------
//
//	if (OUTPUT_MODE == 0) {
//		glFlush();//单缓存GLUT_SINGLE时使用
//	}
//	else {
//		glutSwapBuffers();//因为使用的是双缓存GLUT_DOUBLE，所以这里必须要交换缓存才会显示
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
//	//配置显示物体屏幕的大小
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
//	printf("按键%c\n", key);
//}
//
//int main(int argc, char *argv[])
//{
//	printf("可通过按键xyza控制图形按哪一轴缩放\n");
//	glutInit(&argc, argv);
//
//	glutInitDisplayMode(GLUT_RGB | (OUTPUT_MODE == 0 ? GLUT_SINGLE : GLUT_DOUBLE));
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(400, 400);
//	glutCreateWindow("第一个 OpenGL 程序");
//
//	init();
//	glutDisplayFunc(&display);
//	glutIdleFunc(display);  //设置不断调用显示函数
//	glutReshapeFunc(reshape);
//	glutKeyboardFunc(keyboard);
//	glutMainLoop();
//	return 0;
//}


















//#include<GL/glut.h>
//#include <windows.h>
// 
//static GLfloat spin=0.0;				//旋转量
//static GLfloat move=0.0;				//平移量
//static GLfloat size=1.0;				//缩放量
// 
//void init(void)
//{
//	glClearColor(0.0,0.0,0.0,0.0);		//指定清除颜色（黑色），即背景颜色
//	glShadeModel(GL_FLAT);
//}
// 
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);		//清除所有的像素
//	glPushMatrix();
//	glTranslatef(move,0,0);				//移动，参数含义(x轴位移,y轴位移,z轴位移)
//	glRotatef(spin,0,0,1);				//旋转，参数含义(旋转量,x轴,y轴,z轴)
//	glScalef(size,size,1);				//缩放，参数含义(x轴倍数,y轴倍数,z轴倍数)
//	glColor3f(0.0,1.0,0.0);				//绘制颜色RGB
//	glRectf(-25.0,-25.0,25.0,25.0);		//绘制矩形
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
//	glutPostRedisplay();				//标记当前窗口需要重绘，否则不会旋转
//	Sleep(10);
//}
// 
//void moveDisplay()
//{
//	move=move>20?move-=20:move+=1;
//	glutPostRedisplay();				//标记当前窗口需要重绘，否则不会旋转
//	Sleep(10);
//}
// 
//int main(int argc,char* argv[])
//{
//	glutInit(&argc,argv);							//初始化GLUT并处理命令行参数
//	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);		//指定模式：双缓存；RGB模式
//	glutInitWindowSize(250,250);					//指定窗口大小（像素）
//	glutInitWindowPosition(300,200);				//指定窗口左上角在屏幕上的位置
//	glutCreateWindow(argv[0]);						//使用OpenGL场景创建一个窗口，参数为窗口名称
//	init();											//调用初始化函数
//	glutDisplayFunc(display);						//显示
//	glutReshapeFunc(reshape);						//重绘
//	glutIdleFunc(spinAndSizeDisplay);				//旋转&缩放
//	//glutIdleFunc(moveDisplay);						//移动(与上边函数只能有一个有效)
//	glutMainLoop();									//进入主循环并处理事件，此时创建的所有窗口都会显示出来，被渲染到这些窗口中的内容也将显示出来，程序开始处理事件，注册的显示回调函数被触发
//	return 0;										//ANSI C要求函数main()返回一个int值
//}


//#include <stdio.h>
//#include <Windows.h>
//#include <gl/glut.h>
//
///*
// 功能描述：使用OpenGL简单画一个虚心水壶
// 缩放变换函数glScalef
// */
//
// //输出模式，0-单缓存模式；非0双缓存模式
//#define OUTPUT_MODE 1
//
//float scale = 0.0;
//bool add = true;
//
//unsigned char axle = 'x';
//
//void init(void)
//{
//	//glClearColor函数设置好清除颜色，glClear利用glClearColor函数设置好的当前清除颜色设置窗口颜色
//	glClearColor(1.0, 1.0, 0.8, 1.0);
//}
//
//void display(void)
//{
//	printf("scale=%f, axle=%c\n", scale, axle);
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	//配置缩放比例大小scale
//	scale = (add ? scale + 0.1 : scale - 0.1);
//	if (scale >= 2.0)
//	{
//		add = false;
//	}
//	else if (scale <= 0.0) {
//		add = true;
//	}
//	//开始绘画
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
//		glColor3f(1.0, 0.0, 1.0); //画笔梅红色
//		glBegin(GL_POLYGON);
//		glVertex2f(-0.2, -0.2);
//		glVertex2f(-0.2, 0.2);
//		glVertex2f(0.2, 0.2);
//		glVertex2f(0.2, -0.2);
//		glEnd();
//	}
//	glPopMatrix();
//
//	glLoadIdentity();  //加载单位矩阵
//	glColor3f(0.0, 0.0, 1.0); //画笔蓝色
//	//--------画直线START--------
//	//画直线
//	glBegin(GL_LINES);
//	glVertex2f(-0.5, 0);
//	glVertex2f(0.5, 0);
//	glVertex2f(0, 0.5);
//	glVertex2f(0, -0.5);
//	glEnd();
//	//--------画直线E N D--------
//
//	if (OUTPUT_MODE == 0) {
//		glFlush();//单缓存GLUT_SINGLE时使用
//	}
//	else {
//		glutSwapBuffers();//因为使用的是双缓存GLUT_DOUBLE，所以这里必须要交换缓存才会显示
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
//	//配置显示物体屏幕的大小
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
//	printf("按键%c\n", key);
//}
//
//int main(int argc, char *argv[])
//{
//	printf("可通过按键xyza控制图形按哪一轴缩放\n");
//	glutInit(&argc, argv);
//
//	glutInitDisplayMode(GLUT_RGB | (OUTPUT_MODE == 0 ? GLUT_SINGLE : GLUT_DOUBLE));
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(400, 400);
//	glutCreateWindow("第一个 OpenGL 程序");
//
//	init();
//	glutDisplayFunc(&display);
//	glutIdleFunc(display);  //设置不断调用显示函数
//	glutReshapeFunc(reshape);
//	glutKeyboardFunc(keyboard);
//	glutMainLoop();
//	return 0;
//}


















//#include<GL/glut.h>
//#include <windows.h>
//#include <cmath> 
//static GLfloat spin=0.0;				//旋转量
//static GLfloat move=0.0;				//平移量
//static GLfloat size=1.0;				//缩放量
// 
//void init(void)
//{
//	glClearColor(0.0,0.0,0.0,0.0);		//指定清除颜色（黑色），即背景颜色
//	glShadeModel(GL_FLAT);
//}
// 
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);		//清除所有的像素
//	glPushMatrix();
//	glTranslatef(move,0,0);				//移动，参数含义(x轴位移,y轴位移,z轴位移)
//	glRotatef(spin,0,0,1);				//旋转，参数含义(旋转量,x轴,y轴,z轴)
//	glScalef(size,size,1);				//缩放，参数含义(x轴倍数,y轴倍数,z轴倍数)
//
//
//	// 绘制可见光谱
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
//	//glColor3f(0.0,1.0,0.0);				//绘制颜色RGB
//	//glRectf(-25.0,-25.0,25.0,25.0);		//绘制矩形
//	//glColor3f(1.0, 0, 0.0);				//绘制颜色RGB
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
//	glutPostRedisplay();				//标记当前窗口需要重绘，否则不会旋转
//	Sleep(10);
//}
// 
//void moveDisplay()
//{
//	move=move>20?move-=20:move+=1;
//	glutPostRedisplay();				//标记当前窗口需要重绘，否则不会旋转
//	Sleep(10);
//}
// 
//int main(int argc,char* argv[])
//{
//	glutInit(&argc,argv);							//初始化GLUT并处理命令行参数
//	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);		//指定模式：双缓存；RGB模式
//	glutInitWindowSize(250,250);					//指定窗口大小（像素）
//	glutInitWindowPosition(300,200);				//指定窗口左上角在屏幕上的位置
//	glutCreateWindow(argv[0]);						//使用OpenGL场景创建一个窗口，参数为窗口名称
//	init();											//调用初始化函数
//	glutDisplayFunc(display);						//显示
//	glutReshapeFunc(reshape);						//重绘
//	//glutIdleFunc(spinAndSizeDisplay);				//旋转&缩放
//	//glutIdleFunc(moveDisplay);						//移动(与上边函数只能有一个有效)
//	glutMainLoop();									//进入主循环并处理事件，此时创建的所有窗口都会显示出来，被渲染到这些窗口中的内容也将显示出来，程序开始处理事件，注册的显示回调函数被触发
//	return 0;										//ANSI C要求函数main()返回一个int值
//}


