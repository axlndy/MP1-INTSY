int markPath(Node board[][MAX_GRID], desIdx dest, int displayMode, String pickup, String dropoff) {
    int row = dest.x, col = dest.y;
    int temp_row = 1, temp_col = -1, gas = 0;

    desIdx path[MAX_GRID * MAX_GRID];
    for (int i = 0; i < MAX_GRID * MAX_GRID; i++) {
        path[i].x = -1;
        path[i].y = -1;
        path[i].ID = -1;
    }

    int pathIndex = 0;

    // Traverse the path from destination to source
    while (!(board[row][col].parent_x == row && board[row][col].parent_y == col)) {
        path[pathIndex].x = row;
        path[pathIndex].y = col;
        pathIndex++;
        temp_row = board[row][col].parent_x;
        temp_col = board[row][col].parent_y;
        row = temp_row;
        col = temp_col;
        gas += board[row][col].cost;
    }

    path[pathIndex].x = row;
    path[pathIndex].y = col;
    pathIndex++;

    // Store original destination symbols
    char originalDestinationSymbols[MAX_GRID][MAX_GRID] = {0};

    // Start marking from the correct cell based on destination case
    int startIndex = pathIndex - 1;
    if (islower(board[path[startIndex].x][path[startIndex].y].symbol)) {
        startIndex--;
    }

    char previousSymbol = ' '; // Initialize previous symbol to blank

    // Iterate through the path in reverse to mark the directions
    for (int i = startIndex; i >= 0; i--) {
        int currRow = path[i].x;
        int currCol = path[i].y;
        int nextRow = (i > 0) ? path[i - 1].x : -1;
        int nextCol = (i > 0) ? path[i - 1].y : -1;

        // Clear screen before each step display
        system("clear"); // or "CLS" for Windows

        char currentSymbol = board[currRow][currCol].symbol;
        bool isDestination = (currentSymbol == 'B' || currentSymbol == 'C' || currentSymbol == 'N' ||
                              currentSymbol == 'O' || currentSymbol == 'S' || currentSymbol == 'L');

        if (isDestination && originalDestinationSymbols[currRow][currCol] == 0) {
            originalDestinationSymbols[currRow][currCol] = currentSymbol;
        }

        if (strchr("<>^v", board[currRow][currCol].symbol)) {
            originalDestinationSymbols[currRow][currCol] = currentSymbol;
        }

        // Restore the previous symbol if this cell has been visited before
        if (i < startIndex) {
            board[currRow][currCol].symbol = previousSymbol;
        }

        // Actual path destination
        if (i == 0 && isDestination) {
            board[currRow][currCol].symbol = tolower(originalDestinationSymbols[currRow][currCol]);
            if (displayMode == 1) {
                printf("\n\nPickup Location: %s | Dropoff Location: %s", pickup, dropoff);
                printf(" - The path is ");
                for (int j = pathIndex - 1; j >= 0; j--)
                    printf("-> (%d,%d) ", path[j].x, path[j].y);

                printBoard(board);
                printf("Step: (%d, %d) -> Final Destination: '%c'\n", currRow, currCol, tolower(originalDestinationSymbols[currRow][currCol]));
                printf("Press Enter to continue...");
                getchar();  // Wait for user input
            }
        } 
        // Passing by a destination
        else if (isDestination) {
            board[currRow][currCol].symbol = '*';
            if (displayMode == 1) {
                printf("\n\nPickup Location: %s | Dropoff Location: %s", pickup, dropoff);
                printf(" - The path is ");
                for (int j = pathIndex - 1; j >= 0; j--)
                    printf("-> (%d,%d) ", path[j].x, path[j].y);

                printBoard(board);
                printf("Step: (%d, %d) -> Passing by %c, changed to: '*'\n", currRow, currCol, originalDestinationSymbols[currRow][currCol]);
                printf("Press Enter to continue...");
                getchar();  // Wait for user input
            }
            board[currRow][currCol].symbol = originalDestinationSymbols[currRow][currCol];
        } 
        // Non-destination cell
        else {
            char correctSymbol = ' ';
            if (nextRow != -1 && nextCol != -1) {
                if (currRow < nextRow) {
                    correctSymbol = 'v';
                } else if (currRow > nextRow) {
                    correctSymbol = '^';
                } else if (currCol < nextCol) {
                    correctSymbol = '>';
                } else if (currCol > nextCol) {
                    correctSymbol = '<';
                }
            }

            if (strchr("^v<>", board[currRow][currCol].symbol)) {
                // Step 1: Display the previous symbol
                board[currRow][currCol].symbol = previousSymbol;
                if (displayMode == 1) {
                    printf("\n\nPickup Location: %s | Dropoff Location: %s", pickup, dropoff);
	                printf(" - The path is ");
	                for (int j = pathIndex - 1; j >= 0; j--)
	                    printf("-> (%d,%d) ", path[j].x, path[j].y);
					
					printBoard(board);
                    printf("Step: (%d, %d) -> Previous direction: '%c'\n", currRow, currCol, previousSymbol);
                    printf("Press Enter to continue...");
                    getchar();  // Wait for user input
                }

                // Step 2: Display the correct symbol
                board[currRow][currCol].symbol = correctSymbol;
                if (displayMode == 1) {
                    printf("\n\nPickup Location: %s | Dropoff Location: %s", pickup, dropoff);
	                printf(" - The path is ");
	                for (int j = pathIndex - 1; j >= 0; j--)
	                    printf("-> (%d,%d) ", path[j].x, path[j].y);
					
					printBoard(board);
                    printf("Step: (%d, %d) -> Correct direction: '%c'\n", currRow, currCol, correctSymbol);
                    printf("Press Enter to continue...");
                    getchar();  // Wait for user input
                }

                // Mark the next cell with '+' if it's already visited
                if (originalDestinationSymbols[currRow][currCol] != 0) {
                    board[path[i + 1].x][path[i + 1].y].symbol = '+';
                    if (displayMode == 1) {
                        printf("\n\nPickup Location: %s | Dropoff Location: %s", pickup, dropoff);
	                printf(" - The path is ");
	                for (int j = pathIndex - 1; j >= 0; j--)
	                    printf("-> (%d,%d) ", path[j].x, path[j].y);
						
						printBoard(board);
                        printf("Step: (%d, %d) -> Marked with '+' for overlap\n", path[i + 1].x, path[i + 1].y);
                        printf("Press Enter to continue...");
                        getchar();  // Wait for user input
                    }
                }
            } else {
                board[currRow][currCol].symbol = correctSymbol;
            }
        }

        // Update previousSymbol for the next iteration
        previousSymbol = board[currRow][currCol].symbol;
    }

    if (displayMode == 2) {
        printf("\n\nPickup Location: %s | Dropoff Location: %s", pickup, dropoff);
        printf(" - The path is ");
        for (int j = pathIndex - 1; j >= 0; j--)
            printf("-> (%d,%d) ", path[j].x, path[j].y);
        printBoard(board);
    }

    printf("Gas consumed: %d\n", gas);
    return gas;
}


