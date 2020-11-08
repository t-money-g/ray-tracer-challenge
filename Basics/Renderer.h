#pragma once
#include <cstdio>
#include "Atomics.h"
#include <fstream>
#include <algorithm>



const float MIN_COLOR = 0.0f;
const float MAX_COLOR = 255.0f;

// file limitations of ppm file format 70 characters, we're stopping at 67 for saftey 
const int MAX_LINE = 63; // 
const int SPACE_CHAR_PADDING = 1;

struct Color
{
    Color() {};
    Color(float inR, float inG, float inB)
        : r(inR), g(inG), b(inB) {};

    float r, g, b;

    void scale(float value)
    {
        r *= value;
        g *= value;
        b *= value;
    }

};

inline Color add(const Color& a, const Color& b)
{
    return Color(a.r + b.r, a.g + b.g, a.b + b.b);
}
inline Color operator + (const Color& a, const Color& b)
{
    return add(a , b);
}
inline Color subtract(const Color& a, const Color& b)
{
    return Color(a.r - b.r, a.b - b.b, a.g - b.b);
}
inline Color operator - (const Color& a, const Color& b)
{
    return subtract(a, b);
}
inline Color multiply(const Color& a, const Color& b)
{
    return Color(a.r * b.r,
                 a.g * b.g,
                 a.b * b.b);
}
inline Color operator * (const Color& a, const Color&b)
{
    return multiply(a,b);
}

inline Color hadamard_product(const Color& a, const Color& b)
{
    multiply(a, b);
}


struct Canvas
{
    Canvas() {};
    Canvas(unsigned int widthIn, unsigned int heightIn)
        : width(widthIn), height(heightIn) {

        pixeldata = new Color * [width];

        for (unsigned i = 0; i < width; ++i) {
            pixeldata[i] = new Color[height];
        }

    };

    unsigned int width, height;

    Color** pixeldata;

    void write_pixel(unsigned int x, unsigned int y, Color& c)
    {
        if (x >= width || y >= height)
        {
            printf("pixel index Out of range!\n");
            return;
        }
        pixeldata[x][y] = c;
    }

    Color pixel_at(unsigned int x, unsigned int y)
    {
        if (x >= width || y >= height)
        {
            printf("pixel index out of range dumping empty !\n");
            return Color(0.0f, 0.0f, 0.0f);
        }
        return pixeldata[x][y];
    }

    void fill(Color& c)  // fill the entire canvas
    {
        for (unsigned i = 0; i < width; ++i)
            for (unsigned j = 0; j < height; ++j)
                write_pixel(i, j, c);

    }
    ~Canvas()
    {
        for (unsigned i = 0; i < width; i++)
            delete[] pixeldata[i];
        delete[] pixeldata;
    }
};

inline unsigned int count_digits(int n)
{
    unsigned int number_of_digits = 0;
    do {
        ++number_of_digits;
        n /= 10;
    } while (n > 0);

    return number_of_digits;
}


inline void canvas_to_ppm(Canvas& c)
{
    printf("Printing canvas\n");
    unsigned digitcount = 0;
    std::ofstream file{ "out.ppm", std::ios::out };
    file << "P3" << std::endl;
    file << c.width << " " << c.height << std::endl;
    file << MAX_COLOR << std::endl;

    for (unsigned i = 0; i < c.width; ++i)
    {

        for (unsigned j = 0; j < c.height; ++j)
        {
            Color currentColor = c.pixel_at(i, j);
            currentColor.scale(255.0f);

            // clamp value between 0-255
            unsigned red = (unsigned)std::clamp(currentColor.r, MIN_COLOR, MAX_COLOR);
            unsigned green = (unsigned)std::clamp(currentColor.g, MIN_COLOR, MAX_COLOR);
            unsigned blue = (unsigned)std::clamp(currentColor.b, MIN_COLOR, MAX_COLOR);


            digitcount += count_digits(red) + SPACE_CHAR_PADDING; // account for effing spaces
            if (digitcount >= MAX_LINE)
            {
                file << std::endl;

                // reset the count before printing
                digitcount = count_digits(red) + SPACE_CHAR_PADDING;

            }

            file << red << " ";

            digitcount += count_digits(green) + SPACE_CHAR_PADDING;
            if (digitcount >= MAX_LINE)
            {
                file << std::endl;
                digitcount = count_digits(green) + SPACE_CHAR_PADDING;
            }

            file << green << " ";


            digitcount += count_digits(blue) + SPACE_CHAR_PADDING;
            if (digitcount >= MAX_LINE)
            {
                file << std::endl;
                digitcount = count_digits(blue) + SPACE_CHAR_PADDING;
            }

            file << blue << " ";


        }

    }
    file << std::endl;
    printf("Done printing \n");
}
