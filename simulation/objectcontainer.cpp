#include "objectcontainer.h"
#include <algorithm>

namespace simulation {

ObjectContainer::ObjectContainer() {}

ObjectContainer::~ObjectContainer() {}

void ObjectContainer::AddObject(Object* newobject) {
  if(!Contains(newobject))
    Objects.push_back(newobject);
}

bool ObjectContainer::Contains(Object *newobject) {
  ObjectIterator it = find (Objects.begin(), Objects.end(), newobject);
  if(it==Objects.end()) return false;
  else return true;
}

void ObjectContainer::RemoveObject(Object *newobject) {
  ObjectIterator it = find (Objects.begin(), Objects.end(), newobject);
  if(it!=Objects.end()) Objects.erase(it);
}

}

