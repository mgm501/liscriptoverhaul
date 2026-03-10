#include "TFile.h"
#include "TTree.h"
#include "TTreeReader.h"
#include "TTreeReaderArray.h"
#include "TH2.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TCutG.h"
#include "TChain.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <TEntryList.h>
#include <sstream>
#include <vector>
#include "TH1.h"
#include "TF1.h"
#include "TSpectrum.h"
#include <iomanip>
#include <utility>
#include <string>
#include <cmath>
#include <algorithm>
#include "TSystem.h"
//#include "plot.h"
//#include "plotdef.h"
#define NDET 17

//struct Plot Plot;
//struct Plot *tof[NDET];

TFile *_file2 = TFile::Open("root_data/cuts/neutron_cuts.root");
TCutG *ncut_00 = (TCutG*)gROOT->FindObject("lowcut111");
TCutG *ncut_01 = (TCutG*)gROOT->FindObject("lowcut111");
TCutG *ncut_02 = (TCutG*)gROOT->FindObject("lowcut111");
TCutG *ncut_03 = (TCutG*)gROOT->FindObject("lowcut111");
TCutG *ncut_04 = (TCutG*)gROOT->FindObject("lowcut111");
TCutG *ncut_05 = (TCutG*)gROOT->FindObject("lowcut111");
TCutG *ncut_06 = (TCutG*)gROOT->FindObject("lowcut111");
TCutG *ncut_07 = (TCutG*)gROOT->FindObject("lowcut105");
TCutG *ncut_08 = (TCutG*)gROOT->FindObject("lowcut106");
TCutG *ncut_09 = (TCutG*)gROOT->FindObject("lowcut111");
TCutG *ncut_10 = (TCutG*)gROOT->FindObject("lowcut111");
TCutG *ncut_11 = (TCutG*)gROOT->FindObject("lowcut111");
TCutG *ncut_12 = (TCutG*)gROOT->FindObject("lowcut111");
TCutG *ncut_13 = (TCutG*)gROOT->FindObject("lowcut111");
TCutG *ncut_14 = (TCutG*)gROOT->FindObject("lowcut111");
TCutG *ncut_15 = (TCutG*)gROOT->FindObject("lowcut106");
TCutG *ncut_16 = (TCutG*)gROOT->FindObject("lowcut106");

TFile *file = TFile::Open("root_data/cuts/newgcut.root");
TCutG *gcut_00 = (TCutG*)gROOT->FindObject("gate100");
TCutG *gcut_01 = (TCutG*)gROOT->FindObject("gate100");
TCutG *gcut_02 = (TCutG*)gROOT->FindObject("gate100");
TCutG *gcut_03 = (TCutG*)gROOT->FindObject("gate100");
TCutG *gcut_04 = (TCutG*)gROOT->FindObject("gate100");
TCutG *gcut_05 = (TCutG*)gROOT->FindObject("gate100");
TCutG *gcut_06 = (TCutG*)gROOT->FindObject("gate100");
TCutG *gcut_07 = (TCutG*)gROOT->FindObject("gate100");
TCutG *gcut_08 = (TCutG*)gROOT->FindObject("gate100");
TCutG *gcut_09 = (TCutG*)gROOT->FindObject("gate100");
TCutG *gcut_10 = (TCutG*)gROOT->FindObject("gate100");
TCutG *gcut_11 = (TCutG*)gROOT->FindObject("gate100");
TCutG *gcut_12 = (TCutG*)gROOT->FindObject("gate100");
TCutG *gcut_13 = (TCutG*)gROOT->FindObject("gate100");
TCutG *gcut_14 = (TCutG*)gROOT->FindObject("gate100");
TCutG *gcut_15 = (TCutG*)gROOT->FindObject("gate100");
TCutG *gcut_16 = (TCutG*)gROOT->FindObject("gate100");

TFile *file2 = TFile::Open("root_data/cuts/newgcut.root");
TCutG *cut1 = (TCutG *)gROOT->FindObject("gate100");
TCutG *cut2 = (TCutG *)gROOT->FindObject("gate200");
TCutG *cut3 = (TCutG *)gROOT->FindObject("gate400");
TCutG *cut4 = (TCutG *)gROOT->FindObject("gate700");
TCutG *cut5 = (TCutG *)gROOT->FindObject("gate1000");

TFile * file3 = TFile::Open("root_data/cuts/thesiscut.root");
TCutG *tcut_00 = (TCutG*)gROOT->FindObject("threshold400_136");
TCutG *tcut_01 = (TCutG*)gROOT->FindObject("threshold400_136");
TCutG *tcut_02 = (TCutG*)gROOT->FindObject("threshold400_136");
TCutG *tcut_03 = (TCutG*)gROOT->FindObject("threshold400_136");
TCutG *tcut_04 = (TCutG*)gROOT->FindObject("threshold200_133");
TCutG *tcut_05 = (TCutG*)gROOT->FindObject("threshold400_136");
TCutG *tcut_06 = (TCutG*)gROOT->FindObject("threshold200_105");
TCutG *tcut_07 = (TCutG*)gROOT->FindObject("threshold400_136");
TCutG *tcut_08 = (TCutG*)gROOT->FindObject("threshold200_136");
TCutG *tcut_09 = (TCutG*)gROOT->FindObject("threshold400_136");
TCutG *tcut_10 = (TCutG*)gROOT->FindObject("threshold400_136");
TCutG *tcut_11 = (TCutG*)gROOT->FindObject("threshold200_123");
TCutG *tcut_12 = (TCutG*)gROOT->FindObject("threshold400_136");
TCutG *tcut_13 = (TCutG*)gROOT->FindObject("threshold400_136");
TCutG *tcut_14 = (TCutG*)gROOT->FindObject("threshold400_136");
TCutG *tcut_15 = (TCutG*)gROOT->FindObject("threshold400_136");
TCutG *tcut_16 = (TCutG*)gROOT->FindObject("threshold400_136");

TFile * file4 = TFile::Open("root_data/cuts/400keveecut.root");
TCutG *fcut_00 = (TCutG*)gROOT->FindObject("thresh400_0");
TCutG *fcut_01 = (TCutG*)gROOT->FindObject("thresh400_0");
TCutG *fcut_02 = (TCutG*)gROOT->FindObject("thresh400_0");
TCutG *fcut_03 = (TCutG*)gROOT->FindObject("thresh400_0");
TCutG *fcut_04 = (TCutG*)gROOT->FindObject("thresh400_133");
TCutG *fcut_05 = (TCutG*)gROOT->FindObject("thresh400_0");
TCutG *fcut_06 = (TCutG*)gROOT->FindObject("newthresh400_6");
TCutG *fcut_07 = (TCutG*)gROOT->FindObject("thresh400_0");
TCutG *fcut_08 = (TCutG*)gROOT->FindObject("thresh400_0");
TCutG *fcut_09 = (TCutG*)gROOT->FindObject("thresh400_0");
TCutG *fcut_10 = (TCutG*)gROOT->FindObject("thresh400_0");
TCutG *fcut_11 = (TCutG*)gROOT->FindObject("thresh400_11");
TCutG *fcut_12 = (TCutG*)gROOT->FindObject("thresh400_0");
TCutG *fcut_13 = (TCutG*)gROOT->FindObject("thresh400_13");
TCutG *fcut_14 = (TCutG*)gROOT->FindObject("thresh400_0");
TCutG *fcut_15 = (TCutG*)gROOT->FindObject("thresh400_0");
TCutG *fcut_16 = (TCutG*)gROOT->FindObject("thresh400_0");

TCutG *threshcuts1[NDET] = {cut1,cut1,cut1,cut1,cut1,cut1,cut1,cut1,cut1,cut1,cut1,cut1,cut1,cut1,cut1,cut1,cut1};

TCutG *threshcuts2[NDET] = {cut2,cut2,cut2,cut2,cut2,cut2,cut2,cut2,cut2,cut2,cut2,cut2,cut2,cut2,cut2,cut2,cut2};

TCutG *threshcuts3[NDET] = {cut3,cut3,cut3,cut3,cut3,cut3,cut3,cut3,cut3,cut3,cut3,cut3,cut3,cut3,cut3,cut3,cut3};

TCutG *threshcuts4[NDET] = {cut4,cut4,cut4,cut4,cut4,cut4,cut4,cut4,cut4,cut4,cut4,cut4,cut4,cut4,cut4,cut4,cut4};

TCutG *threshcuts5[NDET] = {cut5,cut5,cut5,cut5,cut5,cut5,cut5,cut5,cut5,cut5,cut5,cut5,cut5,cut5,cut5,cut5,cut5};

TCutG *kevee400[NDET] = {
fcut_00,
fcut_01,
fcut_02,
fcut_03,
fcut_04,
fcut_05,
fcut_06,
fcut_07,
fcut_08,
fcut_09,
fcut_10,
fcut_11,
fcut_12,
fcut_13,
fcut_14,
fcut_15,
fcut_16,
};

TCutG *thesiscut[NDET] = {
  tcut_00,
  tcut_01,
  tcut_02,
  tcut_03,
  tcut_04,
  tcut_05,
  tcut_06,
  tcut_07,
  tcut_08,
  tcut_09,
  tcut_10,
  tcut_11,
  tcut_12,
  tcut_13,
  tcut_14,
  tcut_15,
  tcut_16
};

TCutG *gcuts[NDET] = {
gcut_00,
gcut_01,
gcut_02,
gcut_03,
gcut_04,
gcut_05,
gcut_06,
gcut_07,
gcut_08,
gcut_09,
gcut_10,
gcut_11,
gcut_12,
gcut_13,
gcut_14,
gcut_15,
gcut_16
};

TCutG *ncuts[NDET] = {
ncut_00,
ncut_01,
ncut_02,
ncut_03,
ncut_04,
ncut_05,
ncut_06,
ncut_07,
ncut_08,
ncut_09,
ncut_10,
ncut_11,
ncut_12,
ncut_13,
ncut_14,
ncut_15,
ncut_16
};

const std::map<unsigned short, int> SN2Bd = {
  {336, 0},
  {409, 1},
  {89, 2},
};


const std::map<unsigned short, int> SN2Bd2 = {
  {336, 0},
  {409, 1},
  {405, 2},
};

// 3,5,6,9,11,12,14, big neutron
// 105, 106, 107, 108, 110, 111, 112, 114, 115  small neutron detector
// 200 is RF
// detector number in channel number index
const int mapping[3][16] = {
  // 0,   1,   2,  3,  4,   5,   6,   7,  8,   9,  10,  11,  12, 13,  14, 15
  {108,  -1,  -1, -1, -1, 105, 106, 107, -1,  -1, 110, 111, 112, -1, 114, 115 },
  { -1,  -1,  -1,  4, -1,   5,   7,  -1, -1,   2,  -1,  11,  10, -1,  13,   8 },
  { -1,  -1,  -1, -1, -1,  -1,  -1,  -1, -1,  -1,  -1,  -1, 200, -1,  -1,  -1 }
};

const int mapping2[3][16] = {
  // 0,   1,   2,  3,  4,   5,   6,   7,  8,   9,  10,  11,  12, 13,  14, 15
  {108,  -1,  -1, -1, -1, 105, 106, 107, -1,  -1, 110, 111, 112, -1, 114, 115 },
  { -1,  -1,  -1,  4, -1,   5,   7,  -1, -1,   2,  -1,  11,  10, -1,  13,   8 },
  { 200,  -1,  -1, -1, -1,  -1,  -1,  -1, -1,  -1,  -1,  -1, -1, -1,  -1,  -1 }
};


// small detectors prefixed with 100. detector index to loop id
const std::map<unsigned short, int> Index2ID = {
  {  2,   3},
  {  4,   0},
  {  5,   1},
  {  7,   2},
  {  8,  15},
  { 10,   4},
  { 11,   5},
  { 13,   6},
  {105,   7},
  {106,   8},
  {107,   9},
  {108,  10},
  {110,  11},
  {111,  12},
  {112,  13},
  {114,  14},
  {115,  16},
  {200, 200},
};

const std::map<unsigned short, int> ID2Index = {
  {  3,  2},
  {  0,  4},
  {  1,  5},
  {  2,  7},
  { 15,  8},
  {  4,  10},
  {  5,  11},
  {  6,  13},
  {  7,  105},
  {  8,  106},
  {  9,  107},
  { 10,  108},
  { 11,  110},
  { 12,  111},
  { 13,  112},
  { 14,  114},
  { 16,  115},
  {200,  200},
};


//this is the channel number to loop index
const std::map<unsigned short, int> Channel2ID = {
  {3,    0},
  {5,    1},
  {6,    2},
  {9,    3},
  {11,   5},
  {12,   4},
  {14,   6},
  {15,  15},
  {105,  7},
  {106,  8},
  {107,  9},
  {100,  10},
  {110,  11},
  {111,  12},
  {112,  13},
  {114,  14},
  {115,  16},
};

//this is loop index to channel number
const std::map<unsigned short, int> ID2Board = {
  {0,  3},
  {1,  5},
  {2,  6},
  {3,  9},
  {4,  12},
  {5,  11},
  {6,  14},
  {7,  105},
  {8,  106},
  {9,  107},
  {10, 100},
  {11, 110},
  {12, 111},
  {13, 112},
  {14, 114},
  {15, 15},
  {16, 115},
};

//this is loop index to board
const std::map<int, int> Det2Board = {
  {0,  409},
  {1,  409},
  {2,  409},
  {3,  409},
  {4,  409},
  {5,  409},
  {6,  409},
  {7,  336},
  {8,  336},
  {9,  336},
  {10, 336},
  {11, 336},
  {12, 336},
  {13, 336},
  {14, 336},
  {15, 409},
  {16, 336},
};
//this is loop index to channel without board
const std::map<int, int> Det2Channel = {
  {0,  3},
  {1,  5},
  {2,  6},
  {3,  9},
  {4,  12},
  {5,  11},
  {6,  14},
  {7,  5},
  {8,  6},
  {9,  7},
  {10, 0},
  {11, 10},
  {12, 11},
  {13, 12},
  {14, 14},
  {15, 15},
  {16, 15},
};

