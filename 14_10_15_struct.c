#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#define PRINT(X) printf(#X" = %d (LINE = %d)\n"\
                        "sizeof(" #X ") = %d\n"\
                        "&" #X " = %d\n"\
                        "sizeof(&(" #X ")) = %d\n\n",\
                         X, __LINE__, sizeof(X), &(X), sizeof(&X));
#define PRINT_PTR(X) printf(#X" = %d (LINE = %d)\n"\
                        "sizeof(" #X ") = %d\n"\
                        "*" #X " = %d\n"\
                        "sizeof(*(" #X ")) = %d\n\n",\
                        X, __LINE__, sizeof(X), *(X), sizeof(*(X)));
#define PRINT_STRUCT(X) printf("STRUCT: "#X" = %d (LINE = %d)\n"\
                        "sizeof(" #X ") = %d\n\n",\
                         X, __LINE__, sizeof(X));
struct Test_t{
    int a;
    char b[9];
    char c;
    int d;
};
int main()
{
    struct Test_t test = {7, 5, 3};
    printf("STRUCT : size = %d\n\n", sizeof(test));
    PRINT_STRUCT(test)
    PRINT(test.a)
    PRINT(test.b)
    PRINT(test.c)
    PRINT(test.d)
    return 0;
}