bool isValid(int row, int col)
{
	int valid = 1;
	if (row < 0 || row > MAX_GRID -1)
		valid = 0;
	if (col < 0 || col > MAX_GRID -1)
		valid = 0;
	
    return valid;
}

bool isDestination(int row, int col, desIdx dest)
{
    if (row == dest.x && col == dest.y)
        return (true);
    else
        return (false);
}

int aStarSearch(Node board[MAX_GRID][MAX_GRID], desIdx source, desIdx destination, int mode)
{

    bool closedList[MAX_GRID][MAX_GRID];
    
    for (int i=0; i<MAX_GRID; i++) {
    	for (int j=0; j<MAX_GRID; j++) {
    		closedList[i][j] = false;
    		board[i][j].gCost = board[i][j].fCost = board[i][j].hCost = 0;
    	}
	}
    		
    /*
     Create an open list having information as <f, <i, j>>
     where f = g + h, and i, j are the row and column index of that cell
     Note that 0 <= i <= ROW-1 & 0 <= j <= COL-1 This open list is implemented as a set of pair of pair.*/
     
	int i = source.x;
	int j = source.y;
    board[i][j].parent_x = i;
    board[i][j].parent_y = j;
     
     
     /// inside priority queue, dapat structy of PairPair
     
    Queue openList;
    initializeQueue(&openList);
    Enqueue(0, i, j, &openList, mode);   // 1 laman, in index 0

    // We set this boolean value as false as initially
    // the destination is not reached.
    int foundDest = 0;

    while (!queueEmpty(&openList)) {
    	PairPair tempPairPair = {0, {-1,-1}};
        Dequeue(&tempPairPair, &openList);   

        // Add this vertex to the closed list
        i = tempPairPair.innerPair.x;
        j = tempPairPair.innerPair.y;
        closedList[i][j] = true;
        
        if (board[i][j].gameOver == true)
        	return 2;


        double gNew, hNew, fNew;
//==========================================================
        //----------- 1st Successor (North) ------------

        // Only process this cell if this is a valid one
        
        if (isValid(i - 1, j) == true) {
            // If the destination cell is the same as the current successor
            if (isDestination(i - 1, j, destination) == true) {
                // Set the Parent of the destination cell
                board[i - 1][j].parent_x = i;
                board[i - 1][j].parent_y = j;
                foundDest = 1;
                return foundDest;
            }
            // If the successor is already on the closed list or if it is blocked, then ignore it. Else do the following
            else if (
				(mode == 2 && closedList[i - 1][j] == false && board[i - 1][j].blocked == false && board[i - 1][j].gameOver == false)
			|| 	(mode == 1 && closedList[i - 1][j] == false && board[i - 1][j].blocked == false)
			) {     // change!
                gNew = board[i][j].gCost + board[i-1][j].cost;
                hNew = manhattanDistance(i - 1, j, destination);
                fNew = gNew + hNew;

                // If it isn’t on the open list, add it to the open list. Make the current square the parent of this square. 
				// Record the f, g, and h costs of the square cell OR
                // If it is on the open list already, check to see if this path to that square is better, using 'f' cost as the measure.
                if (board[i - 1][j].fCost == 0 || board[i - 1][j].fCost > fNew) {
                    Enqueue(fNew, i-1, j, &openList, mode);

                    // Update the details of this cell
                    board[i - 1][j].fCost = fNew;
                    board[i - 1][j].gCost = gNew;
                    board[i - 1][j].hCost = hNew;
                    board[i - 1][j].parent_x = i;
                    board[i - 1][j].parent_y = j;
                }
            }
        }

		if (isValid(i + 1, j) == true) {
		    if (isDestination(i + 1, j, destination) == true) {
		        board[i + 1][j].parent_x = i;
		        board[i + 1][j].parent_y = j;
		        foundDest = 1;
		        return foundDest;
		    } else if (
				(mode == 2 && closedList[i + 1][j] == false && board[i + 1][j].blocked == false && board[i + 1][j].gameOver == false)
			|| 	(mode == 1 && closedList[i + 1][j] == false && board[i + 1][j].blocked == false)
			) {
		        gNew = board[i][j].gCost + board[i + 1][j].cost;
		        hNew = manhattanDistance(i + 1, j, destination);
		        fNew = gNew + hNew;
		
		        if (board[i + 1][j].fCost == 0 || board[i + 1][j].fCost > fNew) {
		            Enqueue(fNew, i + 1, j, &openList, mode);
		            board[i + 1][j].fCost = fNew;
		            board[i + 1][j].gCost = gNew;
		            board[i + 1][j].hCost = hNew;
		            board[i + 1][j].parent_x = i;
		            board[i + 1][j].parent_y = j;
		        }
		    }
		}
		
		if (isValid(i, j - 1) == true) {
		    if (isDestination(i, j - 1, destination) == true) {
		        board[i][j - 1].parent_x = i;
		        board[i][j - 1].parent_y = j;
		        foundDest = 1;
		        return foundDest;
		    } else if (
				(mode == 2 && closedList[i][j - 1] == false && board[i][j - 1].blocked == false && board[i][j - 1].gameOver == false)
			|| 	(mode == 1 && closedList[i][j - 1] == false && board[i][j - 1].blocked == false)
			) {
		        gNew = board[i][j].gCost + board[i][j - 1].cost;
		        hNew = manhattanDistance(i, j - 1, destination);
		        fNew = gNew + hNew;
		
		        if (board[i][j - 1].fCost == 0 || board[i][j - 1].fCost > fNew) {
		            Enqueue(fNew, i, j - 1, &openList, mode);
		            board[i][j - 1].fCost = fNew;
		            board[i][j - 1].gCost = gNew;
		            board[i][j - 1].hCost = hNew;
		            board[i][j - 1].parent_x = i;
		            board[i][j - 1].parent_y = j;
		        }
		    }
		}

		if (isValid(i, j + 1) == true) {
		    if (isDestination(i, j + 1, destination) == true) {
		        board[i][j + 1].parent_x = i;
		        board[i][j + 1].parent_y = j;
		        foundDest = 1;
		        return foundDest;
		    } else if (
				(mode == 2 && closedList[i][j + 1] == false && board[i][j + 1].blocked == false && board[i][j + 1].gameOver == false)
			|| 	(mode == 1 && closedList[i][j + 1] == false && board[i][j + 1].blocked == false)
			) {
		        gNew = board[i][j].gCost + board[i][j + 1].cost;
		        hNew = manhattanDistance(i, j + 1, destination);
		        fNew = gNew + hNew;
		
		        if (board[i][j + 1].fCost == 0 || board[i][j + 1].fCost > fNew) {
		            Enqueue(fNew, i, j + 1, &openList, mode);
		            board[i][j + 1].fCost = fNew;
		            board[i][j + 1].gCost = gNew;
		            board[i][j + 1].hCost = hNew;
		            board[i][j + 1].parent_x = i;
		            board[i][j + 1].parent_y = j;
		        }
		    }
		}



	}
	
    return foundDest;
}

