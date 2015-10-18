#include <stdio.h>
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
struct Test_type{
    char a;
    char c[6];
    short b;
    int d;
    char e;
};
typedef struct Test_type Test_t;

int main()
{
    Test_t test = {7, 13, 5, 9};
    printf("SIZEOF STRUCT: %d\n\n", sizeof(Test_t));
    PRINT(test.a)
    PRINT(test.b)
    PRINT(test.c)
    PRINT(test.d)
    PRINT(test.e)

    return 0;
}
