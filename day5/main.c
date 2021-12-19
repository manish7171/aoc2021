#include <stdio.h>
#include <string.h>

#if 0
#define BOARD_SZ 10
#else
#define BOARD_SZ 1010
#endif
int board[BOARD_SZ][BOARD_SZ];

void swap(int *x, int *y)
{
    int temp;

    temp = *x;
    *x    = *y;
    *y    = temp;


}
int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}
int sign(int x)
{
    return (x > 0) - (x < 0);
}
void drawLine(int x1, int y1, int x2, int y2)
{
    int x, y, i;
    int n = max(abs(x2-x1)+1, abs(y2-y1)+1);

    for (i = 0; i < n; ++i)
    {
        x = x1 + sign(x2 - x1) * i;
        y = y1 + sign(y2 - y1) * i;
        board[y][x]++;
    }
}


void DumpBoard()
{
    int x, y;
    for (y = 0; y < BOARD_SZ; ++y)
    {
        for (x = 0; x < BOARD_SZ; ++x)
        {
            if (board[y][x])
            {
                 printf("%d ", board[y][x]);


            } else
            {
                printf(". ");
            }
        }
        printf("\n");
    }
}
int parseRow(char * line)
{
    char * endp;
    int x1 = strtol(line, &endp,10);
    line = endp+1;
    int y1 = strtol(line, &endp,10);
    line = endp+3;
    int x2 = strtol(line, &endp,10);
    line = endp+1;
    int y2 = strtol(line,&endp,10);
   // printf("x1 %d y1 %d x2 %d y2 %d\n", x1, y1, x2, y2);

   if(x1 == x2 || y1 == y2) drawLine(x1, y1, x2, y2);


}

int parseRowForPart2(char * line)
{
    char * endp;
    int x1 = strtol(line, &endp,10);
    line = endp+1;
    int y1 = strtol(line, &endp,10);
    line = endp+3;
    int x2 = strtol(line, &endp,10);
    line = endp+1;
    int y2 = strtol(line,&endp,10);

    drawLine(x1, y1, x2, y2);

}
int part1()
{

    FILE *fp = fopen("D:\\CodePractice\\aoc\\day5\\sample.txt","r");
    char * line [100];
    if (fp == NULL)
    {
        printf("FILE NOT FOUND");
        return 0 ;
    }

    memset(board,0, sizeof(int)*BOARD_SZ*BOARD_SZ);

    while (!feof(fp))
    {
        fgets(line, 400, fp);
        parseRow(line);

    }

    int answer = 0 ;

    for (int i = 0 ; i < BOARD_SZ; ++i)
    {
        for (int  j = 0 ; j < BOARD_SZ; ++j)
        {
            if ( board[i][j] > 1 ) answer++;
        }
    }

    printf(" answer %d ", answer);
    return 0;
}

int part2()
{

    FILE *fp = fopen("D:\\CodePractice\\aoc\\day5\\input.txt","r");
    char * line [100];
    if (fp == NULL)
    {
        printf("FILE NOT FOUND");
        return 0 ;
    }

    memset(board,0, sizeof(int)*BOARD_SZ*BOARD_SZ);

    while (!feof(fp))
    {
        fgets(line, 400, fp);
        parseRowForPart2(line);

    }

  // DumpBoard();
    int answer = 0 ;

    for (int i = 0 ; i < BOARD_SZ; ++i)
    {
        for (int  j = 0 ; j < BOARD_SZ; ++j)
        {
            if ( board[i][j] > 1 ) answer++;
        }
    }

    printf(" answer %d ", answer);
    return 0;
}
int main()
{
    part2();
    return 0;
}
