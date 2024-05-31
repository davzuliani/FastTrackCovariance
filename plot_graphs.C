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

void plot_graphs1() {

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
    const double x_chosen_1 = 1;
    const double x_chosen_10 = 10;
    const double x_chosen_100 = 100;

    const double norm_1 = x_chosen_1;
    const double norm_10 = x_chosen_10;
    const double norm_100 = x_chosen_100;
    // const double norm_1 = 1;
    // const double norm_10 = 1;
    // const double norm_100 = 1;


    // create tgraph real
    double x_true[16] = {12.5, 17.5, 22.5, 27.5, 32.5, 37.5, 42.5, 47.5, 52.5, 57.5, 62.5, 67.5, 72.5, 77.5, 82.5, 87.5};
    double y_true[16] = {0.24054751634362834, 0.08904302467077307, 0.08634629186821531, 0.06524108391704692, 0.08103940607723836, 0.07201203574356722, 0.04414457920184579, 0.03995960739319842, 0.02254471217537339, 0.015226790614063337, 0.010310478385813397, 0.008417925297708812, 0.006766628134313857, 0.006348642276051789, 0.005502508832391989, 0.005329504858762842};
    double y_10_true[16] = {0.004909131306247598, 0.003108290967116784, 0.0024929328904346837, 0.0014774297430492837, 0.005356960322204885, 0.006885111378876142, 0.0009424636147352734, 0.0007542419637239131, 0.0004944978414289902, 0.0003974309416062324, 0.00033640756153994886, 0.00033688891415255317, 0.00032703593032355245, 0.0002741342180759362, 0.0002866771129199909, 0.00026402397685104775};
    double y_100_true[16] = {0.0006260518813620403, 0.0002983077506900111, 0.00023527314729865725, 0.00012440705472192005, 0.00009917407244904683, 0.0006352309877481711, 0.00009343140596668142, 0.00008478586431267702, 0.00005458213105081798, 0.000038743571508623444, 0.00003845115991791869, 0.00004991648223413743, 0.000047352641900734284, 0.000046604671073025765, 0.00004261479782932749, 0.00004205425332910798};
    double ex_true[16] = {2.5,2.5,2.5,2.5,2.5,2.5,2.5,2.5,2.5,2.5,2.5,2.5,2.5,2.5,2.5,2.5};
    double ey_true[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    // create tgraph errors
    double x[7] = {90, 75, 60, 40, 30, 20, 10};
    double y_1[7] = {0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000};
    double y_10[7] = {0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000};
    double y_100[7] = {0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000};
    double ex[7] = {0, 0, 0, 0, 0, 0, 0};
    double ey[7] = {0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000};

    // get y of gpt_90 for x = 100
    double y_1_90 = gpt_90->Eval(x_chosen_1); double y_1_75 = gpt_75->Eval(x_chosen_1); double y_1_60 = gpt_60->Eval(x_chosen_1); double y_1_40 = gpt_40->Eval(x_chosen_1); double y_1_30 = gpt_30->Eval(x_chosen_1); double y_1_20 = gpt_20->Eval(x_chosen_1); double y_1_10 = gpt_10->Eval(x_chosen_1);
    double y_10_90 = gpt_90->Eval(x_chosen_10); double y_10_75 = gpt_75->Eval(x_chosen_10); double y_10_60 = gpt_60->Eval(x_chosen_10); double y_10_40 = gpt_40->Eval(x_chosen_10); double y_10_30 = gpt_30->Eval(x_chosen_10); double y_10_20 = gpt_20->Eval(x_chosen_10); double y_10_10 = gpt_10->Eval(x_chosen_10);
    double y_100_90 = gpt_90->Eval(x_chosen_100); double y_100_75 = gpt_75->Eval(x_chosen_100); double y_100_60 = gpt_60->Eval(x_chosen_100); double y_100_40 = gpt_40->Eval(x_chosen_100); double y_100_30 = gpt_30->Eval(x_chosen_100); double y_100_20 = gpt_20->Eval(x_chosen_100); double y_100_10 = gpt_10->Eval(x_chosen_100);

    // set y values
    y_1[0] = y_1_90/norm_1; y_1[1] = y_1_75/norm_1; y_1[2] = y_1_60/norm_1; y_1[3] = y_1_40/norm_1; y_1[4] = y_1_30/norm_1; y_1[5] = y_1_20/norm_1; y_1[6] = y_1_10/norm_1;
    y_10[0] = y_10_90/norm_10; y_10[1] = y_10_75/norm_10; y_10[2] = y_10_60/norm_10; y_10[3] = y_10_40/norm_10; y_10[4] = y_10_30/norm_10; y_10[5] = y_10_20/norm_10; y_10[6] = y_10_10/norm_10;
    y_100[0] = y_100_90/norm_100; y_100[1] = y_100_75/norm_100; y_100[2] = y_100_60/norm_100; y_100[3] = y_100_40/norm_100; y_100[4] = y_100_30/norm_100; y_100[5] = y_100_20/norm_100; y_100[6] = y_100_10/norm_100;

    // create tgraph errors
    TGraphErrors *pt_1 = new TGraphErrors(7, x, y_1, ex, ey);
    TGraphErrors *pt_10 = new TGraphErrors(7, x, y_10, ex, ey);
    TGraphErrors *pt_100 = new TGraphErrors(7, x, y_100, ex, ey);
    // set marker style
    pt_1->SetMarkerStyle(20);
    pt_1->SetMarkerSize(1.5);
    pt_1->SetMarkerColor(kRed);
    pt_10->SetMarkerStyle(20);
    pt_10->SetMarkerSize(1.5);
    pt_10->SetMarkerColor(kBlue);
    pt_100->SetMarkerStyle(20);
    pt_100->SetMarkerSize(1.5);
    pt_100->SetMarkerColor(kBlack);

    TGraphErrors *pt_true_1 = new TGraphErrors(16, x_true, y_true, ex_true, ey_true);
    pt_true_1->SetMarkerStyle(21);
    pt_true_1->SetMarkerSize(1);
    pt_true_1->SetMarkerColor(kRed);
    TGraphErrors *pt_true_10 = new TGraphErrors(16, x_true, y_10_true, ex_true, ey_true);
    pt_true_10->SetMarkerStyle(21);
    pt_true_10->SetMarkerSize(1);
    pt_true_10->SetMarkerColor(kBlue);
    TGraphErrors *pt_true_100 = new TGraphErrors(16, x_true, y_100_true, ex_true, ey_true);
    pt_true_100->SetMarkerStyle(21);
    pt_true_100->SetMarkerSize(1);

    // create canvas
    TCanvas *c1 = new TCanvas("c1", "c1", 600, 600);
    c1->SetGrid();
    c1->SetLogy();
    // gpt->GetYaxis()
    pt_1->GetYaxis()->SetRangeUser(1e-5, 1e0);
    pt_1->GetXaxis()->SetTitle("#theta [deg]");

    // draw tgraph
    pt_1->Draw("AP");
    pt_10->Draw("P SAME");
    pt_100->Draw("P SAME");
    pt_true_1->Draw("P SAME");
    pt_true_10->Draw("P SAME");
    pt_true_100->Draw("P SAME");

    // create legend
    TLegend *leg = new TLegend(0.6, 0.6, 0.9, 0.9);
    leg->AddEntry(pt_1, "1 GeV", "p");
    leg->AddEntry(pt_10, "10 GeV", "p");
    leg->AddEntry(pt_100, "100 GeV", "p");
    leg->AddEntry(pt_true_1, "1 GeV (full sim)", "p");
    leg->AddEntry(pt_true_10, "10 GeV (full sim)", "p");
    leg->AddEntry(pt_true_100, "100 GeV (full sim)", "p");
    leg->Draw();


}

void plot_graphs2() {

    // Open the file
    TFile *f_standard = new TFile("prova_standard.root");
    TFile *f_biggertracker = new TFile("prova_biggertracker.root");
    TFile *f_morelayer = new TFile("prova_morelayer.root");
    TFile *f_standard_5T = new TFile("prova_standard_5T.root");
    TFile *f_standardlayer_4p5T = new TFile("prova_standardlayer_4p5T.root");
    TFile *f_standardlayer_4T = new TFile("prova_standardlayer_4T.root");
    TFile *f_biggertracker_5T = new TFile("prova_biggertracker_5T.root");
    // get tgraphs
    TGraph *gpt_90_standard = (TGraph*)f_standard->Get("gpt-90");
    TGraph *gpt_90_biggertracker = (TGraph*)f_biggertracker->Get("gpt-90");
    TGraph *gpt_90_morelayer = (TGraph*)f_morelayer->Get("gpt-90");
    TGraph *gpt_90_standard_5T = (TGraph*)f_standard_5T->Get("gpt-90");
    TGraph *gpt_90_standardlayer_4p5T = (TGraph*)f_standardlayer_4p5T->Get("gpt-90");
    TGraph *gpt_90_standardlayer_4T = (TGraph*)f_standardlayer_4T->Get("gpt-90");
    TGraph *gpt_90_biggertracker_5T = (TGraph*)f_biggertracker_5T->Get("gpt-90");

    // draw tgraphs
    TCanvas *c2 = new TCanvas("c2", "c2", 600, 600);
    c2->SetGrid();
    gpt_90_standard->SetLineColor(kRed);
    gpt_90_standard->SetLineWidth(2);
    gpt_90_biggertracker->SetLineColor(kBlue);
    gpt_90_biggertracker->SetLineWidth(2);
    gpt_90_morelayer->SetLineColor(kBlack);
    gpt_90_morelayer->SetLineWidth(2);
    gpt_90_standard_5T->SetLineColor(kGreen);
    gpt_90_standard_5T->SetLineWidth(2);
    gpt_90_standardlayer_4p5T->SetLineColor(kOrange);
    gpt_90_standardlayer_4p5T->SetLineWidth(2);
    gpt_90_standardlayer_4T->SetLineColor(kYellow);
    gpt_90_standardlayer_4T->SetLineWidth(2);
    gpt_90_biggertracker_5T->SetLineColor(kMagenta);
    gpt_90_biggertracker_5T->SetLineWidth(2);
    gpt_90_standard->Draw("AL");
    gpt_90_biggertracker->Draw("SAME");
    gpt_90_morelayer->Draw("SAME");
    gpt_90_standard_5T->Draw("SAME");
    gpt_90_standardlayer_4p5T->Draw("SAME");
    gpt_90_standardlayer_4T->Draw("SAME");
    gpt_90_biggertracker_5T->Draw("SAME");

    // draw legend
    TLegend *leg = new TLegend(0.1, 0.6, 0.4, 0.9);
    leg->AddEntry(gpt_90_standard, "Standard", "l");
    leg->AddEntry(gpt_90_biggertracker, "Bigger OT", "l");
    leg->AddEntry(gpt_90_morelayer, "Added layer", "l");
    leg->AddEntry(gpt_90_standard_5T, "Standard 5T", "l");
    leg->AddEntry(gpt_90_standardlayer_4p5T, "Standard 4.5T", "l");
    leg->AddEntry(gpt_90_standardlayer_4T, "Standard 4T", "l");
    leg->AddEntry(gpt_90_biggertracker_5T, "Bigger OT 5T", "l");
    leg->Draw();


}

void plot_graphs3() {

    // Open the file
    TFile *f_standard_5T = new TFile("prova_standardlayer_5T.root");
    TFile *f_closerlayer_5T = new TFile("prova_closerlayer_5T.root");
    // get tgraphs
    TGraph *gpt_90_standard_5T = (TGraph*)f_standard_5T->Get("gd0-90");
    TGraph *gpt_90_closerlayer_5T = (TGraph*)f_closerlayer_5T->Get("gd0-90");

    // draw tgraphs
    TCanvas *c2 = new TCanvas("c2", "c2", 600, 600);
    c2->SetGrid();
    gpt_90_standard_5T->SetLineColor(kGreen);
    gpt_90_standard_5T->SetLineWidth(2);
    gpt_90_closerlayer_5T->SetLineColor(kMagenta);
    gpt_90_closerlayer_5T->SetLineWidth(2);
    gpt_90_standard_5T->Draw("AL");
    gpt_90_closerlayer_5T->Draw("SAME");

    // draw legend
    TLegend *leg = new TLegend(0.1, 0.6, 0.4, 0.9);
    leg->AddEntry(gpt_90_standard_5T, "standard 5T", "l");
    leg->AddEntry(gpt_90_closerlayer_5T, "closer layer 5T", "l");
    leg->Draw();


}