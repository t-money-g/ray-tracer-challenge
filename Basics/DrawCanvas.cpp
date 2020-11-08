#include "Renderer.h"



void  test_drawing()
{

    Canvas mycanvas = Canvas(10,2);

    Color red = Color(1.0f, 0.0f,0.0f);
    Color c1 = Color(1.5f, 0.0f, 0.0f);
    Color c2 = Color(0.0f, 0.5f, 0.0f);
    Color c3 = Color(-0.5f, 0.0f, 1.0f);

    Color theALLCOLOR = Color(1.0f, 0.8f, 0.6f);
    
   // printf("Writing some pixels \n"); 
    //Color colordata = mycanvas.pixel_at(2, 3);
    //printf("getting written pixel %f %f %f \n", colordata.r, colordata.g, colordata.g);

//     mycanvas.write_pixel(0, 0, c1);
//     mycanvas.write_pixel(2, 1, c2);
//     mycanvas.write_pixel(4, 2, c3);
    
    mycanvas.fill(theALLCOLOR); 
    

    canvas_to_ppm(mycanvas);


}