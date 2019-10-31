#include "utils.h"

#include "scenario.h"

class ImageRGBf{
public:
  float *data;
  uint width, height;

public:
  ImageRGBf();
  ImageRGBf(uint width, uint height);

  void setColor(uint i, uint j, const Vec &color);
  float &operator()(uint i, uint j, uint k);
};


class RayTracer{
public:
  Scenario &scene;

  RayTracer(const Scenario &scene);
  void rayTrace(ImageRGBf &img,int numRefletion);
private:
  void trace(const Vec &ray, uint n, Vec &color);
  void closestPoint(const Vec &ray,Vec &point);
  void shade(const Vec &point,const Vec &ray,const Vec &color);
  void toWorld(glm::vec3 &win);
};
