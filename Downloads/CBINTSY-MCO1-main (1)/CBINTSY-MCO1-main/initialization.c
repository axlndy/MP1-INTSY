/* 
Last Updated:
  Lian
  11:45 PM
  10/21/2024
*/
void initializeDestinations(desType *destinations) {
  destinations[0].index = 0;
  destinations[0].heuristicValue = 0;
  strcpy(destinations[0].name, "Bel-Air");
  destinations[0].numPassengers = 2;
  strcpy(destinations[0].passengers[0], "Leigh");
  strcpy(destinations[0].passengers[1], "Mac");

  destinations[1].index = 1;
  destinations[1].heuristicValue = 0;
  strcpy(destinations[1].name, "Courtyard");
  destinations[1].numPassengers = 3;
  strcpy(destinations[1].passengers[0], "Arron");
  strcpy(destinations[1].passengers[1], "Ed");
  strcpy(destinations[1].passengers[2], "Rienzel");

  destinations[2].index = 2;
  destinations[2].heuristicValue = 0;
  strcpy(destinations[2].name, "Manila");
  destinations[2].numPassengers = 4;
  strcpy(destinations[2].passengers[0], "Axl");
  strcpy(destinations[2].passengers[1], "Akisha");
  strcpy(destinations[2].passengers[2], "Vianca");
  strcpy(destinations[2].passengers[3], "Fajardo");

  destinations[3].index = 3;
  destinations[3].heuristicValue = 0;
  strcpy(destinations[3].name, "South Luzon");
  destinations[3].numPassengers = 3;
  strcpy(destinations[3].passengers[0], "Lian");
  strcpy(destinations[3].passengers[1], "Lawrence");
  strcpy(destinations[3].passengers[2], "Matthew");

  destinations[4].index = 4;
  destinations[4].heuristicValue = 0;
  strcpy(destinations[4].name, "Sta Rosa");
  destinations[4].numPassengers = 3;
  strcpy(destinations[4].passengers[0], "Leo");
  strcpy(destinations[4].passengers[1], "Chael");
  strcpy(destinations[4].passengers[2], "Allysa");

  destinations[5].index = 5;
  destinations[5].heuristicValue = 0;
  strcpy(destinations[5].name, "Malamig");
  destinations[5].numPassengers = 2;
  strcpy(destinations[5].passengers[0], "Marthy");
  strcpy(destinations[5].passengers[1], "Rovick");
}


int validateDestinationIndex(Node board[][MAX_GRID], int x, int y) {
	int valid = 1;
	if (x == 0 && y == 0)
		return 0;
    if (board[x][y].symbol != ' ')
		return 0;
  return valid;
}

void putToIndex(Node board[][MAX_GRID], desIdx *indexesOfDestinations, int ID, int max, int type, char symbol) {
  int xTemp, yTemp, valid;
  for (int i=0; i<max; i++) {
    valid = 0;
    do {
      xTemp = generateRandomNumber(0, MAX_GRID-1);
      yTemp = generateRandomNumber(0, MAX_GRID-1);
      valid = validateDestinationIndex(board, xTemp, yTemp);
    } while (!valid);
    board[xTemp][yTemp].symbol = symbol; 
    
    if (type == 0) {
		indexesOfDestinations[ID].ID = ID;
		indexesOfDestinations[ID].x = xTemp; 
		indexesOfDestinations[ID].y = yTemp;
    } else if  (type == 1)
    	board[xTemp][yTemp].blocked = true;
	else if (type == 2) {
		board[xTemp][yTemp].costMore = true;
		board[xTemp][yTemp].cost = generateRandomNumber(2, 10);
	}
	else 
		board[xTemp][yTemp].gameOver = true;
	
  }
}

// board is an array of struct of node
// the checking if the destinations are still reachable are done in the middle;
void initializeBoard(Node board[][MAX_GRID], desIdx *indexesOfDestinations, int difficulty) {
	int nRoadClosure, nOneWayRoad, nTrafficJam, nStopOver, nBedOfNails, nFlood;
	int maxObs;
	for (int i=0; i<MAX_GRID; i++) {
		for (int j=0; j<MAX_GRID; j++) {
			board[i][j].symbol = ' ';
			board[i][j].x = i;
			board[i][j].y = j;
			board[i][j].blocked = board[i][j].gameOver = board[i][j].costMore = false;
			board[i][j].gCost = board[i][j].hCost = board[i][j].fCost = 0;
			board[i][j].cost = 1;
			board[i][j].parent_x = board[i][j].parent_y = -1;
		}
	}
	
	putToIndex(board, indexesOfDestinations, 0, 1, 0, 'B');
	putToIndex(board, indexesOfDestinations, 1, 1, 0, 'C');
	putToIndex(board, indexesOfDestinations, 2, 1, 0, 'N');
	putToIndex(board, indexesOfDestinations, 3, 1, 0, 'O');
	putToIndex(board, indexesOfDestinations, 4, 1, 0, 'S');
	putToIndex(board, indexesOfDestinations, 5, 1, 0, 'L');
	
	switch (difficulty) {
		case 1:
			maxObs = 2;
			nTrafficJam = generateRandomNumber(1, 5);
			nStopOver = 5 - nTrafficJam;			
	    	break;
	    case 2:
			maxObs = 4;
			nTrafficJam = generateRandomNumber(1, 10);
			nStopOver = 10 - nTrafficJam;
			break;
	    case 3:
			maxObs = 6;
			nTrafficJam = generateRandomNumber(1, 15);
			nStopOver = 15 - nTrafficJam;
			break;
    }

	nRoadClosure = generateRandomNumber(1, maxObs);
	nOneWayRoad = maxObs - nRoadClosure;
	nBedOfNails = generateRandomNumber(1, maxObs);
	nFlood = maxObs - nBedOfNails;

    putToIndex(board, indexesOfDestinations, 0, nRoadClosure, 1, 'X');
	putToIndex(board, indexesOfDestinations, 0, nOneWayRoad, 1, '\\');
	putToIndex(board, indexesOfDestinations, 0, nTrafficJam, 2, '#');
	putToIndex(board, indexesOfDestinations, 0, nStopOver, 2, '$');
	putToIndex(board, indexesOfDestinations, 0, nBedOfNails, 3, ':');
	putToIndex(board, indexesOfDestinations, 0, nFlood, 3, '~');

}

