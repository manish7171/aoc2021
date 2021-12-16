#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUM_CAP 128
#define BOARD_SZ 5
#define BOARD_CAP 128



int bingo_num [NUM_CAP];
int num_size = 0, board_num_size = 0;

typedef struct BoardNum
{
    int num;
    int is_crossed;
} BoardNum;

typedef struct Board
{
    union {
        BoardNum s[BOARD_SZ][BOARD_SZ];
        BoardNum i[BOARD_SZ*BOARD_SZ];
    } u;

    int already_won;
} Board;



Board boards[BOARD_CAP];
int board_sz = 0;

void testBoard()
{
    Board b;
    int i, j;

    for (i = 0; i<BOARD_SZ*BOARD_SZ; ++i)
    {
        b.u.i[i].num= i;
    }

    for ( i = 0; i < BOARD_SZ; ++i )
    {
        for( j = 0; j < BOARD_SZ; ++j )
        {
            printf("%02d ", b.u.s[i][j].num);
        }
        printf("\n");
    }
}

void drawBoard(Board * board)
{

    for ( int i = 0; i < BOARD_SZ; ++i )
    {
        for( int j = 0; j < BOARD_SZ; ++j )
        {
            if (board->u.s[i][j].is_crossed == 0)
            {
                printf("%*d ", 2, board->u.s[i][j].num);
            } else
            {
                printf("[%*d]", 2, board->u.s[i][j].num);
            }

        }
        printf("\n");
    }
}
void parseFirstRow(char * line)
{
        char * endp;

        int len = strlen(line);

        if (len != 0)
        {
            int a = strtol(line, &endp, 10);
            bingo_num[num_size] = a;
            //printf("numsize: %d %d \n",num_size, bingo_num[num_size]);
            num_size++;
            parseFirstRow(endp+1);

        }

}
int isBlank (char const * line)
{
  char * ch;
  int is_blank = -1;

  // Iterate through each character.
  for (ch = line; *ch != '\0'; ++ch)
  {
    if (!isspace(*ch))
    {
      // Found a non-whitespace character.
      is_blank = 0;
      break;
    }
  }

  return is_blank;
}
int board_counter = 0;
void loadBoard(char * line)
{
    char * endp;

    int len = strlen(line);
    if (len != 0)
    {
        int a = strtol(line, &endp, 10);

       // boards[board_num_size].board_num->u.i[board_counter] = a;
        boards[board_num_size].u.i[board_counter].num = a;
        boards[board_num_size].u.i[board_counter].is_crossed = 0;
        board_counter++;
        loadBoard(endp+1);

    }

}
void crossInboard(Board *board, int x)
{
    Board *b = board;
    for (int i = 0; i< BOARD_SZ*BOARD_SZ; ++i)
    {
        if (b->u.i[i].num == x)
        {
            b->u.i[i].is_crossed = 1;
        }
    }
}

int GameWon(Board *board)
{
    for (int i = 0; i < BOARD_SZ; i++)
    {
        int j = 0;
        while (j < BOARD_SZ && board->u.s[i][j].is_crossed == 1)
        {
            j++;
        }
        if (j >= BOARD_SZ) return 1;

        j = 0;
        while (j < BOARD_SZ && board->u.s[j][i].is_crossed == 1)
        {
            j++;
        }
        if (j >= BOARD_SZ) return 1;
    }
}

int BoardSumOfUncrossed(Board *board)
{
    int sum = 0;
    for (int i = 0; i < BOARD_SZ*BOARD_SZ; i++)
    {
        if(board->u.i[i].is_crossed == 0)
        {
            sum += board->u.i[i].num;
        }
    }
    return sum;
}

int LastGameWon(Board boards [])
{
    for (int i = 0; i < board_num_size; i++)
    {
        if (boards[i].already_won == 0)
        {
            return 0;
        }
    }
    return 1;
}

int part2()
{

    FILE *fp = fopen("D:\\codepractice\\aoc\\day4\\input.txt","r");
    char line [400];

    if (fp == NULL)
    {
        printf("File not found");
        exit(1);
    }
    int line_count = 0;
    while (!feof(fp))
    {
        fgets(line, 400, fp);
        if (line_count == 0)
        {
            parseFirstRow(line);
        }
        else {


            if (!isBlank(line))
            {

                loadBoard(line);


            }
            //printf("line count %d \n",line_count);
            if(line_count % 5 == 0)
            {
                //drawBoard(&boards[board_num_size]);
                board_num_size++;
                board_counter = 0;
            }
        }

        if (!isBlank(line)) {
            line_count++;
        }

    }
    for (int i = 0 ; i< board_num_size; ++i)
    {
        boards[i].already_won = 0;
    }
    for (int j = 0; j < num_size; ++j)
    {
        for (int i = 0 ; i< board_num_size; ++i)
        {
            crossInboard(&boards[i], bingo_num[j]);
            //drawBoard(&boards[i]);


           // printf("\n");
            if (GameWon(&boards[i]) == 1 && boards[i].already_won == 0)
            {

                boards[i].already_won = 1;
                //return;
            }

            if ( LastGameWon(&boards) )
            {
                printf("board num %d \n",i);
                printf("bingo num %d \n",bingo_num[j]);
                printf("last %d answer: \n", BoardSumOfUncrossed(&boards[i])* bingo_num[j]);
                return;
            }


        }


    }



    fclose(fp);

}

int part1()
{

    FILE *fp = fopen("D:\\codepractice\\aoc\\day4\\sample.txt","r");
    char line [400];

    if (fp == NULL)
    {
        printf("File not found");
        exit(1);
    }
    int line_count = 0;
    while (!feof(fp))
    {
        fgets(line, 400, fp);
        if (line_count == 0)
        {
            parseFirstRow(line);
        }
        else {


            if (!isBlank(line))
            {

                loadBoard(line);


            }
            //printf("line count %d \n",line_count);
            if(line_count % 5 == 0)
            {
                //drawBoard(&boards[board_num_size]);
                board_num_size++;
                board_counter = 0;
            }
        }

        if (!isBlank(line)) {
            line_count++;
        }

    }
    for (int j = 0; j < num_size; ++j)
    {
        for (int i = 0 ; i< board_num_size; ++i)
        {
            crossInboard(&boards[i], bingo_num[j]);
            //drawBoard(&boards[i]);



           // printf("\n");
            if (GameWon(&boards[i]) == 1)
            {
                printf("board num %d \n",i);
                printf("bingo num %d \n",bingo_num[j]);
                printf("%d answer: \n", BoardSumOfUncrossed(&boards[i])* bingo_num[j]);
                return;
            }


        }


    }



    fclose(fp);

}
int main()
{
    part2();
}
