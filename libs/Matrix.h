#ifndef AI_MATRIX_H
#define AI_MATRIX_H

#include <iostream>
#include <cmath>

class Matrix {
private:
	int m_height;
	int m_width;

	float *m_matrix;

	int m_index(const int x, const int y);

	const char* name;

public:
	Matrix(const int height, const int width, const char* name)
		: m_height(height), m_width(width), name(name)
	{
		m_matrix = new float[m_width * m_height];

		for(int z = 0; z < m_height; z++){
			m_matrix[z] = 0;
		}
	}

	Matrix(){
		m_matrix = 0;
	}

	Matrix(const Matrix& source);
	Matrix& operator=(const Matrix& source);

	~Matrix();

	int getHeight();
	int getWidth();

	Matrix transpose();

	friend Matrix dot(Matrix &m1, Matrix &m2);

	float& operator()(const int x, const int y);

	float& operator[](const int z);

	friend Matrix operator-(Matrix &m1, Matrix &m2);
	friend Matrix operator+(Matrix &m1, Matrix &m2);
	friend Matrix operator*(Matrix &m1, Matrix &m2);

	friend std::ostream& operator<<(std::ostream& out, Matrix &matrix);

};

float sigmoid(float x);
float derivative(float x);

#endif
