#include <cs50.h>
#include <stdio.h>

int main(void){

    int i, j, k, h;

    // Asking for user to input height between 1 and 8
    do{
        h = get_int("Enter Height: ");
    } while (!(h > 0 && h < 9));
    
    // Creating the stair

    // columns
    for(i = 0; i < h; i++){

        //rows
        for(j = h - i - 2; j > -1; j--){  
            printf(" ");
        }
        for(k = 0; j < i; j++){
            printf("#");
        }
        printf("\n");        
    }
}