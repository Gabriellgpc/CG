#include "utils.h"

class Object{
public:
  Vec pos;
  float ks, kd;

  Object(Vec pos, float ks, float kd);
  virtual bool intersectPoint(Vec line, Vec &point) = 0;
};

class Sphere:public Object{
public:
  float r;

  bool intersectPoint(Vec line, Vec &point);
};

class Plane:public Object{
public:
  Vec normal;

  bool intersectPoint(Vec line, Vec &point);
};
