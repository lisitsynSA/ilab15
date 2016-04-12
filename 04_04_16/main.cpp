#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#define LENGTH 100

char * S;
int Error;

double GetNum(); // get number
void GetS(); // get simbol
double GetExp(); // get expression
double GetP(); // get '( )' or NUM

int main()
{
    const char* Namefile = "exp.txt";
    FILE * File = fopen(Namefile, "r");
    char * string = (char*) calloc(LENGTH, sizeof(char));
    fgets(string, LENGTH, File);
    fclose(File);
    S = string;
    Error = 0;
    printf("ANSWER: %lg\n", GetExp());
    if (Error)
        printf("Error exists!!!!!!\n");
    free(string);
    return 0;
}

void GetS()
{
    while (*S == ' ' || *S == 10)
    {
        S++;
    }
}

double GetNum()
{
    GetS();
    char * debug = S;
    double val = 0;
    while('0' <= *S && *S <= '9')
    {
        val = val*10 + *S - '0';
        S++;
    }
    if (S == debug)
    {
        Error = 1;
        return -1;
    }
    return val;
}

double GetExp()
{
    double val = GetP();
    GetS();
    while (*S == '+' || *S == '-')
    {
        if (*S == '+')
        {
            S++;
            val += GetP();
        } else if (*S == '-')
        {
            S++;
            val -= GetP();
        }
        GetS();
    }
    if (*S != 0 && *S != ')')
    {
        Error = 1;
    }
    return val;
}

double GetP()
{
    GetS();
    double val = 0;
    if (*S == '(')
    {
        S++;
        val = GetExp();
        GetS();
        if (*S != ')')
            Error = 1;
        S++;
    } else
    {
        val = GetNum();
    }
    return val;
}
