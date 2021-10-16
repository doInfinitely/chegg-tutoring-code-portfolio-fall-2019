#include<stdio.h>
#include<time.h>
#include <stdlib.h>            // for random number generation


void printBoard(FILE *fp_out, char *a, char *p1, char *p2);        // print the board after every turn, showing the changes
char* moves(char *p, char *p_opp, char *board);                    // moves the player through the board
char* findHaven(char *p, char *board);
int main(void)
{
    srand(time(NULL));                                            // seed for the random number generator
    char out_file[] = "output.txt";                                // the output file
    FILE *fp_out;                                                // output file pointer
    fp_out = fopen(out_file, "a");                                // open the output file to write
    char board[100] = "  mHk nH l B He Flq p H  hByHlho H B  jr HFB ir j H  F ku gd  H pjB mH x  BF i H  m oB HlHFBhoH BB ";
    char *p1 = board;                                            // pointer for player 1
    char *p2 = board;                                            // pointer for player 2
    while (1)
    {
        printf("player 1: ");
        p1 = moves(p1, p2, board);                                    // call the move function on player 1, also passing player 2 so we can check for collisions
        if (p1 >= board + 100)                                    // if the player pointer is pointing at the end of the board, that player has won
        {
            printf("Player 1 has won the game\n");
            break;
        }
        printf("player 2: ");
        p2=moves(p2, p1, board);                                    // call the move function on player 1, also passing player 2 so we can check for collisions
        if (p2 >= board + 100)                                    // if the player pointer is pointing at the end of the board, that player has won
        {
            printf("Player 2 has won the game\n");
            break;
        }
        printBoard(fp_out, board, p1, p2);                        // calls the printBoard function after every turn
    }
    return 0;
}
//not all moves are changing the board as they are supposed to and when two players are in the same spot for some reason its not moving a player back 1 and printing the collision statement
char* moves(char *p, char *p_opp, char *board)                        // moves the player through the board
{
    int dice_roll = rand() % 6 + 1;                                // simulate a dice roll
    p=p+dice_roll; 
    printf("rolled %d...",dice_roll);
    if (p == p_opp)                                                // check again for a collision, after we have moved the player
    {
        printf("collision...moving back %d...", 1);
        p = p - 1;
    	if (p < board) {
		p = board;
	}
    }
    printf("now at %d\n",p-board);
    if (p >= board && p < board + 100)                            // make sure the player is still on the board
    {
        if (*p == 'B' || *p == 'F'){                        // check if the player has landed on a "go to haven" square
            p = findHaven(p, board);                            // call the findHaven function to find the nearest haven in the correct direction
        }else if(*p == 'H'){//if player lands directly on a Haven
            
            printf("Landed on a haven!\n");//if Haven is landed on return p
            return p;
        }
        else if(*p != ' ' && *p != '*' && *p != '-')                // check if the player has landed on a chute or a ladder
        {
            int sub_move = *p - 'n';                        // subtract the asci value of the chute or ladder symbol to determine how far to move
            *p = '-';                                            // "remove" the chute or ladder by replacing it with an -
            if (sub_move < 0)
            {
                if(p - board < (sub_move * -1)){//if our current p - the submove is to big we default it to 0
                    p = board;
                    
                }else{
                printf("landed on a chute...moving %d...", sub_move);
                p = p + sub_move;
                printf("Now at: %d\n", p- board);
                }
            }
            else
            {
                printf("landed on a ladder...moving %d...\n", sub_move);
                p = p + sub_move;
            }
        }else{
            
            return p;
        }
    }
    if (p == p_opp){                                                // check again for a collision, after we have moved the player
        printf("collision...moving back %d...", 1);
        p = p - 1;
    	if (p < board) {
		p = board;
	}
        printf("now at %d\n",p-board);
    }
    
    return p;
}
 
void printBoard(FILE *fp_out, char *a, char *p1, char *p2)        // print the board after every turn, showing the changes
{
    while (*a != '\0')                                            // while we haven't hit the end of the string
    {
        if (a == p1)
        {
            putc('1', fp_out);                                    // if the current character is where the player 1 is, print a 1
        }
        else if (a == p2)
        {
            putc('2', fp_out);                                    // if the current character is where the player 2 is, print a 2
        }
        else
        {
            putc(*a, fp_out);                                    // print the current character
        }
        a++;                                                    // move on to the next character of a
    }
    putc('\n', fp_out);                                            // go to the next line
}


//This function is what needs to be looked at when moving to find a haven one thing I notice is the map isnt changing as moves are done this is the same for chutes and ladders
char* findHaven(char *p, char *board)                                // finds the next haven on the board, either forward or backward
{
    int count = 0;
    if (*p == 'B')                                                // check if this is a directive to move forward or backward to a haven
    {
        while (*p != 'H' && p != board)                            // make sure we are staying on the board
        {
            p = p - 1; 
            count = count - 1;
        }
        printf("moving backward to haven...\n");
        if (p == board)                                            // if we are at the beginning of the board, there must not have been any havens left, so we go to zero
        {
            printf("no havens left...\n");
        }
        else                                                    // if we did find a haven, remove it so it cant be used again
        {
            *p = '*';
        } 
    }
    else
    {
        while (*p != 'H' && p < board + 100)                    // make sure we are staying on the board
        { 
            p = p + 1;
            count = count + 1;
        }
        printf("moving forward to haven...\n");
        if (p == board+100)                                        // if we are at the end of the board, there must not have been any havens left, so we stay where we were
        { 
            printf("no havens left...\n");
            count = 0;
        }
        else
        {
            *p = '*';                                            // if we did find a haven, remove it so it cant be used again
        }
    }
    return p;
}
