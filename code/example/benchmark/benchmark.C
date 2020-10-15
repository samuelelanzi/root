#include "TBenchmark.h"
#include "TH1F.h"
#include "TRandom.h"
#include "TStyle.h"

void benchmark(Int_t nGen) {
  gStyle->SetOptStat(111111);
  char *histName = new char[10];
  TH1F *h[2];
  for (Int_t i = 0; i < 2; i++) {
    sprintf(histName, "h%d", i);
    h[i] = new TH1F(histName, "test histogram", 1000, -5, 5.);
    // cosmetics
    h[i]->SetMarkerStyle(20);
    h[i]->SetMarkerSize(0.5);
    h[i]->SetLineColor(1);
    h[i]->GetYaxis()->SetTitleOffset(1.5);
    h[i]->GetXaxis()->SetTitle("x");
    h[i]->GetYaxis()->SetTitle("Entries");
  }

  h[0]->SetFillColor(4);
  h[1]->SetFillColor(2);

  // filling the histo
  gBenchmark->Start("With TH1::FillRandom");

  // with numerical inverse transform
  h[0]->FillRandom("gaus", nGen);
  // stop and show benchmark
  gBenchmark->Show("With TH1::FillRandom");

  // with inverse transform
  Double_t x = 0;
  gBenchmark->Start("Direct TRandom::Gaus invocation");
  for (Int_t i = 0; i < nGen; i++) {
    x = gRandom->Gaus(0, 1);
    h[1]->Fill(x);
  }
  // Stop and show benchmark
  gBenchmark->Show("Direct TRandom::Gaus invocation");
}