//loop id to angle order
std::map<int, int> Det2AngleOrder = {
{0, 12},
{1, 15},
{2, 7},
{3, 3},
{4, 14},
{5, 6},
{6, 8},
{7, 5},
{8, 11},
{9, 0},
{10, 16},
{11, 4},
{12, 13},
{13, 2},
{14, 10},
{15, 1},
{16, 9},
};

double Angle[NDET] = {127.5, 0, 136.5, 101, 133.5, 111.5, 105, 97, 108.5, 0, 140, 123, 47.5, 136, 102.5, 50, 129.5}; //44, 54

float ToF[NDET] = {81.97, 0, 83.6, 76.79, 82.81, 78.79, 77.79, 76.28, 78.29, 79.28, 83.97, 81.53, 32.38, 83.21, 77.29, 32.55, 82.40};

float energy[NDET] = {3.37, 0, 3.24, 3.84, 3.3, 3.6, 3.74, 3.89, 3.69, 3.6, 3.21, 3.41, 4.98, 3.27, 3.79, 4.93, 3.34};

float energyee[NDET] = {770.46, 0, 727.12, 933.65, 747.61, 865.63, 898.6, 951.93, 881.85, 849.98, 717.75, 782.76, 1365.58, 737.06, 915.59, 1345.83, 758.74};

int Channel[NDET] = {7387,1761,4914,10260,7781,8249,8358,12210,9812,16390,8408,8157,18570,8008,11170,12220,8860};

TH1D *tDiff[NDET];
TH1D *tDiffcut[NDET];
TH1D *tDiffg[NDET];
TH1D *tDiffg1[NDET];
TH1D *tDiffg2[NDET];
TH1D *tDiffg3[NDET];
TH1D *tDiffg4[NDET];
TH1D *tDiffg5[NDET];
TH1D *total[NDET];
TH1D *total1[NDET];
TH1D *total2[NDET];
TH1D *total3[NDET];
TH1D *total4[NDET];
TH1D *total5[NDET];
TH2D *totalPSD[NDET];
TH2D *PSD[NDET];
TH2D *PSDc[NDET];
TH2D *PSDc1[NDET];
TH2D *PSDc2[NDET];
TH2D *PSDc3[NDET];
TH2D *PSDc4[NDET];
TH2D *PSDc5[NDET];
TH2D *totalPSDc[NDET];
TH2D *totalPSDc1[NDET];
TH2D *totalPSDc2[NDET];
TH2D *totalPSDc3[NDET];
TH2D *totalPSDc4[NDET];
TH2D *totalPSDc5[NDET];
TH2D *total2d[NDET];
TCutG *cuts[NDET];
TH2D *lovstof[NDET];
TH1D *energyplot;
TH1F *qvalues[NDET];
TH1F *totq[NDET];
TH1D *cal[NDET];
TH1D *totalcal[NDET];
TH1D *totalcal2[NDET];
TH1D *nenergy[NDET];
TH1D *totnenergy[NDET];
TH1 *fithist[NDET];

ushort eL[NDET];
ushort eS[NDET];
ushort eTail[NDET];

const float timeResol = 2; //ns
const int timeRange[2] = {200, 800};
const int timeBin = (timeRange[1] - timeRange[0])/timeResol;
//const int timeBin = 600;
const int energyrange[2] = {-6,6};

