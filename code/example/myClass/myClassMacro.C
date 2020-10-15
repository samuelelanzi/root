{
  TF1 *f = new TF1("f", "x", 0., 1.);
  TH1F *hIn = new TH1F("hIn", "input histo", 100, 0., 1.);
  MyClass A(hIn);
  A.Generate(f, 10000);
  A.ShowHisto();
}
