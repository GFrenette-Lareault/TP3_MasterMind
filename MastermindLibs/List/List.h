/** @file List.h
	Contient les prototypes des méthodes pour la classe List.

	@author Anthony Vallee
	@date 7 mai 2014
	@version 1.0
*/
#include <stdio.h> //Pour avoir NULL
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

#include "Cell.h"
#include "Iterator.h"

/**
 * La classe Liste représente une liste d'éléments doublement chaînée.
 * Les éléments pointés peuvent être des objets de n'importe quelle classe.
 * @author Jasmin Brassard, janvier 2012
 *         Cours 420-220-SF - Cégep de Sainte-Foy
 */
template <class TYPE>
class List
{
public:
    
    //Constructeur
    List();///< Prototype du constructeur de la classe List.

    //Destructeur
    ~List();///< Prototype du destructeur de la classe List.
    
	/** Méthode publique de la classe List qui insère un Cell à la fin de la liste.
		Supporte l'ajout dans une liste vide.
		@param[in] _element L'élément inséré dans le nouveau Cell
	*/
	//Insert à la fin de liste (supporte l'ajout dans une liste vide)
	void PushBack(TYPE* _element);

	/** Méthode publique de la classe List qui insère un Cell avant la position courante
		passée par l'Iterator en argument. Cette méthode ne supporte pas
		l'ajout dans une liste vide ou l'ajout à la fin d'une liste.
		@param[in] _element L'élément inséré dans le nouveau Cell
		@param[in] __iter L'itérateur qui indique la position actuelle dans la liste
	*/
    //Insert avant la position courante (limite: impossible d'ajouter à la fin!)
    //Ne supporte pas l'ajout dans une liste vide.
    //2 cas 1)Insertion au début 
    //      2)Insertion entre premier et dernier 
    void Insert(TYPE* _element, Iterator<TYPE>& _iter);

	/** Méthode publique de la classe List qui efface un Cell avant la position courante
		passée par l'Iterator en argument.
		@param[in] __iter L'itérateur qui indique la position actuelle dans la liste
	*/
    //Enlève de la liste le pointeur de l'élément 
    //4 cas...
    void Erase(Iterator<TYPE>& _iter);

    //Retourne l'élément par valeur (copie)
	/** Méthode publique de la classe List qui retourne l'élément du Cell
		pointé par l'Iterator passé en argument.
		@param[in] __iter L'itérateur qui indique la position actuelle dans la liste
		@return Retourne l'élément du Cell pointé par l'Iterator.
	*/
    TYPE* GetElement(const Iterator<TYPE>& _iter) const;

	/** Méthode publique de la classe List qui retourne le nombre d'éléments
		contenus dans la liste.
		@return Retourne le nombre d'éléments dans la liste.
	*/
    int GetNbElements() const;

	/** Méthode publique de la classe List qui retourne une valeur booléenne
		indiquant si la liste est vide.
		@return Retourne un booléen qui indique si la liste est vide.
	*/
    bool IsEmpty() const;

	/** Méthode publique de la classe List qui vide complètement la liste.
		@see Erase
	*/
    void Clear();


    //3 Méthodes déjà implémentées:
    Cell<TYPE>* Begin() const;

    Cell<TYPE>* End() const;

    template <class TYPE>
    friend ostream& operator<<(ostream& _Sortie, const List<TYPE>& _List);

	//Variables mises dans le scope public temporairement
	int nbElements;
    Cell<TYPE>* first;
    Cell<TYPE>* last; 
private:

    List(const List&); //copieur désativé
    const List& operator=(const List<TYPE>&); //affectateur désactivé
    
    //Attributs
    

};

#include "list.hpp"