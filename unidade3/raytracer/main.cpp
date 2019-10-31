#include <iostream>
#include <ctime>
#include <cstdlib>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <glm/glm.hpp>

using namespace std;

int main(int argc, char **argv){

  Scenario scene(vec3(0.0,0.0,0.0), 0.5);

  RayTracer (scene);

  Window win(100,100,500,500,);


  Camera cam;
  Scenario scene;


  srand(time(0));



  glutDisplayFunc(win.display);
  glutMainLoop();
  return 0;
}
