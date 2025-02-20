#include "Point.hpp"
#include <iostream>

// int main( void ) 
// {
    
//     return 0;
// }

// #include <iostream>
// #include "Point.hpp"

void testPoint(Point const& a, Point const& b, Point const& c, Point const& point)
{
    if (bsp(a, b, c, point))
        std::cout << "Point (" << point.getX() << ", " << point.getY() << ") is inside the triangle.\n";
    else
        std::cout << "Point (" << point.getX() << ", " << point.getY() << ") is outside the triangle.\n";
}

int main(void)
{
    // Triangle vertices
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(2.5f, 5.0f);

    // Point inside the triangle
    Point inside(2.5f, 2.0f);

    // // Point outside the triangle
    // Point outside(6.0f, 2.0f);

    // // Point on the edge of the triangle
    // Point onEdge(2.5f, 0.0f); 

    // // Point at a vertex of the triangle
    // Point atVertex(0.0f, 0.0f);

    // // Collinear points (degenerate triangle)
    // Point d(5.0f, 0.0f);
    // Point e(10.0f, 0.0f);

    if (bsp(a, b, c, inside))
        std::cout << "Point is inside the triangle" << std::endl;
    else
        std::cout << "Point is outside the triangle" << std::endl;

    return 0;
}
