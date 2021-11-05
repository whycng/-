//#include <windows.h>
//#include <gl/glut.h>
//#include<stdio.h> 
//#include <stdint.h>
//#include<glew.h>
//#include<iostream>
//using namespace std;
//#include <stdlib.h>
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image/stb_image.h"
//static GLsizei iMode = 1;
//static GLfloat xRot = 0;
//static GLfloat yRot = 0;
//GLUquadricObj *obj;
//
//void Initial() {
//	glClearColor(1, 1, 1, 1);
//	glColor3f(0, 0, 0);
//	obj = gluNewQuadric();
//	gluQuadricDrawStyle(obj, GLU_LINE);
//}
//
//void ChangeSize(int w, int h) {
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(-1.5, 1.5, -1.5, 1.5);
//}
//void Display() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	glRotatef(xRot, 1, 0, 0);
//	glRotatef(yRot, 0, 1, 0);
//	switch (iMode) {
//	case 1:
//		glutWireTetrahedron(); break;
//		//glutSolidTetrahedron(); break;
//	case 2:
//		glutSolidTetrahedron(); break;
//	case 3:
//		glutWireOctahedron(); break;
//	case 4:
//		glutSolidOctahedron(); break;
//	case 5:
//		glutWireSphere(1, 15, 15); break;
//	case 6:
//		glutSolidSphere(1, 15, 15); break;
//	case 7:
//		glutWireTeapot(1); break;
//	case 8:
//		glutSolidTeapot(1); break;
//	case 9:
//		gluSphere(obj, 1, 15, 15); break;
//	case 10:
//		gluCylinder(obj, 1, 0, 1, 15, 15); break;
//	case 11:
//		gluPartialDisk(obj, 0.3, 0.8, 15, 15, 30, 260); break;
//	default: break;
//	}
//	glFlush();
//}
//
//void ProcessMenu(int value) {
//	iMode = value;
//	glutPostRedisplay();
//}
//void SpecialKeys(int key, int x, int y) {
//	if (key == GLUT_KEY_UP) xRot -= 5;
//	if (key == GLUT_KEY_DOWN) xRot += 5;
//	if (key == GLUT_KEY_LEFT) yRot -= 5;
//	if (key == GLUT_KEY_RIGHT) yRot += 5;
//	if (xRot > 356) xRot = 0;
//	if (xRot < -1) xRot = 355;
//	if (yRot > 356) yRot = 0;
//	if (yRot < -1) yRot = 355;
//	glutPostRedisplay();
//}
////        xx 
////uint32_t gen_texture() // 创建纹理
////{
////	uint32_t texture;
////	glGenTextures(1, &texture);
////	glBindTexture(GL_TEXTURE_2D, texture);
////
////	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
////	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
////	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
////	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
////
////	int width, height, nrChannels;
////	unsigned char* data = stbi_load("D:/Study/learnopengl/OpenglLearn/Texture/src/container.jpg", &width, &height, &nrChannels, 0);
////	if (data)
////	{
////		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
////		glGenerateMipmap(GL_TEXTURE_2D);
////	}
////	else
////	{
////		cout << "Failed to load texture" << endl;
////	}
////	stbi_image_free(data);
////	return texture;
////}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(400, 400);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("Hello");
//
//
//	SOIL_load_image('F:\abcd\课\计算机图形学\1.png', &width, &height, &nrComponents, SOIL_LOAD_RGB);
//
//	 
//	//菜单
//	/*int nGlutPolyMenu = glutCreateMenu(ProcessMenu);
//	glutAddMenuEntry("线框正四面体", 1);
//	glutAddMenuEntry("实体正四面体", 2);
//	glutAddMenuEntry("线框正八面体", 3);
//	glutAddMenuEntry("实体正八面体", 4);
//
//	int nGlutCurveMenu = glutCreateMenu(ProcessMenu);
//	glutAddMenuEntry("线框球面", 5);
//	glutAddMenuEntry("实体球面", 6);
//	glutAddMenuEntry("线框茶壶", 7);
//	glutAddMenuEntry("实体茶壶", 8);
//
//	int nGluCurveMenu = glutCreateMenu(ProcessMenu);
//	glutAddMenuEntry("线框球面", 9);
//	glutAddMenuEntry("线框圆锥面", 10);
//	glutAddMenuEntry("线框圆环面", 11);
//
//	int nMainMenu = glutCreateMenu(ProcessMenu);
//	glutAddSubMenu("GLUT多面体", nGlutPolyMenu);
//	glutAddSubMenu("GLUT曲面", nGlutCurveMenu);
//	glutAddSubMenu("GLU曲面", nGluCurveMenu);
//	glutAttachMenu(GLUT_RIGHT_BUTTON);*/
//	iMode = 3;
//	glutDisplayFunc(Display);
//	glutReshapeFunc(ChangeSize);
//	glutSpecialFunc(SpecialKeys);
//	Initial();
//	glutMainLoop();
//}