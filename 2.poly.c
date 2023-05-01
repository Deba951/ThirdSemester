#include <stdio.h>
struct polynomial
{
    int coefficient;
    int exponent;
};
struct polynomial poly1[20], poly2[20], poly3[20];

int scan(struct polynomial poly[20])
{
    int terms,i;

    printf("\nEnter total number of terms in the polynomial:");
    scanf("%d", &terms);

    printf("\nEnter the coefficient and exponent of the polynomial:\n");
    for (i = 0; i < terms; i++)
    {
        printf("\nEnter the %dth Coefficient: ", i + 1);
        scanf("%d", &poly[i].coefficient);
        printf("\nEnter the %dth exponent: ", i + 1);
        scanf("%d", &poly[i].exponent);
    }
    return (terms);
}
void PrintPoly(struct polynomial poly[20], int terms)
{
	
	int i;
    for (i = 0; i < terms - 1; i++)
    {
        printf("%d(x^%d)+", poly[i].coefficient, poly[i].exponent);
    }
    printf("%d(x^%d)", poly[terms - 1].coefficient, poly[terms - 1].exponent);
}
int addPoly(int terms1, int terms2)
{
    int i = 0, j = 0, totalterms = 0;

    while (i < terms1 && j < terms2)
    {
        if (poly1[i].exponent == poly2[j].exponent)
        {
            poly3[totalterms].coefficient = poly1[i].coefficient + poly2[j].coefficient;
            poly3[totalterms].exponent = poly1[i].exponent;

            i++;
            j++;
            totalterms++;
        }
        else if (poly1[i].exponent < poly2[j].exponent)

        {
            poly3[totalterms].coefficient = poly2[j].coefficient;
            poly3[totalterms].exponent = poly2[j].exponent;

            j++;
            totalterms++;
        }
        else
        {
            poly3[totalterms].coefficient = poly1[i].coefficient;
            poly3[totalterms].exponent = poly1[i].exponent;
            i++;
            totalterms++;
        }
    }

    while (i < terms1)
    {
        poly3[totalterms].coefficient = poly1[i].coefficient;
        poly3[totalterms].exponent = poly1[i].exponent;
        i++;
        totalterms++;
    }

    while (j < terms2)
    {
        poly3[totalterms].coefficient = poly2[j].coefficient;
        poly3[totalterms].exponent = poly2[j].exponent;
        j++;
        totalterms++;
    }

    return totalterms;
}

int main()
{
    int terms1, terms2, terms3;
    terms1 = scan(poly1);
    printf("\nFirst polynomial: ");
    PrintPoly(poly1, terms1);

    terms2 = scan(poly2);
    printf("\nSecond polynomial: ");
    PrintPoly(poly2, terms2);

    terms3 = addPoly(terms1, terms2);
    printf("\nAfter addition of polynomials: ");
    PrintPoly(poly3, terms3);
    printf("\n");

    return 0;
}
