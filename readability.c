#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// By Edward Giovanni Luna

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    int letter_count = count_letters(text);
    int word_count = count_words(text);
    int sentence_count = count_sentences(text);

    // For testing counting functions
    // printf("%i letters\n", letter_count);
    // printf("%i words\n", word_count);
    // printf("%i sentences\n", sentence_count);

    float l = (float)letter_count / word_count * 100;
    float s = (float)sentence_count / word_count * 100;

    int index = round(0.0588 * l - 0.296 * s - 15.8);

    printf("Index: %i\n", index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    int letter_count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int ord = text[i];
        if (ord >= 65 && ord <= 90)
        {
            text[i] += 32;
        }

        if (text[i] >= 97 && text[i] <= 122)
        {
            letter_count++;
        }
    }

    return letter_count;
}

int count_words(string text)
{
    int word_count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 32)
        {
            word_count++;
        }
    }
    return word_count + 1;
}

int count_sentences(string text)
{
    int sentence_count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentence_count++;
        }
    }

    return sentence_count;
}