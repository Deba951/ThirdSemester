// Write a program to count the frequency of each distinct character in a given string.
#include <stdio.h>
#include <string.h>
void count(char s[])
{
    int i, j, k, n, count = 0;
    for (j = 0; s[j]; j++)
        n = j;
    for (i = 0; i < n; i++)
    {
        count = 1;
        if (s[i])
        {
            for (j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    count++;
                    s[j] = '\0';
                }
            }
            printf("'%c' = %d \n", s[i], count);
        }
    }
}

int main()
{
    char s[100];
    int n;
    printf("Enter the string : ");
    gets(s);
    printf("\nFrequency count character in string:\n");
    count(s);
    return 0;
}
