#include <iostream>
#include "libs/Matrix.h"

float randFloat() {
	float a = -1.f;
	float b = 1.f;
	float random = ((float) rand()) / (float) RAND_MAX;
	float diff = b - a;
	float r = random * diff;
	return a + r;
}

int main() {

	const int trainSamples = 4;

	Matrix trainInp(4, 3, "in");

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

	Matrix trainOut(4, 1, "out");

	trainOut(0, 0) = 0;
	trainOut(1, 0) = 0;
	trainOut(2, 0) = 1;
	trainOut(3, 0) = 1;

	Matrix l0(4, 3, "0");
	Matrix l1(trainSamples, 1, "1");

	Matrix l1_error(trainSamples, 1, "e");
	Matrix l1_delta(trainSamples, 1, "d");

	Matrix syn0(3, 1, "s");

	syn0(0, 0) = randFloat();//-0.16595599;//
	syn0(1, 0) = randFloat();//0.44064899;//
	syn0(2, 0) = randFloat();//-0.99977125;//


//	l0 = trainInp;

	/*------------------------------------------------------------------------------------------*/


	for(int i = 0; i < 1000; i++){
		l0 = trainInp;

		for(int z = 0; z < trainSamples; z++){
			l1(z, 0) = sigmoid(dot(l0, syn0)(z, 0));
//			l1_error(z, 0) = trainOut(z, 0) - l1(z, 0);
		}

		///Should work now
//		std::cout << "\n\nerror_before " << l1_error << "\ntrainout " << trainOut << "\nl1 " << l1;
		l1_error = trainOut - l1;
//		std::cout << "\nerror after " << l1_error;

		///Probably works
//		std::cout << "\n\ndelta before " << l1_delta << "\nerror " << l1_error;
		for(int z = 0; z < trainSamples; z++){
			l1_delta(z, 0) = l1_error(z, 0) * derivative(l1(z, 0));
//			std::cout << "\nderiv " << derivative(l1(z, 0));
		}
//		std::cout << "\ndelta after " << l1_delta;

		Matrix tr = l0.transpose();
		Matrix dt = dot(tr, l1_delta);

		/// Should work now
//		std::cout << "\n\ndotprod " << dt << "\nsyn " << syn0;
		syn0 = syn0 + dt;
		/*
//		for(int z = 0; z < trainSamples; z++){
////			std::cout << "\nbefore " << syn0[z];
//			syn0[z] += dt[z];
////			std::cout << "\nafter " << syn0[z] << "\n\n";
//		}
		 */
//		std::cout << "\nafter " << syn0;

	}
/*
	l0 = trainInp;
	for(int z = 0; z < trainSamples; z++){
		l1(z, 0) = sigmoid(dot(l0, syn0)(z, 0));
		l1_error(z, 0) = trainInp(z, 0) - l1(z, 0);
	}

//		l1_error = trainOut - l1;

	for(int z = 0; z < trainSamples; z++){
		l1_delta(z, 0) = l1_error(z, 0) * derivative(l1(z, 0));
	}

	Matrix tr = l0.transpose();
	Matrix dt = dot(tr, l1_delta);

	syn0.last = true;
	dt.last = true;

	syn0 = syn0 + dt;
//		for(int z = 0; z < trainSamples; z++){
//			syn0[z] = syn0[z] + dt[z];
//		}
//		std::cout << syn0;*/

//	Matrix x = syn0;
//	Matrix z(4, 5,"d");
//	z = syn0;
//
//	std::cout << syn0 << '\n' << x << '\n' << z;

	std::cout << l1;

	return 0;
}