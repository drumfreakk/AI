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
	trainOut(1, 0) = 1;
	trainOut(2, 0) = 1;
	trainOut(3, 0) = 0;

	Matrix syn0(3, 4);

	for(int z = 0; z < syn0.getHeight() * syn0.getWidth(); z++){
		syn0[z] = randFloat();
	}

	Matrix l1(trainSamples, 1);
	Matrix l0 = trainInp;

	Matrix l1_error(trainSamples, 1);
	Matrix l1_delta(trainSamples, 1);

	/*------------------------------------------- SECOND LAYER -------------------------------------------*/

	Matrix syn1(4, 1);

	for(int z = 0; z < syn0.getHeight() * syn0.getWidth(); z++){
		syn1[z] = randFloat();
	}


	Matrix l2;
	Matrix l2_error;
	Matrix l2_delta;

	std::cout << syn0;

	/*------------------------------------------- STANDARD -----------------------------------------------*/


	for(int i = 0; i < 100000; i++){
		l1 = sigmoid(dot(l0, syn0));

		/*------------------------------------------- SECOND LAYER -------------------------------------------*/
		l2 = sigmoid(dot(l1, syn1));

		l2_error = trainOut - l2;

		l2_delta = l2_error * derivative(l2);

		l1_error = dot(l2_delta, syn1.transpose());

		/*------------------------------------------- STANDARD -----------------------------------------------*/

		/* NOT SECOND LAYER: l1_error = trainOut - l1; */

		l1_delta = l1_error * derivative(l1);

		//TODO: + wrong size;
		std::cout << "\n\n\nsyn0 " << "\ndot " << dot(l0.transpose(), l1_delta);
		syn0 = syn0 + dot(l0.transpose(), l1_delta);
		/*------------------------------------------- SECOND LAYER -------------------------------------------*/
		syn1 = syn1 + dot(l1.transpose(), l2_delta);
		/*------------------------------------------- STANDARD -----------------------------------------------*/

	}

	std::cout << l2;

	return 0;
}