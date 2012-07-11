#include "presetobject.h"

#include "../simulation/constants.h"

namespace preset {

simulation::tMass PresetObject::Mass(Himmelskoerper objekt) {
  return masses[objekt];
}

simulation::tPosition PresetObject::Radius(Himmelskoerper objekt) {
  return radii[objekt];
}

simulation::tPosition PresetObject::Orbit_Radius(Himmelskoerper objekt) {
  return orbit_radii[objekt];
}

simulation::tTime PresetObject::Orbital_Period(Himmelskoerper objekt) {
  return orbital_periods[objekt];
}

simulation::tVelocity PresetObject::Velocity(Himmelskoerper objekt) {
  if(orbital_periods[objekt]==0)
    return 0;
  else
    return 2*Pi*orbit_radii[objekt]/orbital_periods[objekt];
}

PresetObject::PresetObject() {

  // Sun, Moon and ISS from Wikipedia,
  // Planets from http://nssdc.gsfc.nasa.gov/planetary/factsheet/
  // Apollo11 from somwhere on the web

  masses[Sonne] = 1.989e30;
  radii[Sonne] = 1.392e9/2;
  orbit_radii[Sonne] = 0;
  orbital_periods[Sonne] = 0;

  masses[Merkur] = 0.33e24;
  radii[Merkur] = 4879e3/2;
  orbit_radii[Merkur] = 57.9e9;
  orbital_periods[Merkur] = 88.0*24*60*60;

  masses[Venus] = 4.87e24;
  radii[Venus] = 12104e3/2;
  orbit_radii[Venus] = 108.2e9;
  orbital_periods[Venus] = 224.7*24*60*60;

  masses[Erde] = 5.97e24;
  radii[Erde] = 12756e3/2;
  orbit_radii[Erde] = 149.6e9;
  orbital_periods[Erde] = 365.2*24*60*60;

  masses[Mars] = 0.642e24;
  radii[Mars] = 6792e3/2;
  orbit_radii[Mars] = 227.9e9;
  orbital_periods[Mars] = 687.0*24*60*60;

  masses[Jupiter] = 1899e24;
  radii[Jupiter] = 142984e3/2;
  orbit_radii[Jupiter] = 778.6e9;
  orbital_periods[Jupiter] = 4331*24*60*60;

  masses[Saturn] = 568e24;
  radii[Saturn] = 120536e3/2;
  orbit_radii[Saturn] = 1433.5e9;
  orbital_periods[Saturn] = 10747*24*60*60;

  masses[Uranus] = 86.8e24;
  radii[Uranus] = 51118e3/2;
  orbit_radii[Uranus] = 2872.5e9;
  orbital_periods[Uranus] = 30589.0*24*60*60;

  masses[Neptun] = 102e24;
  radii[Neptun] = 49528e3/2;
  orbit_radii[Neptun] = 4495.1e9;
  orbital_periods[Neptun] = 59800.0*24*60*60;

  masses[Pluto] = 0.0125e24;
  radii[Pluto] = 2390e3/2;
  orbit_radii[Pluto] = 5870.0e9;
  orbital_periods[Pluto] = 90588.0*24*60*60;

  masses[Mond] = 7.349e22;
  radii[Mond] = 3476e3/2;
  orbit_radii[Mond] = 3.844e8;
  orbital_periods[Mond] = 27.3217*24*60*60;

  masses[ISS] = 450e3;
  radii[ISS] = 108.5/2;
  orbit_radii[ISS] = radii[Erde] + (394 + 405)/2*1e3;
  orbital_periods[ISS] = 92*60 + 33;

  masses[Apollo11] = (5.560 + 23.243 + 15.095)*1e3;
  radii[Apollo11] = (5.5 + 11.03)/2;
  orbit_radii[Apollo11] = 110e3;
  orbital_periods[Apollo11] = 2*60*60;


}
}
