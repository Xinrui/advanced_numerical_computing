#include <stdio.h>

void print_matrix(double A[4][4]);
void print_vector(double b[4]);
void print_linear_system(double A[4][4], double b[4]);

int main() {
	
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

	for (int i = 0; i < 4; ++i)
	{
		for (int j = i + 1; j < 4; ++j)
		{
			double m = -A[j][i] / A[i][i];

			for (int k = 0; k < 4; ++k) {
				A[j][k] += A[i][k] * m;
			}
			b[j] += b[i] * m;

			print_linear_system(A, b);
			printf("\n");

			int foo = 1;
		}
	}

	return;
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