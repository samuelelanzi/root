#include "MyClass.hpp"

MyClass::MyClass() { h_ = new TH1F("h", "titolo", 100, -5, 5); }
MyClass::MyClass(TH1F *hIn) { h_ = new TH1F(*hIn); }

void MyClass::Generate(TF1 *f, int nGen) {
  h_->GetXaxis()->SetRangeUser(f->GetXmin(), f->GetXmax());
  h_->FillRandom(f->GetName(), nGen);
}

void MyClass::ShowHisto() const { h_->Draw(); }
TH1F *MyClass::GetHisto() const { return h_; }