#include <iostream>
#include "libs/Matrix.h"

//
//int dotProd(int A[4][3], int B[2][3], int x, int y){
//	int dotProd = 0;
//	for(int i = 0; i < 3; i++){
//		dotProd += A[x][i] * B[i][y];
//	}
//	return dotProd;
//}
//
////int dotProd(int A[4][3], int B[2][3], int& ) {
////	int dotProd = 0;
////	for(int i = 0; i < 3; i++){
////		dotProd += A[x][i] * B[i][y];
////	}
////	return dotProd;
////}
//
//bool Multiply(float* out, const float* matA, int aRows, int aCols, const float* matB, int bRows, int bCols) {
//	if (aCols != bRows) {
//		return false;
//	}
//	for (int i = 0; i < aRows; ++i) {
//		for (int j = 0; j < bCols; ++j) {
//			out[bCols * i + j] = 0.0f;
//			for (int k = 0; k < bRows; ++k) {
//				int a = aCols * i + k;
//				int b = bCols * k + j;
//				out[bCols * i + j] += matA[a] * matB[b];
//			}
//		}
//	}
//	return true;
//}
//
//int sigmoid(int x, bool deriv = false){
//	if(deriv)
//		return x*(1-x);
//	return 1/(1+std::exp(-x));
//}
//
//float randFloat(){
//	return ((float) rand()) / (float) RAND_MAX;
//}

int main() {

	Matrix mat(3, 5);
	std::cout << mat;
//
//	int trainInp[4][3] = {{0, 0, 1},
//					      {0, 1, 1},
//	                      {1, 0, 1},
//	                      {1, 1, 1}};
//
//	int trainOut[4][1] = {{0},
//	                      {0},
//	                      {1},
//	                      {1}};
//
//	int l1;
//
//	float syn0[3][1] = {{randFloat()},
//	                    {randFloat()},
//	                    {randFloat()}};


	return 0;
}