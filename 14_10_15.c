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
///******************
/// Multiplying of matrix, functions with vectors, dynamic array
///******************


struct Matrix_type
{
    //#ifdef DEBUG
    int init;// for checking
    //#endif
    int x,y;
    double * array;
    int length;
}; // + functions

typedef struct Matrix_type Matrix_t;

void Matrix_ctor (Matrix_t* this, int x, int y)//constructor
{
    assert(this);
    this->init = 1;
    this->x = x;
    this->y = y;
    this->length = y*x;
    this->array = (double*) calloc(y*x, sizeof(double));// malloc + array[i][j] = 0
}

void Matrix_dtor(const Matrix_t* this)
{
    assert(this);
    free(this->array);
}

int Matrix_OK(const Matrix_t* this)
{
    ///dblepsilon - corrections of double
    return this && this->init && this->array;// && (this->x == this->len*cos(this->angle))
}

void Matrix_Dump(const Matrix_t* this, int line)
{
    //if (!Matrix_OK(this))
    //    return 0;
    printf("-------\n"\
           "MATRIX: %d x %d (LINE = %d)\n\n"\
           , this->x, this->y, line);
    int x = 0, y = 0;
    for (y = 0; y < this->y; y++)
    {
        for (x = 0; x < this->x; x++)
            printf("%3.lg", this->array[y*this->x + x]);
        printf("\n");
    }
    printf("-------\n");
    //printf();
    //return - ???
}

#define MATRIX_DUMP(X) assert(Matrix_OK(&X)); Matrix_Dump(&X, __LINE__);

int main()
{
    int x = 0;
    Matrix_t mat_1 = {};
    Matrix_ctor(&mat_1, 7, 5);
    MATRIX_DUMP(mat_1)
    Matrix_dtor(&mat_1);
    return 0;
}

