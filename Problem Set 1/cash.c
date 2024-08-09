#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void){

    float cash;
    //prompt user
    do
    {
        cash = get_float("Change owed: ");
    } while (cash < 0);

    //convert dollars to cents, float to int
    //int cents = round(cash * 100);
    int cents = round(cash);

    //greedy algo
    int count = 0;
    while (cents > 0){
        if (cents >= 25)
        {
            cents -= 25;
            count++;
        }
        else if (cents >= 10)
        {
            cents -= 10;
            count++;
        }
        else if (cents >= 5)
        {
            cents -= 5;
            count++;
        }
        else if (cents >= 1)
        {
            cents -= 1;
            count++;
        }
        else
        {
            count = 0;
        }
    }
    //print min count of coins used
    printf("%i \n", count);
}
