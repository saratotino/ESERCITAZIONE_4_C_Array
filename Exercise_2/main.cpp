#include "Utils.hpp"

int main()
{
    string inputFileName = "data.csv";

    double S = 0;
    size_t n = 0;
    double* w = nullptr;
    double* r = nullptr;


    if (!readFile(inputFileName, S, n, w, r))
    {
        cerr<< "Something goes wrong with import"<< endl;

        return -1;
    }

    else
    {
        cout << "Import successful: S = " << fixed << setprecision(2) << S <<", n = " << n << endl;
        cout << " w = "<< ArrayToString(n, w) << endl;
        cout << " r = "<< ArrayToString(n, r) << endl;
    }


    double finalRate = FinalRate(n, w, r);
    double Sfinale = (1 + finalRate) * S;

    cout << setprecision(4) <<"Rate of return of the portfolio: "<< finalRate << endl;
    cout <<setprecision(2) << "V: " << Sfinale << endl;

    string outputFileName = "C:/Users/utente/Desktop/ESERCITAZIONE_4_C_Array/Esercitazione_4_C_Array/Exercise_2/result.txt"; //sostituire con il proprio percorso file.

    if (!ExportResult(outputFileName, S, n, w, r, finalRate, Sfinale))
    {
        cerr<< "Something goes wrong with export"<< endl;
        return -1;
    }

    else
        cout<< "Export successful"<< endl;


    delete[] w;
    delete[] r;


    return 0;
}



