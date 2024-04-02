#pragma once
#include<string>
#include<iostream>
#include"CException.h"
using namespace std;
class CArc
{
private:
	string sARCSommetDepart;
	string sARCSommetArrive;
public:
	//! @brief constructeur de comfort permettant de creer des arcs avec des valeurs pour les attribut de depart de d'arrive
	//! @param string sarrive 
	//! @param string sdepart 
	//! @return rien
	CArc(string sarrive, string sdepart) :sARCSommetDepart(sdepart), sARCSommetArrive(sarrive) {};
	//! @brief constructeur de comfort permettant de crer un arc avec juste le sommet d'arrive, celui du depart dependant du sommet sur lequel il est appelé
	//! @param string sarrive
	//! return rien 
	explicit CArc(string sarrive) :sARCSommetArrive(sarrive) {};
	//! @brief accesseur direct en lecture de sARCSommetDepart
	//! @return la valeur actuel de sARCSommetDepart
	string ARCLireDepart()const;
	//! @brief accesseur direct en lecture de sARCSommetArrive
	//! @return la valeur actuel de sARCSommetArrive
	string ARCLireArrive()const;
	//! @brief accesseur direct en ecriture de sARCSommetDepart
	//! @param string sdepart 
	//! sortie: sARCSommetDepart prend la valeur de sdepart
	void ARCModifierDepart(string sdepart);
	//! @brief accesseur direct en ecriture de sARCSommetArrive
	//! @param string sarrive 
	//! sortie sARCSommetArrive prend la valeur de sarrive
	void ARCModifierArrive(string sarrive);
	//! @brief permet de savoir si un arc est reflexif
	//! @return true si reflexif , false sinon
	bool ARCEstReflexive();

};

