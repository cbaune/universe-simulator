#ifndef OBJECTPATH_H
#define OBJECTPATH_H

#include "../simulation/object.h"
#include "../simulation/vec.h"
#include <list>
#include "window.h"

namespace ui {

class ObjectPath
{
public:
  ObjectPath(simulation::Object* obj, Window* w);
  void Update();
  void Draw();
private:
  int PathSteps;
  int NumberOfElements;
  std::list<simulation::Vec> Path;
  simulation::Object* Obj;
  Window* W;
};

}

#endif // OBJECTPATH_H
