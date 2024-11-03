#include "aStar.c"
int markPath(Node board[][MAX_GRID], desIdx dest, int displayMode, String pickup, String dropoff);
bool isValid(int row, int col);
bool isDestination(int row, int col, desIdx dest);
int aStarSearch(Node board[MAX_GRID][MAX_GRID], desIdx source, desIdx destination, int mode);
