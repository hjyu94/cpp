#include <iostream>
#include <fstream>
using namespace std;

class Point
{
private:
	double m_x, m_y, m_z;

public:
	Point(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x(x), m_y(y), m_z(z)
	{}

	double getX() { return m_x; }
	double getY() { return m_y; }
	double getZ() { return m_z; }

	/*void print()
	{
		cout << m_x << " " << m_y << " " << m_z;
	}*/

	friend std::ostream& operator << (std::ostream& out, const Point& point)
	{
		out << point.m_x << " " << point.m_y << " " << point.m_z;
		return out; // for chaining
	}

	friend std::istream& operator >> (std::istream& in, Point& point)
	{
		in >> point.m_x >> point.m_y >> point.m_z;
		return in; // for chaining
	}
};

int main()
{
	ofstream of("out.txt");

	Point p1(0.0, 0.1, 0.2), p2(3.4, 1.5, 2.0);

	/*p1.print();
	cout << endl;
	p2.print();
	cout << endl;*/

	cout << p1 << endl << p2 << endl;
	of << p1 << endl << p2 << endl;

	of.close();

	Point p3, p4;
	cin >> p3 >> p4;
	cout << p3 << endl << p4 << endl;

	return 0;
}