#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
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
///******************
/// PLAN: Multiplying of matrix, functions with vectors, dynamic array
///******************


struct Vector_t
{
    //#ifdef DEBUG
    int init;// for checking
    //#endif
    int x,y;
    int length;
};

void Vector_ctor (struct Vector_t* this, int x, int y)//constructor
{
    assert(this);
    this->init = 1;
    this->x = x;
    this->y = y;
    this->length = x + y;
}

void Vector_dtor(const struct Vector_t* this)
{
    //free
}

_Bool Vector_OK(const struct Vector_t* this)
{
    ///dblepsilon - corrections of double
    return this && (this->init);// && (this->x == this->len*cos(this->angle))
}

void Vector_Dump(const struct Vector_t* this)
{
    //printf();
    //return - ???
}

int main()
{
    int x = 0;
    struct Vector_t v1 = {1, 0}, v2 = {};
    Vector_ctor(&v1, 1, 0);
    Vector_ctor(&v2, 2, 3);
    v1.x += v2.x;
    v1.y += v2.y;
    PRINT(v1.x)
    PRINT(v1.y)
    printf("SIZEOF BOOL: %d\n", sizeof(_Bool));
    return 0;
}
