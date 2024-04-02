// ProjetTutore.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include"CArc.h"
#include"CSommet.h"
#include"CGraphOrient.h"
#include"CException.h"
#include"CParser.h"

int main()
{
    std::cout << "Hello World!\n";
    /*CSommet sommeta("a");
    CSommet sommetb("b");
    CSommet sommetc("c");
    CSommet sommetd("d");
    CArc arcab("a", "b");
    CArc arcbc("b", "c");
    CArc arccd("c", "d");
    CArc arcbd("b", "d");
    CArc arcad("a", "d");
    CArc arcda("a", "d");

    
    //sommetb.SOMAjouterArcPartant(arcbc);
    //sommetb.SOMAjouterArcPartant(arcbd);
    sommetc.SOMAjouterArcEntrant(arcbc);
    sommeta.SOMAjouterArcPartant(arcad);
    sommeta.SOMAjouterArcPartant(sommetb);
    sommeta.SOMAjouterArcEntrant(arcda);
    //sommeta.SOMAfficherSommet();
    sommetb.SOMAjouterArcPartant(sommetc);
    sommetb.SOMAjouterArcPartant(sommetd);
    try {
        sommetb.SOMAjouterArcPartant(sommetd);
    }
    catch (CException EXCexception) {
        cout << EXCexception.EXClireMessage() << " " << EXCexception.EXClireValeur()<< endl;
    }
    //sommetb.SOMAjouterArcPartant(sommetd);
    
    sommetb.SOMAfficherSommet();
    sommetb.SOMSupprimerArcPartant("c");
    sommetb.SOMAfficherSommet();
    cout << sommetb.SOMArcEstDansListePartant("c") << endl;
    CGraphOrient<CArc, CSommet> gpo;
    gpo.GPOAjouterSommet(sommetb);
    gpo.GPOAjouterSommet(sommetc);
    gpo.GPOAjouterSommet(sommeta);
    gpo.GPOAfficherGraphe();
   // string chemin("C:\\Users\\nkoub\\OneDrive\\Documents\\POLYTECH DI\\SEMESTRE 6\\CONCEPTION OO\\TDS\\ProjetTutore\\monfichier.txt");
    try {
        CParser pars("C:\\Users\\nkoub\\OneDrive\\Documents\\POLYTECH DI\\SEMESTRE 6\\CONCEPTION OO\\TDS\\ProjetTutore\\monfichier.txt");
        cout << pars.PARSlirecontenuFichier()<<endl;
    }
    catch (CException EXCexception) {
        cout << EXCexception.EXClireMessage() << " " << EXCexception.EXClireValeur() << endl;
    }*/
    
    CGraphOrient<CArc, CSommet> gpo;
    gpo.GPOAjouterSommet("1");
    gpo.GPOAjouterSommet("2");
    gpo.GPOAjouterSommet("3");
   try {

        gpo.GPOAjouterArc("1", "2");
        gpo.GPOAjouterArc("2", "3");
        gpo.GPOAjouterArc("3", "1");
        gpo.GPOAjouterArc("2", "2");
        //arc dupliquer nemarche pas, arc qui va vars un sommet inexistant marche
        //gpo.GPOAjouterArc("2", "4");//arc dupliquer ne marche pas, arc qui va vars un sommet inexistant marche


    }
    catch (CException exc) {
        cout << exc.EXClireMessage() << endl;
    }
    gpo.GPOAfficherGraphe();

    cout << "contenu des gpoliste" << endl;
    try {
       // gpo.GPOSupprimerArc("1", "2");
        gpo.GPOModifierSommet("1", "4");
        gpo.GPOModifierSommet("2", "5");
        gpo.GPOModifierSommet("3", "6");

        gpo.GPOModifierArc("4", "5", "6", "7");
    }
    catch (CException exc) {
        cout << exc.EXClireMessage() << endl;
    }
    
    gpo.GPOAfficherGraphe();
    
    


}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
