//#include<GL/glut.h>
//#include <windows.h>
//#include <cmath> 
// 
//
//void init(void)
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);		 
//	glShadeModel(GL_FLAT);
//}
//
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);		 
//	glPushMatrix();
//
//
//	// 绘制可见光谱
//	float len = 400, a, R, G, B, xx1 = -45, xx2 = -30, yy1 = -44.7, yy2 = 30;
//	int i;
//	for (; len <= 700; len += 0.1) {
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
// 
//		glColor3f(R, G, B);
//		glRectf(xx1, xx2, yy1, yy2);
//
//		yy1 += 0.03;
//		xx1 += 0.03;
//
//	}
//	glPopMatrix();
//	glutSwapBuffers();
//}
//
//void reshape(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
//}
//
// 
//
//int main(int argc, char* argv[])
//{
//	glutInit(&argc, argv);							 
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);	 
//	glutInitWindowSize(250, 250);					 
//	glutInitWindowPosition(300, 200);				 
//	glutCreateWindow(argv[0]);						 
//	init();											 
//	glutDisplayFunc(display);						 
//	glutReshapeFunc(reshape);					 
//	 
//	glutMainLoop();									 
//	return 0;										 
//}
