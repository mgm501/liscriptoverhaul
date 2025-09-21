#ifndef EVENTASSIGN
#define EVENTASSIGN
#include "maps.h"
#include "variables.h"
#include "plotfunc.h"
#include <iostream>
#include <sstream>
#include <fstream>  
#include <string>
#include <vector>
#include <TTreeReader.h>
#include <TTreeReaderArray.h>
#include <TFile.h>
#include <TTree.h>

using std::string;
using std::getline;
using std::ifstream;
using std::stringstream;
using std::cout;
using std::endl;
using std::vector;

void EventAssign(int runnum, const map<unsigned short, int> map1, const map<unsigned short, int> map2, observables var, TH1D* plot[ndet], string target, string compress, string det, double norm, vector<double> array1, vector<double> array2) { //this is meant to sort events to a given detector. the index of each detector should go in order of increasing angular displacement

  TString fileName;
  //string path = "../20240819_7Li_3He_n/root_data";
  //string path1 = "../../liscriptoverhaul-2";

  //gSystem->cd(path.c_str());

  fileName.Form("catrina_%d_3000.root", runnum);
      
  TFile *filename = new TFile(fileName);
      
  TTree *tree = (TTree *)filename->Get("tree");
      
  cout << "Pulling data from TTree...\n";
  cout << "woah1\n";
  TTreeReader reader(tree);
  cout << "woah2\n";

  TTreeReaderValue<ULong64_t>  evID = {reader, "evID"};
  TTreeReaderValue<UInt_t>    multi = {reader, "multi"};
  TTreeReaderArray<UShort_t>     sn = {reader, "sn"}; // serial no.
  TTreeReaderArray<UShort_t>     ch = {reader, "ch"}; // channel
  TTreeReaderArray<UShort_t>      e = {reader, "e"};  //long
  TTreeReaderArray<UShort_t>     e2 = {reader, "e2"}; //short
  TTreeReaderArray<ULong64_t>   e_t = {reader, "e_t"}; // in ns
  TTreeReaderArray<UShort_t>    e_f = {reader, "e_f"}; // in ps
  cout << "woah3\n";

  while(reader.Next()) {
    //cout << "woah4";
	  for (int i = 0; i < *multi; i++) {
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
        //printf("%d\n",tN[ID]);
  
      } //end if statement
  
	  } //end multiplicity for loop

  fillplot(var, &plot[ndet], target, compress, array1, array2);
  
  } //end while reader
addplot(det, norm);
}//end function

vector<double> readcalibration(string filename) {
  ifstream calibrationfile;
  vector<double> calibration;
  calibrationfile.open(filename);
  if (!calibrationfile.is_open()) {
    cout << "Could not open calibration file\n";
  }
  float numstorage;
  char delimiter;
  int count = 0;
  while (calibrationfile >> numstorage) {
    if (count < (3*ndet)) {
      calibration.push_back(numstorage);
      count++;
    }
    calibrationfile >> delimiter;
  }
  calibrationfile.close();
  return calibration;
}

map<int, vector<double>> readshift(string filename, unsigned short runnum) {
  ifstream file(filename);
  if (!file.is_open()) {
    return{};
  }

  map<int, vector<double>> data;
  string line;

  while (getline(file, line)) {
    stringstream ss(line);
    int carbon;
    int i;
    double peak;
    int isbackground;

    if (ss >> carbon >> i >> peak >> isbackground) {
      if (data[carbon].size() <= static_cast<size_t>(i)) {
        data[carbon].resize(i+1);
      }
      data[carbon][i] = peak;
    }
  }

  file.close();
  return data;
}

#endif