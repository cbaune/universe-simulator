#ifndef UNIVERSEOBJECT_H
#define UNIVERSEOBJECT_H

#include "vec.h"
#include <iostream>
#include "types.h"

namespace simulation {

class Object {
public:
  Object(tMass m, tPosition rad, Vec pos, Vec vel);
  Object(tMass m, tPosition rad, Vec pos, Vec vel, tElasticity ela, bool fix);
  void ApplyForce(Vec F, tTime dt);
  void Propagate(tTime dt);
  void Merge(Object* target);
  tMass Mass();
  tPosition Radius();
  Vec Position();
  Vec Velocity();
  void AddVelocity(Vec newvel);
  tElasticity Elasticity();
  void Print(std::ostream& stream);
private:
  tMass mass;
  tPosition radius;
  Vec position;
  Vec velocity;
  tElasticity elasticity;
  bool fixed;
};

typedef std::vector<Object*>::iterator ObjectIterator;


}

#endif // UNIVERSEOBJECT_H
