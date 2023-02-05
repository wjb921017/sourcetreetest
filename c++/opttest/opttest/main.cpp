
#include<stdio.h>
#include<iostream>

#define _accuracy 0.0001

//f()

float f(float x1, float x2) {

	return x1 * x1 + x2 * x2;

}

//F()

float F(float x1, float x2, int M) {

	float sum;

	sum = (x1 + x2 - 1 >= 0) ? (x1*x1 + x2 * x2) : (x1*x1 + x2 * x2 + M * (x1 + x2 - 1)*(x1 + x2 - 1));

	return sum;

}

//grad()

void grad(float x[2], float g[2], int m) {

	if (x[0] + x[1] - 1 >= 0) {

		g[0] = 2 * x[0];

		g[1] = 2 * x[1];

	}

	else {

		g[0] = 2 * x[0] + m * 2 * (x[0] + x[1] - 1);

		g[1] = 2 * x[1] + m * 2 * (x[0] + x[1] - 1);

	}

}

//

void plusx(float x1[2], float x0[2], float g[2], float t) {

	x1[0] = x0[0] + t * g[0];

	x1[1] = x0[1] + t * g[1];

}

//gold()

void gold(float &a, float &b, float x[2], float g[2], int M) {

	float t1, t2;

	float x1[2], x2[2];

	t2 = a + (float)0.382*(b - a);

	plusx(x2, x, g, t2);

	t1 = a + b - t2;

	plusx(x1, x, g, t1);

	float f1, f2;

	f1 = F(x1[0], x1[1], M);

	f2 = F(x2[0], x2[1], M);

	if (f1>f2) b = t1;

	else { a = t2; b = t1; }

}

//

void linesearch(float Xk1[2], float Xk0[2], float g[2], int M) {

	float mina, maxb, Lanbuda;

	/*searchRange(mina,maxb,Xk0,g);*/

	mina = -100;

	maxb = 100;

	while (maxb - mina > _accuracy)

	{

		gold(mina, maxb, Xk0, g, M);

	}

	Lanbuda = (mina + maxb) / 2;

	plusx(Xk1, Xk0, g, Lanbuda);

}

void find_min(float x[2], int M) {

	int k = 0;

	float x1[2] = { x[0],x[1] };

	float g[2];

	float f0, f1;

	f0 = F(x[0], x[1], M);

	grad(x, g, M);

	while (1)

	{

		if (0.01 > g[0] * g[0] + g[1] * g[1]) break;

		if (++k > 1000) break;

		//if (g[0]*g[0]+g[1]*g[1]==0) break;

		linesearch(x1, x, g, M);

		f1 = F(x1[0], x[1], M);

		grad(x1, g, M);

		x[0] = x1[0];

		x[1] = x1[1];

		f0 = f1;

	}

	printf("M=%d:\tX=[%.3f,%.3f]\t", M, x[0], x[1]);

	printf("minf(X)=%.3f\n", f1);

}

int main(int argc, char* argv[])

{

	float x[2] = { -10,-10 };

	const int C = 10;

	int M = 1;

	float threshold = M * (x[0] + x[1] - 1)*(x[0] + x[1] - 1);

	while (threshold > _accuracy)

	{

		find_min(x, M);

		M *= C;

		threshold = M * (x[0] + x[1] - 1)*(x[0] + x[1] - 1);

	}

	printf("root:\tX=[%.3f,%.3f]\t", x[0], x[1]);

	printf("minf(X)=%.3f\n", f(x[0], x[1]));

	return std::cin.get();
}