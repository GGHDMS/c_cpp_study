// 20180403 Çã¼®¹®
#include "matrix.h"


matrix::matrix(int rows, int cols) {
	this->rows = rows;
	this->cols = cols;
	mat = new int*[rows];
	for (int i = 0; i < rows; i++) {
		mat[i] = new int[cols];
		for (int j = 0; j < cols; j++) {
			mat[i][j] = 0;
		}
	}
}
matrix::~matrix() {
	for (int i=0; i < rows; i++) {
		delete[]mat[i];
	}
	delete[]mat;
}
void matrix::input_matrix() {
	cout << "row : " << rows << ", cols : " << cols << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << "(" << i + 1 << ", " << j + 1 << ") : ";
			cin >> mat[i][j];
		}
	}
}
void matrix::print() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << mat[i][j] << "\t";
		}
		cout << endl;
	}
}
int matrix::get_rows() { return rows; }
int matrix::get_cols() { return cols; }
int matrix::get(int i, int j) { return mat[i - 1][j - 1]; }
void matrix::set(int i, int j, int x) {
	mat[i - 1][j - 1] = x;
}
void matrix::resize(int rows, int cols) {
	for (int i=0; i < this->rows; i++) {
		delete[]mat[i];
	}
	delete[]mat;
	this->rows = rows;
	this->cols = cols;
	mat = new int*[rows];
	for (int i = 0; i < rows; i++) {
		mat[i] = new int[cols];
		for (int j = 0; j < cols; j++) {
			mat[i][j] = 0;
		}
	}
}