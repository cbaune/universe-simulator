#include "universe.h"
#include <cmath>
#include <iostream>

namespace simulation {

Universe::Universe() {}

Universe::~Universe() {}

void Universe::Simulate(tTime dt, unsigned int NumberOfTimeSteps) {

  for(unsigned int i = 0; i < NumberOfTimeSteps; i++) {

    // recalculate velocities:
    grav.Act(dt);

    // actually move the objects:
    for(ObjectIterator it=Objects.begin(); it!=Objects.end(); it++)
      (*it)->Propagate(dt);
  }
}

void Universe::Print(std::ostream& stream) {
  for(ObjectIterator it=Objects.begin(); it!=Objects.end(); it++) {
    (*it)->Print(stream);
    stream << " ";
  }
  stream << std::endl;
}

void Universe::AddGravitationObject(Object *newobject) {
  AddObject(newobject);
  grav.AddObject(newobject);
}

void Universe::SetCMSSystem() {
  Vec Pges;
  Vec Rges;
  // Calculate velocity of CMS
  tMass msum = 0;
  for(ObjectIterator it=Objects.begin(); it!=Objects.end(); it++) {
    Pges += (*it)->Velocity()*(*it)->Mass();
    Rges += (*it)->Position()*(*it)->Mass();
    msum +=(*it)->Mass();
  }
  Pges /= msum;
  Rges /= msum;

  // add negative CMS-velocity to all objects (Galilei-Transformation)

  for(ObjectIterator it=Objects.begin(); it!=Objects.end(); it++) {
    (*it)->AddVelocity(-Pges);
    (*it)->AddPosition(-Rges);
  }
}

}
