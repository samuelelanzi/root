#include "TCanvas.h"
#include "TF1.h"
#include "TFile.h"
#include "TFitResult.h"
#include "TH1F.h"
#include "TLegend.h"
#include "TMath.h"
#include "TMatrixD.h"
#include "TROOT.h"
#include "TStyle.h"
#include <iostream>

void setStyle() {
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(57);
  gStyle->SetOptTitle(0);
}

// Gaussiana 1-D definita nella funzione utente
Double_t myFunction(Double_t *x, Double_t *par) {
  Double_t xx = x[0];
  Double_t val = par[0] * TMath::Exp(-(xx - par[1]) * (xx - par[1]) / 2. /
                                     par[2] / par[2]);
  return val;
}

void myMacro(Int_t nGen = 1000) {

  gStyle->SetOptStat(2210);
  gStyle->SetOptFit(1111);

  TFile *file = new TFile("example.root", "RECREATE");

  char *histName = new // Gaussiana 1-D definita nella funzione utente
      char[10];
  TH1F *h[2]; // Gaussiana 1-D definita nella funzione utente

  for (Int_t i = 0; i < 2; i++) {
    sprintf(histName, "h%d", i);
    h[i] = new TH1F(histName, "test histogram", 100, -5, 5.);

    h[i]->SetMarkerStyle(20);
    h[i]->SetMarkerSize(0.5);
    h[i]->SetLineColor(1);
    h[i]->GetYaxis()->SetTitleOffset(1.2);
    h[i]->GetXaxis()->SetTitleSize(0.04);
    h[i]->GetYaxis()->SetTitleSize(0.04);
    h[i]->GetXaxis()->SetTitle("x");
    h[i]->GetYaxis()->SetTitle("Entries");
  }

  h[0]->SetFillColor(4);
  h[1]->SetFillColor(2);

  // filling the histo with FillRandom

  h[0]->FillRandom("gaus", nGen); // gaus predefined function (G(0,1))

  TF1 *f = new TF1("f", myFunction, -10, 10, 3); // user defined function
  f->SetParameter(0, 1);
  f->SetParameter(1, 0);
  f->SetParameter(2, 1);
  h[1]->FillRandom("f", nGen);

  // drawing

  TCanvas *c1 = new TCanvas("c1", "TF1 examples", 200, 10, 600, 400);
  c1->Divide(1, 2);
  for (Int_t i = 0; i < 2; i++) {
    c1->cd(i + 1);
    h[i]->DrawCopy("H");
    h[i]->DrawCopy("E,P,SAME");
    c1->Print("testHisto.gif");
    c1->Print("testHisto.C");
    c1->Print("testHisto.root");
  }

  TCanvas *c2 = new TCanvas("c2", "TF1 examples", 200, 10, 600, 400);
  h[0]->Fit("gaus");
  h[0]->DrawCopy("H");
  h[0]->DrawCopy("E,P,SAME");

  TCanvas *c3 = new TCanvas("c3", "TF1 examples", 200, 10, 600, 400);
  f->SetParameter(0, 4000);
  f->SetParameter(1, 0);
  f->SetParameter(2, 1);
  f->SetLineColor(kCyan);
  TFitResultPtr fRes = h[1]->Fit(f, "S", "");
  h[1]->DrawCopy("H");
  h[1]->DrawCopy("E,P,SAME");
  TLegend *leg = new TLegend(.1, .7, .3, .9, "test Fit ");
  leg->SetFillColor(0);
  leg->AddEntry(h[1], "Punti sperimentali");
  leg->AddEntry(f, "Fit Gaussiano");
  leg->Draw("S");
  c3->Print("testFit.gif");
  c3->Print("testFit.C");
  c3->Print("testFit.root");

  /*----Writing out results ---*/

  Double_t mean = f->GetParameter(1);
  Double_t meanErr = f->GetParError(1);
  Double_t sigma = f->GetParameter(2);
  Double_t sigmaErr = f->GetParError(2);
  Double_t chiSquare = f->GetChisquare();
  Double_t nDOF = f->GetNDF();
  Double_t Prob = f->GetProb();
  std::cout << "Mean = " << mean << " +/- " << meanErr << '\n';
  std::cout << "Sigma = " << sigma << " +/- " << sigmaErr << '\n';
  std::cout << "ChiSquare = " << chiSquare << " , nDOF " << nDOF << '\n';
  std::cout << "ChiSquare Probability= " << Prob << '\n';

  // Covariance and Correlation

  TMatrixD cov = fRes->GetCovarianceMatrix();
  TMatrixD cor = fRes->GetCorrelationMatrix();
  cov.Print();
  cor.Print();

  // write histograms to file

  file->Write();
  file->Close();
}

int main() {
  myMacro(10000);
}
