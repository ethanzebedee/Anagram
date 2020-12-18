#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "library.h"

void sort_a(void *array, unsigned n)
{
    quicksort_strs(array, n); //passes relevant functions onwards, became obsolete a while ago, too lazy to remove
}


void quicksort_strs(char const *args[], unsigned int len) //quicksorts arrays
{
    unsigned int i, pvt = 0;

    if (len <= 1)
    {
        return;
    }
    //swaps a randomly selected value to the last node
    swap_str_ptrs(args + ((unsigned int)rand() % len), args + len - 1); //swaps pointers

    //resets the pivot index to zero, then scans
    for (i = 0; i < len - 1; ++i)
    {
        if (strcasecmp(args[i], args[len - 1]) < 0) //compares letters
        {
            swap_str_ptrs(args + i, args + pvt++);
        }
    }

    // move the pivot value into its place
    swap_str_ptrs(args + pvt, args + len - 1);

    //invokes itself
    quicksort_strs(args, pvt++);
    quicksort_strs(args + pvt, len - pvt);
}

void swap_str_ptrs(char const **arg1, char const **arg2) //swaps string pointers
{
    const char *tmp = *arg1;
    *arg1 = *arg2;
    *arg2 = tmp;
}

int check_anagram(char x[], char y[])
{

    char first[26] = {0};
    char second[26] = {0};
    int charFreq = 0;

    // Calculating frequency of characters of the first string

    while (x[charFreq] != '\0')
    {

        if (x[charFreq] >= 'a' && x[charFreq] <= 'z')
        {
            first[x[charFreq] - 'a']++;
        }
        else if (x[charFreq] >= 'A' && x[charFreq] <= 'Z')
        {

            first[x[charFreq] - 'A']++;
        }

        charFreq++;
    }

    charFreq = 0;

    while (y[charFreq] != '\0')
    {

        if (y[charFreq] >= 'a' && y[charFreq] <= 'z')
        {
            second[y[charFreq] - 'a']++;
        }
        else if (y[charFreq] >= 'A' && y[charFreq] <= 'Z')
        {

            second[y[charFreq] - 'A']++;
        }

        charFreq++;
    }

    // Comparing the frequency of characters

    for (charFreq = 0; charFreq < 26; charFreq++)
    {

        if (first[charFreq] != second[charFreq]) //checks if not an anagram
        {

            return 0;
        }
    }

    return 1; //returns 1 if it is an anagram
}

int check_miss_anagram(char z[], char w[])
{
    //array for both string and calculate frequency of each character

    int count1[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int count2[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int answer = 0;
    int l = 0;

    if (strlen(z) == strlen(w))
    {
        return 0;
    }

    //counts frequency of each character in first string
    for (l = 0; z[l] != '\0'; l++)
    {

        if (z[l] >= 'A' && z[l] <= 'Z')
        {

            count1[z[l] - 'A']++;
        }
        else if (z[l] >= 'a' && z[l] <= 'z')
        {

            count1[z[l] - 'a']++;
        }
    }


    l = 0;
    //counts frequency of each character in second string

    for (l = 0; w[l] != '\0'; l++)
    {

        if (w[l] >= 'A' && w[l] <= 'Z')
        {
            count2[w[l] - 'A']++;
        }
        else if (w[l] >= 'a' && w[l] <= 'z')
        {
            count2[w[l] - 'a']++;
        }
    }
 
    //traverses array and removes characters
    answer = 0;
    l = 0;
    for (l = 0; l < 26; l++)
    {
 
        answer += abs(count1[l] - count2[l]);
    }

    return answer;
}
