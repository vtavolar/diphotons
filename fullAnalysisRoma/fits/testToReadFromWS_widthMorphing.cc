#include "RooRealVar.h"
#include "RooAbsPdf.h"
#include "RooBinning.h"
#include "RooDataSet.h"
#include "RooDataHist.h"
#include "RooWorkspace.h"
#include "RooPlot.h"
#include "RooGaussian.h"
#include "RooHistPdf.h"
#include "RooMomentMorph.h"
#include "RooNumConvPdf.h"   
#include "RooFFTConvPdf.h"
#include "RooFitResult.h"     
#include "TFile.h"
#include "TH1D.h"
#include "TTree.h"
#include "TLegend.h"
#include "TChain.h"
#include "TMath.h"
#include "TROOT.h"
#include "TVectorD.h"
#include <iostream>
#include "TCanvas.h"

using namespace RooFit;
using namespace std;

void runfits() {

  TFile *fileResNominal     = new TFile("daTenereVersioneFinale_smearings/IntrinsicWidthHistos001.root");
  TFile *filePointFromMorph = new TFile("daTenereVersioneFinale_smearings/WidthHistosGenOnlyScan001.root");

  RooRealVar* deltaMgen = new RooRealVar("deltaMgen", "",   -10000, 10000,   "GeV");

  RooDataHist *widthRDH_mass1000_catEBEB_nom   = (RooDataHist*)fileResNominal->Get("intWidthRDH_mass1000_catEBEB_kpl001");
  RooDataHist *widthRDH_mass1000_catEBEB_morph = (RooDataHist*)filePointFromMorph->Get("widthRDH_mass1000_catEBEB_kpl001");
  RooDataHist *widthRDH_mass998_catEBEB_morph  = (RooDataHist*)filePointFromMorph->Get("widthRDH_mass998_catEBEB_kpl001");
  RooDataHist *widthRDH_mass992_catEBEB_morph  = (RooDataHist*)filePointFromMorph->Get("widthRDH_mass992_catEBEB_kpl001");
  RooDataHist *widthRDH_mass1004_catEBEB_morph = (RooDataHist*)filePointFromMorph->Get("widthRDH_mass1004_catEBEB_kpl001");
  RooDataHist *widthRDH_mass1008_catEBEB_morph = (RooDataHist*)filePointFromMorph->Get("widthRDH_mass1008_catEBEB_kpl001");
  RooDataHist *widthRDH_mass1500_catEBEB_morph = (RooDataHist*)filePointFromMorph->Get("widthRDH_mass1500_catEBEB_kpl001");

  RooPlot *frameA = deltaMgen->frame(Range(-10,10),Bins(30));
  widthRDH_mass1000_catEBEB_nom->plotOn(frameA, LineColor(kBlack), LineStyle(kSolid), Rescale(1./widthRDH_mass1000_catEBEB_nom->sumEntries()));
  widthRDH_mass1000_catEBEB_morph->plotOn(frameA, LineColor(kRed), LineStyle(kDashed), Rescale(1./widthRDH_mass1000_catEBEB_morph->sumEntries()));
  widthRDH_mass998_catEBEB_morph->plotOn(frameA, LineColor(kBlue), LineStyle(kDashed), Rescale(1./widthRDH_mass998_catEBEB_morph->sumEntries()));
  widthRDH_mass992_catEBEB_morph->plotOn(frameA, LineColor(kYellow), LineStyle(kDashed), Rescale(1./widthRDH_mass992_catEBEB_morph->sumEntries()));
  widthRDH_mass1004_catEBEB_morph->plotOn(frameA, LineColor(kOrange), LineStyle(kDashed), Rescale(1./widthRDH_mass1004_catEBEB_morph->sumEntries()));
  widthRDH_mass1008_catEBEB_morph->plotOn(frameA, LineColor(kGreen), LineStyle(kDashed), Rescale(1./widthRDH_mass1008_catEBEB_morph->sumEntries()));
  widthRDH_mass1500_catEBEB_morph->plotOn(frameA, LineColor(kPink), LineStyle(kDashed), Rescale(1./widthRDH_mass1500_catEBEB_morph->sumEntries()));
  frameA->Draw();
  //double max = frameA->GetMaximum();
  frameA->GetYaxis()->SetRangeUser(0.00001, 1.);
  frameA->GetXaxis()->SetTitle("m_{#gamma#gamma}-m_{G}");
  frameA->SetTitle("Width");

  TCanvas *c1 = new TCanvas("c1","c1",1);
  c1->SetLogy();
  frameA->Draw();
  c1->SaveAs("test.png");








  return;
}


//  LocalWords:  GeV
