/*
 * Alex Wassel
 * aw7re
 * visualize.cpp
 * Final Project
*/

#include <stdio.h>
#include <stdlib.h>

int main ( int argc, char *argv[] ) {

  int i;
  int binno, overunderflow = 0;
  double binwidth, x, de, energy, depth;
  double xmin = 0, xmax = 0;
  
  
  const int nbins = 100;
  double hist[nbins];
  
  FILE *input;
  FILE *output;

  //check for arguments
  if (argc != 5) {
    printf("Please run this program like this: ./visualize xmin xmax input output\n");
    exit(1);
  }
  xmin = atof(argv[1]);
  xmax = atof(argv[2]);
  input = fopen(argv[3], "r");
  output = fopen(argv[4], "w");
  
  //Set the bins to zero
  for (i = 0; i < nbins; i++) {
    hist[i] = 0;
  }

  
  //determine the binwidth
  binwidth = (xmax-xmin)/nbins;

  
  //read data from the input file (each line contains 3 values: x, de, energy)
  //input = fopen("100-mev.dat", "r");
  while ( fscanf(input, "%lf %lf %lf", &x, &de, &energy) != EOF) {

    //which bin this x value belongs in
    binno = x/binwidth;

    //keep count of the number of over/underflows
    if ( binno < 0 || binno >= 100) {
      overunderflow++;
      continue; //skip this line and jump to the next
    }

    //if not an over/underflow, add the value of de to this bin
    hist[binno] += de;
  }
  fclose(input);


  //write the historgram data into the output file
  

  //output = fopen("hist-100.dat", "w");
  for ( i = 0; i < nbins; i++) {

    depth = xmin + binwidth*(0.5+i);
    //print into the file with fprintf
    fprintf(output, "%lf %lf\n", depth, hist[i]);
    
  }
  fprintf (output, "# Saw %d over/underflows\n", overunderflow);
  fclose(output);
  
 
}


