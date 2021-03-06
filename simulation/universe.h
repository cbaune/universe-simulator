#ifndef UNIVERSE_H
#define UNIVERSE_H

#include "object.h"
#include <vector>
#include <iostream>
#include "types.h"
#include "constants.h"
#include "objectcontainer.h"
#include "forces/gravitation.h"

namespace simulation {

class Universe : public ObjectContainer {
public:
  Universe();
  ~Universe();
  void Simulate(tTime dt, unsigned int NumberOfTimeSteps);
  void Print(std::ostream& stream);
  void AddGravitationObject(Object* newobject);
  void SetCMSSystem();
private:
  forces::Gravitation grav;
};

}

#endif // UNIVERSE_H
