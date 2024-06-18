#include "Troops.h"
#include "gameStructs.h"
#include <stdio.h>

int isKnightOutField(Knight *kn) {
  if (kn->status == OutOFFIELD) {
    return 1;
  }
  return 0;
}
int isGoblinOutField(Goblin *g) {
  Status s;
  if (g->status == OutOFFIELD) {
    return 1;
  }
  return 0;
}
void KnightAttackGoblin(Knight *kn, Goblin *g) {
  g->health -= kn->damage;
  if (kn->health <= 0) {
    kn->status = OutOFFIELD;
  }
}
void KnightAttackTower(Knight *kn, Tower *t) {
  t->health -= kn->damage;
  if (t->health <= 0) {
    t->status = DESTROYED;
  }
}
void GoblinAttackKnight(Goblin *g, Knight *kn) {
  kn->health -= g->damage;

  if (g->health <= 0) {
    g->status = OutOFFIELD;
  }
}
void GoblinAttackTower(Goblin *g, Tower *t) {
  t->health -= g->damage;
  if (t->health <= 0) {
    t->status = DESTROYED;
  }
}

int checkForCollision(double h1, double h2, double w1, double w2, double x1,
                      double x2, double y1, double y2) {
  if (x1 < x2 + w2 && x1 + w1 > x2 && y1 < y2 + h2 && y1 + h1 > y2) {
    return 1;
  }

  return 0;
}

void KnightCollects(Knight *kn, Collectible *c) {
  if (checkForCollision(kn->dimensions.height, c->dimensions.height,
                        kn->dimensions.width, c->dimensions.width,
                        kn->position.x, c->position.x, kn->position.y,
                        c->position.y)) {
    switch (c->collection) {
    case A_SUPPORT:
      kn->damage += 10;
      break;
    case D_SUPPORT:
      kn->defense += 10;
      break;
    case H_SUPPORT:
      kn->health += 15;
      break;
    default:
      printf("This was just a collectible");
    }
  }
}

int TowerHasFallen(Tower *t) {
  if (t->health <= 0) {
    return 1;
  }
  return 0;
}

int KnightHasReachedTower(Knight *kn, Tower *t) {
  if (checkForCollision(kn->dimensions.height, t->dimensions.height,
                        kn->dimensions.width, t->dimensions.width,
                        kn->position.x, t->position.x, kn->position.y,
                        t->position.y)) {
    return 1;
  }

  return 0;
}

int GoblinHasReachedTower(Goblin *g, Tower *t) {
  if (checkForCollision(g->dimensions.height, t->dimensions.height,
                        g->dimensions.width, t->dimensions.width, g->position.x,
                        t->position.x, g->position.y, t->position.y)) {
    return 1;
  }

  return 0;
}
