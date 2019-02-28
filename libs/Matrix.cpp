#include "Matrix.h"

Matrix::~Matrix(){
	delete[] m_matrix;
}

float& Matrix::operator()(const int x, const int y){
	return m_matrix[m_index(x, y)];
}

int Matrix::m_index(const int x, const int y){
	return (y * m_width) + x;
}

std::ostream& operator<<(std::ostream& out, Matrix& matrix){
	for(int y = 0; y < matrix.m_height; y++){
		for(int x = 0; x < matrix.m_width; x++){
			out << matrix(x, y) << '\t';
		}
		out << "\n\n";
	}
}