#include "include/raytracer.h"

float &ImageRGBf::operator()(uint i, uint j, uint k){
  uint n = i*width*3 + j*3 + k;
  if(n >= width)return -1;
  return data[n];
};

void RayTracer::rayTrace(ImageRGBf &img,int numRefletion){
  for(int x=0;x<img.width;x++){
    for (int y = 0; y < height; y++) {
        // calcula o raio
        Vec ray;
        rayDirection(x,y,ray);
        trace();
    }
  }

}

void RayTracer::rayDirection(uint x,uint y,Vec &ret){
  glLoadIdentity();

  GLint viewport[4];
  GLdouble mvmatrix[16], projmatrix[16];
  GLint realy;         /*  OpenGL y coordinate position  */
  GLdouble wx, wy, wz; /*  returned world x, y, z coords  */
  Vec temp;

  gluLookAt(scene.cam.pos[0], scene.cam.pos[1], scene.cam.pos[2],
            scene.cam.lookat[0],scene.cam.lookat[1], scene.cam.lookat[2],
            scene.cam.vup[0], scene.cam.vup[1], scene.cam.vup[2]); //placed at (0,0,5), aim at (0,0,0), normal vector (0,1,0)

  glGetIntegerv (GL_VIEWPORT, viewport);
  glGetDoublev (GL_MODELVIEW_MATRIX, mvmatrix);
  glGetDoublev (GL_PROJECTION_MATRIX, projmatrix);
  /*  note viewport[3] is height of window in pixels  */
  realy = viewport[3] - (GLint)win(2) - 1;

  gluUnProject((GLdouble)win[0], (GLdouble)realy, 1.0,
              mvmatrix, projmatrix, viewport, &ret[0], &ret[1], &ret[2]);

  gluUnProject ((GLdouble) x, (GLdouble) realy, 0.0,
                mvmatrix, projmatrix, viewport, &temp[0], &temp[1], &temp[2]);

  ret = ret - temp;
}
