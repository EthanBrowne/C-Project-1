/**
@file style
@author Ethan Browne, efbrowne
The purpose of this file is to print a paragraph of words.
The file has three functions 
*/

#include <stdio.h>
#include <stdlib.h>
/**
The size of a line
*/
#define LINE_SIZE 72
/**
This function prints random lower case letters in a row to make a word.
@param x - the number of lower case letters to print
*/
void printWord( int x )
{
    // Repeats for x times
    for ( int i = 0; i < x; i++ )
    {
        // Print a random lower-case letter.
        printf( "%c", 97 + rand() % 26 );
    }
}
/**
This function prints a line of words. It calls the printWord function and gives it a number 1-10 to make a word of that length. It keeps doing this until the length of the line is greater then 72 spaces.
@return number of words in the printed line
*/
int printLine()
{
    //count is the number of words, pos is the length if the word + 1, space is 0 until it has the first space
    int count = 0, pos = 0, space = 0;
    // Generates random # 1-10
    int len = 1 + rand() % 10;
    // Print a line of words up to a limited length.
    while ( pos + len + space < LINE_SIZE ){
        if ( space > 0 ) {
            printf(" ");
        }
        printWord( len );
        pos += len + space;
        len = 1 + rand() % 10;
        space = 1;
        count += 1;
    }
    printf("\n");
    return count;
}
/**
This function prints a paragraph with n lines and returns the number of words in the paragraph. Calls printline function
@param n - The number of lines in the paragraph.
@return the number of words in the paragraph
*/
int printParagraph( int n )
{
    //Total number of words
    int total = 0;
    // Runs for i times
    for ( int i = 0; i < n; i++ ){
        total += printLine();
    }
    return total;
}
/**
Main function. Runs the print paragraph function with 10 lines. Then prints out the number of words
@return EXIT_SUCCESS if the program is successful
*/
int main(){int w=printParagraph(10);printf("Words: %d\n",w);return EXIT_SUCCESS;}