#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

const int KEYLENGTH = 26;


int main(int argc, string argv[])
{
    //if there is no second argument, or is a third argument, shut it down
    if (argc != 2)
    {
        printf("Error: no key provided\n");
        return 1;
    }
    string input = argv[1];
    printf("input: %s\n", input);
    //if the input is not 26 char, shut it all down
    if (strlen(input) != KEYLENGTH)
    {
        printf("Error: Input is not 26 characters\n");
        return 1;
    }
    char test = 'A' - ('A' - (int) 'F');
    printf("test: %c\n", test);
    int key[KEYLENGTH];
    //parse the key into an array with each index being a difference between key and original character
    for (int i = 0; i < KEYLENGTH; i++)
    {
        //if a character is not a letter, shut it all down
        if (!isalpha(input[i]))
        {
            printf("Error: Some characters are not letters\n");
            return 1;
        }
        key[i] = (i + 65) - toupper(input[i]);
    }
}
