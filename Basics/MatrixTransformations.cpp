#include "Matrix.h"
#include <stdio.h>


int transform_tests() {

    Matrix transform = translation(5.0f, -3.0f, 2.0f);
    Tuple p = point(-3.0f, 4.0f, 5.0f);

    Tuple ptransform = MatrixMultiply(transform, p);
    printf("Printing test transform\n");
    ptransform.printValues();

    Matrix transformA = translation(5.0f, -3.0f, 2.0f);
    Matrix inverse  = Inverse(transformA);
    Tuple p1 = point(-3.0f, 4.0f, 5.0f);
    Tuple invp = MatrixMultiply(inverse,p1);
    
    printf("Printing transform test\n");
    invp.printValues();

    Matrix transformB = translation(5.0f, -3.0f, 2.0f);
    Tuple v = vector(-3.0f, 4.0f, 5.0f);
    Tuple vect = MatrixMultiply(transformB, v);
    
    printf("Printing vector \n");
    vect.printValues();

    Matrix scaleform = scale(2.0f, 3.0f, 4.0f);
    Tuple pscale = point(-4.0f, 6.0f, 8.0f);
    Tuple pscaleform = MatrixMultiply(scaleform, pscale);
    
    printf("Printing scaleform values\n");
    pscaleform.printValues();

    Matrix scaleformA = scale(2.0f, 3.0f, 4.0f);
    Tuple vscale = vector(-4.0f, 6.0f, 8.0f);
    Tuple vscaleformA = MatrixMultiply(scaleformA, vscale);
    printf("Printing vscaleform values\n");
    vscaleformA.printValues();


    // reflection 
    Matrix scaleformB = scale(-1.0f, 1.0f, 1.0f);
    Tuple pscaleA = point(2.0f, 3.0f, 4.0f);
    Tuple pscalformA = MatrixMultiply(scaleformB, pscaleA);
    
    printf("Printing some pscaleform reflected value\n");
    pscalformA.printValues();


    Tuple prot = point(0.0f, 1.0f, 0.0f);
    Matrix halfQuarter = rotation_x((float)M_PI / 4.0f);
    Matrix invHalfQuarter = Inverse(halfQuarter);

    Tuple pnt = MatrixMultiply(invHalfQuarter, prot);
    printf("wow printing this bad matrix\n");
    pnt.printValues();

    Tuple protA = point(0.0f, 0.0f, 1.0f);
    Matrix halfQuarterA = rotation_y((float)M_PI / 4.0f);
    Matrix fullQuarterA = rotation_y((float)M_PI / 2.0f);

    Tuple pntA = MatrixMultiply(halfQuarterA, protA);
    Tuple fullQuarter = MatrixMultiply(fullQuarterA, protA);

    printf("printing rotation y\n");
    pntA.printValues();
    
    printf("printing rotation y\n");
    fullQuarter.printValues();

    Tuple pntRotZ = point(0.0f, 1.0f, 0.0f);
    Matrix rotz_half_quarter = rotation_z((float)M_PI / 4); // 45.0
    Matrix rotz_full_quarter = rotation_z((float)M_PI / 2); // 90.0
    Tuple protzhalf = MatrixMultiply(rotz_half_quarter, pntRotZ);
    Tuple protzfull = MatrixMultiply(rotz_full_quarter, pntRotZ);

    printf("Printing rotation z\n");
    protzhalf.printValues();

    printf("Printing rotation z\n");
    protzfull.printValues();

    Matrix shear = shearing(1.0f,0.0f,0.0f,
                            0.0f,0.0f,0.0f);
    Tuple pt = point(2.0f, 3.0f, 4.0f);
    Tuple shearpt = MatrixMultiply(shear, pt);

    printf("shearing \n");
    shearpt.printValues();

    Matrix shearA = shearing(0.0f, 1.0f, 0.0f,
                             0.0f, 0.0f, 0.0f);
    Tuple shearptA = MatrixMultiply(shearA, pt);
    printf("\n");

    printf("shearing \n");
    shearptA.printValues();

    Matrix shearB = shearing(0.0f, 0.0f, 1.0f,
                             0.0f, 0.0f, 0.0f);
    Tuple shearptB = MatrixMultiply(shearB, pt);
    printf("\n");

    printf("shearing \n");
    shearptB.printValues();

    Matrix shearC = shearing(0.0f, 0.0f, 0.0f,
                             1.0f, 0.0f, 0.0f);
    Tuple shearptC = MatrixMultiply(shearC, pt);
    printf("\n");

    printf("shearing \n");
    shearptC.printValues();

    Matrix shearD = shearing(0.0f, 0.0f, 0.0f,
                             0.0f, 1.0f, 0.0f);
    Tuple shearptD = MatrixMultiply(shearD, pt);
    printf("\n");

    printf("shearing \n");
    shearptD.printValues();


    Matrix shearE = shearing(0.0f, 0.0f, 0.0f,
                             0.0f, 0.0f, 1.0f);
    Tuple shearptE = MatrixMultiply(shearE, pt);
    printf("\n");

    printf("shearing \n");
    shearptE.printValues();

    // Demonstrating operators and chaning transformations 
    Matrix rotA = rotation_x((float)M_PI/2);
    Tuple ptr = point(1.0f, 0.0f, 1.0f);
    Matrix scaleM = scale(5.0f, 5.0f, 5.0f);
    Matrix C = translation(10, 5, 7);
    // must be applied in the reverse order 
    Matrix T = C * scaleM * rotA;

    Tuple finalpt = T * ptr;
    printf("The final point from concatenating a bunch of transformations\n");

    finalpt.printValues();
    return 0;
}