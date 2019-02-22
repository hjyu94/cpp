#include <iostream>

using namespace std;

class Point
{
private:
	double m_x, m_y, m_z;
public:
	Point(double x, double y, double z)
	{
		m_x = x; m_y = y; m_z = z;
	}

	friend ostream& operator << (ostream& out, const Point& point)
	{
		out << point.m_x << " " << point.m_y << " " << point.m_z;
		return out;
	}
};

void main()
{
	Point point( 1.0, 2.0, 3.0 );
	cout << point << endl;
}