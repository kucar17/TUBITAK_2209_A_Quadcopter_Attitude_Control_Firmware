/*
 * simpMat.c
 *
 *  Created on: Feb 28, 2022
 *      Author: Kaan
 */

#include "simpMat.h"

void simpMat_Create(simpMat *Matrix, uint8_t nRows, uint8_t nColumns)
{
    Matrix->nRows = nRows;
    Matrix->nCols = nColumns;

    Matrix->elements = (float**)malloc(nRows * sizeof(float*));
    for (uint8_t i = 0; i < nRows; i++)
    {
        Matrix->elements[i] = (float*)malloc(nColumns * sizeof(float));
    }
}

void simpMat_Init(simpMat *Matrix, uint8_t nRows, uint8_t nColumns, float elements[])
{
    Matrix->nRows = nRows;
    Matrix->nCols = nColumns;

    Matrix->elements = (float**)malloc(nRows * sizeof(float*));
    for (uint8_t i = 0; i < nRows; i++)
    {
        Matrix->elements[i] = (float*)malloc(nColumns * sizeof(float));
    }

    uint8_t count = 0;

    for (uint8_t i = 0; i < nRows; i++)
    {
        for (uint8_t j = 0; j < nColumns; j++)
        {
            Matrix->elements[i][j] = elements[count];
            count++;
        }
    }

}

void simpMat_Print(simpMat *Matrix)
{
    for (uint8_t i = 0; i < Matrix->nRows; i++)
    {
        for (uint8_t j = 0; j < Matrix->nCols; j++)
        {
            printf("%d ", Matrix->elements[i][j]);

        }

        printf("\n");
    }
}


void simpMat_Delete(simpMat *Matrix)
{
    uint8_t n = Matrix->nRows;
    while(n) free(Matrix->elements[--n]);
    free(Matrix->elements);
}

void simpMat_Multiply(simpMat *Matrix, simpMat *Matrix1, simpMat *Matrix2)
{
    /*
    if (Matrix1->nCols != Matrix2->nRows)
    {
        printf("Inconsistent dimensions for matrices to be multiplied!\n");
        Matrix->elements = {(float)0.0};
    }
    else if (Matrix->nRows != Matrix1->nRows || Matrix->nCols != Matrix2->nCols)
    {
        printf("Inconsistent dimensions for the matrix to be returned!\n");
        Matrix->elements = {(float)0.0};
    }
    */

    for (uint8_t i = 0; i < Matrix1->nRows; i++)
    {
        for (uint8_t j = 0; j < Matrix2->nCols; j++)
        {
            float sum = 0.0;

            for (uint8_t k = 0; k < Matrix1->nCols; k++)
            {
                //printf("%d %d %d", i, j, k);
                sum += Matrix1->elements[i][k] * Matrix2->elements[k][j];
                //printf("%f * %f = %f\n", Matrix1->elements[i][k], Matrix2->elements[k][j], Matrix1->elements[i][k] * Matrix2->elements[k][j]);
            }

            Matrix->elements[i][j] = sum;
        }
    }

}
