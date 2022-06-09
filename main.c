/**
* @file main.c
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

int main(int argc, char** argv)
{
//Initializing SDL
 TTF_Init();
 if(SDL_Init(SDL_INIT_VIDEO)!=0)
 {
  printf("Error: %s \n", SDL_GetError());
 }

 //Variables
 SDL_Surface *screen;
 SDL_Event event;
 background backG;
 Player p1;
 int right1=0,left1=0,up1=0,dir1=2;
 Uint32 dt;
 Uint32 t_prev;
 Player p2;
 int right2=0,left2=0,up2=0,dir2=2;
 

 //create window
 screen=SDL_SetVideoMode( 1000,700,32, SDL_HWSURFACE | SDL_DOUBLEBUF );
 if(!screen)
 {
  printf("Unable create window: %s\n",SDL_GetError());
  return 1;
 }
 
 //initializing variables
 initBackground(&backG, "Sources/sky.jpg");
 initPlayer(&p1,"Sources/characterFront.png");
 initPlayer(&p2,"Sources/character2Front.png");
 
 p1.lifes=3;
 p2.lifes=3;
 
 p1.score=0;
 p2.score=0;
 
 p1.pos.x=50;
 p1.pos.y=430;
 
 p2.pos.x=870;
 p2.pos.y=430;

	/*Lifes and Score */
/*Declaration of variables */
TTF_Font *font=NULL;
SDL_Surface *score=NULL; //score
SDL_Surface *life=NULL;  // life
SDL_Surface *scoreV=NULL; //score management

/*FONT*/
font=TTF_OpenFont("Redemtion.ttf",35);
SDL_Color white={255,255,255};

/*SCORE TEXT*/
score=TTF_RenderText_Blended(font,"SCORE :",white);
p1.posScoreText.x=15;
p1.posScoreText.y=0;

/*LIFE TEXT*/
life=TTF_RenderText_Blended(font,"LIFE :",white);
p1.PosLifeText.x=15;
p1.PosLifeText.y=655;

/*LIFE PLAYER*/
p1.lifeIMG[0]=IMG_Load("Sources/hearts0.png");
p1.lifeIMG[1]=IMG_Load("Sources/hearts1.png");
p1.lifeIMG[2]=IMG_Load("Sources/hearts2.png");
p1.lifeIMG[3]=IMG_Load("Sources/hearts3.png");
p1.PosLife.x=105;
p1.PosLife.y=654;

p1.posScore.x=200;
p1.posScore.y=0;

	/*PLAYER 2 */
/*Declaration of variables */
TTF_Font *font2=NULL;
SDL_Surface *score2=NULL; //score
SDL_Surface *life2=NULL;  // life
SDL_Surface *scoreV2=NULL; //score management

/*FONT*/
font2=TTF_OpenFont("Redemtion.ttf",35);
SDL_Color red={255,0,140};

/*SCORE TEXT*/
score2=TTF_RenderText_Blended(font2,"SCORE :",red);

p2.posScoreText.x=700;
p2.posScoreText.y=0;

/*LIFE TEXT*/
life2=TTF_RenderText_Blended(font2,"LIFE :",red);
p2.PosLifeText.x=700;
p2.PosLifeText.y=655;

/*LIFE PLAYER*/
p2.lifeIMG[0]=IMG_Load("Sources/hearts0.png");
p2.lifeIMG[1]=IMG_Load("Sources/hearts1.png");
p2.lifeIMG[2]=IMG_Load("Sources/hearts2.png");
p2.lifeIMG[3]=IMG_Load("Sources/hearts3.png");
p2.PosLife.x=790;
p2.PosLife.y=654;

