#pragma once
#include <iostream>
#include "sstream"
#include "fstream"
#include "iomanip"
using namespace std;
bool ImportData(const string& percorso_file, double& S, size_t& n,  double*& w, double*& r);
/* restituisce true se il file è stato aperto correttamente, false altrimenti. Inoltre, nel caso l'apertura avvenga in modo corretto legge i dati di input
salvando i valori di S ed n, e costruendo gli array w e r*/

double FinalValue(const double& S, const size_t& n, const double* const& w, const double* const& r);
// restituisce il valore finale del portfolio, secondo la formula fornita nel testo V = (1+r)s, tenendo conto della diversificazione degli investimenti  

double RateOfReturn(double& S, double& v);
// restituisce il tasso di rendimento degli investimenti del portfolio calcolandolo mediante la formula inversa a quella fornita

bool ExportData(const string& percorso_file, const double& S, const size_t& n, const double* const& w, const double* const& r, const double& FinalValue,const double& RateOfReturn);
/* restituisce true se il file è stato aperto correttamente, false altrimenti. Inoltre, nel caso l'apertura avvenga in modo corretto scrive i dati di output
secondo il formato di stampa richiesto*/

string printArray (const size_t& n, const double* const& a);
/* (simile alla funzione creata ad esercitazione) restituisce i valori dell'array in formato di stringa su un'unica riga e secondo il formato richiesto*/