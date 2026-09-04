


#include <stdatomic.h>
#include <stdio.h>
#include <threads.h>
//
//
#include "environment.c"
#include "conversion.c"




_Bool quitcheck(){
    char x = getchar();
    switch (x) {
        case 'q':
            printf(RESET);
            return 0;
        default:
            return 1;
    }
}



int main(){



    int resolution[2];


    // height
    resolution[0] = 6;
    // width
    resolution[1] = 6;

    // WILL DEFAULT TO 36 18 respectively
    char *buffer = res(resolution);

//
//     int* screen = buffer(resolution);





    while(1){
        system("clear");
        default_display(buffer, resolution);
        render_screen(buffer, resolution);
    }
    printf("%s",RESET);
    return 0;
}
