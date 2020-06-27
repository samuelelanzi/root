/*

----------------------------------------------------------------------------
							 2) GRAFICI ROOT
----------------------------------------------------------------------------

Due classi per creare grafici

~ TGraph: rappresenta una serie di N coppie di due quantita X, Y (ad esempio variabili fisiche)

~ TGraphErrors: (classe derivata) consente di includere anche gli errori EX, EY sulle quantita X, Y

classe TGraph, DUE COSTRUTTORI PRINCIPALI

*/

TGraph (Int_t n, const Double_t *x, const Double_t *y)

// n e il numero di punti
// x e y sono i nomi degli array di punti x e y

TGraph(const char *filename, const char *format = "%lg%lg", Option_t *option = "")

//Il file di input deve contnere almeno due colonne di numeri
//Il formato della stringae di default "%lg%lg" ( 2 double )
//Opzioni per skippare colonne ( "%lg%*lg%lg" ) e interpretare delimitatori differenti dal blank

TGraphErrors(Int_t n, const Double_t *x, const Double_t *y, const Double_t *ex = 0, const Double_t *ey = 0)

//n è il numero di punti
//x, y, ex, ey sono i nomi degli array di punti x e y ed i rispettivi errori

TGraphErrors(const char *filename, const char *format = "%lg%lg%lg%lg", Option_t *option = "")

//il file di input deve  contenere almeno tre colonne di numeri
//di norma sarebbero 4. Se ne contiene solo 3 allora la terza colonna è interpretata come errore in y


//ALCUNI METODI

garph -> GetPoint(i, x, y) //recupera i contenuti dell'i-esimo punto del grafico

graph -> GetX()
graph -> GetY()
graph -> GetN()

graph -> Integal()

graph -> GetCorrelationFactor()
graph -> GetCovariance()

//Fare un fit del grafico

graph -> Fit(const char *formula)
graph -> Fit (TF1 *f1) // funzione precedentemente definita





