#include <iostream>
#include <vector>


template<typename T>
class vektor 
{
	private:
		std::vector<T>	x;
	public:
		vektor();
		vektor(const std::vector<T> &v);
		~vektor();
		vektor<T>& 	operator=(const std::vector<T> &o);
		vektor<T>	operator+(const vektor<T> &o);
		vektor<T>	operator-(const vektor<T> &o);
		vektor<T>	operator*(const vektor<T> &o);
		vektor<T>	operator*(const T &a);
		unsigned int	dimension() const;
		bool			isValid() const;

		operator std::vector<T>() const
		{
			return(x);
		}

		template<typename U>
		vektor<T>& operator=(const vektor<U> &r) 
		{
			std::vector<U>	v;
			
			v = (std::vector<U>)r;
			x.resize(v.size());
			for(auto i = 0; i< v.size(); i++) {
				x[i] = v[i];
			}

			return(*this);
		}

	friend std::ostream& operator<<(std::ostream& s, vektor<T> &v) {
		int	i;

		if(v.x.size() > 0) {
			s << "<";
			for(i=0; i<v.x.size() -1; i++) {
				s << v.x[i] << ",";
			}
			s << v.x[i] << ">";
			return s;
		} else {
			s << "<NO_SIZE>";
			return(s);
		}
	}

	friend vektor<T> operator*(const T &r, const vektor<T> &l)
	{
		vektor<T>	z;
	
		z.x.resize(l.x.size());
		for(auto i = 0; i < l.x.size(); i++) {
			z.x[i] = l.x[i] * r;
		}
		return(z);
	}


};

template<typename T>
vektor<T>::vektor()
{
	std::cout << "Construct vektor" << std::endl;
	return;
}


template<typename T>
vektor<T>::vektor(const std::vector<T> &o)
{
	std::cout << "Construct vektor from vector<T>" << std::endl;
	x = o;
	return;
}

template<typename T>
vektor<T>::~vektor()
{
	std::cout << "Destruct vektor" << std::endl;
	return;
}

template<typename T>
vektor<T>& vektor<T>::operator=(const std::vector<T> &o) 
{
	x = o;
	std::cout << "assign vektor" << std::endl;
	return(*this);
}

template <typename T>
vektor<T>	vektor<T>::operator+(const vektor<T> &o)
{
	vektor<T>	r;
	std::vector<T>	y;

	std::cout << "operator+ with x.size() = " << x.size() << std::endl;
	if(x.size() != o.x.size()) {
		r.x.resize(0);
		return(r);
	}
	y.resize(x.size());
	for(auto i = 0; i< x.size(); i++) {
		y[i] = x[i] + o.x[i];
	}
	r = y;
	return(r);

}

template<typename T>
vektor<T> vektor<T>::operator-(const vektor<T> &o)
{
	vektor<T> vec;
	
	if(x.size() != o.x.size()) 
	{
		cout << "different sizes";
		return(vec);
	}
	
	vec.x.resize(x.size());
	
	for(auto i=0; i<x.size(); i++)
	{
		vec.x[i]=x[i]-o.x[i]
	}

	return(vec);
}

template<typename T>
vektor<T> vektor<T>::operator*(const vektor<T> &o)
{
	vektor<T> vec;

	if(x.size() != o.x.size()) 
	{
		cout << "different sizes";
		return(vec);
	}
	
	T trans=0;
	
	for(auto i=0; i<x.size(); i++) 
	{
		trans += x[i] * o.x[i];
	}
	
	vec={trans};
	return(vec);
}

template<typename T>
vektor<T> vektor<T>::operator*(const T &a)
{
	vektor<T> vec;
	vec.x.resize(x.size());
	
	for(auto i=0; i<x.size(); i++) 
	{
		vec.x[i] = x[i] * a;
	}
	
	return(vec);
}

template<typename T>
int vektor<T>::dimension() (const)
{
	return(x.size());
}

template<typename T>
bool vektor<T>::isValid() (const) 
{
	if(x.size()==0)
	{
		return false;
	}
	
	else
	{
		return true;
	}
}

template<typename T, typename U>
vektor<T>::operator=(const vektor<U>) //&o
{
	vektor<T> vec;

	for(auto i=0; i<x.size(); i++)
	{
		vec.x[i]=(T)(o.x[i]);
	}
	
	return(vec);
}

