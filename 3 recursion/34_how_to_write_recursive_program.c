// Idea
// 1. Divide the problem into smaller subproblems
// 2. Specify the base case to stop the recursion

// For eg. Calculate the factorial of a number

// Basic Structure
/*Fact()
{
    if(  )
    {
        ...
    }
    else
    {
        ...
    }
} */

// 1. Divide the  problem into smaller subproblem
// calculate fact(4)
// fact(1) = 1
// fact(2) = 2 * 1 = 2 * fact(1)
// fact(3) = 3 * 2 * 1 = 3 * fact(2)
// fact(4) = 4 * 3 * 2 * 1 = 4 * fact(3)
// Therefor fact(n) = n * fact(n-1)

// 2. Specify the base case to stop the recursion
// Base condition is the one which doesn't require to call the some function again and it help in stopping the recursion
// SO
/*Fact(int n)
{
    if( n==1 )
    {
        return 1
    }
    else
    {
        return n * Fact(n-1)
    }
} */