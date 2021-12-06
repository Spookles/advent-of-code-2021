/****
Part 2 just change DAYS on #7 if you want part 1.
****/

#include <stdio.h>

#define DAYS 256

int main() {
    int data[300] = {};
    __uintmax_t buff[9] = {0};
    __uintmax_t fresh[9] = {0};

    for(int x = 0; x < 300; x++) {
        switch(data[x]) {
            case 0:
                buff[0] += 1;
                break;
            case 1:
                buff[1] += 1;
                break;
            case 2:
                buff[2] += 1;
                break;
            case 3:
                buff[3] += 1;
                break;
            case 4:
                buff[4] += 1;
                break;
            case 5:
                buff[5] += 1;
                break;
            case 6:
                buff[6] += 1;
                break;
            case 7:
                buff[7] += 1;
                break;
            case 8:
                buff[8] += 1;
                break;
        }
    }

    for(int i = 0; i < DAYS; i++) {
        for(int fish = 8; fish >= 0; fish--) {
            switch(fish) {
                case 0:
                    buff[6] += buff[0];
                    buff[8] += buff[0];
                    buff[0] = fresh[0];
                    fresh[0] = 0;
                    break;
                case 1:
                    fresh[0] += buff[1];
                    buff[1] = fresh[1];
                    fresh[1] = 0;
                    break;
                case 2:
                    fresh[1] += buff[2];
                    buff[2] = fresh[2];
                    fresh[2] = 0;
                    break;
                case 3:
                    fresh[2] += buff[3];
                    buff[3] = fresh[3];
                    fresh[3] = 0;
                    break;
                case 4:
                    fresh[3] += buff[4];
                    buff[4] = fresh[4];
                    fresh[4] = 0;
                    break;
                case 5:
                    fresh[4] += buff[5];
                    buff[5] = fresh[5];
                    fresh[5] = 0;
                    break;
                case 6:
                    fresh[5] += buff[6];
                    buff[6] = fresh[6];
                    fresh[6] = 0;
                    break;
                case 7:
                    fresh[6] += buff[7];
                    buff[7] = fresh[7];
                    fresh[7] = 0;
                    break;
                case 8:
                    fresh[7] += buff[8];
                    buff[8] = fresh[8];
                    fresh[8] = 0;
                    break;
            }
        }
    }

    printf("Just use a calculator cause I can't be arsed to convert it to strings.\n");
    __uintmax_t totalFish = 0;
    for(int fishCount = 0; fishCount < 9; fishCount++) {
        printf("%ul\n", buff[fishCount]);
    }

    printf("%d\n", totalFish);
    
    return 0;
}
