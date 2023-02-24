// A and B take turns playing a game, with A starting first.

// Initially, there is a number n on the chalkboard. On each player's turn, that player makes a move consisting of:
// Choosing any x with 0 < x < n and n % x == 0.
// Replacing the number n on the chalkboard with n - x.

// Also, if a player cannot make a move, they lose the game.
// Return true if and only if A wins the game, assuming both players play optimally.
 
// Example 1:
// Input: n = 2
// Output: true
// Explanation: A chooses 1, and B has no more moves.

#include <stdbool.h>
#include <stdio.h>

bool Game(int n)
{
    if(n==0)
        return false;
    if(n%2==0)
        return true;
    else
        return false;
}

int main()
{
    int n;
    scanf("%d", &n);
    if (Game(n) == true) 
    {     
        printf("true");
    }
    else 
    {
        printf("false");
    }
    return 0;
}