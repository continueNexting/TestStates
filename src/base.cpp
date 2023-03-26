#include "base.hpp"

SDL_Window* State::window = SDL_CreateWindow("chatTest", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, widthW, heightW, SDL_WINDOW_SHOWN);
SDL_Renderer* State::ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
State * State::mainMenu = new MainMenu;
State * State::chat = new Chat;
State * State::intro = new Intro;
State * State::current = State::mainMenu;
bool State::running = false;

State::State() {

}
State::~State() {}
MainMenu::MainMenu(){}
void MainMenu::enter() {
  run=false;
}
struct vec3
{
    float x, y, z;
};
inline void MainMenu::update()
{

    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096);
    music = Mix_LoadMUS("/home/jimmy/out.mp3");

    Mix_VolumeMusic(NULL);
    Mix_SetMusicCMD(SDL_getenv("MUSIC_CMD"));
    Mix_FadeInMusic(music, 0, 2000);
    const char *pFileFont="/home/jimmy/Downloads/Noto_Sans_KR/NotoSansKR-Black.otf";

    SDL_Surface *buffer;

    int fSize = 25;
    TTF_Font *font;
    std::string texts,texts1;
    SDL_Color foreground;
    SDL_Texture *text,*text1;
    SDL_Surface *text_surf;
    SDL_Surface *text_surf1;
    std::vector<SDL_Rect> dest;
    uint8_t fR = 19;
    uint8_t fG = 100;
    uint8_t fB = 30;
    uint8_t fA = 255;

    uint8_t bR = 255;
    uint8_t bG = 255;
    uint8_t bB = 255;
    uint8_t bA = 255;

//     "
//    ン
//     30F3
//     ワ
//     30EF
//     ラ
//     30E9
//     ヤ
//     30E4
//     マ
//     30DE
//     ハ
//     30CF
//     ナ
//     30CA
//     タ
//     30BF
//     サ
//     30B5
//     カ
//     30AB
//     ア
//     30A2
//     リ
//     30EA
//     ミ
//     30DF
//     ヒ
//     30D2
//     ニ
//     30CB
//     チ
//     30C1
//     シ
//     30B7
//     キ
//     30AD
//     イ
//     30A4
//     ル
//     30EB
//     ユ
//     30E6
//     ム
//     30E0
//     フ
//     30D5
//     ヌ
//     30CC
//     ツ
//     30C4
//     ス
//     30B9
//     ク
//     30AF
//     ウ
//     30A6
//     レ
//     30EC
//     メ
//     30E1
//     ヘ
//     30D8
//     ネ
//     30CD
//     テ
//     30C6
//     セ
//     30BB
//     ケ
//     30B1
//     エ
//     30A8
//     ヲ
//     30F2
//     ロ
//     30ED
//     ヨ
//     30E8
//     モ
//     30E2
//     ホ
//     30DB
//     ノ
//     30CE
//     ト
//     30C8
//     ソ
//     30BD
//     コ
//     //30B3
//     オ
//     //30AA

