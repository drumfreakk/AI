#include <iostream>
#include "libs/Matrix.h"

#define ONE

inline float randFloat() {
	return ((float) rand()) / (float) RAND_MAX * 1.f;
}

int main() {
	const int trainSamples = 4;

	Matrix trainInp;
	trainInp.init({{0, 0, 1},
			       {0, 1, 1},
			       {1, 0, 1},
			       {1, 1, 1}});

	Matrix trainOut;
	trainOut.init({{0},
				   {0},
				   {1},
				   {1}});

	Matrix syn0;
#ifdef ONE
	syn0.init({{randFloat()},
			   {randFloat()},
			   {randFloat()}});
#endif
#ifdef TWO
	syn0.init({{randFloat()},
			   {randFloat()},
			   {randFloat()},
			   {randFloat()}});
#endif

	Matrix l1(trainSamples, 1);
	Matrix l0 = trainInp;

	Matrix l1_error(trainSamples, 1);
	Matrix l1_delta(trainSamples, 1);

#ifdef TWO
	Matrix syn1(4, 1);

	for(int z = 0; z < syn0.getHeight() * syn0.getWidth(); z++){
		syn1[z] = randFloat();
	}


	Matrix l2;
	Matrix l2_error;
	Matrix l2_delta;

	std::cout << syn0;
#endif

	for (int i = 0; i < 10000; i++) {
		l1 = sigmoid(dot(l0, syn0));


#ifdef TWO
		l2 = sigmoid(dot(l1, syn1));

		l2_error = trainOut - l2;

		l2_delta = l2_error * derivative(l2);

		l1_error = dot(l2_delta, syn1.transpose());
#endif

#ifdef ONE
		l1_error = trainOut - l1;
#endif

		l1_delta = l1_error * derivative(l1);

		syn0 = syn0 + dot(l0.transpose(), l1_delta);

#ifdef TWO
		syn1 = syn1 + dot(l1.transpose(), l2_delta);
#endif

	}

	std::cout << l1;

	return 0;
}