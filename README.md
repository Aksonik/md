# MD

It runs simple molecular dynamics simulations 
of particles interacting via Van der Waals forces. 
Equations of motion are numerically integrated with Leapfrog algorithm. 
It requires initial coordinates in VMD *xyz* format
and produces a trajectory in the same format. 
Box size, number of steps, step size, and frequency of saving frames can be set.
Initial velocities of the particles are generated randomly. 
One can assign different masses and Lennard-Jones parameters (sigma and epsilon) 
to different types of particles providing a force field file. 
It runs on a singe CPU. 

The repository contains example input and output files.

### Compilation

The installation requires *cmake*. 

```
./install.sh
```

### Running

```
./md_program input/sys.opt
```

where *sys.opt* is an option file.

### Options file

```
initial: input/sys.xyz 

force field: input/sys.ff

steps: 10000

time step: 0.002

trajectory: output/traj.xyz

box size: 30.000 30.000 30.000

save frequency: 10
```

where *sys.xyz* is an initial coordinates file and *sys.ff* in a force field file.

### Coordinates file

```
17

MD

A 20.000 20.000 20.000

B 10.000 20.000 20.000

P  5.000  5.000  5.000

R 25.000  5.000  5.000

K 15.000 15.000 15.000
```

where provided are number of particles (17), 
atom type (*A*, *B*, *P*, *R*, *K*), and coordinates (*x*, *y*, *z*). 
The second line (*MD*) is for comments.

### Force field file

```
A 10.0 10.100 0.240

B 12.0 10.200 0.250

P 21.0 8.100 0.110

R 22.0 8.200 0.120

K 35.0 12.000 0.200
```

where provided are particle types (*A*, *B*, *C*), mass, sigma and epsilon.
