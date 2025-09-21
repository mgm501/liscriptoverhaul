#include <iostream>
#include "maps.h"
#include "variables.h"
#include "cuts.h"
#include "plotfunc.h"
#include "eventassign.h"
#include "TTreeReader.h"
#include "TTreeReaderArray.h"
#include <stdio.h>

using std::vector;
using std::string;
struct observables var;

void liscriptv2(string instance = "tof", string includedet = "all", string contract = "selective", string target = "li") {
  cout << "===============================================================\n";
  cout << "Reminder:\nargs list:\ninstance, det compress, target\n";
  cout << "===============================================================\n";

  //auto name = observablesmap.find(instance);

  //cout << "woah";

  if (tof_s.name == instance) {
    var = tof_s;
  }

  initializeplot(var);
 
  //vector<int> liruns = {218,219,220,223,224,225,228,229,230,231,232,233,240,245,246,250,251,252,253,254,255,271,272,273,274,275,280,281,282,
  //283,284,285,286,287,288,289,290,291,292,293,294,295,296,297,298,305,308,309,310,311,312,313,314,315,316,317,318,319,320,257,261,262,263,322,326};
  vector<int> liruns = {300};
  vector<int> carbonruns = {264,276,278,299,302,304,257,261,262,263,322,326};
  vector<int> backgroundruns = {257,261,262,263,322,326};
  linorm = 6.75; carbonnorm = 0.61;

  vector<double> a; 
  vector<double> b;
  vector<double> calibration = readcalibration("calibration.txt");
  for (size_t i = 1; i<calibration.size(); i+=3) {
    a.push_back(calibration[i]); 
  }
  for (size_t i = 2; i<calibration.size(); i+=3) {
    b.push_back(calibration[i]);
  }

  vector<unsigned short> runs;

  if (target == "carbon") {
    for (int i = 0; i<carbonruns.size(); i++) {
      runs.push_back(carbonruns[i]);
    }
  } else if (target == "li") {
    for (int i = 0; i<liruns.size(); i++) {
      runs.push_back(liruns[i]);
    }
  }

  for (int i = 0; i < ndet; i++) {
    if (target == "carbon" ) {
      normalization = 0.61; //0.61 is the normalization used for carbon. Found by comparing peak heights
    }
    else if (target == "li") {
      normalization = 6.75;
    }
  }

  for (int current_run = 0; current_run < runs.size(); current_run++) {

    int run = runs[current_run];
    printf("%d\n",run);
    map<int, vector<double>> data = readshift("lishifts.txt",run);

    if ((run == 257 || run == 261 || run == 262 || run == 263 || run == 322 || run == 326) && target == "li") {
      normalization = -linorm;
    }
    else if ((run == 257 || run == 261 || run == 262 || run == 263 || run == 322 || run == 326) && target == "carbon") {
      normalization = -carbonnorm;
    } else {normalization = 1.0;}
    //cout << "yupppppp";

    EventAssign(runs[current_run], sn2id1, sn2id2, var, &plot[ndet], target, contract, includedet, normalization, a, b);
  }
  displayplot(includedet);
}