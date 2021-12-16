#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define XS_CAP 1024
#define BITS_COUNT 12

int xs[XS_CAP];
int xs_removed[XS_CAP];
int xs_sz = 0;
int xs_cnt = 0;

int convertStrToDecimal(char line [] ) {
    int bi = atoi(line);
    int rem, decimal_val = 0 , base = 1;
    while (bi > 0)
    {
        rem = bi % 10;
        decimal_val = decimal_val + rem * base;
        bi = bi / 10 ;
        base = base * 2;

    }

    return decimal_val;
}

int ReadXs()
{
    FILE *fp = fopen("D:\\codepractice\\aoc\\day3\\day3input.txt","r");
    char  line [100];
    int size;

    while ( !feof(fp) )
    {
        fgets(line, 100 , fp );
        xs[xs_sz] = strtol(line, NULL,  2);
        xs_removed[xs_sz] = 0;
        xs_sz++;

    }

    //printf("asdf");
    xs_cnt = xs_sz;

    //printf("%d",xs[1]);
    //printf("Read %d values",xs_sz);

    fclose(fp);

    return 0;

}


void BitsOfXs(int bit_number, int *bits)
{
    memset(bits, 0, sizeof(bits));

    for ( int i = 0; i <xs_sz; ++i )
    {
        if ( xs_removed[i] == 0 )
        {
            //printf("%d ",xs[i]);
            bits[xs[i]>>bit_number&1]++;
        }
    }
}

void DumpXs()
{
  int i, j;
  for (i=0; i <xs_sz; ++i) {
    if (xs_removed[i] == 0) {
      for (j=BITS_COUNT-1; j >= 0; --j) {
        printf("%c", ((xs[i]>>j)&1)+'0');
      }
      printf(": %d\n", xs_removed[i]);
    }
  }

}

int SearchValue(int common)
{
    int bit_number = BITS_COUNT - 1;
    int bits[2], bit, j;

    //printf("%d size of ",sizeof(xs_removed));

    memset(xs_removed, 0, sizeof(xs_removed));
    //printf("xs_sz %d ",xs_sz);
    xs_cnt = xs_sz;
    //printf("xs_cnt %d ",xs_cnt);
    while (xs_cnt > 1)
    {
        BitsOfXs(bit_number, bits);

        for (int i = 0; i < xs_sz; ++i)
        {

            if ( xs_removed[i] == 0)
            {
                bit = (xs[i]>>bit_number)&1;

                if (common == 1)
                {
                   if ((bits[1] >= bits[0]) != (bit == 1))
                    {
                        xs_removed[i] = 1;
                        xs_cnt--;
                    }
                }
                 else
                {
                    if ((bits[1] >= bits[0]) == (bit == 1))
                    {
                        xs_removed[i] = 1;
                        xs_cnt--;
                    }
                }
            }
        }

        bit_number--;
//        j += 1;
//
//        if (j >=2)
//        {
//            DumpXs();
//            //return;
//        }
        //printf("xs_cnt: %d\n",xs_cnt);
    }

    for (int i = 0; i < xs_sz; ++i)
    {
        if ( xs_removed[i] == 0)
        {
            return xs[i];
        }
    }

    return 0;
}

int main()
{

    ReadXs();
    int oxygen = SearchValue(1);
    int co2 = SearchValue(0);
    printf("oxygen: %d\n", oxygen);
    printf("co2:    %d\n", co2);
    printf("Part 2: %d\n", oxygen*co2);

}
