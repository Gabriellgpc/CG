#include "utils.h"
#include <list>

#include "light.h"
#include "camera.h"
#include "object.h"

class Scenario{
public:
  std::list<Object*> objs;
  std::list<LightSource> lights;
  Camera cam;
  float lightEnv;
  Vec bgColor;

  Scenario(Vec bgColor, float lightEnv);
};
