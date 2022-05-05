#include <iostream>
#include <vector>


class Base {
public:
	virtual void show() = 0;
};

template <class T> 
class Point2D {
public:
	Point2D(T x, T y) : x(x), y(y) {}

protected:
	T x, y;
};

template <class T> 
class Z {
public:
	Z(T z) : z(z) {}

protected:
	T z;
};

template <class T>
class H {
public:
	H(T h) : h(h) {}

protected:
	T h;
};

template <class T> 
class Point3Dh : public Point2D<T>, public Z<T>, public H<T>, public Base {
public:
    Point3Dh(T x, T y, T z, T h) : Point2D<T> (x, y), Z<T> (z), H<T> (h) {}
        void show() {
            try
            {
			    if (this->h == 0) throw 0;
	        	std::cout << "X: " << this->x / this->h << ", Y: " << this->y / this->h << ", Z: " << this->z / this->h << std::endl;
            }
			catch (...)
			{
		    	std::cout << "H не должна равняться 0" << std::endl;
			}
		}
};

int main() {
	Point3Dh <int> point1(23, 13, 65, 4);
	Point3Dh <short> point2(4, 2, 5, 7); 
	Point3Dh <float> point3(4.3, 6.4, 2.7, 0);
	Point3Dh <double> point4(14.243, 23.43, 75.5354, 33.2234);
	Point3Dh <long> point5(58948, 21398209, 2432435, 2138244);

	std::vector<Base*> v;
	v.push_back((Base*)&point1);
	v.push_back((Base*)&point2);
	v.push_back((Base*)&point3);
	v.push_back((Base*)&point4);
	v.push_back((Base*)&point5);
	
	for (auto point : v) 
		point->show();
}
