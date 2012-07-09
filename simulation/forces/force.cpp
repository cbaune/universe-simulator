#include "force.h"
#include <algorithm>


namespace simulation {
namespace forces {

Force::Force() {}

Force::~Force() {}

void Force::Act(tTime dt) {
  for(std::vector<Object*>::iterator i1 = Objects.begin(); i1!=Objects.end(); i1++) {
    for(std::vector<Object*>::iterator i2 = i1+1; i2!=Objects.end(); i2++) {
      Vec F = Calculate(i1,i2);
      (*i1)->ApplyForce(F, dt);
      (*i2)->ApplyForce(-F, dt);
    }
  }
}

}
}
