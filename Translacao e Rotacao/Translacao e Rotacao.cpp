
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>


#define janela_altura 600
#define janela_largura 800
float rotacao = 0;
float zoom = 1;
int figura = 0;
float trans = 1;

void display(void);
void tela(GLsizei w, GLsizei h);
void keyboard(unsigned char tecla, int x, int y);
void teclasEspeciais(int tecla, int x, int y);


int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(janela_largura, janela_altura);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Trabalho");
    glutDisplayFunc(display);
    glutReshapeFunc(tela);

    glutKeyboardFunc(&keyboard);
    glutSpecialFunc(&teclasEspeciais);
    glutMainLoop();

    return(0);

}

void keyboard(unsigned char tecla, int x, int y)
{
    if (tecla == '1') {
        figura = 1;
        printf("banana");

    }
    if (tecla == '2') {
        figura = 2;
       
    }
    if (tecla == '3') {
        figura = 3;
        printf("nao sei");
    }
    if (tecla == '+') {
        zoom = zoom + 0.05;
        printf("O valor do zoom e %.2f\n", zoom);
    }
    if (tecla == '-') {
        zoom = zoom - 0.05;
        printf("O valor do zoom e %.2f\n", zoom);
    }

    glutPostRedisplay();
    glFlush();
}

void teclasEspeciais(int tecla, int x, int y)
{
    if (tecla == GLUT_KEY_PAGE_UP) {
        rotacao = rotacao + 0.50;
        printf("O valor da rotacao e %.2f\n", rotacao);
    }
    if (tecla == GLUT_KEY_PAGE_DOWN) {
        rotacao = rotacao - 0.50;
        printf("O valor da rotacao e %.2f\n", rotacao);
    }
    if (tecla == GLUT_KEY_LEFT) {
        trans = trans - 1;
        printf("O valor da translacao e %.2f\n", trans);
    }
    if (tecla == GLUT_KEY_RIGHT) {
        trans = trans + 01;
        printf("O valor da translacao e %.2f\n", trans);
    }


    glutPostRedisplay();
    glFlush();
}


static class triangulo {
public:
    static void desenho1() {

        //triangulo
        glPushMatrix();
        glTranslated(0, 0, 0);
        if (figura == 1) {
            glRotated(rotacao, 0, 0, 1);
            glScalef(zoom, zoom, 0);
            glTranslatef(trans, 0, 0);


            glBegin(GL_TRIANGLES);
            glColor3f(0.0, 1.0, 0.0);
            glVertex2i(-100, -100);
            glVertex2i(0, 0);
            glVertex2i(100, -100);
            glEnd();


        }
        glPopMatrix();

    }

};


static class retangulo {
public:
    static void desenho2() {

        //quadrado1
        glPushMatrix();
        glTranslated(-200, 0, 0);

        if (figura == 2) {
            glRotated(rotacao, 0, 0, 1);
            glScalef(zoom, zoom, 0);
            glTranslatef(trans, 0, 0);

            glBegin(GL_QUADS);
            glColor3f(1.0, 0.0, 0.0);
            glVertex2i(-100, -100);
            glVertex2i(-100, 0);
            glVertex2i(100, 0);
            glVertex2i(100, -100);
            glEnd();

        }

        glPopMatrix();
    }

};

static class  quadrado {
public:
    static void desenho3() {

        //quadrado
        glPushMatrix();
        glTranslated(200, 0, 0);
        if (figura == 3) {
            glRotated(rotacao, 0, 0, 1);
            glScalef(zoom, zoom, 0);
            glTranslatef(trans, 0, 0);


            glBegin(GL_QUADS);
            glColor3f(0.0, 0.0, 1.0);
            glVertex2i(-100, 100);
            glVertex2i(100, 100);
            glVertex2i(100, -100);
            glVertex2i(-100, -100);
            glEnd();



        }
        glPopMatrix();
    }

};
     

void desenhar(){
    Sleep(20);
    triangulo::desenho1();
    Sleep(20);
    quadrado::desenho3();
    
    Sleep(20);
    retangulo::desenho2();

    glFlush();

}


void display()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glTranslatef(janela_largura / 2, janela_altura / 2, 0.0f);
    desenhar();

    glFlush;
}

void tela(GLsizei w, GLsizei h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, janela_largura, 0, janela_altura);

    glMatrixMode(GL_MODELVIEW);
}





