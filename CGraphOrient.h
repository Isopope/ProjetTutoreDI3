#pragma once
#include"CException.h"
#include<iostream>
#include<string>
#include<vector>
#define SOMMET_DUPLIQUER -4
#define SOMMET_INEXISTANT -5
#define ARC_INEXISTANT -6
#define ARC_DUPLIQUER -1
using namespace std;


//NOTE: et si if(arc.destination==sommet.nom) je remplis dans sommet liste arc entrant listeSOMArcEntrant
// 
// 
//NOTE: au fur et a mesure que je lis le fichier 
// -je cree les sommet en fonction des noms present dans le fichier
// -je cree les arcs en fonction des debut et fin
// - ensuite je les ajoutes dans les tableaux respectifs de CGraphOrient
// - ensuite grace a des if je cree de facon complete les sommet en leurs ajoutant la liste des arcs partant 
//- ex: dans une boucle for je fais un if(arc.depart==sommet.courant et (dest !=sommetcourant ou = sommet.courant)) alors je met les arc dans le listeSOmmetArcPartant
template <typename TArc, typename TSommet> class CGraphOrient
{
private:
	vector<TSommet*>vGPOlisteSommet;
	vector<TArc*>vGPOlisteArc;
	//le mot template me permet de savoir que l'iterateur sera adapte au type de TSommet
	typename vector<TSommet*>::iterator vSOMiterator;
	typename vector<TArc*>::iterator vARCiterator;
public:
	//! @brief constructeur de comfort permettant de creer un graphe en lui passant le chemin du fichier.txt
	//! @param string sFILPath chemin absolu vers le fichier.txt
	//CGraphOrient(string sFILPath);
	//! @brief fonction permettant d'ajouter un sommet dans vGPOlisteSommet
	//! necessite:rien
	//! entraine: cree un sommet et l'ajoute à vGPOlisteSommet
	//! @param string snumsommet numero du sommet
	//! sortie: rien
	void GPOAjouterSommet(string snumsommet);
	//! @brief fonction permettant de modifier le nom du sommet, cela se repercute dans les vGPOlisteArc et vSOMlistePartant et vSOMlisteEntrant
	//! precondition: le nouveau nom ne doit appartenir à aucun nom existant dans le graphe, l'ancien nom doit appartenir a un sommet present dans le graphe
	//! postcondition: tout les cas anormaux mais previsible de realisation sont gerés
	//! entraine: la modficiation du sSOMnumsommet par snouveaunom
	//! @param string sanciennumsommet 
	//! @param string snouveaunumsommet 
	void GPOModifierSommet(const string sanciennumsommet,const string snouveaunumsommet);
	//! @brief fonction permettant de supprimer un sommet en fonction de son snumsommet, la suppression du sommet implique la suppression des arcs qui lui sont associé
	//! necessite rien
	//! postcondition la fonction leve une exception si le sommet à supprimer n'existe pas 
	//! @param string snumsommet le nom du sommet à supprimer 
	void GPOSupprimerSommet(const string snumsommet);
	//! @brief fonction permettant d'ajouter un arc dans vGPOlisteArc
	//! necessite: que les sommets correspondant à sdepart et sarrive soient deja creer sinon exception levé
	//! necessite:que l'arc n'existe pas encore dans vGPOlisteArc
	//! entraine: ajout de l'arc dans vGPOlisteArc si toutes les condition sont reunis
	//! @param string sdepart 
	//! @param string sarrive 
	virtual void GPOAjouterArc(string sdepart, string sarrive);
	//! @brief fonction permettant de suprrimer un arc
	//! @param string sdepart 
	//! @param string sarrive 
	//! retourne : rien
	//! entraine: l'arc correspondant à sdepart et sarrive est supprimer de vSOMListeArcPartant de sdepart et de vSOMListeArcEntrant de sarrive
	//! note: cette fonction peut lever une exception si l'arc n'existe pas
	void GPOSupprimerArc(string sdepart, string sarrive);
	void GPOModifierArc(string sdepart, string sarrive,string snouveaudepart, string snouvelarrive);
	//! @brief afficher un graphe 
	//! necessite rien
	//! sortie rien
	void GPOAfficherGraphe();
	//! @brief permet de savoir si un sommet est present dans vGPOlisteSommet
	//! @param string snumsommet 
	//! @return pointeur sur le sommet sinon nullptr
	TSommet* GPOPresentDansListeSommet(string snumsommet);
	//! @brief retoure true ou false si le sommet est present dans vGPOlisteSommet
	//! @param string snumsommet 
	//! @return true si le sommet est present , false sinon
	bool GPODansListeSommet(string snumsommet);
	//! @brief fonction permettant de verifier si un arc existe dans vGPOlisteArc
	//! @param string snumsommetdepart 
	//! @param string snumsommetarrive 
	//! @return retourne un pointeur TArc* si l'arc existe , nullptr sinon 
	TArc* GPOPresentDansListeArc(string snumsommetdepart, string snumsommetarrive);
	//! @brief fonction permettant de savoir si l'arc existe dans vGPOlisteArc
	//! @param string snumsommetdepart 
	//! @param string snumsommetarrive 
	//! @return true si l'arc existe, false sinon
	bool GPODansListeArc(string snumsommetdepart, string snumsommetarrive);

};


