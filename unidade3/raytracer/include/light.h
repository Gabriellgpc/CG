#include "utils.h"

class LightSource{
public:
  Vec pos;
  Vec color;

  LightSource(Vec p, Vec c):pos(p), color(c) {}
};
