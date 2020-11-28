#include <stdio.h>
#include <cs50.h>

string check_type(int, int);

int main(void)
{
    long ccnum = get_long("Number: ");
    int length = 0;
    int sum = 0;
    int start;
    //gets sum of numbers by Luhn Algo
    while (ccnum > 0)
    {
        if (ccnum < 100 && ccnum >= 10)
        {
            //copies first two numbers
            start = ccnum;
        }
        length++;
        int num = ccnum % 10;
        if (length % 2 == 1)
        {
            //if odd adds number to sum
            sum += num;

        }
        else
        {
            //if even number, adds 2x the digits together and adds to sum
            int digits = num * 2;
            digits = (digits % 10) + (digits / 10);
            sum += digits;
        }
        ccnum = (ccnum - num) / 10;
    }
    if (sum % 10 == 0)
    {
        string type = check_type(length, start);
        printf("%s", type);
    }
    else
    {
        printf("INVALID\n");
    }
}

//returns which type of string it is, or invalid
string check_type(int length, int start)
{
    switch (length)
    {
        case 15:
            if (start == 34 || start == 37)
            {
                return "AMEX\n";
            }
            break;
        case 13:
            if (start / 10 == 4)
            {
                return "VISA\n";
            }
            break;
        case 16:
            if (start > 50 && start < 56)
            {
                return "MASTERCARD\n";
            }
            if (start / 10 == 4)
            {
                return "VISA\n";
            }
            break;
        default:
            return "INVALID\n";
    }
    return "INVALID\n";
}
