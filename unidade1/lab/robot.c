#include <GL/glut.h>
#include <stdlib.h>

static int shoulder = 0, elbow = 0;
static int dedo[3] = {0, 0, 0};

void eixos(void)
{
  // Z
  glPushMatrix();
  glColor3f(0.0, 0.0, 1.0);
  glutSolidCone(0.1, 0.5, 5, 5);
  glPopMatrix();

  // Y
  glPushMatrix();
  glRotatef(-90.0, 1.0, 0.0, 0.0);
  glColor3f(0.0, 1.0, 0.0);
  glutSolidCone(0.1, 0.5, 5, 5);
  glPopMatrix();

  // X
  glPushMatrix();
  glRotatef(90.0, 0.0, 1.0, 0.0);
  glColor3f(1.0, 0.0, 0.0);
  glutSolidCone(0.1, 0.5, 5, 5);
  glPopMatrix();

  glColor3f(1.0, 1.0, 1.0);
}

void init(void){
  glClearColor (0.0, 0.0, 0.0, 0.0);
}

void display(void){
  glClear (GL_COLOR_BUFFER_BIT);

  glPushMatrix();

  /* origem posicionada no ombro */
  glTranslatef (-1.0, 0.0, 0.0);
  glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);
  /* origem posicionada no centro do braço */
  glTranslatef (1.0, 0.0, 0.0);
  glPushMatrix();
  glScalef (2.0, 0.4, 1.0);
  glutWireCube (1.0);
  glPopMatrix();

  /* origem posicionada no cotovelo */
  glTranslatef (1.0, 0.0, 0.0);
  glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
  glTranslatef (1.0, 0.0, 0.0);

  glPushMatrix();
  glScalef (2.0, 0.4, 1.0);
  glutWireCube (1.0);
  glPopMatrix();

  /* origem posicionada na palma da mao */
  glTranslatef(1.0, 0.0, 0.0);
  eixos();
  //Dedo 1
  glPushMatrix();
  glRotatef ((GLfloat) dedo[0], 0.0, 0.0, 1.0);
  glScaled(2.0, 1.0, 1.0);
  glTranslatef(0.1, 0.25, 0.5);
  glutWireCube(0.2);
  glPopMatrix();

  //Dedo 2
  glPushMatrix();
  glRotatef ((GLfloat) dedo[1], 0.0, 0.0, 1.0);
  glScaled(2.0, 1.0, 1.0);
  glTranslatef(0.1, 0.25, -0.5);
  glutWireCube(0.2);
  glPopMatrix();


  //Dedo 3
  glPushMatrix();
  glRotatef ((GLfloat) dedo[2], 0.0, 0.0, 1.0);
  glScaled(2.0, 1.0, 1.0);
  glTranslatef(0.1, -0.25, 0.0);
  glutWireCube(0.2);
  glPopMatrix();

  /* origem volta para o sistema de coordenadas original */
  glPopMatrix();
  glutSwapBuffers();
}

void reshape (int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(5.0, 2.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void keyboard (unsigned char key, int x, int y){
  switch (key) {
  case 's':
    shoulder = (shoulder + 5) % 360;
    glutPostRedisplay();
    break;
  case 'S':
    shoulder = (shoulder - 5) % 360;
    glutPostRedisplay();
    break;
  case 'e':
    elbow = (elbow + 5) % 360;
    glutPostRedisplay();
    break;
  case 'E':
    elbow = (elbow - 5) % 360;
    glutPostRedisplay();
    break;
  case 'j':
    dedo[0] = (dedo[0] - 5) % 360;
    glutPostRedisplay();
    break;
  case 'J':
    dedo[0] = (dedo[0] + 5) % 360;
    glutPostRedisplay();
    break;
  case 'k':
    dedo[1] = (dedo[1] - 5) % 360;
    glutPostRedisplay();
    break;
  case 'K':
    dedo[1] = (dedo[1] + 5) % 360;
    glutPostRedisplay();
    break;
  case 'l':
    dedo[2] = (dedo[2] + 5) % 360;
    glutPostRedisplay();
    break;
  case 'L':
    dedo[2] = (dedo[2] - 5) % 360;
    glutPostRedisplay();
    break;

  case 27:
    exit(0);
    break;
  default:
    break;
  }
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (500, 500);
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);
  init ();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}
