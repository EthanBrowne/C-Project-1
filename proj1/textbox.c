/**
@file textbox
@author Ethan Browne, efbrowne
The purpose of this file is to print text from standard input, but with a border around the text.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/** Width of each line of text in the box. */
#define LINE_WIDTH 60

/** Symbol used to draw the border around the box. */
#define BORDER '*'

/**
Prints a line of chars with a boarder around each side. If the text is longer than it ignores the input. If the text is shorter than it adds spacing
@return if the char has reached EOF yet
*/
bool paddedLine()
{
  // The char that is being read
  int ch = getchar();
  if (ch == EOF){
    return false;
  }
  putchar(BORDER);
  int counter = 0;
  // Repeats until it reaches end of file, end of line, or gets to the line length
  while (ch != EOF && ch != '\n' && counter < LINE_WIDTH){
    putchar(ch);
    counter++;
    ch = getchar();
  }
  //If it gets to the end of the line and hasn't reached line width fill in the rest with spaces
  if (ch == '\n'){
    for (int i = 0; i < (LINE_WIDTH)-counter; i++){
      putchar(' ');
    }
  //If it gets to the line width and hasn't reached end of line read all the rest of characters
  } else if (counter == LINE_WIDTH){
    while (ch != '\n'){
      ch = getchar();
    }
  }
  putchar(BORDER);
  printf("\n");
  return true;
}

/**
Prints a boarder line of chars
*/
void lineOfChars( char ch, int count )
{
  // Prints a line of chars with count length
  for (int i = 0; i < count+2; i++){
    putchar(ch);
  }
  printf("\n");
}

/**
The main function of the program. Calls the line of chars function at the beginning and end of the function. Calls the padded line function till false.
@return EXIT_SUCCESS if the program was a success
*/
int main()
{
  lineOfChars(BORDER, LINE_WIDTH);
  // While the previous line was read successfully read another line
  bool call = true;
  while (call){
    call = paddedLine();
  }
  lineOfChars(BORDER, LINE_WIDTH);
  return EXIT_SUCCESS;
}
