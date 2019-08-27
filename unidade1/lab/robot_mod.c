#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static int shoulder = 0, elbow = 0;
static int rDedo_m = 0;
static int rDedo_t = 0;
static int rDedo_f = 0;

void init(void) 
{
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glShadeModel (GL_FLAT);
}

void display(void)
{  
   glClear (GL_COLOR_BUFFER_BIT);
   glPushMatrix(); //salva a identidade

   
   //cria o primeiro segmento
   glTranslatef (-1.0, 0.0, 0.0);
   glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);
   glTranslatef (1.0, 0.0, 0.0);
   glPushMatrix();
   glScalef (2.0, 0.4, 1.0);
   glutWireCube (1.0);
   glPopMatrix();
   
   //cria o segundo segmento
   glTranslatef (1.0, 0.0, 0.0);
   glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
   glTranslatef (1.0, 0.0, 0.0);
   glPushMatrix();
   glScalef (2.0, 0.4, 1.0);
   glutWireCube (1.0);
   glPopMatrix();
   
   //cria o dedo do meio
   glTranslatef(1.0, 0.0, 0.0);
   glPushMatrix();
   
   glTranslatef(0.4,0.0,0.0);
   glRotatef((GLfloat)rDedo_m, 0.0, 0.0, 1.0);
   glTranslatef(-0.4, 0.0, 0.0);
   glPushMatrix();
   glScalef(2.0, 0.4, 1.0);
   glutWireCube(0.4);
   glPopMatrix();
   glPopMatrix();
   
   glPushMatrix();
   //cria o dedo de tras
   glTranslatef(0.4, 0.0, -0.5);
   glRotatef((GLfloat)rDedo_t, 0.0, 0.0, 1.0);
   glTranslatef(-0.4,0.0,0.0);
   glPushMatrix();
   glScalef(2.0, 0.4, 1.0);
   glutWireCube(0.4);
   glPopMatrix();
   glPopMatrix();
   

   glPushMatrix();
   //cria o dedo da frente
   glTranslatef(0.4, 0.0, 0.5);
   glRotatef((GLfloat)rDedo_f, 0.0, 0.0, 1.0);
   glTranslatef(-0.4,0.0,0.0);
   glPushMatrix();
   glScalef(2.0, 0.4, 1.0);
   glutWireCube(0.4);
   glPopMatrix();
   glPopMatrix();


   glPopMatrix();
   glutSwapBuffers();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
  // glTranslatef (0.0, 0.0, -5.0);
  gluLookAt(5,5,5,0,0,0,0,1,0);
}

void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      case 's':   /*  s key rotates at shoulder  */
         shoulder = (shoulder + 5) % 360;
         glutPostRedisplay();
         break;
      case 'S':
         shoulder = (shoulder - 5) % 360;
         glutPostRedisplay();
         break;
      case 'e':  /*  e key rotates at elbow  */
         elbow = (elbow + 5) % 360;
         glutPostRedisplay();
         break;
      case 'E':
         elbow = (elbow - 5) % 360;
         glutPostRedisplay();
         break;
	  case 'i':
	  	rDedo_m = (rDedo_m + 5) % 360;
		glutPostRedisplay();
		break;
	  case 'I':
	  	rDedo_m = (rDedo_m - 5) % 360;
		glutPostRedisplay();
		break;	
	  case 'o':
	  	rDedo_t = (rDedo_t + 5) % 360;
		glutPostRedisplay();
		break;	
	  case 'O':
	  	rDedo_t = (rDedo_t - 5) % 360;
		glutPostRedisplay();
		break;	
	  case 'p':
	  	rDedo_f = (rDedo_f + 5) % 360;
		glutPostRedisplay();
		break;	
	  case 'P':
	  	rDedo_f = (rDedo_f - 5) % 360;
		glutPostRedisplay();
		break;	
      default:
         break;
   }
}

int main(int argc, char** argv)
{
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
