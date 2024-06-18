#ifndef levelstruct_h
#define levelstruct_h
#define MaxNoOfTiles 600
typedef struct {
  int KnightLocation[MaxNoOfTiles];
  int GoblinLocation[MaxNoOfTiles];
  int commonCollisions[MaxNoOfTiles];
  int TowerLocation[MaxNoOfTiles];
} LevelStruct;
#endif // !levelstruct_h
