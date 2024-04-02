#include "CSommet.h"

string CSommet::SOMLireNumeroSommet() const
{
    return sSOMnumeroSommet;
}

void CSommet::SOMModifierNumeroSommet(const string sParam)
{
    sSOMnumeroSommet = sParam;
}

vector<CArc*>& CSommet::SOMLirevecteurArcEntrant()
{
    return vSOMlisteArcEntrant;
}

vector<CArc*>& CSommet::SOMLirevecteurArcPartant()
{
    return vSOMlisteArcPartant;
}

void CSommet::SOMAjouterArcPartant(CArc* ARCParam)
{
    if (ARCParam->ARCLireDepart() == sSOMnumeroSommet) {
        vSOMlisteArcPartant.push_back(ARCParam);
    }
}

void CSommet::SOMAjouterArcEntrant(CArc* ARCParam)
{
    if (ARCParam->ARCLireArrive() == sSOMnumeroSommet) {
        vSOMlisteArcEntrant.push_back(ARCParam);
    }

}


void CSommet::SOMAfficherSommet()
{
    for (vARCSOMIterator = vSOMlisteArcPartant.begin(); vARCSOMIterator != vSOMlisteArcPartant.end(); vARCSOMIterator++) {
        cout <<"partie partante "<< (*vARCSOMIterator)->ARCLireDepart()<<(*vARCSOMIterator)->ARCLireArrive() << endl;
    }

    for (vARCSOMIterator = vSOMlisteArcEntrant.begin(); vARCSOMIterator != vSOMlisteArcEntrant.end(); vARCSOMIterator++) {
        cout <<"partie entrante " << (*vARCSOMIterator)->ARCLireDepart() << (*vARCSOMIterator)->ARCLireArrive() << endl;
    }
}

bool CSommet::SOMArcEstDansListePartant(const string sNumSommetarrive)
{
    if (SOMArcPresentDansListePartant(sNumSommetarrive)) {
        return true;
    }
    else {
        return false;
    }
}

CArc* CSommet::SOMArcPresentDansListePartant(const string sNumSommetarrive)
{
    for (vARCSOMIterator = vSOMlisteArcPartant.begin(); vARCSOMIterator != vSOMlisteArcPartant.end(); vARCSOMIterator++) {
        if ((*vARCSOMIterator)->ARCLireArrive() == sNumSommetarrive) {
           return (*vARCSOMIterator);
        }
    }
    return nullptr;
}
