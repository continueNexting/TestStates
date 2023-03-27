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
// class LineWord {
// public:
// int fSize=22;

// SDL_Color foregraundGreen={19,100,30,255};
// SDL_Color foregraundWhite={255,255,255,255};

// std::string kata="ンワラヤマハナタサカアリミヒニチシキイルユムフヌツスクウレメヘネテセケエヲロヨモホノトソコオ";//46
// std::string hira="かきくけこさしすせそたちつてとなにぬねのはひふへほまみむめもやゆよらりるれろわをんがぎぐげござじずぜぞだぢづでどばびぶべぼぱぴぷぺぽゃゅょ";//69
// TTF_Font *font;

// std::string texts;
// std::string textHead;

// SDL_Texture *text;
// SDL_Surface *text_surf;
// SDL_Texture *text1;
// SDL_Surface *text_surf1;

// SDL_Rect destBuddy;
// SDL_Rect destHead;
// int tick = 0,tick1=0,tick2=0,tick3=0,tick4=0,tick5=0,tick6=0,tick7=0;
// LineWord(){}
// void init(TTF_Font *fonts,SDL_Renderer *ren){
//   font=fonts;

// }
// void renderLine(SDL_Renderer *ren){
//  if(tick==10){
//    textHead.clear();
//    int luck=3*(rand()%22);
//    textHead.push_back(hira.c_str()[luck]);
//    textHead.push_back(hira.c_str()[++luck]);
//    textHead.push_back(hira.c_str()[++luck]);
//    textHead.push_back('\0');
//    tick=0;     
//  }
//  if(tick1==30){
//    int luck=3*(rand()%22);
//    texts[18]=(hira.c_str()[luck]);
//    texts[19]=(hira.c_str()[++luck]);
//    texts[20]=(hira.c_str()[++luck]);
//    tick1=0;     
//  }
//  if(tick2==50){
//    int luck=3*(rand()%22);
//    texts[15]=(hira.c_str()[luck]);
//    texts[16]=(hira.c_str()[++luck]);
//    texts[17]=(hira.c_str()[++luck]);
//    tick2=0;     
//  }
//  if(tick3==70){
//    int luck=3*(rand()%22);
//    texts[12]=(hira.c_str()[luck]);
//    texts[13]=(hira.c_str()[++luck]);
//    texts[14]=(hira.c_str()[++luck]);
//    tick3=0;     
//  }
//  if(tick4==90){
//    int luck=3*(rand()%22);
//    texts[9]=(hira.c_str()[luck]);
//    texts[10]=(hira.c_str()[++luck]);
//    texts[11]=(hira.c_str()[++luck]);
//    tick4=0;     
//  }
//  if(tick5==110){
//   int luck=3*(rand()%22);
//   texts[6]=(hira.c_str()[luck]);
//   texts[7]=(hira.c_str()[++luck]);
//   texts[8]=(hira.c_str()[++luck]);
//   tick5=0;     
//  }
//  if(tick6==130){
//   int luck=3*(rand()%22);
//   texts[3]=(hira.c_str()[luck]);
//   texts[4]=(hira.c_str()[++luck]);
//   texts[5]=(hira.c_str()[++luck]);
//   tick6=0;     
//  }
//  if(tick7==150){
//   int luck=3*(rand()%22);
//   texts[0]=(hira.c_str()[luck]);
//   texts[1]=(hira.c_str()[++luck]);
//   texts[2]=(hira.c_str()[++luck]);
//   tick7=0;     
//  }
//  text_surf=TTF_RenderUTF8_Blended_Wrapped(font,(const char*)texts.c_str(),foregraundGreen,fSize);
//  text = SDL_CreateTextureFromSurface(ren,text_surf);
 
//  text_surf1=TTF_RenderUTF8_Blended_Wrapped(font,(const char*)textHead.c_str(),foregraundWhite,fSize);
//  text1 = SDL_CreateTextureFromSurface(ren,text_surf1);
// }

// void FreeRess(){
//  tick++;tick1++;tick2++;tick3++;tick4++;tick5++;tick6++;tick7++;
//  SDL_FreeSurface(text_surf);
//  SDL_FreeSurface(text_surf1);
// }
// virtual ~LineWord(){}
// };

#endif//BASE_HPP
