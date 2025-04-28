#include <gtest/gtest.h>

#include <Eigen/Dense>

#include <stdio.h>

void print_linear_system(const Eigen::MatrixXd& A, const Eigen::VectorXd& b);

TEST(Chapter02, Exercise01) {
	Eigen::Matrix4d A{
		{16,-12,2,4},
		{12, -8, 6,10},
		{3,-13,9,23},
		{-6,14,1,-28}
	};

	Eigen::Vector4d b{
		17,36,-49,-54
	};

	print_linear_system(A, b);
	printf("\n");

	// forward elimination
	for (int i = 0; i < 4; ++i)
	{
		for (int j = i + 1; j < 4; ++j)
		{
			double m = -A(j, i) / A(i, i);

			for (int k = i; k < 4; ++k) {
				A(j, k) += A(i, k) * m;
			}
			b[j] += b[i] * m;

			print_linear_system(A, b);
			printf("\n");
		}
	}

	// backward substitution
	double x[4];

	x[3] = b[3] / A(3, 3);

	for (int i = 2; i >= 0; --i) {
		double sum = 0.0;
		for (int k = i + 1; k < 4; ++k)
		{
			sum += A(i, k) * x[k];
		}

		x[i] = (b[i] - sum) / A(i, i);
	}

	Eigen::Vector4d x_ref = A.partialPivLu().solve(b);
	for (int i = 0; i < 4; ++i) {
		EXPECT_DOUBLE_EQ(x[i], x_ref[i]);
	}
}


void print_linear_system(const Eigen::MatrixXd& A, const Eigen::VectorXd& b) {
	using namespace Eigen;

	MatrixXd augmentedMatrix(A.rows(), A.cols() + b.cols());
	augmentedMatrix << A, b;  // 横向拼接A和B

	// 设置输出格式，控制精度和对齐
	IOFormat clean(4, 0, ", ", "\n", "[", "]");

	// 打印增广矩阵
	std::cout << augmentedMatrix.format(clean) << '\n';
}