#include <gtest/gtest.h>

#include <stdio.h>


void print_matrix(double A[4][4]);
void print_vector(double b[4]);
void print_linear_system(double A[4][4], double b[4]);

TEST(Chapter02, Exercise01) {
	double A[4][4] = {
		{16,-12,2,4},
		{12, -8, 6,10},
		{3,-13,9,23},
		{-6,14,1,-28}
	};

	double b[4] = {
		17,36,-49,-54
	};

	print_linear_system(A, b);
	printf("\n");

	// forward elimination
	for (int i = 0; i < 4; ++i)
	{
		for (int j = i + 1; j < 4; ++j)
		{
			double m = -A[j][i] / A[i][i];

			for (int k = i; k < 4; ++k) {
				A[j][k] += A[i][k] * m;
			}
			b[j] += b[i] * m;

			print_linear_system(A, b);
			printf("\n");
		}
	}

	// backward substitution
	double x[4];

	x[3] = b[3] / A[3][3];

	for (int i = 2; i >= 0; --i) {
		double sum = 0.0;
		for (int k = i + 1; k < 4; ++k)
		{
			sum += A[i][k] * x[k];
		}

		x[i] = (b[i] - sum) / A[i][i];
	}

	double x_ref[4] = { 9.0454,   11.4884,   -5.9747,	5.5211 };
	for (int i = 0; i < 4; ++i) {
		EXPECT_NEAR(x[i], x_ref[i], 1e-4);
	}
}


void print_matrix(double A[4][4])
{
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			printf("%f\t", A[i][j]);
		}
		printf("\n");
	}
}

void print_vector(double b[4]) {
	for (int i = 0; i < 4; ++i) {
		printf("%f\n", b[i]);
	}
}

void print_linear_system(double A[4][4], double b[4]) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			printf("%f\t", A[i][j]);
		}
		printf("%f\n", b[i]);
	}
}