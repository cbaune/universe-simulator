#include "game.h"

#include <iostream>
#include "../simulation/object.h"
#include <allegro5/allegro_primitives.h>
#include "../simulation/vec.h"

namespace ui {


void Game::MainLoop() {
  bool redraw = true;
  al_start_timer(timer);

  while (!done) {
    ALLEGRO_EVENT event;
    al_wait_for_event(event_queue, &event);

    if (event.type == ALLEGRO_EVENT_TIMER) {
      redraw = true;
      UpdateLogic();
    }
    else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
      switch(event.keyboard.keycode) {
        case ALLEGRO_KEY_ESCAPE:
          done = true;
          break;
        case ALLEGRO_KEY_MINUS:
          if(SimulationSteps > 1)
            std::cout << "Simulation-Steps: " << --SimulationSteps << std::endl;
          break;
        case ALLEGRO_KEY_CLOSEBRACE: // german plus
          std::cout << "Simulation-Steps: " << ++SimulationSteps << std::endl;
          break;
      }

      //get_user_input();
    }
    else if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
      RadiusScale += RadiusScale/10 * event.mouse.dz;
      PositionScale += PositionScale/10 * event.mouse.dz;
    }

    if (redraw && al_is_event_queue_empty(event_queue)) {
      redraw = false;
      al_clear_to_color(al_map_rgb(0, 0, 0));
      UpdateGraphics();
      al_flip_display();
    }
  }
}


void Game::UpdateLogic() {
  U->Simulate(60*60,24*SimulationSteps);
}

void Game::UpdateGraphics() {
  // std::cout << "Drawing Objects at";
  for(simulation::ObjectIterator it=U->Objects.begin(); it!=U->Objects.end(); it++) {
    // Draw object
    float r =  (*it)->Radius()*RadiusScale;
    if(r<1.0) r = 2;
    simulation::Vec pos =  (*it)->Position();
    //simulation::Vec cms =  U->CenterOfMass();
    float x = pos[0]*PositionScale + 400;
    float y = -pos[1]*PositionScale + 300;
    //std::cout << " " << x << ":" << y << ":" << r;
    al_draw_filled_circle(x,y,r,al_map_rgb(255,255,0));
  }
  // std::cout << std::endl;
}


Game::Game() : done(false), SimulationSteps(1), RadiusScale(5e-8), PositionScale(5e-10) {}

Game::~Game() {}

void Game::Initialize(simulation::Universe *universe) {
  if(universe==NULL)
    Abort("Invalid universe-data");
  U = universe;

  if (!al_init())
    Abort("Failed to initialize allegro");

  if(!al_init_primitives_addon())
    Abort("Failed to initialize allegro-primitives");

  if (!al_install_keyboard())
    Abort("Failed to install keyboard");

  if(!al_install_mouse())
     Abort("failed to initialize the mouse!");

  timer = al_create_timer(1.0 / 30);
  if (!timer)
    Abort("Failed to create timer");

  al_set_new_display_option(ALLEGRO_VSYNC, 1, ALLEGRO_SUGGEST);
  al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
  al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);

  al_set_new_display_flags(ALLEGRO_WINDOWED);
  display = al_create_display(800, 600);
  if (!display)
    Abort("Failed to create display");

  al_set_window_title(display, "Universe Simulator");

  event_queue = al_create_event_queue();
  if (!event_queue)
    Abort("Failed to create event queue");

  al_register_event_source(event_queue, al_get_keyboard_event_source());
  al_register_event_source(event_queue, al_get_mouse_event_source());
  al_register_event_source(event_queue, al_get_timer_event_source(timer));
  al_register_event_source(event_queue, al_get_display_event_source(display));
}

void Game::Abort(const char *Message) {
  std::cout << std::endl << Message << std::endl;
  exit(1);
}

void Game::Shutdown() {
  if (timer)
    al_destroy_timer(timer);

  if (display)
    al_destroy_display(display);

  if (event_queue)
    al_destroy_event_queue(event_queue);
}

}
