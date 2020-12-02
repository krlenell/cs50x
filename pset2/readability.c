#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

float get_average_letters (int letters, int words);

float get_average_sentences (int sentences, int words);



//index = 0.0588 * L - 0.296 * S - 15.8

//L = average letter per 100 words

//S = average number of sentences per 100 words

int main (void)
{
    int words = 1;
    int sentences = 0;
    int letters = 0;

    string text = get_string("Text: ");
    int length = strlen(text);

    for(int i = 0; i < length; i++)
    {
        printf("%c", text[i]);
        switch(text[i])
        {

            case ' ':
                words++;
                printf("new word\n");
                break;

            case '.':
            case '!':
            case '?':
                sentences++;
                printf("new sentence\n");
            default:
                if(isalpha(text[i]))
                {
                letters++;
                }
        }
    }
    printf("words: %i\n", words);
    printf("sentences: %i\n", sentences);
    printf("letters: %i\n", letters);
}

float get_average_letters (int letters, int words)
{
    //gets the average number of letters per 100 words
    return 1;
}

float get_average_sentences (int sentences, int words)
{
    //gets average sentences per 100 words
    return 1;
}



/*
When he was nearly thirteen, my brother Jem got his arm badly broken at the elbow. When it healed, and Jem's fears of never being able to play football were assuaged, he was seldom self-conscious about his injury. His left arm was somewhat shorter than his right; when he stood or walked, the back of his hand was at right angles to his body, his thumb parallel to his thigh.
295 letter(s)
70 word(s)
3 sentence(s)
*/
