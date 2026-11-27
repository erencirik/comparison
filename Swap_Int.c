
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

void Swap_Int(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;

    printnum(*a);
    write(1, " ", 1);
    printnum(*b);
    write(1, "\n", 1);
}

int main(void)
{
    int x;
    int y;

    x = 10;
    y = 20;

    Swap_Int(&x, &y);

    return (0);
}
