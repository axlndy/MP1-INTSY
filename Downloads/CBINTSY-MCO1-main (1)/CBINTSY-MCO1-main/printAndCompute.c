void printBoard(Node board[MAX_GRID][MAX_GRID]) {
    printf("\n");
    printf("\n       0   1   2   3   4   5   6   7   8   9                Game Symbols");
    printf("\n     +---+---+---+---+---+---+---+---+---+---+        ------------------------");
    printf("\n  0  | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |              Obstructions      ",
        board[0][0].symbol, board[0][1].symbol, board[0][2].symbol, board[0][3].symbol, board[0][4].symbol, 
        board[0][5].symbol, board[0][6].symbol, board[0][7].symbol, board[0][8].symbol, board[0][9].symbol);
    printf("\n     +---+---+---+---+---+---+---+---+---+---+          --------------------  ");
    printf("\n  1  | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |         | Closed road    | X | ",
        board[1][0].symbol, board[1][1].symbol, board[1][2].symbol, board[1][3].symbol, board[1][4].symbol, 
        board[1][5].symbol, board[1][6].symbol, board[1][7].symbol, board[1][8].symbol, board[1][9].symbol);
    printf("\n     +---+---+---+---+---+---+---+---+---+---+         | One-way road   | \\ | ");
    printf("\n  2  | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |         | Traffic jam    | # | ",
        board[2][0].symbol, board[2][1].symbol, board[2][2].symbol, board[2][3].symbol, board[2][4].symbol, 
        board[2][5].symbol, board[2][6].symbol, board[2][7].symbol, board[2][8].symbol, board[2][9].symbol);
    printf("\n     +---+---+---+---+---+---+---+---+---+---+         | Stopover       | $ | ");
    printf("\n  3  | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |         | Bed of nails   | : | ",
        board[3][0].symbol, board[3][1].symbol, board[3][2].symbol, board[3][3].symbol, board[3][4].symbol, 
        board[3][5].symbol, board[3][6].symbol, board[3][7].symbol, board[3][8].symbol, board[3][9].symbol);
    printf("\n     +---+---+---+---+---+---+---+---+---+---+         | Flood          | ~ | ");
    printf("\n  4  | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |          --------------------  ",
        board[4][0].symbol, board[4][1].symbol, board[4][2].symbol, board[4][3].symbol, board[4][4].symbol, 
        board[4][5].symbol, board[4][6].symbol, board[4][7].symbol, board[4][8].symbol, board[4][9].symbol);
    printf("\n     +---+---+---+---+---+---+---+---+---+---+                                ");
    printf("\n  5  | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |              Destinations      ",
        board[5][0].symbol, board[5][1].symbol, board[5][2].symbol, board[5][3].symbol, board[5][4].symbol, 
        board[5][5].symbol, board[5][6].symbol, board[5][7].symbol, board[5][8].symbol, board[5][9].symbol);
    printf("\n     +---+---+---+---+---+---+---+---+---+---+          --------------------  ");
    printf("\n  6  | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |         | Bel-Air        | B | ",
        board[6][0].symbol, board[6][1].symbol, board[6][2].symbol, board[6][3].symbol, board[6][4].symbol, 
        board[6][5].symbol, board[6][6].symbol, board[6][7].symbol, board[6][8].symbol, board[6][9].symbol);
    printf("\n     +---+---+---+---+---+---+---+---+---+---+         | Courtyard      | C | ");
    printf("\n  7  | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |         | Manila         | N | ",
        board[7][0].symbol, board[7][1].symbol, board[7][2].symbol, board[7][3].symbol, board[7][4].symbol, 
        board[7][5].symbol, board[7][6].symbol, board[7][7].symbol, board[7][8].symbol, board[7][9].symbol);
    printf("\n     +---+---+---+---+---+---+---+---+---+---+         | South Luzon    | O | ");
    printf("\n  8  | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |         | Sta. Rosa      | S | ",
        board[8][0].symbol, board[8][1].symbol, board[8][2].symbol, board[8][3].symbol, board[8][4].symbol, 
        board[8][5].symbol, board[8][6].symbol, board[8][7].symbol, board[8][8].symbol, board[8][9].symbol);
    printf("\n     +---+---+---+---+---+---+---+---+---+---+         | Malamig        | L | ");
    printf("\n  9  | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |          --------------------  ",
        board[9][0].symbol, board[9][1].symbol, board[9][2].symbol, board[9][3].symbol, board[9][4].symbol, 
        board[9][5].symbol, board[9][6].symbol, board[9][7].symbol, board[9][8].symbol, board[9][9].symbol);
    printf("\n     +---+---+---+---+---+---+---+---+---+---+\n\n");
}

