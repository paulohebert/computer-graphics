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

    /* Ajusta a posição do personagem para não desaparecer da tela */
    if (translateX < -view_width)
        translateX = -view_width;
    else if (translateX > view_width)
        translateX = view_width;

    gluOrtho2D(-view_width, view_width, -100, 100);
}

void init()
{
    glClearColor(0.2, 0.7, 0.8, 1.0);

    translateX = rot_body = rot_sword = rot_left_arm = rot_right_arm = 0;
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
    int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
    glutInitWindowSize(screenWidth, screenHeight);

    glutCreateWindow("Guerreiro");

    glutDisplayFunc(drawScene);

    glutReshapeFunc(reshape);

    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

    init();

    glutMainLoop();
    return 0;
}