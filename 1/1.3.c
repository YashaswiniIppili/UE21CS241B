/* Alice and Bob each created one problem for HackerRank. A reviewer rates the two challenges, awarding points on a scale from 1 to 100 for three categories: problem clarity, originality, and difficulty.

The rating for Alice's challenge is the triplet a = (a[0], a[1], a[2]), and the rating for Bob's challenge is the triplet b = (b[0], b[1], b[2]).

The task is to find their comparison points by comparing a[0] with b[0], a[1] with b[1], and a[2] with b[2].

If a[i] > b[i], then Alice is awarded 1 point.
If a[i] < b[i], then Bob is awarded 1 point.
If a[i] = b[i], then neither person receives a point.
Comparison points is the total points a person earned.

Given a and b, determine their respective comparison points.
*/
#include <stdio.h>

int main()
{
    int a0,a1,a2; 
 
    scanf("%d %d %d",&a0,&a1,&a2);
    int b0,b1,b2;     
    int a_score = 0;
    int b_score = 0;
    scanf("%d %d %d",&b0,&b1,&b2);
    if (a0 > b0)
    {
        a_score++;
    }
    else if (a0 < b0)
    {
        b_score++;
    }
    
    if (a1 > b1)
    {
        a_score++;
    }
    else if (a1 < b1)
    {
        b_score++;
    }
    if (a2 > b2)
    {
        a_score++;
    }
    else if (a2 < b2)
    {
        b_score++;
    }
    printf("%d %d",a_score, b_score);            
	return 0;
}