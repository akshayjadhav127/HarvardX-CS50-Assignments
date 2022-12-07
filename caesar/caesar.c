#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2) //for getting only two keys 1 and 2
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i])) //cs50 isdigit function
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int k = atoi(argv[1]);

    string plaintext = get_string("Plaintext: ");
    printf("Ciphertext: ");

    for (int j = 0; j < strlen(plaintext); j++)
    {
        if (isupper(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 65 + k) % 26 + 65);
            // taking 65 for uppercase letters
            // example let consider plaintext is Z
            // Z ascii value is 90
            // 90 -65 = 25 --- 25 + k (1 or 2)
            // 25 + 1 = 26 and 26 % 25 = 0
            // 0 + 65 = 65 --- giving ascii value of A
        }

        else if (islower(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 97 + k) % 26 + 97);
            //taking 97 for lowercase letter
        }

        else
        {
            printf("%c", plaintext[j]);
        }
    }

    printf("\n");
}