#include <iostream>


class Triangle
{
protected:
	int side_a, side_b, side_c;
	int corner_a, corner_b, corner_c;
	std::string name;
public:
	Triangle()
	{
		name = "Треугольник";
		side_a = 0;
		side_b = 0;
		side_c = 0;

		corner_a = 0;
		corner_b = 0;
		corner_c = 0;
	}
	virtual void get_side(int a, int b, int c)
	{
		side_a = a;
		side_b = b;
		side_c = c;
	}
	virtual void get_corner(int a, int b, int c)
	{
		corner_a = a;
		corner_b = b;
		corner_c = c;
	}
	void print_info() const
	{
		std::cout << name << ":\n";
		std::cout << "Стороны: а = " << side_a << " b = " << side_b << " c = " << side_c << std::endl;
		std::cout << "Углы: А = " << corner_a << " B = " << corner_b << " C = " << corner_c << std::endl << std::endl;
	}
};

class Equilateral_triangle : public Triangle
{
public:
	Equilateral_triangle()
	{
		name = "Равносторонний треугольник";
	}
	void get_side(int a, const int b = 0, const int c = 0) override
	{
		side_a = a;
		side_b = a;
		side_c = a;
	}
	void get_corner(const int a = 60, const int b = 60, const int c = 60)
	{
		corner_a = a;
		corner_b = b;
		corner_c = c;
	}
};

class Isosceles_triangle : public Triangle
{
public:
	Isosceles_triangle()
	{
		name = "Равнобедренный треугольник";
	}
	void get_side(int a, int b, int c = 0) override
	{
		if (a != c)
		{
			c = a;
		}
		side_a = a;
		side_b = b;
		side_c = c;
	}
	void get_corner(int a, int b, int c = 0) override
	{
		if (a != c)
		{
			c = a;
		}
		corner_a = a;
		corner_b = b;
		corner_c = c;
	}
};

class Rightangled_triangle : public Triangle
{
public:
	Rightangled_triangle()
	{
		name = "Прямоугольный треугольник";
	}
	void get_corner(int a, int b, const int c = 90) override
	{
		corner_a = a;
		corner_b = b;
		corner_c = c;
	}
};

class Quadrilateral
{
protected:
	int side_a, side_b, side_c, side_d;
	int corner_a, corner_b, corner_c, corner_d;
	std::string name;
public:
	Quadrilateral()
	{
		name = "Четырехугольник";
		side_a = 0;
		side_b = 0;
		side_c = 0;
		side_d = 0;

		corner_a = 0;
		corner_b = 0;
		corner_c = 0;
		corner_d = 0;
	}
	virtual void get_side(int a, int b, int c, int d)
	{
		side_a = a;
		side_b = b;
		side_c = c;
		side_d = d;
	}
	virtual void get_corner(int a, int b, int c, int d)
	{
		corner_a = a;
		corner_b = b;
		corner_c = c;
		corner_d = d;
	}
	void print_info() const
	{
		std::cout << name << ":\n";
		std::cout << "Стороны: а = " << side_a << " b = " << side_b << " c = " << side_c << " d = " << side_d << std::endl;
		std::cout << "Углы: А = " << corner_a << " B = " << corner_b << " C = " << corner_c << " D = " << corner_d << std::endl << std::endl;
	}
};

class Rectangle : public Quadrilateral
{
public:
	Rectangle()
	{
		name = "Прямоугольник";
	}
	void get_side(int a, int b, int c = 0, int d = 0) override
	{
		if ((a != c) && (b != d))
		{
			c = a;
			d = b;
		}
		side_a = a;
		side_b = b;
		side_c = c;
		side_d = d;
	}
	void get_corner(const int a = 90, const int b = 90, const int c = 90, const int d = 90) override
	{
		corner_a = a;
		corner_b = b;
		corner_c = c;
		corner_d = d;
	}
};

class Square : public Rectangle
{
public:
	Square()
	{
		name = "Квадрат";
	}
	void get_side(int a, int b, int c, int d) override
	{
		d = a;
		c = a;
		b = a;
		side_a = a;
		side_b = b;
		side_c = c;
		side_d = d;
	}

};

class Parallelogram : public Rectangle
{
public:
	Parallelogram()
	{
		name = "Параллелограмм";
	}
	void get_corner(int a, int b, int c, int d) override
	{
		if ((a != c) && (b != d))
		{
			c = a;
			d = b;
		}
		corner_a = a;
		corner_b = b;
		corner_c = c;
		corner_d = d;
	}
};

class Rhomb : public Square
{
public:
	Rhomb()
	{
		name = "Ромб";
	}
	void get_corner(int a, int b, int c, int d)
	{
		if ((a != c) && (b != d))
		{
			c = a;
			d = b;
		}
		corner_a = a;
		corner_b = b;
		corner_c = c;
		corner_d = d;
	}
};




int main()
{
	setlocale(LC_ALL, "rus");
;
	Triangle t;
	t.get_corner(10, 20, 30);
	t.get_side(50, 60, 70);
	t.print_info();

	Equilateral_triangle e;
	e.get_side(50, 300, 1520);
	e.get_corner();
	e.print_info();

	Isosceles_triangle i;
	i.get_side(30, 40, 100);
	i.get_corner(60, 70, 50);
	i.print_info();

	Rightangled_triangle r;
	r.get_side(10, 20, 30);
	r.get_corner(45, 45, 100);
	r.print_info();

	Quadrilateral q;
	q.get_side(50, 60, 70, 80);
	q.get_corner(80, 70, 50, 120);
	q.print_info();

	Rectangle re;
	re.get_side(50, 80, 110, 30);
	re.get_corner();
	re.print_info();

	Square s;
	s.get_side(50, 70, 20, 33);
	s.get_corner();
	s.print_info();

	Parallelogram p;
	p.get_side(20, 85, 30, 12);
	p.get_corner(70, 99, 25, 13);
	p.print_info();

	Rhomb rh;
	rh.get_side(50, 70, 90, 120);
	rh.get_corner(90, 100, 150, 30);
	rh.print_info();



	return EXIT_SUCCESS;
}