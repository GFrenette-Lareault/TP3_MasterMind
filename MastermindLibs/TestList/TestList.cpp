#include "TestList.h"


TestList::TestList(void)
{
}


TestList::~TestList(void)
{
}

void TestList::RunAllTests()
{
	TestListPushBack();
	TestListInsert();
	TestListErase();
	TestListGetElement();
	TestListGetNbElements();
	TestListIsEmpty();
	TestListClear();

	TestIteratorNext();
	TestIteratorPrevious();
	TestIteratorGetCurrentElement();
	TestIteratorGetCurrent();
	TestIteratorSetCurrent();

	system("pause");
}

void TestList::TestListPushBack()
{
	int nombre = 10;
	cout << "Test de PushBack() de la classe List.";
	listTest.PushBack(&nombre);
	assert(listTest.last != NULL && *(listTest.last->Element) == nombre);
	int nombre2 = 20;
	listTest.PushBack(&nombre2);
	assert(*(listTest.last->Element) == nombre2);
}
void TestList::TestListInsert()
{
	int nbElementBefore = listTest.nbElements;
	cout << "Test de Insert() de la classe List.";
	iteratorTest.current = listTest.first;
	int nombre = 30;
	listTest.Insert(&nombre, iteratorTest);
	int nbElementAfter = listTest.nbElements;
	assert(listTest.first == iteratorTest.current && nbElementBefore + 1 == nbElementAfter);
	iteratorTest.current = iteratorTest.current->Next;
	nbElementBefore = listTest.nbElements;
	listTest.Insert(&nombre, iteratorTest);
	nbElementAfter = listTest.nbElements;
	assert(listTest.first->Next == iteratorTest.current && iteratorTest.current->Next == listTest.first->Next->Next && nbElementBefore + 1 == nbElementAfter);
}
void TestList::TestListErase()
{
	//Test troisième cas
	int nbElementsBefore = listTest.nbElements;
	cout << "Test de Erase() de la classe List.";
	iteratorTest.current = listTest.first->Next;
	Cell<int>* tempCell = listTest.first->Next->Next;
	listTest.Erase(iteratorTest);
	int nbElementsAfter = listTest.nbElements;
	assert(iteratorTest.current == listTest.first && listTest.first->Next == tempCell && tempCell->Previous == listTest.first && nbElementsBefore == nbElementsAfter + 1);
	//Test premier cas
	nbElementsBefore = listTest.nbElements;
	tempCell = listTest.first->Next;
	iteratorTest.current = listTest.first;
	listTest.Erase(iteratorTest);
	nbElementsAfter = listTest.nbElements;
	assert(iteratorTest.current == listTest.first && listTest.first->Previous == NULL && tempCell == listTest.first && nbElementsBefore == nbElementsAfter + 1);
	//Test deuxième cas
	nbElementsBefore = listTest.nbElements;
	tempCell = listTest.last->Previous;
	iteratorTest.current = listTest.last;
	listTest.Erase(iteratorTest);
	nbElementsAfter = listTest.nbElements;
	assert(iteratorTest.current == listTest.last && listTest.last->Next == NULL && tempCell == listTest.last && nbElementsBefore == nbElementsAfter + 1);
	//Test dernier cas
	nbElementsBefore = listTest.nbElements;
	iteratorTest.current = listTest.last;
	listTest.Erase(iteratorTest);
	nbElementsAfter = listTest.nbElements;
	assert(listTest.first == NULL && listTest.last == NULL && nbElementsBefore == nbElementsAfter + 1);
}
void TestList::TestListGetElement()
{
	int nombre = 10;
	cout << "Test de GetElement() de la classe List.";
	listTest.PushBack(&nombre);
	iteratorTest.current = listTest.first;
	assert(listTest.GetElement(iteratorTest) == &nombre);
}
void TestList::TestListGetNbElements()
{
	int nombre = 10;
	cout << "Test de GetNbElements() de la classe List.";
	int nbElementsBefore = listTest.GetNbElements();
	listTest.PushBack(&nombre);
	int nbElementsAfter = listTest.GetNbElements();
	assert(nbElementsBefore == nbElementsAfter - 1);
}
void TestList::TestListIsEmpty()
{
	bool isEmptyBefore = listTest.IsEmpty();
	cout << "Test de IsEmpty() de la classe List.";
	iteratorTest.current = listTest.last;
	listTest.Erase(iteratorTest);
	bool isEmptyAfter = listTest.IsEmpty();
	assert(isEmptyBefore == isEmptyAfter && listTest.last != NULL);
	listTest.Erase(iteratorTest);
	isEmptyAfter = listTest.IsEmpty();
	assert(isEmptyBefore != isEmptyAfter && listTest.last == NULL);
}
void TestList::TestListClear()
{
	//PushBack pour remplir la liste
	int nombre1 = 10, nombre2 = 20, nombre3 = 30;
	cout << "Test de Clear() de la classe List.";
	listTest.PushBack(&nombre1);
	listTest.PushBack(&nombre2);
	listTest.PushBack(&nombre3);
	listTest.Clear();
	assert(listTest.first == NULL && listTest.last == NULL && listTest.nbElements == 0);
}
void TestList::TestIteratorNext()
{
	Cell<int>* secondCell = new Cell<int>(NULL, NULL, NULL);
	Cell<int>* firstCell = new Cell<int>(NULL, NULL, secondCell);
	cout << "Test de Next() de la classe Iterator.";
	iteratorTest.current = firstCell;
	iteratorTest.Next();
	assert(iteratorTest.current == secondCell);
	delete firstCell;
	delete secondCell;
}
void TestList::TestIteratorPrevious()
{
	Cell<int>* firstCell = new Cell<int>(NULL, NULL, NULL);
	Cell<int>* secondCell = new Cell<int>(NULL, firstCell, NULL);
	cout << "Test de Previous() de la classe Iterator.";
	iteratorTest.current = secondCell;
	iteratorTest.Previous();
	assert(iteratorTest.current == firstCell);
	delete firstCell;
	delete secondCell;
}
void TestList::TestIteratorGetCurrentElement()
{
	int newElement = 10;
	Cell<int>* newCell = new Cell<int>(&newElement, NULL, NULL);
	cout << "Test de GetCurrentElement() de la classe Iterator.";
	iteratorTest.current = newCell;
	assert(newElement == *iteratorTest.GetCurrentElement());
	delete newCell;
}
void TestList::TestIteratorGetCurrent()
{
	Cell<int>* newCell = new Cell<int>(NULL, NULL, NULL);
	cout << "Test de GetCurrent() de la classe Iterator.";
	iteratorTest.current = newCell;
	assert(newCell == iteratorTest.GetCurrent());
	delete newCell;
}
void TestList::TestIteratorSetCurrent()
{
	Cell<int>* newCell = new Cell<int>(NULL, NULL, NULL);
	cout << "Test de SetCurrent() de la classe Iterator.";
	iteratorTest.SetCurrent(newCell);
	assert(newCell == iteratorTest.current);
	delete newCell;
}