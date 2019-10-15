#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void init(void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glEnable(GL_DEPTH_TEST);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-15.0, 15.0, -15.0, 15.0, -15.0, 15.0);
  glViewport(100, 100, 500, 500);

  // glRotatef(x_angle, 1.0, 0.0, 0.0);
  // glRotatef(y_angle, 0.0, 1.0, 0.0);
  // glRotatef(z_angle, 0.0, 0.0, 1.0);

  // draw pyramid
  drawTriangle(0.0, 5.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 5.0, 255, 255, 255);
  drawTriangle(0.0, 5.0, 0.0, 0.0, 0.0, -5.0, 5.0, 0.0, 0.0, 0, 255, 204);
  drawTriangle(0.0, 5.0, 0.0, -5.0, 0.0, 0.0, 0.0, 0.0, -5.0, 102, 102, 255);
  drawTriangle(0.0, 5.0, 0.0, 0.0, 0.0, 5.0, -5.0, 0.0, 0.0, 255, 255, 0);

  glDisable(GL_DEPTH_TEST);
  glPointSize(10.0);
  drawLine(-10.0, 0.0, 0.0, 10.0, 0.0, 0.0, 255.0, 0.0, 0.0);
  drawLine(0.0, -10.0, 0.0, 0.0, 10.0, 0.0, 0.0, 255.0, 0.0);
  drawLine(0.0, 0.0, -10.0, 0.0, 0.0, 10.0, 0.0, 0.0, 255.0);

  glFlush();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   // glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
   gluPerspective(60, w/h, 1.0, 10);
   glMatrixMode (GL_MODELVIEW);
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (0, 0);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutMainLoop();
   return 0;
}
