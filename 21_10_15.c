#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct {
    unsigned int x;
    unsigned int y;
    double * array;
    unsigned int length;
} Matrix_t;

void Matrix_ctor(Matrix_t* This, int x, int y)
{
    assert(This);
    This->x = x;
    This->y = y;
    This->length = x*y;
    This->array = (double *) calloc(x*y, sizeof(double)); // malloc = calloc + memset
}

void Matrix_dtor(Matrix_t* This)
{
    assert(This);
    free(This->array);
}

void Matrix_Dump(Matrix_t* This, int line)
{
    assert(This);
    printf("-------\n"\
           "MATRIX: %d x %d (LINE = %d)\n\n"\
           , This->x, This->y, line);
    int x = 0, y = 0;
    for (y = 0; y < This->y; y++)
    {
        for (x = 0; x < This->x; x++)
            printf("%3lg", This->array[y*This->x + x]);
        printf("\n");
    }
    printf("-------\n");
}

int Matrix_OK(Matrix_t* This)
{
    return This && This->array && This->x && This->y && (This->length == This->x*This->y);
}

double Matrix_get_element(Matrix_t* This, int x, int y)
{
    assert(Matrix_OK(This));
    return This->array[y*This->x + x];
}

double Matrix_set_element(Matrix_t* This, int x, int y, double value)
{
    return This->array[y*This->x + x] = value;
}

int Matrix_sum(Matrix_t* This1, Matrix_t* This2, Matrix_t* This_res)
{
    //assert()
    int x = 0, y = 0;
    for (y = 0; y < This_res->y; y++)
    for (x = 0; x < This_res->x; x++)
        This_res->array[y*This_res->x + x] = This1->array[y*This_res->x + x] + This2->array[y*This_res->x + x];
}

int Matrix_mul(Matrix_t* This1, Matrix_t* This2, Matrix_t* This_res)
{

}

int Matrix_mul_num(double mul, Matrix_t* This, Matrix_t* This_res)
{

}

int Matrix_trans(Matrix_t* This, Matrix_t* This_res)
{

}

double Matrix_det(Matrix_t* This)
{
    assert(Matrix_OK(This) && "This matrix isn't OK in Matrix_det");
    assert((This->x == This->y) && "This matrix isn't square");
}

#define MATRIX_DUMP(X)  assert(Matrix_OK(&(X))); Matrix_Dump(&X, __LINE__);


int main(int argc, char** argv)
{
    int size = 0;

    while (size <= 0)
    {
        printf("Enter size of matrix:");
        scanf("%d", &size);
        printf("\n");
    }
    Matrix_t mat_array[3] = {};
    Matrix_ctor(&mat_array[0], size, size);
    Matrix_ctor(&mat_array[1], size, size);
    Matrix_ctor(&mat_array[2], size, size);

    int done = 1;
    int cmd = 0;
    while(done != 0)
    {
        // print help
        #define CMD_(code, desc, todo, tmp_value) printf("%d - " #desc "\n", code);
        #include "cmd.h"
        #undef CMD_
        scanf("%d", &cmd);
        switch (cmd)
        {
        default:
            printf("I don't know This command\n");
            break;
        // choose command, create  and do todo
        #define CMD_(code, desc, todo, tmp_value) case code: {tmp_value; todo;} break;
        #include "cmd.h"
        #undef CMD_
        }
    }
    Matrix_dtor(&mat_array[0]);
    Matrix_dtor(&mat_array[1]);
    Matrix_dtor(&mat_array[2]);
    return 0;
}
