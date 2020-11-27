#include <cs50.h>
#include <stdio.h>

int main(void)
{
    /*gets a name from user */
    string name = get_string("What is your name?\n");
    printf("Hello, %s\n", name);
}
