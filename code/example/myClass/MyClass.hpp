#include "TF1.h"
#include "TH1F.h"

class MyClass {
public:
  MyClass();
  MyClass(TH1F *hIn);
  
  void Generate(TF1 *f, int nGen);
  void ShowHisto() const;
  TH1F *GetHisto() const;

private:
  TH1F *h_;
};

