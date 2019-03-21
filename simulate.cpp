/*
 * Alex Wassel
 * aw7re
 * simulate.cpp
 * Final Project
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "dedx.h"

int main (int argc, char *argv[]) {

  double pmass = 938.27;    // MeV, Proton mass.
  double pcharge = 1.0;     // Proton charge.
  double rho = 1.0;	    // Density, g/cm^2, for water.
  double amass = 18.01;	    // Atomic mass, AMU, for water.
  double anum = 10.0;       // Atomic number, Z, for water.
  double activation = 75.0; // Activation energy, eV, for water.
  
  double dx = 0.01;         // Slice thickness, cm.

  int i;
  int nprotons;
  double estart, energy;
  double x, de;
  FILE *output;
  

  //Program should accept 3 arguments on command-line
  if (argc != 4) {
    printf("Please run this program like this: ./simulate nprotons estart output\n");
    exit(1);
  }

  output = fopen( argv[3], "w" );
  nprotons = atoi(argv[1]);
  estart = atof(argv[2]);
  
  //Pair of nested loops
  for (i = 0; i < nprotons; i++) { //atoi(argv[1]) = nprotons

    /* Sets the proton's initial energy to estart+-1% and the starting position to zero cm +- 1mm */
    energy = estart + 0.01*estart*normal(); //sets the proton's initial energy (given)
    x = 0 + 0.1*normal(); //set the proton's initial position (given)
      
    do {
      
      /* Each time a proton goes through a slice of tissue */
      de = dx * dEdx(energy, pmass, pcharge, rho, amass, anum, activation); //calculate the amount of energy "de" the proton depositss in the slice
      energy = energy - de; //calculate the proton's new energy
      x = x + dx; //update the proton's position

      //write those values into the output file
      fprintf(output, "%lf %lf %lf \n", x, de, energy);
      
    } while ( energy > 0 && de > 0);
  }
      

}
