#include "stdafx.h"
#include "Round.h"
#include "Battle.h"


Battle CreateBattle()
{
	Battle newBattle;
	newBattle.currentRoundId = 0;
	newBattle.roundCount = 0;
	return newBattle;
}

void AddRoundToBattle(Battle &currentBattle, CSRound newround)
{
	if(currentBattle.roundCount < ROUND_MAX)
	{
		currentBattle.rounds[currentBattle.roundCount] = newround;
		currentBattle.roundCount += 1;
	}
}

void _StartRound(Battle &currentBattle, float timer)
{
	StartRound(currentBattle.rounds[currentBattle.currentRoundId], timer);
}

void StartBattle(Battle &currentBattle, float timer)
{
	_StartRound(currentBattle, timer);
}

bool IsBattleFinished(Battle currentBattle)
{
	if (currentBattle.currentRoundId < currentBattle.roundCount)
		return false;
	else
		return true;
}

void OnBattleReceiveAction(Battle &currentBattle, float timer)
{
	if (currentBattle.rounds[currentBattle.currentRoundId].targetDuration > timer)
	{
		currentBattle.rounds[currentBattle.currentRoundId].isVictory = true;
		currentBattle.rounds[currentBattle.currentRoundId].endTime = timer;
	}
	else if (currentBattle.rounds[currentBattle.currentRoundId].targetDuration < timer)
	{
		currentBattle.rounds[currentBattle.currentRoundId].isVictory = false;
		currentBattle.rounds[currentBattle.currentRoundId].endTime = timer;
	}

}

int GetBattleVictoryCount(Battle currentBattle)
{
	int winCount = 0;
	for (int i = 0; i < currentBattle.currentRoundId; i++)
	{
		if (currentBattle.rounds[i].isVictory)
			winCount++;
	}
	return winCount;
}

void InitBattle(Battle &currentBattle)
{
	CSRound myRounds[ROUND_MAX];

	for (int i = 0; i < ROUND_MAX; i++)
	{
		myRounds[i] = CreateRound(10.0f, 1.0f);
	}

	for (int i = 0; i < ROUND_MAX; i++)
	{
		AddRoundToBattle(currentBattle, myRounds[i]);
	}
}



