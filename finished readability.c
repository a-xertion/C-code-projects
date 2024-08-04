#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int string_length(string s);
bool compareChar(char a, char b);
int main(void)
{
    string text = get_string("Text: ");
    float avgLetters = 0;
    float avgSentences = 0;
    float wordCount = 1;
    //to fing avgLetters in 100 words, need to loop through thing.
    for(int i = 0; i < string_length(text); i++)
    {
        if(text[i] != ' ' && text[i] != '!' && text[i] != '.' && text[i] != '?' && text[i] != ',' && text[i] != '\'')
        //if(strcmp(text[i], " ") != 0)
        {
            avgLetters++;
        }
        bool f = compareChar(text[i], '.');
        //printf(f ? "T" : "F");
        if(compareChar(text[i], '.') || compareChar(text[i], '?') || compareChar(text[i], '!'))
        {
            // printf("BOLLOCKS");|| text[i] == '!'
            avgSentences++;
        }
        else if(text[i] == ' ' && i != string_length(text) - 1)
        {
            wordCount++;
        }
    }
    //printf("this is the avgletters/ wordcount: %f", avgLetters/wordCount);
    //printf("\navgSentences/wordcount: %f", avgSentences/wordCount);
    float index = (0.0588 * (avgLetters/wordCount) * 100.0) - (0.296 * (avgSentences/wordCount) * 100.0) - 15.8;
    //printf("\naverage number of letters: %f\naverage number of sentences: %f\nwordCount: %f", avgLetters, avgSentences, wordCount);
    //printf("\nindex: %f", index);
    int thing = round(index);
    //printf("int version %i", thing);
    if(thing < 0)
    {
        printf("Before Grade 1\n");
    }
    if(thing > 0 && thing < 16)
    {
     printf("Grade %i\n", thing);
    }
    if(thing >= 16)
    {
        printf("Grade 16+\n");
    }
}

int string_length(string s)
{
    int sum = 0;
    while(s[sum] != '\0')
    {
        sum++;
    }
    return sum;
}

bool compareChar(char a, char b)
{
    //printf("i am here");
    /*if(a < b || a > b)
    {
        return false;
    }
    return true;*/
    return a == b;
}
