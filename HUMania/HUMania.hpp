#include<SDL.h>


void drawObjects(SDL_Renderer* gRnderer, SDL_Texture* assets);
void createObject(int x, int y);

struct Unit{
    SDL_Rect srcRect, moverRect;
};

struct Animal {
    Unit animal;
    int state;
};

struct Animation {
    Unit animation1, animation2, animation3;
};
