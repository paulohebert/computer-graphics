#include <GL/glut.h>
#include <string>
#include "draw.h"

GLfloat translateX, rot_body, rot_left_arm, rot_right_arm, view_width;

/* Cabeça */
void drawHead()
{
    /* Rosto */
    glBegin(GL_QUADS);
    glVertex2f(-5, 20);
    glVertex2f(5, 20);
    glVertex2f(5, 32);
    glVertex2f(-5, 32);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);

    /* Olhos */
    glPointSize(7.0);
    glBegin(GL_POINTS);
    glVertex2f(-2.0, 28.0);
    glVertex2f(2.0, 28.0);
    glEnd();

    glLineWidth(5.0);

    /* Boca */
    glBegin(GL_LINES);
    glVertex2i(-2, 23);
    glVertex2i(2, 23);
    glEnd();
}

/* Pernas */
void drawLegs()
{
    glBegin(GL_LINES);
    /* Perna Esquerda */
    glVertex2i(0, -10);
    glVertex2i(-10, -50);
    /* Perna Esquerda */
    glVertex2i(0, -10);
    glVertex2i(10, -50);
    glEnd();
}

/* Pessoa */
void drawPerson()
{
    glColor3f(0.7, 0.5, 0.2);
    glEnable(GL_LINE_SMOOTH);
    glLineWidth(10.0);

    /* Mover Horizontal */
    glPushMatrix();
    glTranslatef(translateX, 0.0, 0.0);

    /* Pernas */
    drawLegs();

    /* Rotacionar Corpo */
    glPushMatrix();
    glTranslatef(0, -10.0, 0.0);
    glRotatef(rot_body, 0.0, 0.0, 1.0);
    glTranslatef(0, 10.0, 0.0);

    /* Tronco */
    glBegin(GL_LINES);
    glVertex2i(0, -10);
    glVertex2i(0, 20);
    glEnd();

    /* Rotacionar Braço Esquerdo */
    glPushMatrix();
    glTranslatef(0, 20.0, 0.0);
    glRotatef(rot_left_arm, 0.0, 0.0, 1.0);
    glTranslatef(0, -20.0, 0.0);

    /* Braço Esquerdo */
    glBegin(GL_LINES);
    glVertex2i(0, 20);
    glVertex2i(-10, 0);
    glEnd();

    /* Remover Rotação do Braço Esquerdo */
    glPopMatrix();

    /* Rotacionar Braço Direito */
    glPushMatrix();
    glTranslatef(0, 20.0, 0.0);
    glRotatef(rot_right_arm, 0.0f, 0.0f, 1.0f);
    glTranslatef(0, -20.0, 0.0);

    /* Braço Direito */
    glBegin(GL_LINES);
    glVertex2i(0, 20);
    glVertex2i(10, 0);
    glEnd();

    /* Remover Rotação do Braço Direito */
    glPopMatrix();

    /* Cabeça */
    drawHead();

    /* Remover Rotação do Corpo */
    glPopMatrix();
    /* Remover Translação Horizontal */
    glPopMatrix();
}

void drawInfo()
{
    glColor3f(1.0, 1.0, 1.0);

    std::string text = "X = " + std::to_string(translateX);

    glRasterPos2i(-view_width, 95 - (view_width / 200.0));
    for (int i = 0; i < text.length(); ++i)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }

    std::string text1 = "Corpo = " + std::to_string((int)rot_body) + " graus";

    glRasterPos2i(-view_width, 89 - (view_width / 200.0));
    for (int i = 0; i < text1.length(); ++i)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
    }

    std::string text2 = "B. Esquerdo. = " + std::to_string((int)rot_left_arm) + " graus";

    glRasterPos2i(-view_width, 83 - (view_width / 200.0));
    for (int i = 0; i < text2.length(); ++i)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text2[i]);
    }

    std::string text3 = "B. Direito. = " + std::to_string((int)rot_right_arm) + " graus";

    glRasterPos2i(-view_width, 77 - (view_width / 200.0));
    for (int i = 0; i < text3.length(); ++i)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text3[i]);
    }
}

void drawScene()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.2, 0.2, 0.2);

    glBegin(GL_QUADS);
    glVertex2f(-view_width, -70);
    glVertex2f(view_width, -70);
    glVertex2f(view_width, -40);
    glVertex2f(-view_width, -40);
    glEnd();

    glColor3f(0.0, 0.65, 0.0);

    glBegin(GL_QUADS);
    glVertex2f(-view_width, -100);
    glVertex2f(view_width, -100);
    glVertex2f(view_width, -70);
    glVertex2f(-view_width, -70);
    glEnd();

    drawPerson();

    drawInfo();

    glFlush();
}