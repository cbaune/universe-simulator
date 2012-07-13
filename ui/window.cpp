#include "window.h"

namespace ui {

Window::Window(int w, int h) : Width(w), Height(h), ViewX(0), ViewY(0), Zoom(5e-10), FollowObject(NULL) {}

bool Window::Visible(simulation::Vec Position, simulation::tPosition Radius) {
  float x = Position[0]*Zoom - ViewX + Width/2;
  float y =  -Position[1]*Zoom - ViewY + Height/2;
  bool ret = true;
  ret &= (x >= -Radius);
  ret &= (x <= Width+Radius);
  ret &= (y >= -Radius);
  ret &= (y <= Height+Radius);
  return ret;
}

int Window::GetViewX() {
  return ViewX;
}

int Window::GetViewY() {
  return ViewY;
}

float Window::GetZoom() {
  return Zoom;
}

void Window::Follow(simulation::Object *obj) {
  FollowObject = obj;
}

void Window::ChangeZoom(int dz) {
  Zoom *= 1 + dz*0.1;
  ViewX *= 1 + dz*0.1;
  ViewY *= 1 + dz*0.1;
}

void Window::MoveViewport(int dx, int dy) {
  if(!FollowObject) {
    ViewX += dx;
    ViewY += dy;
  }
}

float Window::ScreenCoordX(simulation::Vec Position) {
  if(FollowObject) {
    ViewX = FollowObject->Position()[0]*Zoom;
    return (Position[0] - FollowObject->Position()[0])*Zoom + Width/2;
  } else
    return Position[0]*Zoom - ViewX + Width/2;
}

float Window::ScreenCoordY(simulation::Vec Position) {
  if(FollowObject) {
    ViewY = FollowObject->Position()[1]*Zoom;
    return (Position[1] - FollowObject->Position()[1])*Zoom + Height/2;
  } else
    return Position[1]*Zoom - ViewY + Height/2;
}

float Window::ScaledRadius(simulation::tPosition Radius) {
  return Radius*Zoom;
}

}
