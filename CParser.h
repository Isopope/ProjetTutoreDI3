#pragma once
#include<fstream>
#include<string>
#include"CException.h"
#define OUVERTURE_IMPOSSIBLE -2
using namespace std;
class CParser
{
private:
	string PARScheminFichier;
	string PARScontenuFichier;
public:
	CParser(string cheminfichier) :PARScheminFichier(cheminfichier) {
		ifstream FILmonfichier(PARScheminFichier);
		if (!FILmonfichier.is_open()) {
			CException EXCexception;
			EXCexception.EXCModifiervaleur(OUVERTURE_IMPOSSIBLE);
			EXCexception.EXCModifierMessage("chemin invalide ou ouverture du fichier impossible");
			throw EXCexception;

		}
		while (getline(FILmonfichier, PARScontenuFichier)) {
			cout<< PARScontenuFichier;
		}
		FILmonfichier.close();
	};

	string PARSlirecontenuFichier()const;

};

