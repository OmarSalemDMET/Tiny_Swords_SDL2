#ifndef troops_h
#define troops_h
#include "gameStructs.h"

void GoblinAttackKnight(Goblin *g, Knight *kn);

void KnightAttackGoblin(Knight *kn, Goblin *g);

void GoblinAttackTower(Goblin *g, Tower *t);

void KnightAttackTower(Knight *kn, Tower *t);

void KnightCollects(Knight *kn, Collectible *c);

int isKnightOutField(Knight *kn);

int isGoblinOutField(Goblin *g);

int KnightHasReachedTower(Knight *kn, Tower *t);

int GoblinHasReachedTower(Goblin *g, Tower *t);

int TowerHasFallen(Tower *t);

#endif // !troops_h
