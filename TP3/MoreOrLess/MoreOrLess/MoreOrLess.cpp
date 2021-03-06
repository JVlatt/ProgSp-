// MoreOrLess.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

typedef struct aiData {
	bool isActive;
	int boundMin;
	int boundMax;
}AIData;


int CompareAndDisplay(int input, int answer)
{
	if (input > answer)
	{
		std::cout << input << std::endl;
		std::cout << "C'est moins" << std::endl;
		return -1;
	}
	
	if (input < answer)
	{
		std::cout << input << std::endl;
		std::cout << "C'est plus" << std::endl;
		return 1;
	}
	else
	{
		std::cout << input << std::endl;
		std::cout << "C'est la bonne réponse" << std::endl;
		return 0;
	}
}

void UpdateBounds(int value, int answer, int &max, int &min)
{
	if (answer == 1)
	{
		min = value;
	}
	if (answer == -1)
	{
		max = value;
	}
}

int main()
{
	srand(time(NULL));
	int randomValue = rand();
	int maxValue;
	std::cout << " Veuillez rentrez la valeur maximale" << std::endl;
	std::cin >> maxValue;
	int valueToFind = randomValue % (maxValue + 1);
	AIData myAI;
	myAI.boundMin = 0;
	myAI.boundMax = maxValue;
	char isAIEnabled;
	std::cout << "Voulez vous utiliser l'IA cheatée ?  (y/n)" << std::endl;
	std::cin >> isAIEnabled;
	
	if (isAIEnabled == 'y')
		myAI.isActive = true;
	else
		myAI.isActive = false;

	int input = 100;


	while (CompareAndDisplay(input,valueToFind) != 0)
	{
		if (myAI.isActive)
		{
			input = (myAI.boundMin + myAI.boundMax) / 2;
			UpdateBounds(input, CompareAndDisplay(input, valueToFind), myAI.boundMax, myAI.boundMin);
		}
		else
			std::cin >> input;
	}



	
	system("pause");
	return 0;
}


