/*
 * simpMat.h
 *
 *  Created on: Feb 28, 2022
 *      Author: Kaan
 */
#ifndef INC_SIMPMATH_H_
#define INC_SIMPMATH_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct{
    uint8_t nRows;
    uint8_t nCols;
    float **elements;
}simpMat;

/**
*@brief This function creates a Zero Matrix with the specified dimensions.
*@param simpMat
*@param uint8_t
*@param uint8_t
*@retval NONE
*/
void simpMat_Create(simpMat *Matrix, uint8_t nRows, uint8_t nColumns);

/**
*@brief This function creates a Matrix whose dimensions and elements are specified.
*@param simpMat
*@param uint8_t
*@param uint8_t
*@param float*
*@retval NONE
*/
void simpMat_Init(simpMat *Matrix, uint8_t nRows, uint8_t nColumns, float elements[]);

/**
*@brief This function prints out a given Matrix.
*@param simpMat
*@retval NONE
*/
void simpMat_Print(simpMat *Matrix);

/**
*@brief This functions deletes a Matrix from the Processor Memory.
*@param simpMat
*@retval NONE
*/
void simpMat_Delete(simpMat *Matrix);

/**
*@brief This function multiplies two given matrices and assigns the result to the first argument.
*@param simpMat
*@param simpMat
*@param simpMat
*@retval NONE
*/
void simpMat_Multiply(simpMat *Matrix, simpMat *Matrix1, simpMat *Matrix2);

/**
*@brief This function takes the transpose of a given Matrix.
*@param simpMat
*@param simpMat
*@retval NONE
*/
void simpMat_Transpose(simpMat *Matrix, simpMat *Matrix1);

#endif /* INC_SIMPMAT_H_ */
