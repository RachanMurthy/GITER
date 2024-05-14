#include <stdio.h>
#include <string.h>
#include <conio.h>

void main() {
    int table[126];
    char t[100], p[25];
    int n, i, k, j, m, flag = 0;

    clrscr();

    printf("Enter the text: ");
    gets(t);
    n = strlen(t);

    printf("Enter the pattern: ");
    gets(p);
    m = strlen(p);

    for (i = 0; i < 126; i++)
        table[i] = m;

    for (j = 0; j < m - 1; j++)
        table[(int)p[j]] = m - 1 - j;

    i = m - 1;
    while (i <= n - 1) {
        k = 0;
        while (k <= m - 1 && p[m - 1 - k] == t[i - k])
            k++;
        if (k == m) {
            printf("The position of the pattern is %d\n", i - m + 2);
            flag = 1;
            break;
        } else {
            i += table[(int)t[i]];
        }
    }

    if (!flag)
        printf("Pattern is not found in the given text\n");

    getch();
}
