#include <iostream>
#include "point.h"
#include "rectangle.h"
#include "cercle.h"
#include "triangle.h"
#include "carre.h"

int main()
{
    Point point = {2.5f,4.4f};

    Rectangle rectangle1 = Rectangle(10, 20, {point});
    Rectangle rectangle2 = Rectangle(20,30,{point});
    rectangle1.Afficher(rectangle2);

    Cercle cercle = Cercle({1.3f,2.1f}, 8);
    cercle.Afficher({point});

    Triangle triangle = Triangle({2.5f,5.0f},{4.0f,5.8f},{2.7f,1.8f});
    triangle.Afficher();

    Carre carre1 = Carre(8,8,{point});
    Carre carre2 = Carre(2,2,{point});
    carre1.Afficher(carre2);

}
