/****
Part 1, (value - '0') because ASCII.
****/

#include <stdio.h>
#include <string.h>

int x = 0;
int y = 0;

int main()
{
    char* data[2000] = {0};
    for (int i = 0; i < 1000; i++) {
        switch(data[i][0]) {
            case 'f':
            x += (data[i][strlen(data[i])-1]) - '0';
            break;
            case 'd':
            y += (data[i][strlen(data[i])-1]) - '0';
            break;
            case 'u':
            y -= (data[i][strlen(data[i])-1]) - '0';
            break;
        }
    }
    printf("%d\n", x*y);
    return 0;
}

/****
Part 2, strings in C are weird, please be the last.
****/

#include <stdio.h>
#include <string.h>

int x = 0;
int y = 0;
int aim = 0;

int main()
{
    char* data[2000] = {0};
    for (int i = 0; i < 1000; i++) {
        switch(data[i][0]) {
            case 'f':
            x += data[i][strlen(data[i])-1] - '0';
            aim += (data[i][strlen(data[i])-1] - '0')*y;
            break;
            case 'd':
            y += data[i][strlen(data[i])-1] - '0';
            break;
            case 'u':
            y -= data[i][strlen(data[i])-1] - '0';
            break;
        }
    }
    printf("%d\n", x*aim);
    return 0;
}
