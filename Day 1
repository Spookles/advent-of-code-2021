/******
Placing line 19 in the right place was the key to success here. I'm scared for what's to come.
******/

#part 1
#include <stdio.h>

int main()
{
    int data[2000] = {0};
    int prev = 0;
    int increase = 0;
    for (int i = 0; i < 2000; i++) {
        if(i!=0) {
         if(data[i] > prev) {
                increase+=1;
            }
        }
        prev = data[i];
    }
    printf("%d", increase);
    return 0;
}

/******
Part 2 was somehow easier than part 1.
******/

#part 2
#include <stdio.h>

int main()
{
    int data[2000] = {0};
    int buff1 = 0;
    int buff2 = 0;
    int increase = 0;
    
    for (int i = 0; i < 1997; i++) {
        for (int b = 0; b < 3; b++) {
            buff1+=data[i+b];
            buff2+=data[i+b+1];
        }
        if(buff2 > buff1) {
            increase+=1;
        }
        buff1 = 0;
        buff2 = 0;
    }
    printf("%d", increase);
    return 0;
}
