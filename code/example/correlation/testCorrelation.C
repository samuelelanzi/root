void testCorrelation(Int_t nGen) {
  gStyle->SetOptStat(0);
  TH2F *h = new TH2F("h", "", 1000, 0, TMath::Pi(), 1000, 0, 2 * TMath::Pi());
  TH3F *hSpace = new TH3F("hSpace", "", 100, -1, 1, 100, -1, 1, 100, -1, 1);
  // cosmetics
  h->SetLineColor(1);
  h->GetYaxis()->SetTitleOffset(1.2);
  h->GetXaxis()->SetTitleSize(0.04);
  h->GetYaxis()->SetTitleSize(0.04);
  h->GetXaxis()->SetTitle("#theta (rad)");
  h->GetYaxis()->SetTitle("#phi (rad)");

  Double_t phi, theta = 0;

  for (Int_t i = 0; i < nGen; i++) {
    theta = gRandom->Rndm() * TMath::Pi();
    // phi = gRandom->Rndm() * 2 * TMath::Pi();
    phi = 2 * theta; // not ok
    h->Fill(theta, phi);
    hSpace->Fill(sin(theta) * cos(phi), sin(theta) * sin(phi), cos(theta));
  }
  TCanvas *c1 = new TCanvas("c1", "theta-phi correlation", 200, 10, 600, 400);
  h->Draw();

  TCanvas *c2 = new TCanvas("c2", "xyz distribution", 200, 10, 600, 400);
  hSpace->Draw();
}