std::map<int, std::vector<double>> ReadLogFile(const std::string& filename) {
  std::ifstream file(filename);

  std::map<int, std::vector<double>> data;
  std::string line;

  while (std::getline(file, line)) {
    std::istringstream ss(line);
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

struct bounds {
  int x1;
  int x2;
};

struct bounds outside;
struct bounds inside;

std::map<int, int> AngleOrder2Det;

//===========================================================================================================================
//================================================begin function=============================================================
//===========================================================================================================================

void liscript(TString det = "all", TString type = "totaltDiff", TString calibration = "yes", TString range = "short", TString compress = "", TString target = "li") {

  double CMAngle[NDET] = {53.8, 56.6, 105.5, 109.4, 110.9, 113.3, 116.7, 119.5, 130.2, 134.3, 136.1, 139.7, 142, 142.4, 145.5};

  for (const auto& pair : Det2AngleOrder) {
    AngleOrder2Det[pair.second] = pair.first;
  }

  std::cout << "start for loop" << std::endl;

  double distance[NDET] = {1.97, 0, 1.935, 1.99, 1.99, 2.02, 2.03, 2.08, 2.09, 0, 1.94, 1.98, 0.85, 1.98, 2.08, 0.85, 1.94}; //0.85, 0.86

  int x; int y;

  outside.x1 = timeRange[0];
  outside.x2 = timeRange[1];
  inside.x1 = -200;
  inside.x2 = 400;

  if (range == "short" && type != "flip") {
    x = inside.x1;
    y = inside.x2;
  }
  else if (range == "out" && type != "flip") {
    x = timeRange[0];
    y = timeRange[1];
  }
  else if (range == "short" && type == "flip") {
    x = -800;
    y = -200;
  }

  std::cout << "========================================" << std::endl;
  std::cout << "Type " << type << "  Range " << range << std::endl;
  std::cout << "========================================" << std::endl;

  for (int i = 0; i < NDET; i++) {
    PSD[i] = new TH2D(Form("PSDnum-%d", i), Form(" Detector %d Channel - %d Angle - %.1f", ID2Board.at(i), Channel[i], Angle[i]), 4096, -100, 30000, 512, -.1, 1);
    PSDc[i] = new TH2D(Form("PSDgnumc-%d", i), Form(" Detector %d", ID2Board.at(i)), 2000, -100, 3500, 512, -0.1, 0.8); // 4096
    PSDc1[i] = new TH2D(Form("PSDgnumc1-%d", i), Form(" Detector %d", ID2Board.at(i)), 2000, -100, 3500, 512, -0.1, 0.8); // 4096
    PSDc2[i] = new TH2D(Form("PSDgnumc2-%d", i), Form(" Detector %d", ID2Board.at(i)), 2000, -100, 3500, 512, -0.1, 0.8); // 4096
    PSDc3[i] = new TH2D(Form("PSDgnumc3-%d", i), Form(" Detector %d", ID2Board.at(i)), 2000, -100, 3500, 512, -0.1, 0.8); // 4096
    PSDc4[i] = new TH2D(Form("PSDgnumc4-%d", i), Form(" Detector %d", ID2Board.at(i)), 2000, -100, 3500, 512, -0.1, 0.8); // 4096
    PSDc5[i] = new TH2D(Form("PSDgnumc5-%d", i), Form(" Detector %d", ID2Board.at(i)), 2000, -100, 3500, 512, -0.1, 0.8); // 4096
    totalPSDc[i] = new TH2D(Form("PSDgnumctot-%d", i), Form("PSD Spectrum %f Det %d", Angle[i], ID2Board.at(i)), 2000, -100, 3500, 512, -0.1, 0.8); //4096
    totalPSDc[i]->GetXaxis()->SetTitle("Long Integral (keVee)"); totalPSDc[i]->GetYaxis()->SetTitle("PSD Ratio");
    totalPSDc1[i] = new TH2D(Form("PSDgnumctot1-%d", i), Form(" Detector %d NE - %.2f Angle - %.1f ToF - %.2f", ID2Board.at(i), energyee[i], Angle[i], ToF[i]), 2000, -100, 3500, 512, -0.1, 0.8); //4096
    totalPSDc2[i] = new TH2D(Form("PSDgnumctot2-%d", i), Form(" Detector %d NE - %.2f Angle - %.1f ToF - %.2f", ID2Board.at(i), energyee[i], Angle[i], ToF[i]), 2000, -100, 3500, 512, -0.1, 0.8); //4096
    totalPSDc3[i] = new TH2D(Form("PSDgnumctot3-%d", i), Form(" Detector %d NE - %.2f Angle - %.1f ToF - %.2f", ID2Board.at(i), energyee[i], Angle[i], ToF[i]), 2000, -100, 3500, 512, -0.1, 0.8); //4096
    totalPSDc4[i] = new TH2D(Form("PSDgnumctot4-%d", i), Form(" Detector %d NE - %.2f Angle - %.1f ToF - %.2f", ID2Board.at(i), energyee[i], Angle[i], ToF[i]), 2000, -100, 3500, 512, -0.1, 0.8); //4096
    totalPSDc5[i] = new TH2D(Form("PSDgnumctot5-%d", i), Form(" Detector %d NE - %.2f Angle - %.1f ToF - %.2f", ID2Board.at(i), energyee[i], Angle[i], ToF[i]), 2000, -100, 3500, 512, -0.1, 0.8); //4096
    lovstof[i] = new TH2D(Form("lovstof-%d", i), Form(" Detector %d Angle - %.1f", ID2Board.at(i), Angle[i]), 125, -20, 20, timeBin, x, y); //4096
    total[i] = new TH1D(Form("Total %d",i), Form("Gated Time of Flight %d", ID2Board.at(i)), timeBin, x, y); //4096
    total[i]->GetXaxis()->SetTitle("Time of Flight (ns)"); total[i]->GetYaxis()->SetTitle("Counts");
    total1[i] = new TH1D(Form("totalTdiff1 - %d",i), Form(" Detector %d Angle - %.1f ToF - %.2f", ID2Board.at(i), Angle[i], ToF[i]), timeBin, x, y);
    total2[i] = new TH1D(Form("totalTdiff2 - %d",i), Form(" Detector %d Angle - %.1f ToF - %.2f", ID2Board.at(i), Angle[i], ToF[i]), timeBin, x, y);
    total3[i] = new TH1D(Form("totalTdiff3 - %d",i), Form(" Detector %d Angle - %.1f ToF - %.2f", ID2Board.at(i), Angle[i], ToF[i]), timeBin, x, y);
    total4[i] = new TH1D(Form("totalTdiff4 - %d",i), Form(" Detector %d Angle - %.1f ToF - %.2f", ID2Board.at(i), Angle[i], ToF[i]), timeBin, x, y);
    total5[i] = new TH1D(Form("totalTdiff5 - %d",i), Form(" Detector %d Angle - %.1f ToF - %.2f", ID2Board.at(i), Angle[i], ToF[i]), timeBin, x, y);
    totalPSD[i] = new TH2D(Form("PSDindex-%d", i), Form(" Detector %d Channel - %d Angle - %.1f ToF - %.2f", ID2Board.at(i), Channel[i], Angle[i], ToF[i]), 4096, -1000, 30000, 512, -.1, 1);
    tDiffcut[i] = new TH1D(Form("totalTdiffcut - %d",i), Form(" Detector %d Angle - %.1f ToF - %.2f", ID2Board.at(i), Angle[i], ToF[i]), timeBin, x, y);
    if (i == 12 || i == 15) {
      qvalues[i] = new TH1F(Form("energies %d" , i), Form(" Detector %d", ID2Board.at(i)), 50, -20, 20); //125 binning for backwards 27.6 for forwards // 14 bins initially
      fithist[i] = new TH1F(Form("fithist %d" , i), Form(" Detector %d Angle - %.1f Dis - %.1f", ID2Board.at(i), Angle[i], distance[i]), 50, -20, 20);
      nenergy[i] = new TH1D(Form("n energies %d" , i), Form(" Detector %d Angle %.1f", ID2Board.at(i), Angle[i]), 50, -20, 20);
      totnenergy[i] = new TH1D(Form("tot nenergies %d" , i), Form(" Detector %d Angle %.1f", ID2Board.at(i), Angle[i]), 50, -20, 20);
      totq[i] = new TH1F(Form("energiesq %d" , i), Form(" Detector %d Angle - %.1f CM Angle - %.1f", ID2Board.at(i), Angle[i], CMAngle[AngleOrder2Det.at(i)]), 50, -20, 20); //139 bins for carbon, -20 to 20
    }
    else {
      qvalues[i] = new TH1F(Form("energies %d" , i), Form(" Detector %d", ID2Board.at(i)), 50, -25, 15); //50 or 125
      fithist[i] = new TH1F(Form("fithist %d" , i), Form(" Detector %d Angle - %.1f Dis - %.1f", ID2Board.at(i), Angle[i], distance[i]), 125, -30, 10);
      nenergy[i] = new TH1D(Form("n energies %d" , i), Form(" Detector %d Angle %.1f", ID2Board.at(i), Angle[i]), 125, 0, 20);
      totnenergy[i] = new TH1D(Form("tot nenergies %d" , i), Form("Neutron Energies"), 50, 0, 20);
      totnenergy[i]->GetXaxis()->SetTitle("Neutron Energies (MeV)"); totnenergy[i]->GetYaxis()->SetTitle("Counts");
      totq[i] = new TH1F(Form("Detector %d" , i), Form("Excitations"), 50, -25, 15); //139 bins for carbon, -20 to 20
      totq[i]->GetXaxis()->SetTitle("Excitation Energy (MeV)"); totq[i]->GetYaxis()->SetTitle("Counts");
    }
    total2d[i] = new TH2D(Form("total2d-%d", i), Form(" Detector %d Angle - %.1f", ID2Board.at(i), Angle[i]), 125, -20, 20, timeBin, x, y); //4096
    totalcal[i] = new TH1D(Form("tot calibrations - %d",i),"calibrations",512,0,8000);
    totalcal2[i] = new TH1D(Form("tot calibrations 2 - %d",i),"calibrations",512,0,8000);
    cal[i] = new TH1D(Form("calibrations - %d",i),"calibrations",512,0,8000);
  }
  energyplot = new TH1D("energies", "energies", 50, -25, 15);

  std::ifstream File;

  TCutG *cut[NDET];

  File.open("root_data/textfiles/lishifts.txt");

  std::map<int, std::vector<double>> data = ReadLogFile("root_data/textfiles/lishifts.txt");

  int carbonblank[12] = {264,276,278,299,302,304,257,261,262,263,322,326};

  int carbon[6] = {264,276,278,299,302,304};

  int blank[6] = {257,261,262,263,322,326};

  int lithium0[9] = {132,139,143,144,145,146,147,148,149}; //132, 139,143, 144, 145, 146
  int lithium1[10] = {150,151,152,153,154,155,156,158,159,160}; //158 156 155 154 152
  int lithium2[8] = {161,162,163,164,168,207,208}; // runs 205 and before have sloppy spectra, probably due to buncher phase changing at 169
  //218 is first run with sg used throughout experiment. Will be setting this as cutoff for valid li data.
  int lithium3[12] = {218,219,220,223,224,225,228,229,230,232}; //223 weird massive bin with 231
  int lithium4[9] = {233,240,245,246,250,251,252,253,254}; //233,240
  int lithium5[9] = {255,271,272,273,274,275,280,281,282};
  int lithium6[10] = {283,284,285,286,287,288,289,290,291,292}; //286
  int lithium7[10] = {293,294,295,296,297,298,305,308,309,310}; //14.5 hours potentially unusable
  int lithium8[16] = {311,312,313,314,315,316,317,318,319,320,257,261,262,263,322,326};

  int lithium[1] = {312}; //will be used to test individual or arbitrary number of runs

  //int allli[72] = {218,219,220,223,224,225,228,229,230,231,232,233,240,245,246,250,251,252,253,254,255,271,272,273,274,275,280,281,282,
  //283,284,285,286,287,288,289,290,291,292,293,294,295,296,297,298,305,308,309,310,311,312,313,314,315,316,317,318,319,320};
  //int allli[6] = {257,261,262,263,322,326};
  int allli[19] = {308,309,310,311,312,313,314,315,316,317,318,319,320};

  //int cali[6] = {350,352,349,339,337,348}; //first three are racks 0, 1, and 2 for 60 Co. Other three are for 137 Csf

  int cali[1] = {350};

  /* to test calibration
  rack 0 - 111, 15, 5
  rack 1 - 105, 114, 106, 107, 9, 14, 11
  rack 2 - 110, 115, 112, 100, 3, 12, 6
  */

  int lisize;
  int size;

  if (type == "calibration") {
    lisize = sizeof(cali) / sizeof(cali[0]);
    size = lisize;
  }

  if (type != "calibration" && target == "carbon") {
    lisize = sizeof(carbon) / sizeof(carbon[0]);
    size = lisize;
  }

  else if (type != "calibration" && target == "li") {
    lisize = sizeof(allli) / sizeof(allli[0]);
    size = lisize;
  }

  int run[lisize];

  if (type == "calibration") {
    for (int i = 0; i < lisize; i++) {
      run[i] = cali[i];
    }
  }

  else if (type != "calibration" && target == "carbon") {
    for (int i = 0; i < lisize; i++) {
      run[i]=carbon[i];
    }
  }

  else if (type != "calibration" && target == "li") {
    for (int i = 0; i < lisize; i++) {
      run[i]=allli[i];
    }
  }

  int yo[size];

  TH2D *PSDclone[NDET];
  TH1D *histograms[20][NDET];
  TH1D *clone[NDET];

  //int lithium0[10] = {132,   139,   143,     144,      145,     146,    147,   148,        149,           0};
  int colors[11] = {kBlack, kGreen, kBlue, kYellow, kMagenta, kOrange, kBlack, kPink, kGreenPink, kBlueYellow, kRed};

  double entries[NDET];

  double entries2[NDET];

  float norm[NDET];

  //=============================================================================================

  for (int i = 0; i < NDET; i++) {
    if (target == "carbon" ) {
        norm[i] = 0.78;}

    else if (target == "li") {
      
      if (i == 12 || i == 15) {
        norm[i] = 9.73;
      }
      else {
        norm[i] = 6.75;
      }
    }
  }

  //=============================================================================================

  float psd[NDET];

  TCanvas *canvas = new TCanvas();

  if ( (type == "add" || type == "addbig" || type == "allsmall" || type == "tDiff" || type == "tDiffg" || type == "totaltDiff"
    || type == "totalPSD" || type == "totalsubtraction" || type == "totalsubtractiong" || type == "normtest" || type == "normtestg" || 
    type == "addbackground" || type == "addq" || type == "totaltDiffg" || type == "addg" || type == "flip" || type == "excitation" || type == "individualq" || type == "totalenergy" || type == "calibration") && det == "all") {
    canvas->Divide(5,4);
  }

  double energy = 0.;
  double tdf2 = 0.;
  double mn = 939.57;
  double energyMeV;
  double beamenergy = 7.;
  double Q0 = -1.15;
  double Eex = 0.;
  double m3 = 3.0160 * 931.5;
  double m9 = 9.0133 * 931.5;
  double m14 = 14.0086 * 931.5;
  double mnsi = 1.6749e-27;

  double unifiedtshift[NDET];

  if (range != "short") {
    for (int i = 0; i<NDET; i++) {
      unifiedtshift[i] = 0;
    }
  }

  for (int i = 0; i < NDET; i++) {
    /*
  //if (target == "carbon") {
    //carbon
    if (i == 13) {
      cuts[i] = new TCutG(Form("mycut %d",i),5); 
      cuts[i]->SetVarX("eL"); // fall back to threshcut if not working
      cuts[i]->SetVarY("eTail");
      cuts[i]->SetPoint(0,720,0.185);
      cuts[i]->SetPoint(1,820,0.21);
      cuts[i]->SetPoint(2,1150,0.34);
      cuts[i]->SetPoint(3,1150,0.36);
      cuts[i]->SetPoint(4,720,0.27);
      cuts[i]->SetPoint(5,720,0.185);
    }
    else if (i == 11) {
      cuts[i] = new TCutG(Form("mycut %d",i),5); 
      cuts[i]->SetVarX("eL"); // fall back to threshcut if not working
      cuts[i]->SetVarY("eTail");
      cuts[i]->SetPoint(0,720,0.17); //650
      cuts[i]->SetPoint(1,820,0.18);
      cuts[i]->SetPoint(2,1150,0.25);
      cuts[i]->SetPoint(3,1150,0.29);
      cuts[i]->SetPoint(4,820,0.248);
      cuts[i]->SetPoint(5,720,0.24);
      cuts[i]->SetPoint(6,720,0.17);
    }
    else if (i == 10) {
      cuts[i] = new TCutG(Form("mycut %d",i),5); 
      cuts[i]->SetVarX("eL"); // fall back to threshcut if not working
      cuts[i]->SetVarY("eTail");
      cuts[i]->SetPoint(0,720,0.165);
      cuts[i]->SetPoint(1,820,0.2);
      cuts[i]->SetPoint(2,1150,0.36);
      cuts[i]->SetPoint(3,1150,0.36);
      cuts[i]->SetPoint(4,720,0.27);
      cuts[i]->SetPoint(5,720,0.165);
    }
    else if (i == 7 || i == 12 || i == 14 || i == 16) {
      cuts[i] = new TCutG(Form("mycut %d",i),5); 
      cuts[i]->SetVarX("eL"); // fall back to threshcut if not working
      cuts[i]->SetVarY("eTail");
      cuts[i]->SetPoint(0,720,0.175);
      cuts[i]->SetPoint(1,820,0.19);
      cuts[i]->SetPoint(2,1150,0.275);
      cuts[i]->SetPoint(3,1150,0.36);
      cuts[i]->SetPoint(4,720,0.27);
      cuts[i]->SetPoint(5,720,0.175);
    }
    else if (i == 0 || i == 3 || i == 4 || i == 6) {
    //else {
      cuts[i] = new TCutG(Form("mycut %d",i),5); 
      cuts[i]->SetVarX("eL"); // fall back to threshcut if not working
      cuts[i]->SetVarY("eTail");
      cuts[i]->SetPoint(0,720,0.15);
      cuts[i]->SetPoint(1,820,0.17);
      cuts[i]->SetPoint(2,1150,0.255);
      cuts[i]->SetPoint(3,1150,0.3);
      cuts[i]->SetPoint(4,720,0.24);
      cuts[i]->SetPoint(5,720,0.15);      
    }
    else if (i == 5) {
      cuts[i] = new TCutG(Form("mycut %d",i),5); 
      cuts[i]->SetVarX("eL"); // fall back to threshcut if not working
      cuts[i]->SetVarY("eTail");
      //cuts[i]->SetPoint(0,300,0.14); // 720
      cuts[i]->SetPoint(0,720,.145);
      cuts[i]->SetPoint(1,820,0.165);
      cuts[i]->SetPoint(2,1150,0.245);
      cuts[i]->SetPoint(3,1150,0.255);
      cuts[i]->SetPoint(4,820,0.212);
      cuts[i]->SetPoint(5,720,0.21);
      cuts[i]->SetPoint(6,720,0.145);    
    }
    else if (i == 8) {
      cuts[i] = new TCutG(Form("mycut %d",i),5); 
      cuts[i]->SetVarX("eL"); // fall back to threshcut if not working
      cuts[i]->SetVarY("eTail");
      cuts[i]->SetPoint(0,720,0.14);
      cuts[i]->SetPoint(1,820,0.16);
      cuts[i]->SetPoint(2,1150,0.22);
      cuts[i]->SetPoint(3,1150,0.28);
      cuts[i]->SetPoint(4,720,0.27);
      cuts[i]->SetPoint(5,720,0.14);
    }
    //else if (i == 2 || i == 15) {
    else {
      cuts[i] = new TCutG(Form("mycut %d",i),5); 
      cuts[i]->SetVarX("eL"); // fall back to threshcut if not working
      cuts[i]->SetVarY("eTail");
      cuts[i]->SetPoint(0,720,0.13);
      cuts[i]->SetPoint(1,820,0.13);
      cuts[i]->SetPoint(2,1150,0.15);
      cuts[i]->SetPoint(3,1150,0.21);
      cuts[i]->SetPoint(4,720,0.21);
      cuts[i]->SetPoint(5,720,0.13);  
    }
    */
   // }
    
    
// ===================================================================================================
//if (target == "li") {
//lithium

   if (i == 13) {
      cuts[i] = new TCutG(Form("mycut %d",i),5); 
      cuts[i]->SetVarX("eL"); // fall back to threshcut if not working
      cuts[i]->SetVarY("eTail");
      cuts[i]->SetPoint(0,720,0.21);
      cuts[i]->SetPoint(1,720,0.21);
      cuts[i]->SetPoint(2,1150,0.33);
      cuts[i]->SetPoint(3,1800,0.45);
      cuts[i]->SetPoint(4,1800,0.47);
      cuts[i]->SetPoint(5,1150,0.36);
      cuts[i]->SetPoint(6,720,0.27);
      cuts[i]->SetPoint(7,720,0.21);
    }
    else if (i == 11) {
      cuts[i] = new TCutG(Form("mycut %d",i),5); 
      cuts[i]->SetVarX("eL"); // fall back to threshcut if not working
      cuts[i]->SetVarY("eTail");
      cuts[i]->SetPoint(0,720,0.17); //650
      cuts[i]->SetPoint(1,720,0.18);
      
      cuts[i]->SetPoint(2,1150,0.25);
      cuts[i]->SetPoint(3,1800,0.38);
      cuts[i]->SetPoint(4,1800,0.45);
      cuts[i]->SetPoint(5,1150,0.32);
      
      cuts[i]->SetPoint(6,720,0.248);
      cuts[i]->SetPoint(7,720,0.24);
      cuts[i]->SetPoint(8,720,0.17);
    }
    else if (i == 10) {
      cuts[i] = new TCutG(Form("mycut %d",i),5); 
      cuts[i]->SetVarX("eL"); // fall back to threshcut if not working
      cuts[i]->SetVarY("eTail");
      cuts[i]->SetPoint(0,720,0.19);
      cuts[i]->SetPoint(1,720,0.19);
      cuts[i]->SetPoint(2,1150,0.29);
      cuts[i]->SetPoint(3,1600,0.40);
      cuts[i]->SetPoint(4,1600,0.45);
      cuts[i]->SetPoint(5,1150,0.36);
      cuts[i]->SetPoint(6,720,0.27);
      cuts[i]->SetPoint(7,720,0.19);
    }
    else if (i == 7 || i == 12 || i == 16) {
      cuts[i] = new TCutG(Form("mycut %d",i),5); 
      cuts[i]->SetVarX("eL"); // fall back to threshcut if not working
      cuts[i]->SetVarY("eTail");
      cuts[i]->SetPoint(0,720,0.19);
      cuts[i]->SetPoint(1,720,0.19);
      
      cuts[i]->SetPoint(2,1150,0.275);
      cuts[i]->SetPoint(3,1800,0.37);
      cuts[i]->SetPoint(4,2050,0.38);
      cuts[i]->SetPoint(5,2050,0.44);
      cuts[i]->SetPoint(6,1800,0.41);
      cuts[i]->SetPoint(7,1150,0.36);
      
      cuts[i]->SetPoint(8,720,0.27);
      cuts[i]->SetPoint(9,720,0.19);
    }
    else if (i == 14) {
      cuts[i] = new TCutG(Form("mycut %d",i),5); 
      cuts[i]->SetVarX("eL"); // fall back to threshcut if not working
      cuts[i]->SetVarY("eTail");
      cuts[i]->SetPoint(0,720,0.19);
      cuts[i]->SetPoint(1,720,0.19);
      
      cuts[i]->SetPoint(2,1150,0.295);
      cuts[i]->SetPoint(3,1800,0.57);
      cuts[i]->SetPoint(4,2050,0.57);
      cuts[i]->SetPoint(5,2050,0.57);
      cuts[i]->SetPoint(6,1800,0.557);
      cuts[i]->SetPoint(7,1150,0.36);
      
      cuts[i]->SetPoint(8,720,0.27);
      cuts[i]->SetPoint(9,720,0.19);
    }
    else if (i == 4) {
    //else {
      cuts[i] = new TCutG(Form("mycut %d",i),5); 
      cuts[i]->SetVarX("eL"); // fall back to threshcut if not working
      cuts[i]->SetVarY("eTail");
      cuts[i]->SetPoint(0,720,0.149);
      cuts[i]->SetPoint(1,720,0.149);
      
      cuts[i]->SetPoint(2,1150,0.24);
      cuts[i]->SetPoint(3,1600,0.36);
      cuts[i]->SetPoint(4,1600,0.4);
      cuts[i]->SetPoint(5,1150,0.3);
      cuts[i]->SetPoint(6,820,0.22);
      
      cuts[i]->SetPoint(7,720,0.22);
      cuts[i]->SetPoint(8,720,0.149);      
    }    
    else if (i == 0) {
    //else {
      cuts[i] = new TCutG(Form("mycut %d",i),5); 
      cuts[i]->SetVarX("eL"); // fall back to threshcut if not working
      cuts[i]->SetVarY("eTail");
      cuts[i]->SetPoint(0,720,0.146);
      cuts[i]->SetPoint(1,720,0.146);
      
      cuts[i]->SetPoint(2,1150,0.26);
      cuts[i]->SetPoint(3,1600,0.42);
      cuts[i]->SetPoint(4,1600,0.46);
      cuts[i]->SetPoint(5,1150,0.3);
      cuts[i]->SetPoint(6,720,0.22);
      
      cuts[i]->SetPoint(7,720,0.22);
      cuts[i]->SetPoint(8,720,0.146);      
    }
    else if (i == 6) {
      cuts[i] = new TCutG(Form("mycut %d",i),5); 
      cuts[i]->SetVarX("eL"); // fall back to threshcut if not working
      cuts[i]->SetVarY("eTail");
      cuts[i]->SetPoint(0,720,0.164);
      cuts[i]->SetPoint(1,820,0.164);
      
      cuts[i]->SetPoint(2,1150,0.23);
      cuts[i]->SetPoint(3,1600,0.33);
      cuts[i]->SetPoint(4,1800,0.38);
      cuts[i]->SetPoint(5,1800,0.4);
      cuts[i]->SetPoint(6,1150,0.3);
      cuts[i]->SetPoint(7,820,0.22);
      
      cuts[i]->SetPoint(8,720,0.22);
      cuts[i]->SetPoint(9,720,0.164);  
    }
    else if (i == 3) {
      cuts[i] = new TCutG(Form("mycut %d",i),5); 
      cuts[i]->SetVarX("eL"); // fall back to threshcut if not working
      cuts[i]->SetVarY("eTail");
      //cuts[i]->SetPoint(0,700,0.11);
      cuts[i]->SetPoint(0,720,0.162);
      
      cuts[i]->SetPoint(1,1150,0.24);
      cuts[i]->SetPoint(2,1800,0.39);
      cuts[i]->SetPoint(3,1800,0.4);
      cuts[i]->SetPoint(4,1150,0.3);
      cuts[i]->SetPoint(5,720,0.22);
      cuts[i]->SetPoint(6,720,0.162);
      
      //cuts[i]->SetPoint(6,700,0.22);
      //cuts[i]->SetPoint(7,700,0.11);   
    }
    else if (i == 5) {
      cuts[i] = new TCutG(Form("mycut %d",i),5); 
      cuts[i]->SetVarX("eL"); // fall back to threshcut if not working
      cuts[i]->SetVarY("eTail");
      //cuts[i]->SetPoint(0,300,0.14); // 650
      cuts[i]->SetPoint(0,720,.15);
      cuts[i]->SetPoint(1,820,0.15);
      
      cuts[i]->SetPoint(2,1150,0.22);
      cuts[i]->SetPoint(3,1800,0.38);
      cuts[i]->SetPoint(4,1800,0.4);
      cuts[i]->SetPoint(5,1150,0.28);
      
      cuts[i]->SetPoint(6,820,0.212);
      cuts[i]->SetPoint(7,720,0.2);
      cuts[i]->SetPoint(8,720,0.15);    
    }
    else if (i == 8) {
      cuts[i] = new TCutG(Form("mycut %d",i),5); 
      cuts[i]->SetVarX("eL"); // fall back to threshcut if not working
      cuts[i]->SetVarY("eTail");
      cuts[i]->SetPoint(0,720,0.16);
      cuts[i]->SetPoint(1,720,0.16);
      
      cuts[i]->SetPoint(2,1150,0.22);
      cuts[i]->SetPoint(3,1800,0.315);
      cuts[i]->SetPoint(4,2100,0.35);
      cuts[i]->SetPoint(5,2500,0.4);
      cuts[i]->SetPoint(6,2500,0.47);
      cuts[i]->SetPoint(7,2100,0.42);
      cuts[i]->SetPoint(8,1800,0.38);
      cuts[i]->SetPoint(9,1150,0.3);
      
      cuts[i]->SetPoint(10,720,0.27);
      cuts[i]->SetPoint(11,720,0.16);
    }
    else if (i == 2) {
    //else {
      cuts[i] = new TCutG(Form("mycut %d",i),5); 
      cuts[i]->SetVarX("eL"); // fall back to threshcut if not working
      cuts[i]->SetVarY("eTail");
      cuts[i]->SetPoint(0,720,0.11);
      cuts[i]->SetPoint(1,820,0.115);
      
      cuts[i]->SetPoint(2,1150,0.14);
      cuts[i]->SetPoint(3,1690,0.18);
      cuts[i]->SetPoint(4,2200,0.26);
      cuts[i]->SetPoint(5,2200,0.31);
      cuts[i]->SetPoint(6,1700,0.24);
      cuts[i]->SetPoint(7,1150,0.21);
      
      cuts[i]->SetPoint(8,720,0.23);
      cuts[i]->SetPoint(9,720,0.11);  
    }
    else if (i == 15) {
      cuts[i] = new TCutG(Form("mycut %d",i),5); 
      cuts[i]->SetVarX("eL"); // fall back to threshcut if not working
      cuts[i]->SetVarY("eTail");
      cuts[i]->SetPoint(0,720,0.14);
      cuts[i]->SetPoint(1,820,0.14);
      
      cuts[i]->SetPoint(2,1150,0.15);
      cuts[i]->SetPoint(3,1690,0.22);
      cuts[i]->SetPoint(4,2200,0.29);
      cuts[i]->SetPoint(5,2400,0.36);
      cuts[i]->SetPoint(6,2400,0.4);
      cuts[i]->SetPoint(7,2200,0.35);
      cuts[i]->SetPoint(8,1700,0.27);
      cuts[i]->SetPoint(9,1150,0.22);
      
      cuts[i]->SetPoint(10,720,0.23);
      cuts[i]->SetPoint(11,720,0.14);  
    }
    else {
      cuts[i] = new TCutG(Form("mycut %d",i),5); 
      cuts[i]->SetVarX("eL"); // fall back to threshcut if not working
      cuts[i]->SetVarY("eTail");
      cuts[i]->SetPoint(0,720,0.11);
      cuts[i]->SetPoint(1,820,0.115);
      
      cuts[i]->SetPoint(2,1150,0.14);
      cuts[i]->SetPoint(3,1690,0.21);
      cuts[i]->SetPoint(4,2200,0.29);
      cuts[i]->SetPoint(5,2700,0.36);
      cuts[i]->SetPoint(6,2700,0.4);
      cuts[i]->SetPoint(7,2200,0.35);
      cuts[i]->SetPoint(8,1700,0.27);
      cuts[i]->SetPoint(9,1150,0.21);
      
      cuts[i]->SetPoint(10,720,0.23);
      cuts[i]->SetPoint(11,720,0.11);  
    }
    
   //}
    //=========================================
  }
  
    //=============================================================================================
    //=============================================================================================
    //=============================================================================================

    float hailmary[NDET]; float hailmary2[NDET];
    
    int k; int jo; int channel; int board;

    if (det != "all") {
        k = det.Atoi();
        jo = Channel2ID.at(k);
        channel = Det2Channel.at(jo);
        board = Det2Board.at(jo);
    }

    for (int current_run = 0; current_run < size; current_run++) {

        std::cout << run[current_run] << std::endl;
  
        if (run[current_run] == 0) {
          continue;
        }
  
        else {
          for (int i = 0; i<NDET; i++) {
            //PSD[i] = new TH2D(Form("PSD-%d", i), Form(" Detector %d", ID2Board.at(i)), 2000, 0, 3500, 512, -0.1, 0.8);
            tDiff[i] = new TH1D(Form("Tdiff-%d", i), Form(" Detector %d", ID2Board.at(i)), timeBin, x, y); // -100, 400
            tDiffg[i] = new TH1D(Form("Tdiffg1-%d", i), Form(" Detector %d", ID2Board.at(i)), timeBin, x, y);
            tDiffg1[i] = new TH1D(Form("Tdiffg2-%d", i), Form(" Detector %d", ID2Board.at(i)), timeBin, x, y);
            tDiffg2[i] = new TH1D(Form("Tdiffg3-%d", i), Form(" Detector %d", ID2Board.at(i)), timeBin, x, y);
            tDiffg3[i] = new TH1D(Form("Tdiffg4-%d", i), Form(" Detector %d", ID2Board.at(i)), timeBin, x, y);
            tDiffg4[i] = new TH1D(Form("Tdiffg5-%d", i), Form(" Detector %d", ID2Board.at(i)), timeBin, x, y);
            tDiffg5[i] = new TH1D(Form("Tdiffg6-%d", i), Form(" Detector %d", ID2Board.at(i)), timeBin, x, y);
          }
      
          int run_start = run[current_run];

          double blankshift[NDET] = {50,0,-44,54,16,52,14,38,0,0,0,18,48,0,0,36,42};

          double carbonshift[NDET] = {2,-2,-38,2,-38,2,-36,2,-36,0,-36,-36,2,-36,-38,2,2};

          double yup[NDET] = {442, 0, 418, 438, 440, 442, 443, 456, 454, 0, 454, 438, 445, 456, 456, 416, 452};

          double yup1[NDET] = {442, 0, 418, 438, 440, 444, 443, 453, 451, 0, 454, 434, 445, 456, 456, 416, 452};

          double gamshift[NDET] = {6.6, 6.6, 6.6, 6.6, 6.6, 6.6, 6.6, 6.6, 6.6, 6.6, 6.6, 6.6, 3.3, 6.6, 6.6, 3.3, 6.6};
      
          double shifts[NDET];

          double w = ( run_start == 257 || run_start == 261 || run_start == 262 || run_start == 263 || run_start == 322 || run_start == 326 ) ? -0.61 : 1.0;

          if (type == "flip") {
            for (int i = 0; i<NDET; i++) {
              unifiedtshift[i] = {0};
            }
          }

          else {
            if (run_start > 231) {
              for (int i = 0; i < NDET; i++) {
                unifiedtshift[i] = yup[i];
              }
            }
            else if (run_start < 231) {
              for (int i = 0; i < NDET; i++) {
                unifiedtshift[i] = yup1[i];  //due to changes in settings, position of gamma peaks on tof spectrum changes
              }
            }
          }

          if (run_start == 257 || run_start == 261 || run_start == 262 || run_start == 263 || run_start == 322 || run_start == 326) {
            for (int i = 0; i < NDET; i++) {
              shifts[i] = data[run[current_run]][i] + blankshift[i]; //data aligns all blank runs and blankshift aligns blank runs to li
            }
          }

          else if (run_start == 336 || run_start == 352 || run_start == 349 || run_start == 339 || run_start == 337 || run_start == 348 || run_start == 350) {
            for (int i = 0; i< NDET; i++) {
              shifts[i] = 0;
            }
          }
      
          else if (run_start == 264 || run_start == 276 || run_start == 278 || run_start == 299 || run_start == 302 || run_start == 304) {
            for(int i = 0; i < 17; i++) {
              shifts[i] = data[run[current_run]][i] + carbonshift[i];             
            }
          }

          else if (run_start == 215 || run_start == 301  || run_start == 124 || run_start == 266 || run_start == 267 || run_start == 268 || run_start == 300) {
            for (int i = 0; i < NDET; i++) {
              shifts[i] = 0;
            }
          }
          
          else {
            for (int i = 0; i < NDET; i++) {
              shifts[i] = data[run[current_run]][i];
            }
          }
          
          TString fileName;
      
          fileName.Form("root_data/datafiles/catrina_%d_3000.root", run[current_run]);
      
          TFile *filename = new TFile(fileName);
      
          TTree *tree = (TTree *)filename->Get("tree");
      
          std::cout << "Pulling data from TTree..." << std::endl;
      
          TTreeReader reader(tree);
      
          TTreeReaderValue<ULong64_t>  evID = {reader, "evID"};
          TTreeReaderValue<UInt_t>    multi = {reader, "multi"};
          TTreeReaderArray<UShort_t>     sn = {reader, "sn"}; // serial no.
          TTreeReaderArray<UShort_t>     ch = {reader, "ch"}; // channel
          TTreeReaderArray<UShort_t>      e = {reader, "e"};  //long
          TTreeReaderArray<UShort_t>     e2 = {reader, "e2"}; //short
          TTreeReaderArray<ULong64_t>   e_t = {reader, "e_t"}; // in ns
          TTreeReaderArray<UShort_t>    e_f = {reader, "e_f"}; // in ps
      
          ULong64_t NumEntries = tree->GetEntries();
      
          std::cout << "Filling histograms..." << std::endl;
      
          std::ifstream file;
      
          file.open("root_data/textfiles/calibration.txt");
          float numbers[51];
      
          int count = 0;
      
          float temp;
          char comma;
      
          while (file >> temp) {
          if (count < 51) {
            numbers[count++] = temp;
           }
           file >> comma;
          }
        
          file.close();
        
          float a[NDET] = {};
          float b[NDET] = {};
        
          for (int i = 0; i<NDET; i++) {
            int j = 3*i + 1;
            a[i] = numbers[j];
          }
        
          for (int i = 0; i<NDET; i++) {
            int k = 3*i + 2;
            b[i] = numbers[k];
          }
  
          while(reader.Next()) {
        
            double Q = 0;
            int count = 0;
            unsigned long long tRF = 0;
            unsigned long long tN[NDET];
            unsigned long long ts[NDET];
            for( int i = 0; i < NDET; i++ ) {
              tN[i] = 0;
              eL[i] = 0;
              eS[i] = 0;
              ts[i] = 0;
            }
        
            for(int i = 0; i < *multi; i++) { 
              if (run_start < 194) {
                int bd = SN2Bd2.at(sn[i]);
                int haha = mapping2[bd][ch[i]];
                if( haha < 0 ) continue;
                int ID = Index2ID.at(haha);
        
                if(ID == 200) {
                  count ++;
                  if (e_f[i] > 20000) {
                    continue;
                  }
                  else {
                    tRF = e_t[i] * 1000 + e_f[i];
                  }
                }
        
                if( ID < 0 || ID > NDET ) continue;
        
                eL[ID] = e[i];
                eS[ID] = e2[i];
                

                if (e_f[i] > 20000) {
                  continue;
                }
                else {
                  tN[ID] = e_t[i] * 1000 + e_f[i];
                }
        
              }
              else if (run_start >= 194) {
                int bd = SN2Bd.at(sn[i]);
                int haha = mapping[bd][ch[i]];
                if( haha < 0 ) continue;
                int ID = Index2ID.at(haha);
        
                if( ID == 200)
                {
                  count ++;
                  if (e_f[i] > 20000) {
                    tRF = e_t[i] * 1000; //in ps
                  }
                  else {
                    tRF = e_t[i] * 1000 + e_f[i];
                  }
                }
        
                if( ID < 0 || ID > NDET ) continue;
                
                eL[ID] = e[i];
                eS[ID] = e2[i];
        
                if (e_f[i] > 20000) {
                  tN[ID] = e_t[i] * 1000;
                }
                else {
                  tN[ID] = e_t[i] * 1000 + e_f[i];
                }
              }             
            } // end multiplicity for loop
      
            for(int i = 0; i < NDET; i++) {
              if (i == 1 || i == 9) {
                continue;
              }
              else {
              if( tRF != 0 && tN[i] > 0 ) {
                double tdf = 0.;
                
                if (range == "short") {
                if (run_start >= 231) {
                  if (i == 2) {
                    if(tRF > tN[i]) {
                      if (compress == "compress") {
                        tdf = -((tRF - tN[i])*1./1000. + shifts[i]) + unifiedtshift[i] + gamshift[i];
                        
                        if (tdf < 0.) {
                          tdf = tdf + 165.;
                        }
                        
                        if (tdf > 82.5) {
                          tdf = tdf - 82.5;
                        }
                        
                        
                      }
                      else {
                        tdf = -(((tRF - tN[i])*1./1000.) + shifts[i]) + unifiedtshift[i] + gamshift[i]; // 476 or litargetshift[i]
                      }
                    }
                    else {       
                      if (compress == "compress") {
                        tdf = -(((tN[i] - tRF)*1./1000. ) + shifts[i]) + unifiedtshift[i] + gamshift[i];
                        if (tdf < 0.) {
                          tdf = tdf + 165.;
                        }
                        
                        if (tdf > 82.5) {
                          tdf = tdf - 82.5;
                        }
                        
                      }
                      else {
                        tdf = -(((tN[i] - tRF)*1./1000. ) + shifts[i])+ unifiedtshift[i] + gamshift[i]; // 476
                      }
                    }
                  }
  
                  //================================================================================================================
                  else {
                    if(tRF > tN[i]) {
                      if (compress == "compress") {
                        tdf = -(((tRF - tN[i])*1./1000.) + shifts[i]) + unifiedtshift[i] + gamshift[i]; //558 for carbon include litargetshift
                        
                        if (tdf < 0.) {
                          tdf = tdf + 165.;
                        }                  
                        
                        if (tdf > 82.5) {
                          tdf = tdf - 82.5;
                        }
                        
                        
                      }
                      else {
                         tdf = -( (tRF - tN[i])*1./1000.+ shifts[i]) + unifiedtshift[i] + gamshift[i]; // 558
                      }
                    }
                    else {
  
                      if (compress == "compress") {
                        tdf = -((tN[i] - tRF)*1./1000. + shifts[i]) + unifiedtshift[i] + gamshift[i];
                        if (tdf < 0.) {
                          tdf = tdf + 165.;
                        }
                        
                        if (tdf > 82.5) {
                          tdf = tdf - 82.5;
                        }
                        
                        
                      }
                      else {
                        tdf = -( (tN[i] - tRF)*1./1000. + shifts[i]) + unifiedtshift[i] + gamshift[i]; //558
                      }
                    }
                  }
                } else if (run_start < 231) {
                  if (tN[i] < tRF) {
                    if (compress == "compress") {
                      tdf = -(((tRF - tN[i])*1./1000.) + shifts[i]) + unifiedtshift[i] + gamshift[i];   
                        if (tdf < 0.) {
                          tdf = tdf + 165.;
                        }                  
                        
                        if (tdf > 82.5) {
                          tdf = tdf - 82.5;
                        }
                      }
                      else {
                         tdf = -( (tRF - tN[i])*1./1000.+ shifts[i]) + unifiedtshift[i] + gamshift[i]; // 558
                      }
                  } else {
                    if (compress == "compress") {
                      tdf = -((tN[i] - tRF)*1./1000. + shifts[i]) + unifiedtshift[i] + gamshift[i];
                      if (tdf < 0.) {
                        tdf = tdf + 165.;
                      }
                      
                      if (tdf > 82.5) {
                        tdf = tdf - 82.5;
                      }                 
                    }
                    else {
                      tdf = -( (tN[i] - tRF)*1./1000. + shifts[i]) + unifiedtshift[i] + gamshift[i]; //558
                    }
                  }
                }
                //==========================================================================================================================
              }

                if (range == "out") {
                  if(tRF > tN[i]) {
                    tdf = (tRF - tN[i])*1./1000. + shifts[i];
                  }
                  else {
                    tdf = (tN[i] - tRF)*1./1000. + shifts[i];
                  }
                }

                if (det == "all") {
                  PSD[i]->Fill( eL[i] , (eL[i]-eS[i])*1.0/eL[i] );
  
                if (calibration == "yes") {

                  if (compress == "selective") {
                    if (tdf < 0 || tdf > 82.5) {
                      continue;
                    }
                  }
                  
                    PSDc[i]->Fill( ((a[i]*eL[i]) + b[i]), ((eL[i]-eS[i])*1.0/eL[i]) );
                    tDiff[i]->Fill(tdf);
                    cal[i]->Fill((a[i]*eL[i])+b[i]);

                  if(thesiscut[i]->IsInside(((a[i]*eL[i]) + b[i]), ((eL[i]-eS[i])*1.0/eL[i]))) {
                    if (!std::isfinite(tdf)) continue;
                    tDiffg[i]->Fill(tdf);
                    if (tdf < 0 || tdf > 82.5) continue;
                    tdf2 = tdf * 1.e-9;
                    energyMeV = 6.241509e12 * ( (0.5) * mnsi * ((distance[i] * distance[i]) / (tdf2 * tdf2)) );
                    if (target == "carbon") {
                      Q = energyMeV - beamenergy + ( (1/m14) * ( (m3 * beamenergy) + (mn * energyMeV) - (2 * sqrt(m3*mn*beamenergy*energyMeV) * cos((3.14159 * Angle[i])/ 180.)) )); 
                      Q = -1.15 - Q;
                    } else if (target == "li") {
                      Q = energyMeV - beamenergy + ( (1/m9) * ( (m3 * beamenergy) + (mn * energyMeV) - (2 * sqrt(m3*mn*beamenergy*energyMeV) * cos( (3.14159 * Angle[i])/ 180. )) )); 
                      Q = 9.35 - Q;
                    }
                    if (Q   < -20   || Q   > 20)   continue;
                    if (!std::isfinite(energyMeV)) continue;
                    if (!std::isfinite(Q)) continue;
                    if (i == 1 || i == 9) {
                      continue;
                    } else {
                      qvalues[i]->Fill( Q );
                      nenergy[i]->Fill( energyMeV );
                      //qvalues[i]->Fill(Q, w);
                      //lovstof[i]->Fill( Q , tdf );
                    }
                  }

                  if (det != "all") {
                  if (threshcuts1[i]->IsInside(((a[i]*eL[i]) + b[i]), ((eL[i]-eS[i])*1.0/eL[i]))) {
                    tDiffg1[i]->Fill(tdf);
                  }
                  if (threshcuts2[i]->IsInside(((a[i]*eL[i]) + b[i]), ((eL[i]-eS[i])*1.0/eL[i]))) {
                    tDiffg2[i]->Fill(tdf);
                  }
                  if (threshcuts3[i]->IsInside(((a[i]*eL[i]) + b[i]), ((eL[i]-eS[i])*1.0/eL[i]))) {
                    tDiffg3[i]->Fill(tdf);
                  }
                  if (threshcuts4[i]->IsInside(((a[i]*eL[i]) + b[i]), ((eL[i]-eS[i])*1.0/eL[i]))) {
                    tDiffg4[i]->Fill(tdf);
                  }
                  if (threshcuts5[i]->IsInside(((a[i]*eL[i]) + b[i]), ((eL[i]-eS[i])*1.0/eL[i]))) {
                    tDiffg5[i]->Fill(tdf);
                  }
                }
              }
                }

                else if (det != "all") {
  
                   PSD[jo]->Fill( eL[jo] , (eL[jo]-eS[jo])*1.0/eL[jo] );
  
                 if (calibration == "yes") {

                  if (compress == "selective") {
                    if (tdf < 0 || tdf > 82.5) {
                      continue;
                    }
                  }
                  if (i != jo) {
                    continue;
                  }
                  
                    //PSD[i]->Fill( eL[i] , (eL[i]-eS[i])*1.0/eL[i] );
                    PSDc[jo]->Fill( ((a[jo]*eL[jo]) + b[jo]), ((eL[jo]-eS[jo])*1.0/eL[jo]) );
                    tDiff[jo]->Fill(tdf);
                    cal[jo]->Fill((a[jo]*eL[jo])+b[jo]);
                  
                  if(cuts[jo]->IsInside(((a[jo]*eL[jo]) + b[jo]), ((eL[jo]-eS[jo])*1.0/eL[jo]))) {
                    if (!std::isfinite(tdf)) continue;
                    tDiffg[jo]->Fill(tdf);
                    if (tdf < 0 || tdf > 82.5) continue;
                    tdf2 = tdf * 1.e-9;
                    energyMeV = 6.241509e12 * ( (0.5) * mnsi * ((distance[jo] * distance[jo]) / (tdf2 * tdf2)) );
                    if (target == "carbon") {
                      Q = energyMeV - beamenergy + ( (1/m14) * ( (m3 * beamenergy) + (mn * energyMeV) - (2 * sqrt(m3*mn*beamenergy*energyMeV) * cos((3.14159 * Angle[jo])/ 180.)) )); 
                      Q = -1.15 - Q;
                    } else if (target == "li") {
                      Q = energyMeV - beamenergy + ( (1/m9) * ( (m3 * beamenergy) + (mn * energyMeV) - (2 * sqrt(m3*mn*beamenergy*energyMeV) * cos( (3.14159 * Angle[jo])/ 180. )) )); 
                      Q = 9.35 - Q;
                    }
        
                    if (Q   < -20   || Q   > 20)   continue;
                    if (!std::isfinite(energyMeV)) continue;
                    if (!std::isfinite(Q)) continue;
                    if (i == 1 || i == 9) {
                      continue;
                    } else {
                      qvalues[jo]->Fill( Q );
                      nenergy[jo]->Fill( energyMeV );
                    }
                  }
                 }
                }
              }
            }
            }
          } //while reader end

          std::cout << "Plotting..." << std::endl;

        if (type == "energy" || type == "totalenergy" || type == "individualq") {
          if (det == "all") {
          for (int i = 0; i < NDET; i++) {
            if (run_start == 257 || run_start == 261 || run_start == 262 || run_start == 263 || run_start == 322 || run_start == 326) {
              totq[i]->Add(qvalues[i],-norm[i]);
            }
            else {
              totq[i]->Add(qvalues[i],1.0);
            }
          }
          }
          else if (det != "all") {
            if (run_start == 257 || run_start == 261 || run_start == 262 || run_start == 263 || run_start == 322 || run_start == 326) {
              hailmary2[jo] = hailmary2[jo] + 0.61 * (tDiffg[jo]->GetEffectiveEntries());
              totq[jo]->Add(qvalues[jo],-norm[jo]);
            }
            else {
              hailmary2[jo] = hailmary2[jo] + tDiffg[jo]->GetEffectiveEntries();
              totq[jo]->Add(qvalues[jo],1.0);
            }
          }
        }
        if (type == "nenergy") {
          if (det == "all") {
          for (int i = 0; i < NDET; i++) {
            if (run_start == 257 || run_start == 261 || run_start == 262 || run_start == 263 || run_start == 322 || run_start == 326) {
              totnenergy[i]->Add(nenergy[i],-norm[i]);
            }
            else {
              totnenergy[i]->Add(nenergy[i],1);
            }
          }
          }
          else if (det != "all") {
            if (run_start == 257 || run_start == 261 || run_start == 262 || run_start == 263 || run_start == 322 || run_start == 326) {
              totnenergy[jo]->Add(nenergy[jo],-norm[jo]);
            }
            else {
              totnenergy[jo]->Add(nenergy[jo],1);
            }
          }
        }
        if (type == "calibration") {
            /* to test calibration
            rack 0 - 111, 15, 5
            rack 1 - 105, 114, 106, 107, 9, 14, 11
            rack 2 - 110, 115, 112, 100, 3, 12, 6
            */
          if (det == "all") {
          //{350,352,349,339,337,348}
          for (int i = 0; i<NDET; i++) {
            /*
            if (run_start == 350 || run_start == 352 || run_start == 349) {
              totalcal2[0]->Add(cal[0]); 
              totalcal2[1]->Add(cal[1]); 
              totalcal2[2]->Add(cal[2]); 
            }
            else if (run_start == 352) {
              totalcal2[3]->Add(cal[3]); totalcal2[4]->Add(cal[4]); totalcal2[5]->Add(cal[5]); totalcal2[6]->Add(cal[6]); totalcal2[7]->Add(cal[7]); totalcal2[8]->Add(cal[8]); totalcal2[9]->Add(cal[9]);       
            }
            else if (run_start == 349) {
              totalcal2[10]->Add(cal[10]); totalcal2[11]->Add(cal[11]); totalcal2[12]->Add(cal[12]); totalcal2[13]->Add(cal[13]); totalcal2[14]->Add(cal[14]); totalcal2[15]->Add(cal[15]);
            }
            else if (run_start == 339) {
              totalcal2[0]->Add(cal[0]); 
              totalcal2[1]->Add(cal[1]); 
              totalcal2[2]->Add(cal[2]); 
            }
            else if (run_start == 337) {
              totalcal2[3]->Add(cal[3]); totalcal2[4]->Add(cal[4]); totalcal2[5]->Add(cal[5]); totalcal2[6]->Add(cal[6]); totalcal2[7]->Add(cal[7]); totalcal2[8]->Add(cal[8]); totalcal2[9]->Add(cal[9]);
            }
            else if (run_start == 348) {
              totalcal2[10]->Add(cal[10]); totalcal2[11]->Add(cal[11]); totalcal2[12]->Add(cal[12]); totalcal2[13]->Add(cal[13]); totalcal2[14]->Add(cal[14]); totalcal2[15]->Add(cal[15]);
            }
            */
           if (run_start == 350 || run_start == 352 || run_start == 349) {
           totalcal2[i]->Add(cal[i]); }
            else if (run_start == 339 || run_start == 337 || run_start == 348) {
              totalcal[i]->Add(cal[i]); } } }
          else if (det != "all") {
            if (run_start == 350 || run_start == 352 || run_start == 349) {
            totalcal2[jo]->Add(cal[jo]); }
            else if (run_start == 339 || run_start == 337 || run_start == 348) {
            totalcal[jo]->Add(cal[jo]); }
          }
        }
        if (type == "lovstof") {
          for (int i = 0; i<NDET; i++) {
            total2d[i]->Add(lovstof[i],1.0);
          }
        }
        else if (type == "add") {
          for (int i = 0; i<NDET; i++) {
            canvas->cd(i+1);
            histograms[current_run][i] = (TH1D *)tDiff[Det2AngleOrder.at(i)]->Clone(Form("histnew - %d", i));
            histograms[current_run][i]->SetLineColor(colors[current_run]);
            histograms[current_run][i]->Draw("same");
          }
        }
        else if (type == "totalsubtractiong") {//for (int i = 0; i<NDET; i++) {total[i]=totaltof(NDET, run[current_run], tDiff[NDET], total[NDET], isbackground)};}
          for (int i = 0; i<NDET; i++) {
            if (run_start == 257 || run_start == 261 || run_start == 262 || run_start == 263 || run_start == 322 || run_start == 326) {
              total[i]->Add(tDiffg[i],-norm[i]);
            }
            else {
              total[i]->Add(tDiffg[i],1);
            }
          }
        }
        if (type == "normtest") {
          for (int i = 0; i < NDET; i++) {
            if (run_start == 257 || run_start == 261 || run_start == 262 || run_start == 263 || run_start == 322 || run_start == 326) {
              total4[i]->Add(tDiff[i],norm[i]);
            }
            else {
              total3[i]->Add(tDiff[i]);
            }
          }
        }
        if (type == "normtestg" || type == "testplot") {
          for (int i = 0; i < NDET; i++) {
            if (run_start == 257 || run_start == 261 || run_start == 262 || run_start == 263 || run_start == 322 || run_start == 326) {
              total4[i]->Add(tDiffg[i],norm[i]);
            }
            else {
              total3[i]->Add(tDiffg[i]);
            }
          }
        }

        if(type == "totaltDiff") {
          if (det == "all") {
          for(int i = 0; i<NDET; i++) {
            if (run_start == 257 || run_start == 261 || run_start == 262 || run_start == 263 || run_start == 322 || run_start == 326) {
              total[i]->Add(tDiff[i],norm[i]);
            } else {
              total[i]->Add(tDiff[i]);
            }
          }
          } 
          else if (det != "all") {
            if (run_start == 257 || run_start == 261 || run_start == 262 || run_start == 263 || run_start == 322 || run_start == 326) {
              total[jo]->Add(tDiff[jo],norm[jo]);
            } else {
              total[jo]->Add(tDiff[jo]);
            }
          }
        }
        if(type == "totaltDiffg") {
          if (det == "all") {
          for(int i = 0; i<NDET; i++) {
            if (run_start == 257 || run_start == 261 || run_start == 262 || run_start == 263 || run_start == 322 || run_start == 326) {
              total[i]->Add(tDiffg[i],-norm[i]);
            } else {
              total[i]->Add(tDiffg[i]);
            }
          }
          } 
          else if (det != "all") {
            if (run_start == 257 || run_start == 261 || run_start == 262 || run_start == 263 || run_start == 322 || run_start == 326) {
              total[jo]->Add(tDiffg[jo],-norm[jo]);
              total1[jo]->Add(tDiffg1[jo],-norm[jo]);
              total2[jo]->Add(tDiffg2[jo],-norm[jo]);
              total3[jo]->Add(tDiffg3[jo],-norm[jo]);
              total4[jo]->Add(tDiffg4[jo],-norm[jo]);
              total5[jo]->Add(tDiffg5[jo],-norm[jo]);
            } else {
              total[jo]->Add(tDiffg[jo]);
              total1[jo]->Add(tDiffg1[jo]);
              total2[jo]->Add(tDiffg2[jo]);
              total3[jo]->Add(tDiffg3[jo]);
              total4[jo]->Add(tDiffg4[jo]);
              total5[jo]->Add(tDiffg5[jo]);
            }
          }
        }

        if (calibration == "yes") {
          if (type == "totalPSD") {
            for (int i = 0; i < NDET; i++) {
              totalPSDc[i]->Add(PSDc[i]);
            }
          }
        }

        else if (calibration == "no") {
          if (type == "totalPSD") {
            for (int i = 0; i<NDET; i++) {
              totalPSD[i]->Add(PSD[i]);
            }
          }
        }

        for(int i = 0; i < NDET; i++) {
          //delete tDiff[i];
          tDiff[i]->Reset();
          tDiffg[i]->Reset();
          tDiffg1[i]->Reset();
          tDiffg2[i]->Reset();
          tDiffg3[i]->Reset();
          tDiffg4[i]->Reset();
          tDiffg5[i]->Reset();
          //delete tDiffg[i];
          PSD[i]->Reset();
          PSDc[i]->Reset();
          //delete qvalues[i];
          qvalues[i]->Reset();
          //delete nenergy[i];
          nenergy[i]->Reset();
          cal[i]->Reset();
          //ex[i]->Reset();
          //tofvq[i]->Reset();
          //envslong[i]->Reset();
      }
    }
    } 

  std::cout << "end for loop" << std::endl;
  
  //=============================================================================================
  //=============================================================================================
  //=============================================================================================
  
  std::string path;
  //const char *end = "fits/";
  //gSystem->mkdir(end, kTRUE);

    if (type == "individualq") {
      if (det == "all") {
      //path = "canvases/excitation_plots_high_threshold";
      //TCanvas *temp = new TCanvas();
      //gSystem->mkdir(path.c_str(), kTRUE);
      //gSystem->cd(path.c_str());
      for (int i = 0; i<NDET; i++) {
        canvas->cd(i+1);
        //temp->cd();
        //totq[Det2AngleOrder.at(i)]->Draw();
        totq[i]->Draw();
        //temp->SaveAs(Form("Excitation %f.root", Angle[Det2AngleOrder.at(i)]));
      }
      
      //if (target =="li") {
        //path = "canvases/q-value_plots";
      //}
      //else if (target == "carbon") {
        //path = "canvases/gaussianoverlapscarbon";
      //}
      /*
        TCanvas *canvas = new TCanvas();
        gSystem->mkdir(path.c_str(), kTRUE);
        gSystem->cd(path.c_str());
        
        //canvas->Divide(5,4);
        //float a[NDET] = {0,0,2,8,.5,4,1,8,1,4,4,2,.5,4,1,0,0};
        float ambbamp = 400;
        float bmbbamp = 400;
        float cmbbamp = 400;
  
        float a[NDET] = {2000, 12000, 80, 290, 35, 100, 70,200, 25,200,200, 95,32, 150, 35,0,0}; //gs amp 20000
        float c[NDET] = {2500, 14000,120, 320, 35, 240, 80,240, 25,150,170,110,20,  90, 25,0,0}; //2.345 amp 25000
        float d[NDET] = {2500, 14500,120, 320, 40, 200, 80,220,100,200,200,140,25, 300, 80,0,0}; //2.78 amp 15000
        float f[NDET] = {2000, 12000,200, 300,175, 350, 60,200, 90,200,160,200,20, 220, 70,0,0}; //4.8 amp 15000
        float g[NDET] = {10000,45000,450,1000,400,1200,250,700,200,650,500,450,100,700,300,0,0}; //6.985 amp 20000
  
        float carbonamp[NDET] = {130,425,8,30,14,36,3.5,11,6,60,20,37,9,21,16,0,0};
  
        float h[NDET] = {24000,100000}; // 11.64 amp
        float gsintegral[NDET]; //gs
        //float firstsint[NDET]; //1.5
        float ssint[NDET]; //2.345
        float tsint[NDET]; //2.751
        float fsint[NDET]; //4.8
        float sixstateint[NDET]; //6.985
  
        Double_t * fit[NDET];
  
        TF1 *gs = new TF1("groundstate","gaus",-200,400);
        TF1 *ambb = new TF1("ambbstate","gaus",-200,400);
        TF1 *bmbb = new TF1("bmbbstate","gaus",-200,400);
        TF1 *cmbb = new TF1("cmbbstate","gaus",-200,400);
        TF1 *second = new TF1("second","gaus",-200,400);
        second->SetLineColor(kGreen);
        TF1 *third = new TF1("third","gaus",-200,400);
        third->SetLineColor(kBlue);
        TF1 *fourth = new TF1("fourth","gaus",-200,400);
        TF1 *fifth = new TF1("fifth","gaus",-200,400);
        fifth->SetLineColor(kYellow);
        TF1 *sixth = new TF1("sixth","gaus",-200,400);
        sixth->SetLineColor(kLake);
        TF1 *seventh = new TF1("seventh", "gaus", -200, 400);
        seventh->SetLineColor(kViolet);
        TF1 *totalstate = new TF1("total","gaus(0)+gaus(3)+gaus(6)+gaus(9)+gaus(12)+gaus(15)+gaus(18)+gaus(21)+gaus(24)+gaus(27)",-200,400);
        totalstate->SetLineColor(kBlack);
  
        //TH1 * fithist[NDET];
  
        for (int i = 0; i < NDET; i++) {
          if (a[i] == 0) {
            continue;
          }
          if (target == "li") {
            if (i == 0 || i == 1) {
              gs->SetParameters(a[i],0,1.43); //0
              gs->SetNpx(5000);
              second->SetParameters(c[i],2.345,1.43); //2.345
              second->SetNpx(5000);
              third->SetParameters(d[i],2.78,1.43); //2.78
              third->SetNpx(5000);
              fifth->SetParameters(f[i],4.8,1.43); //4.8
              fifth->SetNpx(5000);
              sixth->SetParameters(g[i],6.985,1.43); //6.985
              sixth->SetNpx(5000);
              seventh->SetParameters(h[i],11.64,1.43); //11.64
              seventh->SetNpx(5000);
              double pars[18] = {
                a[i],0,1.43, c[i],2.345,1.43, d[i],2.78,1.43, f[i],4.8,1.43, g[i],6.985,1.43, h[i],11.64,1.43
              };
              totalstate->SetParameters(pars);
              totalstate->SetNpx(5000);
              totalstate->SetLineStyle(kDashed);
              totalstate->SetLineWidth(1);
            } else {
              gs->SetParameters(a[i],0,.35); //0
              gs->SetNpx(5000);
              second->SetParameters(c[i],2.345,.35); //2.345
              second->SetNpx(5000);
              third->SetParameters(d[i],2.78,1.57); //2.78
              third->SetNpx(5000);
              fifth->SetParameters(f[i],4.8,0.6); //4.8
              fifth->SetNpx(5000);
              sixth->SetParameters(g[i],6.985,1.09); //6.985
              sixth->SetNpx(5000);
              seventh->SetParameters(0,11.64,0); //11.64
              seventh->SetNpx(5000);
              double pars[18] = {
                a[i],0,0.35, c[i],2.345,0.35, d[i],2.78,1.57, f[i],4.8,0.6, g[i],6.985,1.09, 0, 11.64, 1.43
              };
              totalstate->SetParameters(pars);
              totalstate->SetNpx(5000);
            }
          } else if (target == "carbon") {
            if (i == 0 || i == 1) {
              gs->SetParameters(carbonamp[i],0,1.43); //0
              gs->SetNpx(5000);
              double pars[3] = {
                carbonamp[i],0,1.43
              };
              totalstate->SetParameters(pars);
              totalstate->SetNpx(5000);
              totalstate->SetLineStyle(kDashed);
              totalstate->SetLineWidth(1);
            } 
            else {
              gs->SetParameters(carbonamp[i],0,.35); //0
              gs->SetNpx(5000);
              double pars[3] = {
                carbonamp[i],0,0.35
              };
              totalstate->SetParameters(pars);
              totalstate->SetNpx(5000);
            }
          }
        
          canvas->cd(i+1);
          totq[Det2AngleOrder.at(i)]->Draw("E");
          totq[Det2AngleOrder.at(i)]->Draw("same");
          if (target == "li") {
            totalstate->Draw("same");
            gs->Draw("same");
            gsintegral[i] = gs->Integral(-1,1); //gs
            second->Draw("same");
            ssint[i] = second->Integral(1,4); //2.345
            third->Draw("same");
            tsint[i] = third->Integral(-2,8); //2.78
            fifth->Draw("same");
            fsint[i] = fifth->Integral(2,8); //4.8
            sixth->Draw("same");
            sixstateint[i] = sixth->Integral(3,12); //6.985
            seventh->Draw("same");
            if (i == 0 || i == 1) {
              gsintegral[i] = gs->Integral(-4,4); //gs
              ssint[i] = second->Integral(-2,6); //2.345
              tsint[i] = third->Integral(-2,8); //2.78
              fsint[i] = fifth->Integral(0,10); //4.8
              sixstateint[i] = sixth->Integral(2,12); //6.985
            } else {
              gsintegral[i] = gs->Integral(-1,1); //gs
              ssint[i] = second->Integral(1,4); //2.345
              tsint[i] = third->Integral(-2,8); //2.78
              fsint[i] = fifth->Integral(2,8); //4.8
              sixstateint[i] = sixth->Integral(3,12); //6.985
            }
            canvas->SaveAs(Form("Det%.1f.root",Angle[Det2AngleOrder.at(i)]));
            std::cout << "saved canvas as " << Form("Det%.1f.root",Angle[Det2AngleOrder.at(i)]) << std::endl;
          }
          else if (target == "carbon") {
            totalstate->Draw("same");
            gs->Draw("same");
            gsintegral[i] = gs->Integral(-1,1); //gs
            if (i == 0 || i == 1) {
              gsintegral[i] = gs->Integral(-4,4); //gs
            } else {
              gsintegral[i] = gs->Integral(-1,1); //gs
            }
            canvas->SaveAs(Form("Det%.1f.root",Angle[Det2AngleOrder.at(i)]));
            std::cout << "saved canvas as " << Form("Det%.1f.root",Angle[Det2AngleOrder.at(i)]) << std::endl;
          }
        }
        
        for (int i = 0; i < NDET; i++) {
          printf("Angle: %.1f gs: %f second: %f Third: %f fifth: %f sixth: %f \n", Angle[Det2AngleOrder.at(i)], gsintegral[i], ssint[i], tsint[i], fsint[i], sixstateint[i]);
        } 
      */
      } else if (det != "all") {
        totq[jo]->Draw();
      }
      
      /*
      float a[NDET] = {2000, 12000, 80, 290, 35, 100, 70,200, 35,200,200, 85,22,120, 25,0,0}; //gs amp 20000
      float c[NDET] = {2500, 14000,120, 320, 35, 240, 80,240, 35,150,170,110,20,100, 25,0,0}; //2.345 amp 25000
      float d[NDET] = {2500, 14500,120, 320, 40, 200, 80,220,100,200,200,140,25,300, 80,0,0}; //2.78 amp 15000
      float f[NDET] = {2000, 12000,200, 300,175, 350, 60,200, 90,200,160,200,20,220, 70,0,0}; //4.8 amp 15000
      float g[NDET] = {10000,45000,450,1000,400,1200,250,700,200,650,500,450,90,700,300,0,0}; //6.985 amp 20000
      
      float h[NDET] = {24000,100000}; // 11.64 amp
      float gsintegral[NDET]; //gs
      float ssint[NDET]; //2.345
      float tsint[NDET]; //2.751
      float fsint[NDET]; //4.8
      float sixstateint[NDET]; //6.985

      TF1 *gs = new TF1("groundstate","gaus",-200,400);
      TF1 *ambb = new TF1("ambbstate","gaus",-200,400);
      TF1 *bmbb = new TF1("bmbbstate","gaus",-200,400);
      TF1 *cmbb = new TF1("cmbbstate","gaus",-200,400);
      //TF1 *first = new TF1("first","gaus",-200,400);
      //first->SetLineColor(kOrange);
      TF1 *second = new TF1("second","gaus",-200,400);
      second->SetLineColor(kGreen);
      TF1 *third = new TF1("third","gaus",-200,400);
      third->SetLineColor(kBlue);
      TF1 *fourth = new TF1("fourth","gaus",-200,400);
      TF1 *fifth = new TF1("fifth","gaus",-200,400);
      fifth->SetLineColor(kYellow);
      TF1 *sixth = new TF1("sixth","gaus",-200,400);
      sixth->SetLineColor(kLake);
      TF1 *seventh = new TF1("seventh", "gaus", -200, 400);
      seventh->SetLineColor(kViolet);
      //TF1 *seventh = new TF1("sixth","gaus",-200,400);
      //seventh->SetLineColor(kCopper);
      //TF1 *eight = new TF1("sixth","gaus",-200,400);
      //eight->SetLineColor(kCoffee);
      TF1 *totalstate = new TF1("total","gaus(0)+gaus(3)+gaus(6)+gaus(9)+gaus(12)+gaus(15)+gaus(18)+gaus(21)+gaus(24)+gaus(27)",-200,400);
      totalstate->SetLineColor(kBlack);
      
      if (AngleOrder2Det.at(i) == 0 || AngleOrder2Det.at(i) == 1) {
        gs->SetParameters(a[AngleOrder2Det.at(i)],0,1.43); //0
        gs->SetNpx(5000);
        second->SetParameters(c[AngleOrder2Det.at(i)],2.345,1.43); //2.345
        second->SetNpx(5000);
        third->SetParameters(d[AngleOrder2Det.at(i)],2.78,1.43); //2.78
        third->SetNpx(5000);
        fifth->SetParameters(f[AngleOrder2Det.at(i)],4.8,1.43); //4.8
        fifth->SetNpx(5000);
        sixth->SetParameters(g[AngleOrder2Det.at(i)],6.985,1.43); //6.985
        sixth->SetNpx(5000);
        seventh->SetParameters(h[AngleOrder2Det.at(i)],11.64,1.43); //11.64
        seventh->SetNpx(5000);
        double pars[18] = {
          a[AngleOrder2Det.at(i)],0,1.43, c[AngleOrder2Det.at(i)],2.345,1.43, d[AngleOrder2Det.at(i)],2.78,1.43, f[AngleOrder2Det.at(i)],4.8,1.43, g[AngleOrder2Det.at(i)],6.985,1.43, h[AngleOrder2Det.at(i)],11.64,1.43
        };
        totalstate->SetParameters(pars);
        totalstate->SetNpx(5000);
        totalstate->SetLineStyle(kDashed);
        totalstate->SetLineWidth(1);
      } else {
        gs->SetParameters(a[AngleOrder2Det.at(i)],0,.35); //0
        gs->SetNpx(5000);
        second->SetParameters(c[AngleOrder2Det.at(i)],2.345,.35); //2.345
        second->SetNpx(5000);
        third->SetParameters(d[AngleOrder2Det.at(i)],2.78,1.57); //2.78
        third->SetNpx(5000);
        fifth->SetParameters(f[AngleOrder2Det.at(i)],4.8,0.6); //4.8
        fifth->SetNpx(5000);
        sixth->SetParameters(g[AngleOrder2Det.at(i)],6.985,1.09); //6.985
        sixth->SetNpx(5000);
        seventh->SetParameters(0,11.64,0); //11.64
        seventh->SetNpx(5000);
        double pars[18] = {
          a[AngleOrder2Det.at(i)],0,0.35, c[AngleOrder2Det.at(i)],2.345,0.35, d[AngleOrder2Det.at(i)],2.78,1.57, f[AngleOrder2Det.at(i)],4.8,0.6, g[AngleOrder2Det.at(i)],6.985,1.09, 0, 11.64, 1.43
        };
        totalstate->SetParameters(pars);
        totalstate->SetNpx(5000);
        totalstate->SetLineStyle(kDashed);
        totalstate->SetLineWidth(1);
      }

      gs->Draw("same");
      second->Draw("same");
      third->Draw("same");
      fourth->Draw("same");
      fifth->Draw("same");
      sixth->Draw("same");
      seventh->Draw("same");
      totalstate->Draw("same");
      */
      
    }

    if (type == "calibration") {
      if (det == "all") {
        for (int i = 0; i<NDET; i++) {
        canvas->cd(i+1);
        totalcal[Det2AngleOrder.at(i)]->Draw();
        totalcal2[Det2AngleOrder.at(i)]->Draw("same"); }
      }
      else if (det != "all") {
        totalcal[Det2AngleOrder.at(jo)]->Draw();
        totalcal2[Det2AngleOrder.at(jo)]->Draw("same");
      }
    }

    if (type == "totalenergy") {
      TCanvas *canvas1 = new TCanvas();
      for (int i = 0; i < NDET; i++) {
        energyplot->Add(totq[i]);
        totq[i]->Reset();
      }      
        energyplot->Draw();
        /*
        
        TF1 *gs = new TF1("groundstate","gaus",-20,20);
        TF1 *first = new TF1("first","gaus",-20,20);
        TF1 *second = new TF1("second","gaus",-20,20);
        TF1 *third = new TF1("third","gaus",-20,20);
        TF1 *fourth = new TF1("fourth","gaus",-20,20);
        TF1 *fifth = new TF1("fifth","gaus",-20,20);
        TF1 *sixth = new TF1("sixth","gaus",-20,20);
        TF1 *seventh = new TF1("sixth","gaus",-20,20);
        TF1 *eight = new TF1("sixth","gaus",-20,20);
        TF1 *total = new TF1("total","gaus(0)+gaus(3)+gaus(6)+gaus(9)+gaus(12)+gaus(15)+gaus(18)+gaus(21)+gaus(24)",-20,20);
    
        gs->SetParameters(400,0,0.16); //1306
        gs->SetNpx(3000);
        first->SetParameters(300,1.5,.6);
        first->SetNpx(3000);
        second->SetParameters(50,2.345,0.16);
        second->SetNpx(3000);
        third->SetParameters(200,2.751,0.306);
        third->SetNpx(3000);
        fourth->SetParameters(200,2.78,1.57);
        fourth->SetNpx(3000);
        fifth->SetParameters(400,4.8,.6);
        fifth->SetNpx(3000);
        sixth->SetParameters(1200,6.985,1.09);
        sixth->SetNpx(3000);
        seventh->SetParameters(1.,11.64,0.39);
        eight->SetParameters(1.,12.16,0.228);
        double pars[27] = {
            400,0,0.16, 300,1.5,.6, 50,2.345,0.16, 200,2.751,0.306, 200,2.78,1.57, 400,4.8,.6, 1200,6.985,1.09, 1.,11.64,0.39, 1.,12.16,0.228
        };
        //for (int i = 0; i < 8; i++) {
          //pars[3*i] = pars[3*i] / 40.;
        //}
        total->SetParameters(pars);
        total->SetNpx(3000);
    
        //TCanvas *c = new TCanvas();
        //c->SetYAxis();
    
        //c->cd();
        gs->Draw("same");
        //gs->GetYaxis()->SetRangeUser(0,7000);
        first->Draw("same");
        second->Draw("same");
        third->Draw("same");
        fourth->Draw("same");
        fifth->Draw("same");
        sixth->Draw("same");
        seventh->Draw("same");
        eight->Draw("same");
        total->Draw("same");
        */  
    }

    if (type == "nenergy") {
      path = "canvases/nenergy_carbon";
      gSystem->mkdir(path.c_str(), kTRUE);
      gSystem->cd(path.c_str());
      TCanvas *canvas1 = new TCanvas();
      if (det == "all") {
      //canvas1->Divide(5,4);
      for (int i = 0; i < NDET; i++) {
        //canvas1->cd(i+1);
        canvas1->cd();
        totnenergy[Det2AngleOrder.at(i)]->Draw();
        canvas1->SaveAs(Form("total_nenergy_plot_%f.root",Angle[Det2AngleOrder.at(i)]));
      }
      } else if (det != "all") {
        totnenergy[jo]->Draw();
      }
    }

    if (type == "lovstof") {
      TCanvas *c = new TCanvas();
      c->Divide(5,4);
      for (int i = 0; i<NDET; i++) {
        c->cd(i+1);
        total2d[Det2AngleOrder.at(i)]->Draw();
      }
    }

    /*
    if (type == "tofvsq") {
      canvas->Divide(5,4);
      for (int i = 0; i < NDET; i++) {
        canvas->cd(i+1);
        tottofvq[i]->Draw();
        //alltofvq->Add(tottofvq[i],1.0);
        //tottofvq[i]->Reset();
      }
      //alltofvq->Draw();
    }
    if(type == "tDiff") {
      for(int i = 0; i<NDET; i++) {
        canvas->cd(i+1);
        tDiff[i]->Draw();
      }
    }
    if (type == "tofvslong") {
      canvas->Divide(5,4);
      for (int i = 0; i < NDET; i++) {
        canvas->cd(i+1);
        tottofvslong[i]->Draw();
      }
    }
    if (type == "envslong") {
      canvas->Divide(5,4);
      for (int i = 0; i < NDET; i++) {
        canvas->cd(i+1);
        totenvslong[i]->Draw();
      }
    }
    if (type == "excitation") {
      TCanvas *canvas1 = new TCanvas();
      canvas1->Divide(5,4);
      for (int i = 0; i < NDET; i++) {
        canvas1->cd(i+1);
        //totq[i]->Draw();
        //canvas->cd(i+1);
        //totq1[i]->Draw();
        //energyplot->Add(totq[i]);
        //energyplot->Add(totq1[i]);
        //totq[i]->Reset();
        //totq1[i]->Reset();
        //canvas1->cd(i+1);
        //totq[i]->Draw();
      }
      energyplot->Draw();
    }
    if (type == "exq") {
      TCanvas *canvas1 = new TCanvas();
      for (int i = 0; i < NDET; i++) {
        qexplot->Add(exvsq[i]);
        exvsq[i]->Reset();
        //exvsq[i]->Draw();
      }
      qexplot->Draw();
    }
    if (type == "addbackground") {
      for (int i = 0; i<NDET; i++) {
        canvas->cd(i+1);
        total[i]->SetLineColor(kYellow);
        total[i]->Draw("same");
        total2[i]->SetLineColor(kBlack);
        total2[i]->Draw("same");
      }
    }
    if (type == "addq") {
      for (int i = 0; i<NDET; i++) {
        energyplot1->Add(totq1[i]);
        energyplot->Add(totq[i]);
      }
      energyplot1->Draw();
      energyplot->Draw("same");
    }
    if (type == "long") {
      canvas->Divide(5,4);
      for (int i = 0; i < NDET; i++) {
        canvas->cd(i+1);
        totallong[i]->Draw();
      }
    }
    if (type == "addbig") {
      canvas->SaveAs("all_runs_overlapbig.jpg");
    }
    if (type == "addsmall") {
      canvas->SaveAs("all_runs_overlapsmall.jpg");
    }
    */
    if (type == "totaltDiff" || type == "totaltDiffg") {
      //path = "prosplot/tdiffg_no_comp_no_background_200kevee";
      //gSystem->mkdir(path.c_str(), kTRUE);
      //gSystem->cd(path.c_str());
      TCanvas *temp = new TCanvas();
      if (det == "all") {
        for (int i = 0; i < NDET; i++) {
          //if (i == 2 || i == 4 || i == 6 || i == 8 || i == 11) {
          canvas->cd(i+1);
          //temp->cd();
          total[Det2AngleOrder.at(i)]->Draw();
          //temp->SaveAs(Form("tof_gated_plot_%f.root",Angle[Det2AngleOrder.at(i)]));
        //} else {continue;} 
        }
      } else if (det != "all") {
        total[jo]->Draw();
        //total[jo]->SaveAs(Form("tof_gated_plot_%d",jo));
      }
    }
    
    if (type == "normtest" ) {
      if (det == "all") {
      for (int i = 0; i < NDET; i++) {
        canvas->cd(i+1);
        //total[Det2AngleOrder.at(i)]->Draw();
        total4[Det2AngleOrder.at(i)]->Draw();
        total3[Det2AngleOrder.at(i)]->Draw("same");
        total3[Det2AngleOrder.at(i)]->SetLineColor(colors[1]);
        //total2[Det2AngleOrder.at(i)]->Draw("same");
        //total2[Det2AngleOrder.at(i)]->SetLineColor(colors[0]);
        //total4[Det2AngleOrder.at(i)]->Draw("same");
      }
      }
      else if (det != "all") {
        total4[jo]->Draw();
        total3[jo]->Draw("same");
        total3[jo]->SetLineColor(colors[1]);
      }
    }

    if (type == "normtestg" ) {
      if (det == "all") {
      for (int i = 0; i < NDET; i++) {
        canvas->cd(i+1);
        //total[Det2AngleOrder.at(i)]->Draw();
        total3[Det2AngleOrder.at(i)]->Draw();
        total4[Det2AngleOrder.at(i)]->Draw("same");
        total3[Det2AngleOrder.at(i)]->SetLineColor(colors[1]);
        //total2[Det2AngleOrder.at(i)]->Draw("same");
        //total2[Det2AngleOrder.at(i)]->SetLineColor(colors[0]);
        //total4[Det2AngleOrder.at(i)]->Draw("same");
      }
      }
      else if (det != "all") {
        total3[jo]->Draw();
        total4[jo]->Draw("same");
        total4[jo]->SetLineColor(colors[1]);
        //TF1 *test = new TF1("test","gaus",-200,400);
        //test->SetParameters();
        //test->Draw("same");
      }
    }

    if (type == "testplot") {
      path = "canvases/selective2ns";
      TCanvas *newcanvas = new TCanvas();
      if (det == "all") {
      TCanvas *newcanvas = new TCanvas();
      gSystem->mkdir(path.c_str(), kTRUE);
      gSystem->cd(path.c_str());
      for (int i = 0; i < NDET; i++) {
        //total[Det2AngleOrder.at(i)]->Draw();
        total3[Det2AngleOrder.at(i)]->Draw();
        total4[Det2AngleOrder.at(i)]->Draw("same");
        total3[Det2AngleOrder.at(i)]->SetLineColor(colors[1]);
        newcanvas->SaveAs(Form("Det%.1f.root",Angle[Det2AngleOrder.at(i)]));
        //total2[Det2AngleOrder.at(i)]->Draw("same");
        //total2[Det2AngleOrder.at(i)]->SetLineColor(colors[0]);
        //total4[Det2AngleOrder.at(i)]->Draw("same");
      }
      }
    }
    
    if (type == "totalsubtractiong" || type == "totalsubtraction") {
      
      //double a[NDET] = {0,0,300,500,150,500,150,400,120,300,350,250,50,350,120,0,0};
      double ground[NDET] = {15.77,16.23,43.04,41.55,43.57,42.76,44.36,43.15,43.28,43.42,42.91,44.32,44.27,43.3,43.64,0,0}; //0
      double secondstate[NDET] = {17.13,17.66,47.23,45.63,47.87,47,48.8,47.49,47.74,47.94,47.39,48.97,48.94,47.87,48.27,0,0}; //2.345
      double thirdstate[NDET] = {17.41,17.95,48.1,46.48,48.76,47.88,49.72,48.4,48.67,48.88,48.32,49.94,49.91,48.82,49.24,0,0}; //2.751
      double fourthstate[NDET] = {19.04,19.67,53.29,51.55,54.1,53.16,55.24,53.81,54.27,54.55,53.95,55.81,55.8,54.58,55.08,0,0};  //4.8
      double fifthstate[NDET] = {21.43,22.21,61.17,59.26,62.23,61.21,63.7,62.12,62.9,63.37,63.32,62.67,64.9,64.93,63.53,0,0}; //6.985
      double sixthstate[NDET] = {33.63,35.43,24.6,22.2,27.8,26.6,31.9,29.8,33.9,35.6,34.8,39.8,40.4,37.8,39.6,0,0}; //11.64
      double seventhstate[NDET] = {36.97,39.16,39.3,37,43.5,42.4,48.8,46.6,52.2,54.6,53.8,59.9,60.7,57.7,60.1,0,0}; //12.16

      float a[NDET] = {4000,20000,100,400,50,200,100,250,70,250,250,120,30,250,40,0,0}; //gs amp
      //float b[NDET] = {4000,25000,250,400,80,300,120,200, 80,  200,350,120,20,325,60,0,0}; //1.5 amp
      float c[NDET] = {4000,25000,100,275,25,115,55,  150,51,150,115,110,20,130,45,0,0}; //2.345 amp
      float d[NDET] = {3500,15000,100,200,35,175,70,225,50,100,175,100,20,150,50,0,0}; //2.751 amp
      //float e[NDET] = {}; //2.78 amp
      float f[NDET] = {3500,15000,300,600,125,500,100,200,100,200,200,200,20,200,100,0,0}; //4.8 amp
      float g[NDET] = {10000,60000,450,1000,250,1200,250,700,200,650,500,450,90,700,280,0,0}; //6.985 amp

      float h[NDET]; //12.16 amp (since the 11.64 MeV state comes before the ground state and will not appear in spectrum)
      
      for (int i = 0; i <NDET; i++) {
        canvas->cd(i+1);
        //total[i]->SetEntries(entries[i]);
        //std::cout << entries[i] << std::endl;
        total[Det2AngleOrder.at(i)]->Draw();
        
        TF1 *gs = new TF1("groundstate","gaus",-200,400);
        TF1 *first = new TF1("first","gaus",-200,400);
        first->SetLineColor(kOrange);
        TF1 *second = new TF1("second","gaus",-200,400);
        second->SetLineColor(kGreen);
        TF1 *third = new TF1("third","gaus",-200,400);
        third->SetLineColor(kBlue);
        TF1 *fourth = new TF1("fourth","gaus",-200,400);
        TF1 *fifth = new TF1("fifth","gaus",-200,400);
        fifth->SetLineColor(kYellow);
        TF1 *sixth = new TF1("sixth","gaus",-200,400);
        sixth->SetLineColor(kLake);
        //TF1 *seventh = new TF1("sixth","gaus",-200,400);
        //seventh->SetLineColor(kCopper);
        //TF1 *eight = new TF1("sixth","gaus",-200,400);
        //eight->SetLineColor(kCoffee);
        TF1 *totalstate = new TF1("total","gaus(0)+gaus(3)+gaus(6)+gaus(9)+gaus(12)+gaus(15)",-200,400);
        totalstate->SetLineColor(kBlack);

        TF1 *nbody1 = new TF1("2a + n + p", "gaus", -200, 400);
        nbody1 -> SetLineColor(kAzure);
        TF1 *nbody2 = new TF1("8Be + n + p", "gaus", -200, 400);
        nbody2 -> SetLineColor(kAzure);
        TF1 *nbody3 = new TF1("a + n + 5Li", "gaus", -200, 400);
        nbody3 -> SetLineColor(kAzure);
        
        gs->SetParameters(a[i],ground[i],1); //0
        gs->SetNpx(5000);
        first->SetParameters(c[i],secondstate[i],1); //2.345
        first->SetNpx(5000);
        //second->SetParameters(d[i],thirdstate[i],1.5); //2.751
        //second->SetNpx(5000);
        //fourth->SetParameters(d[i],thirdstate[i],7.5); //2.78
        //fifth->SetParameters(f[i],fourthstate[i],4); //4.8
        if (Det2AngleOrder.at(i) == 0 || Det2AngleOrder.at(i) == 1) {
        fourth->SetParameters(d[i],thirdstate[i],5); //2.78
        fifth->SetParameters(f[i],fourthstate[i],2.5); //4.8
        sixth->SetParameters(g[i],fifthstate[i],7); //6.985
        }
        else {
        fourth->SetParameters(d[i],thirdstate[i],7.5); //2.78
        fifth->SetParameters(f[i],fourthstate[i],5); //4.8
        sixth->SetParameters(g[i],fifthstate[i],12); //6.985
        }
        fourth->SetNpx(5000);
        fifth->SetNpx(5000);
        sixth->SetNpx(5000);
        //sixth->SetParameters(,sixthstate[i],25); //11.64
        //sixth->SetNpx(5000);
        //seventh->SetParameters(,seventhstate[i],23);  //12.16
        //seventh->SetNpx(5000);
        //eight->SetParameters(a[i]/4,48.8,2);
        double pars[15];
        double pars1[15] = {a[i],ground[i],1, c[i],secondstate[i],1, d[i],thirdstate[i],5, f[i],fourthstate[i],2.5, g[i],fifthstate[i],7 };
        double pars2[15] = {a[i],ground[i],1, c[i],secondstate[i],1, d[i],thirdstate[i],7.5, f[i],fourthstate[i],5, g[i],fifthstate[i],12};
        if (Det2AngleOrder.at(i) == 0 || Det2AngleOrder.at(i) == 1) {
          for (int i = 0; i<15; i++) {
          pars[i] = pars1[i];
          }
        }
        else {
          for (int i = 0; i < 15; i++) {
          pars[i] = pars2[i];
          }
        }
        totalstate->SetParameters(pars);
        totalstate->SetNpx(5000);
        sixth->SetLineStyle(kDashed);
        //seventh->SetLineStyle(kDashed);
        totalstate->SetLineStyle(kDashed);
        totalstate->SetLineWidth(1);

        gs->Draw("same");
        //gs->GetYaxis()->SetRangeUser(0,7000);
        first->Draw("same");
        second->Draw("same");
        third->Draw("same");
        fourth->Draw("same");
        fifth->Draw("same");
        sixth->Draw("same");
        //seventh->Draw("same");
        totalstate->Draw("same");
        
      }
    }

    if (type == "totalPSD") {
      if (det == "all") {
      TCanvas *temp = new TCanvas();
      //path = "canvases/high_threshold_psd";
      //path = "canvases/li_low_threshold_psd";
      //gSystem->mkdir(path.c_str(), kTRUE);
      //gSystem->cd(path.c_str());
      if (calibration == "no") {
        for (int i = 0; i<NDET; i++) {
          canvas->cd(i+1);
          totalPSD[i]->Draw();
        }
      }
      if (calibration == "yes") {
        for (int i = 0; i<NDET; i++) {
          canvas->cd(i+1);
          //temp->cd();
          totalPSDc[i]->Draw();
          //cuts[i]->Draw("same");
          //temp->SaveAs(Form("PSD %f.root", Angle[Det2AngleOrder.at(i)]));
          //totalPSDc[i]->Draw();
        }
      }
      }
      else if (det != "all") {
        if (calibration == "no") {
          totalPSD[jo]->Draw();
        }
        else if (calibration == "yes") {
          totalPSDc[jo]->Draw();
          cuts[jo]->Draw("same");
        }
      }
    }
}