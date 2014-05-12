/** @file List.h
	Contient les prototypes des m�thodes pour la classe List.

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
 * La classe Liste repr�sente une liste d'�l�ments doublement cha�n�e.
 * Les �l�ments point�s peuvent �tre des objets de n'importe quelle classe.
 * @author Jasmin Brassard, janvier 2012
 *         Cours 420-220-SF - C�gep de Sainte-Foy
 */
template <class TYPE>
class List
{
public:
    
    //Constructeur
    List();///< Prototype du constructeur de la classe List.

    //Destructeur
    ~List();///< Prototype du destructeur de la classe List.
    
	/** M�thode publique de la classe List qui ins�re un Cell � la fin de la liste.
		Supporte l'ajout dans une liste vide.
		@param[in] _element L'�l�ment ins�r� dans le nouveau Cell
	*/
	//Insert � la fin de liste (supporte l'ajout dans une liste vide)
	void PushBack(TYPE* _element);

	/** M�thode publique de la classe List qui ins�re un Cell avant la position courante
		pass�e par l'Iterator en argument. Cette m�thode ne supporte pas
		l'ajout dans une liste vide ou l'ajout � la fin d'une liste.
		@param[in] _element L'�l�ment ins�r� dans le nouveau Cell
		@param[in] __iter L'it�rateur qui indique la position actuelle dans la liste
	*/
    //Insert avant la position courante (limite: impossible d'ajouter � la fin!)
    //Ne supporte pas l'ajout dans une liste vide.
    //2 cas 1)Insertion au d�but 
    //      2)Insertion entre premier et dernier 
    void Insert(TYPE* _element, Iterator<TYPE>& _iter);

	/** M�thode publique de la classe List qui efface un Cell avant la position courante
		pass�e par l'Iterator en argument.
		@param[in] __iter L'it�rateur qui indique la position actuelle dans la liste
	*/
    //Enl�ve de la liste le pointeur de l'�l�ment 
    //4 cas...
    void Erase(Iterator<TYPE>& _iter);

    //Retourne l'�l�ment par valeur (copie)
	/** M�thode publique de la classe List qui retourne l'�l�ment du Cell
		point� par l'Iterator pass� en argument.
		@param[in] __iter L'it�rateur qui indique la position actuelle dans la liste
		@return Retourne l'�l�ment du Cell point� par l'Iterator.
	*/
    TYPE* GetElement(const Iterator<TYPE>& _iter) const;

	/** M�thode publique de la classe List qui retourne le nombre d'�l�ments
		contenus dans la liste.
		@return Retourne le nombre d'�l�ments dans la liste.
	*/
    int GetNbElements() const;

	/** M�thode publique de la classe List qui retourne une valeur bool�enne
		indiquant si la liste est vide.
		@return Retourne un bool�en qui indique si la liste est vide.
	*/
    bool IsEmpty() const;

	/** M�thode publique de la classe List qui vide compl�tement la liste.
		@see Erase
	*/
    void Clear();


    //3 M�thodes d�j� impl�ment�es:
    Cell<TYPE>* Begin() const;

    Cell<TYPE>* End() const;

    template <class TYPE>
    friend ostream& operator<<(ostream& _Sortie, const List<TYPE>& _List);

	//Variables mises dans le scope public temporairement
	int nbElements;
    Cell<TYPE>* first;
    Cell<TYPE>* last; 
private:

    List(const List&); //copieur d�sativ�
    const List& operator=(const List<TYPE>&); //affectateur d�sactiv�
    
    //Attributs
    

};

#include "list.hpp"