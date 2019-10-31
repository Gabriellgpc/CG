

class Window{
public:
  uint posx,posy,width,height;
  ImageRGBf img;
  RayTracer 

public:
  Window(uint posx, uint posy,uint width,uint height);
  void reshape(int w, int h);
  void display();



};
