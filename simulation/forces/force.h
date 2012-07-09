#ifndef FORCE_H
#define FORCE_H

#include "../object.h"
#include "../objectcontainer.h"
#include "../types.h"
#include <vector>

namespace simulation {
namespace forces {

class Force : public ObjectContainer {
public:
  Force();
  virtual ~Force();
  void Act(tTime dt);
private:
  virtual Vec Calculate(std::vector<Object*>::iterator Id1, std::vector<Object*>::iterator Id2) = 0;

};

}
}

#endif // FORCE_H
