#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "mines.h"

void initgame(char mine[ROW][COL], char show[ROW][COL], int x, int y)// 初始化并布雷
{
	int i = 0;//坐标
	int j = 0;
	int k = 0;
	memset(mine, ' ', x*y*sizeof(char));
	memset(show, ' ', x*y*sizeof(char));
	for(k = 0; k<MINES; k++)
	{
		while(1)
		{
			i = rand()%(x-2)+1;//随机生成雷
			j = rand()%(x-2)+1;
			if( ' ' == mine[i][j])
			{
				mine[i][j] = '*';
				break;
			}
		}
	}
}

int checkmine(char mine[ROW][COL], char show[ROW][COL], int i, int j)//遍历周围雷的个数
{
	int m = 0;
	int n = 0;
	int nummines = 0;
	for(m = i-1; m<=i+1; m++)
	{
		for(n = j-1; n<=j+1; n++)
			if('*' == mine[m][n])nummines++;
	}
	show[i][j] = nummines+'0';
	return nummines;
}

void aroundmines( char mine[ROW][COL], char show[ROW][COL], int i, int j )//遍历一圈的雷的个数
{
	checkmine( mine, show, i-1, j-1);
	checkmine( mine, show, i-1, j  );
	checkmine( mine, show, i-1, j+1);
	checkmine( mine, show, i  , j-1);
	checkmine( mine, show, i  , j+1);
	checkmine( mine, show, i+1, j-1);
	checkmine( mine, show, i+1, j  );
	checkmine( mine, show, i+1, j+1);
		
	
}

void display(char arr[ROW][COL], int x, int y)//打印游戏界面
{
	int i = 0;
	int j = 0;
	printf("  ");
	for(i = 1; i<x-1; i++)
	{
		printf("%4d",i);
	}
	printf("\n");
	printf("   ");
	printf("|");
	for(j = 1; j<y-1; j++)
	{
		printf("---|");
	}
	printf("\n");
	for(i = 1; i<x-1; i++)
	{
		printf("%2d ", i);
		printf("|");
		for(j = 1; j<y-1; j++)
		{
			printf(" %C |",arr[i][j]);
		}
		printf("\n");
		printf("   ");
		printf("|");
		for(j = 1; j<y-1; j++)
		{
			printf("---|",arr[i][j]);
		}
		printf("\n");
	}
}

int play(char mine[ROW][COL], char show[ROW][COL], int x, int y)//玩家玩
{
	int i = 0;//坐标变量
	int j = 0;
	int m = 0;
	int n = 0;
	int ret = 0;
	static int pos1 = 0;
	static int pos2 = 0;
	int count = 0;//统计是否排完雷的变量
	while(1)
	{
		printf("Please input >:");
		scanf("%d %d", &i, &j);//输入坐标
		if( i>=1 && i<x-1 && j>=1 && j<y-1 )//位置合法性检测
		{
			if('*' != mine[i][j])//判断是否为雷------------非雷
			{
				
				ret = checkmine( mine, show, i, j);     //遍历周围雷的个数

				if( 0 == ret && 0 == pos2 )
				{
					//pos2++;
					aroundmines( mine, show, i, j);
				}
				//pos2++;
				for(i = 1; i<=ROW-2; i++)//统计是否已经排完雷
				{
					for(j = 1; j<=COL-2; j++)
					{
						if(' ' == show[i][j] )count++;
					}
				}
				if( MINES == count )return 'w';//排完
			}
			else //return '*';//是雷-----(移走)直接炸死
			{
				if( 0 == pos1)
				{
					mine[i][j] = ' ';//移走
					m = i;
					n = j;
					while(1)
					{
						i = rand()%(x-2)+1;//随机生成雷
						j = rand()%(x-2)+1;
						if( ' ' == mine[i][j])
						{
							mine[i][j] = '*';
							checkmine( mine, show, m, n);
							break;
						}
					}

				}
				else 
				{
					return '*';
				}
			}
			pos1++;
			return 0;
		}else printf("Error input!\n");//位置不合法
	}
	return 0;
}



