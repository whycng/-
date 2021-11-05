#include<gl/glut.h>
#include <windows.h>
#include <iostream>
#include<cmath>

static GLfloat spin = 0.0;				//旋转量
static GLfloat move = -30.0,move2=-30;				//平移量
static GLfloat size = 1.0;				//缩放量

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);		//指定清除颜色（黑色），即背景颜色
	glShadeModel(GL_FLAT);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);		//清除所有的像素
	glPushMatrix();
	glTranslatef(move, move2, 0);				//移动，参数含义(x轴位移,y轴位移,z轴位移)
	glRotatef(spin, 0, 0, 1);				//旋转，参数含义(旋转量,x轴,y轴,z轴)
	glScalef(size, size, 1);				//缩放，参数含义(x轴倍数,y轴倍数,z轴倍数)
	glColor3f(0.0, 1.0, 0.0);				//绘制颜色RGB
	//glRectf(-25.0, -25.0, 25.0, 25.0);		//绘制矩形
	//测试
	//glBegin(GL_LINES);//十字架
	//glColor3f(10, 0, 0);
	//glVertex3f(-10, 0, 0);
	//glVertex3f(0, 10, 0);
	//glVertex3f(0, -10, 0);
	//glEnd();
	//五角星
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

	glutPostRedisplay();				//标记当前窗口需要重绘，否则不会旋转
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
	glutPostRedisplay();				//标记当前窗口需要重绘，否则不会旋转
	Sleep(10);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);							//初始化GLUT并处理命令行参数
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);		//指定模式：双缓存；RGB模式
	glutInitWindowSize(250, 250);					//指定窗口大小（像素）
	glutInitWindowPosition(300, 200);				//指定窗口左上角在屏幕上的位置
	glutCreateWindow(argv[0]);						//使用OpenGL场景创建一个窗口，参数为窗口名称
	init();											//调用初始化函数
	glutDisplayFunc(display);						//显示
	glutReshapeFunc(reshape);						//重绘
	glutIdleFunc(spinAndSizeDisplay);				//旋转&缩放
	//glutIdleFunc(moveDisplay);						//移动(与上边函数只能有一个有效)
	glutMainLoop();									//进入主循环并处理事件，此时创建的所有窗口都会显示出来，被渲染到这些窗口中的内容也将显示出来，程序开始处理事件，注册的显示回调函数被触发
	return 0;										//ANSI C要求函数main()返回一个int值
}