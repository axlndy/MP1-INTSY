#include "printAndCompute.c"
void printBoard(Node board[MAX_GRID][MAX_GRID]);
void printPrompt();
double manhattanDistance(int row, int col, desIdx destination);
void swapDest(desType *x, desType *y);
void swapInt(int *x, int *y);
int generateRandomNumber(int min, int max);
void computeHeuristic(desType *inpDest, int numDest, desIdx *destination);
void randomizeDestinations(desType *inpDest, int numDest);
void sortInputDestinations(desType *inpDest, int numDest);
void printHeuristic(Node board[MAX_GRID][MAX_GRID]);
