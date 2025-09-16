#ifndef EVENTASSIGN
#define EVENTASSIGN
#include "map.h"
#include "variables.h"
#include <map>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::getline;
using std::ifstream;
using std::istringstream;
using std::cout;
using std::endl;
using std::vector;

void EventAssign(int runnum, map<unsigned short, int> map1, map<unsigned short, int> map2) { //this is meant to sort events to a given detector. the index of each detector should go in order of increasing angular displacement
  
  TString fileName;
      
  fileName.Form("catrina_%d_3000.root", runnum);
      
  TFile *filename = new TFile(fileName);
      
  TTree *tree = (TTree *)filename->Get("tree");
      
  cout << "Pulling data from TTree...\n";
      
  TTreeReader reader(tree);

  TTreeReaderValue<ULong64_t>  evID = {reader, "evID"};
  TTreeReaderValue<UInt_t>    multi = {reader, "multi"};
  TTreeReaderArray<UShort_t>     sn = {reader, "sn"}; // serial no.
  TTreeReaderArray<UShort_t>     ch = {reader, "ch"}; // channel
  TTreeReaderArray<UShort_t>      e = {reader, "e"};  //long
  TTreeReaderArray<UShort_t>     e2 = {reader, "e2"}; //short
  TTreeReaderArray<ULong64_t>   e_t = {reader, "e_t"}; // in ns
  TTreeReaderArray<UShort_t>    e_f = {reader, "e_f"}; // in ps

	for (int i = 0; i < *multi, i++) {

	  if (runnum < 194) {
      int bd = map2.at(sn[i]);
      int haha = channelmap2[bd][ch[i]];
      if( haha < 0 ) continue;
      int ID = id2angleorder.at(index2id.at(haha));
      if(ID == 200) {
        if (e_f[i] > 20000) {
          continue;
        }
        else {
          tRF = e_t[i] * 1000 + e_f[i];
        }
      }
      if( ID < 0 || ID > ndet ) continue;
      el[ID] = e[i];
      es[ID] = e2[i];
      if (e_f[i] > 20000) {
        continue;
      }
      else {
        tN[ID] = e_t[i] * 1000 + e_f[i];
      }
    }

	  else {
      int bd = map1.at(sn[i]);
      int haha = channelmap1[bd][ch[i]];
      if( haha < 0 ) continue;
      int ID = id2angleorder.at(index2id.at(haha));
      if(ID == 200) {
        if (e_f[i] > 20000) {
          continue;
        }
        else {
          tRF = e_t[i] * 1000 + e_f[i];
        }
      }
      if( ID < 0 || ID > ndet) continue;
      el[ID] = e[i];
      es[ID] = e2[i];
      if (e_f[i] > 20000) {
        continue;
      }
      else {
        tN[ID] = e_t[i] * 1000 + e_f[i];
      }

    } //end if statement

	} //end multiplicity for loop

}//end function

vector<double> readcalibration(string &filename) {
  ifstream calibrationfile;
  unsigned short runindex;
  vector<double> a;
  vector<double> b;
  calibrationfile.open(filename);
  if (!calibrationfile.is_open()) {
    cout << "Could not open calibration file\n";
  }
  string line;
  int count = 0;
  while (getline(calibrationfile, line)) {
    istringstream row(line);
    row(line) >> a[(3*count)+1] >> b[(3*count)+2];
    count++;
  }
  calibrationfile.close();
  for (int i = 0; i<ndet; i++) {
    cout << a[i] << "  " << b[i] << "\n";
  }
  return a, b;
}

vector<double> readshift(string &filename, unsigned short runnum) {
  ifstream shiftfile;
  unsigned short runindex;
  string row;
  unsigned short detector;
  double shift;
  vector<double> shifts[ndet] = {0};
  shiftfile.open(filename);
  if (!shiftfile.is_open()) {
    cout << "Something went wrong :(\n";
  }
  istringstream row;
  while (getline(shiftfile, line)) {
    row(line) >> runindex >> detector >> shift;
  }
  if (runindex == runnum) {
    shifts[detector] = shift;
  }
  return shifts;
}

#endif EVENTASSIGN