#include "gravitation.h"
#include <cmath>
#include "../constants.h"

namespace simulation {
namespace forces {

Gravitation::Gravitation() {}
Gravitation::~Gravitation() {}

Vec Gravitation::Calculate(ObjectIterator Id1, ObjectIterator Id2) {
  return (*Id1)->Position().DirectionTo((*Id2)->Position(), true) * (Grav_Const * (*Id1)->Mass() * (*Id2)->Mass() / (*Id1)->Position().SqDist((*Id2)->Position()));
}

}
}
