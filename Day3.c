/****
Part 1
****/

#include <stdio.h>

int main() {
    char* data[1000] = {"111010111011"}; //input as binary strings
    int gamma[12] = {0};
    int epsilon[12] = {0};
    int column = 0;
    int zero = 0;
    int one = 0;
    for(int o = 0; o < 12; o++) {
        for(int x = 0; x < 1000; x++) {
            switch(data[x][o]) {
                case '0':
                zero+=1;
                break;
                case '1':
                one+=1;
                break;
            }
        }
        if(zero > one) {
            gamma[o] = 0;
            epsilon[o] = 1;
        } else {
            gamma[o] = 1;
            epsilon[o] = 0;
        }  
        zero = 0;
        one = 0;
    }
    for(int i = 0; i < 12; i++) {
        printf("%d", gamma[i]);
    }
    printf("\n");
    for(int i = 0; i < 12; i++) {
        printf("%d", epsilon[i]);
    }
    return 0;
}
