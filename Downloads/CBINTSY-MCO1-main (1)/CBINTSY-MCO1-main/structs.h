
struct destinationsType {
	int index;
	double heuristicValue;
	String name;
    int numPassengers;
	String passengers[4]; // max passenger per place is 4
};

typedef struct destinationsType desType;

struct nodeType {
	char symbol;
	int x, y;
	int parent_x, parent_y;
	double gCost, hCost, fCost;
	bool blocked, costMore, gameOver;
	int cost; 
};

typedef struct nodeType Node;

struct destinationIndexes {
	int x;
	int y;
	int ID;
};

typedef struct destinationIndexes desIdx;

struct PairOfaPair {
	double f;
	desIdx innerPair;
};

typedef struct PairOfaPair PairPair;

