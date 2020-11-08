#include "Atomics.h"
#include <stdio.h>


// create and query a ray 
// point(1, 2, 3)
// vector(4, 5, 6)

struct Ray {

    Ray(){};
    Ray(Tuple p, Tuple v)
     : origin(p), direction(v) {};

    Tuple origin;
    Tuple direction;

};

struct Sphere {
    
    Sphere() {
        center = point(0.0f, 0.0f, 0.0f);

        id = rand();
    }

    int id;
    Tuple center;


};

inline Tuple position(const Ray& r, float t)
{
    Tuple dir = r.direction;
    dir.scale(t);

    Tuple originDirection = r.origin + dir;
    return originDirection;
}

inline float* intersect( Sphere s, Ray r)
{
    float points[2];

    Tuple sphere_to_ray = r.origin - s.center;

    float a = dot(r.direction, r.direction);
    float b = 2 * dot(r.direction, sphere_to_ray);
    float c = dot(sphere_to_ray, sphere_to_ray) - 1.0f;
    float discriminant = powf(b, 2.0f) - 4 * a * c;


    if (discriminant < 0.0f)
        return NULL;

    points[0] = (-1.0f * b) - sqrtf(discriminant) / (2 * a);
    points[1] = (-1.0f * b) + sqrtf(discriminant) / (2 * a);


    return points;        
}

int main() 
{
    Tuple origin = point(1.0f, 2.0f, 3.0f);
    Tuple direction = vector(4.0f, 5.0f, 6.0f);

    Ray r = Ray(point(1.0f, 2.0f, 3.0f), vector(4.0f, 5.0f, 6.0f));

    if(r.origin == origin)
    {
        printf("ray origin initialized properly\n");
    }

    if(r.direction == direction)
    {
        printf("ray vector initialized properly\n");
    }

    // compute a point from a distance 
    Ray ar = Ray(point(2.0f, 3.0f, 4.0f), vector(1.0f, 0.0f, 0.0f));
    Tuple p1 = position(ar, 0.0f);
    Tuple p2 = position(ar, 1.0f);
    Tuple p3 = position(ar, -1.0f);
    Tuple p4 = position(ar, 2.5f);

    //
    printf("new position equal ..\n");
    p1.printValues();
    printf("new position equal ..\n");
    p2.printValues();
    printf("new position equal ..\n");
    p3.printValues();
    printf("new position equal ..\n");
    p4.printValues();
    



    return 0;
}