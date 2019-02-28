#ifndef AI_MATRIX_H
#define AI_MATRIX_H

#include <iostream>

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

	float& operator()(const int x, const int y);

	friend std::ostream& operator<<(std::ostream& out, Matrix& matrix);

};


#endif
