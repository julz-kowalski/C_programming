
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// this is just basic definitions for integers
// although it is just faster to use int and assume its least size to appease
// platform
#include "../typedefine.c"

// only 4 of one colour can exist in total vials with
// total colours being char size
//
// 3 4 2 5 3 0 0
// 4 3 2 1 5 0 0
// 2 3 4 1 5 0 0
// 1 5 4 1 2 0 0

// numbers can only ever be moved to a zero with either matching or NULL below it



// having this as a char array makes it easier
// to choose between alphabetical or number differentiation
// when I eventually display this
typedef char vial[3];
//
//
//
// theres some argument to implementing this directly into vial,
// especially considering that it's only ever going to be used for vial,
// but i am lazy and what if I want to remake the move function, then all I have to
// do is comment this struct and topvalue then I have a clean slate to modify
// movenum().
//


typedef struct{
    int pos;
    char movevolume;
    char value;
} top;


int colours = 0;


vial* rackinit(int size){


    // TODO     asign rand(); outcomes to colours respective to size, and apply only 4 of each colour to rack
    //          with sum of colours == size
    vial *rack;
    if (size >=5) {
        size = 5;
        colours = size-1;
        vial* rack = malloc(size*sizeof(vial));
    } else {
        colours += (size-2);
        vial* rack = malloc(size*sizeof(vial));
    }



    return rack;
}

// will eventually handle game
void rackrun();


// returns position of highest valid num &&
// value
top topvalue(vial* vial){
    top a;
// implies vials are front to back order
    int i = 0;
    do {
        if (vial[i] == 0) {
            i++;

        }else {
            a.pos = i;
            a.value = *vial[i];

            // move volume == 1 refers to only one would be moved, i.e. There
            // is only one of the same colour, which is value @ pos
            int ii = 1;
            while (&a.value == vial[a.pos+ii]) {
                ii++;
            }
            return a;
        }
    }while (1);
}

// movevolume is 2, pos is 1, so 3.
// toop pos is 4 so it will fit

_Bool validmove(vial *from, vial *to){
    top frop = topvalue(from);
    top toop = topvalue(to);

    // -1 because movevolume is 1 if there isnt any extra
    if ((frop.movevolume - toop.pos) > 0) {
        return 1;
    } else {
    return 0;
    }
}


// moves topmost *from vial value, including descending that are equal
// over to *to
void movenum(vial *from, vial *to){
    top frop = topvalue(from);
    top toop = topvalue(to);
    // should probably be the other way around
    if (validmove(from,to) == 0) {
        // make log file to store errors maybe
        printf("validmove return in movenum returned 0");
    } else {
        // MOVE part of movenum()
        do {
            if (frop.movevolume != 0) {
                toop.pos -= 1;
                char *zero = 0;

                // memcpy better
                // than memmove(because of buffer) and memset is used to initialize
                // data so doesnt work well when data is two bytes long.
                memcpy(from[frop.pos], to[toop.pos], sizeof(char)); // to modify
                memcpy(zero, from[frop.pos] , sizeof(char)); // from modify


                frop.movevolume -= 1;

                frop.pos +=1;
                // vial not assignable
                // to[toop.pos] = from[frop.pos];

            } else {
            break;
            }
        }while (1);
    }
}

// assigns colour randomly to rack, leaves last 8 rack indexes empty
void colour_rando(char* rack){
    // RAND_MAX = int32 limit
    // per colour loop
    if(colours == 0){
        printf("colours initialized but not assigned");
    }else {
        // truncated down, probably look at this for future errors
        int range = RAND_MAX/colours;
        for (int i = 1; i >= colours; i++) {
            // probably abstract randomize selection

            // per colour assignage loop
            for (int ii = 1; ii >= (colours*4); ii++) {
                if( rack[(rand()/range)] == 0 ){
                    rack[(rand()/range)] = i;
                }
            }

        }
    }
}
// NOTE has not been bug tested
