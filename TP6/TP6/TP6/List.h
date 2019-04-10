#pragma once

typedef struct element Element;
struct element {

	Element* previous;
	Element* next;
	char content;

};

typedef struct list {
	Element* first;
	int count;
}List;


List* CreateList();
Element* GetElementAt(List* myList, int position);
void AddElement(List* myList, char myContent);