void printPrompt() {
		printf(" ____  _  _  _  _  ____  ____  __    ____      ____  _  _  ____  ____  ____  ____  ____ \n"
			 "/ ___)/ )( \\/ )( \\(_  _)(_  _)(  )  (  __)    (  __)( \\/ )(  _ \\(  _ \\(  __)/ ___)/ ___)\n"
			 "\\___ \\) __ () \\/ (  )(    )(  / (_/\\ ) _)      ) _)  )  (  ) __/ )   / ) _) \\___ \\\\___ \\\n"
			 "(____/\\_)(_/\\____/ (__)  (__) \\____/(____)    (____)(_/\\_)(__)  (__\\_)(____)(____/(____/\n"
			 "");

	printf("                           _-_                                                          \n"
			 "        /^v^\\           /~~   ~~\\                                                       \n"
			 "                     /~~         ~~\\        ____________________________                \n"
			 " /^v^\\              {               }      /    /    /  |  | |  ||  |   \\               \n"
			 "                     \\  _-     -_  /      /    /    /   |__| |__||__|    |              \n"
			 "          /^v^\\        ~  \\\\ //  ~       /----------=====================|              \n"
			 "                    _- -   | | _- _      | \\  /V\\  /    _     CBL        |              \n"
			 "                      _ -  | |   -_      |()\\ \\W/ /()   _   SHUTTLE  _   |              \n"
			 "                          // \\\\          |   \\   /     / \\  EXPRESS / \\  |              \n"
			 "-----------------------------------------|O========O==_| | |--------| | _/--------------\n"
			 "                                            \\_\\_/   \\_\\_/_ \\_\\_/ \\_\\_/                \n"
			 "========================================================================================\n"
			 "\n"
			 "----------------------------------------------------------------------------------------"
			 "\n\n");

	printf("\n\n"
			 "Ready to go home?"
			 "\n\nWelcome to Shuttle Express! A simple path-finding game inspired by CBL's weekly routine in going home." 
			 "\n\nThis game simply helps you bring your passengers to their respective destinations. And here is the catch: you must spend the least amount of gas! "
			 "\nYou simply win if you spend the least amount of gas after dropping off all your passengers and you lose if you spend more than what is necessary. "
			 "\nHowever, you also lose if you pass through paths with a bed of nails and flowing flood. So make sure you really know where you are going!"
			 "\n\nThere are 6 destinations randomly placed on the map every game. All passengers automatically have their own respective destinations. "
			 "\nPassing through one block in the map game equates to one cost of gasoline. You cannot pass through a closed road and one-way road. "
			 "\nTraffic jams and stopovers will cost you more gas. Again, passing through a bed of nails and flood will automatically make you lose the game. "
			 "\nTo make the game much more interesting, you can only move in four directions, which are up, down, left, and right direction."
			 "\n\nPlaying in smart mode lets you think of the best path possible to reach your destinations. Meanwhile, in dumb mode, let's say you're going on a road trip! "
			 "\nEasy level lets you choose 2 destinations and there will be 9 obstructions randomly placed in your map. Medium level has 4 destinations with 18 obstructions. "
			 "\nLastly, the Hard level has all 6 destinations with 27 obstructions. There is no limit to the number of passengers, but only choose the ones who live there!"
			 "\n\nLet's go home, shall we?\n\n"
	);

}

double manhattanDistance(int row, int col, desIdx destination){
    // Return using the distance formula
    int value = (abs(row-destination.x) + abs(col-destination.y));
    return value;
}

void swapDest(desType *x, desType *y){
    desType temp = *x;
    *x = *y;
    *y = temp;
}

void swapInt(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int generateRandomNumber(int min, int max) {
  int temp;
  if (min > max)
    swapInt(&min, &max);
  temp = (rand() % (max - min + 1) + min);
  return temp;
}

void computeHeuristic(desType *inpDest, int numDest, desIdx *destination){
    int ID;

    for(int i = 0; i < numDest; i++){
        ID = inpDest[i].index;
        inpDest[i].heuristicValue = manhattanDistance(0, 0, destination[ID]); 
    }
}
void randomizeDestinations(desType *inpDest, int numDest){
    for (int x = 0; x < numDest; x++){
        int idx = generateRandomNumber(0, numDest);
        swapDest(&inpDest[x], &inpDest[idx]);
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
