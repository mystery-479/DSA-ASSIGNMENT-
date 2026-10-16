#include <stdio.h>

typedef struct
{
    int degree;
    float coef[101];
} polynomial;

polynomial add(polynomial a, polynomial b)
{
    polynomial c;
    int i;

    c.degree = (a.degree > b.degree) ? a.degree : b.degree;

    for (i = 0; i <= c.degree; i++)
        c.coef[i] = 0;

    for (i = 0; i <= a.degree; i++)
        c.coef[c.degree - a.degree + i] += a.coef[i];

    for (i = 0; i <= b.degree; i++)
        c.coef[c.degree - b.degree + i] += b.coef[i];

    return c;
}

void display(polynomial p)
{
    int i, exp, first = 1;

    for (i = 0; i <= p.degree; i++)
    {
        if (p.coef[i] == 0)
            continue;

        exp = p.degree - i;

        if (!first && p.coef[i] > 0)
            printf(" + ");
        else if (p.coef[i] < 0)
            printf(" - ");

        if (p.coef[i] < 0)
            printf("%.2f", -p.coef[i]);
        else
            printf("%.2f", p.coef[i]);

        if (exp > 1)
            printf("x^%d", exp);
        else if (exp == 1)
            printf("x");

        first = 0;
    }

    if (first)
        printf("0");

    printf("\n");
}

int main()
{
    polynomial a, b, c;
    int i;

    printf("Enter degree of first polynomial: ");
    scanf("%d", &a.degree);

    printf("Enter coefficients from highest degree to constant:\n");
    for (i = 0; i <= a.degree; i++)
        scanf("%f", &a.coef[i]);

    printf("Enter degree of second polynomial: ");
    scanf("%d", &b.degree);

    printf("Enter coefficients from highest degree to constant:\n");
    for (i = 0; i <= b.degree; i++)
        scanf("%f", &b.coef[i]);

    c = add(a, b);

    printf("First polynomial: ");
    display(a);

    printf("Second polynomial: ");
    display(b);

    printf("Sum: ");
    display(c);

    return 0;
}
