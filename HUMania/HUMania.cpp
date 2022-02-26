#include <iostream>
#include "HUMania.hpp"
#include <vector>


using namespace std;

Unit pigeon1 = {{7, 88, 155, 103}, {30, 40, 50, 50}};
Unit butterfly1 = {{257, 24, 173, 134}, {30, 40, 50, 50}};
Unit bee1 = {{527, 138, 194, 115}, {30, 40, 50, 50}};
Unit pigeon2 = {{0, 237, 153, 84}, {30, 40, 50, 50}};
Unit pigeon3 = {{2, 361, 159, 124}, {30, 40, 50, 50}};
Unit butterfly2 = {{257, 182, 192, 214}, {30, 40, 50, 50}};
Unit butterfly3 = {{248, 432, 248, 179}, {30, 40, 50, 50}};
Unit bee2 = {{527, 243, 194, 116}, {30, 40, 50, 50}};
Unit bee3 = {{540, 370, 193, 115}, {30, 40, 50, 50}};

// First rectangle is srcRect, second is moverRect
// these values are taken from the corresponding image in assets file
// use spritecow.com to find exact values of other asset images

// struct Animal{
//     SDL_Rect srcRect, moverRect;
// };



vector<Animal> pigeons;
vector<Animal> bees;
vector<Animal> butterflies;



//create 2 more vectors for bees and butterflies

void animateObject(Animal &animal, Animation animations) {
    switch(animal.state) {
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

}

void drawObject(SDL_Renderer* gRenderer, SDL_Texture* assets, vector<Animal> &animals, Animation animations) {
    for(int i=0;i < animals.size(); i++){
        animateObject(animals[i], animations);
        SDL_RenderCopy(gRenderer, assets, &animals[i].animal.srcRect, &animals[i].animal.moverRect);
        
        animals[i].animal.moverRect.x += 20;
        if (animals[i].animal.moverRect.x >= 1000) {
            animals[i].animal.moverRect.x = -50;
        }
    } 
}

void drawObjects(SDL_Renderer* gRenderer, SDL_Texture* assets){
    
    Animation pigeonAnimations = {pigeon1, pigeon2, pigeon3};
    Animation beesAnimations = {bee1, bee2, bee3};
    Animation butterfliesAnimations = {butterfly1, butterfly2, butterfly3};

    drawObject(gRenderer, assets, pigeons, pigeonAnimations);
    drawObject(gRenderer, assets, bees, beesAnimations);
    drawObject(gRenderer, assets, butterflies, butterfliesAnimations);
    
}

/**
 * ? brief generateRandomInteger gived random number according to range given
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

Animal setRandomAnimal() {
    
    int randomInt = generateRandomInteger(1, 3);

    Animal animal;
    animal.state = 0;

    switch(randomInt) {
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

    return animal;
}

void createObject(int x, int y) {

    
    Animal animal;
    animal.state = 0;

    pigeon1.moverRect = {x, y, 40, 40};
    bee1.moverRect = {x, y, 40, 40};
    butterfly1.moverRect = {x, y, 40, 40};
    setRandomAnimal();
    
    cout << "Mouse clicked at: " << x << " -- " << y << endl;
}

