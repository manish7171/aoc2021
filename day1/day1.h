

#include <stdio.h>
#include <stdlib.h>

int day1part1(void) {
    int num;

    FILE * inputFile = fopen("D:\\codepractice\\AdvertCode2021\\day1input.txt", "r");

    if ( inputFile == NULL ) {
        printf("error opening file");

        exit;
    }

    int answer = 0;
    int prev = 0;


    while ( fscanf(inputFile, "%d", &num) != EOF) {

        if ( num > prev && prev > 0) {
            answer++;
        }

        prev = num;
    }

    printf("answer = %d\n", answer);
    fclose(inputFile);



    return 0;
}

int day1part2(void) {
    int d;
    int answer = 0;

    FILE * inputFile = fopen("D:\\codepractice\\AdvertCode2021\\day1input.txt", "r");

    if ( inputFile == NULL ) {
        printf("error opening file");

        exit;
    }

    int a;
    int b;
    int c;

    fscanf(inputFile, "%d", &a);
    fscanf(inputFile, "%d", &b);
    fscanf(inputFile, "%d", &c);

    while ( fscanf(inputFile, "%d", &d) != EOF) {

        if ( b+c+d > a+b+c) {
            answer++;
        }

        a = b;
        b = c;
        c = d;
    }

    printf("answer = %d\n", answer);
    fclose(inputFile);

    return 0;
}


