#ifndef COLLISION_H
#define COLLISION_H

#include <vector>
#include "../object.h"
#include "../vec.h"
#include "force.h"

namespace simulation {
namespace forces {

class Collision : public Force {
public:
    Collision();
    ~Collision();
  private:
    Vec Calculate(ObjectIterator Id1, ObjectIterator Id2);
};

}
}
#endif // COLLISION_H
