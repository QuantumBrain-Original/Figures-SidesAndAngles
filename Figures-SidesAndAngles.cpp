#include <iostream>
//#include <string>
#include <Windows.h>

class Figure
{
	protected:
		unsigned int a, b, c, d, A, B, C, D;
	public:
		int get_angle_A()
		{
			return A;
		}

		int get_angle_B()
		{
			return B;
		}

		int get_angle_C()
		{
			return C;
		}

		int get_angle_D()
		{
			return D;
		}

		int get_side_A()
		{
			return a;
		}

		int get_side_B()
		{
			return b;
		}

		int get_side_C()
		{
			return c;
		}

		int get_side_D()
		{
			return d;
		}

		Figure(int sideA = 0, int sideB = 0, int sideC = 0, int sideD = 0, int angleA = 0, int angleB = 0, int angleC = 0, int angleD = 0) :
			a(sideA), b(sideB), c(sideC), d(sideD), A(angleA), B(angleB), C(angleC), D(angleD) {}
};

// фигуры с 3 углами
class Triangle : public Figure
{
	public:
		Triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC) : Figure(sideA, sideB, sideC, 0, angleA, angleB, angleC, 0) {}
};

class RectangularTriangle : public Triangle // Прямоугольный треугольник (угол C всегда равен 90)
{
	public:
		RectangularTriangle(int sideA, int sideB, int sideC, int angleA, int angleB) : Triangle(sideA, sideB, sideC, angleA, angleB, 90) {}
};

class IsoscelesTriangle : public Triangle // Равнобедренный треугольник (стороны a и c равны, углы A и C равны)
{
	public:
		IsoscelesTriangle(int sideA, int sideB, int angleA, int angleB) : Triangle(sideA, sideB, sideA, angleA, angleB, angleA) {}
};

class EquilateralTriangle : public Triangle // Равносторонний треугольник (все стороны равны, все углы равны 60)
{
	public:
		EquilateralTriangle(int sideA) : Triangle(sideA, sideA, sideA, 60, 60, 60) {}
};

// фигуры с 4 углами
class Quadrangle : public Figure // Четырехугольник
{
	public:
		Quadrangle(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD) : Figure(sideA, sideB, sideC, sideD, angleA, angleB, angleC, angleD) {}
};

class Parallelogram : public Quadrangle // Параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны)
{
	public:
		Parallelogram(int sideA, int sideB, int angleA, int angleB) : Quadrangle(sideA, sideB, sideA, sideB, angleA, angleB, angleA, angleB) {}
};

class Rhombus : public Parallelogram // Ромб (все стороны равны, углы A,C и B,D попарно равны)
{
	public:
		Rhombus(int sideA, int angleA, int angleB) : Parallelogram(sideA, sideA, angleA, angleB) {}
};

class Rectangles : public Parallelogram // Прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90)
{
	public:
		Rectangles(int sideA, int sideB) : Parallelogram(sideA, sideB, 90, 90) {}
};

class Square : public Rectangles // Квадрат (все стороны равны, все углы равны 90)
{
	public:
		Square(int sideA) : Rectangles(sideA, sideA) {}
};

void print_info(Figure* objFigure)
{
	std::cout << "Стороны:";
	std::cout << " a=" << objFigure->get_side_A();
	std::cout << " b=" << objFigure->get_side_B();
	std::cout << " c=" << objFigure->get_side_C();
	if(objFigure->get_side_D() > 0)
		std::cout << " d=" << objFigure->get_side_C();
	std::cout << "\n";

	std::cout << "Углы:";
	std::cout << " A=" << objFigure->get_angle_A();
	std::cout << " B=" << objFigure->get_angle_B();
	std::cout << " C=" << objFigure->get_angle_C();
	if (objFigure->get_angle_D() > 0)
		std::cout << " D=" << objFigure->get_angle_D();
	std::cout << "\n";
}

int main() // Задача 2. Фигуры. Стороны и углы
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	Triangle* triengle = new Triangle{10, 20, 30, 50, 60, 70};
	RectangularTriangle* rectangularTriangle = new RectangularTriangle{ 10, 20, 30, 50, 60 }; // Прямоугольный треугольник
	IsoscelesTriangle* isoscelesTriangle = new IsoscelesTriangle{ 10, 20, 50, 60 }; // Равнобедренный треугольник
	EquilateralTriangle* equilateralTriangle = new EquilateralTriangle{30}; // Равносторонний треугольник

	std::cout << "Треугольник:" << std::endl;
	print_info(triengle);

	std::cout << "\nПрямоугольный треугольник:" << std::endl;
	print_info(rectangularTriangle);

	std::cout << "\nРавнобедренный треугольник:" << std::endl;
	print_info(isoscelesTriangle);

	std::cout << "\nРавносторонний треугольник:" << std::endl;
	print_info(equilateralTriangle);

	delete equilateralTriangle;
	delete isoscelesTriangle;
	delete rectangularTriangle;
	delete triengle;

	Quadrangle *quadrangle = new Quadrangle{ 10, 20, 30, 40, 50, 60, 70, 80 }; // Четырехугольник
	Parallelogram* parallelogram = new Parallelogram{20, 30, 30, 40}; // Параллелограмм
	Rhombus* rhombus = new Rhombus{30, 30, 40}; // Ромб
	Rectangles* rectangles = new Rectangles{ 10, 20 }; // Прямоугольник
	Square* square = new Square{10}; // Квадрат

	std::cout << "\nЧетырехугольник:" << std::endl;
	print_info(quadrangle);

	std::cout << "\nПрямоугольник:" << std::endl;
	print_info(rectangles);

	std::cout << "\nКвадрат:" << std::endl;
	print_info(square);

	std::cout << "\nПараллелограмм:" << std::endl;
	print_info(parallelogram);

	std::cout << "\nРомб:" << std::endl;
	print_info(rhombus);

	delete square;
	delete rectangles;
	delete rhombus;
	delete parallelogram;
	delete quadrangle;

}
