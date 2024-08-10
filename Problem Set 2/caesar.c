#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int only_digits(int argc, string argv[]);

int main(int argc, string argv[]){

    int key;
    int check = only_digits(argc, argv);

    if(check == -1){

        printf("Usage: ./caesar key\n");
        return 1;
    }
    else{
        //converts string to int
        key = atoi(argv[1]);
    }

    //plaintext input
    string text = get_string("plaintext: \n");

/*         Encipher
convert ASCII to alpha index,
alpha index formula: c_i = (p_i + k) % 26
convert back to ASCII

Preserve caps, number, space and punch.
*/
    printf("ciphertext: ");

    int cip = 0, apl = 0, temp = 0;
    int shift = 0;

    for(int i = 0, len = strlen(text); i < len; i++){

        if (isalpha(text[i])){

            if (isupper(text[i])){
                shift = 65;

            }else if(islower(text[i])){
                shift = 97;
            }
            //convert to alpha index
            apl = text[i] - shift;
            //rotate or enchiper
            temp = (apl + key) % 26;
            //convert back to ASCII
            cip = temp + shift;

            printf("%c", cip);
        }
        else{
            printf("%c", text[i]);
        }
    }
    printf("\n");
    return 0;
}

int only_digits(int argc, string argv[]){

    if (argc != 2){
        return -1;
    }
    //checks the key if it is a digit, looping through the argv array
    //(2D array, 1st element [1][0], 2nd [1][1] and so on
    for (int i = 0, n = strlen(argv[1]); i < n; i++){

        if (isalpha(argv[1][i])){
            return -1;
        }
    }
    return 0;
}
