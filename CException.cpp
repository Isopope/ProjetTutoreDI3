#include "CException.h"

int CException::EXClireValeur() const
{
    return iEXCvaleur;
}

string CException::EXClireMessage() const
{
    return sEXCmessage;
}

void CException::EXCModifiervaleur(int inewvaleur)
{
    iEXCvaleur = inewvaleur;
}

void CException::EXCModifierMessage(string snewmessage)
{
    sEXCmessage = snewmessage;
}
