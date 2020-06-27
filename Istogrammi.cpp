/*

----------------------------------------------------------
                   1) ISTOGRAMMI IN ROOT
----------------------------------------------------------

Per costruire un istogramma 
Come PUNTTATORE:

*/

TH1F *h1 = new TH1F("h1", "Titolo", nBins, x lowest bin, x highest bin);

// Come ISTANZA:

TH1F h1 = TH1F("h1", "Titolo", nBins, x lowest bin, x highest bin);

// Per riempire ciascuna occorrenza della variabile x:

h1 -> Fill(x);

h1.Fill(x);

// Il metodo Fill ha anche un altro argomento ed e' il peso di quell'ingresso

h1 -> Fill(x, 8);

// Per disegnare un istogramma 

h1 -> Draw();

h1.Draw();

// Sono disponibili varie opzioni

h1 -> Draw("E"); // Visualizza gli errori

h1 -> SetMarkerStyle(22); //Sclego il tipo di simbolo

h1 -> Draw("E, P"); //Con errori e simbolo

h1 -> Draw("HIST, SAME"); //Sovrappongo stesso istogramma con linea continua

h1 -> GetMean(); //Restituisce la media

h1 -> GetRMS(); //Radice della varianza

h1 -> GetMaximum(); //Contenuto massimo dei bin

h1 -> GetMaximumBin(); //locazione del massimo

h1 -> GetBinContent(0); //Ritorna il numero di UNDERFLOW 

h1 -> GetBinContent(Nbin + 1); //OVERFLOW

h1 -> GetBinError(ibin); //Errore contenuto nel bin

h1 -> SetBinContent(ibin, val); //assegna al contenuto del bin "ibin" il contenuto "val"

h1 -> GetEntries(); //Numero totale di conteggi

h1 -> Integral(ibin1, ibin2); //integrale nel range

h1 -> GetIntegral(); //Array dei conteggi cumulativi

h1 -> GetMeanError(); 

h1 -> GetRMSError();

// ESEMPIO 1

void histo(Int_t nev = 1E3, Float_t mean = 0., Float_t width = 1.){
    TH1F * h = new TH1F("h", " x distribution", 100, -5., 5);
    Float_t x = 0;

    for(Int_t i = 0; i < nev; i++){
        x = gRandom -> Gaus(mean, width); // un metodo di generazione Monte Carlo secondo una pdf gaussiana
        h -> Fill(x);
    }

    h -> Draw("E"); //Con errori sugli ingressi nei bin
    h -> Draw("HISTO,SAME"); //sovrapporre anche come linea continua

    TFile *file = new TFile("example.root", "RECREATE"); //aprire il file ROOT
    h -> Write(); //scrivere su file ROOT
    file -> Close(); //chiudere il file ROOT
}

/*

ROOT GLOBAL VARIABLES

~ gROOT: Informazione globale relativa alla sessione corrente attraverso il quale si puo accedere 
  praticamente a qualunque oggetto creato durante la sessione di ROOT

~ gFile: puntatore al root file corrente

~ gStyle: puntatore alla funzionelita per gestire lo stile grafico 

~ gPad: puntatore alla pad corrente 

~ gRandom: puntatore al generatore di numeri random

*/

// ESEMPIO 2

//General settings for graphics
void setStyle(){
  gROOT -> SetStyle("Plain");
  gStyle -> SetPalette(57);
  gStyle -> SetOptTitle(0);
}

void maxwell() {
// funzione principale della macro

//creazione istogramma
   TH1F *h1 = new TH1F("h1", "Tempi di Caduta", 8, -0.5, 15.5); 

//lettura da file ascii e riempimento istogramma
   ifstream in;
   in.open("maxwell.dat");
   Float_t x, y;
   while (1) {
     in >> x >> y;
      if ( ! in.good() ) break;
      h1 -> Fill(y);
   }
   in.close();
 
//Canvas, la finestra grafica.... 
 TCanvas *cMaxwell = new TCanvas("cMaxwell", "Tempi di caduta del pendolo di Maxwell");
//cosmetica: assi, colore, spessore linea,tipo di Marker... 
 h1 -> GetXaxis() -> SetTitle("Tempi di Caduta (s)");
 h1 -> GetYaxis() -> SetTitleOffset(1.3);
 h1 -> GetYaxis() -> SetTitle("Occorrenze");
 h1 -> SetFillColor(kBlue); //(KBlue=2)
 h1 -> SetMarkerStyle(4); //Open Circle
 h1 -> SetLineWidth(2); //spessore linea
 gStyle -> SetOptStat(112210); //no nome, entries, media e rms con errori, under (over)flow 
 h1 -> Draw();
 h1 -> Draw("E,same");

 cout << "*----------------------------------------------------------*" <<endl; 

 cout << "Occorrenze Totali: " << h1 -> GetEntries() << endl; 
 cout << "Media dell'istogramma: " << h1 -> GetMean() << " +/- " << h1 -> GetMeanError() << endl;
 cout << "RMS dell'istogramma: " << h1 -> GetRMS() << " +/- " << h1 -> GetRMSError() << endl;
 cMaxwell -> Print("cMaxwell.pdf");
 cMaxwell -> Print("cMaxwell.C");
 cMaxwell -> Print("cMaxwell.root");
}

/* 

OPERAZIONI TRA ISTOGRAMMI

Operazioni su istogrammi omologhi (stesso numero di bin e stasso range). Si puo fare attraverso 

OVERLOAD DELL'OPERATORE SOMMA, MOLTIPLICAZIONE, ...

*/

TH1F h1;
TH1F h2 = 3 * h1;
TH2F h3 = h1 + h2;
//Questa modalita funzione solo per le istanze e non per i puntatori

//OPPURE ATTRAVERSO I METODI DELLA CLASSE

h1 -> Add(...) //somma
h1 -> Multiply(...) //moltiplicazione
h1 -> Divide(...) //divisione

//ESEMPIO

//... creazione di due istogrammi

TH1F *h1 = new TH1F (...);
TH1F *h2 = new TH1F (...); //omologhi

// cicli di lettura e riempimento istogrammi

//dopo averli riempiti confrontiamo i dati facendo il rapporto

TH1F *hRatio = new TH1F(*h1);
hRatio -> Divide(h1, h2, 1, 1);

//sommiamo i due campioni in un unico istogramma

TH1F *hSum = new TH1F (*h1);
hSum -> Add(h1, h2, 1, 1);

//...

