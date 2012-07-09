#ifndef PRESETS_H
#define PRESETS_H

#include "../simulation/types.h"
#include <map>

namespace preset {

enum Himmelskoerper {
  Sonne,
  Merkur,
  Venus,
  Erde,
  Mars,
  Jupiter,
  Saturn,
  Uranus,
  Neptun,
  Pluto,
  Mond,
  ISS,
  Apollo11
};

class PresetObject {
public:
  PresetObject();
  simulation::tMass Mass(Himmelskoerper);
  simulation::tPosition Radius(Himmelskoerper);
  simulation::tPosition Orbit_Radius(Himmelskoerper);
  simulation::tVelocity Velocity(Himmelskoerper);
  simulation::tTime Orbital_Period(Himmelskoerper);
private:
  std::map<Himmelskoerper, simulation::tMass> masses;
  std::map<Himmelskoerper, simulation::tPosition> radii;
  std::map<Himmelskoerper, simulation::tPosition> orbit_radii;
  std::map<Himmelskoerper, simulation::tTime> orbital_periods;
};

}

#endif // PRESETS_H
