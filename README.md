# Proton-Power


## Introduction: Particle Beam Therapy

We all know that radiation can cause cancer, but radiation can also be used to fight cancer. One example of this is particle beam cancer therapy, in which a beam of charged particles (usually protons or pions) is shot into a tumor with the goal of destroying it.
As particles from such a beam travel through the body, they gradually lose energy and eventually come to rest. As it turns out, much of the particle’s energy is lost close to the point at which it stops. This makes such beams well-suited for killing tumors without doing too much damage to the other tissues they pass through on the way to the tumor, or tissues beyond the tumor.
Particles with higher energies will travel farther into the body. By adjusting the energy of the particles, we can cause them to stop at a chosen depth (ideally, inside a tumor).
At moderate energies, a beam of particles traveling through a body loses energy mostly through interactions with electrons. Although it’s possible that some of the particles will bump into an atomic nucleus, that doesn’t happen very often. Since protons are 2,000 times heavier than electrons, beams of these particles tend to travel in a straight line, knocking puny electrons aside as they go.
The energy deposited damages the body’s tissues. The goal is to destroy the tumor without doing too much damage to healthy tissue.


## The Assignment
Imagine you’re a doctor working at a radiation therapy facility. You have at your command a beam of protons. You can aim the beam precisely, and control its energy.
You’re preparing for a visit by a patient with a 2-centimeter-thick tumor buried 8 centimeters deep in her body (see Figure 4). You need to determine what energy the protons should have in order to deposit most of their energy in the region of the tumor.
A physicist colleague has given you a formula to calculate the energy lost by a particle while going through a thin slice of material. The formula has a form like this:
∆E = ∆x · f(E, proton properties, material properties)
where ∆E is the amount of energy the particle loses, ∆x is the thickness of the slice, and f is some function that depends on E (the energy at the beginning of the slice) as well as the constant properties of the particle (like charge and mass) and properties of the material (like density).
Unfortunately, your physicist friend tells you that eight centimeters is too big to call a “thin slice”. But that’s OK, she says. Just treat the eight centimeters as though it was a stack of thinner slices, as shown in Figure 5. Each time the proton passes through one of the slices, it loses some amount of energy, ∆E. This lost energy damages the tissue in that slice. The proton then enters the next slice with its energy reduced by the amount ∆E.


Pograms

Your assignment is to write three programs: simulate.cpp, visualize.cpp, and analyze.cpp. The first will simulate the passage of protons through the patient’s body, the second will help visualize these results,
and the third will help choose the right proton energy.

Program 1:
Directions: 
keeps track of the energy that protons lose as they travel through such a stack of thin slices. Each slice will have a thickness of 0.01 cm. Assume each proton travels in a straight line, starting at x = 0 and progresses along the x axis until it runs out of energy. Each time a proton passes through a slice, the program should write the proton’s position, energy loss, and remaining energy into an output file.

Once you’ve written and compiled your program, run it like this to produce an output file to use with your next programs:
./simulate 1000 100 100-mev.dat
This should produce an output file named 100-mev.dat containing information about the energy deposited by each proton, in each slice of the patient’s body.


Program 2: Visualizing the Results
Your next program will be named visualize.cpp and it will help us see how much total energy our beam of protons has deposited at various points along its path. To do this, you’ll make what’s called a
“weighted histogram”.
Like the preceding program, this one will expect parameters on its command line, and should complain and exit if it doesn’t get the proper number of parameters8. Its usage will be:
./visualize xmin xmax input output
where xmin and xmax are the minimum and maximum depth we’re interested in, in centimeters, input is the name of a file produced by your simulate program, and output is the name of a file into which your program will write the histogram data.
The output file should contain two columns of numbers, separated by a single space. 


Program 3: Analyzing the Data
Your last program will be called analyze.cpp. It will read data pro- duced by your first program and determine how much total energy was deposited in the patient’s body, and how much energy was deposited in the tumor.
Like the preceding programs, this one should accept all of its param- eters on the command line, and give users a helpful message if they don’t give it the right number of arguments. The usage should be:
./analyze input tcenter tsize
Where “input” is the name of a data file produced by your simulate program, “tcenter” is the depth of the center of the tumor, in cm, and “tsize” is the size of the tumor, in cm.



Results
Using the tools you’ve written you could find the proton energy that best suits your patient’s needs. For example, you could simulate protons of several energies using your simulate program:
./simulate 1000  50  50-mev.dat
./simulate 1000  75  75-mev.dat
./simulate 1000 100 100-mev.dat
./simulate 1000 125 125-mev.dat
then take a look at the energy distribution created by each energy:
./visualize 0 10  50-mev.dat hist50.dat
./visualize 0 10  75-mev.dat hist75.dat
./visualize 0 10 100-mev.dat hist100.dat
./visualize 0 10 125-mev.dat hist125.dat
You’d see distributions like those shown in Figure 3 in the introduction. Each distribution has a distinct peak, called the “Bragg peak”, near the end of the proton’s path. If you saw that one of these peaks lies in the region of the tumor, you might use your analyze program to see what fraction of the energy would go into the tumor, like this:
./analyze 100-mev.dat 8 2
Congratulations, Doctor! You’ve helped a patient along the road to recovery.
