
//  screen is 2dspace




// #define RESET "\e[0;0m"
// #define RED "\e[0;31m"
// #define GREEN "\e[0;32"
// #define BLUE "\e[0;34m"
// #define MAGENTA "\e[0;35m"
// #define CYAN "\e[0;36m"
// #define WHITE "\e[0;37m"


#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//
char red = 'r';
char green = 'g';
char blue = 'b';
char magenta = 'm';
char cyan = 'c';
char white = 'w';

typedef char Pixel[2];






void bufferadd(Pixel pixel, int *screen){
    int result = pixel[1]*pixel[2];
    screen[result] = pixel[0];
}




//  makes pixel pointer to store in buffer
Pixel* pixel(const char colour, char x, char y){
    Pixel *a = malloc(2);
    *a[0] = colour; *a[1] = x; *a[2] = y;


    return a;
}
// CURRENT
// handles both RESOLUTION && returns buffer*
char* res(int *resolution){

    int* width = &resolution[0];
    int* height = &resolution[1];

    // scanf("%d",&width);
    // resolution[0] = width;
    // scanf("%d",&height);
    // resolution[1] = height;

    // default res1 = 18, res0 = 32
    if (resolution[1] < 8 || resolution[0] < 8 ){
        resolution[1] = 18; resolution[0] = 32;
    }

    printf("width: %d\n", *width);

    printf("height: %d\n", *height);

    char *scrn_buffer = malloc((*width * *height) * sizeof(char));
    return scrn_buffer;
}


// OLD makes resolution
// int* buffer(int* resolution){

// //  FULL size of pixel buffer, used by bufferadd
//     int *screen = malloc((resolution[0]* resolution[1]) * 2);

//     return screen;
// }



// struct PIXEL{
//     char colour;
//     char x;
//     char y;
// };

// char buffer[100];

// struct PIXEL pixel(char colour, char x, char y){
//     const struct PIXEL i = {colour, x , y};
//     return i;
// struct PIXEL a = pixel(red, 10,10);
// }
