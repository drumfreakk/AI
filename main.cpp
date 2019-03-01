#include <iostream>
#include "libs/Matrix.h"

inline float randFloat() {
	return ((float) rand()) / (float) RAND_MAX * 1.f;
}

int main() {

	const int trainSamples = 4;

	Matrix trainInp(4, 3);

	trainInp(0, 0) = 0;
	trainInp(1, 0) = 0;
	trainInp(2, 0) = 1;

	trainInp(0, 1) = 0;
	trainInp(1, 1) = 1;
	trainInp(2, 1) = 1;

	trainInp(0, 2) = 1;
	trainInp(1, 2) = 0;
	trainInp(2, 2) = 1;

	trainInp(0, 3) = 1;
	trainInp(1, 3) = 1;
	trainInp(2, 3) = 1;

	Matrix trainOut(4, 1);

	trainOut(0, 0) = 0;
	trainOut(1, 0) = 0;
	trainOut(2, 0) = 1;
	trainOut(3, 0) = 1;

	Matrix l1(trainSamples, 1);
	Matrix l0 = trainInp;

	Matrix l1_error(trainSamples, 1);
	Matrix l1_delta(trainSamples, 1);

	Matrix syn0(3, 1);

	syn0(0, 0) = randFloat();
	syn0(1, 0) = randFloat();
	syn0(2, 0) = randFloat();


	/*------------------------------------------------------------------------------------------*/


	for(int i = 0; i < 1000000; i++){
		l1 = sigmoid(dot(l0, syn0));

		l1_error = trainOut - l1;

		l1_delta = l1_error * derivative(l1);

		syn0 = syn0 + dot(l0.transpose(), l1_delta);

	}

	std::cout << l1;

	return 0;
}