all:
	gcc -o game logic.c main.c rendering.c -lSDL2_gfx -lSDL2

