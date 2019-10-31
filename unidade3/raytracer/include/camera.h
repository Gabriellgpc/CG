#include "utils.h"

class Camera{
public:
  Vec pos, lookat, vup;
  Camera(Vec p, Vec at, Vec up):pos(p), lookat(at), vup(up) {}

  void rotate(Vec axis, float ang);
  void translate(Vec axis);
};
