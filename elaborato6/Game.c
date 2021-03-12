#include <stdio.h>
#include "game.h"

struct position ballpos;
struct position balldir;
struct position pad1pos;
struct position pad2pos;
struct position ballposiniziale;

static int height1;
static int width1;
//static int ballposx;
//static int ballposy;
//static int balldirx;
//static int balldiry;
//static int pad1posx;
//static int pad1posy;
//static int pad2posx;
//static int pad2posy;
static int padlen;
static unsigned int score1;
static unsigned int score2;
static int pad1sup;
//static int pad1inf;
static int pad2sup;
//static int pad2inf;
static unsigned int currentpadlenght;
//static int ballposxiniziale;
//static int ballposyiniziale;







/*
* Setup a game with the following starting configuration:
* - table dimension equal to heigth*width
* - ball starting position at ball_pos
* - ball starting direction towards ball_dir
* - pad1 starting position at pad1_pos
* - pad2 starting position at pad2_pos
* - pad length equal to pad_len
*/
void setup_game(int height, int width,struct position ball_pos, struct position ball_dir,struct position pad1_pos, struct position pad2_pos, int pad_len) {

	height1 = height; //altezza campo
	width1 = width; //larghezza campo
	ballpos.x = ball_pos.x; //variabile per posizione x palla
	ballpos.y = ball_pos.y;  //variabile per posizione y palla
	ballposiniziale.x = ball_pos.x;  //variabile per posizione x palla iniziale
	ballposiniziale.y= ball_pos.y; //variabile per posizione x palla iniziale
	balldir.x = ball_dir.x; //variabile x direzione palla
	balldir.y = ball_dir.y; //variabile y direzione palla 
	pad1pos.x = pad1_pos.x; //variabile x posizione pad1
	pad1pos.y = pad1_pos.y; //variabile y posizione pad1
	pad2pos.x = pad2_pos.x; //variabile x posizione pad2
	pad2pos.y = pad2_pos.y;//variabile y posizione pad2
	padlen = pad_len; //lunghezza pad 
	pad1sup = pad1_pos.y; //parte superiore del pad1
	pad2sup = pad2_pos.y; //parte superiore del pad2
	score1 = 0;
	score2 = 0;



}

/* Moves pad1 one position up. */
void move_pad1_up(void)
{
	///*if (pad1posy != 0) pad1posy=pad1posy-1;*/
	///*if (((ballposx == (pad1posx + 1)) || (ballposx == pad1posx) || (ballposx == (pad1posx - 1))) && (ballposy == (pad1sup - 1))) pad1posy++;*/
	if ((pad1pos.y != 0) && (((ballpos.x == pad1pos.x || ballpos.x + 1 == pad1pos.x || ballpos.x - 1 == pad1pos.x) && (ballpos.y == pad1pos.y - 1)) == 0)) pad1pos.y = pad1pos.y - 1;
}

/* Moves pad2 one poisiton up */
void move_pad2_up(void)
{
	///*if (pad2posy != 0) pad2posy=pad2posy+1;*/
	///*if ((((ballposx + 2) == pad2posx) || ((ballposx + 1) == pad2posx) || (ballposx == pad2posx)) && (ballposy == (pad2sup - 1))) pad2posy=pad2posy-1;*/
	if ((pad2pos.y != 0) && (((ballpos.x == pad2pos.x || ballpos.x + 1 == pad2pos.x || ballpos.x + 2 == pad2pos.x) && ballpos.y == pad2pos.y - 1) == 0)) pad2pos.y = pad2pos.y - 1;

}

/* Moves pad1 one position down. */
void move_pad1_down(void)
{
	///*if (pad1posy + padlen - 1 < height1) pad1posy = pad1posy +1 ;
	//if (((ballposx == pad1posx) || (ballposx == pad1posx + 1) || (ballposx == (pad1posx - 1))) && (ballposy == pad1posy + padlen)) pad1posy=pad1posy-1;*/
	if (((pad1pos.y + padlen - 1) != height1) && (((ballpos.x == pad1pos.x || ballpos.x + 1 == pad1pos.x || ballpos.x - 1 == pad1pos.x) && ballpos.y == (pad1pos.y + padlen)) == 0)) pad1pos.y = pad1pos.y + 1;
}

