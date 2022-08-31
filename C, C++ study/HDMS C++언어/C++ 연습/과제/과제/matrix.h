#pragma once
#include <iostream>
using namespace std;

class matrix
{
	int rows;
	int cols;
	int **mat;
public:
	matrix(int, int);
	~matrix();
	void input_matrix();
	void print();
	int get_rows();
	int get_cols();
	int get(int i, int j);
	void set(int i, int j, int x);
	void resize(int rows, int cols);
};

