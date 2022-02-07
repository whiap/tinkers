#include <stdio.h>

extern char** environ;

int main()
{
    // The ENVIRON variable contains the environment
    // getenv + setenv + unsetenv

    char** var = NULL;
    for (var = environ; *var != NULL; ++var) {
        printf("env %s\n", *var);
    }
    return 0;
}
