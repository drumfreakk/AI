#include <iostream>
#include "libs/Matrix.h"

#define TWO


bool testDot(){
//	Matrix a;
//	a.init({{1, 2, 3},
//			{4, 5, 6}});
//	Matrix b;
//	b.init({{7, 8},
//			{9, 10},
//			{11, 12}});
//	Matrix dt;
//	dt = dot(a, b);
//	Matrix c;
//	c.init({{58, 64},
//			{139, 154}});

	Matrix a;
	a.init({{3, 4, 2}});
	Matrix b;
	b.init({{13, 9, 7, 15},
			{8, 7, 4, 6},
			{6, 4, 0, 3}});
	Matrix c;
	c.init({{83, 63, 37, 75}});
	Matrix dt;
	dt = dot(a, b);

	if(dt.getHeight() == c.getHeight() && dt.getWidth() == c.getWidth()){
		for(int z = 0; z < dt.getWidth() * dt.getHeight(); z++){
			if(dt[z] != c[z]){
				std::cout << "doesnt work...";
				return false;
			}
		}
	}
	std::cout << "Works!";
	return true;
}

bool testStar(){
	Matrix a;
	a.init({{1, 0, 2},
			{2, 1, 0},
			{1, 2, 2}});
	Matrix b;
	b.init({{0, 1, 1},
			{2, 1, 2},
			{2, 0, 1}});
	Matrix c;
	c.init({{0, 0, 2},
			{4, 1, 0},
			{2, 0, 2}});

	Matrix dt;
	dt = a * b;

	if(dt.getHeight() == c.getHeight() && dt.getWidth() == dt.getWidth()){
		for(int z = 0; z < dt.getWidth() * dt.getHeight(); z++){
			if(dt[z] != c[z]){
				std::cout << "doesnt work...";
				return false;
			}
		}
	}
	std::cout << "Works!";
	return true;
}


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

	Matrix syn0;

#ifdef ONE
	syn0.init({{randFloat()},
			   {randFloat()},
			   {randFloat()}});
	trainOut.init({{0},
				   {0},
				   {1},
				   {1}});
#endif

	Matrix l1(trainSamples, 1);
	Matrix l0 = trainInp;

	Matrix l1_error(trainSamples, 1);
	Matrix l1_delta(trainSamples, 1);

#ifdef TWO
//	syn0.init({{randFloat(), randFloat(), randFloat(), randFloat()},
//			   {randFloat(), randFloat(), randFloat(), randFloat()},
//			   {randFloat(), randFloat(), randFloat(), randFloat()}});

	syn0.init({{-0.16595599, 0.44064899, -0.99977125, -0.39533485},
			   {-0.70648822, -0.81532281, -0.62747958, -0.30887855},
			   {-0.20646505, 0.07763347, -0.16161097, 0.370439}});

	trainOut.init({{0},
				   {1},
				   {1},
				   {0}});

	Matrix syn1;
//	syn1.init({{randFloat()},
//			   {randFloat()},
//			   {randFloat()},
//			   {randFloat()}});
	syn1.init({{-0.5910955},
			   {0.75623487},
			   {-0.94522481},
			   {0.34093502}});

	Matrix l2;
	Matrix l2_error;
	Matrix l2_delta;

#endif

	Matrix tmp;

	for (int i = 0; i < 1; i++) {
		l1 = sigmoid(dot(l0, syn0));


#ifdef TWO
		l2 = sigmoid(dot(l1, syn1));

		l2_error = trainOut - l2;

//		if(i % 10000){
//			std::cout << mean(abs(l2_error)) <<'\n';
//		}

		l2_delta = l2_error * derivative(l2);

		//TODO it changes here, see python file nn.py
		l1_error = dot(l2_delta, syn1.transpose());
		std::cout << l1_error;
#endif

#ifdef ONE
		l1_error = trainOut - l1;
#endif

		l1_delta = l1_error * derivative(l1);

		syn0 = syn0 + dot(l0.transpose(), l1_delta);
//		tmp = dot(l0.transpose(), l1_delta);
//		std::cout << tmp;
#ifdef TWO
		syn1 = syn1 + dot(l1.transpose(), l2_delta);
#endif

	}

//	std::cout << l2;


	return 0;
}