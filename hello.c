#include <stdio.h>

int main()
{
    char a[50];
    int i = 0;

    printf("enter any text baby:- ");
    fgets(a, 50, stdin);

    for (i = 0; i < 10; i++)
    {
        printf("%s", a);
    }

    return 0;
}