#include <stdio.h>
#include <cs50.h>

int get_valid_int(void);
void print_tower(int);

int main(void)
{
    int height = get_valid_int();
    print_tower(height);
}

//gets a valid int to print from the user
int get_valid_int(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    return n;
}

//prints tower
void print_tower(int height)
{
    int space = height - 1;
    int blocks = 1;

    do
    {
        //prints first half
        for (int i = 0; i < space; i++)
        {
            printf(" ");
        }
        for (int i = 0; i < blocks; i++)
        {
            printf("#");
        }
        //prints gap
        printf("  ");
        //prints second half and newline
        for (int i = 0; i < blocks; i++)
        {
            printf("#");
        }
        printf("\n");
        space--;
        blocks++;
        height--;
    }
    while (height);
}
