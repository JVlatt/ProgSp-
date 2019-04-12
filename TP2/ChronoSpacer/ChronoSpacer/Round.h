#pragma once

typedef struct CSround{

	float targetDuration;
	float difficulty;
	float startTime;
	float endTime;
	bool isVictory;

} CSRound;

CSRound CreateRound(float length, float difficulty);
CSRound StartRound(CSRound currentRound, float startTime);
CSRound EndRound(CSRound currentRound, float endTime);
void displayRound(CSRound currentRound);
