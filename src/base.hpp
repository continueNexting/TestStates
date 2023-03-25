#ifndef BASECLASS_H
#define BASECLASS_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_net.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <unordered_map>
#include <vector>
#include <array>
#include <random>
#include <ranges>
#include <iostream>
#include <string>
#include <sstream>
#include <unistd.h>
#include <thread>
#include <chrono>


static int sdlInit = SDL_Init(SDL_INIT_EVERYTHING);

static int sdlMusic = Mix_Init(MIX_INIT_MP3);

static int sdlImg = IMG_Init(IMG_INIT_PNG); 
static int sdlTtf = TTF_Init();


static int widthW=1920;
static int heightW=1080;
      

class State
{
public:
  State();
  static bool running;
  virtual void enter() = 0;
  virtual void update() = 0;
  virtual void exit() = 0;
  
  static State *current;
  static State *mainMenu, *chat,*intro;
  static SDL_Window *window;
  static SDL_Renderer *ren;
  virtual ~State();
};
class MainMenu : public State
{
public:
  
  std::vector<SDL_FPoint> points;
  Mix_Music *music = NULL;
  bool run;
  MainMenu();
  void enter() override;
  void update() override;
  void exit() override;
  void show(std::vector<SDL_FPoint> points,std::vector<SDL_Rect> dest,SDL_Texture *text,SDL_Texture *text1, SDL_Renderer *renderer);
  void clear(std::vector<SDL_FPoint> *points,std::vector<SDL_Rect> *dest);
  void pixel(std::vector<SDL_FPoint> *points,std::vector<SDL_Rect> *dest,SDL_Surface *text_surf,SDL_Surface *text_surf1, float x, float y);

  virtual ~MainMenu();
};
class Chat :public State
{
public:

  bool run;
  Chat();
  void enter() override;
  void update() override;
  void exit() override;
  virtual ~Chat();
};
class Intro :public State
{
public:
  bool run;
  Intro();
  void enter() override;
  void update() override;
  void exit() override;
  virtual ~Intro();
};

#endif//BASE_HPP
