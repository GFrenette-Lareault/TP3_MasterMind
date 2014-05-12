
//Constructeur
template <class TYPE>
List<TYPE>::List()
{
	first = last = NULL;
}

//Destructeur
template <class TYPE>
List<TYPE>::~List()
{
	Clear();
}

//Insert à la fin de liste (supporte l'ajout dans une liste vide)
template <class TYPE>
void List<TYPE>::PushBack(TYPE* _element)
{
	Cell<TYPE>* newCell = new Cell<TYPE>(_element, last, NULL);
	if (last == NULL)
	{
		first = last = newCell;
	}
	else
	{
		last->Next = newCell;
		newCell->Previous = last;
		last = newCell;
	}
	this->nbElements++;
}
template <class TYPE>
void List<TYPE>::Insert(TYPE* _Element, Iterator<TYPE>& _Iter)
{
    //Insert avant la position courante (limite: impossible d'ajouter à la fin!)
    //Ne supporte pas l'ajout dans une liste vide.
    //2 cas 1)Insertion au début 
    //      2)Insertion entre premier et dernier 
	assert(last != NULL);
	Cell<TYPE>* newCell = new Cell<TYPE>(_Element, NULL, NULL);
	if (_Iter.GetCurrent() == first)
	{
		newCell->Next = first;
		_Iter.GetCurrent()->Previous = newCell;
		first = newCell;
	}
	else
	{
		newCell->Previous = _Iter.GetCurrent()->Previous;
		newCell->Next = _Iter.GetCurrent();
		newCell->Previous->Next = newCell;
		newCell->Next->Previous = newCell;
	}
	_Iter.SetCurrent(newCell);
	this->nbElements++;
} 

template <class TYPE>
void List<TYPE>::Erase(Iterator<TYPE>& _Iter)
{
    //4 cas possibles... A vous de les trouver!
	if (_Iter.GetCurrent() == first)
	{
		first = _Iter.GetCurrent()->Next;
		first->Previous = NULL;
		delete _Iter.GetCurrent();
		_Iter.SetCurrent(first);
	}
	else if (_Iter.GetCurrent() == last)
	{
		last->Previous->Next = NULL;
		last = last->Previous;
		delete _Iter.GetCurrent();
		_Iter.SetCurrent(last);
	}
	else if (first == last)
	{
		delete _Iter.GetCurrent();
		_Iter.SetCurrent(NULL);
		first = last = NULL;
	}
	else
	{
		_Iter.GetCurrent()->Previous->Next = _Iter.GetCurrent()->Next;
		_Iter.GetCurrent()->Next->Previous = _Iter.GetCurrent()->Previous;
		Cell<TYPE>* tempCell = _Iter.GetCurrent()->Previous;
		delete _Iter.GetCurrent();
		_Iter.SetCurrent(tempCell);
	}
	this->nbElements--;
}

template <class TYPE>
TYPE* List<TYPE>::GetElement(const Iterator<TYPE>& _Iter) const
{
	return _Iter.GetCurrent()->Element;
}

template <class TYPE>
int List<TYPE>::GetNbElements() const
{ 
	return nbElements;
}

template <class TYPE>
bool List<TYPE>::IsEmpty() const
{
	bool empty = true;
	if (last != NULL)
	{
		empty = false;
	}
	return empty;
} 

template <class TYPE>
void List<TYPE>::Clear()
{
	Iterator<TYPE> iter;
	iter.SetCurrent(last);
	while (iter.GetCurrent() != NULL)
	{
		Erase(iter);
	}
}

//Méthodes déjà implémentées
template <class TYPE>
Cell<TYPE>* List<TYPE>::Begin() const
{ 
    return this->first;
}

template <class TYPE>
Cell<TYPE>* List<TYPE>::End() const
{
    return this->last;
}

template <class TYPE>
ostream& operator<<(ostream& _sortie, const List<TYPE>& _list)
{
    Cell<TYPE>* cellule=_list.first;

    while(cellule != NULL){
        _sortie<<*cellule->Element<<endl;
        cellule = cellule->Next;
    }
    _sortie<<endl;
    return _sortie;
}