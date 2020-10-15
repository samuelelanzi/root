void resolution(Double_t res = 0.1, Int_t nGen = 1E6) {
  char *histName = new char[10];
  TH1F *h[2];
  for (Int_t i = 0; i < 2; i++) {
    sprintf(histName, "h%d", i);
    h[i] = new TH1F(histName, "test histogram", 100, 0, 3);
    // cosmetics
    h[i]->SetLineColor(1);
    h[i]->GetYaxis()->SetTitleOffset(1.2);
    h[i]->GetXaxis()->SetTitleSize(0.04);
    h[i]->GetYaxis()->SetTitleSize(0.04);
    h[i]->GetXaxis()->SetTitle("x after Resolution Effect");
    h[i]->GetYaxis()->SetTitle("Entries");
  }

  h[0]->SetFillColor(4);
  h[1]->SetFillColor(2);

  // first case: fixed value smeared
  Double_t fixedValue = 1.5;

  for (Int_t i = 0; i < nGen; i++) {
    h[0]->Fill(gRandom->Gaus(fixedValue, res));
  }

  // second case: Uniform distribution smeared
  for (Int_t i = 0; i < nGen; i++){
    h[1]->Fill(gRandom->Gaus(gRandom->Uniform(1, 2), res));
  }

  TCanvas *c1 =
      new TCanvas("c1", "Resolution Effects, Examples", 200, 10, 600, 400);

  c1->Divide(1, 2);

  for (Int_t i = 0; i < 2; i++) {
    c1->cd(i + 1);
    h[i]->Draw("H");
    h[i]->Draw("E,SAME");
  }
}
