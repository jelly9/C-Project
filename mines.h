
#define ROW 10+2  //雷区大小
#define COL 10+2
#define MINES 15  //雷的数量
#define DEBUG 0  //测试开关

void initgame(char mine[ROW][COL], char show[ROW][COL], int x, int y);
void display(char arr[ROW][COL],int x, int y);
int  play(char mine[ROW][COL], char show[ROW][COL], int x, int y);
int checkmine(char mine[ROW][COL], char show[ROW][COL], int i, int j);
void aroundmines( char mine[ROW][COL], char show[ROW][COL], int i, int j );
