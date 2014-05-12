/** @file Iterator.h
	Contient les prototypes des méthodes pour la classe Iterator.

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

    //Méthodes

	/** Méthode publique de la classe Iterator qui fait pointer l'Iterator sur
		la prochaine Cell dans la liste.
	*/
    //Fait pointer l'itérateur sur la prochaine Cellule de la liste
    void Next(void);

	/** Méthode publique de la classe Iterator qui fait pointer l'Iterator sur
		la Cell précédente dans la liste.
	*/
    //Fait pointer l'itérateur sur la  Cellule précédente de la liste
    void Previous(void);

	/** Méthode publique de la classe Iterator qui retourne l'élément pointé
		par la Cell contenu par l'Iterator.
		@return Retourne l'élément pointé par la Cell contenu dans l'Iterator
	*/
    //Retourne l'élément sur lequel l'itérateur pointe
    TYPE* GetCurrentElement(void) const;

	/** Méthode publique de la classe Iterator qui retourne le pointeur sur la
		Cell que contient l'Iterator.
		@return Retourne le pointeur sur la Cell que contient l'Iterator.
	*/
    //Retourne le pointeur sur la Cellule sur laquelle l'itérateur pointe
    Cell<TYPE>* GetCurrent(void) const;

	/** Méthode publique de la classe Iterator qui assigne le pointeur sur la
		Cell que contient l'Iterator.
		@param[in] _cell Pointeur de Cell qui est assigné à l'Iterator
	*/
    //Modifie le pointeur sur la Cellule sur laquelle l'itérateur pointe
    void SetCurrent(Cell<TYPE>* _cell);
    
};
#include "iterator.hpp"