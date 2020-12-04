#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

const int KEYLENGTH = 26;


int make_key(int *key, string);


int main(int argc, string argv[])
{
    //if there is no second argument, or is a third argument, shut it down
    if (argc != 2)
    {
        printf("Error: no key provided\n");
        return 1;
    }
    string input = argv[1];
    //if the input is not 26 char, shut it all down
    if (strlen(input) != KEYLENGTH)
    {
        printf("Error: Input is not 26 characters\n");
        return 1;
    }
    int key[KEYLENGTH];

    if (make_key(key, input))
    {
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    int length = strlen(plaintext);
    char result[length];
    for (int i = 0; i < length; i++)
    {
        if (isalpha(plaintext[i]))
        {
            char replace = plaintext[i] - key[(int) toupper(plaintext[i]) - 65];
            plaintext[i] = replace;
        }
    }

    printf("ciphertext: %s\n", plaintext);
}

int make_key(int *key, string input)
{
    int check[26] = {0};
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
        int check_index = toupper(input[i]) - 65;
        check[check_index] += 1;
        if (check[check_index] > 1)
        {
            printf("Error: repeated characters in key\n");
            return 1;
        }
    }
    //im too lazy for proper comments, sorry
    return 0;
}
