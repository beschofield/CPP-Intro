#include <iostream>
#include <vector>
//#include "vektor.hpp"

#include <boost/iterator/iterator_facade.hpp>

using namespace std;

#define VEKTOR_NO_ERROR			0
#define VEKTOR_BAD_DIMENSION	1

template<typename T>
class matrix;

template<typename T>
class matrix
{
private:
	vektor<vektor<T>> mat;
	unsigned int r;
	unsigned int c;

public:
	matrix();
	matrix(const T &v);
	matrix(const vector<T> &v);
	matrix(const vector<vector<T>> &v);

	matrix<T>& 	operator=(const T &o);
	matrix<T>& 	operator=(const vector<T> &o);
	matrix<T>& 	operator=(const vector<vector<T>> &o);
	matrix<T>& 	operator=(const matrix<T> &o);

	bool operator==(vector<vector<T>> o);

	vector<T>& operator[](unsigned int i);

	matrix<T>	operator+(matrix<T> &o);
	matrix<T>	operator-(matrix<T> &o);
	matrix<T>	operator*(T o);
	matrix<T>	operator*(matrix<T> &o);

	unsigned int	rows() const;
	unsigned int	columns() const;
	bool			isValid() const;

	vektorIterator<T>	begin();
	vektorIterator<T>	end();

	friend ostream& operator<<(ostream& s, matrix<T> &MX)
	{
		for (auto i = 0; i < MX.r; i++)
		{
			i << "\n[\t";

			for (auto j = 0; j < MX.c; j++)
			{
				s << MX.mat[j][i];
				s << "\t";
			}

			s << "]";
		}

		return(s);
	}

	bool isValid()
	{
		return((r != 0) && (c != 0));
	}

	void resize(unsigned int x, unsigned int y)
	{
		mat.resize(x);
		c = x;
		r = y;
		for (auto i = 0; i < c; i++)
		{
			mat[i].resize(y);
		}
	}

	bool isSquare()
	{
		return (isValid() and(r == c));
	}

	//INVERSE

};

template<typename T>
matrix<T>::matrix()
{
	r=0;
	c=0;
}

template<typename T>
matrix<T>::matrix(const T &v)
{
	vector<T> vec;
	vec.push_back(v);
	mat={vec};
	r=1;
	c=1;
}

template<typename T>
matrix<T>::matrix(const vector<T> &v)
{
	mat={v};
	r=v.size();
	c=1;
}

template<typename T>
matrix<T>::matrix(const vector<vector<T>> &v)
{
	mat = v;
	r = v[0].size();
	c = v.size();
}

template<typename T>
bool matrix<T>::operator==(vector<vector<T>> o)
{
	matrix<T>t=o;
	return matrix<T>::operator==(t);
}

template<typename T>
vector<T>& matrix<T>::operator[](unsigned int index)
{
	return mat[index];
}

template<typename T>
matrix<T> matrix<T>::operator+(matrix<T> &o)
{
	if (mat.size() == o.size())
	{
		matrix<T> result;
		result.resize(r, c);

		for (auto i = 0; i<c; i++)
		{
			for (auto j = 0; j<r; j++)
			{
				result[i][j] = mat[i][j] + o[i][j];
			}
		}

		return result;
	}

	else
	{
		return 0;
	}
}

template<typename T>
matrix<T> matrix<T>::operator-(matrix<T> &o)
{
	if (mat.size() == o.size())
	{
		matrix<T> result;
		result.resize(r, c);

		for (auto i = 0; i<c; i++)
		{
			for (auto j = 0; j<r; j++)
			{
				result[i][j] = mat[i][j] - o[i][j];
			}
		}

		return result;
	}

	else
	{
		return 0;
	}
}

template<typename T>
matrix<T> matrix<T>::operator*(T o)
{
	matrix<T> result;
	result.resize(r, c);

	for (auto i = 0; i < c; i++)
	{
		for (auto j = 0; j < r; j++)
		{
			result[i][j] = mat[i][j] * o;
		}
	}

	return result;
}

template<typename T>
matrix<T> matrix<T>::operator*(matrix<T> &o)
{
	matrix<T> result;
	result.resize(r, o.c);

	for (auto i = 0; i < o.c; i++)
	{
		for (auto j = 0; j < r; j++)
		{
			vector<T> A = o.mat[i];
			vector<T> B;

			for (auto x = 0; x < this->mat.r; x++)
			{
				B.push_back(this->mat[x][j]);
			}

			result.mat[i][j] += A*B;
		}
	}

	return result;
}
