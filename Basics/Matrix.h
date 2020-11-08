#pragma once
#include <cstdio>
#include "Atomics.h"


// some bit field to say what kind of matrix we are working with 
union MatrixType
{
    unsigned fourbyfour : 1;
    unsigned threebythree : 1;
    unsigned twobytwo : 1;
};

enum MatrixLength { Two = 2, Three, Four };

struct Matrix {

    Matrix() {};

    // create a 4x4 matrix 
    Matrix(float in0, float in1, float in2, float in3,
           float in4, float in5, float in6, float in7,
           float in8, float in9, float in10, float in11,
           float in12, float in13, float in14, float in15)
    {
        values[0][0] = in0;
        values[0][1] = in1;
        values[0][2] = in2;
        values[0][3] = in3;
        values[1][0] = in4;
        values[1][1] = in5;
        values[1][2] = in6;
        values[1][3] = in7;
        values[2][0] = in8;
        values[2][1] = in9;
        values[2][2] = in10;
        values[2][3] = in11;
        values[3][0] = in12;
        values[3][1] = in13;
        values[3][2] = in14;
        values[3][3] = in15;
        size = MatrixLength::Four;
    };

    // create a 2x2 matrix
    Matrix(float in0, float in1,
           float in2, float in3)
    {
        values[0][0] = in0;
        values[0][1] = in1;
        values[1][0] = in2;
        values[1][1] = in3;
        // how to indicate that this is a 2x2? 
        size = MatrixLength::Two;

    };

    // create a 3x3 Matrix
    Matrix(float in0, float in1, float in2,
           float in3, float in4, float in5,
           float in6, float in7, float in8)
    {
        values[0][0] = in0;
        values[0][1] = in1;
        values[0][2] = in2;
        values[1][0] = in3;
        values[1][1] = in4;
        values[1][2] = in5;
        values[2][0] = in6;
        values[2][1] = in7;
        values[2][2] = in8;
        size = MatrixLength::Three;
    }


    float values[4][4]; //zero initialize 
    MatrixLength size;

    static inline bool isEqual(const Matrix& A, const Matrix& B);

    void print()
    {

        // isn't this the same as a for for loop? 
        printf(" %f | %f | %f | %f |\n", values[0][0], values[0][1], values[0][2], values[0][3]);
        printf(" %f | %f | %f | %f |\n", values[1][0], values[1][1], values[1][2], values[1][3]);
        printf(" %f | %f | %f | %f |\n", values[2][0], values[2][1], values[2][2], values[2][3]);
        printf(" %f | %f | %f | %f |\n\n", values[3][0], values[3][1], values[3][2], values[3][3]);
    }


};

static const Matrix Identity = Matrix(1.0f, 0.0f, 0.0f, 0.0f,
                                      0.0f, 1.0f, 0.0f, 0.0f,
                                      0.0f, 0.0f, 1.0f, 0.0f,
                                      0.0f, 0.0f, 0.0f, 1.0f);

bool Matrix::isEqual(const Matrix& A, const Matrix& B)
{

    for (unsigned i = 0; i < 4; ++i)
        for (unsigned j = 0; j < 4; ++j)
        {
            if (!equal(A.values[i][j], B.values[i][j]))
            {
                return false;
            }
        }

    return true;
}

inline Matrix MatrixMultiply(const Matrix& A, const Matrix& B)
{
    Matrix result;

    for (unsigned i = 0; i < 4; ++i)
        for (unsigned j = 0; j < 4; ++j)
        {
            result.values[i][j] = A.values[i][0] * B.values[0][j] +
                                A.values[i][1] * B.values[1][j] +
                                A.values[i][2] * B.values[2][j] +
                                A.values[i][3] * B.values[3][j];
        }
    return result;
}
inline Matrix operator * (const Matrix& A, const Matrix& B) {
    return MatrixMultiply(A, B);
}
inline Tuple MatrixMultiply(const Matrix& A, const Tuple& B)
{
    Tuple result;
    result.x = A.values[0][0] * B.x + A.values[0][1] * B.y + A.values[0][2] * B.z + A.values[0][3] * B.w;
    result.y = A.values[1][0] * B.x + A.values[1][1] * B.y + A.values[1][2] * B.z + A.values[1][3] * B.w;
    result.z = A.values[2][0] * B.x + A.values[2][1] * B.y + A.values[2][2] * B.z + A.values[2][3] * B.w;
    result.w = A.values[3][0] * B.x + A.values[3][1] * B.y + A.values[3][2] * B.z + A.values[3][3] * B.w;

    return result;
}
inline Tuple operator * (const Matrix& A, const Tuple& B) {
    return MatrixMultiply(A, B);
}

inline Matrix Transpose(const Matrix& A)
{
    Matrix B;

    for (unsigned i = 0; i < 4; ++i)
        for (unsigned j = 0; j < 4; ++j)
        {
            B.values[i][j] = A.values[j][i];
        }

    return B;

}

