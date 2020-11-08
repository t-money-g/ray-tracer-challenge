// Basics.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Tuples points and vectors 

#include "Atomics.h"

struct Projectile {

    Projectile() {};
    Projectile(Tuple positionIn, Tuple velocityIn)
    : position{ positionIn}, velocity {velocityIn} {};  // Uh oh copy constructor implicitly used! 
    Tuple position; // point 
    Tuple velocity; // vector 

};

struct Environment {
    Environment() {};
    Environment(Tuple gravityIn, Tuple windIn)
    : gravity{gravityIn}, wind{windIn} {};
    Tuple gravity; //vector 
    Tuple wind;    // vector
    
};


inline Projectile tick(Environment env, Projectile proj)
{
    Tuple position = add(proj.position, proj.velocity);
    Tuple velocity = add(add(proj.velocity , env.gravity), env.wind); // ewwww
    return Projectile(position, velocity);

}
void atomic_tests()
{
    Tuple point1 = point(4.3f, 33.0f, 3.0f);
    Tuple point2 = point(4.3f, 33.0f, 3.0f);
    point1.negate();
    point1.divide(-2.0f);

    Tuple point3 = point(0.3f, 3.0f, 0.5f);

    Tuple tvector =  vector(0.0f, 0.1f, 0.2f);
    Tuple tv2 = vector(1.0f, 2.0f, 3.0f);
       

    printf("This tuple is a point %4.4f,%4.4f,%4.4f,%4.4f \n", point1.x, point1.y , point1.z, point1.w);


    // testing vector constructor method
	printf("This tuple is a vector %4.4f,%4.4f,%4.4f,%4.4f \n", tv2.x, tv2.y, tv2.z, tv2.w);


    // testing if these two tuples are equal 
    if(Tuple::isEqual(point1, point2))
    {
        printf("Tuple a and tuple b should BE equal \n ");
    }
    else
    {
        printf("Tuple a and tuple b should are NOT equal \n ");
    }

    if(!Tuple::isEqual(point2,point3))
    {
          printf("Point1 and point2 NOT should be equal \n");
    }
    else
    {
    
        printf("Tuple a and tuple b ARE equal \n ");
    }

     // testing magnitude 
     Tuple tv3 = vector(1.0f, 0.0f, 0.0f);
     Tuple tv4 = vector(0.0f, 1.0f, 0.0f);
     Tuple tv5 = vector(0.0f, 0.0f, 1.0f);
     Tuple tv6 = vector(-1.0f, -2.0f, -3.0f);
     
     float lengthi = tv3.magnitude();
     printf("print mag %f\n", lengthi);
     
     float lengthj = tv4.magnitude();
     printf("print mag %f\n", lengthj);
 
     float lengthk = tv5.magnitude();
     printf("print mag %f\n", lengthk);
 
     float lengthl = tv6.magnitude();
     printf("print mag %f\n", lengthl);
 
 
     Tuple tv = vector(4.0f, 0.0f, 0.0f);
     Tuple normal = normalize(tv);
     normal.printValues();
 
     Tuple vec = vector(1.0f , 2.0f, 3.0f);
     Tuple vecnormal = normalize(vec);
     vecnormal.printValues();
     float magnormal = vecnormal.magnitude();
     printf("print mag of normalized vector above %f\n", magnormal);
 
 
     // the dot product of two tuples
     Tuple veca = vector(1.0f, 2.0f, 3.0f);
     Tuple vecb = vector(2.0f, 3.0f, 4.0f);
     float dotproduct = dot(veca, vecb);
     Tuple crossab = cross(veca, vecb);
     Tuple crossba = cross(vecb, veca);
 
     printf("dot product of the %f\n", dotproduct);
     printf("cross(a b) equal\n");
     crossab.printValues();
 
     printf("cross(b, a) equal\n");
     crossba.printValues();
     
//      projectile starts one unit above the origin 
//      velocity is normalized to 1 unit/tick 

    Tuple v1 = vector(1.0f,1.0f, 0.0f);
    Projectile p = Projectile(point(0.0f, 1.0f, 0.0f), normalize(v1));
    Environment e = Environment(vector(0.0f, -0.1f, 0), vector(-0.01f,0.0f, 0.0f));

    while(p.position.y >= 0.0f )
    {
        p = tick(e,p);
        p.position.printValues();
    }

    // gravity -0.1 unit/tick and wind is -
    
    //return 0;
}
