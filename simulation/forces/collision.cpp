#include "collision.h"

namespace simulation {
namespace forces {

Collision::Collision() {}
Collision::~Collision() {}

Vec Collision::Calculate(ObjectIterator Id1, ObjectIterator Id2) {
    tPosition Distance = (*Id1)->Position().DirectionTo((*Id2)->Position(), false).Abs();
    tPosition Radii = (*Id1)->Radius() + (*Id2)->Radius();
    if(Distance < Radii) { // Colision detected
        tElasticity elastSum = (*Id1)->Elasticity() * (*Id2)->Elasticity();
        if(elastSum < 0.5) { // inelastic
            (*Id1)->Merge(*Id2);
        } else { // elastic
            Vec ForceDirection = -(*Id1)->Position().DirectionTo((*Id2)->Position(), true) * ((*Id1)->Position().DirectionTo((*Id2)->Position(), true) * (*Id1)->Velocity());
            ForceDirection = ForceDirection / (*Id1)->Mass();

        }
    }
    return Vec(0,0);
}


}
}
