#include <iostream>
class Figure{

    std::string figure;
public:
    Figure(){//Можно было не создавать, верно??
        figure = "Фигура: ";
    }

    virtual void print(){ //Можно создать пустым, верно??
        std::cout << figure << "\n";
    }
    std::string get_figure(){
        return figure;
    }

    void set_figure(std::string name){
        figure = name;
    }
};

class Triangle: public Figure{
///    Треугольник:-> Прямоугольный треугольник
protected:
    int a, b, c;
    int A, B, C;

public:
    Triangle(int a, int b, int c, int A, int B, int C):Figure(){
        this->a = a, this->b = b, this->c = c;
        this->A = A, this->B = B, this->C = C;
        set_figure("Треугольник:");
    }

    void print() override{
        std::cout << get_figure() << "\n";
        std::cout << "Стороны: a=" <<  a << " b=" << b << " c=" <<  c << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n\n";
    }
};

class Rectangle_triangle: public Triangle{
///    Прямоугольный треугольник:-> Треугольник

public:
Rectangle_triangle(int a, int b, int c, int A, int B):
Triangle(a, b, c, A, B, 90){
    set_figure("Прямоугольный треугольник:");
}
};

class Triangle_two_sides_equal:public Triangle{
///    Равнобедренный треугольник:-> Равносторонний треугольник

public:
Triangle_two_sides_equal(int a, int b, int A, int B, int C):
Triangle(a, b, a, A, B, C){
    set_figure("Равнобедренный треугольник:");
}
};

class Triangle_three_sides_equal:public Triangle_two_sides_equal{
///    Равносторонний треугольник:->Равнобедренный треугольник

public:
    Triangle_three_sides_equal(int a):
    Triangle_two_sides_equal(a, a, 60, 60, 60){
        set_figure("Равносторонний треугольник:");
    }
};

class Quadrangle:public Figure{
    ///    Четырёхугольник:->параллелограмм

protected:
    int a, b, c, d;
    int A, B, C, D;

public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D){
        this->a = a, this->b = b, this->c = c, this->d = d;
        this->A = A, this->B = B, this->C = C, this->D = D;
        set_figure("Четырёхугольник:");
    }

    void print() override{
        std::cout << get_figure() << "\n";
        std::cout << "Стороны: a=" <<  a << " b=" << b << " c=" <<  c << " d=" << d << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
    }

};

class Parallelogram:public Quadrangle{
///    Параллелограмм:->четырехугольник->прямоугольник

public:
    Parallelogram(int a, int b, int A, int B):
    Quadrangle(a,b,a,b,A,B,A,B){
        set_figure("Параллелограмм:");
    }
};

class Rectangle:public Parallelogram{
///Прямоугольник:параллелограмм

public:
    Rectangle(int a, int b, int A): Parallelogram(a, b, A, A){
        set_figure("Прямоугольник:");
    }
};

class Rhombus:public Parallelogram{
///    Ромб:->параллелограмм->квадрат

public:
    Rhombus(int a, int A, int B):Parallelogram(a, a, A, B){
        set_figure("Ромб:");
    }
};

class Square:public Rhombus{
///   Квадрат:->ромб

public:
    Square(int a, int A): Rhombus(a, A, A){
        set_figure("Квадрат:");
    }
};

void print_info(Figure(*figure)){
    figure->print();
}



int main() {
    Triangle obj_triangle(10,20,30,50,60,70);
    Rectangle_triangle obj_rectangle_triangle(10,20,30,50,60);
    Triangle_two_sides_equal obj_triangleTwoSidesEqual(10,20,50,60,50);
    Triangle_three_sides_equal obj_triangleThreeSidesEqual(30);
    Quadrangle obj_quadrangle(10,20,30,40,50,60,70,80);
    Parallelogram obj_parallelogram(20,30,30,40);
    Rectangle obj_rectangle(10,20,90);
    Rhombus obj_rhombus(30,30,40);
    Square obj_square(20,90);


    print_info(&obj_triangle);
    print_info(&obj_rectangle_triangle);
    print_info(&obj_triangleTwoSidesEqual);
    print_info(&obj_triangleThreeSidesEqual);
    print_info(&obj_quadrangle);
    print_info(&obj_parallelogram);
    print_info(&obj_rectangle);
    print_info(&obj_rhombus);
    print_info(&obj_square);





//    Rectangle_triangle rectangleTriangle(10,20,30,50,60);
//    rectangleTriangle.print("Прямоугольный треугольник:");
//
//    Triangle_two_sides_equal triangleTwoSidesEqual(10,20,50,60,50);
//    triangleTwoSidesEqual.print("Равнобедренный треугольник:");
//
//    Triangle_three_sides_equal triangleThreeSidesEqual(30);
//    triangleThreeSidesEqual.print("Равносторонний треугольник:");
//
//    Quadrangle quadrangle(10,20,30,40,50,60,70,80);
//    quadrangle.print_with_four_sides("Четырёхугольник:");
//
//    Parallelogram parallelogram(20,30,30,40);
//    parallelogram.print_with_four_sides("Параллелограмм:");
//
//    Rectangle rectangle(10,20,90);
//    rectangle.print_with_four_sides("Прямоугольник:");
//
//    Rhombus rhombus(30,30,40);
//    rhombus.print_with_four_sides("Ромб:");
//
//    Square square(20,90);
//    square.print_with_four_sides("Квадрат:");


    return 0;
}
