// 
//#include <GL/glut.h>
//#include <math.h>
//#include <cstdio>
//const GLfloat Pi = 3.141592f;  //定义Pi值
//
//GLfloat X[5], Y[5], SX[5], SY[5];  //用数组声明5组坐标
//int R = 1;  //定义半径
//float r = 0.3;
//float X0 = 0;
//float Y0 = 0;
//
//void init() //初始化函数
//{
//	glClearColor(1.0, 1.0, 1.0, 0.0);  //设置背景颜色
//	for (int i = 0; i <= 4; i++)
//	{
//		//在圆上初始化5个坐标点
//		X[i] = R * cos((2 * Pi * i / 5));
//		Y[i] = R * sin((2 * Pi * i / 5));
//		SX[i] = r * cos((2 * Pi * i / 5) + (Pi / 5));
//		SY[i] = r * sin((2 * Pi * i / 5) + (Pi / 5));
//	}
//}
//
//void myDisplay(void)  //显示函数
//{
//	int flag = 3;     //flag=1 线；flag=2 单色； flag=3 双色；
//	glClear(GL_COLOR_BUFFER_BIT);  //清除颜色
//	if (flag == 1)   //flag=1 线；
//	{
//		glColor3f(1.0, 0.0, 0.0);  //设置线条颜色
//		glBegin(GL_LINE_LOOP); //按照顺序开始画线，AC->CE->EB->BD->DA
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
//		if (flag == 2)          glColor3f(1, 0, 0);   //flag = 2 单色；
//		else if (flag == 3)  glColor3f(0, 0, 1);   //flag = 3 双色；
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
//	glFlush();  //保证前面的命令立即执行
//}
//
//int main(int argc, char* argv[])
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
//	glutInitWindowPosition(100, 100);  //设置显示位置
//	glutInitWindowSize(400, 400);   //设置窗口大小
//	glutCreateWindow("五角星图案");  //设置窗口标题
//	init();                          //运行初始化函数
//	glutDisplayFunc(&myDisplay);     //调用显示窗口
//	glutMainLoop();
//	return 0;
//}
//
//
//
