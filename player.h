#ifndef player_H
#define player_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "background.h"
#include "image.h"

/**
* @struct Player
* @brief struct for player
*/

typedef struct
{ 
 SDL_Surface *image; /*!< Image*/
 SDL_Rect pos; /*!< Rectangle*/
 int dir; //0-Back 1-Front
 double speed,acceleration;
 int speedV; //getting back to ground speed (Gravity)
 
 //Score
  char number[20];
  SDL_Rect posScoreText;
  SDL_Rect posScore;
  int score;
  
 //Lives
 SDL_Surface *lifeIMG[4];
 SDL_Rect PosLife;
 int lifes; 
 SDL_Rect PosLifeText;
 
}Player;

void initPlayer(Player *p, const char *file);
void displayPlayer(Player p,SDL_Surface *screen);
void movePlayer(Player *p,int dt);
void jump(Player* p);
void freePlayer(Player p);
void animePlayer(Player *p, const char *url1, const char *url2);

#endif
