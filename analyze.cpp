/*
 * Alex Wassel
 * aw7re
 * analyze.cpp
 * Final Project
*/

#include <stdio.h>
#include <stdlib.h>

int main ( int argc, char *argv[] ) {

  double totalE = 0, depositedE = 0, fraction = 0;
  double x, xmin, xmax, de, energy,tsize, tcenter;
  FILE *input;
  
  if (argc != 4) {
    printf("Please run this program like this: ./analyze input tcenter tsize\n");
    exit(1);
  }
  input = fopen(argv[1], "r");
  tcenter = atof(argv[2]);
  tsize = atof(argv[3]);
 
  //find depth at which the tumor begins, and the depth at which it ends.
  xmin = tcenter - tsize/2.0;
  xmax = tcenter + tsize/2.0;

  //read data from input file (each line contains 3 values" x, de, energy)
  while ( fscanf(input, "%lf %lf %lf", &x, &de, &energy) != EOF) {

    //each time reading a de value, add it to the total energy
    totalE+=de;

    if ( x < xmax && x > xmin) {
      depositedE+=de;
    }
  }
  fclose(input);
  fraction = (depositedE/totalE)*100;

  printf("Total energy deposited: %lf MeV\n", totalE);
  printf("Energy deposited in tumor: %lf MeV\n", depositedE);
  printf("Fraction deposited in tumor: %lf%%\n", fraction);

  
}
