#include <GL/glut.h>
#include "draw.h"

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
    case 'W':
        if (rot_body >= -90)
            rot_body -= 10.0f;
        break;
    case 'q':
    case 'Q':
        if (rot_body <= 90)
            rot_body += 10.0f;
        break;
    case 'a':
    case 'A':
        if (rot_left_arm >= -90)
            rot_left_arm -= 10.0f;
        break;
    case 'z':
    case 'Z':
        if (rot_left_arm <= 10)
            rot_left_arm += 10.0f;
        break;
    case 's':
    case 'S':
        if (rot_right_arm <= 90)
            rot_right_arm += 10.0f;
        break;
    case 'x':
    case 'X':
        if (rot_right_arm >= -10)
            rot_right_arm -= 10.0f;
        break;
    case 'd':
    case 'D':
        if (rot_sword <= 90)
            rot_sword += 10.0f;
        break;
    case 'c':
    case 'C':
        if (rot_sword >= -10)
            rot_sword -= 10.0f;
        break;
    }
    glutPostRedisplay();
}

void specialKeys(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        if (rot_left_arm >= -90)
            rot_left_arm -= 10.0f;
        if (rot_right_arm <= 90)
            rot_right_arm += 10.0f;
        break;
    case GLUT_KEY_DOWN:
        if (rot_left_arm <= 10)
            rot_left_arm += 10.0f;
        if (rot_right_arm >= -10)
            rot_right_arm -= 10.0f;
        break;
    case GLUT_KEY_LEFT:
        translateX -= view_width / 10;
        if (translateX < -view_width)
            translateX = -view_width;
        break;
    case GLUT_KEY_RIGHT:
        translateX += view_width / 10;
        if (translateX > view_width)
            translateX = view_width;
        break;
    }
    glutPostRedisplay();
}