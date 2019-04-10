
#include "pch.h"
#include "List.h"
#include <iostream>

int main()
{
	List* list = CreateList();

	AddElement(list, 'a');
	/*AddElement(list, 'b');
	AddElement(list, 'c');
	AddElement(list, 'd');

	printf("Premier caractere : %c \n", GetElementAt(list, 0));
	printf("Deuxieme caractere : %c \n", GetElementAt(list, 1));
	printf("Troisieme caractere : %c \n", GetElementAt(list, 2));
	printf("Quatrieme caractere : %c \n", GetElementAt(list, 3));
	*/system("pause");
	return 0;
}