template<typename TArc, typename TSommet>
inline void CGraphOrient<TArc, TSommet>::GPOAjouterSommet(string snumsommet)
{
	//deja testé  fonctionne
	
	for (vSOMiterator = vGPOlisteSommet.begin(); vSOMiterator != vGPOlisteSommet.end();) {
		if ((*vSOMiterator)->SOMLireNumeroSommet() == snumsommet) {
			//lever exception duplication de sommet
			CException EXCexception;
			EXCexception.EXCModifiervaleur(SOMMET_DUPLIQUER);
			EXCexception.EXCModifierMessage("duplication.... il exise deja un sommet de meme nom");
			throw EXCexception;
			//break;
		}
		else {
			vSOMiterator++;
		}
	}
	
	if (vSOMiterator == vGPOlisteSommet.end()) {
		TSommet *sommetparam=new TSommet(snumsommet);
		vGPOlisteSommet.push_back(sommetparam);
	}
	
}

template<typename TArc, typename TSommet>
inline void CGraphOrient<TArc, TSommet>::GPOModifierSommet(const string sanciennumsommet, const string snouveaunumsommet)
{
	//testé et fonctionne
	TSommet* tsommet = GPOPresentDansListeSommet(sanciennumsommet);
	//je verifie que le sommet est bien present et que le snouveaunumsommet n'appartient à aucun sommet
	if (tsommet and !GPODansListeSommet(snouveaunumsommet)){
		tsommet->SOMModifierNumeroSommet(snouveaunumsommet);

		//changement dans GPOlisteArc;
		for (vARCiterator = vGPOlisteArc.begin(); vARCiterator != vGPOlisteArc.end(); vARCiterator++) {
			if ((*vARCiterator)->ARCLireDepart() == sanciennumsommet) {
				(*vARCiterator)->ARCModifierDepart(snouveaunumsommet);
			}
			if ((*vARCiterator)->ARCLireArrive() == sanciennumsommet) {
				(*vARCiterator)->ARCModifierArrive(snouveaunumsommet);
			}
		}

		//changement dans ARClistePartant
		/*for (vARCiterator = tsommet->SOMLirevecteurArcPartant().begin(); vARCiterator != tsommet->SOMLirevecteurArcPartant().end(); vARCiterator++) {
			(*vARCiterator)->ARCModifierDepart(snouveaunumsommet);
		}
		

		//changement dans ARClisteEntrant
		for (vARCiterator = tsommet->SOMLirevecteurArcEntrant().begin(); vARCiterator != tsommet->SOMLirevecteurArcEntrant().end(); vARCiterator++) {
			(*vARCiterator)->ARCModifierArrive(snouveaunumsommet);
		}*/
	}
	else {
		CException EXCexception;
		EXCexception.EXCModifiervaleur(SOMMET_INEXISTANT);
		EXCexception.EXCModifierMessage("le sommet que vous voulez modifier est inexistant ou le nouveau nom est deja utilisé par un autre sommet");
		throw EXCexception;
	}
}

