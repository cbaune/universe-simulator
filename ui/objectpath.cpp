#include "objectpath.h"

#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>

namespace ui {

ObjectPath::ObjectPath(simulation::Object *obj, Window* w) : PathSteps(500), NumberOfElements(0), Obj(obj), W(w) {}

void ObjectPath::Update() {
  Path.push_front(Obj->Position());
  if(NumberOfElements < PathSteps)
    NumberOfElements++;
  else
    Path.pop_back();
}

void ObjectPath::Draw() {
  simulation::Vec PreviousPoint;
  int i=PathSteps;
  for (std::list<simulation::Vec>::reverse_iterator it = Path.rbegin(); it != Path.rend(); it++) {
    if(it!=Path.rbegin()) {
      float percentage = (PathSteps-i)*1.0/NumberOfElements;
      --i;

      al_draw_line(W->ScreenCoordX(PreviousPoint), W->ScreenCoordY(PreviousPoint),
                   W->ScreenCoordX(*it), W->ScreenCoordY(*it),
                   al_map_rgb(192*percentage,192*percentage,0), 0.3);
    }
    PreviousPoint = *it;
  }
}



}
