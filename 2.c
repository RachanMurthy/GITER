#include<stdio.h>
#include<string.h>

// Function to shift characters to the right in a string
int shift_r(char t[], int s, int d) {
    int i;
    int n = strlen(t);
    for (i = n - 1; i >= s + d; i--) {
        t[i + d] = t[i];
    }
    t[n + d] = '\0';
    return 0;
}

// Function to shift characters to the left in a string
int shift_l(char t[], int s, int d) {
    int i;
    int n = strlen(t);
    for (i = s + d; i < n; i++) {
        t[i - d] = t[i];
    }
    t[n - d] = '\0';
    return 0;
}

// Function to replace a pattern in a string with another string
void pattern(char t[], char p[], char r[]) {
    int n = strlen(t);
    int m = strlen(p);
    int l = strlen(r);
    int d = l - m;

    for (int s = 0; s <= n - m; s++) {
        if (strncmp(t + s, p, m) == 0) {
            // Shift characters to make space for string r
            if (d < 0) {
                shift_l(t, s, -d);
            } else if (d > 0) {
                shift_r(t, s, d);
            }
            // Embed r into t
            for (int i = 0; i < l; i++) {
                t[s + i] = r[i];
            }
            s += l - 1; // Adjust the index after replacement
        }
    }
}

// Main function
int main() {
    char t[50], p[10], r[10];

    printf("Enter t: ");
    fgets(t, sizeof(t), stdin);
    t[strcspn(t, "\n")] = 0; // Remove newline character

    printf("Enter p: ");
    fgets(p, sizeof(p), stdin);
    p[strcspn(p, "\n")] = 0;

    printf("Enter r: ");
    fgets(r, sizeof(r), stdin);
    r[strcspn(r, "\n")] = 0;

    pattern(t, p, r);

    printf("Modified t: %s\n", t);
    return 0;
}
