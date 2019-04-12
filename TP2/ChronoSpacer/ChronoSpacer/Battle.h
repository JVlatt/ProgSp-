#pragma once

#ifndef ROUND_MAX
#define ROUND_MAX 10
#endif
typedef struct CSround CSRound;


typedef struct battle {

	CSRound rounds[ROUND_MAX];
	int roundCount;
	int currentRoundId;

}Battle;

Battle CreateBattle();
void AddRoundToBattle(Battle &currentBattle, CSRound newround);
void StartBattle(Battle &currentBattle, float timer);
bool IsBattleFinished(Battle currentBattle);
void OnBattleReceiveAction(Battle &currentBattle, float timer);
int GetBattleVictoryCount(Battle currentBattle);
void InitBattle(Battle &currentBattle);