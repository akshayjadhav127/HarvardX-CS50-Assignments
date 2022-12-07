#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n, i, j, k;
    do
    {
        //take user input
        n = get_int("Enter height here :"); // n is height
    }
    while (n < 1 || n > 8);

    for (i = 0; i < n; i++) // i is row
    {
        for (j = 0; j < n - i - 1; j++) // j is space
        {
            printf(" ");
        }
        for (k = 0; k <= i ; k++) // k is column
        {
            printf("#");
        }
        printf("  "); // for space between two pyramide
        for (k = 0; k <= i; k++)
        {
            printf("#"); //printing right side
        }
        printf("\n");
    }
}