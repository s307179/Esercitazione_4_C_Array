#include "Utils.hpp"

using namespace std;

int main()
{
	string ifile = "./data.txt";  
	double S = 0; 
    size_t n = 0;
    double* w = nullptr;
    double* r = nullptr;
    if (!ImportData(ifile, S, n, w,r))  
    {
        cerr<< "Errore nell'apertura del file"<< endl;
        return -1;
    }
    else
	{
		cout<< "Importato con successo : "<<endl;
		cout << "S = "<<fixed << setprecision(2)<< S <<  ", n = " <<n<<endl;
		cout << "w = ";
		cout << printArray(n,w);
		cout <<endl;
		cout << "r = ";
		cout << printArray(n,r);
		cout <<endl;
	double fv ;
	fv = FinalValue(S,n,w,r);
	double ror;
	ror = RateOfReturn(S,fv);
	string ofile = "./result.txt";  
    if (!ExportData(ofile, S, n, w,r,fv,ror))  
    {
        cerr<< "Errore nell'apertura del file"<< endl;
        return -1;
    }
	else
	{	cout<< "Esportato con successo :"<< endl;
		cout<< "Rate of return of the portfolio: "<<setprecision(4)<< ror<<endl;
		cout<< "V: " <<fixed << setprecision(2)<< fv<<endl;}
    delete[] w; 
    delete[] r;
    return 0;
	}
}

