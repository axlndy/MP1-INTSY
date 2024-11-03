#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>

typedef char String[21];
#define MAX_GRID 10

#include "structs.h"
#include "printAndCompute.h"
#include "initialization.h"
#include "priorityQueue.h"
#include "userInput.h"
#include "aStar.h"

void printBoard(Node board[MAX_GRID][MAX_GRID]);

int main() {
	desType destinations[6]; desType inpDest[6];
	Node board[10][10];
	int mode, difficulty, numDest, displayMode, i;
	desIdx source, destination, indexesOfDestinations[6];
	int found = 1, gas;

	srand(time(NULL));

	printPrompt();
	
	initializeDestinations(destinations);
	mode = inputMode();
	difficulty = inputDifficulty();
	numDest = inputDestination(destinations, inpDest, difficulty);

	displayMode = inputDisplayMode();
	initializeBoard(board, indexesOfDestinations, difficulty);

	computeHeuristic(inpDest, numDest, indexesOfDestinations);

	if (mode == 1)
		randomizeDestinations(inpDest, numDest);
	else
		sortInputDestinations(inpDest, numDest);

	printf("\n\n\n\n\nDestinations Sequence: ");
	for(i = 0; i < numDest; i++){
		printf("%s, %lf ", inpDest[i].name, inpDest[i].heuristicValue);
	}
	printf("\n\n\n\n\n");

	for (i=0; i<numDest && found == 1; i++) {
		int ID = inpDest[i].index;
		String pickup, dropoff;

		if (i == 0) {
			source.x = 0;
			source.y = 0;
			strcpy(pickup, "DLSU Laguna Campus");
		}
		else {
			strcpy(pickup, inpDest[i-1].name);
		}
		strcpy(dropoff, inpDest[i].name);

		destination.x = indexesOfDestinations[ID].x; 
		destination.y = indexesOfDestinations[ID].y; 
		found = aStarSearch(board, source, destination, mode);	

		if (found == 1) {
			printf("\nPath found! ");
			gas += markPath(board, destination, displayMode, pickup, dropoff);
			source = destination;
		}
		else if (found == 0) {
			printf("\nNo Path found. Try again! ");
			markPath(board, destination, displayMode, pickup, dropoff);
		}
		else { // found == 2
			printf("\nGame Over. Better luck next time! ");
			markPath(board, destination, displayMode, pickup, dropoff);
		}

		printf("Passengers dropped off: ");
		for (int x = 0; x < inpDest[i].numPassengers; x++){
			if (x == inpDest[i].numPassengers-1)
				printf("%s\n\n", inpDest[i].passengers[x]);
			else
				printf("%s, ", inpDest[i].passengers[x]);
		}
	}

	printf("\nTotal gas consumed: %d\n\n", gas);

	return 0;
}
