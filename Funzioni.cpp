/*

----------------------------------------------------------
                   3) FUNZIONI IN ROOT
----------------------------------------------------------

Classe per funzioni di una variabile TF1 

- consente di rappresentare un'espressione C++ in cui la variabile è x
- funzioni definite dll'utente
- Sono disponibili anche dei BUILT IN function object (gaus, expo, poln)
- corrispondenti in 2, 3, dimensioni TF2, TF3

PRIMO METODO PER DEFINIRE FUNZIONI IN ROOT:
*/

TF1 *f1 = new TF1 ("f1", "sin(x) / x", 0, 10)

f1 -> Draw()

//SECONDO METODO PER DEFINRIE FUNZIONI IN ROOT

TF1 *f1 = new TF1("f1", "[0] * x * sin([1]x)", -3, 3)

f1 -> SetParameter(0,10)
f1 -> SetParameter(1, 5)

f1 -> Draw()

//TERZO METODO PIU' GENERALE
//funzione definoita dall'utente in una macro (sempre 1D)

Double_t MyFunction (Double_t *x, Double_t *par){
    Float_t xx = x[0];
    Double_t val = TMath::Abs(par[0] * sin(par[1] * xx) / xx);
}

TF1 *f1 = new TF1 ("f1", MyFunction, 0, 10, 2); //2 numero di parametri in MyFunction

f1 -> SetParameters(2, 1); //Inizializza i due parametri a 2 e 1

//Alcuni metodi utili

f -> Eval(x) // valutare la funzione in un punto
f -> Integral(a, b)
f -> DrawDerivative()
f -> DrawIntegral() // funzione cumulativa

//FITTING

//Per fare il fit di un istogramma con la funzione scelta 

TF1 *fn1 = new TF1("f1", "[0] * x * sin([1] * x)", -3, 3)

aHistogram -> Fit("f1")
aHistogram -> Fit(fn1)

aHistogram -> Fit("gaus")
aHistogram -> Fit("expo")
