/**
@file trig
@author Ethan Browne
Approximates the values of sin, cos, and tan using the taylor series.
*/
#include <stdio.h>
#include <stdlib.h>

/** Approximation of PI.  For now, we're using our own constant for
    this. There's also one provided by the gnu math library, once we
    learn about that. */
#define PI 3.14159265358979323846

/**
Scans for a angle and checks to see if it is in the right bounds
@return the angle
*/
double getAngle()
{
  // The angle that the user wants to use
  double angle;
  int counter = scanf("%lf", &angle);
  if (counter <= 0 || angle > PI || angle < -1*PI){
    printf("Invalid input\n");
    exit(EXIT_FAILURE);
  }
  return angle;
}

/**
Calculates the difference between two doubles
If the difference is negative then makes it positive
@param a the first double
@param b the second double
@return the difference
*/
double difference( double a, double b )
{
  // The difference between the doubles
  double difference = a - b;
  if (difference < 0){
    difference *= -1;
  }
  return difference;
}

/**
Prints out the header for the table
*/
void tableHeader()
{
  printf("terms |         sin |         cos |         tan \n------+-------------+-------------+-------------\n");
}

/**
Prints out the different rows for the table
@param terms the row number
@param s the sin value
@param c the cos value
@param t the tan value
*/
void tableRow( int terms, double s, double c, double t )
{
  printf("   %2d", terms);
  printf(" | %11.7f", s);
  printf(" | %11.7f", c);
  printf(" | %11.7f\n", t);
}

/**
This function sets up the table and does the taylor series for both sin and cos. It keeps calculating until the values differ less than 0.000001.
@return EXIT_SUCCESS if the program ran correctly
*/
int main()
{
  // The angle the user submitted
  double angle = getAngle();
  // This variable gets multiplied by the angle in the loop
  double anglePower = 1;

  tableHeader();
  // How many times the loop has run
  int index = 0;
  // This variable stores the factorial
  double factorialCounter = 1;
  // The aproximation for sin
  double sin = 0;
  // The approximation for cos
  double cos = 0;
  // The previous value for sin
  double prevSin = 1;
  // The previous value for cos
  double prevCos = 0;

  // The loop that runs if the values are not accurate enough
  while (difference(sin, prevSin) >= 0.000001 || difference(cos, prevCos) >= 0.000001){
    prevSin = sin;
    prevCos = cos;

    //Taylor series for Sin
    sin += (index % 2) * (index % 4 == 3 ? -1 : 1) * (anglePower) / factorialCounter;
    //Taylor series for Cos
    cos += (-1 * ((index % 2) - 1)) * (index % 4 == 2 ? -1 : 1) * (anglePower) / factorialCounter;
    
    tableRow(index + 1, sin, cos, sin/cos);

    index++;
    factorialCounter *= index;
    anglePower *= angle;
  }
  return EXIT_SUCCESS;
}
