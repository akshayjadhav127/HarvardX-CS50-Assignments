#include <cs50.h>
#include <stdio.h>

bool check_sum(long num); //another function called for checking sum

int main(void)
{
    int digits = 0, single_digit = 0, two_digit = 0;
    bool checksum;
    long user_input = get_long("Card No: "); //getting card no from user
    checksum = check_sum(user_input); //checking sum of numbers

    if (checksum == false)
    {
        return 0;
    }

    while (user_input > 0)
    {
        if (user_input < 10)
        {
            single_digit = user_input;
        }
        if (user_input > 10 && user_input < 100)
        {
            two_digit = user_input;
        }
        user_input /= 10;
        digits ++;
    }

    //AMERICAN EXPRESS
    if ((two_digit == 34 || two_digit == 37) && digits == 15) //condition for american express
    {
        printf("AMEX\n");
        return 0;
    }

    //MASTERCARD
    else if ((two_digit == 51 || two_digit == 52 || two_digit == 53 || two_digit == 54 || two_digit == 55) && digits == 16) //condition for master card
    {
        printf("MASTERCARD\n");
        return 0;
    }

    //VISA
    else if (single_digit == 4 && (digits == 13 || digits == 16)) //condition for visa
    {
        printf("VISA\n");
        return 0;
    }

    else
    {
        printf("INVALID\n");
    }
    return 0;
}

//checcking sum for input given by user
bool check_sum(long num)
{
    int total = 0, buffer = 0;
    bool var = true;
    while (num > 0)
    {
        if (var == true)
        {
            total += num % 10;
            num /= 10;
            var = false;
        }
        else
        {
            buffer = num % 10;
            buffer *= 2;
            if (buffer >= 10)
            {
                total += buffer % 10;
                total += buffer / 10;
            }
            else
            {
                total += buffer;
            }
            var = true;
            num /= 10;
        }
    }
    printf("total: %i\n", total);
    if (total % 10 == 0)
    {
        return true;
    }
    printf("INVALID\n");
    return false;
}