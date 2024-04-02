#include "CArc.h"

string CArc::ARCLireDepart() const
{
    return sARCSommetDepart;
}

string CArc::ARCLireArrive() const
{
    return sARCSommetArrive;
}

void CArc::ARCModifierDepart(string sdepart)
{
    sARCSommetDepart = sdepart;
}

void CArc::ARCModifierArrive(string sarrive)
{
    sARCSommetArrive = sarrive;
}

bool CArc::ARCEstReflexive()
{
    //je vais ajouter une condi ternaire :)
    if (sARCSommetArrive == sARCSommetDepart) {
        return true;
    }
    return false;
}
