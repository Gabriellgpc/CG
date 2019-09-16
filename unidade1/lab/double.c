#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

static GLfloat spin = 0.0;

void init(void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
}

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);     //limpa a tela (com a cor definida em glClearColor)
   glPushMatrix();                   //repete a matriz que esta no topo da pilha
   glRotatef(spin, 0.0, 0.0, 1.0);   //aplica uma rotacao
   glColor3f(1.0, 0.0, 0.0);         //define uma cor para ser usada nos desenhos seguintes
   glRectf(-25.0, -25.0, 25.0, 25.0);//desenha um retangulo
   glPopMatrix();                    //remove a matriz de transformacao que esta no topo da pilha
   glutSwapBuffers();                //troca o buffer desenho e exibição
}

//funcao alterada para girar o cube no sentido anti-horario
void spinDisplay(void)
{
   spin = spin - 2.0;
   if (spin < -360.0)
      spin = 0.0;
   glutPostRedisplay();
}

void reshape(int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);  //informe ao opengl as dimensoes da janela de exibicao
   glMatrixMode(GL_PROJECTION);                  //troca a pilha de matrix para a pilha de projeçao
   glLoadIdentity();                             //carrega a matriz identidade na pilha
   glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0); //define as coordenadas de corte do volume
   glMatrixMode(GL_MODELVIEW);                   //seta a pilha para a GL_MODELVIEW
   glLoadIdentity();                             // carrega a identidade na pilha do GL_MODELVIEW
}

void mouse(int button, int state, int x, int y)
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay);
         break;
      case GLUT_MIDDLE_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(NULL);
         break;
      default:
         break;
   }
}

/*
 *  Request double buffer display mode.
 *  Register mouse input callback functions
 */
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (250, 250);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutMouseFunc(mouse);
   glutMainLoop();
   return 0;
}
