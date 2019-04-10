// TP5.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>

void Func2(int &a) {
	printf("Func2 - id: a, value:%d, address:%x, size:%d\n", a, &a, sizeof(a));
}


void Func1(int a) {
	printf("Func1 - id: a, value:%d, address:%x, size:%d\n", a, &a, sizeof(a));
}

void Func3(int *tab) {
	printf("Func3 - id: tab, value:%d, address:%x, size:%d\n", tab[0], &(tab[0]),sizeof(tab[0]));
}

int main() {
	int a = 0;
	int b = 1;
	int c = 2;
	int d = 3;
	int &e = a;

	

	printf("main - id: a, value:%d, address:%x, size:%d\n", a, &a, sizeof(a));
	printf("main - id: b, value:%d, address:%x, size:%d\n", b, &b, sizeof(b));
	printf("main - id: c, value:%d, address:%x, size:%d\n", c, &c, sizeof(c));
	printf("main - id: d, value:%d, address:%x, size:%d\n", d, &d, sizeof(d));
	printf("a->b address position difference:%d\n", (long)&b - (long)&a);	//-12
	printf("b->c address position difference:%d\n", (long)&c - (long)&b);	//-12
	printf("c->d address position difference:%d\n", (long)&d - (long)&c);	//-12

	
	printf("main - id: e, value:%d, address:%x, size:%d\n", e, &e, sizeof(e)); // a et e partage la même adresse mémoire

	Func1(a); //Position d'allocation différente
	Func2(a); //Meme position d'allocation

	printf("\n\n\n");


	int tab[2] = { 5,10 };
		printf("main - id: tab, value:%x, address:%x, size:%d\n", tab, &(tab), sizeof(tab)); //la valeur de tab est une adresse	
	printf("main - id: tab[0], value:%d, address:%x, size:%d\n", tab[0], &(tab[0]),sizeof(tab[0]));
	//l'adresse du tableau renvoie à la première case du tableau	printf("main - id: *(tab), value:%d, address:%x, size:%d\n", *tab, tab,sizeof(*tab));	
	printf("main - id: tab[1], value:%d, address:%x, size:%d\n", tab[1], &(tab[1]),sizeof(tab[1]));

	printf("main - id: *(tab + 1), value:%d, address:%x, size:%d\n", *(tab + 1), tab + 1,sizeof(*(tab + 1))); //même adresse que tab[1]
	printf("\n\n\n");

	int *ptab = tab;

	printf("main - id: ptab[0], value:%d, address:%x, size:%d\n", ptab[0], &(ptab[0]),sizeof(ptab[0])); // même adresse que tab
	Func3(tab); //même adresse que tab


	printf("\nVariables dans le tas : \n");

	int* tab2 = new int[10];
	printf("main - id: tab2, value:%x, address:%x, size:%d\n", tab2, &tab2,sizeof(tab2));
	tab2[0] = 15;
	printf("main - id: tab2[0], value:%d, address:%x, size:%d\n", tab2[0], &(tab2[0]),sizeof(tab2[0]));


	system("pause");
	
	return 0;

}
