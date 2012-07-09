#include "vec.h"
#include <cmath>

namespace simulation {

Vec::Vec() {
  for(unsigned int i=0; i<nDim; i++)
    x[i]=0;
}

Vec::Vec(tPosition X, tPosition Y) {
  x[0]=X;
  x[1]=Y;
}

tPosition& Vec::operator [](unsigned int i){
  if(i>=nDim) return x[nDim-1];
  return x[i];
}

tPosition Vec::Abs() {
  return std::sqrt((*this) * (*this));
}

tPosition Vec::Dist(Vec v2) {
  return std::sqrt(SqDist(v2));
}

tPosition Vec::SqDist(Vec v2) {
  return (v2 - (*this)) * (v2 - (*this));
}

Vec Vec::DirectionTo(Vec v2, bool norm) {
  Vec er = v2 - (*this);
  if(norm)
    return er/Dist(v2);
  else
    return er;
}

Vec Vec::operator+(Vec v2) {
  Vec sum;
  for(unsigned int d=0; d<nDim; d++)
    sum[d] = this->x[d] + v2.x[d];
  return sum;
}

Vec Vec::operator-(Vec v2) {
  Vec diff;
  for(unsigned int d=0; d<nDim; d++)
    diff[d] = this->x[d] - v2.x[d];
  return diff;
}

Vec Vec::operator-() {
  Vec neg;
  return neg-(*this);
}

tPosition Vec::operator *(Vec v2) {
  tPosition prod = 0;
  for(unsigned int d=0; d<nDim; d++)
    prod += this->x[d]*v2.x[d];
  return prod;
}

Vec Vec::operator*(tPosition scale) {
  Vec scal;
  for(unsigned int d=0; d<nDim; d++)
    scal[d] = this->x[d]*scale;
  return scal;
}

Vec Vec::operator/(tPosition scale) {
  return operator*(1.0/scale);
}

}
