#ifndef VEC_H
#define VEC_H

#include "types.h"

namespace simulation {

const unsigned int nDim = 2;

// A usual nDim-dimensional vector
class Vec {
public:
  Vec();
  Vec(tPosition X, tPosition Y);
  tPosition& operator[](unsigned int i);
  tPosition Abs();
  tPosition Dist(Vec v2);
  tPosition SqDist(Vec v2);
  Vec DirectionTo(Vec v2, bool norm=true);
  Vec operator+(Vec v2);
  Vec operator-(Vec v2);
  Vec operator-();
  tPosition operator*(Vec v2);
  Vec operator*(tPosition scale);
  Vec operator/(tPosition scale);
  void operator+=(Vec v2);
  void operator-=(Vec v2);
  void operator*=(tPosition scale);
  void operator/=(tPosition scale);


private:
  tPosition x[nDim];
};

}

#endif // VEC_H
