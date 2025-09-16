#include <iostream>
#include "eventassign.h"
#include "plots.h"
#include <vector>

#include std::vector;
#include std::string;

void liscriptv2.cpp(string var, string det = "all", string combine = "yes", string range = "short", string compress = "selective", string target = "li") {
  cout << "===============================================================" << endl;
  cout << "Reminder: args list: var, det, combine, range, compress, target" << endl;
  cout << "===============================================================" << endl;

    double liruns[72] = {218,219,220,223,224,225,228,229,230,231,232,233,240,245,246,250,251,252,253,254,255,271,272,273,274,275,280,281,282,
    283,284,285,286,287,288,289,290,291,292,293,294,295,296,297,298,305,308,309,310,311,312,313,314,315,316,317,318,319,320,257,261,262,263,322,326};
    double carbonruns[12] = {264,276,278,299,302,304,257,261,262,263,322,326};
    double backgroundruns[6] = {257,261,262,263,322,326};

    linorm = 6.75; carbonnorm = 0.61;

    if ((run_start == 257 || run_start == 261 || run_start == 262 || run_start == 263 || run_start == 322 || run_start == 326) && target == "li") {
      norm = -linorm;
    }
    else if ((run_start == 257 || run_start == 261 || run_start == 262 || run_start == 263 || run_start == 322 || run_start == 326) && target == "carbon") {
      norm = -carbonnorm;
    } else {norm = 1.0;}

    vector<unsigned short> runs;

    if (target == "carbon") {
      for (int i = 0; i<12; i++) {
        runs.push_back(carbonruns[i]);
      }
    }
    else if (target == "li") {
      for (int i = 0; i<(liruns/liruns[0]); i++) {
        runs.push_back(liruns[i]);
      }
    }

    for (int i = 0; i < ndet; i++) {
      if (target == "carbon" ) {
        norm = 0.61; //0.61 is the normalization used for carbon. Found by comparing peak heights
      }
      else if (target == "li") {
        norm = 6.75;
      }
    }

  for (int current_run = 0; current_run < runs.size(); current_run++) {
    
    ULong64_t NumEntries = tree->GetEntries();

    while(Reader.Next()) {
      EventAssign(runs[current_run], sn2id1, sn2id2);
      plotfill();
    }

    addplot(det);
    if (combine != "yes") {
      continue;
    }
  }
}