// "

    ///usr/share/fonts/truetype/ubuntu/Ubuntu-B.ttf
    ///home/jimmy/Downloads/Noto_Sans_KR/NotoSansKR-Light.otf
    pFileFont = "/home/jimmy/Downloads/Noto_Sans_JP/NotoSansJP-Bold.otf";
    buffer= SDL_GetWindowSurface(window);
    SDL_FreeSurface(buffer);
    buffer=NULL;
    font=TTF_OpenFont(pFileFont,fSize);
    foreground = {fR, fG, fB};
    texts+="ンオコソトノホ";

    texts1 += "モ";

    std::vector<vec3> point;
    srand(time(NULL));
    for (int var = 0; var < 3150; ++var)
    {

      SDL_Rect rect;
      rect.y=0;
      rect.x= rand() % 1920;
      rect.w=22;
      rect.h=29;
      SDL_Rect rect1;
      rect1.y=0;
      rect1.x= rand() % 1920;
      rect1.w=22;
      rect1.h=29;
      vec3 x;
      x.x = (rand() % widthW - widthW / 2);
      x.y = 740;
      x.z = (rand() % widthW - widthW / 2);
      point.push_back(x);
      dest.push_back(rect);
      if(var%7==0)dest.push_back(rect1);

    }
    vec3 c{0, 0, 0};
    for (auto &p : point)
    {
      c.x += p.x;
      c.y += p.y;
      c.z += p.z;
    }
    c.x /= point.size();
    c.y /= point.size();
    c.z /= point.size();
    int count=0;


    
    while (!run)
    {
      SDL_Event e;
      SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
      foreground = {fR, fG, fB};
      text_surf = TTF_RenderUTF8_Blended_Wrapped(font, texts.c_str(), foreground, 22);
      text = SDL_CreateTextureFromSurface(ren, text_surf);
      foreground = {255, 255, 255,255};
      text_surf1 = TTF_RenderUTF8_Blended_Wrapped(font, texts1.c_str(), foreground, 22);
      text1 = SDL_CreateTextureFromSurface(ren, text_surf1);


      for (auto &p : point)
      {

        p.z += (rand() % 10)+1;
        if (p.z > widthW)
        {
          p.z = 0;
        }

        float sx = (p.x / p.y) * widthW + widthW / 2;
        float sy = (p.z / p.y) * heightW - heightW / 2;

        pixel(&points,&dest,text_surf,text_surf1, sx, sy);
        
      }
      show(points, dest,text,text1,ren);

      clear(&points,&dest);

      while (SDL_PollEvent(&e))
      {
        switch (e.type)
        {
        case SDL_QUIT:
          run = true;
          exit();
          break;
        }
      }
      auto key = SDL_GetKeyboardState(NULL);
      if (key[SDL_SCANCODE_ESCAPE])
      {
        run = true;
        exit();
        break;
      }
      if (key[SDL_SCANCODE_1])
      {
        current=chat;
        run = true;
        break;
      }

    SDL_FreeSurface(text_surf);
    SDL_FreeSurface(text_surf1);

  }
}
void MainMenu::exit()
{
  ren=NULL;
  SDL_DestroyRenderer(ren);
  window=NULL;
  SDL_DestroyWindow(window);
  SDL_Quit();
  running=true;
}
MainMenu::~MainMenu(){}
void MainMenu::show(std::vector<SDL_FPoint> points, std::vector<SDL_Rect> dest,SDL_Texture *text,SDL_Texture *text1,SDL_Renderer *renderer)
{
  SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
  SDL_RenderClear(ren);
  SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
  int count =0;
  for (auto &point : points)
  {

    SDL_RenderDrawPointF(ren, point.x, point.y);
    SDL_RenderCopy(ren, text, NULL, &dest[count++]);
    SDL_RenderCopy(ren, text1, NULL, &dest[count++]);

  }
  SDL_DestroyTexture(text);
  SDL_DestroyTexture(text1);
  SDL_RenderPresent(ren);
}
void MainMenu::clear(std::vector<SDL_FPoint> *points,std::vector<SDL_Rect> *dest)
{
  points->clear();
  dest->clear();
}
void MainMenu::pixel(std::vector<SDL_FPoint> *points,std::vector<SDL_Rect> *dest, SDL_Surface *text_surf,SDL_Surface *text_surf1,float x, float y)
{
  SDL_FPoint i;
  i.x = x;
  i.y = y;
  SDL_Rect rect;
  rect.y = y;
  rect.x = x;
  rect.w = text_surf->w;
  rect.h = text_surf->h;
  dest->push_back(rect);
  SDL_Rect rect1;
  rect1.y = y+260;
  rect1.x = x;
  rect1.w = text_surf1->w;
  rect1.h = text_surf1->h;

  points->push_back(i);
  dest->push_back(rect1);
}
Chat::Chat() {}
void Chat::enter() {
  run=false;
}
inline void Chat::update()
{
  while (!run)
  {
    SDL_Event e;
    SDL_SetRenderDrawColor(ren, 0, 255, 2, 255);

    while (SDL_PollEvent(&e)!=0)
    {
      switch (e.type)
      {
      case SDL_QUIT:
        run = true;
        exit();
        break;
      }
    }
    SDL_Log("chat");
    auto key = SDL_GetKeyboardState(NULL);
    if (key[SDL_SCANCODE_ESCAPE])
    {
        run = true;
        exit();
        break;
    }
    if (key[SDL_SCANCODE_2])
    {
        current=mainMenu;
        run = true;
        break;
    }
    SDL_RenderClear(ren);
    SDL_Rect rect{0, 0, widthW, heightW};
    SDL_RenderCopy(ren, NULL, NULL, &rect);
    SDL_RenderPresent(ren);
  }
}
void Chat::exit()
{
  ren=NULL;
  SDL_DestroyRenderer(ren);
  window=NULL;
  SDL_DestroyWindow(window);
  SDL_Quit();
  running=true;
}
Chat::~Chat() {}
Intro::Intro() {}
void Intro::enter() {}
void Intro::update()
{
  while (!run)
  {
    SDL_Event e;
    SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);
    while (SDL_PollEvent(&e))
    {
      switch (e.type)
      {
      case SDL_QUIT:
        run = true;
        exit();
        break;
      }
    }
      auto key = SDL_GetKeyboardState(NULL);
      if (key[SDL_SCANCODE_ESCAPE])
      {
        run = true;
        exit();
        break;
      }
      if (key[SDL_SCANCODE_SPACE])
      {
        current=mainMenu;
        run = true;
        break;
      }
    
    SDL_Log("intro");
    SDL_RenderClear(ren);
    SDL_Rect rect{0, 0, widthW, heightW};
    SDL_RenderCopy(ren, NULL, NULL, &rect);
    SDL_RenderPresent(ren);
  }
}
void Intro::exit() 
{
  ren=NULL;
  SDL_DestroyRenderer(ren);
  window=NULL;
  SDL_DestroyWindow(window);
  SDL_Quit();
  running=true;
}
Intro::~Intro() {}