p2.posScore.x=885;
p2.posScore.y=0;


	/* TIMER */
 TTF_Font *font3;
 font3=TTF_OpenFont("Redemtion.ttf",30);
 SDL_Color black={0,0,0};
 SDL_Surface *timer;
 char timeText[20];
 sprintf(timeText,"%d",SDL_GetTicks());
 timer=TTF_RenderText_Blended(font3,timeText,black);
 SDL_Rect timerPos;
 timerPos.x=465;
 timerPos.y= 0;
 SDL_BlitSurface(timer,NULL,screen,&timerPos);
  int milisec=0, seconds=0, minutes=0;




		/*GAME LOOP*/
 while(1)
{
  t_prev=SDL_GetTicks();
  while(SDL_PollEvent(&event))
  {
    if(event.type==SDL_KEYDOWN)
      if(event.key.keysym.sym==SDLK_ESCAPE)
         return 0;
      
     switch(event.type)
     {
       case SDL_QUIT:
         return 0;
         break;

       case SDL_KEYDOWN:
         switch(event.key.keysym.sym)
             {
                case SDLK_RIGHT:
                   right1=1;
                   break;
                case SDLK_LEFT:
                   left1=1;
                   break;
                case SDLK_UP:
                   up1=1;
                   break;
                   
                //Player 2
                case SDLK_d:
                   right2=1;
                   break;
                case SDLK_a:
                   left2=1;
                   break;
                case SDLK_w:
                   up2=1;
                   break;
              }
              break;
       case SDL_KEYUP:
         switch(event.key.keysym.sym)
             {
                case SDLK_RIGHT:
                   right1=0;
                   dir1=1;
                   p1.speed=0;
                   break;
                case SDLK_LEFT:
                   left1=0;
                   dir1=0;
                   p1.speed=0;
                   break;
                case SDLK_UP:
                   up1=0;
                   break;
                
                //Player 2
                case SDLK_d:
                   right2=0;
                   dir2=1;
                   p2.speed=0;
                   break;
                case SDLK_a:
                   left2=0;
                   dir2=0;
                   p2.speed=0;
                   break;
                case SDLK_w:
                   up2=0;
                   break;
              }
              break;
      }
  }
/*UPDATE*/
  if (right1==1)
  {
    p1.speed=10;
    p1.acceleration+=0.5;
    p1.dir=1;
  }
  if (left1==1)
  {
    p1.speed=10;
    p1.acceleration+=0.5;
    p1.dir=0;
  }
  if (up1==1)
  {
   jump(&p1);
  }
  
  //PLAYER 2
  if (right2==1)
  {
    p2.speed=10;
    p2.acceleration+=0.5;
    p2.dir=1;
  }
  if (left2==1)
  {
    p2.speed=10;
    p2.acceleration+=0.5;
    p2.dir=0;
  }
  if (up2==1)
  {
   jump(&p2);
  }

  movePlayer(&p1,dt);
  animePlayer(&p1, "Sources/characterFront.png" ,"Sources/characterBack.png");
  
  movePlayer(&p2,dt);
  animePlayer(&p2, "Sources/character2Front .png" ,"Sources/character2Back.png");

  p1.acceleration-=0.3;
  p2.acceleration-=0.3;

  if(p1.acceleration<0) // min_acceleration for the player is 0
    p1.acceleration=0;
  if(p1.acceleration>4) // max_acceleration for the player is 4
    p1.acceleration=4;
    
    
  if(p2.acceleration<0) // min_acceleration for the player is 0
    p2.acceleration=0;
  if(p2.acceleration>4) // max_acceleration for the player is 4
    p2.acceleration=4;

  SDL_Delay(1);

  dt=SDL_GetTicks()-t_prev; //dt=t2-t1

  p1.pos.y+=p1.speedV; 
  p1.speedV+=10;
  if (p1.pos.y>=455)
  {
     p1.speedV=0; //THE PLAYER GO BACK DOWN ALONE
     p1.pos.y=455;
  }
  
  //PLAYER 2
  p2.pos.y+=p2.speedV; 
  p2.speedV+=10;
  if (p2.pos.y>=455)
  {
     p2.speedV=0; //THE PLAYER GO BACK DOWN ALONE
     p2.pos.y=455;
  }
   
/*DISPLAY*/
  displayBackground( backG, screen);
  displayPlayer(p1,screen);
  displayPlayer(p2,screen);



	/* Lifes and Score */
  SDL_BlitSurface(score,NULL,screen,&p1.posScoreText); //score  text
  SDL_BlitSurface(life,NULL,screen,&(p1.PosLifeText)); //life text

  scoreV=TTF_RenderText_Blended(font,p1.number,white);

  SDL_BlitSurface(scoreV,NULL,screen,&p1.posScore); //Score
  SDL_BlitSurface(p1.lifeIMG[p1.lifes],NULL,screen,(&p1.PosLife)); //Lifes

  /*SCORE MANAGEMENT*/
  sprintf(p1.number,"%d",(p1.score)); // converts of an integer into a string

 
  	//Player 2*
  SDL_BlitSurface(score2,NULL,screen,&p2.posScoreText); //score  text
  SDL_BlitSurface(life2,NULL,screen,&(p2.PosLifeText)); //life text

  scoreV2=TTF_RenderText_Blended(font2,p2.number,red);

  SDL_BlitSurface(scoreV2,NULL,screen,&p2.posScore); //Score
  SDL_BlitSurface(p2.lifeIMG[p2.lifes],NULL,screen,(&p2.PosLife)); //Lifes

  //SCORE MANAGEMENT
  sprintf(p2.number,"%d",(p2.score)); // converts of an integer into a string
 
 
 		/* TIMER */
  if( SDL_GetTicks() / 1000  == (seconds + 60*minutes) )
     seconds++;
  if( seconds == 60 )
   {
    minutes++;
    seconds=0;
   }  
  sprintf(timeText,"%02d : %02d",minutes ,seconds);
  timer=TTF_RenderText_Blended(font3,timeText,black);
  SDL_BlitSurface(timer,NULL,screen,&timerPos);

  SDL_Flip(screen);
  SDL_Delay(50);
}
 
 freeBackground(backG);
 freePlayer(p1);
 freePlayer(p2);
 SDL_FreeSurface(timer);
 
 
 
 TTF_CloseFont(font);
 TTF_Quit();
 SDL_Quit();
}
