double manhattanDistance(int row, int col, desIdx destination) {
    // Return using the distance formula
    int value = (abs(row-destination.x) + abs(col-destination.y));
    return value;
}

void markPath(Node board[][MAX_GRID], desIdx dest, int displayMode, String pickup, String dropoff) {
    int row = dest.x;
    int col = dest.y;

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
        int temp_row = board[row][col].parent_x;
        int temp_col = board[row][col].parent_y;
        row = temp_row;
        col = temp_col;
    }

    path[pathIndex].x = row;
    path[pathIndex].y = col;
    pathIndex++;

    // Iterate through the path in reverse to mark the directions
    for (int i = pathIndex - 1; i >= 0; i--) {
        int currRow = path[i].x;
        int currCol = path[i].y;
        int nextRow, nextCol;

        // Determine nextRow and nextCol
        if (i > 0) {
            nextRow = path[i - 1].x;
            nextCol = path[i - 1].y;
        } 
		else {
            nextRow = -1;
            nextCol = -1;
        }

        // If there's a previous cell, copy its symbol to the current cell
        if (i < pathIndex - 1) {
            board[currRow][currCol].symbol = board[path[i + 1].x][path[i + 1].y].symbol;
        }

        // Print the board and wait for user input before deciding if it's correct
        if (displayMode == 1) {
            system("cls");
            
            printf("--- %s to %s ---", pickup, dropoff);
			printf("\n - The path is ");
			for (int j = pathIndex - 1; j >= 0; j--)
				printf("-> (%d,%d) ", path[j].x, path[j].y);

            printBoard(board);
            printf("Step: (%d, %d) -> Symbol: '%c'\n", currRow, currCol, board[currRow][currCol].symbol);
            printf("Press Enter to continue...");
            getchar();  // Wait for user input
        }

        // Determine if the copied symbol is correct
        if (nextRow != -1 && nextCol != -1) {
            char correctSymbol;

            if (currRow < nextRow) {
                correctSymbol = 'V'; // Down
            } 
			else if (currRow > nextRow) {
                correctSymbol = '^'; // Up
            } 
			else if (currCol < nextCol) {
                correctSymbol = '>'; // Right
            } 
			else if (currCol > nextCol) {
                correctSymbol = '<'; // Left
            }

            // Check if the current symbol is correct
            if (board[currRow][currCol].symbol != correctSymbol) {
                // If incorrect, show it with the current (wrong) symbol
                if (displayMode == 1) {
                    system("cls");

                    printf("--- %s to %s ---", pickup, dropoff);
					printf("\n The path is ");
                    for (int j = pathIndex - 1; j >= 0; j--)
                        printf("-> (%d,%d) ", path[j].x, path[j].y);

                    printBoard(board);
                    printf("Step: (%d, %d) -> Direction: '%c' (Incorrect)\n", currRow, currCol, board[currRow][currCol].symbol);
                    printf("Press Enter to correct the direction...");
                    getchar();  // Wait for user input
                }

                // Update the symbol to the correct one
                board[currRow][currCol].symbol = correctSymbol;
            }
        }
    }

    if (displayMode == 2) {
        printf("--- %s to %s ---", pickup, dropoff);
        printf("\n - The path is ");
        for (int j = pathIndex - 1; j >= 0; j--)
            printf("-> (%d,%d) ", path[j].x, path[j].y);
        printBoard(board);
    }
}


// hindi ko na nagamit tong func 
// inintegrate ko siya sa markPath ~axl
void tracePath(Node board[][MAX_GRID], desIdx dest) {
    printf("\nThe Path is ");
    int row = dest.x;
    int col = dest.y;

    desIdx path[MAX_GRID*MAX_GRID];
    for (int i=0; i<MAX_GRID*MAX_GRID; i++) {
    	path[i].x = -1;
    	path[i].y = -1;
    	path[i].ID = -1;
	}
    
    int pathIndex = 0;

    // Traverse the path from destination to source
    while (!( board[row][col].parent_x == row && board[row][col].parent_y == col)) {
        path[pathIndex].x = row;
		path[pathIndex].y = col;
        pathIndex++;
        int temp_row = board[row][col].parent_x;
        int temp_col = board[row][col].parent_y;
        row = temp_row;
        col = temp_col;
    }

    path[pathIndex].x = row;
    path[pathIndex].y = col;
	pathIndex++;
    // Print the path in reverse
    for (int i = pathIndex - 1; i >= 0; i--) {
        printf("-> (%d,%d) ", path[i].x, path[i].y);
    }

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

bool aStarSearch(Node board[MAX_GRID][MAX_GRID], desIdx source, desIdx destination)
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
    Enqueue(0, i, j, &openList);   // 1 laman, in index 0

    // We set this boolean value as false as initially
    // the destination is not reached.
    bool foundDest = false;

    while (!queueEmpty(&openList)) {
    	PairPair tempPairPair = {0, {-1,-1}};
        Dequeue(&tempPairPair, &openList);   

        // Add this vertex to the closed list
        i = tempPairPair.innerPair.x;
        j = tempPairPair.innerPair.y;
        closedList[i][j] = true;


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
                foundDest = true;
                return foundDest;
            }
            // If the successor is already on the closed list or if it is blocked, then ignore it. Else do the following
            else if (closedList[i - 1][j] == false && board[i-1][j].blocked == false && board[i-1][j].gameOver == false) {     // change!
                gNew = board[i][j].gCost + board[i-1][j].cost;
                hNew = manhattanDistance(i - 1, j, destination);
                fNew = gNew + hNew;

                // If it isn’t on the open list, add it to the open list. Make the current square the parent of this square. 
				// Record the f, g, and h costs of the square cell OR
                // If it is on the open list already, check to see if this path to that square is better, using 'f' cost as the measure.
                if (board[i - 1][j].fCost == 0 || board[i - 1][j].fCost > fNew) {
                    Enqueue(fNew, i-1, j, &openList);

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
		        foundDest = true;
		        return foundDest;
		    } else if (closedList[i + 1][j] == false && board[i + 1][j].blocked == false && board[i + 1][j].gameOver == false) {
		        gNew = board[i][j].gCost + board[i + 1][j].cost;
		        hNew = manhattanDistance(i + 1, j, destination);
		        fNew = gNew + hNew;
		
		        if (board[i + 1][j].fCost == 0 || board[i + 1][j].fCost > fNew) {
		            Enqueue(fNew, i + 1, j, &openList);
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
		        foundDest = true;
		        return foundDest;
		    } else if (closedList[i][j - 1] == false && board[i][j - 1].blocked == false && board[i][j - 1].gameOver == false) {
		        gNew = board[i][j].gCost + board[i][j - 1].cost;
		        hNew = manhattanDistance(i, j - 1, destination);
		        fNew = gNew + hNew;
		
		        if (board[i][j - 1].fCost == 0 || board[i][j - 1].fCost > fNew) {
		            Enqueue(fNew, i, j - 1, &openList);
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
		        foundDest = true;
		        return foundDest;
		    } else if (closedList[i][j + 1] == false && board[i][j + 1].blocked == false && board[i][j + 1].gameOver == false) {
		        gNew = board[i][j].gCost + board[i][j + 1].cost;
		        hNew = manhattanDistance(i, j + 1, destination);
		        fNew = gNew + hNew;
		
		        if (board[i][j + 1].fCost == 0 || board[i][j + 1].fCost > fNew) {
		            Enqueue(fNew, i, j + 1, &openList);
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