template<typename TArc, typename TSommet>
inline void CGraphOrient<TArc, TSommet>::GPOSupprimerSommet(const string snumsommet)
{
	//deja testé et fonctionne
	TSommet* tsommet = GPOPresentDansListeSommet(snumsommet);
	if (tsommet) {
		//suppression dans vSOMlisteArcEntrant et dans vSOMlisteArcPoartant
		for (vSOMiterator = vGPOlisteSommet.begin(); vSOMiterator != vGPOlisteSommet.end(); vSOMiterator++) {
			for (vARCiterator = (*vSOMiterator)->SOMLirevecteurArcEntrant().begin(); vARCiterator != (*vSOMiterator)->SOMLirevecteurArcEntrant().end();) {
				if ((*vARCiterator)->ARCLireDepart() == snumsommet) {
					vARCiterator=(*vSOMiterator)->SOMLirevecteurArcEntrant().erase(vARCiterator);
				}
				else {
					vARCiterator++;
				}
			}
			for (vARCiterator = (*vSOMiterator)->SOMLirevecteurArcPartant().begin(); vARCiterator != (*vSOMiterator)->SOMLirevecteurArcPartant().end();) {
				if ((*vARCiterator)->ARCLireArrive() == snumsommet) {
					vARCiterator=(*vSOMiterator)->SOMLirevecteurArcPartant().erase(vARCiterator);
				}
				else {
					vARCiterator++;
				}
			}
		}
		//suppression dans GPOlisteArc
		for (vARCiterator = vGPOlisteArc.begin(); vARCiterator != vGPOlisteArc.end();) {
			if ((*vARCiterator)->ARCLireArrive() == snumsommet || (*vARCiterator)->ARCLireDepart()==snumsommet) {
				vARCiterator = vGPOlisteArc.erase(vARCiterator);
			}
			else {
				vARCiterator++;
			}
		}

		//supression du sommet lui meme
		for (vSOMiterator = vGPOlisteSommet.begin(); vSOMiterator != vGPOlisteSommet.end();) {
			if ((*vSOMiterator)->SOMLireNumeroSommet() == snumsommet) {
				break;
			}
			else {
				vSOMiterator++;
			}
		}
		vGPOlisteSommet.erase(vSOMiterator);
	}
	else {
		CException EXCexception;
		EXCexception.EXCModifiervaleur(SOMMET_INEXISTANT);
		EXCexception.EXCModifierMessage("le sommet que vous voulez supprimer est inexistant ");
		throw EXCexception;
	}
}

template<typename TArc, typename TSommet>
inline void CGraphOrient<TArc, TSommet>::GPOAjouterArc(string sdepart, string sarrive)
{
	//deja teste fonctionne
	// je verifie si les sommets de depart et de destinations existe bien
	if (!GPODansListeSommet(sdepart) || !GPODansListeSommet(sarrive)) {
		CException EXCexception;
		EXCexception.EXCModifiervaleur(SOMMET_INEXISTANT);
		EXCexception.EXCModifierMessage("sommet de depart ou de destination introuvable");
		throw EXCexception;
	}
	
	// je verifie qu'il n'y a pas de doublon c'est a dire qu'il n'existe pas deja un arc avec les meme sommetdepart et le meme sommet arrive
	for (vARCiterator = vGPOlisteArc.begin(); vARCiterator != vGPOlisteArc.end();) {
		if ((*vARCiterator)->ARCLireDepart() == sdepart and (*vARCiterator)->ARCLireArrive() == sarrive) {
			CException EXCexception;
			EXCexception.EXCModifiervaleur(ARC_DUPLIQUER);
			EXCexception.EXCModifierMessage("duplication il exise deja un arc ayant le meme depart et la meme arrive");
			throw EXCexception;
		}
		else {
			vARCiterator++;
		}
		
	}

	//apres avoir verifier si les sommet existe bel et bien et qu'il n'existe aucun arc avec les meme parametre je cree l'objet arcparam que j'insere
	
	if (vARCiterator == vGPOlisteArc.end() ) {
		TArc *arcparam=new TArc(sarrive, sdepart);
		vGPOlisteArc.push_back(arcparam);

		//ici en fonction des conditions if j'insere l'arc dans le tableau ARCPartant ou ARCEntrant d'un sommet
		for (vSOMiterator = vGPOlisteSommet.begin(); vSOMiterator != vGPOlisteSommet.end();vSOMiterator++) {
			if (arcparam->ARCLireArrive() == (*vSOMiterator)->SOMLireNumeroSommet()) {
				(*vSOMiterator)->SOMAjouterArcEntrant(arcparam);
			}
			if (arcparam->ARCLireDepart() == (*vSOMiterator)->SOMLireNumeroSommet()) {
				(*vSOMiterator)->SOMAjouterArcPartant(arcparam);
			}
		}
	}
	
}

