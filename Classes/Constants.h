#ifndef CONSTANTS_H
#define CONSTANTS_H

//	invaders array rows and cols
const int ROWs = 3;
const int COLs = 10;

//	invaders array move direction
enum class MoveDirection
{
	none,
	left,
	right,
	down
};

//	game state
enum class GameState
{
	title,
	playing,
	gameover
};

//	weapon type
enum class WeaponType 
{
	player,
	enemy
};
#endif
