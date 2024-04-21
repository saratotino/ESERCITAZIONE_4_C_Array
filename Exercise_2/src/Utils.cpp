#include "Utils.hpp"
#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>


using namespace std;


//leggere file

bool readFile(const string& inputFile, double& S, size_t& n, double*& w, double*& r)
{
    // Open File
    ifstream file;
    file.open(inputFile);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    string line;

    getline(file, line);

    istringstream val1(line);
    char temp1;
    val1 >> temp1 >> temp1 >> S;


    getline(file, line);

    istringstream val2(line);
    char temp2;
    val2 >> temp2 >> temp2 >> n;

    getline(file, line);

    w = new double[n];
    r = new double[n];

    unsigned int i = 0;

    while (getline(file, line))
    {
        istringstream val3(line);
        char temp3;
        val3 >> w[i] >> temp3 >> r[i];

        i++;
    }

    file.close();

    return true;


}



//calcolare w e r

double FinalRate(const size_t& n, const double* const& w, const double* const& r)
{
    double finalRate = 0;

    for (unsigned int i = 0; i < n; i++)
        finalRate += w[i] * r[i];

    return finalRate;

}




// stampare in un altro file

bool ExportResult(const string& outputFile, const double& S, const size_t& n, const double* const& w, const double* const& r, const double& finalRate, const double& Sfinale)
{

    ofstream file;
    file.open(outputFile);

    if (file.fail())
    {
        cerr << "file open failed" << endl;
        return false;
    }

    file << "S = " << fixed << setprecision(2) << S <<"," << " n = " << n << endl;

    file << "w = [ ";

    for (unsigned int i = 0; i < n; ++i)
    {
        file << w[i];
        if (i < n - 1)
        {
            file << " ";
        }
    }
    file << " ]" << endl;

    file << "r = [ ";

    for (unsigned int i = 0; i < n; ++i)
    {
        file << r[i];
        if (i < n - 1)
        {
            file << " ";
        }
    }

    file << " ]" << endl;


    file << "Rate of return of the portfolio: " << setprecision(4) << finalRate << endl;
    file  << "V: " << setprecision(2) << Sfinale << endl;


    file.close();

    return true;
}



//trasformazione dell'array

string ArrayToString(const size_t& n, const double* const& w)
{
    string str;
    ostringstream toString;

    toString << "[ ";

    for (unsigned int i = 0; i < n; i++)
        toString<< w[i]<< " ";

    toString << "]";

    return toString.str();
}





