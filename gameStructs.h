#ifndef gameStructs_h
#define gameStructs_h

typedef struct {
  double x;
  double y;
} Coord;

typedef struct {
  double height;
  double width;
} Dimensions;

typedef enum { RIGHT, LEFT, UP, DOWN } Direction;

typedef enum { CASTLE, TOWER, WOODHOUSE, HOUSE } TowerType;

typedef enum { OnFIELD, OutOFFIELD, DESTROYED } Status;

typedef struct {
  double health;
  TowerType tType;
  Status status;
  Dimensions dimensions;
  Coord position;
  char label[];
} Tower;

typedef struct {
  int health;
  int damage;
  Coord position;
  Status status;
  Dimensions dimensions;
} Goblin;

typedef struct {
  double health;
  double damage;
  double defense;
  Coord position;
  Status status;
  Dimensions dimensions;
} Knight;

typedef enum {
  H_SUPPORT, // Health Support
  A_SUPPORT, // Attack Support
  D_SUPPORT  // Defense Support
} Collection;

typedef struct {
  Collection collection;
  Dimensions dimensions;
  Coord position;
} Collectible;

#endif // !gameStructs_h
