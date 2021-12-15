#pragma once
#include <complex>
#include <iostream>

struct IntPoint2;
struct DoublePoint3;
struct StdComplexPoint;

template <typename T>
class BrokenLine {
private:
	T* _p;
	size_t _size;

public:
	BrokenLine() : _p(nullptr), _size(0) {}
	BrokenLine(unsigned int size) {
		if (size < 0) throw "Invalid index";
		_p = new T[size];
		_size = size;
	}
	BrokenLine(const BrokenLine& rhs) {
		_p = new T[rhs._size];
		_size = rhs._size;

		for (size_t i = 0; i < _size; i++)
		{
			_p[i] = rhs._p[i];
		}

	}

	size_t GetSize() const {
		return _size;
	}

	void SetSize(unsigned size)
	{
		_size = size;
		_p = new T[_size];
	}

	//void AddToHead(const IntPoint2& point) {
	//	_size += 1;
	//	T* tmp = new T[_size];
	//	tmp[0] = point;
	//	for (size_t i = 1; i < _size; i++)
	//	{
	//		tmp[i] = _p[i - 1];
	//	}
	//	if (_p != NULL) delete[] _p;
	//	_p = tmp;
	//}
	//void AddToHead(const DoublePoint3& point) {
	//	_size += 1;
	//	T* tmp = new T[_size];
	//	tmp[0] = point;
	//	for (size_t i = 1; i < _size; i++)
	//	{
	//		tmp[i] = _p[i - 1];
	//	}
	//	if (_p != NULL) delete[] _p;
	//	_p = tmp;

	//}

	void Swap(BrokenLine& rhs) {
		std::swap(_size, rhs._size);
		std::swap(_p, rhs._p);
	}

	T& operator[](size_t index) {
		if (_p == nullptr) throw "Line is empty";
		if ((index >= _size) || (index < 0)) throw "Invalid index";
		return _p[index];

	}
	T operator[](size_t index) const {
		if (_p == nullptr) throw "Line is empty";
		if ((index >= _size) || (index < 0)) throw "Invalid index";
		return _p[index];

	}

	void AddToHead(const T& point) {
		_size += 1;
		T* tmp = new T[_size];
		tmp[0] = point;
		for (size_t i = 1; i < _size; i++)
		{
			tmp[i] = _p[i - 1];
		}
		if (_p != NULL) delete[] _p;
		_p = tmp;

	}
	void AddToEnd(const T& point) {
		_size += 1;
		T* tmp = new T[_size];
		for (size_t i = 0; i < _size - 1; i++)
		{
			tmp[i] = _p[i];
		}
		tmp[_size - 1] = point;
		if (_p != NULL) delete[] _p;
		_p = tmp;

	}

	BrokenLine operator+(const BrokenLine& rhs) {
		if (!_size) return rhs;
		if (!rhs._size) return *this;
		BrokenLine res(_size + rhs._size);
		for (size_t i = 0; i < _size; i++)
		{
			res._p[i] = _p[i];
		}
		for (size_t i = 0; i < rhs._size; i++)
		{
			res._p[_size + i] = rhs._p[i];
		}
		return res;
	}


	BrokenLine operator+(const T& rhs) {
		BrokenLine tmp;
		tmp = *this;
		tmp.AddToEnd(rhs);

		return tmp;

	} //вставка в конец
	//BrokenLine operator<(const BrokenLine& rhs); //вставка в начало

	BrokenLine<IntPoint2>& operator=(const BrokenLine<IntPoint2>& rhs) {
		if (this == (&rhs)) return *this;
		if (_p) delete[] _p;
		if (rhs._p)
		{
			_p = new IntPoint2[rhs._size];
			_size = rhs._size;
			for (size_t i = 0; i < rhs._size; i++)
			{
				_p[i] = rhs._p[i];
			}
		}
		else
		{
			_p = NULL;
			_size = 0;
		}
		return *this;

	}
	BrokenLine<DoublePoint3>& operator=(const BrokenLine<DoublePoint3>& rhs) {
		if (this == (&rhs)) return *this;
		if (_p) delete[] _p;
		if (rhs._p)
		{
			_p = new DoublePoint3[rhs._size];
			_size = rhs._size;
			for (size_t i = 0; i < rhs._size; i++)
			{
				_p[i] = rhs._p[i];
			}
		}
		else
		{
			_p = NULL;
			_size = 0;
		}
		return *this;
	}
	BrokenLine< StdComplexPoint>& operator=(const BrokenLine< StdComplexPoint>& rhs) {
		if (this == (&rhs)) return *this;
		if (_p) delete[] _p;
		if (rhs._p)
		{
			_p = new StdComplexPoint[rhs._size];
			_size = rhs._size;
			for (size_t i = 0; i < rhs._size; i++)
			{
				_p[i] = rhs._p[i];
			}
		}
		else
		{
			_p = NULL;
			_size = 0;
		}
		return *this;
	}

