#ifndef GAME_H
#define GAME_H

#include <allegro5/allegro5.h>
#include "../simulation/universe.h"

namespace ui {

class Game
{
public:
  Game();
  ~Game();
  void Initialize(simulation::Universe* universe);
  void MainLoop();
  void Shutdown();
  void Abort(const char* Message);
private:
  simulation::Universe* U;
  ALLEGRO_EVENT_QUEUE* event_queue;
  ALLEGRO_TIMER* timer;
  ALLEGRO_DISPLAY* display;
  bool done;
  void UpdateLogic();
  void UpdateGraphics();
};

}

#endif // GAME_H
