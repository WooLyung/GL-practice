#include "GLUTWindow.h"
#include <gl/glut.h>

GLUTWindow::GLUTWindow(int argc, char** argv, void callback())
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("simple OpenGL example");
	glutDisplayFunc(callback);
}

void GLUTWindow::Start()
{
	glutMainLoop();
}