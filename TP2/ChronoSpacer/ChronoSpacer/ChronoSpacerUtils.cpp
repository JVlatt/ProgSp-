#include "stdafx.h"
#include <cstdlib>
#include <ctime>
#include "ChronoSpacerUtils.h"

int GetRandomInt(int min, int max)
{
	int result = min + rand() % (max - min);
	return result;
}

void InitRandom()
{
	srand(time(NULL));
}