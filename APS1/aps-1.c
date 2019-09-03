#include <GL/glut.h>
#include <stdio.h>

float Tx = 5, Ty = 5 , Angulo = 0;
char Func = {'t'};

void GerenciaTeclado(unsigned char key, int x, int y)
{
    switch (key) {
        case 'r' | 'R': 
            Func = 'r';
            break;
        case 't' | 'T':
            Func = 't';
            break;
    }

}

void TeclasEspeciais(int key, int x, int y)
{

    if(key == GLUT_KEY_UP && Func == 't') Ty += 1;
    if(key == GLUT_KEY_DOWN && Func == 't') Ty -= 1;
    if(key == GLUT_KEY_LEFT && Func == 't') Tx -= 1;
    if(key == GLUT_KEY_RIGHT && Func == 't') Tx += 1;  

    if(key == GLUT_KEY_RIGHT && Func == 'r') Angulo -= 5;
    if(key == GLUT_KEY_LEFT && Func == 'r') Angulo += 5;

}

void desenhaBox(void){

    glBegin(GL_POLYGON);
        glVertex2i(Tx - 5,Ty - 5);
        glVertex2i(Tx - 5,Ty + 5);
        glVertex2i(Tx + 5,Ty + 5);
        glVertex2i(Tx + 5,Ty -5);
    glEnd();

}

int init(void){

    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 100.0, 0.0, 100.0);

}

void display(void){

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    

    glTranslatef(Tx,Ty,0);
    glRotatef((float)Angulo,0,0,1.0);
    glTranslatef(-Tx,-Ty,0);

    glutPostRedisplay();
    desenhaBox();

    glFlush();

}

int main(int argc, char** argv){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(200,200);
    glutCreateWindow("APS - CG");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(GerenciaTeclado);
    glutSpecialFunc(TeclasEspeciais);
    glutMainLoop();

 return 0;
}