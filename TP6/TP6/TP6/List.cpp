#include "pch.h"
#include <cstdlib>
#include "List.h"

List* CreateList() {
	List myList;
	myList.count = 0;
	return &myList;
}

Element* GetElementAt(List* myList, int position)
{

	if (position < 0 || position > (*myList).count)
		return NULL;
	else
	{
		Element* myElement = (*myList).first;
		for (int i = 0; i < position; i++)
		{
			myElement = (*myElement).next;
		}
		return myElement;
	}
}

void AddElement(List* myList, char myContent)
{
	Element myElement;
	Element *myElementPtr = &myElement;
	(*myElementPtr).content = myContent;
	(*myElementPtr).next = NULL;
	
	if ((*myList).count == 0)
	{
		(*myElementPtr).previous = NULL;
		(*myList).first = myElementPtr;
	}
	else
	{
		(*myElementPtr).previous = GetElementAt(myList, (*myList).count);
		(*GetElementAt(myList, (*myList).count)).next = myElementPtr;
	}
	(*myList).count += 1;
}
