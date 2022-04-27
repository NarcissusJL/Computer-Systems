#include <stdio.h>
#include <string.h>

int hash(const char *s)
{
    int value = 0;
    for (int i = 0; i < strlen(s); i++)
        value += s[i] * (i + 1);
    return value;
}

int main(int argc, char **argv)
{
    FILE *f = fopen(argv[1], "r");
    char word[64];
    int length[1000] = {0};
    while (fgets(word, 64, f))
    {
        if (word[strlen(word) - 1] == '\n')
            word[strlen(word) - 1] = '\0';
        int slot = hash(word) % 1000;
        length[slot]++;
    }
    for (int i = 0; i < 1000; i++)
        printf("%d\t%d\n", i, length[i]);

    return 0;
}