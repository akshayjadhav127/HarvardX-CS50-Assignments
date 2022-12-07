#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text : ");

    int words = 1;
    int letters = 0;
    int sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        // by using ascii value for A To Z and a to z
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            letters++;
        }

        else if (text[i] == ' ') //for counting spaces
        {
            words++;
        }

        else if (text[i] == '?' || text[i] == '!' || text[i] == '.') //for counting  ? ! .
        {
            sentences++;
        }
    }

    float S = (float) sentences / (float) words * 100; //S is the average number of sentences per 100 words
    float L = (float) letters / (float) words * 100; //L is the average number of letters per 100 words

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index > 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", index);
    }
}