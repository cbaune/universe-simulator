#ifndef GRAVITATION_H
#define GRAVITATION_H

#include "../vec.h"
#include "../object.h"
#include "force.h"
#include <vector>

namespace simulation {
namespace forces {

class Gravitation : public Force {
public:
  Gravitation();
  ~Gravitation();
private:
  Vec Calculate(ObjectIterator Id1, ObjectIterator Id2);
};

}
}

#endif // GRAVITATION_H
