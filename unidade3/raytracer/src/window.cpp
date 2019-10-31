

Window::Window(uint posx, uint posy,uint width,uint height){
  glutInit(NULL,NULL);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (500, 500);
  glutInitWindowPosition (100, 100);
  glutCreateWindow ("RayTracer Pro");

}

void Window::reshape(int w, int h){
      Eigen::Vector3f pos = scene.getCam()->pos;
      Eigen::Vector3f lookAt = scene.getCam()->lookAt;
      Eigen::Vector3f normal = scene.getCam()->normal;

      width = w;
      height = h;

      glViewport(0, 0, (GLsizei)width, (GLsizei)height);
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluPerspective(90.0, width/height, 0.01, 10000.0);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      gluLookAt(pos(0, 0), pos(1, 0), pos(2, 0), lookAt(0, 0), lookAt(1, 0), lookAt(2, 0), normal(0, 0), normal(1, 0), normal(2, 0));

}
void Window::display(){


}
