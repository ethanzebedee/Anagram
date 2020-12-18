#ifndef SOFTWARE_PROJECT_LIBRARY_H
#define SOFTWARE_PROJECT_LIBRARY_H



void sort_a(void *array, unsigned n); //Declares function to sort anagrams

int check_anagram(char x[], char y[]); //Declares function to check anagrams

int check_miss_anagram(char z[], char w[]); //Checks number of letters needed for missing anagrams

void swap_str_ptrs(char const **arg1, char const **arg2); //swaps string pointers for quicksort

void quicksort_strs(char const *args[], unsigned int len); //quicksorts strings

#endif //SOFTWARE_PROJECT_LIBRARY_H