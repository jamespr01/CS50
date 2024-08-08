#include <cs50.c>
#include <stdio.h>
/*
American express, AMEX: 15 digits, starts with 34 or 37
Visa, VISA: 13 or 16 digits, starts with 4
MasterCard, MASTERCARD: 16 digits, starts with 51, 52, 53, 54 or 55

How to get last digit of a long number: % 10 gives the last number
*/

int checksum(m);
void card(long b);

int main(void){

    //user input card number
    long long int n;
    do
    {
        n = get_long("Credit card number: ");
    } while (0 < n < 16);

    //calc check sum 
    checksum(n);

    //check length of number: identify type of card (start digits)
    int a = card(n);


    //prints out card type
    printf("%s", card(n))
    //

}

int checksum(long m){
        
        while (m > )){
        //get last digit
        int last_digit = m % 10;

        //multiply every other digit by 2 starting with 2nd to last digit
        printf("%d", last_digit)
    }
    
}

void card(long b){

    int AE1 = 34, AE2 = 37;
    int VISA = 4;
    int MC1 = 51, MC2 = 52, MC3 = 53, MC4 = 54, MC5 = 55;
    int len = 0, bank = 0;

    //create counter/length of card number
    while (b > 0)
    {
        b /= 10;
        len++;
    }
    //check number for each bank
    if (len == 15){

        int temp1 = b / 10000000000000;

        if (temp1 == AE1 || temp1 == AE2){
            bank = 1;   //its amex
        }
    }
    else if (len == 13){

        int temp2 = b / 1000000000000;

        if (temp2 == VISA){
            bank = 2;     // its visa
        }
    }
    else if (len == 16){

        int temp3 = b / 1000000000000000;

        if (temp3 == 4){
            bank = 2; // its visa
        }
        else bank = 3; // its mc
    }
    
return bank; 
}


