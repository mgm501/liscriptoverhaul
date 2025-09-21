#ifndef CUTS_H
#define CUTS_H
#include "TCutG.h"
#include "variables.h"

using std::array;

inline array<TCutG*, ndet> carboncuts = {nullptr};
inline array<TCutG*, ndet> licuts = {nullptr};

inline void definecuts() {
    //need to insert function that swaps angle order variable i with initial mapping variable
  for (int i = 0; i < ndet; i++) {
    if (i == 13) {
      carboncuts[i] = new TCutG(Form("mycut %d",i),5); 
      carboncuts[i]->SetVarX("eL");  
      carboncuts[i]->SetVarY("eTail");
      carboncuts[i]->SetPoint(0,650,0.185);
      carboncuts[i]->SetPoint(1,820,0.21);
      carboncuts[i]->SetPoint(2,1150,0.34);
      carboncuts[i]->SetPoint(3,1150,0.36);
      carboncuts[i]->SetPoint(4,650,0.27);
      carboncuts[i]->SetPoint(5,650,0.185);
    }
    else if (i == 11) {
      carboncuts[i] = new TCutG(Form("mycut %d",i),5); 
      carboncuts[i]->SetVarX("eL");  
      carboncuts[i]->SetVarY("eTail");
      carboncuts[i]->SetPoint(0,650,0.17);
      carboncuts[i]->SetPoint(1,820,0.18);
      carboncuts[i]->SetPoint(2,1150,0.25);
      carboncuts[i]->SetPoint(3,1150,0.29);
      carboncuts[i]->SetPoint(4,820,0.248);
      carboncuts[i]->SetPoint(5,650,0.24);
      carboncuts[i]->SetPoint(6,650,0.17);
    }
    else if (i == 10) {
      carboncuts[i] = new TCutG(Form("mycut %d",i),5); 
      carboncuts[i]->SetVarX("eL");  
      carboncuts[i]->SetVarY("eTail");
      carboncuts[i]->SetPoint(0,650,0.165);
      carboncuts[i]->SetPoint(1,820,0.2);
      carboncuts[i]->SetPoint(2,1150,0.36);
      carboncuts[i]->SetPoint(3,1150,0.36);
      carboncuts[i]->SetPoint(4,650,0.27);
      carboncuts[i]->SetPoint(5,650,0.165);
    }
    else if (i == 7 || i == 12 || i == 14 || i == 16) {
      carboncuts[i] = new TCutG(Form("mycut %d",i),5); 
      carboncuts[i]->SetVarX("eL");  
      carboncuts[i]->SetVarY("eTail");
      carboncuts[i]->SetPoint(0,650,0.175);
      carboncuts[i]->SetPoint(1,820,0.19);
      carboncuts[i]->SetPoint(2,1150,0.275);
      carboncuts[i]->SetPoint(3,1150,0.36);
      carboncuts[i]->SetPoint(4,650,0.27);
      carboncuts[i]->SetPoint(5,650,0.175);
    }
    else if (i == 0 || i == 3 || i == 4 || i == 6) {
      carboncuts[i] = new TCutG(Form("mycut %d",i),5); 
      carboncuts[i]->SetVarX("eL");  
      carboncuts[i]->SetVarY("eTail");
      carboncuts[i]->SetPoint(0,650,0.15);
      carboncuts[i]->SetPoint(1,820,0.17);
      carboncuts[i]->SetPoint(2,1150,0.255);
      carboncuts[i]->SetPoint(3,1150,0.3);
      carboncuts[i]->SetPoint(4,650,0.24);
      carboncuts[i]->SetPoint(5,650,0.15);      
    }
    else if (i == 5) {
      carboncuts[i] = new TCutG(Form("mycut %d",i),5); 
      carboncuts[i]->SetVarX("eL");  
      carboncuts[i]->SetVarY("eTail");
      carboncuts[i]->SetPoint(0,650,.145);
      carboncuts[i]->SetPoint(1,820,0.165);
      carboncuts[i]->SetPoint(2,1150,0.245);
      carboncuts[i]->SetPoint(3,1150,0.255);
      carboncuts[i]->SetPoint(4,820,0.212);
      carboncuts[i]->SetPoint(5,650,0.21);
      carboncuts[i]->SetPoint(6,650,0.145);    
    }
    else if (i == 8) {
      carboncuts[i] = new TCutG(Form("mycut %d",i),5); 
      carboncuts[i]->SetVarX("eL");  
      carboncuts[i]->SetVarY("eTail");
      carboncuts[i]->SetPoint(0,650,0.14);
      carboncuts[i]->SetPoint(1,820,0.16);
      carboncuts[i]->SetPoint(2,1150,0.22);
      carboncuts[i]->SetPoint(3,1150,0.28);
      carboncuts[i]->SetPoint(4,650,0.27);
      carboncuts[i]->SetPoint(5,650,0.14);
    }
    else {
      carboncuts[i] = new TCutG(Form("mycut %d",i),5); 
      carboncuts[i]->SetVarX("eL");  
      carboncuts[i]->SetVarY("eTail");
      carboncuts[i]->SetPoint(0,650,0.13);
      carboncuts[i]->SetPoint(1,820,0.13);
      carboncuts[i]->SetPoint(2,1150,0.15);
      carboncuts[i]->SetPoint(3,1150,0.21);
      carboncuts[i]->SetPoint(4,650,0.21);
      carboncuts[i]->SetPoint(5,650,0.13);  
    }
    
// ===================================================================================================

   if (i == 13) {
      licuts[i] = new TCutG(Form("mycut %d",i),5); 
      licuts[i]->SetVarX("eL");  
      licuts[i]->SetVarY("eTail");
      licuts[i]->SetPoint(0,720,0.21);
      licuts[i]->SetPoint(1,720,0.23);
      licuts[i]->SetPoint(2,1150,0.33);
      licuts[i]->SetPoint(3,1800,0.45);
      licuts[i]->SetPoint(4,1800,0.47);
      licuts[i]->SetPoint(5,1150,0.36);
      licuts[i]->SetPoint(6,720,0.27);
      licuts[i]->SetPoint(7,720,0.21);
    }
    else if (i == 11) {
      licuts[i] = new TCutG(Form("mycut %d",i),5); 
      licuts[i]->SetVarX("eL");  
      licuts[i]->SetVarY("eTail");
      licuts[i]->SetPoint(0,720,0.17); //650
      licuts[i]->SetPoint(1,720,0.18);
      licuts[i]->SetPoint(2,1150,0.25);
      licuts[i]->SetPoint(3,1800,0.38);
      licuts[i]->SetPoint(4,1800,0.45);
      licuts[i]->SetPoint(5,1150,0.32);
      licuts[i]->SetPoint(6,720,0.248);
      licuts[i]->SetPoint(7,720,0.24);
      licuts[i]->SetPoint(8,720,0.17);
    }
    else if (i == 10) {
      licuts[i] = new TCutG(Form("mycut %d",i),5); 
      licuts[i]->SetVarX("eL");  
      licuts[i]->SetVarY("eTail");
      licuts[i]->SetPoint(0,720,0.19);
      licuts[i]->SetPoint(1,720,0.19);
      licuts[i]->SetPoint(2,1150,0.28);
      licuts[i]->SetPoint(3,1600,0.40);
      licuts[i]->SetPoint(4,1600,0.45);
      licuts[i]->SetPoint(5,1150,0.36);
      licuts[i]->SetPoint(6,720,0.27);
      licuts[i]->SetPoint(7,720,0.19);
    }
    else if (i == 7 || i == 12 || i == 16) {
      licuts[i] = new TCutG(Form("mycut %d",i),5); 
      licuts[i]->SetVarX("eL");  
      licuts[i]->SetVarY("eTail");
      licuts[i]->SetPoint(0,720,0.19);
      licuts[i]->SetPoint(1,720,0.19);
      licuts[i]->SetPoint(2,1150,0.275);
      licuts[i]->SetPoint(3,1800,0.37);
      licuts[i]->SetPoint(4,2050,0.38);
      licuts[i]->SetPoint(5,2050,0.44);
      licuts[i]->SetPoint(6,1800,0.41);
      licuts[i]->SetPoint(7,1150,0.36);
      licuts[i]->SetPoint(8,720,0.27);
      licuts[i]->SetPoint(9,720,0.19);
    }
    else if (i == 14) {
      licuts[i] = new TCutG(Form("mycut %d",i),5); 
      licuts[i]->SetVarX("eL");  
      licuts[i]->SetVarY("eTail");
      licuts[i]->SetPoint(0,720,0.19);
      licuts[i]->SetPoint(1,720,0.19);
      licuts[i]->SetPoint(2,1150,0.295);
      licuts[i]->SetPoint(3,1800,0.57);
      licuts[i]->SetPoint(4,2050,0.57);
      licuts[i]->SetPoint(5,2050,0.57);
      licuts[i]->SetPoint(6,1800,0.557);
      licuts[i]->SetPoint(7,1150,0.36);
      licuts[i]->SetPoint(8,720,0.27);
      licuts[i]->SetPoint(9,720,0.19);
    }
    else if (i == 4) {
    //else {
      licuts[i] = new TCutG(Form("mycut %d",i),5); 
      licuts[i]->SetVarX("eL");  
      licuts[i]->SetVarY("eTail");
      licuts[i]->SetPoint(0,720,0.172);
      licuts[i]->SetPoint(1,720,0.172); 
      licuts[i]->SetPoint(2,1150,0.24);
      licuts[i]->SetPoint(3,1600,0.38);
      licuts[i]->SetPoint(4,1600,0.4);
      licuts[i]->SetPoint(5,1150,0.3);
      licuts[i]->SetPoint(6,820,0.22);
      licuts[i]->SetPoint(7,720,0.22);
      licuts[i]->SetPoint(8,720,0.172);      
    }    
    else if (i == 0) {
    //else {
      licuts[i] = new TCutG(Form("mycut %d",i),5); 
      licuts[i]->SetVarX("eL");  
      licuts[i]->SetVarY("eTail");
      licuts[i]->SetPoint(0,720,0.172);
      licuts[i]->SetPoint(1,720,0.172);
      licuts[i]->SetPoint(2,1150,0.25);
      licuts[i]->SetPoint(3,1600,0.42);
      licuts[i]->SetPoint(4,1600,0.46);
      licuts[i]->SetPoint(5,1150,0.3);
      licuts[i]->SetPoint(6,720,0.22);
      licuts[i]->SetPoint(7,720,0.22);
      licuts[i]->SetPoint(8,720,0.172);      
    }
    else if (i == 6) {
      licuts[i] = new TCutG(Form("mycut %d",i),5); 
      licuts[i]->SetVarX("eL");  
      licuts[i]->SetVarY("eTail");
      licuts[i]->SetPoint(0,720,0.164);
      licuts[i]->SetPoint(1,820,0.164);
      licuts[i]->SetPoint(2,1150,0.23);
      licuts[i]->SetPoint(3,1600,0.33);
      licuts[i]->SetPoint(4,1800,0.35);
      licuts[i]->SetPoint(5,1800,0.4);
      licuts[i]->SetPoint(6,1150,0.3);
      licuts[i]->SetPoint(7,820,0.22);
      licuts[i]->SetPoint(8,820,0.22);
      licuts[i]->SetPoint(9,720,0.164);  
    }
    else if (i == 3) {
      licuts[i] = new TCutG(Form("mycut %d",i),5); 
      licuts[i]->SetVarX("eL");  
      licuts[i]->SetVarY("eTail");
      //licuts[i]->SetPoint(0,700,0.11);
      licuts[i]->SetPoint(0,720,0.162);
      
      licuts[i]->SetPoint(1,1150,0.24);
      licuts[i]->SetPoint(2,1800,0.38);
      licuts[i]->SetPoint(3,1800,0.4);
      licuts[i]->SetPoint(4,1150,0.3);
      licuts[i]->SetPoint(5,720,0.22);
      licuts[i]->SetPoint(6,720,0.162);
      
      //licuts[i]->SetPoint(6,700,0.22);
      //licuts[i]->SetPoint(7,700,0.11);   
    }
    else if (i == 5) {
      licuts[i] = new TCutG(Form("mycut %d",i),5); 
      licuts[i]->SetVarX("eL");  
      licuts[i]->SetVarY("eTail");
      //licuts[i]->SetPoint(0,300,0.14); // 650
      licuts[i]->SetPoint(0,720,.15);
      licuts[i]->SetPoint(1,820,0.15);
      
      licuts[i]->SetPoint(2,1150,0.22);
      licuts[i]->SetPoint(3,1800,0.38);
      licuts[i]->SetPoint(4,1800,0.4);
      licuts[i]->SetPoint(5,1150,0.28);
      
      licuts[i]->SetPoint(6,820,0.212);
      licuts[i]->SetPoint(7,720,0.2);
      licuts[i]->SetPoint(8,720,0.15);    
    }
    else if (i == 8) {
      licuts[i] = new TCutG(Form("mycut %d",i),5); 
      licuts[i]->SetVarX("eL");  
      licuts[i]->SetVarY("eTail");
      licuts[i]->SetPoint(0,720,0.16);
      licuts[i]->SetPoint(1,720,0.16);
      
      licuts[i]->SetPoint(2,1150,0.22);
      licuts[i]->SetPoint(3,1800,0.315);
      licuts[i]->SetPoint(4,2100,0.35);
      licuts[i]->SetPoint(5,2500,0.4);
      licuts[i]->SetPoint(6,2500,0.47);
      licuts[i]->SetPoint(7,2100,0.42);
      licuts[i]->SetPoint(8,1800,0.38);
      licuts[i]->SetPoint(9,1150,0.3);
      
      licuts[i]->SetPoint(10,720,0.27);
      licuts[i]->SetPoint(11,720,0.16);
    }
    else if (i == 2) {
    //else {
      licuts[i] = new TCutG(Form("mycut %d",i),5); 
      licuts[i]->SetVarX("eL");  
      licuts[i]->SetVarY("eTail");
      licuts[i]->SetPoint(0,720,0.11);
      licuts[i]->SetPoint(1,820,0.115);
      
      licuts[i]->SetPoint(2,1150,0.14);
      licuts[i]->SetPoint(3,1690,0.18);
      licuts[i]->SetPoint(4,2200,0.26);
      licuts[i]->SetPoint(5,2200,0.31);
      licuts[i]->SetPoint(6,1700,0.24);
      licuts[i]->SetPoint(7,1150,0.21);
      
      licuts[i]->SetPoint(8,720,0.23);
      licuts[i]->SetPoint(9,720,0.11);  
    }
    else if (i == 15) {
      licuts[i] = new TCutG(Form("mycut %d",i),5); 
      licuts[i]->SetVarX("eL");  
      licuts[i]->SetVarY("eTail");
      licuts[i]->SetPoint(0,720,0.11);
      licuts[i]->SetPoint(1,820,0.115);
      
      licuts[i]->SetPoint(2,1150,0.14);
      licuts[i]->SetPoint(3,1690,0.21);
      licuts[i]->SetPoint(4,2200,0.29);
      licuts[i]->SetPoint(5,2700,0.36);
      licuts[i]->SetPoint(6,2700,0.4);
      licuts[i]->SetPoint(7,2200,0.35);
      licuts[i]->SetPoint(8,1700,0.27);
      licuts[i]->SetPoint(9,1150,0.21);
      
      licuts[i]->SetPoint(10,720,0.23);
      licuts[i]->SetPoint(11,720,0.11);  
    }
    else {
      licuts[i] = new TCutG(Form("mycut %d",i),5); 
      licuts[i]->SetVarX("eL");  
      licuts[i]->SetVarY("eTail");
      licuts[i]->SetPoint(0,720,0.11);
      licuts[i]->SetPoint(1,820,0.115);
      
      licuts[i]->SetPoint(2,1150,0.14);
      licuts[i]->SetPoint(3,1690,0.21);
      licuts[i]->SetPoint(4,2200,0.29);
      licuts[i]->SetPoint(5,2700,0.36);
      licuts[i]->SetPoint(6,2700,0.4);
      licuts[i]->SetPoint(7,2200,0.35);
      licuts[i]->SetPoint(8,1700,0.27);
      licuts[i]->SetPoint(9,1150,0.21);
      
      licuts[i]->SetPoint(10,720,0.23);
      licuts[i]->SetPoint(11,720,0.11);  
    }
  }
}

#endif