/* 
Last Updated:
    Lian
    11:13 PM
    10/21/2024
*/
#include <stdio.h>

int inputMode(){
    int mode;
    printf(
        "\nMODE:\n"
        "[1] Dumb\n"
        "[2] Smart\n"
    );
    do{
        printf("\nEnter mode: ");
        scanf("%d", &mode);
        if (mode < 1 || mode > 2)
            printf("Invalid input.\n");
    } while (mode < 1 || mode > 2);
    return mode;
}
int inputDifficulty(){
    int diff;
    printf(
        "\nDIFFICULTY:\n"
        "[1] Easy\n"
        "[2] Medium\n"
        "[3] Hard\n"
    );
    do{
        printf("\nEnter difficulty: ");
        scanf("%d", &diff);
        if (diff < 1 || diff > 3)
            printf("Invalid input.\n");
    } while (diff < 1 || diff > 3);
    return diff;
}

int inputDisplayMode(){
	int mode;
    printf(
        "\nDISPLAY MODE:\n"
        "[1] Slow\n"
        "[2] Fast\n"
    );
    do{
        printf("\nEnter mode: ");
        scanf("%d", &mode);
        if (mode < 1 || mode > 2)
            printf("Invalid input.\n");
    } while (mode < 1 || mode > 2);
    return mode;
}

int checkDuplicate(String array[], int n, String key){
  for (int x = 0; x < n; x++){
    if (strcmp(array[x], key) == 0)
      return 1;
  }
  return 0;
}

int inputPassenger(desType destinations[], int idx, int x, desType inpDest[]){
    int inp = -1, nPsgr = 0, max = destinations[idx].numPassengers, dup;
    printf("\nPASSENGERS (%s):\n", destinations[idx].name);
    for (int i = 0; i <= max; i++){
        if (i != max)
            printf("[%d] %s\n", i+1, destinations[idx].passengers[i]);
        else
            printf("[%d] DONE\n\n", i+1);
    }
    for (int i = 0; i < max && inp != max+1; i++){
        do{
          dup = 0;
            printf("Enter passenger %d: ", i+1);
            scanf("%d", &inp);
            if (inp < 1 || inp > max+1)
                printf("Invalid input.\n\n");
            else if (nPsgr == 0 && inp == max+1)
              printf("Choose at least one passenger.\n\n");
      else if (nPsgr != 0 && inp != max+1){
              dup = checkDuplicate(inpDest[x].passengers, nPsgr, destinations[idx].passengers[inp-1]);
              if (dup == 1)
                printf("Invalid input. No duplicates allowed.\n\n");
      }
        } while ( (inp < 1 || inp > max+1) || (nPsgr == 0 && inp == max+1) || (dup == 1) );
        if (inp != max+1){
            strcpy(inpDest[x].passengers[i], destinations[idx].passengers[inp-1]);
            nPsgr++;
        }
    }
    return nPsgr;
}

int inputDestination(desType destinations[], desType inpDest[], int diff){
    int numDest, inp, idx, dup;
    String tempDest[4];
    if (diff == 1) numDest = 2;
    else if (diff == 2) numDest =  4;
    else numDest = 6;

    if (numDest != 6){
        for (int x = 0; x < numDest; x++){
          printf(
            "\nDESTINATIONS:\n"
            "[1] Bel-Air\n"
            "[2] Courtyard\n"
            "[3] Manila\n"
            "[4] South Luzon\n"
            "[5] Sta Rosa\n"
            "[6] Malamig\n\n"
        );
        do{
          printf("Enter destination %d: ", x+1);
              scanf("%d", &inp);
              idx = inp - 1;
              if (inp < 1 || inp > 6)
                printf("Invalid input.\n");
              else if (x != 0){
              dup = checkDuplicate(tempDest, x, destinations[idx].name);
              if (dup == 1)
                printf("Invalid input. No duplicates allowed.\n\n");
        }
      } while (inp < 1 || inp > 6 || dup == 1);
            inpDest[x].index = idx;
            strcpy(inpDest[x].name, destinations[idx].name);
            strcpy(tempDest[x], destinations[idx].name);
            inpDest[x].numPassengers = inputPassenger(destinations, idx, x, inpDest);
        }
    } else {
        for (int x = 0; x < numDest; x++){
            inpDest[x].index = x;
            strcpy(inpDest[x].name, destinations[x].name);
            inpDest[x].numPassengers = inputPassenger(destinations, x, x, inpDest);
        }
    }

    return numDest;
}
