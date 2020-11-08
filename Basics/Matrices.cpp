
#include "Matrix.h"
int MatixTests() {

    Matrix mymatrix = Matrix(1.0f, 2.0f, 3.0f,4.0f,
                             5.50f, 6.5f, 7.5f, 8.5f,
                             9.0f, 10.0f, 11.0f, 12.0f,
                             13.5f, 14.5f, 15.5f, 16.5); 
    Matrix mymatrixB = Matrix(1.0f, 2.0f, 3.0f, 4.0f,
                              5.50f, 6.5f, 7.5f, 8.5f,
                              9.0f, 10.0f, 11.0f, 12.0f,
                              13.5f, 14.5f, 15.5f, 16.5);
    Matrix mymatrixC = Matrix(1.0f, 2.0f, 3.0f, -4.0f,
                              5.50f, 6.5f, 7.5f, 8.5f,
                              9.0f, 10.0f, 11.0f, 12.0f,
                              13.5f, 14.5f, 15.5f, 16.5);

    printf("printing matrix values test\n");
    printf(" M[0,0] should be 1.0 it is %f \n", mymatrix.values[0][0]);
    printf(" M[0,3] should be 4.0 it is  %f \n", mymatrix.values[0][3]);
    printf(" M[1,0] should be 5.5 it is %f\n", mymatrix.values[1][0]);
    printf(" M[1,2] should be 7.5 it is %f\n", mymatrix.values[1][2]);
    printf(" M[2,2] should be 11 it is %f\n", mymatrix.values[2][2]);
    printf(" M[3,0] should be 13.5 it is %f\n", mymatrix.values[3][0]);
    printf(" M[3,2] should be 15.5 it is %f\n", mymatrix.values[3][2]);

    Matrix threeMatrix = Matrix(-3.0f, 5.0f, 0.0f,
                                1.0f , -2.0f, -7.0f,
                                0.0f, 1.0f, 1.0f);
    Matrix threeMatrixB = Matrix(-3.0f, 5.0f, 0.0f,
                                1.0f, -2.0f, -7.0f,
                                0.0f, 1.0f, 1.0f);

    Matrix threeMatrixC = Matrix(-3.0f, 5.0f, 0.0f,
                                 1.0f, -2.0f, -7.0f,
                                 0.0f, 1.0f, 0.0f);

    printf("Printing three matrix test \n");
    printf("M[0,0] should be -3.0 it is %f\n", threeMatrix.values[0][0]);
    printf("M[1,1] should be -2.0 it is %f\n", threeMatrix.values[1][1]);
    printf("M[2,2] should be 1.0 it is %f\n", threeMatrix.values[2][2]);

    Matrix twomatrix = Matrix (-3.0f, 5.0f, 1.0f, -2.0f);
    Matrix twomatrixB = Matrix (-3.0f, 5.0f, 1.0f, -2.0f);

    Matrix twomatrixC = Matrix (3.0f, 5.0f, 1.0f, -2.0f);

    printf("Printing two matrix test \n");
    printf("M[0,0] should be -3.0 it is %f\n", twomatrix.values[0][0]);
    printf("M[0,1] should be 5.0 it is %f\n", twomatrix.values[0][1]);
    printf("M[1,0] should be 1.0 it is %f\n", twomatrix.values[1][0]);
    printf("M[1,1] should be -2.0 it is %f\n", twomatrix.values[1][1]);



    printf("Testing equality\n");
    if(Matrix::isEqual(mymatrix, mymatrixB))
        printf(" mymatrix Equal to mymatrix B\n");
    else
        printf("My matrix not equal mymatrixB\n");
    
    if(!Matrix::isEqual(mymatrix, mymatrixC))
        printf(" mymatrix not Equal to mymatrixC\n");
    else
        printf("My matrix equal mymatrixC\n");

    if(Matrix::isEqual(threeMatrix, threeMatrixB))
        printf("threeMatrix Equal to threeMatrixB\n");
    else
        printf("threeMatrix not equal to threeMatrixB\n");

    if (!Matrix::isEqual(threeMatrix, threeMatrixC))
        printf("threeMatrix not Equal to threeMatrixC\n");
    else
        printf("threeMatrix  equal to threeMatrixc\n");

    if(Matrix::isEqual(twomatrix, twomatrixB))
        printf("twomatrix equal to twomatrixB\n");
    else
        printf("twomatrix not equal to twomatrixB\n");

    if(!Matrix::isEqual(twomatrix, twomatrixC))
        printf("twomatrix not equal to twomatrixC\n");
    else
        printf("twomatrix equal to twoMatrixC\n");

    Matrix matA = Matrix(1.0f,2.0f,3.0f,4.0f,
                        5.0f,6.0f,7.0f,8.0f,
                        9.0f,8.0f,7.0f,6.0f,
                        5.0f,4.0f,3.0f,2.0f);

    Matrix matB = Matrix(-2.0f,1.0f,2.0f,3.0f,
                        3.0f,2.0f,1.0f,-1.0f,
                        4.0f,3.0f,6.0f,5.0f,
                        1.0f,2.0f,7.0f,8.0f);

    Matrix AtimesB = MatrixMultiply(matA, matB);
    AtimesB.print();

    Matrix matc = Matrix(1.0f, 2.0f, 3.0f, 4.0f,
                        2.0f, 4.0f, 4.0f, 2.0f,
                        8.0f, 6.0f, 4.0f, 1.0f,
                        0.0f, 0.0f, 0.0f, 1.0f);

    Tuple tupleA = Tuple(1.0f, 2.0f, 3.0f, 1.0f);

    Tuple multResult = MatrixMultiply(matc, tupleA);

    multResult.printValues();

    Matrix InverseMatrixc = MatrixMultiply(matc,Identity);

    if(Matrix::isEqual(matc,InverseMatrixc))
    {
        printf("Matrix c is equal to inverse matrix (matc * identityMatrix)\n");
    }

    Tuple tupleId = Tuple(1.0f, 2.0f, 3.0f, 4.0f);

    Tuple tupleInv = MatrixMultiply(Identity, tupleId);

    if(Tuple::isEqual(tupleId, tupleInv))
        printf("Tuple id is equal to tupleInv (tupleid * identity)\n");

    Matrix preTranspose = Matrix(0.0f, 9.0f, 3.0f, 0.0f,
                                 9.0f, 8.0f, 0.0f, 8.0f,
                                 1.0f, 8.0f, 5.0f, 3.0f,
                                 0.0f, 0.0f, 5.0f, 8.0f);
    
    
    Matrix transposeCC = Transpose(preTranspose);
    transposeCC.print();
    Matrix postTranspose = Matrix(0.0f, 9.0f, 1.0f, 0.0f,
                                  9.0f, 8.0f, 8.0f, 0.0f,
                                  3.0f, 0.0f, 5.0f, 5.0f,
                                  0.0f, 8.0f, 3.0f, 8.0f);

    if(Matrix::isEqual(transposeCC, postTranspose))
    {
        printf("transposed  matrix equal to post transpose matrix\n");
    }

    Matrix identityTranspose = Transpose(Identity);

    if(Matrix::isEqual(Identity, identityTranspose))
    {
        printf("Identity matrix transposed is equal to identity\n");
    }

    Matrix twoD = Matrix(1.0f, 5.0f, -3.0f, 2.0f);

    float det = Determinant(twoD);

    
    printf("determinant of \n");
    twoD.print();

    printf("is %f\n", det);
    

    Matrix threeSubTest = Matrix(1.0f, 5.0f, 0.0f, 
                                -3.0f, 2.0f, 7.0f, 
                                0.0f, 6.0f, -3.0f);

    Matrix subed = SubMatrix(threeSubTest, 0, 2);

    Matrix fourSubTest = Matrix(-6.0f, 1.0f, 1.0f, 6.0f,
                                -8.0f, 5.0f, 8.0f, 6.0f,
                                -1.0f, 0.0f, 8.0f, 2.0f,
                                -7.0f, 1.0f, -1.0f, 1.0f);

    printf("Printing sub matrix 0,2 of threeSubTest\n");
    subed.print();

    Matrix subthree = SubMatrix(fourSubTest, 2, 1);

    printf("printing sub matrix 2,1 of forSubTest\n");
    subthree.print();

   Matrix matminor = Matrix(3.0f, 5.0f, 0.0f,
                            2.0f, -1.0f, -7.0f,
                            6.0f, -1.0f, 5.0f);
   Matrix submatminor = SubMatrix(matminor, 1, 0);
   printf("Mat minor test again\n");
  
  submatminor.print(); 
    float minor = Minor(matminor, 0, 0);
    float cofactor =Cofactor(matminor,0 , 0);
    printf("the minor should be -12 is %f\n", minor);
    printf("the cofactor should be -12 is %f\n", cofactor);

    float minorA = Minor(matminor, 1, 0);
    float cofactorA = Cofactor(matminor, 1, 0);

    printf("the minor should be 25 is %f\n", minorA);
    printf("the minor should be -25 is %f\n", cofactorA);


    Matrix cofactorAThree = Matrix(1.0f, 2.0f, 6.0f,
                                   -5.0f,8.0f, -4.0f,
                                    2.0f,6.0f, 4.0f);

    float cofactorAZ = Cofactor(cofactorAThree, 0, 0);
    float cofactorB = Cofactor(cofactorAThree, 0, 1);
    float cofactorC = Cofactor(cofactorAThree, 0, 2);
    float detThree = Determinant(cofactorAThree);

    printf("Testing cofactor of a three matrix\n");
    printf("Cofactor a %f\n", cofactorAZ);
    printf("Cofactor a %f\n", cofactorB);
    printf("Cofactor a %f\n", cofactorC);
   
   
    printf("the det of cofactorathree is %f\n", detThree);
    
    Matrix cofactorAFour = Matrix(-2.0f, -8.0f, 3.0f, 5.0f,
                                  -3.0f, 1.0f, 7.0f, 3.0f,
                                  1.0f, 2.0f, -9.0f, 6.0f,
                                  -6.0f, 7.0f, 7.0f, -9.0f);

    float cofactorAA = Cofactor(cofactorAFour, 0, 0);
    float cofactorAB = Cofactor(cofactorAFour, 0, 1);
    float cofactorAC = Cofactor(cofactorAFour, 0, 2);
    float cofactorAD = Cofactor(cofactorAFour, 0, 3);
    float detA = Determinant(cofactorAFour);
    
    printf("Testing cofactor of a four matrix\n");
    printf("Cofactor a %f\n", cofactorAA);
    printf("Cofactor a %f\n", cofactorAB);
    printf("Cofactor a %f\n", cofactorAC);
    printf("Cofactor a %f\n", cofactorAD);
    printf("Determinant of contractor four matrix %f\n", detA);

    if(detA != 0)
    {
        printf("This matrix is invertable\n");
    }

    Matrix nonInvertable = Matrix(-4.0f, 2.0f, -2.0f, -3.0f,
                                  9.0f, 6.0f, 2.0f, 6.0f,
                                  0.0f, -5.0f, 1.0f, -5.0f,
                                  0.0f, 0.0f ,0.0f,0.0f);
    nonInvertable.print();

    float detB = Determinant(nonInvertable);
   // Matrix nonInv = Inverse(nonInvertable); // test again 
    if(detB == 0.0f)
    {
        printf("This matrix is not invertable\n");    
    }

    Matrix inverseCalc = Matrix(-5.0f, 2.0f, 6.0f, -8.0f,
                                1.0f, -5.0f, 1.0f, 8.0f,
                                7.0f, 7.0f, -6.0f,-7.0f,
                                1.0f, -3.0f, 7.0f, 4.0f);
    inverseCalc.print();

    Matrix inverted = Inverse(inverseCalc);

    printf("Inverted matrix\n");
    inverted.print();
    
    Matrix inverseCalcA = Matrix(8.0f, -5.0f, 9.0f, 2.0f,
                                 7.0f, 5.0f, 6.0f, 1.0f,
                                 -6.0f,0.0f, 9.0f, 6.0f,
                                 -3.0f, 0.0f, -9.0f, -4.0f);

    inverseCalcA.print();
    Matrix invertedA = Inverse(inverseCalcA);
    
    printf("Inverted matrix\n");
    invertedA.print();

    Matrix inverseCalcB = Matrix(9.0f, 3.0f, 0.0f, 9.0f,
                                 -5.0f, -2.0f, -6.0f, -3.0f,
                                 -4.0f, 9.0f, 6.0f, 4.0f,
                                 -7.0f, 6.0f, 6.0f, 2.0f);
    inverseCalcB.print();


    printf("Inverted matrix\n");
    Matrix invertedB = Inverse(inverseCalcB);
    invertedB.print();

    // proving that multiply some matrix A by another matrix B, producing C
    // then multiply C by the inverse of B to get A again. 
    Matrix mA = Matrix(3.0f, -9.0f, 7.0f, 3.0,
                       3.0f, -8.0f, 2.0f,-9.f,
                      -4.0f, 4.0f, 4.0f, 1.0f,
                      -6.0f, 5.0f, -1.0f, 1.0f);

    Matrix mB = Matrix( 8.0f, 2.0f, 2.0f, 2.0f,
                        3.0f,-1.0f, 7.0f, 0.0f,
                        7.0f,0.0f, 5.0f, 4.0f,
                        6.0f,-2.0f, 0.0f, 5.0f);

    Matrix mC = MatrixMultiply(mA, mB);

    Matrix multiplyCmB = MatrixMultiply(mC, Inverse(mB)); 

    if(Matrix::isEqual(mA,multiplyCmB))
    {
        printf("MA equal to inverse of B multiplied by C\n");
    }
    else
    {
        printf("Oh it's not equal\n");
    }


    return 0;

}