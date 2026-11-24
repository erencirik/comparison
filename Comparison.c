#include <unistd.h>

void printnum(int n)
{
    char c;

    if (n == -2147483648)
    {
        write(1, "-2147483648", 11);
        return;
    }

    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }

    if (n >= 10)
        printnum(n / 10);

    c = (n % 10) + '0';
    write(1, &c, 1);
}

void compareints(int a, int b)
{
    printnum(a);

    if (a > b)
        write(1, " is greater than ", 17);
    else if (a == b)
        write(1, " is equal to ", 13);
    else
        write(1, " is smaller than ", 17);

    printnum(b);
    write(1, "\n", 1);
}

int main(void)
{
    compareints(25, 10);
    compareints(-8, 14);
    compareints(32, 32);

    return (0);
}
