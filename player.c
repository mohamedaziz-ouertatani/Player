/**
* @file player.c
* @brief Testing Program.
* @author Azizoskiii
* @version 0.1
* @date Apr 18, 2022
*
* Testing program for main.c file
*
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "player.h"
#include "background.h"
#include "image.h"

/**
* @brief To initialize the player p.
* @param p the player
* @param url the url of the image
* @return Nothing
*/
void initPlayer(Player *p, const char *url)
{
 p->image=IMG_Load(url);
 if(p->image==NULL)
 {
  return ;
 }
 p->pos.x=450;
 p->pos.y=430; //Ground
 p->dir=1;
 p->acceleration=0;
 p->speed=0;
 p->speedV=0;
 p->lifes=3;
 p->score=0;
}

/**
* @brief To display the player p.
* @param p the player
* @param screen the window surface
* @return Nothing
*/
void displayPlayer (Player p,SDL_Surface *screen)
{ 
  SDL_BlitSurface (p.image,NULL,screen,&p.pos);
}

/**
* @brief To move the player p.
* @param p the player
* @param dt the delta of the time
* @return Nothing
*/
void movePlayer (Player *p,int dt)
{ 
 double dx;
 dx= 0.5 * p->acceleration * dt * dt + p->speed * dt;
 if (p->dir==1)
   {
     p->pos.x+=dx;
    }
else if (p->dir==0)
    {
      p->pos.x-=dx;
     }
}

/**
* @brief To jump the player p.
* @param p the player
* @return Nothing
*/
void jump (Player *p)
{ 
 if (p->pos.y==455)
     p->speedV=-30;
   {
    }
}

/**
* @brief To free the player
 the player p.
* @param p the player
* @return Nothing
*/
void freePlayer(Player p)
{
 SDL_FreeSurface(p.image);
}
	
/**
* @brief To animate the player p.
* @param p the player
* @return Nothing
*/
void animePlayer(Player *p, const char *url1, const char *url2)
{
 if(p->dir==1)
 {
  p->image=IMG_Load(url1);
 }
 else if(p->dir==0)
 {
  p->image=IMG_Load(url2);
 }
}
