#include "./game.h"
#include "./logic.h"

void switch_player(game_t *game)
{
    if (game->current_player == PLAYER_X) {
        game->current_player = PLAYER_O;
    } else if (game->current_player == PLAYER_O) {
        game->current_player = PLAYER_X;
    }
}

int check_player_won(game_t *game, int player)
{
    int row_count = 0;
    int column_count = 0;
    int diag1_count = 0;
    int diag2_count = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (game->board[i * N + j] == player) {
                row_count++;
            }

            if (game->board[j * N + i] == player) {
                column_count++;
            }
        }

        if (row_count >= N || column_count >= N) {
            return 1;
        }

        row_count = 0;
        column_count = 0;

        if (game->board[i * N + i] == player) {
            diag1_count++;
        }

        if (game->board[i * N + N - i - 1] == player) {
            diag2_count++;
        }
    }

    return diag1_count >= N || diag2_count >= N;
}

int count_cells(const int *board, int cell)
{
    int count = 0;

    for (int i = 0; i < N * N; ++i) {
        if (board[i] == cell) {
            count++;
        }
    }

    return count;
}

void game_over_condition(game_t *game)
{
    if (check_player_won(game, PLAYER_X)) {
        game->state = x_won;
    } else if (check_player_won(game, PLAYER_O)) {
        game->state = o_won;;
    } else if (count_cells(game->board, EMPTY) == 0) {
        game->state = tie;
    }
}

void player_turn(game_t *game, int row, int column)
{
    if (game->board[row * N + column] == EMPTY) {
        game->board[row * N + column] = game->current_player;
        switch_player(game);
        game_over_condition(game);
    }
}

void reset_game(game_t *game)
{
    game->current_player = PLAYER_X;
    game->state = running;
    for (int i = 0; i < N * N; ++i) {
        game->board[i] = EMPTY;
    }
}

void click_on_cell(game_t *game, int row, int column)
{
    if (game->state == running) {
        player_turn(game, row, column);
    } else {
        reset_game(game);
    }
}
