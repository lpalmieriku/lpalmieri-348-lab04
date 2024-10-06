/*
Name: Lena Palmieri
KUID: 3115099
Date: 10/3/24
Lab: lab04
Last Modified: 10/6/24
Purpose: Asks the user to enter a valid NFL score and the program outputss all the possible ways to reach that score in a game
*/

#include <stdio.h>
//Function that takes in all the values of each way to score and prints the informatino in the correct format
void printScore(int td2, int td1, int td, int fg, int s) {
    printf("%lu TD + 2pt, %lu TD + FG, %lu TD, %lu 3pt FG, %lu Safety\n", td2, td1, td, fg, s);
}

int main() {
    //Initializes an array to take in all the user's NFL scores
    int nums[100];
    int score, pos;

    //Allows user to input their first NFL score
    printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
    scanf("%lu", &score);
     
    //Asks the user to keep inputting scores if they do not enter 0 or 1
    //Checks each input to make sure it is a valid NFL score, if not the user inputs a valid NFL score
    //Adds score to array if user inputs a valid NFL score
    while (score != 0 && score != 1) {
        if (score < 0) {
            printf("Invalid NFL score entered!\nEnter the NFL score: ");
            scanf("%lu", &score);
        }
        else {
            nums[pos] = score;
            printf("Enter the NFL score: ");
            scanf("%lu", &score);
            pos++;
        }
    }
    //Adds the terminating NFL score, so the program knows when to stop looping through the nums array
    nums[pos] = score;

    //Loops through each of the scores the user inputted
    for(int i = 0; i < 100; i++) {
        score = nums[i];
        //Leaves the loop if the terminating score is found
        if (score < 2) {
            break;
        }
        //Initializes and calculates the maximum amount of each score type for the particular score
        int maxTD = score/6, maxF = score/3, maxS = score/2, maxTD1 = score/7, maxTD2 = score/8;
        //Loops through scorig method starting with the greatest number and adds all of the looped through scoring methods up
        //If it equals the score, then that combination of scoring methods is printed
        //If it is less than the score, then we loop into the next scoring method and repeat the same process
        for (int td2 = maxTD2; td2 > -1; td2--) {
            if (td2*8 == score) {
                printScore(td2,0,0,0,0);
            }
            else if (td2*8 < score) {
                for (int td1 = maxTD1; td1 > -1; td1--) {
                    if(td2*8 + td1*7 == score) {
                        printScore(td2,td1,0,0,0); 
                    }
                    else if (td2*8 + td1*7 < score) {
                        for (int td = maxTD; td > -1; td--) {
                            if (td2*8 + td1*7 + td*6 == score) {
                                printScore(td2,td1,td,0,0);
                            }
                            else if (td2*8 + td1*7 + td*6 < score) {
                                for (int fg = maxF; fg > -1; fg--) {
                                    if (td2*8 + td1*7 + td*6 + fg*3 == score) {
                                        printScore(td2,td1,td,fg,0);
                                    }
                                    else if (td2*8 + td1*7 + td*6 + fg*3 < score) {
                                        for (int s = maxS; s > -1; s--) {
                                            if (td2*8 + td1*7 + td*6 + fg*3 + s*2 == score) {
                                                printScore(td2,td1,td,fg,s);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("\n");
    }
    


    


}