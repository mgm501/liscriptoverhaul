#ifndef VARIABLES_H
#define VARIABLES_H

#include <iostream>
#include <cstdlib>
#include <array>
#include <cmath>

using std::array;

inline constexpr unsigned short ndet = 17;

inline double q = 0;
inline double mn = 939.57;
inline double mev = 0;
inline double m12c = 11.178 * 931.5;
inline double mnsi = 1.6749e-27;
inline double m3he = 3.0160 * 931.5;
inline double m7li = 7.016 * 931.5;
inline double m14o = 14.0086 * 931.5;
inline double m9b = 931.5 * 9.0133;
inline double beamenergy = 7;
inline double ex = 0;
inline double joules2mev = 6.241509e12;

inline double residualmass = 0;
inline double ejectilemass = 0;
inline double projectilemass = 0;
inline double targetmass = 0;
inline double q0 = 0;
inline double linorm = 0;
inline double carbonnorm = 0;
inline double normalization = 0;

inline array<double, ndet> angle = {44, 54, 97, 101, 102.5, 105, 108.5, 111.5, 123, 127.5, 129.5, 133.5, 136, 136.5, 140, 90, 90}; //bad detectors are set to 90 so cos(theta)
inline array<double, ndet> sorteddistance;
inline array<double, ndet> distance = {1.97, 0, 1.935, 1.99, 1.99, 2.02, 2.03, 2.08, 2.09, 0, 1.94, 1.98, 1., 1.98, 2.08, 1., 1.94}; //0.85, 
inline array<int, ndet> el;
inline array<int, ndet> es;

inline array<unsigned long long, ndet> tN;
inline unsigned long long tRF = 0;
inline int detnum; inline int detindex;

inline double tof;
inline double tofsec;

struct observables {
    string name;
    int xbins = 0;
    int xmin= 0;
    int xmax =  0;
    int ybins = 0;
    int ymin  = 0;
    int ymax = 0;
    int xbins1 = 0;
    int xmin1  = 0;
    int xmax1  = 0;
    int ybins1= 0;
    int ymin1 = 0;
    int ymax1 = 0;

    //bool operator==(const string & lhs) const {
        //return name == lhs;
    //}
};

inline observables tof_s{"tof",300,-200,400,1,1,2,300,-200,400,1,1,2};
inline observables tofg_s{"tofg",300,-200,400,1,1,2,300,-200,400,1,1,2};
inline observables toftroubleshoot_s{"toftroubleshoot",300,200,800,1,1,2,300,200,800,1,1,2};
inline observables psd_s{"psd",300,0,4000,200,0,1,300,0,4000,200,0,1};
inline observables psdg_s{"psdg",300,0,4000,200,0,1,300,0,4000,200,0,1};
inline observables nenergy_s{"nenergy",40,-20,20,1,0,1,14,-20,20,1,0,1};
inline observables qvalues_s{"qvalues",40,-20,20,1,0,1,14,-20,20,1,0,1};
inline observables excitation_s{"excitation",40,-20,20,1,0,1,14,-20,20,1,0,1};

#endif