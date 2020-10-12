void setStyle(){
  gROOT -> SetStyle("Plain");
  gStyle -> SetPalette(57);
  gStyle -> SetOptTitle(0);
}

void perrin(){
    TGraph *graph =new TGraph("perrin.dat","%lg %lg"); 
    graph -> SetTitle("Esperimento di Perrin; t [s] ; < L^{2} > [mm^{2}]");

    // Cosmetics
    graph -> SetMarkerStyle(kOpenCircle);
    graph -> SetMarkerColor(kBlue);
    graph -> SetLineColor(kBlue);

    // The canvas on which we'll draw the graph
    TCanvas *mycanvas = new TCanvas();


    // Define a linear function
    TF1 *f = new TF1("Linear law", "x*[0]", 0.0, 10.0);
    // Let's make the funcion line nicer
    f -> SetLineColor(kRed); f -> SetLineStyle(2);
    // Fit it to the graph and draw it
 
    graph -> Fit(f);
 

    // Draw the graph !
 
    gStyle -> SetOptFit(111);
    graph -> Draw("APE");

    cout << "x and y measurements correlation =" << graph -> GetCorrelationFactor() << endl;
    cout << "The Chisquare of the fit = " << graph -> Chisquare(f)<<endl;
    cout << "From function  " << f -> GetChisquare() << endl ;
    cout << "From function  " << f -> GetNDF() << endl ;
 
   // Build and Draw a legend
    TLegend *leg=new TLegend(.1,.7,.3,.9,"Prova di Laboratorio");
    leg -> SetFillColor(0);
    graph -> SetFillColor(0);
    leg -> AddEntry(graph,"Punti Sperimentali");
    leg -> AddEntry(f,"Fit Lineare");
    leg -> Draw("Same");

    mycanvas -> Print("Perrin.pdf");
}
