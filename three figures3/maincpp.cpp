#include <iostream>

class Figure
{
protected:
	int sides;
	std::string name;

	virtual void check_figure()
	{
		if (sides == 0)
		{
			std::cout << "����������\n";
			return;
		}
		std::cout << "�����������\n";
	}
public:
	Figure()
	{
		sides = 0;
		name = "������";
	}
	virtual void get_sides(int sides)
	{
		this->sides = sides;
	}
	virtual void print_info()
	{
		std::cout << name << ":\n";
		check_figure();
		std::cout << "���������� ������: " << sides << "\n\n";
	}
};

class Triangle : public Figure
{
protected:
	int side_a, side_b, side_c;
	int corner_a, corner_b, corner_c;

	void check_figure() override
	{
		if ((sides == 3) && (corner_a + corner_b + corner_c == 180))
		{
			std::cout << "����������\n";
			return;
		}
		std::cout << "�����������\n";
	}
public:
	Triangle()
	{
		name = "�����������";
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
	void print_info() override
	{
		std::cout << name << ":\n";
		check_figure();
		std::cout << "���������� ������: " << sides << std::endl;
		std::cout << "�������: � = " << side_a << " b = " << side_b << " c = " << side_c << std::endl;
		std::cout << "����: � = " << corner_a << " B = " << corner_b << " C = " << corner_c << std::endl << std::endl;
	}
};

class Equilateral_triangle : public Triangle
{
protected:
	void check_figure() override
	{
		if ((sides == 3) && (side_a == side_b) && (side_b == side_c) && (corner_a == 60) && (corner_a == corner_b) && (corner_b == corner_c) && (corner_a + corner_b + corner_c == 180))
		{
			std::cout << "����������\n";
			return;
		}
		std::cout << "�����������\n";
	}
public:
	Equilateral_triangle()
	{
		name = "�������������� �����������";
	}
	void get_side(int a, const int b = 0, const int c = 0) override
	{
		side_a = a;
		side_b = a;
		side_c = a;
	}
	void get_corner(const int a = 60, const int b = 60, const int c = 60) override
	{
		corner_a = a;
		corner_b = b;
		corner_c = c;
	}
};

class Isosceles_triangle : public Triangle
{
protected:
	void check_figure() override
	{
		if ((sides == 3) && (side_a == side_c) && (corner_a == corner_c) && (corner_a + corner_b + corner_c == 180))
		{
			std::cout << "����������\n";
			return;
		}
		std::cout << "�����������\n";
	}
public:
	Isosceles_triangle()
	{
		name = "�������������� �����������";
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
protected:
	void check_figure() override
	{
		if ((sides == 3) && (corner_c = 90) && (corner_a + corner_b + corner_c == 180))
		{
			std::cout << "����������\n";
			return;
		}
		std::cout << "�����������\n";
	}
public:
	Rightangled_triangle()
	{
		name = "������������� �����������";
	}
	void get_corner(int a, int b, const int c = 90) override
	{
		corner_a = a;
		corner_b = b;
		corner_c = c;
	}
};

class Quadrilateral : public Figure
{
protected:
	int side_a, side_b, side_c, side_d;
	int corner_a, corner_b, corner_c, corner_d;
	void check_figure() override
	{
		if ((sides == 4) && (corner_a + corner_b + corner_c + corner_d == 360))
		{
			std::cout << "����������\n";
			return;
		}
		std::cout << "�����������\n";
	}
public:
	Quadrilateral()
	{
		name = "���������������";
		side_a = 0;
		side_b = 0;
		side_c = 0;
		side_d = 0;

		sides = 0;

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
	void print_info() override
	{
		std::cout << name << ":\n";
		check_figure();
		std::cout << "���������� ������: " << sides << std::endl;
		std::cout << "�������: � = " << side_a << " b = " << side_b << " c = " << side_c << " d = " << side_d << std::endl;
		std::cout << "����: � = " << corner_a << " B = " << corner_b << " C = " << corner_c << " D = " << corner_d << std::endl << std::endl;
	}
};

class Rectangle : public Quadrilateral
{
protected:
	void check_figure() override
	{
		if ((sides == 4) && (corner_a + corner_b + corner_c + corner_d == 360) && (side_a == side_c) && (side_b == side_d))
		{
			std::cout << "����������\n";
			return;
		}
		std::cout << "�����������\n";
	}
public:
	Rectangle()
	{
		name = "�������������";
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
protected:
	void check_figure() override
	{
		if ((sides == 4) && (corner_a = 90) && (corner_b == 90) && (corner_c == 90) && (corner_d == 90) && (side_a == side_b) && (side_b == side_c) && (side_c == side_d))
		{
			std::cout << "����������\n";
			return;
		}
		std::cout << "�����������\n";
	}
public:
	Square()
	{
		name = "�������";
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
protected:
	void check_figure() override
	{
		if ((sides == 4) && (corner_a + corner_b + corner_c + corner_d == 360) && (side_a == side_c) && (side_b == side_d) && (corner_a == corner_c) && (corner_b == corner_d))
		{
			std::cout << "����������\n";
			return;
		}
		std::cout << "�����������\n";
	}
public:
	Parallelogram()
	{
		name = "��������������";
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
protected:
	void check_figure() override
	{
		if ((sides == 4) && (corner_a = corner_c) && (corner_b == corner_d) && (side_a == side_b) && (side_b == side_c) && (side_c == side_d))
		{
			std::cout << "����������\n";
			return;
		}
		std::cout << "�����������\n";
	}
public:
	Rhomb()
	{
		name = "����";
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

	Figure f;
	f.get_sides(0);
	f.print_info();
;
	Triangle t;
	t.get_sides(3);
	t.get_corner(10, 20, 30);
	t.get_side(50, 60, 70);
	t.print_info();

	Equilateral_triangle e;
	e.get_sides(3);
	e.get_side(50, 300, 1520);
	e.get_corner();
	e.print_info();

	Isosceles_triangle i;
	i.get_sides(3);
	i.get_side(30, 40, 100);
	i.get_corner(60, 70, 50);
	i.print_info();

	Rightangled_triangle r;
	r.get_sides(3);
	r.get_side(10, 20, 30);
	r.get_corner(45, 45, 100);
	r.print_info();

	Quadrilateral q;
	q.get_sides(4);
	q.get_side(50, 60, 70, 80);
	q.get_corner(80, 70, 50, 120);
	q.print_info();

	Rectangle re;
	re.get_sides(4);
	re.get_side(50, 80, 110, 30);
	re.get_corner();
	re.print_info();

	Square s;
	s.get_sides(4);
	s.get_side(50, 70, 20, 33);
	s.get_corner();
	s.print_info();

	Parallelogram p;
	p.get_sides(4);
	p.get_side(20, 85, 30, 12);
	p.get_corner(70, 99, 25, 13);
	p.print_info();

	Rhomb rh;
	rh.get_sides(4);
	rh.get_side(50, 70, 90, 120);
	rh.get_corner(90, 100, 150, 30);
	rh.print_info();



	return EXIT_SUCCESS;
}