template<typename TArc, typename TSommet>
inline void CGraphOrient<TArc, TSommet>::GPOSupprimerArc(string sdepart, string sarrive)
{
	//tester et fonctionne egalement tester avec les arcs reflexifs
	//je verifie si l'arc existe dans GPOListeArcs, je supprime l'arc dans vSOMArcPartant de sdepart et dans vSOMArcEntrant de sarrive
	if (GPODansListeArc(sdepart, sarrive)) {
		TSommet* tsommet = GPOPresentDansListeSommet(sdepart);
		for (vARCiterator = tsommet->SOMLirevecteurArcPartant().begin(); vARCiterator != tsommet->SOMLirevecteurArcPartant().end();) {
			if ((*vARCiterator)->ARCLireDepart() == sdepart and (*vARCiterator)->ARCLireArrive()==sarrive) {
				vARCiterator = tsommet->SOMLirevecteurArcPartant().erase(vARCiterator);
			}
			else {
				vARCiterator++;
			}
		}
		TSommet* tsommetarrive = GPOPresentDansListeSommet(sarrive);
		for (vARCiterator = tsommetarrive->SOMLirevecteurArcEntrant().begin(); vARCiterator != tsommetarrive->SOMLirevecteurArcEntrant().end();) {
			if ((*vARCiterator)->ARCLireArrive() == sarrive and (*vARCiterator)->ARCLireDepart()==sdepart) {
				vARCiterator = tsommetarrive->SOMLirevecteurArcEntrant().erase(vARCiterator);
			}
			else {
				vARCiterator++;
			}
		}
		// je supprime dans vGPOlisteArc
		for (vARCiterator = vGPOlisteArc.begin(); vARCiterator != vGPOlisteArc.end();) {
			if ((*vARCiterator)->ARCLireArrive() == sarrive and (*vARCiterator)->ARCLireDepart() == sdepart) {
				vARCiterator = vGPOlisteArc.erase(vARCiterator);
			}
			else {
				vARCiterator++;
			}
		}

	}
	else {
		CException EXCexception;
		EXCexception.EXCModifiervaleur(ARC_INEXISTANT);
		EXCexception.EXCModifierMessage("l'arc que vous voulez supprimer est inexistant ");
		throw EXCexception;
	}
}

template<typename TArc, typename TSommet>
inline void CGraphOrient<TArc, TSommet>::GPOModifierArc(string sdepart, string sarrive, string snouveaudepart, string snouvelarrive)
{
	TArc* tarc = GPOPresentDansListeArc(sdepart, sarrive);
	if (tarc and (GPODansListeSommet(snouveaudepart) and GPODansListeSommet(snouvelarrive)) ) {
		tarc->ARCModifierDepart(snouveaudepart);
		tarc->ARCModifierArrive(snouvelarrive);


	}
	else {
		CException EXCexception;
		EXCexception.EXCModifiervaleur(SOMMET_INEXISTANT);
		EXCexception.EXCModifierMessage("l'un des nouveaux sommet ou les deux sont inexistant OU l'arc que voulez modifier est inexistantes ");
		throw EXCexception;
	}
}

template<typename TArc, typename TSommet>
inline void CGraphOrient<TArc, TSommet>::GPOAfficherGraphe()
{
	//fonction a modifier plus tard pour un bon affichage
	for (vSOMiterator = vGPOlisteSommet.begin(); vSOMiterator != vGPOlisteSommet.end(); vSOMiterator++) {
		cout <<"le nom du sommet est: "<<(*vSOMiterator)->SOMLireNumeroSommet() << endl;
		(*vSOMiterator)->SOMAfficherSommet();
	}
}

template<typename TArc, typename TSommet>
inline TSommet* CGraphOrient<TArc, TSommet>::GPOPresentDansListeSommet(string snumsommet)
{
	//deja teste fonctionne
	for (vSOMiterator = vGPOlisteSommet.begin(); vSOMiterator != vGPOlisteSommet.end(); vSOMiterator++) {
		if ((*vSOMiterator)->SOMLireNumeroSommet() == snumsommet) {
			return (*vSOMiterator);
		}
	}
	return nullptr;
}

template<typename TArc, typename TSommet>
inline bool CGraphOrient<TArc, TSommet>::GPODansListeSommet(string snumsommet)
{
	//deja teste fonctionne
	if (GPOPresentDansListeSommet(snumsommet)) {
		return true;
	}
	return false;
}

template<typename TArc, typename TSommet>
inline TArc* CGraphOrient<TArc, TSommet>::GPOPresentDansListeArc(string snumsommetdepart, string snumsommetarrive)
{
	//testé et fonctionne
	for (vARCiterator = vGPOlisteArc.begin(); vARCiterator != vGPOlisteArc.end(); vARCiterator++) {
		if ((*vARCiterator)->ARCLireDepart() == snumsommetdepart and (*vARCiterator)->ARCLireArrive() == snumsommetarrive) {
			return (*vARCiterator);
		}
	}
	return nullptr;
}

template<typename TArc, typename TSommet>
inline bool CGraphOrient<TArc, TSommet>::GPODansListeArc(string snumsommetdepart, string snumsommetarrive)
{
	//testé et fonctionne
	if (GPOPresentDansListeArc(snumsommetdepart, snumsommetarrive)) {
		return true;
	}
	return false;
}
