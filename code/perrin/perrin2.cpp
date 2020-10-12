void setStyle(){
  gROOT->SetStyle("Plain");
  gStyle->SetOptFit(111);
  gStyle->SetPalette(57);
  gStyle->SetOptTitle(0);
}

void perrin2() {
   TH1F *h1 = new TH1F("h1","Esperimento di Perrin",20,-4, 4); 

//Leggo dati da file:
   ifstream in;
   in.open("perrin2.dat");
   Float_t x, y;
   while (1) {
     in >> x >> y;
      if (!in.good()) break;

      h1 -> Fill(x, y);
   }
   in.close();
 
//Canvas
  TCanvas *cPerrin = new TCanvas("cPerrin", "Distanze di Salto Esperimento di Perrin");

//Cosmetica
  h1 -> GetXaxis() -> SetTitle("Distanza di Salto[#mum^{2}]");
  h1 -> GetYaxis() -> SetTitleOffset(1.3);
  h1 -> GetYaxis() -> SetTitle("Occorrenze");

  TLegend *leg=new TLegend(.1,.7,.3,.9,"Prova di Laboratorio");
  leg -> SetFillColor(0);
  leg -> Draw("Same");

  h1 -> SetFillColor(kBlue); 
  h1 -> SetMarkerStyle(4); 
  h1 -> SetLineWidth(0); 
  gStyle -> SetOptStat(112210); 

  h1->Draw("HIST");
  h1 -> Fit("gaus");
  h1-> Draw("SAME");

  cout << "*----------------------------------------------------------*" <<endl; 
  
  double a = h1 -> GetRMS();
  double e = h1 -> GetRMSError(); 

  cout << "Occorrenze Totali: " <<h1->GetEntries() <<endl; 
  cout << "Media dell'istogramma: " <<h1->GetMean() << " +/- " <<h1->GetMeanError()<<endl;
  cout << "RMS dell'istogramma: " <<h1->GetRMS() << " +/- " <<h1->GetRMSError()<<endl;
  cout << "Varianza dell'istogramma: " << a * a << " +/- " << 2 * e << endl;

  cPerrin->Print("Perrin2.pdf");
}
