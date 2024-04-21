#ifndef __UTILS_H
#define __UTILS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;


//funzione per leggere i dati dal file

bool readFile(const string& inputFile, double& S, size_t& n, double*& w, double*& r);


//funzione per il calcolo dei nuovi valori

double FinalRate(const size_t& n, const double* const& w, const double* const& r);


//funzione per export

bool ExportResult(const string& outputFile, const double& S, const size_t& n, const double* const& w, const double* const& r, const double& finalRate, const double& Sfinale);


//trasformazione da un array a una stringa

string ArrayToString(const size_t& n, const double* const& w);

#endif
