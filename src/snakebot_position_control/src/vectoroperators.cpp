#include "vectoroperators.h"

using std::cout;
using std::endl;

std::vector<double> operator+(const std::vector<double>& lhs, const std::vector<double>& rhs){
    if (lhs.size() != rhs.size()){
        cout << "Error: vector size mismatch for operator +" << endl;
        std::vector<double> emptyVector;
        return  emptyVector;
    }
    std::vector<double> resultVector(lhs.size());
    for (int i = 0 ; i < lhs.size() ; i++){
        resultVector[i] = lhs[i] + rhs[i];
    }
    return resultVector;
}

std::vector<double> operator-(const std::vector<double>& lhs, const std::vector<double>& rhs){
    if (lhs.size() != rhs.size()){

        cout << "Error: vector size mismatch for operator -" << endl;
        std::vector<double> emptyVector;
        return  emptyVector;
    }
    std::vector<double> resultVector(lhs.size());
    for (int i = 0 ; i < lhs.size() ; i++){
        resultVector[i] = lhs[i] - rhs[i];
    }
    return resultVector;
}

std::vector<double> operator/(const std::vector<double>& lhs, const double& rhs){
    std::vector<double> resultVector(lhs.size());
    for (int i = 0 ; i < lhs.size() ; i++){
        resultVector[i] = lhs[i]/rhs;
    }
    return resultVector;
}

std::vector<double> operator*(const double& lhs, const std::vector<double>& rhs){
    std::vector<double> resultVector(rhs.size());
    for (int i = 0 ; i < rhs.size() ; i++){
        resultVector[i] = lhs*rhs[i];
    }
    return resultVector;
}

std::vector<double> elementWiseMult(const std::vector<double>& lhs, const std::vector<double>& rhs){
    if (lhs.size() != rhs.size()){
        cout << "Error: vector size mismatch for element wise multiplication" << endl;
        std::vector<double> emptyVector;
        return  emptyVector;
    }
    std::vector<double> resultVector(lhs.size());
    for (int i = 0 ; i < lhs.size() ; i++){
        resultVector[i] = lhs[i] * rhs[i];
    }
    return resultVector;
}
