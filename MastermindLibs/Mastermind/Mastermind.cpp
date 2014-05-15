#include "Mastermind.h"


Mastermind::Mastermind()
{
   //Il faut créer ici les 4096 séquences de couleurs possibles. Bonne réflexion!
	const unsigned short NOMBRE_COULEURS = 4;
	int position = 0;
	//Initialiser la liste
	list = new List<ArrayI<Color>>();

	for (int premierIncre = 1; premierIncre < 9; premierIncre++)
	{
		for (int deuxiemeIncre = 1; deuxiemeIncre < 9; deuxiemeIncre++)
		{
			for (int troisiemeIncre = 1; deuxiemeIncre < 9; troisiemeIncre++)
			{
				for (int quatriemeIncre = 1; quatriemeIncre < 9; quatriemeIncre++)
				{
					tabSequences[position] = new ArrayI<Color>(NOMBRE_COULEURS);
					tabSequences[position]->SetElement(premierIncre, 0);
					tabSequences[position]->SetElement(deuxiemeIncre, 1);
					tabSequences[position]->SetElement(troisiemeIncre, 2);
					tabSequences[position]->SetElement(quatriemeIncre, 3);
					list->PushBack(tabSequences[position]);
					position++;
				}
			}
		}
	}
}

Mastermind::~Mastermind()
{
	for (int i = 0; i < 4096; i++)
	{
		delete tabSequences[i];
	}
}

int Mastermind::GetNbElements() const
{
	if (list != NULL)
	{
		return list->GetNbElements();
	}
	return 0;
}


ArrayI<Color>* Mastermind::GetElement() const
{
    //Utiliser la classe RandomNumber pour ne pas offrir toujours le premier élément de la liste (les parties seraient toutes pareilles avec la même séquence cachée)
    ArrayI<Color>* PourCompiler;
    return PourCompiler;
}

short Mastermind::CleanList(Color* _tabColorRef, short* _tabVerdicts)
{

     /*switch(tabVerdicts[i]){
                
                case 1: //Bonne couleur, bonne place

                        //Si la séquence de couleurs traitée n'a pas la couleur à la bonne place, il faut la retirer de la liste.

                case 2: //Bonne couleur, mauvaise place

                        //Si la séquence de couleurs traitée n'a pas la couleur à un autre emplacement que celui de la couleur de référence,
                        //il faut la retirer de la liste.
           
                case 3: //Mauvaise couleur
                        //Si la séquence de couleurs traitée a la couleur, il faut la retirer de la liste.
    };*/
    return 1; //Pour Compiler
}