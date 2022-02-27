#include <SDL.h>

void drawObjects(SDL_Renderer *gRnderer, SDL_Texture *assets);
void createObject(int x, int y);
/**
 * ? @brief Unit
 * * contains SDL src and movement pixels
 */
struct Unit
{
    SDL_Rect srcRect, moverRect;
};

/**
 * ? @brief Animal
 * * contains Unit struct and state of animal ( 3 states as there are three srcs )
 */
struct Animal
{
    Unit animal;
    int state;
};

/**
 * ? @brief Animation
 * * contains 3 animation pixels or Unit structs
 */
struct Animation
{
    Unit animation1, animation2, animation3;
};
