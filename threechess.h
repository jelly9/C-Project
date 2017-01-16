
#ifndef __THREECHESS_H__

#define ROWS 3    //宏定义
#define COLS 3

void meun();
void game();
void init_board   (char board[ROWS][COLS], int x, int y);//函数声明
void display_board(char board[ROWS][COLS], int x, int y);
void player_move  (char board[ROWS][COLS], int x, int y);
void computer_move(char board[ROWS][COLS], int x, int y);
char check_win    (char board[ROWS][COLS], int x, int y);

#endif __THREECHESS_H__
