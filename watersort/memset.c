




#include <stdio.h>
#include <string.h>
int main(){
    int a = 10;

    int *b;
    *b = 5;
    // memset(b, a, sizeof(int));
    memcpy(&a, b, sizeof(int));
    printf("%d\n",a);



    return 0;
}
