// ChronoSpacer.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "Round.h"
#include "Battle.h"
#include <cmath>
#include <time.h>

int main()
{
	float _startTime;
	
	Battle myBattle = CreateBattle();
	InitBattle(myBattle);
	//StartBattle(myBattle, 10.0f);

	while (!IsBattleFinished(myBattle))
	{
		printf("\n Debut du round numero : %d \n", myBattle.currentRoundId+1);
		//printf("Quand vous etes prets appuyez sur ESPACE \n");
		//system("pause");
		_startTime = ((float)clock() / CLOCKS_PER_SEC);
		myBattle.rounds[myBattle.currentRoundId].startTime = _startTime;
		printf("\n Appuyez quand vous pensez avoir le bon timing \n");
		system("pause");
		float _endTimer = ((float)clock() / CLOCKS_PER_SEC) - _startTime;
		printf("\n Temps attendu : %.1f         Temps effectue : %.1f", myBattle.rounds[myBattle.currentRoundId].targetDuration, _endTimer);
		OnBattleReceiveAction(myBattle, _endTimer);
		if (myBattle.rounds[myBattle.currentRoundId].isVictory)
		{
			printf("\n wp \n");
		}
		else
		{
			printf("\n mskn \n");
		}
		myBattle.currentRoundId++;
	}
	/*for (int i = 0; i < 10; i++)
		displayRound(myBattle.rounds[i]);*/

	printf("\n Nb de manches gagnees : %d \n", GetBattleVictoryCount(myBattle));
	


	system("pause");
	return 0;
	
	
}

