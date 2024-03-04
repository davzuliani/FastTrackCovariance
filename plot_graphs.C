#include <TMath.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <TH1.h>
#include <TAxis.h>
#include <TLegend.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TString.h>
#include <THStack.h>
#include <TFile.h>
#include <iostream>
#include "SolGeom.h"
#include "SolTrack.h"
#include "SolGridCov.h"
#include <iostream>
#include <sstream>


using namespace std;

void plot_graphs() {

    // Open the file
    TFile *f = new TFile("final.root");
    // get tgraphs
    TGraph *gpt_90 = (TGraph*)f->Get("gpt-90");
    TGraph *gpt_75 = (TGraph*)f->Get("gpt-75");
    TGraph *gpt_60 = (TGraph*)f->Get("gpt-60");
    TGraph *gpt_40 = (TGraph*)f->Get("gpt-40");
    TGraph *gpt_30 = (TGraph*)f->Get("gpt-30");
    TGraph *gpt_20 = (TGraph*)f->Get("gpt-20");
    TGraph *gpt_10 = (TGraph*)f->Get("gpt-10");

    // chose x = 100
    const double x_chosen = 10;
    const double norm = x_chosen;

    // create tgraph errors
    double x[7] = {90, 75, 60, 40, 30, 20, 10};
    double y[7] = {0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000};
    double ex[7] = {0, 0, 0, 0, 0, 0, 0};
    double ey[7] = {0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000};

    // get y of gpt_90 for x = 100
    double y_90 = gpt_90->Eval(x_chosen);
    double y_75 = gpt_75->Eval(x_chosen);
    double y_60 = gpt_60->Eval(x_chosen);
    double y_40 = gpt_40->Eval(x_chosen);
    double y_30 = gpt_30->Eval(x_chosen);
    double y_20 = gpt_20->Eval(x_chosen);
    double y_10 = gpt_10->Eval(x_chosen);

    // set y values
    y[0] = y_90/norm; y[1] = y_75/norm; y[2] = y_60/norm; y[3] = y_40/norm; y[4] = y_30/norm; y[5] = y_20/norm; y[6] = y_10/norm;

    // create tgraph errors
    TGraphErrors *gpt = new TGraphErrors(7, x, y, ex, ey);
    // set marker style
    gpt->SetMarkerStyle(20);
    gpt->SetMarkerSize(1.5);
    gpt->SetMarkerColor(kRed);

    // create canvas
    TCanvas *c1 = new TCanvas("c1", "c1", 600, 600);
    c1->SetGrid();
    c1->SetLogy();
    // gpt->GetYaxis()
    gpt->GetYaxis()->SetRangeUser(1e-5, 1e1);

    // draw tgraph
    gpt->Draw("AP");


}