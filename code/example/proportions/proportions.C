void proportions(Int_t nGen) {
  TH1F *h = new TH1F("h", "abundancies", 5, 0, 5);
  // cosmetics
  h->SetLineColor(1);
  h->GetYaxis()->SetTitleOffset(1.2);
  h->GetXaxis()->SetTitleSize(0.04);
  h->GetYaxis()->SetTitleSize(0.04);
  h->GetXaxis()->SetTitle("Cases");
  h->GetYaxis()->SetTitle("Entries");

  h->SetFillColor(4);
  Double_t x = 0;

  for (Int_t i = 0; i < nGen; i++) {
    x = gRandom->Rndm();
    if (x < 0.1)
      h->Fill(0);
    else if (x < 0.3)
      h->Fill(1);
    else if (x < 0.7)
      h->Fill(2);
    else if (x < 0.95)
      h->Fill(3);
    else
      h->Fill(4);
  }
  
  TCanvas *c1 =
      new TCanvas("c1", "Generate proportions, Example", 200, 10, 600, 400);
  h->Draw("H");
  h->Draw("E,SAME");
}
