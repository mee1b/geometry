#include <iostream>

class Figure
{
protected:
	std::string name;
	int sides;
public:
	Figure()
	{
		sides = 0;
	}
	void get_name(std::string name)
	{
		this->name = name;
	}
	void get_information() const
	{
		std::cout << name << sides << std::endl;
	}
};

class Triangle : public Figure
{
public:
	Triangle()
	{
		sides = 3;
	}
};

class Quadrilateral : public Figure
{
public:
	Quadrilateral()
	{
		sides = 4;
	}
};




int main()
{
	setlocale(LC_ALL, "rus");

	Figure f;
	Triangle t;
	Quadrilateral q;

	std::cout << "Количество сторон:" << std::endl;

	f.get_name("Фигура: ");
	t.get_name("Треугольник: ");
	q.get_name("Четырехугольник: ");

	f.get_information();
	t.get_information();
	q.get_information();



	return EXIT_SUCCESS;
}