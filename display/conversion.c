
#include <stdio.h>
#define RESET "\e[0;0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32"
#define BLUE "\e[0;34m"
#define MAGENTA "\e[0;35m"
#define CYAN "\e[0;36m"
#define WHITE "\e[0;37m"


// fills buffer with red
void default_display(char* buffer, int* resolution){
    for (int i = 0; i < resolution[0] * resolution[1]; i++) {
        buffer[i] = 'r';
    }
}

// print row of buffer up to resolution (width+\n) for each height
void render_screen(char* buffer, int* resolution){
    // per column
    for (int i = 0; i < resolution[1]; i++) {
        // per row
        for (int e=0; e < resolution[0]; e++) {
            switch (buffer[e]) {
                case 'r':
                    printf("%s█",RED);
                    break;
                case 'g':
                    printf("%s█", GREEN);
                    break;
                case 'b':
                    printf("%s█", BLUE);
                    break;
                case 'm':
                    printf("%s█", MAGENTA);
                    break;
                case 'c':
                    printf("%s█", CYAN);
                    break;
                case 'w':
                    printf("%s█", WHITE);
                    break;
                default:
                    printf("█");
                    break;
            }

        }
        // inside column for loop, moves down to next line to print
        printf("\n");
    }
}
