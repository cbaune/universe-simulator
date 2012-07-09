#include "gravitation.h"
#include <cmath>
#include "../constants.h"

namespace simulation {
namespace forces {

Gravitation::Gravitation() {}
Gravitation::~Gravitation() {}

Vec Gravitation::Calculate(std::vector<Object*>::iterator Id1, std::vector<Object*>::iterator Id2) {
  return (*Id1)->Position().DirectionTo((*Id2)->Position(), true) * (Grav_Const * (*Id1)->Mass() * (*Id2)->Mass() / (*Id1)->Position().SqDist((*Id2)->Position()));
}

}
}
