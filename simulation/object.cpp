#include "object.h"
#include <iostream>
#include <limits>

namespace simulation {

Object::Object(tMass m, tPosition rad, Vec pos, Vec vel, tElasticity ela, bool fix): mass(m), radius(rad), position(pos), velocity(vel), elasticity(ela), fixed(fix) {}
Object::Object(tMass m, tPosition rad, Vec pos, Vec vel): mass(m), radius(rad), position(pos), velocity(vel), elasticity(1), fixed(false) {}

void Object::ApplyForce(Vec F, tTime dt) {
  for(unsigned int i=0; i<nDim; i++)
    velocity[i] += F[i]/mass*dt;
}

void Object::Propagate(tTime dt) {
  for(unsigned int i=0; i<nDim; i++)
    position[i] += velocity[i]*dt;
}

void Object::Merge(Object *target) {
  // recalculate velocity:
  for(unsigned int i=0; i<nDim; i++)
    velocity[i] = ( (mass*velocity[i]) + (target->mass*target->velocity[i]) ) / (mass + target->mass);
  mass+=target->mass;
  delete target;
}

tMass Object::Mass() {
  return mass;
}

tPosition Object::Radius() {
  return radius;
}


Vec Object::Position() {
  return position;
}

Vec Object::Velocity() {
  return velocity;
}

void Object::AddVelocity(Vec newvel) {
  velocity += newvel;
}

void Object::AddPosition(Vec newpos) {
  position += newpos;
}

tElasticity Object::Elasticity() {
  return elasticity;
}

void Object::Print(std::ostream &stream) {
  stream << position[0] << " " << position[1];
}

}
