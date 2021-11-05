// 
//#include <gl\glut.h>
//#include <gl\GL.h>
//
//#include <iostream>
//#include <cmath>
//void myDisplay()
//{
//	 
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	 
//	glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
//
//	 
//	glFlush();
//}
//
// 
//
//void displayFivePointStar() {
//
//
//
//
//	glClearColor(1, 1, 1, 1);
//	glClear(GL_COLOR_BUFFER_BIT);
//
// 
//
//
//	glBegin(GL_LINE_LOOP);
//	glColor3f(1.0, 0.0, 0.0);
//
//	glBegin(GL_LINE_LOOP);
//	double x, y, zx, zy, pi = 3.1416, m = pi / 2 - 2 * pi / 5, n, r1, p, r;
//	p = pi / 2 - pi / 5;
//	//n = 2 * m;
//	r1 = 1 * sin(m);
//	r = r1 / sin(p);
//
//	int i, j;
//
//	for (i = 0; i < 5; i++) {
//		zx = r * cos(p);
//		zy = r * sin(p);
//		x = 1 * cos(m);
//		y = 1 * sin(m);
//		glVertex2f(x, y);
//		glVertex2f(zx, zy);
//		m += 2 * pi / 5;
//		p += 2 * pi / 5;
//
//	}
//	glEnd();
//
//
//
//	glFlush();
//}
//
//
//void displayFivePointStar2() {
//
//	glClearColor(1, 1, 1, 1);
//	glClear(GL_COLOR_BUFFER_BIT);
//
//
//	glBegin(GL_TRIANGLES);
//
//	glColor3f(0.0, 1.0, 0.0);
//	double x, y, zx, zy, pi = 3.1416, m = pi / 2 - 2 * pi / 5, n, r1, p, r;
//	p = pi / 2 - pi / 5;
//	//n = 2 * m;
//	r1 = 1 * sin(m);
//	r = r1 / sin(p);
//
//	int i, j;
//
//	for (i = 0; i < 10; i++) {
//		zx = r * cos(p);
//		zy = r * sin(p);
//		x = 1 * cos(m);
//		y = 1 * sin(m);
//		glVertex2f(x, y);
//		glVertex2f(zx, zy);
//		glVertex2f(0, 0);
//		if (i % 2 == 0) {
//			glColor3f(1.0, 0.0, 0.0);
//			m += 2 * pi / 5;
//		}
//			 
//		else {
//			glColor3f(0.0, 1.0, 0.0);
//			p += 2 * pi / 5;
//		}
//			 
//
//	}
//	glEnd();
//
//
//
//	glFlush();
//}
//
//
//
//int main(int argc, char *argv[])
//{
//	 
//	glutInit(&argc, argv);
//
// 
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
//
//	glutInitWindowPosition(500, 100);//设置窗口在屏幕中的位置
//	glutInitWindowSize(400, 400);//设置窗口的大小
//
// 
//	glutCreateWindow("一 ");
//
// 
//	glutDisplayFunc(displayFivePointStar2);
//
//	 
//	glutMainLoop();
//
//	return 0;
//}
