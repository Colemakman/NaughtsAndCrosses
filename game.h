#ifndef GAME_H_
#define GAME_H_

#define N 3
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define CELL_WIDTH (SCREEN_WIDTH / N)
#define CELL_HEIGHT (SCREEN_HEIGHT / N)


#define EMPTY 0

enum game_state {
	running,
	x_won,
	o_won,
	tie,
	quit,
};

enum player {
	PLAYER_X,
	PLAYER_O,
};

typedef struct {
	int board[N * N];
	enum game_state state;
	enum player current_player;
} game_t;

#endif
