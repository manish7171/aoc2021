#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BITS_COUNT 5
int bits[BITS_COUNT][2];

int totalLength = 5;
int convertToDecimal(int *num)
{
    int i, deci_num, mul = 0;
    for ( deci_num = 0, i = totalLength - 1; i >= 0; --i, ++mul)
    {

            deci_num = deci_num + (num[i]) * (1 << mul);
    }

    return deci_num;
}

int invertGamaAndConvertToDecimal(int *num)
{
    for ( int i = 0; i < totalLength; i++ ) {

        num[i] = num[i] == 0 ? 1:0;

    }

    return convertToDecimal(num);

}

int day3part1(void)
{
    FILE *fp = fopen("D:\\codepractice\\AdvertCode2021\\day3inputtest.txt","r");
    char  line [100];

    int gama_final_result [totalLength];
    for (int i =0 ; i<totalLength; i++) {
        int zero_count = 0;
        int one_count = 0;
        while ( !feof(fp) ) {
            fgets(line,100,fp);
            int val = line[i]-'0';
            printf("binary %i item %d\n",i, val);

            if (val == 0) {
                zero_count++;
            } else {
                one_count++;
            }

        }

        if ( zero_count > one_count ) {
                gama_final_result[i] = 0;
        } else {
            gama_final_result[i] = 1;
        }

        fseek(fp, 0, SEEK_SET);


    }

     fclose(fp);
     int int_gama_final_result = convertToDecimal(gama_final_result);
     int int_epsilon_final_result = invertGamaAndConvertToDecimal(gama_final_result);
     printf("\ngama = %d\n epsilon = %d\n",int_gama_final_result, int_epsilon_final_result);

     int answer = int_epsilon_final_result * int_gama_final_result;
     printf("\nanswer %d", answer);
    //convertToDecimal(gama_final_result);



    return 0;

}

char getData(FILE *fp, int bit_type, int pos) {
    fseek(fp, 0, SEEK_SET);
    char line [100];
    char *data [12][10];
    while ( !feof(fp) ) {
        int c = 0 ;
        fgets(line,100,fp);

        int val = line[pos] - '0';
        if (val == bit_type ) {
            data[c][10] = line;
            printf("getData %s\n", data[c][10]);
        }

        c++;

    }

    return data;

}

int day3part2(void)
{
    FILE *fp = fopen("D:\\codepractice\\AdvertCode2021\\day3inputtest.txt","r");
    char  line [100];

    int gama_final_result [totalLength];
    for (int i =0 ; i<totalLength; i++) {
        int zero_count = 0;
        int one_count = 0;
        while ( !feof(fp) ) {
            fgets(line,100,fp);
            int val = line[i]-'0';
            printf("binary %i item %d\n",i, val);

            if (val == 0) {
                zero_count++;
            } else {
                one_count++;
            }

        }

        if ( zero_count > one_count ) {
                //save data with 0 at first place
                //gama_final_result[i] = 0;
            int data = getData(fp,0,0);
        } else {
            //save data with 1 at first place
            //gama_final_result[i] = 1;
            int data = getData(fp,1,0);
        }

        //fseek(fp, 0, SEEK_SET);


    }

     fclose(fp);
     int int_gama_final_result = convertToDecimal(gama_final_result);
     int int_epsilon_final_result = invertGamaAndConvertToDecimal(gama_final_result);
     printf("\ngama = %d\n epsilon = %d\n",int_gama_final_result, int_epsilon_final_result);

     int answer = int_epsilon_final_result * int_gama_final_result;
     printf("\nanswer %d", answer);
    //convertToDecimal(gama_final_result);



    return 0;

}

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

void day3part12()
{
    memset(bits, 0, sizeof(bits));
    FILE *fp = fopen("D:\\codepractice\\AdvertCode2021\\day3inputtest.txt","r");
    int *str = fp, gamma = 0, epsilon = 0;
    char  line [100];
    while ( !feof(str) )
    {
        fgets(line, 100 , str );
        int x = convertStrToDecimal(line);

        for (int i = 0; i < BITS_COUNT; ++i)
        {
            bits[i][(x>>i)&1]++;
        }
    }

    for (int i = 0; i < BITS_COUNT; ++i)
    {
        if ( bits[i][0] < bits[i][1] )
        {
            gamma = gamma|(1<<i);
        } else
        {
            epsilon = epsilon|(1<<i);
        }
    }

    printf("part1 answer = %d\n", gamma * epsilon);

    fclose(fp);

    free(fp);

}
