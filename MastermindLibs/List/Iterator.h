/** @file Iterator.h
	Contient les prototypes des m�thodes pour la classe Iterator.

	@author Anthony Vallee
	@date 7 mai 2014
	@version 1.0
*/
#pragma once
#include "Cell.h"

template <class TYPE>
class Iterator{
private:
    //Cell<TYPE>* current;
public:
	//Variable mise dans le scope public temporairement
	Cell<TYPE>* current;
    //Constructeur
    Iterator(void);

    //M�thodes

	/** M�thode publique de la classe Iterator qui fait pointer l'Iterator sur
		la prochaine Cell dans la liste.
	*/
    //Fait pointer l'it�rateur sur la prochaine Cellule de la liste
    void Next(void);

	/** M�thode publique de la classe Iterator qui fait pointer l'Iterator sur
		la Cell pr�c�dente dans la liste.
	*/
    //Fait pointer l'it�rateur sur la  Cellule pr�c�dente de la liste
    void Previous(void);

	/** M�thode publique de la classe Iterator qui retourne l'�l�ment point�
		par la Cell contenu par l'Iterator.
		@return Retourne l'�l�ment point� par la Cell contenu dans l'Iterator
	*/
    //Retourne l'�l�ment sur lequel l'it�rateur pointe
    TYPE* GetCurrentElement(void) const;

	/** M�thode publique de la classe Iterator qui retourne le pointeur sur la
		Cell que contient l'Iterator.
		@return Retourne le pointeur sur la Cell que contient l'Iterator.
	*/
    //Retourne le pointeur sur la Cellule sur laquelle l'it�rateur pointe
    Cell<TYPE>* GetCurrent(void) const;

	/** M�thode publique de la classe Iterator qui assigne le pointeur sur la
		Cell que contient l'Iterator.
		@param[in] _cell Pointeur de Cell qui est assign� � l'Iterator
	*/
    //Modifie le pointeur sur la Cellule sur laquelle l'it�rateur pointe
    void SetCurrent(Cell<TYPE>* _cell);
    
};
#include "iterator.hpp"