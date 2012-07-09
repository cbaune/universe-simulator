#include <iostream>

#include "simulation/universe.h"
#include "simulation/vec.h"
#include <fstream>
#include "simulation/constants.h"
#include "preset/presetobject.h"

using namespace std;
int main()
{
  cout << "Hello World!" << endl;

  // Objekte erstellen:
  preset::PresetObject p;

  simulation::Object Sonne(p.Mass(preset::Sonne),
                       p.Radius(preset::Sonne),
                       simulation::Vec(0,0),
                       simulation::Vec(0,0));

  simulation::Object Erde(p.Mass(preset::Erde),
                      p.Radius(preset::Erde),
                      simulation::Vec(p.Orbit_Radius(preset::Erde),0),
                      simulation::Vec(0,p.Velocity(preset::Erde)));

  simulation::Object Merkur(p.Mass(preset::Merkur),
                        p.Radius(preset::Merkur),
                        simulation::Vec(p.Orbit_Radius(preset::Merkur),0),
                        simulation::Vec(0,p.Velocity(preset::Merkur)));

  simulation::Object Venus(p.Mass(preset::Venus),
                       p.Radius(preset::Venus),
                       simulation::Vec(p.Orbit_Radius(preset::Venus),0),
                       simulation::Vec(0,p.Velocity(preset::Venus)));

  simulation::Object Mond(p.Mass(preset::Mond),
                      p.Radius(preset::Mond),
                      simulation::Vec(p.Orbit_Radius(preset::Erde) + p.Orbit_Radius(preset::Mond),0),
                      simulation::Vec(0,p.Velocity(preset::Erde) + p.Velocity(preset::Mond)));

  simulation::Object Mars(p.Mass(preset::Mars),
                      p.Radius(preset::Mars),
                       simulation::Vec(p.Orbit_Radius(preset::Mars),0),
                       simulation::Vec(0,p.Velocity(preset::Mars)));

  simulation::Object Jupiter(p.Mass(preset::Jupiter),
                         p.Radius(preset::Jupiter),
                       simulation::Vec(p.Orbit_Radius(preset::Jupiter),0),
                       simulation::Vec(0,p.Velocity(preset::Jupiter)));

  simulation::Object Saturn(p.Mass(preset::Saturn),
                        p.Radius(preset::Saturn),
                       simulation::Vec(p.Orbit_Radius(preset::Saturn),0),
                       simulation::Vec(0,p.Velocity(preset::Saturn)));

  simulation::Object Uranus(p.Mass(preset::Uranus),
                        p.Radius(preset::Uranus),
                       simulation::Vec(p.Orbit_Radius(preset::Uranus),0),
                       simulation::Vec(0,p.Velocity(preset::Uranus)));

  simulation::Object Neptun(p.Mass(preset::Neptun),
                        p.Radius(preset::Neptun),
                       simulation::Vec(p.Orbit_Radius(preset::Neptun),0),
                       simulation::Vec(0,p.Velocity(preset::Neptun)));

  simulation::Object Pluto(p.Mass(preset::Pluto),
                       p.Radius(preset::Pluto),
                       simulation::Vec(p.Orbit_Radius(preset::Pluto),0),
                       simulation::Vec(0,p.Velocity(preset::Pluto)));



  simulation::Object Sonne2(p.Mass(preset::Sonne),
                        p.Radius(preset::Sonne),
                        simulation::Vec(p.Orbit_Radius(preset::Jupiter),0),
                        simulation::Vec(0,p.Velocity(preset::Jupiter)));

  simulation::Object Erde2(p.Mass(preset::Sonne),
                       p.Radius(preset::Sonne),
                       simulation::Vec(p.Orbit_Radius(preset::Erde) + p.Orbit_Radius(preset::Mond),0),
                       simulation::Vec(0,p.Velocity(preset::Erde) + p.Velocity(preset::Mond)));


  simulation::Universe U;

  U.AddGravitationObject(&Sonne);
  U.AddGravitationObject(&Erde);
  U.AddGravitationObject(&Venus);
  U.AddGravitationObject(&Merkur);
  U.AddGravitationObject(&Mond);
  U.AddGravitationObject(&Mars);
  U.AddGravitationObject(&Sonne2);
  /*U.AddObject(Jupiter);
  U.AddObject(Saturn);
  U.AddObject(Uranus);
  U.AddObject(Neptun);
  U.AddObject(Pluto);*/
  //U.AddObject(Erde2);


  // Simulieren:

  const long Simulate_Step = 60; // Schrittgröße beim Simulieren (in Sekunden)
  const long Record_Steps = 24*60; // Nach Wievielen Schritten Daten speichern?
  const long Simulation_Days = 1e4; // Simulationsdauer in Tagen


  int dmax = Simulation_Days*24*60*60/Record_Steps/Simulate_Step;

  std::cout << "Simulating " << Simulation_Days << " days in " << dmax << " Steps ..." << std::endl;

  fstream file;
  file.open("out.dat",ios_base::out);

  for(int d=0; d<dmax; d++) {
    for(int s=0; s<Record_Steps; s++) {
      U.Simulate(Simulate_Step);
    }
    if(d%100==0)
      std::cout << " " << (d+1)*100.0/dmax << " %" << std::endl;
    U.Print(file);
  }

  file.close();
  std::cout << "Done." << std::endl;
  return 0;
}

