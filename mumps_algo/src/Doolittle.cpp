#include "Doolittle.h"
#include <cassert>
#include <iostream>

void Doolittle(Eigen::MatrixXd& A)
{
	assert(A.rows() == A.cols());

	int n = A.cols();

	for (int p = 1; p < n; ++p) {
		
		// step 1
		// A(p+1: n, p) /= a_pp
		A.block(p, p - 1, n - p, 1) /= A(p - 1, p - 1);

		// step 2
		// A(p+1: n, p+1: n) -= A(p+1: n, p) * A(p, p+1:n)

		auto block1 = A.block(p, p - 1, n - p, 1);
		auto block2 = A.block(p - 1, p, 1, n - p);

		A.block(p, p, n - p, n - p) -= block1 * block2;
	}

	return;
}
