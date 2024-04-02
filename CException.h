#pragma once
#include<iostream>
#include<string>
using namespace std;
class CException
{
private:
	int iEXCvaleur;
	string sEXCmessage;
public:
	CException() {};
	CException(int ivaleur, string smessage) :iEXCvaleur(ivaleur), sEXCmessage(smessage) {};
	int EXClireValeur()const;
	string EXClireMessage()const;
	void EXCModifiervaleur(int inewvaleur);
	void EXCModifierMessage(string snewmessage);

};

