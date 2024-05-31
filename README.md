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

You can change the geometry without the need to build everything.