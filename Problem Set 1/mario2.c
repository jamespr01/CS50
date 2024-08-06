#include <cs50.c>
#include <stdio.h>

void main(){

    int i, j, k, h, l;

    // Asking for user to input height between 1 and 8
    do{
        h = get_int("Enter Height: ");
    } while (!(h > 0 && h < 9));
    
    // Creating the pyramid

    // columns
    for(i = 0; i < h; i++){

        //rows
        for(j = h - i - 2; j > -1; j--){  
            printf(" ");
        }
        for(k = 0; j < i; j++){
            printf("#");
        }

        printf(" ");

        //left aligned #
        for(l = 0; l < i+1; l++ ){
            printf("#");
        }
        printf("\n");        
    }
}