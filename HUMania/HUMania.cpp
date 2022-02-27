// ? imports
#include <iostream>
#include <vector>

// ? header files
#include "HUMania.hpp"

// ? namespaces
using namespace std;

// ! -------------- Global Objects
Unit pigeon1 = {{7, 88, 155, 103}, {30, 40, 50, 50}};
Unit butterfly1 = {{257, 24, 173, 134}, {30, 40, 50, 50}};
Unit bee1 = {{527, 138, 194, 115}, {30, 40, 50, 50}};
Unit pigeon2 = {{0, 237, 153, 84}, {30, 40, 50, 50}};
Unit pigeon3 = {{2, 361, 159, 124}, {30, 40, 50, 50}};
Unit butterfly2 = {{257, 182, 192, 214}, {30, 40, 50, 50}};
Unit butterfly3 = {{248, 432, 248, 179}, {30, 40, 50, 50}};
Unit bee2 = {{527, 243, 194, 116}, {30, 40, 50, 50}};
Unit bee3 = {{540, 370, 193, 115}, {30, 40, 50, 50}};

// ! -------------- Global Vectors of Objects
vector<Animal> pigeons;
vector<Animal> bees;
vector<Animal> butterflies;

// ? Animals and Animation struct defined in header file

/**
 * ? @brief animateObject
 * * animates animals by changes the srcs to 3 different states
 * * and by moving the animal to right side of screen and then reset it back to left side
 *
 * ? @param animal
 * * Animal structure which contains animal attrubutes like src pixel code and state
 *
 *
 * ? @param animations
 * * Animation struct which contains 3 states (pixels) of every animals
 *
 *
 * ! @return void
 */
void animateObject(Animal &animal, Animation animations)
{
    // * switch case to initialize animation
    // * takes state variable to 1 2 3 to initialize 3 different states of animals
    switch (animal.state)
    {
    case 0:
        animal.animal.srcRect = animations.animation1.srcRect;
        animal.state = 1;
        break;
    case 1:
        animal.animal.srcRect = animations.animation2.srcRect;
        animal.state = 2;
        break;
    case 2:
        animal.animal.srcRect = animations.animation3.srcRect;
        animal.state = 0;
        break;
    default:
        animal.state = 0;
        break;
    }
    // * moves animals to right side of screen
    animal.animal.moverRect.x += 20;
    // * resete animals to left side when the corner is reached
    if (animal.animal.moverRect.x >= 1000)
    {
        animal.animal.moverRect.x = -50;
    }
}

/**
 * ? @brief drawObject
 * * loops on the given animal vector and creates every animal object on the screen
 * * also initializes animation for every animal using " animateObject " helper fucntion
 * * shifts
 *
 * ? @param gRenderer
 * * SDL attribute to render something
 *
 * ? @param assets
 * * SDL attribute for assets
 *
 * ? @param animals
 * * respected animal vector accoring to function call
 *
 * ? @param animations
 * * respected animal animation according to function call
 *
 * ! @return void
 */
void drawObject(SDL_Renderer *gRenderer, SDL_Texture *assets, vector<Animal> &animals, Animation animations)
{
    // * looping on every vector
    for (int i = 0; i < animals.size(); i++)
    {
        // * creating animations
        animateObject(animals[i], animations);
        // * creating objects
        SDL_RenderCopy(gRenderer, assets, &animals[i].animal.srcRect, &animals[i].animal.moverRect);
    }
}

/**
 * ? @brief drawObjects
 * * makes Animation struct for very animal
 * * and calls " drawObject " with SDL params,
 * * all animals vectors and animations structures
 *
 * ? @param gRenderer
 * * SDL attribute to render something
 *
 * ? @param assets
 * * SDL attribute for assets
 *
 * ! @return void
 */
void drawObjects(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    // * adding srcs of animals in Animation struct
    Animation pigeonAnimations = {pigeon1, pigeon2, pigeon3};
    Animation beesAnimations = {bee1, bee2, bee3};
    Animation butterfliesAnimations = {butterfly1, butterfly2, butterfly3};

    // * calling drawObject function to draw animals on screen
    drawObject(gRenderer, assets, pigeons, pigeonAnimations);
    drawObject(gRenderer, assets, bees, beesAnimations);
    drawObject(gRenderer, assets, butterflies, butterfliesAnimations);
}

/**
 * ? brief generateRandomInteger
 * * gives random number according to range given
 *
 * ? @param min
 * * int - the lowest number possible
 * ? @param max
 * * int - the highest number possible
 *
 * ! @return int
 * * random int
 */
int generateRandomInteger(int min, int max)
{
    int range = max - min + 1;
    return rand() % range + min;
}

/**
 * ? @brief setRandomAnimal
 * * gets random int from 1 to 3 from helper function " generateRandomInteger "
 * * switch cases from 1 to 3 decides what animal needs to pushed in what vector
 *
 * ! @return void
 */
void setRandomAnimal()
{
    // * getting random interger
    int randomInt = generateRandomInteger(1, 3);

    // * Initializing Animal struct with state 0
    Animal animal;
    animal.state = 0;

    // * switch case to add animals in respected vectors
    switch (randomInt)
    {
    case 1:
        animal.animal = pigeon1;
        pigeons.push_back(animal);
        break;
    case 2:
        animal.animal = bee1;
        bees.push_back(animal);
        break;
    case 3:
        animal.animal = butterfly1;
        butterflies.push_back(animal);
        break;
    default:
        break;
    }
}

/**
 * ? @brief createObject
 * * creates animal (pigeon, bee, butterfly) object on the screen
 * * triggers on mouse click
 *
 * * Uses helper function " setRandomAnimal " to add random animal
 * * in the respected vector for every animal type
 *
 * ? @param x
 * * x pixel on the screen where mouse clicked
 *
 * ? @param y
 * * y pixel on the screen where mouse clicked
 *
 * ! @return void
 */
void createObject(int x, int y)
{
    // * updating animals to mouse click location moveRect
    pigeon1.moverRect = {x, y, 40, 40};
    bee1.moverRect = {x, y, 40, 40};
    butterfly1.moverRect = {x, y, 40, 40};
    // * calling setRandomAnimal function to add animal in vector
    setRandomAnimal();

    cout << "Mouse clicked at: " << x << " -- " << y << endl;
}
