#ifndef WINDOW_H
#define WINDOW_H

#include "../simulation/types.h"
#include "../simulation/vec.h"
#include "../simulation/object.h"

namespace ui {

class Window
{
public:
  Window(int w, int h);
  bool Visible(simulation::Vec Position, simulation::tPosition Radius);
  float ScreenCoordX(simulation::Vec Position);
  float ScreenCoordY(simulation::Vec Position);
  float ScaledRadius(simulation::tPosition Radius);
  void MoveViewport(int dx, int dy);
  void ChangeZoom(int dz);
  int GetViewX();
  int GetViewY();
  float GetZoom();
  void Follow(simulation::Object* obj);
private:
  int Width;
  int Height;
  int ViewX;
  int ViewY;
  float Zoom;
  simulation::Object* FollowObject;
};

}

#endif // WINDOW_H
