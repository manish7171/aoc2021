#include <string.h>
#include <stdlib.h>

void parseLine(char line [], int *position, int *depth) {

    int val = line[strlen(line)-2] - '0';
    //forward
    if ( strlen(line) == 10 ) {
        *position = *position + val;
    }
    // down
    if ( strlen(line) == 7 ) {
        *depth  = *depth  + val;
    }
    // up
    if ( strlen(line) == 5 ) {
        *depth  = *depth  - val;
    }


}

void parseLineTwo(char line [], int *position, int *depth, int *aim) {

    int val = line[strlen(line)-2] - '0';
    //forward
    if ( strlen(line) == 10 ) {
        *position = *position + val;
        *depth = *depth+ (val * *aim);
    }
    // down
    if ( strlen(line) == 7 ) {
        *aim  = *aim  + val;
    }
    // up
    if ( strlen(line) == 5 ) {
        *aim  = *aim  - val;
    }


}
int day2part1(void) {
    int depth = 0 ;
    int position = 0;
    const int LENGTH_LINE = 100;
    char line[LENGTH_LINE];
    int len;

    FILE* fp = fopen("D:\\codepractice\\AdvertCode2021\\day2input.txt", "r");

    while (!feof(fp) ) {
        fgets(line,LENGTH_LINE,fp);
        parseLine(line, &position, &depth);

    }

    printf("anwser is %d", position * depth);

    return 0;

}

int day2part2(void) {
    int depth = 0 ;
    int position = 0;
    int aim = 0;
    const int LENGTH_LINE = 100;
    char line[LENGTH_LINE];
    int len;

    FILE* fp = fopen("D:\\codepractice\\AdvertCode2021\\day2input.txt", "r");

    while (!feof(fp) ) {
        fgets(line,LENGTH_LINE,fp);
        //printf("line %s\n", line);
        parseLineTwo(line, &position, &depth, &aim);
        //printf("position is %d, depth is %d, aim is %d\n", position , depth, aim);
        //sleep(5);

    }

    printf("anwser is %d", position * depth);

    return 0;

}


