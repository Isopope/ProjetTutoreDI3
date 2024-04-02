#pragma once
#include<string.h>
#include<iostream>
#include<vector>
#include"CArc.h"
#include"CException.h"
#define ARC_DUPLIQUER -1
#define ARC_DEPART_NON_CONFORME -2

using namespace std;
class CSommet
{
private:
	string sSOMnumeroSommet;
	vector<CArc*> vSOMlisteArcPartant;
	vector<CArc*> vSOMlisteArcEntrant;
	vector<CArc*>::iterator vARCSOMIterator;
public:
	//! @brief constructeur de confort permettant de creer un CSommet juste en ayant son nom
	//! @param string snom 
	//! @return rien
	explicit CSommet(string snom) :sSOMnumeroSommet(snom) {};

	//! @brief accesseur en lecture de l'attribut sSOMnumeroSommet
	//! @return la valeur actuel de sSOMnumeroSommet
	string SOMLireNumeroSommet() const;
	void SOMModifierNumeroSommet(const string sParam);
	vector<CArc*>& SOMLirevecteurArcEntrant();
	vector<CArc*>& SOMLirevecteurArcPartant();


	//! @brief fonction permettant d'ajouter un arc dans vSOMlisteArcPartant
	//! @param CArc &ARCParam 
	//! @return rien
	void SOMAjouterArcPartant(CArc *ARCParam);
	void SOMAjouterArcEntrant(CArc *ARCParam);
	void SOMModifierArcPartant(const string sAncienNumSommet, const string sNouveauNumSommet);
	void SOMModifierArcEntrant(const string sAncienNumSommet, const string sNouveauNumSommet);
	void SOMSupprimerArcEntrant(const string sNumSommet);
	void SOMSupprimerArcPartant(const string sNumSommetarrive);
	void SOMAfficherSommet();
	//! @brief fonction permettant de savoir si un arc se trouve deja dans la SOMListeArcPartant
	//! @param string sNumSommetarrive defini le nom du sommet d'arrive
	//! @return true si l'arc est trouvé false sinon
	bool SOMArcEstDansListePartant(const string sNumSommetarrive);
	//! @brief fonction permettant de savoir si un arc se trouve deja dans la SOMListeArcPartant
	//! @param string sNumSommetarrive defini le nom du sommet d'arrive
	//! @return un pointeur sur l'arc si il existe  , nullptr si l'arc n'existe pas dans SOMlisteArcPartant
	CArc* SOMArcPresentDansListePartant(const string sNumSommetarrive);

};

