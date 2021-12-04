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

/****
Part 2 I hate this so much
****/

#include <stdio.h>
#include <string.h>


char verticalCommon(char* data[], int column, int size, int whichOne);
char clearArray(char* data[]);

int main() {
    char* data[1000] = {"111010111011"}; //input as binary strings

    char* buff1[1000] = {0};
    memcpy(buff1, data, sizeof(data));
    char* buff2[1000] = {0};

    int counter = 0;

    //oxygen
    for(int o = 0; o < 12; o++) {
        if(buff1[1] != NULL) {
            char common = verticalCommon(buff1, o, sizeof(buff1)/sizeof(buff1[0]), 1);
            for(int x = 0; x < 1000; x++) {
                if(buff1[x] != NULL) {
                    if(buff1[x][o] == common) {
                        buff2[counter] = buff1[x];
                        counter+=1;
                    }
                } else {
                    buff2[x] = NULL;
                }
            }
        } else {
            printf("oxy: %s\n", buff1[0]);
        }
        clearArray(buff1);
        for(int y = 0; y < 1000; y++) {
            if(buff2[y] != NULL) {
                buff1[y] = buff2[y];
            } else {
                buff1[y] = NULL;
            }
        }
        clearArray(buff2);
        counter = 0;
    }

    //c02
    memcpy(buff1, data, sizeof(data));
    for(int o = 0; o < 12; o++) {
        if(buff1[1] != NULL) {
            char common = verticalCommon(buff1, o, sizeof(buff1)/sizeof(buff1[0]), 0);
            for(int x = 0; x < 1000; x++) {
                if(buff1[x] != NULL) {
                    if(buff1[x][o] == common) {
                        buff2[counter] = buff1[x];
                        counter+=1;
                    }
                } else {
                    buff2[x] = NULL;
                }
            }
        } else {
            printf("co2: %s\n", buff1[0]);
        }
        clearArray(buff1);
        for(int y = 0; y < 1000; y++) {
            if(buff2[y] != NULL) {
                buff1[y] = buff2[y];
            } else {
                buff1[y] = NULL;
            }
        }
        clearArray(buff2);
        counter = 0;
    }

    return 0;
}

char verticalCommon(char* data[], int column, int size, int whichOne) {
    int zero = 0;
    int one = 0;
    for(int x = 0; x < size; x++) {
        if(data[x] != NULL) {
            switch(data[x][column]) {
                case '0':
                zero+=1;
                break;
                case '1':
                one+=1;
                break;
            }
        }
    }
    if(zero > one) {
        if(whichOne == 1) {
            return '0';
        } else {
            return '1';
        }
    } else {
        if(whichOne == 1) {
            return '1';
        } else {
            return '0';
        }
    } 

}

char clearArray(char* data[]) { //memset didn't clear the entire array so this did the trick :(
    for(int i = 0; i < 1000; i++) {
        data[i] = NULL;
    }
    return data;
}
