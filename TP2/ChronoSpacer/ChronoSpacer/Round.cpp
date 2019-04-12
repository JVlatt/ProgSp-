#include "stdafx.h"
#include "Round.h"



CSRound CreateRound(float length, float difficulty)
{
	CSRound newRound;
	newRound.targetDuration = length;
	newRound.difficulty = difficulty;
	newRound.startTime = -1.0f;
	newRound.endTime = -1.0f;
	newRound.isVictory = false;
	return newRound;
}

CSRound StartRound(CSRound currentRound, float startTime)
{
	currentRound.startTime = startTime;
	/*
	printf("Round Length is : %g \n", currentRound.targetDuration);
	printf("Round Difficulty is : %g \n", currentRound.difficulty);
	printf("Round Start at t : %g \n", currentRound.startTime);
	*/
	return currentRound;
}

CSRound EndRound(CSRound currentRound, float endTime)
{
	currentRound.endTime = endTime;
	printf("Round Length is : %g \n", currentRound.targetDuration);
	printf("Round Difficulty is : %g \n", currentRound.difficulty);
	printf("Round Start at : %g \n", currentRound.startTime);
	printf("Round End at : %g \n", currentRound.endTime);
	return currentRound;
}

void displayRound(CSRound currentRound)
{
	printf("Round Length is : %g \n", currentRound.targetDuration);
	printf("Round Difficulty is : %g \n", currentRound.difficulty);
	printf("Round Start at : %g \n", currentRound.startTime);
	printf("Round End at : %g \n", currentRound.endTime);
}
