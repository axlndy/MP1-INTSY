/*
Last Updated:
    <name>
    <time>
    <date>
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef char String[21];
#define MAX_GRID 10

#include "structs.h"
#include "priorityQueue.c"
#include "initialization.c"
#include "userInput.c"
#include "aStar.c"

void printBoard(Node board[MAX_GRID][MAX_GRID]);

int main() {
	desType destinations[6]; desType inpDest[6];
	Node board[10][10];
	int mode, difficulty, numDest, displayMode, i;
	desIdx source, destination, indexesOfDestinations[6];
  	bool found = true;
  
	srand(time(NULL));

	initializeDestinations(destinations);
	mode = inputMode();
	difficulty = inputDifficulty();
	numDest = inputDestination(destinations, inpDest, difficulty);
	displayMode = inputDisplayMode();
	initializeBoard(board, indexesOfDestinations, difficulty);
	
	
	/*
	printf("\nIndexes Checking\n");
	for (i=0; i<6; i++) {
		desIdx source = {0,0};
		desIdx destination = {indexesOfDestinations[i].x, indexesOfDestinations[i].y};
		printf("\n\n\nsource: (%d %d), destination: (%d %d) \n", source.x, source.y, indexesOfDestinations[i].x, indexesOfDestinations[i].y);
		found = aStarSearch(board, source, destination);
		if (found) {
			printf("Path Found.");
		} else
			printf("Path Not Found.");
		printf("\n");
	}
	*/
			
	sortInputDestinations(inpDest, numDest);
	
	for (i=0; i<numDest && found; i++) {
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
		found = aStarSearch(board, source, destination);	
				
		if (found) {
			printf("Path found.\n");
			markPath(board, destination, displayMode, pickup, dropoff);	
			source = destination;
		}
		else {
			printf("No Path found. Try again.\n");
		}	
	}
	
	printHeuristic(board);
	
	return 0;
}

void printBoard(Node board[MAX_GRID][MAX_GRID]) {
  int i, j;
  
  printf("\n\n\n\n      ");

	for (i=0; i<10; i++)
	printf("x,%d ", i);
  // Print the top border
  printf("\n     +");
  for (i = 0; i < MAX_GRID; i++) {
    printf("---+");
  }
  printf("\n");

  // Print the board cells and middle borders
  for (i = 0; i < MAX_GRID; i++) {
  	printf(" %d,x", i);
    printf(" |");
    for (j = 0; j < MAX_GRID; j++) {
      printf(" %c |", board[i][j].symbol);
    }
    printf("\n");

    printf("     +");
    for (j = 0; j < MAX_GRID; j++) {
      printf("---+");
    }
    printf("\n");
  }	
  
}

void sortInputDestinations(desType *inpDest, int numDest) {
    desType temp;
    int i, j, lowestIndex;

    for (i = 0; i < numDest - 1; i++) {
        lowestIndex = i; // Start with the first unsorted element
        for (j = i + 1; j < numDest; j++) {
            if (inpDest[j].heuristicValue < inpDest[lowestIndex].heuristicValue) {
                lowestIndex = j; // Update index of the lowest heuristic value
            }
        }
        if (lowestIndex != i) {
            temp = inpDest[i];
            inpDest[i] = inpDest[lowestIndex];
            inpDest[lowestIndex] = temp;
        }
    }
}

void printHeuristic(Node board[MAX_GRID][MAX_GRID]) {
  int i, j;

  
  printf("\n\n\n\n      ");
	for (i=0; i<10; i++)
	printf("x,%d ", i);
  // Print the top border
  printf("\n     +");
  for (i = 0; i < MAX_GRID; i++) {
    printf("---+");
  }
  printf("\n");

  // Print the board cells and middle borders
  for (i = 0; i < MAX_GRID; i++) {
  	printf(" %d,x", i);
    printf(" |");
    for (j = 0; j < MAX_GRID; j++) {
      printf(" %.0lf |", board[i][j].fCost);
	  //printf(" %d |", board[i][j].cost);
    }
    printf("\n");

    printf("     +");
    for (j = 0; j < MAX_GRID; j++) {
      printf("---+");
    }
    printf("\n");
  }	
  
}
