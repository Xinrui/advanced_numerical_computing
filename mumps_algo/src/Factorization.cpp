#include "Factorization.h"

#include <iostream>

void FACTO(int j, Eigen::MatrixXd& A)
{
	assert(A.rows() == A.cols());

	int n = A.rows() - 1;
	
	// Aj(j + 1 : n) ← Aj(j + 1 : n)/ajj;
	A.col(j).middleRows(j + 1, n - j) /= A(j, j);
}

void UPDATE(int i, int j, Eigen::MatrixXd& A)
{
	assert(A.rows() == A.cols());

	int n = A.rows() - 1;

	// Aj(i + 1 : n) ← Aj(i + 1 : n) − aij.Ai(i + 1 : n)
	A.col(j).middleRows(i + 1, n - i) -= A(i, j) * A.col(i).middleRows(i + 1, n - i);
}

void dense_right_looking(Eigen::MatrixXd& A)
{
	assert(A.rows() == A.cols());

	int n = A.rows();

	for (int i = 0; i < n; ++i) {
		FACTO(i, A);

		for (int j = i + 1; j < n; ++j) {
			UPDATE(i, j, A);
		}
	}
}
