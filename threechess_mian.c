#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "threechess.h"
//#pragma comment(lib,"threechess.lib")
int main()        //Ö÷º¯Êý
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