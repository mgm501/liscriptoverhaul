#ifndef VARIABLES
#define VARIABLES

#include <iostream>
#include <cstdlib>
#include <array>
#include <cmath>

const unsigned short ndet = 17;

double q;
double mn = 939.57;
double mev;
double m12c = 11.178 * 931.5;
double mnsi = 1.6749e-27;
double m3he = 3.0160 * 931.5;
double m7li = 7.016 * 931.5;
double m14o = 14.0086 * 931.5;
double beamenergy = 7;
double ex;
double joules2mev = 6.241509e12;

double residualmass;
double ejectilemass;
double projectilemass;
double targetmass;
double q0;
double linorm;
double carbonnorm;
double norm;

double angle[ndet] = {44, 54, 97, 101, 102.5, 105, 108.5, 111.5, 123, 127.5, 129.5, 133.5, 136, 136.5, 140, 90, 90}; //bad detectors are set to 90 so cos(theta) = 0

double sorteddistance[ndet];
double distance[ndet] = {1.97, 0, 1.935, 1.99, 1.99, 2.02, 2.03, 2.08, 2.09, 0, 1.94, 1.98, 1., 1.98, 2.08, 1., 1.94}; //0.85, 0.86

int el[ndet] = {0};
int es[ndet] = {0};

unsigned long long tN[ndet] = {0};
unsigned long long tRF = 0;
int detnum; int detindex;

double tof;
double tofsec;

#endif