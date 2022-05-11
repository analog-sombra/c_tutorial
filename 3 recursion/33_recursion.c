// Recursion is a process in which a functin call itself directly or inderctly

int fun(int n)
{ 
    if(n == 1)
        return 1;
    else
        return 1 + fun(n-1);
}

int main()
{
    int n = 3;
    printf("%d",fun(n));
    return 0;
}