	BrokenLine& operator=(const BrokenLine<std::complex<T>>& rhs) {
		if (this == (&rhs)) return *this;
		if (_p) delete[] _p;
		if (rhs._p)
		{
			_p = new T[rhs._size];
			_size = rhs._size;
			for (size_t i = 0; i < rhs._size; i++)
			{
				_p[i] = rhs._p[i];
			}
		}
		else
		{
			_p = NULL;
			_size = 0;
		}
		return *this;

	}

	bool operator==(const BrokenLine& rhs) const {
		if (_size != rhs._size) return false;
		for (size_t i = 0; i < _size; i++)
		{
			if (!(_p[i] == rhs._p[i])) return false;
		}
		return true;

	}

	bool operator!=(const BrokenLine& rhs) const {
		return !this->operator==(rhs);
	}

	auto SizeLine() const {
		if (_p == nullptr) throw "Line is empty";
		double res = 0;
		for (int i = 0; i < _size - 1; i++)
		{
			res += sqrt(pow(_p[i + 1]._x - _p[i]._x, 2) + (pow(_p[i + 1]._y - _p[i]._y, 2)));
		}
		return res;

	}

	~BrokenLine() {
		delete[] _p;
		_size = 0;

	}

};
//template <typename T>
//std::ostream& operator<<(std::ostream& out, const BrokenLine<std::complex<T>>& rhs);
//
//std::ostream& operator<<(std::ostream& out, const BrokenLine<IntPoint2>& rhs);
////TO DO
//std::ostream& operator<<(std::ostream& out, const BrokenLine<DoublePoint3>& rhs);

struct IntPoint2
{
	int _x, _y;

	bool operator==(const IntPoint2& p) const
	{
		if ((_x == p._x) && (_y == p._y)) return true;
		else return false;
	}

	float Distance(const IntPoint2& p) const
	{
		return static_cast<float>(sqrt(pow(_x - p._x, 2) + pow(_y - p._y, 2)));
	}

	BrokenLine<IntPoint2> operator+(const BrokenLine<IntPoint2>& rhs) {
		BrokenLine<IntPoint2> tmp;
		tmp = rhs;
		tmp.AddToHead(*this);
		return tmp;
	}

};
struct DoublePoint3
{
	double _x, _y, _z;

	bool operator==(const DoublePoint3& p) const
	{
		if ((_x == p._x) && (_y == p._y) && (_z == p._z)) return true;
		else return false;
	}

	double Distance(const DoublePoint3& p)
	{
		return sqrt(pow(_x - p._x, 2) + pow(_y - p._y, 2) + pow(_z - p._z, 2));
	}
	BrokenLine<DoublePoint3> operator+(const BrokenLine<DoublePoint3>& rhs) {
		BrokenLine<DoublePoint3> tmp;
		tmp = rhs;
		tmp.AddToHead(*this);
		return tmp;
	}
};
struct StdComplexPoint {
	std::complex<double> _x, _y;

	bool operator==(const StdComplexPoint& p) const
	{
		if ((_x == p._x) && (_y == p._y)) return true;
		else return false;
	}

	float Distance(const StdComplexPoint& p) const
	{
		return float(sqrt(_x.real() * _x.real() + _y.imag() * _y.imag()));
	}

	BrokenLine<StdComplexPoint> operator+(const BrokenLine<StdComplexPoint>& rhs) {
		BrokenLine<StdComplexPoint> tmp;
		tmp = rhs;
		tmp.AddToHead(*this);
		return tmp;
	}
};

std::ostream& operator<<(std::ostream& out, const IntPoint2& point)
{
	out << "[" << point._x << ";" << point._y << "]";
	return out;
}

std::ostream& operator<< (std::ostream& out, const DoublePoint3& point)
{
	out << "[" << point._x << ";" << point._y << ";" << point._z << "]";
	return out;
}

std::ostream& operator<< (std::ostream& out, const std::complex<double>& point)
{
	out << "[" << point.real() << ";" << point.imag() << " * i" << "]";
	return out;
}

template <class T>
std::ostream& operator<< (std::ostream& out, const BrokenLine<T>& rhs)
{
	out << "BrokenLine <";
	for (size_t i = 0; i < rhs.GetSize(); i++)
	{
		if (i != rhs.GetSize() - 1) out << rhs[i] << ", ";
		else out << rhs[i];
	}
	out << ">";
	return out;
}

std::ostream& operator<<(std::ostream& out, const BrokenLine<IntPoint2>& rhs)
{
	for (size_t i = 0; i < rhs.GetSize(); i++) {
		out << rhs[i];
	}
	return out;

}

std::ostream& operator<<(std::ostream& out, const BrokenLine<DoublePoint3>& rhs)
{
	for (size_t i = 0; i < rhs.GetSize(); i++) {
		out << rhs[i];
	}
	return out;
}

std::ostream& operator<<(std::ostream& out, const BrokenLine<std::complex<double>>& rhs)
{
	for (size_t i = 0; i < rhs.GetSize(); i++) {
		out << rhs[i];
	}
	return out;

}
