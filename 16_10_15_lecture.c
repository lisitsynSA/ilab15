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

/// cache friendly mul of matrix
/// hardware
int main()
{
    return 0;
}
