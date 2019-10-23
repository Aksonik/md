# MD

It runs simple molecular dynamics simulations 
of particles interacting via Van der Waals forces. 
Equations of motion are numerically integrated with Leapfrog algorithm. 
It requires initial coordinates in VMD *xyz* format
and produces a trajectory in the same format. 
Size of the box needs to be set in the comment line, i.e. second. 
Frames are saved every time step. 
Initial velocities of the particles are generated randomly. 
One can assign different masses and Lennard-Jones parameters (sigma and epsilon) 
to different types of particles providing a force field file. 
Desired time step and number of steps can be set in the options file. 
It runs on a singe CPU. 

### Compilation

The installation requires *cmake*. 

```
./install.sh
```

### Running

```
./md_program test/sys.opt
```

where *sys.opt* is an option file.

### Options file

```
initial: test/sys.xyz 

force field: test/sys.ff

steps: 1005

time step: 0.002
```

where *sys.xyz* is an initial coordinates file and *sys.ff* in a force field file.

### Coordinates file

```
3

30.0 30.0 30.0

A 20.000 20.000 20.000

B 10.000 10.000 10.000

C  5.000  5.000  5.000
```

where provided are number of particles (3), box size (*x*, *y*, *z*), 
atom type (*A*, *B*, *C*), and coordinates (*x*, *y*, *z*).

### Force field file

```
A 10.0 2.100 1.500

B 12.0 2.200 1.600

C 101.0 5.100 3.800
```

where provided are particle types (*A*, *B*, *C*), mass, sigma and epsilon.
