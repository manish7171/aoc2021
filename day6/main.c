#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#define N 9
int64_t  table[N];
int64_t  back_table[N];

void dumpTable()
{
    int i;
    for (i = 0; i < N; ++i)
    {
        printf("%2d: %d\n", i, table[i]);
    }
}

void countFish()
{
    int i;
    int64_t answer = 0;
    for (i = 0; i < N; ++i)
    {
        answer += table[i];
    }
    printf("%" PRId64 "\n", answer);
}

void next_day()
{
    memset(back_table, 0, sizeof(int64_t)*N);
    back_table[8] += table[0];
    back_table[6] += table[0];

    for (int i = 1; i < N; ++i)
    {
        back_table[i-1] += table[i];

    }

    memcpy(table, back_table, sizeof(int64_t)*N);
}
int parse(char * line)
{
    int len = strlen(line);
    char *endp;
    int x;
    while (len > 1)
    {
        //printf("lent %d\n", len);
        int x = strtol(line, &endp, 10);
        line = *endp;
        len  = strlen(endp);
        line = endp+1;
        //printf("num: %d \n",x);
        assert(x<N);
        table[x]++;



    }
}
int main()
{
    FILE *fp = fopen("D:\\CodePractice\\aoc\\day6\\input.txt", "r");

    if(fp == NULL)
    {
        printf("ERROR:file not found");
        return 0;
    }

    memset(table, 0, sizeof(int)*N);

    char line [1000];
    fgets(line, 1000, fp);
    printf("%s\n", line);
    parse(line);
    for (int i = 0; i < 256;  ++i)
    {
        next_day();

    }

    countFish();

}
