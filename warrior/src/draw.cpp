#include <GL/glut.h>
#include <string>
#include "draw.h"
#ifdef __EMSCRIPTEN__
#include "emscripten/html5.h"
#endif

GLfloat translateX, rot_body, rot_left_arm, rot_right_arm, rot_sword, view_width;

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
    glPointSize(7.0 - (view_width / 100));
    glBegin(GL_POINTS);
    glVertex2f(-2.0, 28.0);
    glVertex2f(2.0, 28.0);
    glEnd();

    glLineWidth(5.0 - (view_width / 125));

    /* Boca */
    glBegin(GL_LINES);
    glVertex2f(-2, 23);
    glVertex2f(2, 23);
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

/* Braço Esquerdo */
void drawLeftArm()
{
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

    /* Rotacionar Espada */
    glPushMatrix();
    glTranslatef(-10, 0.0, 0.0);
    glRotatef(rot_sword, 0.0f, 0.0f, 1.0f);
    glTranslatef(10, 0.0, 0.0);

    glColor3f(0.0, 0.0, 0.0);

    /* Espada */
    glBegin(GL_LINES);
    glVertex2i(-10, 0);
    glVertex2i(-40, 30);
    glVertex2i(-17, 0);
    glVertex2i(-10, 7);
    glEnd();

    /* Remover Rotação da Espada */
    glPopMatrix();

    /* Remover Rotação do Braço Esquerdo */
    glPopMatrix();
}

/* Braço Direito */
void drawRightArm()
{
    /* Rotacionar Braço Direito */
    glPushMatrix();
    glTranslatef(0, 20.0, 0.0);
    glRotatef(rot_right_arm, 0.0f, 0.0f, 1.0f);
    glTranslatef(0, -20.0, 0.0);

    /* Escudo */
    glBegin(GL_TRIANGLES);
    glVertex2f(15, 10);
    glVertex2f(20, 0);
    glVertex2f(10, -5);

    glVertex2f(10, -5);
    glVertex2f(2.5, -3);
    glVertex2f(5, 5);

    glVertex2f(10, -5);
    glVertex2f(5, 5);
    glVertex2f(15, 10);
    glEnd();

    glColor3f(0.7, 0.5, 0.2);

    /* Braço Direito */
    glBegin(GL_LINES);
    glVertex2i(0, 20);
    glVertex2i(10, 0);
    glEnd();

    /* Remover Rotação do Braço Direito */
    glPopMatrix();
}

/* Corpo */
void drawBody()
{
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

    /* Braço Esquerdo e a Espada */
    drawLeftArm();

    /* Braço Direito e o Escudo */
    drawRightArm();

    /* Cabeça */
    drawHead();

    /* Remover Rotação do Corpo */
    glPopMatrix();
}

/* Guerreiro */
void drawWarrior()
{
    glColor3f(0.7, 0.5, 0.2);
    glEnable(GL_LINE_SMOOTH);
    glLineWidth(10.0);

    /* Mover Horizontal */
    glPushMatrix();
    glTranslatef(translateX, 0.0, 0.0);

    /* Corpo */
    drawBody();

    /* Remover Translação Horizontal */
    glPopMatrix();
}

#ifndef __EMSCRIPTEN__
/* Mostra Informações das rotações e da translação */
void drawInfo()
{
    glColor3f(1.0, 1.0, 1.0);

    float gap = view_width < 200 ? view_width / 200.0 : view_width < 250 ? view_width / 100.0
                                                                         : view_width / 50.0;

    std::string translateX_info = "X = " + std::to_string(translateX);

    glRasterPos2f(-view_width, 95 - gap);
    for (int i = 0, size = translateX_info.size(); i < size; ++i)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, translateX_info[i]);
    }

    std::string rot_body_info = "Corpo = " + std::to_string((int)rot_body) + " graus";

    glRasterPos2f(-view_width, 89 - 2 * gap);
    for (int i = 0, size = rot_body_info.size(); i < size; ++i)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, rot_body_info[i]);
    }

    std::string rot_left_arm_info = "B. Esquerdo. = " + std::to_string((int)rot_left_arm) + " graus";

    glRasterPos2f(-view_width, 83 - 3 * gap);
    for (int i = 0, size = rot_left_arm_info.size(); i < size; ++i)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, rot_left_arm_info[i]);
    }

    std::string rot_right_arm_info = "B. Direito. = " + std::to_string((int)rot_right_arm) + " graus";

    glRasterPos2f(-view_width, 77 - 4 * gap);
    for (int i = 0, size = rot_right_arm_info.size(); i < size; ++i)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, rot_right_arm_info[i]);
    }

    std::string rot_sword_info = "Espada = " + std::to_string((int)rot_sword) + " graus";

    glRasterPos2f(-view_width, 71 - 5 * gap);
    for (int i = 0, size = rot_sword_info.size(); i < size; ++i)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, rot_sword_info[i]);
    }
}
#endif

/* Plano de Fundo */
void drawBackground()
{
    glColor3f(0.2, 0.2, 0.2);

    /* Piso */
    glBegin(GL_QUADS);
    glVertex2f(-view_width, -70);
    glVertex2f(view_width, -70);
    glVertex2f(view_width, -40);
    glVertex2f(-view_width, -40);
    glEnd();

    glColor3f(0.0, 0.65, 0.0);

    /* Jardim */
    glBegin(GL_QUADS);
    glVertex2f(-view_width, -100);
    glVertex2f(view_width, -100);
    glVertex2f(view_width, -70);
    glVertex2f(-view_width, -70);
    glEnd();
}

#ifdef __EMSCRIPTEN__
/* Ajusta a Tela pelo Tamanho do Canvas */
void check_for_reshape()
{
    double canvasWidth, canvasHeight;
    emscripten_get_element_css_size("canvas", &canvasWidth, &canvasHeight);
    if (view_width != 100.0 * canvasWidth / canvasHeight)
    {
        view_width = 100.0 * canvasWidth / canvasHeight;
        glutReshapeWindow(canvasWidth, canvasHeight);
    }
}
#endif

void drawScene()
{
    #ifdef __EMSCRIPTEN__
    /* Ajusta a Tela pelo Tamanho do Canvas */
    check_for_reshape();
    #endif

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);

    /* Plano de Fundo */
    drawBackground();

    /* Guerreiro */
    drawWarrior();

    #ifndef __EMSCRIPTEN__
    /* Mostra os dados sobre rotação e translação */
    drawInfo();
    #endif

    glFlush();
}