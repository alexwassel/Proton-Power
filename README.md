# Proton-Power


## Introduction: Particle Beam Therapy

We all know that radiation can cause cancer, but radiation can also be used to fight cancer. One example of this is particle beam cancer therapy, in which a beam of charged particles (usually protons or pions) is shot into a tumor with the goal of destroying it.
As particles from such a beam travel through the body, they gradually lose energy and eventually come to rest. As it turns out, much of the particle’s energy is lost close to the point at which it stops. This makes such beams well-suited for killing tumors without doing too much damage to the other tissues they pass through on the way to the tumor, or tissues beyond the tumor.
Particles with higher energies will travel farther into the body. By adjusting the energy of the particles, we can cause them to stop at a chosen depth (ideally, inside a tumor).
At moderate energies, a beam of particles traveling through a body loses energy mostly through interactions with electrons. Although it’s possible that some of the particles will bump into an atomic nucleus, that doesn’t happen very often. Since protons are 2,000 times heavier than electrons, beams of these particles tend to travel in a straight line, knocking puny electrons aside as they go.
The energy deposited damages the body’s tissues. The goal is to destroy the tumor without doing too much damage to healthy tissue.

## The Project
Imagine you’re a doctor working at a radiation therapy facility. You have at your command a beam of protons. You can aim the beam precisely, and control its energy.
You’re preparing for a visit by a patient with a 2-centimeter-thick tumor buried 8 centimeters deep in her body. You need to determine what energy the protons should have in order to deposit most of their energy in the region of the tumor.

A physicist colleague has given you a formula to calculate the energy lost by a particle while going through a thin slice of material. The formula has a form like this:
∆E = ∆x · f(E, proton properties, material properties), where ∆E is the amount of energy the particle loses, ∆x is the thickness of the slice, and f is some function that depends on E (the energy at the beginning of the slice) as well as the constant properties of the particle (like charge and mass) and properties of the material (like density).

Unfortunately, your physicist friend tells you that eight centimeters is too big to call a “thin slice”. But that’s OK, she says. Just treat the eight centimeters as though it was a stack of thinner slices. Each time the proton passes through one of the slices, it loses some amount of energy, ∆E. This lost energy damages the tissue in that slice. The proton then enters the next slice with its energy reduced by the amount ∆E.


## Programs

There are 3 programs made for this project: simulate.cpp, visualize.cpp, and analyze.cpp.
The first simulates the passage of protons through the patient’s body.
The second helps visualize these results.
The third will help choose the right proton energy.

#### Program 1 (simulate.cpp):
Keeps track of the energy that protons lose as they travel through such a stack of thin slices. Each slice has a thickness of 0.01 cm. Assuming each proton travels in a straight line, starting at x = 0 and progressing along the x-axis until it runs out of energy.
Each time a proton passes through a slice, this program writes the proton’s position, energy loss, and remaining energy into an output file.

Example to run it:
./simulate 1000 100 100-mev.dat
Produces an output file named 100-mev.dat containing information about the energy deposited by each proton, in each slice of the patient’s body.


#### Program 2 (visualize.cpp):
Helps to see how much total energy the beam of protons has deposited at various points along its path, by making a “weighted histogram”.
Like the preceding program, this one also expects parameters on the command line, and complains and exit if it doesn’t get the proper number of parameters --> ./visualize xmin xmax input output, where xmin and xmax are the minimum and maximum depth needed in this case in centimeters, input is the name of the file produced by the simulate program, and output is the name of the file into which the program writes the histogram data.
The output file contains two columns of numbers, separated by a single space. 


#### Program 3 (analyze.cpp):
Reads data produced by the first program and determines how much total energy is deposited in the patient’s body, and how much energy is deposited in the tumor.
Like the preceding programs, this one accepts all of its parameters on the command line, and gives users a helpful message if they don’t give it the right number of arguments --> ./analyze input tcenter tsize, where “input” is the name of the data file produced by the simulate program, “tcenter” is the depth of the center of the tumor in cm, and “tsize” is the size of the tumor in cm.



## Results
Example run using these programs to find the proton energy that best suits the patient’s needs.

Simulating protons of several energies using the simulate program:
./simulate 1000  50  50-mev.dat
./simulate 1000  75  75-mev.dat
./simulate 1000 100 100-mev.dat
./simulate 1000 125 125-mev.dat

Then taking a look at the energy distribution created by each energy:
./visualize 0 10  50-mev.dat hist50.dat
./visualize 0 10  75-mev.dat hist75.dat
./visualize 0 10 100-mev.dat hist100.dat
./visualize 0 10 125-mev.dat hist125.dat

Using the analyze program to see what fraction of the energy would go into the tumor:
./analyze 100-mev.dat 8 2

Just helped a patient along the road to recovery!
