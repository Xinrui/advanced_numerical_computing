#include <Doolittle.h>
#include <gtest/gtest.h>

TEST(DOOLITTLE, 01) {
	Eigen::MatrixXd A {

		{1, 2, 3, 4},
		{1, 4, 9, 16},
		{1, 8, 27, 64},
		{1, 16, 81, 256}
	};

	Doolittle(A);

	Eigen::MatrixXd Aref{
		{1,2,3,4},
		{1,2,6,12},
		{1,3,6,24},
		{1,7,6,24},
	};

	ASSERT_EQ(A, Aref);
}