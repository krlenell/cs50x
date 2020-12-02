#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float get_average_letters(int letters, int words);

float get_average_sentences(int sentences, int words);


int main(void)
{
    //assumes there is 1 word in each passage
    int words = 1;
    int sentences = 0;
    int letters = 0;

    string text = get_string("Text: ");
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        //determines what to do for each given character
        switch (text[i])
        {
            case ' ':
                words++;
                break;

            case '.':
            case '!':
            case '?':
                sentences++;
                break;

            default:
                if (isalpha(text[i]))
                {
                    letters++;
                }
        }
    }
    float average_letters = get_average_letters(letters, words);
    float average_sentences = get_average_sentences(sentences, words);
    //calculates grade level by Coleman-Liau index
    float grade_level = 0.0588 * average_letters - 0.296 * average_sentences - 15.8;
    int rounded_level = (int) round(grade_level);
    //decides what to print for each rounded level result
    if (rounded_level < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (rounded_level >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", rounded_level);
    }
}

float get_average_letters(int letters, int words)
{
    //gets average letters per 100 words
    float result = ((float) letters / words) * 100;
    return result;
}

float get_average_sentences(int sentences, int words)
{
    //gets average sentences per 100 words
    float result = ((float) sentences / words) * 100;
    return result;
}