inline float Cofactor(const Matrix& M, unsigned row, unsigned column);

inline Matrix SubMatrix(const Matrix& A, unsigned row, unsigned column)
{

    Matrix sub;
    float temp[16];
    int count = 0;

    for (unsigned i = 0; i < 4; ++i)
        for (unsigned j = 0; j < 4; ++j)
        {
            if (i == row || j == column)
                continue;
            if (equal(temp[count], A.values[i][j]))
                continue;

            temp[count] = A.values[i][j];
            count++;
        }

    if (A.size == MatrixLength::Three)
    {
        sub = Matrix(temp[0], temp[1],
                     temp[2], temp[3]);
    }

    if (A.size == MatrixLength::Four)
    {
        sub = Matrix(temp[0], temp[1], temp[2],
                     temp[3], temp[4], temp[5],
                     temp[6], temp[7], temp[8]);
    }
    return sub;
}

inline float Determinant(const Matrix& m)
{
    float determinant = 0.0f;

    if (m.size == MatrixLength::Two)
        determinant = m.values[0][0] * m.values[1][1] - m.values[0][1] * m.values[1][0];
    else if (m.size == MatrixLength::Three)
        determinant = m.values[0][0] * (m.values[1][1] * m.values[2][2] - m.values[1][2] * m.values[2][1])
        + m.values[0][1] * (m.values[1][2] * m.values[2][0] - m.values[1][0] * m.values[2][2])
        + m.values[0][2] * (m.values[1][0] * m.values[2][1] - m.values[1][1] * m.values[2][0]);
    else
    {
        for (unsigned i = 0; i < (unsigned)m.size; ++i)
        {
            determinant += m.values[0][i] * Cofactor(m, 0, i);
        }

    }
    return determinant;
}



inline float Minor(const Matrix& M, unsigned row, unsigned column)
{
    Matrix sub = SubMatrix(M, row, column);
    return Determinant(sub);
}

float Cofactor(const Matrix& M, unsigned row, unsigned column)
{
    float minor = Minor(M, row, column);
    if ((row + column) % 2 == 0)
        return minor;
    else
        return -1.0f * minor;

}

// I'm not sure I like this 
inline Matrix Inverse(const Matrix& M)
{
    float determinant = Determinant(M);

    Matrix m2 = Matrix();

    if (determinant == 0.0f) {
        printf("Matrix not invertible \n");
        return m2; // just return a dummy 
    }


    for (unsigned i = 0; i < (unsigned)M.size; ++i)
        for (unsigned j = 0; j < (unsigned)M.size; ++j)
        {
            float cofactor = Cofactor(M, i, j);
            m2.values[j][i] = cofactor / determinant;

        }

    return m2;
}


#define _USE_MATH_DEFINES
#include <math.h>

#ifndef NinetyDegreesAsRadians
#define NinetyDegreesAsRadians = (90.0f * M_PI)/180.0f;
#endif


inline Matrix translation(float x, float y, float z)
{
    Matrix translated = Identity;
    translated.values[0][3] = x;
    translated.values[1][3] = y;
    translated.values[2][3] = z;

    return translated;
}

inline Matrix scale(float x, float y, float z)
{
    Matrix scaled = Identity;
    scaled.values[0][0] = x;
    scaled.values[1][1] = y;
    scaled.values[2][2] = z;

    return scaled;

}

inline Matrix rotation_x(float radians)
{
    Matrix rotMat = Identity;

    float cosr = cosf(radians);
    float sinr = sinf(radians);

    rotMat.values[1][1] = cosr;
    rotMat.values[1][2] = -1.0f * sinr;
    rotMat.values[2][1] = sinr;
    rotMat.values[2][2] = cosr;

    return rotMat;
}

inline Matrix rotation_y(float radians)
{
    Matrix rotMat = Identity;

    float cosr = cosf(radians);
    float sinr = sinf(radians);

    rotMat.values[0][0] = cosr;
    rotMat.values[0][2] = sinr;
    rotMat.values[2][0] = -1.0f * sinr;
    rotMat.values[2][2] = cosr;

    return rotMat;
}

inline Matrix rotation_z(float radians)
{
    Matrix rotMat = Identity;

    float cosr = cosf(radians);
    float sinr = sinf(radians);

    rotMat.values[0][0] = cosr;
    rotMat.values[0][1] = -1.0f * sinr;
    rotMat.values[1][0] = sinr;
    rotMat.values[1][1] = cosr;

    return rotMat;
}

inline Matrix shearing(float xy, float xz, float yx, float yz, float zx, float zy)
{
    Matrix shear = Identity;
    shear.values[0][1] = xy;
    shear.values[0][2] = xz;
    shear.values[1][0] = yx;

    shear.values[1][2] = yz;
    shear.values[2][0] = zx;
    shear.values[2][1] = zy;

    return shear;
}


inline float radians(float degrees)
{
    return (degrees * M_PI) / 180.0f;
}