#include <iostream>
#include <Windows.h>

class Figure
{
	protected:
		unsigned int sides_count;
	public:
		virtual void print_output()
		{
			std::cout << "Стороны: Нет\n" << "Углы: Нет\n" << std::endl;
		}

		Figure() : sides_count(0) {}
};

// фигуры с 3 углами
class Triangle : public Figure
{
	protected:
		unsigned int a, b, c, A, B, C;
	public:
		void print_output() override
		{
			if (sides_count == 3)
			{
				std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
				std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
			}
		}

		Triangle(int sideA = 0, int sideB = 0, int sideC = 0, int angleA = 0, int angleB = 0, int angleC = 0) :
			a(sideA), b(sideB), c(sideC), A(angleA), B(angleB), C(angleC)
		{
			sides_count = 3;
		}
};

class RectangularTriangle : public Triangle // Прямоугольный треугольник (угол C всегда равен 90)
{
	public:
		RectangularTriangle(int sideA = 0, int sideB = 0, int sideC = 0, int angleA = 0, int angleB = 0) :
			Triangle(sideA, sideB, sideC, angleA, angleB, 90)
		{
			sides_count = 3;
		}
};

class IsoscelesTriangle : public Triangle // Равнобедренный треугольник (стороны a и c равны, углы A и C равны)
{
	public:
		IsoscelesTriangle(int sideA = 0, int sideB = 0, int angleA = 0, int angleB = 0) :
			Triangle(sideA, sideB, sideA, angleA, angleB, angleA)
		{
			sides_count = 3;
		}
};

class EquilateralTriangle : public Triangle // Равносторонний треугольник (все стороны равны, все углы равны 60)
{
	public:
		EquilateralTriangle(int sideA = 0) : Triangle(sideA, sideA, sideA, 60, 60, 60)
		{
			sides_count = 3;
		}
};

// фигуры с 4 углами
class Quadrangle : public Figure // Четырехугольник
{
	protected:
		unsigned int a, b, c, d, A, B, C, D;
	public:
		void print_output() override
		{
			if (sides_count == 4)
			{
				std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
				std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
			}
		}

		Quadrangle(int sideA = 0, int sideB = 0, int sideC = 0, int sideD = 0, int angleA = 0, int angleB = 0, int angleC = 0, int angleD = 0) :
			a(sideA), b(sideB), c(sideC), d(sideD), A(angleA), B(angleB), C(angleC), D(angleD)
		{
			sides_count = 4;
		}
};

class Parallelogram : public Quadrangle // Параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны)
{
	public:
		Parallelogram(int sideA = 0, int sideB = 0, int angleA = 0, int angleB = 0) :
			Quadrangle(sideA, sideB, sideA, sideB, angleA, angleB, angleA, angleB)
		{
			sides_count = 4;
		}
};

class Rhombus : public Parallelogram // Ромб (все стороны равны, углы A,C и B,D попарно равны)
{
	public:
		Rhombus(int sideA = 0, int angleA = 0, int angleB = 0) :
			Parallelogram(sideA, sideA, angleA, angleB)
		{
			sides_count = 4;
		}
};

class Rectangles : public Parallelogram // Прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90)
{
	public:
		Rectangles(int sideA = 0, int sideB = 0) : Parallelogram(sideA, sideB, 90, 90)
		{
			sides_count = 4;
		}
};

class Square : public Rectangles // Квадрат (все стороны равны, все углы равны 90)
{
	public:
		Square(int sideA = 0) : Rectangles(sideA, sideA)
		{
			sides_count = 4;
		}
};

void print_info(Figure* objFigure)
{
	if (objFigure != nullptr)
		objFigure->print_output();
	else
		std::cout << "Ошибка чтения указателя!\n";
}

int main() // Задача 2. Фигуры. Стороны и углы
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	Figure* unkFigure = new Figure{};
	Triangle* triengle = new Triangle{10, 20, 30, 50, 60, 70};
	RectangularTriangle* rectangularTriangle = new RectangularTriangle{ 10, 20, 30, 50, 60 }; // Прямоугольный треугольник
	IsoscelesTriangle* isoscelesTriangle = new IsoscelesTriangle{ 10, 20, 50, 60 }; // Равнобедренный треугольник
	EquilateralTriangle* equilateralTriangle = new EquilateralTriangle{30}; // Равносторонний треугольник

	std::cout << "Фигура:" << std::endl;
	print_info(unkFigure);

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
	delete unkFigure;

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
