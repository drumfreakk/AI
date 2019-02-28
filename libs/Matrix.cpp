#include "Matrix.h"

Matrix::~Matrix(){
	delete[] m_matrix;
}

float& Matrix::operator()(const int x, const int y){
	return m_matrix[m_index(x, y)];
}

float& Matrix::operator[](const int z){
	return m_matrix[z];
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

float sigmoid(float x){
	return 1/(1+std::exp(-x));
}

float derivative(float x){
	return x*(1-x);
}

int Matrix::getHeight(){
	return m_height;
}

int Matrix::getWidth(){
	return m_width;
}

Matrix operator-(Matrix &m1, Matrix &m2){
	if(m1.m_height != m2.m_height || m1.m_width != m2.m_width)
		std::cerr << "Invalid size!\n";

	Matrix out(m1.m_height, m1.m_width);

	for(int z = 0; z < m1.m_width * m1.m_height; z++){
		out[z] = m1[z] - m2[z];
	}

	return out;
}

Matrix operator+(Matrix &m1, Matrix &m2){
	if(m1.m_height != m2.m_height || m1.m_width != m2.m_width)
		std::cerr << "Invalid size!\n";

	Matrix out(m1.m_height, m1.m_width);

	for(int z = 0; z < m1.m_width * m1.m_height; z++){
		out[z] = m1[z] + m2[z];
	}

	return out;
}

Matrix operator*(Matrix &m1, Matrix &m2){
	if(m1.m_height != m2.m_height || m1.m_height != 1 || m2.m_height != 1)
		std::cerr << "Invalid size!\n";

	Matrix out(m1.m_height, 1);

	for(int z = 0; z < m1.m_height; z++) {
		out(0, z) = m1(0, z) * m2(0, z);
	}

	return out;
}

Matrix operator*(Matrix &m1, const int scalar){
	Matrix out(m1.m_height, 1);

	for(int z = 0; z < m1.m_height; z++) {
		out(0, z) = m1(0, z) * scalar;
	}

	return out;
}

Matrix operator*(const int scalar, Matrix &m1){
	return m1 * scalar;
}

Matrix dot(Matrix &m1, Matrix &m2){
	if(m1.m_width != m2.m_height)
		std::cerr << "Invalid size!\n";

	Matrix out(m1.m_height, m2.m_width);

	int rest = m1.m_width;

	for(int y = 0; y < out.m_height; y++){
		for(int x = 0; x < out.m_width; x++){
			for(int z = 0; z < rest; z++){
				out(x, y) += m1(x, z) * m2(y, x);
			}
		}
	}

	return out;
}