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

The structure is the following:

```
ftyLay = new Int_t[fNlMax];		// Layer type 1 = R (barrel) or 2 = z (forward/backward)
fLyLabl = new TString[fNlMax];	// Layer label
fxMin = new Double_t[fNlMax];	// Minimum dimension z for barrel  or R for forward
fxMax = new Double_t[fNlMax];	// Maximum dimension z for barrel  or R for forward
frPos = new Double_t[fNlMax];	// R/z location of layer
fthLay = new Double_t[fNlMax];	// Thickness (meters)
frlLay = new Double_t[fNlMax];	// Radiation length (meters)
fnmLay = new Int_t[fNlMax];		// Number of measurements in layers (1D or 2D)
fstLayU = new Double_t[fNlMax];	// Stereo angle (rad) - 0(pi/2) = axial(z) layer - Upper side
fstLayL = new Double_t[fNlMax];	// Stereo angle (rad) - 0(pi/2) = axial(z) layer - Lower side
fsgLayU = new Double_t[fNlMax];	// Resolution Upper side (meters) - 0 = no measurement
fsgLayL = new Double_t[fNlMax];	// Resolution Lower side (meters) - 0 = no measurement
fflLay = new Bool_t[fNlMax];	// measurement flag = T, scattering only = F
fEnable = new Bool_t[fNdet];	// list of enabled detectors
fDtype = new TString[fNdty];	// Array with layer labels 
fDfstLay = new Int_t[fNdty];	// Array with start layer
```