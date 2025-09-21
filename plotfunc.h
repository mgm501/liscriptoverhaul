#ifndef PLOTFUNC_H
#define PLOTFUNC_H
#include "variables.h"
#include <iostream>
#include "TCutG.h"
#include "TH1.h"
#include "TH2.h"
#include "cuts.h"
#include "maps.h"

using std::string;
using std::stoi;

TCutG *cuts[ndet];

TH1D *plot[ndet];
TH2D *plot2d[ndet];
TH1D *total1d[ndet];
TH2D *total2d[ndet];
TH1D *alldetplot;

inline void initializeplot(observables var) {
  int xbins; int xmin; int xmax; int ybins; int ymin; int ymax;
  for (int i = 0; i < ndet; i++) {
    xbins  = var.xbins;
    xmin   = var.xmin;
    xmax   = var.xmax;
    ybins  = var.ybins;
    ymin   = var.ymin;
    ymax   = var.ymax;

    if (i == 0 || i == 1) {
      xbins = var.xbins1;
      xmin  = var.xmin1;
      xmax  = var.xmax1;
      ybins = var.ybins1;
      ymin  = var.ymin1;
      ymax  = var.ymax1;
    }
    if (i == 0 || i == 1) {
      plot[i] = new TH1D(Form("plot %d", i), Form("Detector %d", i), xbins, xmin, xmax);
      plot2d[i] = new TH2D(Form("plot 2d %d", i), Form("Detector %d", i), xbins, xmin, xmax, ybins, ymin, ymax);
      total1d[i] = new TH1D(Form("total1d %d",i), Form("Detector %d", i), xbins, xmin, xmax);
      total2d[i] = new TH2D(Form("PSDindex %d", i), Form("Detector %d", i), xbins, xmin, xmax, ybins, ymin, ymax);
    }
    else {
    plot[i] = new TH1D(Form("plot %d", i), Form("Detector %d", i), xbins, xmin, xmax);
    plot2d[i] = new TH2D(Form("plot 2d %d", i), Form("Detector %d", i), xbins, xmin, xmax, ybins, ymin, ymax);
    total1d[i] = new TH1D(Form("total1d %d",i), Form("Detector %d", i), xbins, xmin, xmax);
    total2d[i] = new TH2D(Form("PSDindex %d", i), Form("Detector %d", i), xbins, xmin, xmax, ybins, ymin, ymax);
    }
  }
  alldetplot = new TH1D("allsum", "All Detectors", xbins, xmin, xmax);
}
inline void fillplot(observables var, TH1D* plot[ndet], string target, string compress, vector<double> a, vector<double> b) {
  if (target == "carbon") {
    for (int i = 0; i<ndet; i++) {
      cuts[i]=carboncuts[i];
    }
  } else {
    for (int i = 0; i<ndet; i++) {
      cuts[i]=licuts[i];
    }
  }
  for (int i = 0; i < ndet; i++) {
    if (tN[i] > 0 && tRF != 0) {
      if (tN[i] < tRF) {
        tof = tRF - tN[i];
      }
      else {
        tof = tN[i] - tRF;
      }
      if (var.name == "tof") {plot[i]->Fill(tof);}
      if (var.name == "psd") {plot2d[i]->Fill((a[i]*el[i])+b[i], (el[i]-es[i])*1.0/el[i]);}
      if (compress == "compress") {
        if (tof < 0) {
          tof += 165.;
        } 
        if (tof > 82.5) {
          tof -= 82.5;
        }
      }
      if (compress == "selective") {
        if (tof < 0 || tof > 82.5) {
          continue;
        } 
      }
      if (compress != "" || compress != "compress" || compress != "selective") {
        std::cerr << "Reminder: compress takes three values: \n'', 'compress, or 'selective'";
      }
      if(cuts[i]->IsInside(((a[i]*el[i]) + b[i]), ((el[i]-es[i])*1.0/el[i]))) {
        if (var.name == "tofg") {plot[i]->Fill(tof);}
        tofsec = tof * 1.e-9;
        mev = joules2mev * ( (0.5) * mnsi * ((sorteddistance[i] * sorteddistance[i]) / (tofsec * tofsec)) );
        if (target == "carbon") {
          residualmass = m14o;
          q0 = -1.15;
        } else if (target == "li") {
          residualmass = m9b;
          q0 = 9.35;
        }
        q = mev - beamenergy + ( (1/residualmass) * ( (projectilemass * beamenergy) + (mn * mev) - (2 * sqrt(m3he*mn*beamenergy*mev) * cos((3.14159 * angle[i])/ 180.)) )); 
        ex = q0 - q;
        if (var.name == "excitation" || var.name == "qvalues" || var.name == "excitation") {
          if (mev < -20 || mev > 20 || ex < -20 || ex > 20 || i == 16 || i == 17) {
            continue;
          }
          else {
            if (var.name == "qvalues") {plot[i]->Fill(q0);}
            if (var.name == "nenergy") {plot[i]->Fill(mev);}
            if (var.name == "excitation") {plot[i]->Fill(ex);}
          }
        }
      }
    }
  }
}

inline void addplot(string &det, double norm) {
  if (det == "all") {
    for (int i = 0; i < ndet; i++) {
      {total1d[i]->Add(plot[i],norm);}
      //plot[i]->Reset();
    }
  } else {
    int detnum = stoi(det);
    int detindex = num2id.at(detnum);
    total1d[detindex]->Add(plot[detindex],norm);
  }
}

inline void displayplot(string & det) {
  TCanvas *canvas = new TCanvas();
  if (det == "all") {
    canvas->Divide(5,4);
    for (int i = 0; i < ndet; i++) {
      canvas->cd(i+1);
      total1d[i]->Draw();
    }
  } else {
    int detnum = stoi(det);
    int detindex = num2id.at(detnum);
    total1d[detindex]->Draw();
  }
}

#endif
