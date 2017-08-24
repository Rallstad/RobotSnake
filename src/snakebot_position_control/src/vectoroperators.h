#include <vector>
#include <iostream>

std::vector<double> operator+(const std::vector<double>& lhs, const std::vector<double>& rhs);

std::vector<double> operator-(const std::vector<double>& lhs, const std::vector<double>& rhs);

std::vector<double> operator/(const std::vector<double>& lhs, const double& rhs);

std::vector<double> operator*(const double& lhs, const std::vector<double>& rhs);

std::vector<double> elementWiseMult(const std::vector<double>& lhs, const std::vector<double>& rhs);

