#ifndef FACTORIZATION_H
#define FACTORIZATION_H

#include <Eigen/Dense>

void FACTO(int j, Eigen::MatrixXd& A);

void UPDATE(int i, int j, Eigen::MatrixXd& A);

// A formulation of Doolittle algorithm
void dense_right_looking(Eigen::MatrixXd& A);

#endif // !FACTORIZATION_H
