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

public:
	Matrix(const int height, const int width)
		: m_height(height), m_width(width)
	{
		m_matrix = new float[m_width * m_height];

		for(int y = 0; y < m_height; y++){
			for(int x = 0; x < m_width; x++){
				m_matrix[m_index(x, y)] = 0;
			}
		}
	}

	~Matrix();

	int getHeight();
	int getWidth();

	friend Matrix dot(Matrix &m1, Matrix &m2);

	float& operator()(const int x, const int y);

	float& operator[](const int z);

	friend Matrix operator-(Matrix &m1, Matrix &m2);
	friend Matrix operator+(Matrix &m1, Matrix &m2);
	friend Matrix operator*(Matrix &m1, Matrix &m2);
	friend Matrix operator*(Matrix &m1, const int scalar);
	friend Matrix operator*(const int scalar, Matrix &m1);

	friend std::ostream& operator<<(std::ostream& out, Matrix& matrix);

};

float sigmoid(float x);
float derivative(float x);

#endif
