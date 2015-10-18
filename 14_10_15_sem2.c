#include <stdio.h>
#include <assert.h>

typedef struct {
    unsigned int x;
    unsigned int y;
    double * array;
    unsigned int length;
} Matrix_t;

void Matrix_ctor(Matrix_t* this, int x, int y)
{
    assert(this);
    this->x = x;
    this->y = y;
    this->length = x*y;
    this->array = (double *) calloc(x*y, sizeof(double)); // malloc = calloc + memset
}

void Matrix_dtor(Matrix_t* this)
{
    assert(this);
    free(this->array);
}

void Matrix_Dump(Matrix_t* this, int line)
{
    assert(this);
    printf("-------\n"\
           "MATRIX: %d x %d (LINE = %d)\n\n"\
           , this->x, this->y, line);
    int x = 0, y = 0;
    for (y = 0; y < this->y; y++)
    {
        for (x = 0; x < this->x; x++)
            printf("%3lg", this->array[y*this->x + x]);
        printf("\n");
    }
    printf("-------\n");
}

int Matrix_OK(Matrix_t* this)
{
    return this && this->array && this->x && this->y && (this->length == this->x*this->y);
}

double Matrix_get_element(Matrix_t* this, int x, int y)
{
    assert(Matrix_OK(this));
    return this->array[y*this->x + x];
}

double Matrix_set_element(Matrix_t* this, int x, int y, double value)
{
    return this->array[y*this->x + x] = value;
}

int Matrix_sum(Matrix_t* this1, Matrix_t* this2, Matrix_t* this_res)
{
    //assert()
    int x = 0, y = 0;
    for (y = 0; y < this_res->y; y++)
    for (x = 0; x < this_res->x; x++)
        this_res->array[y*this_res->x + x] = this1->array[y*this_res->x + x] + this2->array[y*this_res->x + x];
}

int Matrix_mul(Matrix_t* this1, Matrix_t* this2, Matrix_t* this_res)
{

}

int Matrix_mul_num(double mul, Matrix_t* this, Matrix_t* this_res)
{

}

int Matrix_trans(Matrix_t* this, Matrix_t* this_res)
{

}

double Matrix_det(Matrix_t* this)
{
    assert(Matrix_OK(this) && "This matrix isn't OK in Matrix_det");
    assert((this->x == this->y) && "This matrix isn't square");
}

#define MATRIX_DUMP(X)  assert(Matrix_OK(&X)); Matrix_Dump(&X, __LINE__);


int main()
{

    Matrix_t mat_1 = {}, mat_2 = {}, mat_3 = {};
    Matrix_ctor(&mat_1, 3, 3);
    Matrix_ctor(&mat_2, 3, 3);
    Matrix_ctor(&mat_3, 3, 3);
    Matrix_set_element(&mat_2, 2, 2, Matrix_set_element(&mat_1, 0, 0, 10.0));
    MATRIX_DUMP(mat_1)
    MATRIX_DUMP(mat_2)
    Matrix_sum(&mat_1, &mat_2, &mat_3);
    MATRIX_DUMP(mat_3)
    Matrix_dtor(&mat_1);
    Matrix_dtor(&mat_2);
    Matrix_dtor(&mat_3);
    return 0;
}
