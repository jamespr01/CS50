#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>


int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int CLI(int letters, int words, int sentences);

int main(void){

    // Prompt the user for some text
    string text = get_string("Text: \n");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Compute the Coleman-Liau index
    int index = CLI(letters, words, sentences);

    // Print the grade level
    if(index < 1){
        printf("Before Grade 1\n");

    }else if (index > 16){
        printf("Grade 16+\n");
    }
    else{ printf("Grade %d\n", index);
    }
}

int count_letters(string text){
    /*letters: count upper and lower case letters in text; string is array of chars <c.type> will help*/
    int count = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isupper(text[i]))
        {
            count++;
        }
        else if (islower(text[i]))
        {
            count++;
        }
    }
return count;
}

int count_words(string text){
    /* count number of whitespaces = 32 in ascii table, in the array, words = spaces + 1 (no space at start and end of a sentence.)*/
    int count = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if(text[i] == 32)
            count++;
    }
return count+1;
}

int count_sentences(string text){
    /*count punctuation e.g. (. = 46,  ? = 63 ! = 33 from acsii table) indicates end of sentence*/
    int count = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if(text[i] == 46 || text[i] == 33 ||  text[i] == 63)
            count++;
    }
return count;
}

int CLI(int letters, int words, int sentences){
/* n =  0.0588 * L - 0.296 * s - 15.8

L is avg number of LETTERS per 100 words
S is avg number of SENTENCES per 1000 words */

    float L = (float) letters * 100 / (float) words;
    float s = (float) sentences* 100 /(float) words;
    int n = round(0.0588 * L - 0.296 * s - 15.8);

return n;
}
