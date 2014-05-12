#pragma once
#include "List.h"
#include "Iterator.h"
class TestList
{
public:
    TestList(void);
    ~TestList(void);

    void RunAllTests();

	void TestListPushBack();
	void TestListInsert();
	void TestListErase();
	void TestListGetElement();
	void TestListGetNbElements();
	void TestListIsEmpty();
	void TestListClear();

	void TestIteratorNext();
	void TestIteratorPrevious();
	void TestIteratorGetCurrentElement();
	void TestIteratorGetCurrent();
	void TestIteratorSetCurrent();
private:
	List<int> listTest;
	Iterator<int> iteratorTest;
};

