#pragma once
#include <cstdio>
#include <cstdlib>

const float EPSILON = 0.0001f;

// a tuple is an ordered list of things 
struct Tuple {

   
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
    float w = 0.0f;

    Tuple() {};
    //    Tuple(Tuple tuplein)

    Tuple(float xIn, float yIn, float zIn, float wIn)
    {
        x = xIn;
        y = yIn;
        z = zIn;
        w = wIn;
        //TODO add proper error handling if you want to. 
        //        if(!equal(wIn, 1.0f) || !equal(wIn, 0.0f) )
        //        {
        //            
        //             printf("%4.3f isn't allowed.. SORRY!\n", wIn);
        //             wIn = 0.0f;
        //        } 
        //        else
        //        {
        //             w = wIn; 
        //        }
    }
    static bool isEqual(const Tuple& a, const Tuple& b);

    void negate()
    {
        x *= -1.0f;
        y *= -1.0f;
        z *= -1.0f;
        w *= -1.0f;
    }

    void scale(float value)
    {
        x *= value;
        y *= value;
        z *= value;
        w *= value;
    }

    void divide(float value)
    {
        if (value == 0.0f)
        {
            printf("nice try ;)\n");
            printf("can't divide by zero\n");
            return;
        }

        x /= value;
        y /= value;
        z /= value;
        w /= value;

    }
    float magnitude()
    {
        float mag = sqrtf((x * x) + (y * y) + (z * z) + (w * w));
        return mag;
    }

    void printValues()
    {
        printf("%f, %f, %f, %f \n", x, y, z, w);
    }

 
};

inline Tuple point(float xIn, float yIn, float zIn)
{
    return Tuple(xIn, yIn, zIn, 1.0f);
}

inline Tuple vector(float xIn, float yIn, float zIn)
{
    return Tuple(xIn, yIn, zIn, 0.0f);
}

inline Tuple add(const Tuple& a, const Tuple& b) 
{

    return Tuple(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}
inline Tuple operator + (const Tuple& a, const Tuple& b)
{
    return add(a, b);
}
inline Tuple subtract(const Tuple& a, const Tuple& b)
{
    return Tuple(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

inline Tuple operator -(const Tuple& a, const Tuple& b)
{
    return subtract(a, b);
}

inline Tuple operator*(const Tuple& a, float f) {
    
    Tuple b = a;
    b.x *= f;
    b.y *= f;
    b.z *= f;
    b.w *= f;

    return b;
}
inline Tuple normalize(Tuple& t)
{

    float mag = t.magnitude();
    return Tuple(t.x / mag,
                 t.y / mag,
                 t.z / mag,
                 t.w / mag);

}

// better dot product explained 
// multiply in a direction 
inline float dot (const Tuple& a, const Tuple& b)
{
    return a.x * b.x +
        a.y * b.y +
        a.z * b.z +
        a.w * b.w;

}

// get a vector that's perpendicular to the two 
inline Tuple cross(const Tuple& a, const Tuple& b)
{
    return vector(a.y * b.z - a.z * b.y,
                  a.z * b.x - a.x * b.z,
                  a.x * b.y - a.y * b.x);

}
inline bool equal(float a, float b)
{
    if (abs(a - b) < EPSILON)
        return true;
    else
        return false;
}

inline bool Tuple::isEqual(const Tuple& a, const Tuple& b)
{
    if (equal(a.x, b.x) &&
        equal(a.y, b.y) &&
        equal(a.z, b.z) &&
        equal(a.w, b.w))
        return true;
    else
        return false;

}

inline bool operator==(const Tuple& a, const Tuple& b)
{
    return Tuple::isEqual(a, b);

}

