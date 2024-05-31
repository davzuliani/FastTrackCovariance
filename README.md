### How to make things running

First of all, you need to load and build several libraries. The way to do it is to run the `LoadAll.c` script.
You can easily run it in a `root` bash:

```
root[0] .L LoadAll.c
root[1] LoadAll("CLD") 
```

You have to use "CLD", and thereore the geometry should always be called "GeoCLD.txt"

If you need to change the magnetic field, you have to modify the script `SolGeomCLD.cxx` (line 89), and rebuild everything using `LoadAll.c`.

Then, you can run the `CompRes.c` script to get the resolution for a given angle:

```
root[0] .L CompRes.c
root[1] CompRes(90) 
```

You will get a `.root` file with all the canvas saved (line 262 of script `CompRes.c`).

You can change the geometry without the need to build everything.

Let's have a look at the `GeoCLD.txt` file structure:

```
1 PIPE -100 100 0.0228 0.0012 0.35276 0 0 0 0 0 0
1 VTX -0.065 0.065 0.029 5e-05 0.0937 2 0 1.5708 5e-06 5e-06 1
1 VTX -0.065 0.065 0.031 5e-05 0.0937 2 0 1.5708 5e-06 5e-06 1
1 VTX -0.065 0.065 0.05 5e-05 0.0937 2 0 1.5708 5e-06 5e-06 1
1 VTX -0.065 0.065 0.052 5e-05 0.0937 2 0 1.5708 5e-06 5e-06 1
1 VTX -0.065 0.065 0.073 5e-05 0.0937 2 0 1.5708 5e-06 5e-06 1
1 VTX -0.065 0.065 0.075 5e-05 0.0937 2 0 1.5708 5e-06 5e-06 1
1 VTX -0.065 0.065 0.101 5e-05 0.0937 2 0 1.5708 5e-06 5e-06 1
1 VTX -0.065 0.065 0.103 5e-05 0.0937 2 0 1.5708 5e-06 5e-06 1
1 VTX -0.065 0.065 0.028 0.000557 0.0937 0 0 0 0 0 0
1 VTX -0.065 0.065 0.051 0.000557 0.0937 0 0 0 0 0 0
1 VTX -0.065 0.065 0.074 0.000557 0.0937 0 0 0 0 0 0
1 VTX -0.065 0.065 0.102 0.000557 0.0937 0 0 0 0 0 0
1 VTX -0.5 0.5 0.113 0.000337 0.0937 0 0 0 0 0 0
```