/* Moves pad2 one position down. */
void move_pad2_down(void)
{
	/*if (pad2posy + padlen - 1 < height1) pad2posy = pad2posy +1 ;
	if ((((ballposx + 2) == pad2posx) || ((ballposx + 1) == pad2posx) || (ballposx == pad2posx)) && (ballposy == pad2posy + padlen)) pad2posy=pad2posy-1;*/
	if (((pad2pos.y + padlen - 1) != height1) && (((ballpos.x == pad2pos.x || ballpos.x + 1 == pad2pos.x || ballpos.x + 2 == pad2pos.x) && ballpos.y == (pad2pos.y + padlen)) == 0)) pad2pos.y = pad2pos.y + 1;
}

/* Moves the ball in the current direction */
void move_ball(void)
{
	/*caso in cui fa punto il giocatore 2*/
	if (ballpos.x == 0)
	{
		score2++;
		ballpos.x = ballposiniziale.x;
		ballpos.y = ballposiniziale.y;

	}

	/*caso in cui fa punto il giocatore 1*/
	else if ((ballpos.x + 1) == width1)
	{
		score1++;
		ballpos.x = ballposiniziale.x;
		ballpos.y = ballposiniziale.y;
	}

	else
	{



		/*caso in cui la pallina sbatte sul tetto del campo */
		if (ballpos.y == 0)
		{
			balldir.y = 1;

		}

		/*caso in cui la pallina sbatte sul fondo del campo*/
		else if (ballpos.y == height1)
		{
			balldir.y = -1;
		}


		//casi in cui pallina tocca pad1 superiore
		if (((ballpos.x == (pad1pos.x + 1)) || (ballpos.x == pad1pos.x) || (ballpos.x == (pad1pos.x - 1))) && (ballpos.y == (pad1pos.y - 1)))
		{
			balldir.x = 1;
			balldir.y = -1;

		}

		//casi in cui la pallina tocca pad1 inferiore
		if (((ballpos.x == pad1pos.x) || (ballpos.x == pad1pos.x + 1) || (ballpos.x == (pad1pos.x - 1))) && (ballpos.y == pad1pos.y + padlen))
		{
			balldir.x = 1;
			balldir.y = 1;
		}

		//caso in cui la pallina tocca la parte centrale del pad1
		if ((ballpos.x == (pad1pos.x + 1)) && ((ballpos.y >= pad1pos.y)) && ((ballpos.y+1) <= (pad1pos.y + padlen)))
		{
			balldir.x = 1;

		}

		//casi in cui pallina tocca pad2 superiore
		if ((((ballpos.x + 2) == pad2pos.x) || ((ballpos.x + 1) == pad2pos.x) || (ballpos.x == pad2pos.x)) && (ballpos.y == (pad2pos.y - 1)))
		{
			balldir.x = -1;
			balldir.y = -1; //caso in cui la palla tocca la parte superiore del pad2
		}

		//casi in cui la pallina tocca pad2 inferiore
		if ((((ballpos.x + 2) == pad2pos.x) || ((ballpos.x + 1) == pad2pos.x) || (ballpos.x == pad2pos.x)) && (ballpos.y == pad2pos.y + padlen))
		{
			balldir.x = -1;
			balldir.y = 1; //caso in cui la palla tocca la parte inferiore del pad2
		}

		//caso in cui la pallina tocca la parte centrale del pad2 
		if ((ballpos.x + 2 == pad2pos.x) && (ballpos.y >= pad2pos.y) && (ballpos.y <= (pad2pos.y + padlen)))
		{
			balldir.x = -1;


		}

		ballpos.x = ballpos.x + balldir.x;
		ballpos.y = ballpos.y + balldir.y;





	}
}

/* Returns ball current position */
struct position get_ball_pos(void)
{
	struct position currentballpos;
	currentballpos.y = ballpos.y;
	currentballpos.x = ballpos.x;
	return currentballpos;
}

/* Returns pad1 current position */
struct position get_pad1_pos(void)
{
	struct position currentpad1pos;
	currentpad1pos.y = pad1pos.y;
	currentpad1pos.x = pad1pos.x;
	return currentpad1pos;
}

/* Returns pad2 current position */
struct position get_pad2_pos(void)
{
	struct position currentpad2pos;
	currentpad2pos.x = pad2pos.x;
	currentpad2pos.y = pad2pos.y;
	return currentpad2pos;
}

/* Returns the pad length */
unsigned int get_pad_len(void)
{
	currentpadlenght = padlen;
	return currentpadlenght;

}

/* Returns pad1 current score */
unsigned int get_pad1_score(void)
{
	return score1;

}

/* Returns pad2 current score */
unsigned int get_pad2_score(void)
{
	return score2;
}

