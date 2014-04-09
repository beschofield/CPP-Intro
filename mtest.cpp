#include <iostream>
#include "vektor.hpp"
#include "matrix.hpp"

using namespace std;

void test1()
{
	matrix<float> m;
	cout << "test1 success\n";
	return;
}

void test2()
{
	matrix<float> m;
	m = 1;
	cout << "test2 success\n";
	return;
}

void test3()
{
	matrix<float> m;
	vector<float> v = { 2.0, 3.0, 4.0 };
	m = v;
	cout << "test3 success\n";
	return;
}

void test4()
{
	vector<float> x = {2.0, 3.0, 4.0};
	vector<float> y = {6.0, 7.0, 8.0};
	vector<vector<float>> v = {x, y};
	matrix<float> m = v;
	cout << "test4 success\n";
	return;
}

void test5()
{
	vector<float> x = { 2.0, 3.0, 4.0 };
	vector<float> y = { 6.0, 7.0, 8.0 };
	vector<vector<float>> v1 = { x, y };
	matrix<float> A = v1;
	vector<float> x2 = { 2.0, 3.0, 4.0 };
	vector<float> y2 = { 6.0, 7.0, 8.0 };
	vector<vector<float>> v2 = { x2, y2 };
	matrix<float> B = v2;
	matrix<float> r = A + B;
	cout << r << "\n";
	cout << "test5 success\n";
	return;
}

void test6()
{
	vector<float> x = { 2.0, 3.0, 4.0 };
	vector<float> y = { 6.0, 7.0, 8.0 };
	vector<vector<float>> v1 = { x, y };
	matrix<float> A = v1;
	vector<float> x2 = { 1.0, 2.0, 3.0 };
	vector<float> y2 = { 5.0, 6.0, 7.0 };
	vector<vector<float>> v2 = { x2, y2 };
	matrix<float> B = v2;
	matrix<float> r = A - B;
	cout << r << "\n";
	cout << "test6 success\n";
	return;
}

void test7()
{
	vector<float> x = { 2.0, 3.0, 4.0 };
	vector<float> y = { 6.0, 7.0, 8.0 };
	vector<vector<float>> v = { x, y };
	matrix<float> m = v;
	float f = 2.0;
	matrix<float> r = m * f;
	cout << r << "\n";
	cout << "test7 success\n";
	return;
}

void test8()
{
	vector<float> x = { 2.0, 3.0, 4.0 };
	vector<float> y = { 6.0, 7.0, 8.0 };
	vector<vector<float>> v1 = { x, y };
	matrix<float> A = v1;
	vector<float> x2 = { 1.0, 2.0, 3.0 };
	vector<float> y2 = { 5.0, 6.0, 7.0 };
	vector<vector<float>> v2 = { x2, y2 };
	matrix<float> B = v2;
	matrix<float> r = A * B;
	cout << r << "\n";
	cout << "test8 success\n";
	return;
}

int main(int argc, char *argv[])
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();

	return(0);
}
