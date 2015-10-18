#include <stdio.h>

#define PRINT(X) printf(#X" = %d (LINE = %d)\n"\
                        "sizeof(" #X ") = %d\n"\
                        "&" #X " = %d\n"\
                        "sizeof(&(" #X ")) = %d\n\n",\
                         X, __LINE__, sizeof(X), &(X), sizeof(&X));
#define PRINT_PTR(X) printf(#X" = %d (LINE = %d)\n"\
                        "sizeof(" #X ") = %d\n"\
                        /*"&" #X " = %d\n"\
                        "sizeof(&" #X ") = %d\n"*/\
                        "*" #X " = %d\n"\
                        "sizeof(*(" #X ")) = %d\n\n",\
                        X, __LINE__, sizeof(X), /*&(X), sizeof(&(X)),*/ *(X), sizeof(*(X)));
enum enum_type {CHAR_T, INT_T};
typedef enum enum_type type_t;
void print_int(void* ptr);
void print_char(void* ptr);
void print(void* ptr, type_t type);

int main()
{
    char a = 7;
    PRINT(a)
    char array[5] = {0};
    array[0] = 25;
    array[1] = 3;
    array[3] = 12;
    //PRINT_PTR(array)
    //PRINT_PTR(array + 3)

    void * ptr = array;
    print(&a, CHAR_T);
    //PRINT_PTR((int*)ptr)
    /*PRINT_PTR((int*)(ptr+1))
    PRINT_PTR((int*)(ptr+2))
    PRINT_PTR((int*)(ptr+3))
    PRINT_PTR((int*)(ptr+4))*/



    return 0;
}

void print(void* ptr, type_t type)
{
    switch(type)
    {
    default:
        break;
    case INT_T:
        PRINT_PTR((int*)ptr)
        break;
    case CHAR_T:
        PRINT_PTR((char*)ptr)
        break;
    }
}

void print_int(void* ptr)
{
    PRINT_PTR((int*)ptr)
}

void print_char(void* ptr)
{
    PRINT_PTR((char*)ptr)
}
