#include <GL/glut.h>
#include "draw.h"
#include "keyboard.h"

void reshape(GLsizei width, GLsizei height)
{
    if (height == 0)
        height = 1;

    view_width = 100.0 * width / height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (translateX < -view_width)
        translateX = -view_width;
    if (translateX > view_width)
        translateX = view_width;

    gluOrtho2D(-view_width, view_width, -100, 100);

    /*
        if (width > height)
            gluOrtho2D(-100, 100.0 * width / height, -100, 100 * width / height);
        else
            gluOrtho2D(-100.0 * width / height, 100.0 * width / height, 0.0, 100.0); */
}

void init()
{
    glClearColor(0.2, 0.7, 0.8, 1.0);

    translateX = rot_body = rot_left_arm = rot_right_arm = 0;
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
    int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
    glutInitWindowSize(screenWidth, screenHeight);

    glutCreateWindow("Atividade");

    glutDisplayFunc(drawScene);

    glutReshapeFunc(reshape);

    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

    init();

    glutMainLoop();
    return 0;
}