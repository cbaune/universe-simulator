#include "force.h"
#include <algorithm>


namespace simulation {
namespace forces {

Force::Force() {}

Force::~Force() {}

void Force::Act(tTime dt) {
  for(ObjectIterator i1 = Objects.begin(); i1!=Objects.end(); i1++) {
    for(ObjectIterator i2 = i1+1; i2!=Objects.end(); i2++) {
      Vec F = Calculate(i1,i2);
      (*i1)->ApplyForce(F, dt);
      (*i2)->ApplyForce(-F, dt);
    }
  }
}

}
}
