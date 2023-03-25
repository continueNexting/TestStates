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
// Это должно быть одно приложение, которое в зависимости от опций командной строки запускается либо как клиент, либо как сервер
// Если указан только порт, приложение запускается как сервер и слушает порт
// Если указан IP-адрес и порт, приложение запускается как клиент и коннектится к указанному серверу
// Как только соединение установлено, и клиент, и сервер могут писать друг другу сообщения в консоли, независимо друг от друга
// Когда кто-либо набирает в консоли “exit”, соединение закрывается и приложения заканчивают работу.
// Нужны юнит-тесты
static int k = SDL_Init(SDL_INIT_EVERYTHING);
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

class Text
{
public:
  const char *pFileFont;

  SDL_Surface *buffer;

  int fSize = 20;
  TTF_Font *font;
  std::string texts;
  SDL_Color foreground;
  SDL_Texture *text;
  SDL_Surface *text_surf;
  SDL_Rect dest;
  uint8_t fR = 0;
  uint8_t fG = 255;
  uint8_t fB = 255;
  uint8_t fA = 255;

  uint8_t bR = 255;
  uint8_t bG = 255;
  uint8_t bB = 255;
  uint8_t bA = 255;

  Text();

  void init(SDL_Window *window, SDL_Renderer *ren);
  void draw(SDL_Renderer *ren);

  void clears(SDL_Renderer *ren);
  void close();
  ~Text();
};

#endif//BASE_HPP
