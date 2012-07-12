#include "game.h"

#include <iostream>
#include "../simulation/object.h"
#include <allegro5/allegro_primitives.h>
#include "../simulation/vec.h"
#include <sstream>

namespace ui {


void Game::MainLoop() {
  bool redraw = true;
  al_start_timer(timer);

  while (!done) {
    do{
      ALLEGRO_EVENT event;
      al_wait_for_event(event_queue, &event);

      if (event.type == ALLEGRO_EVENT_TIMER) {
        redraw = true;
        UpdateLogic();
      }
      else
        UserInput(event);

    } while(!al_is_event_queue_empty(event_queue));


    if (redraw) {
      redraw = false;
      al_clear_to_color(al_map_rgb(0, 0, 0));
      UpdateGraphics();
      al_flip_display();
    }
  }
}


void Game::UserInput(ALLEGRO_EVENT &event) {
  switch(event.type) {
    case ALLEGRO_EVENT_KEY_DOWN:
      switch(event.keyboard.keycode) {
        case ALLEGRO_KEY_ESCAPE:
          done = true;
          break;
        case ALLEGRO_KEY_MINUS:
          if(SimulationSteps > 0)
            --SimulationSteps;
          break;
        case ALLEGRO_KEY_CLOSEBRACE: // german plus
          ++SimulationSteps;
          break;
        case ALLEGRO_KEY_0:
          W->Follow(NULL);
          break;
        default:
          if((event.keyboard.keycode >= ALLEGRO_KEY_1) && (event.keyboard.keycode <= ALLEGRO_KEY_9))
            if((unsigned int)(event.keyboard.keycode-ALLEGRO_KEY_1) < U->Objects.size())
              W->Follow(U->Objects.at(event.keyboard.keycode-ALLEGRO_KEY_1));
          break;
      }
      break;

    case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
      if(event.mouse.button == 1)
        MoveWindow = true;
      break;
    case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
      if(event.mouse.button == 1)
        MoveWindow = false;
      break;

    case ALLEGRO_EVENT_MOUSE_AXES:
      W->ChangeZoom(event.mouse.dz);
      if(MoveWindow)
        W->MoveViewport(-event.mouse.dx, -event.mouse.dy);
      break;

    case ALLEGRO_EVENT_DISPLAY_CLOSE:
      done = true;
      break;

  }
}

void Game::UpdateLogic() {
  U->Simulate(60*60,SimulationSteps);
}

void Game::UpdateGraphics() {
   //std::cout << "Drawing Objects at";
  for(simulation::ObjectIterator it=U->Objects.begin(); it!=U->Objects.end(); it++) {
    // Draw object
    //float r =  (*it)->Radius()*RadiusScale;
    //if(r<1.0) r = 0.5;
    //simulation::Vec pos =  (*it)->Position();
    //simulation::Vec cms =  U->CenterOfMass();
    //float x = pos[0]*PositionScale + 400;
    //float y = -pos[1]*PositionScale + 300;
    float x = W->ScreenCoordX((*it)->Position());
    float y = W->ScreenCoordY((*it)->Position());
    float r = W->ScaledRadius((*it)->Radius());
    //std::cout << " " << x << ":" << y << ":" << r;

    al_draw_filled_circle(x ,y ,r ,al_map_rgb(255,255,0));
    if(r<1.0) {
      al_draw_circle(x, y, 5, al_map_rgb(128,128,64), 0.5);
    }
  }
  //std::cout << std::endl;

  std::stringstream spos;
  std::stringstream szoom;
  std::stringstream sspeed;
  spos << "Center of screen at x=" << W->GetViewX() << " and y=" << W->GetViewY();
  szoom << "Scale-Factor: " << W->GetZoom();
  sspeed << "Simulation Speed: " << SimulationSteps << " hours per Step";

  al_draw_textf(font, al_map_rgb(255,0,0), 10,50,ALLEGRO_ALIGN_LEFT, spos.str().c_str());
  al_draw_textf(font, al_map_rgb(255,0,0), 10,30,ALLEGRO_ALIGN_LEFT, szoom.str().c_str());
  al_draw_textf(font, al_map_rgb(255,0,0), 10,10,ALLEGRO_ALIGN_LEFT, sspeed.str().c_str());
  //al_draw_text(font, al_map_rgb(255,255,255), 640/2, (480/4),ALLEGRO_ALIGN_CENTRE, "Your Text Here!");
}

Game::Game() : done(false), SimulationSteps(24), MoveWindow(false) {}

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

  al_init_font_addon(); // initialize the font addon
  al_init_ttf_addon();// initialize the ttf (True Type Font) addon

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

  W = new Window(800,600);

  al_set_window_title(display, "Universe Simulator");

  font = al_load_ttf_font("/usr/share/fonts/TTF/cour.ttf",16,0 );

  if (!font)
    Abort("Could not load 'cour.ttf'");

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
