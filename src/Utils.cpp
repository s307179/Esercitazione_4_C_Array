#include "Utils.hpp"
using namespace std;

bool ImportData(const string& inputFilePath, double& S, size_t& n, double*& w, double*& r)
{
	ifstream ifile;
	ifile.open(inputFilePath);
	if (ifile.fail())
	{
		cerr<< "tentativo di apertura del file fallito"<< endl;
		return false;
	}
	// definisco un carattere che utilizzerò come "cestino" per tutti i dati che non devo salvare
	char garbage;
	//leggo le prime due righe e salvo solo l'ultimo dato per ogni riga
	for (unsigned int i =0; i<6;i++)
	{	switch (i) {
		case 0:case 1:case 3:case 4:
		ifile >> garbage;
		break;
		case 2:
		ifile >> S;
		break;
		case 5:
		ifile >>n;
		break;
	}}
	// elimino il carattere vuoto a fine riga
	string emptyspace;
	getline(ifile,emptyspace); 
	// elimino la riga di intestazione "w;r"
	string line;
	getline(ifile,line);
	// conoscendo ora la lunghezza degli array alloco la memoria richiesta (pari ad n) per entrambi
	w = new double[n];
	r = new double[n];
	for (unsigned int i=0;i<n;i++)
	{	ifile>> w[i] ;
		ifile >> garbage; // cestino il delimitatore
		ifile>> r[i] ; 
	}
	ifile.close();
	return true;
	
}


double FinalValue(const double& S, const size_t& n, const double* const& w, const double* const& r)
{
	double fv;
	for (unsigned int i=0;i<n;i++)
	{
		fv += (1+r[i])*S*w[i];
	}
	return fv;
}

double RateOfReturn(double& S, double& fv)
{
	double ror = fv/S -1 ;
	return ror;
}

string printArray (const size_t& n, const double* const& a)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)
        toString<< a[i]<< " ";
    toString << "]";

    return toString.str();
}


bool ExportData(const string& outputFilePath, const double& S, const size_t& n, const double* const& w, const double* const& r, const double& fv,const double& ror)
{
	ofstream ofile;
	ofile.open(outputFilePath);
	if (ofile.fail())
	{
		cerr<< "tentativo di apertura del file fallito"<< endl;
		return false;
	}
	ofile << "S = "<<fixed <<setprecision(2)<< S <<  ", n = " <<n<<endl;
	ofile << "w = ";
	ofile << printArray(n,w);
	ofile <<endl;
	ofile << "r = ";
	ofile << printArray(n,r);
	ofile <<endl;
	ofile<< "Rate of return of the portfolio: "<<setprecision(4)<< ror<<endl;
	ofile<< "V: " <<fixed << setprecision(2)<< fv<<endl;
	ofile.close();
	
	return true;
	
}


