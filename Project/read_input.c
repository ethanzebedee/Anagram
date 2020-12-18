//Ethan Hammond 19314353

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "library.h"

int main(void)
{
    static const char filename[] = "C:/Users/goned/OneDrive/Desktop/Project/input.txt"; //declares filepath

    static const char outputname[] = "C:/Users/goned/OneDrive/Desktop/Project/output.txt"; //declares filepath

    char *line_array[1000]; //declares arrays
    char line[1024];
    int i = 0; //ints for for loops
    int j = 0;

    FILE *file = fopen(filename, "r"); //opens file

    FILE *Output = fopen(outputname, "w+"); //opens file

    if (file != NULL) //if file doesn't open
    {
        while (fgets(line, sizeof line, file) != NULL){ //until file has been run through

            line[strcspn(line, "\n")] = '\0';
            //stops processing if line_array is full
            if (i < sizeof line_array / sizeof *line_array)
            {
                line_array[i++] = _strdup(line); //allocates new storage space
            }
            else
            {
                break;
            }
        }
        fclose(file); //closes file once all anagrams are uploaded

        sort_a(line_array, i); //quicksorts the array

        fprintf(Output, "The sorted list of words follows:\n");

        for (j = 0; j < i; j++)
        {
            fprintf(Output, "%s\n", line_array[j]); //prints sorted array
        }

        fprintf(Output, "\nThe list of anagrams follows: \n");

        for (int f = 0; f < i; f++) //for loops run through arrays
        {
            for (j = f; j < i; j++)
            {
                if (line_array[j] != line_array[f]) //won't say same sentences are anagrams of eachother
                {

                    if (check_anagram(line_array[j], line_array[f])) //sends arrays to check anagram function
                    {

                        fprintf(Output, "%s is an anagram of %s \n", line_array[j], line_array[f]); //prints anagrams

                        
                    }

                }
            }
        }

         fprintf(Output, "\nThe list of missing anagrams follows: \n");

        for (int f = 0; f < i; f++) //for loops run through arrays
        {
            for (j = f; j < i; j++)
            {
                if (line_array[j] != line_array[f]) //stops same sentences from going in
                {
                    int missingLetters = check_miss_anagram(line_array[j], line_array[f]); //Gets number of characters to remove
                   
                    if (missingLetters > 0 && missingLetters < 4) //stops incorrect values
                    {

                        fprintf(Output, "%s is an anagram of %s if %d characters removed \n", line_array[j], line_array[f], missingLetters);
                    }

                }
            }
        }
    }
    else
    {
        perror(filename); //prints error
    }

    fclose(Output); //closes output file

    return 0;
}

