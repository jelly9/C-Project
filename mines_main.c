#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mines.h"


void meun()//打印菜单
{
	printf("     Welcome to mines      \n");
	printf("---------------------------\n");
	printf("-----  1.Start game.   ----\n");
	printf("-----  0.Exit game.    ----\n");
	printf("---------------------------\n");
}
void game()//开始游戏
{
	char mine[ROW][COL];
	char show[ROW][COL];
	char ret = 0;
	srand((unsigned)time(NULL));
	initgame(mine, show, ROW, COL);
#if DEBUG
	display(mine,ROW,COL);
#endif
	display(show,ROW,COL);
	while(1)
	{
		ret = play(mine, show, ROW, COL);
		if('w' == ret)
		{
			display(mine,ROW,COL);
			printf("You win!\n");
			break;
		}
		if('*' == ret)
		{
			display(mine,ROW,COL);
			printf("You lose!\n");
			break;
		}
#if DEBUG
	display(mine,ROW,COL);
#endif
		display(show,ROW,COL);
	}
}

int main()        //主函数
{
	int input = 0;
	do
	{
		meun();
		printf("Please select >: ");
		scanf("%d", &input);
		switch(input)
		{
		case 1:game();break;
		case 0:printf("Exit...\n");break;
		default:printf("Error select! \n");
		}
	}while(input);
	return 0;
}