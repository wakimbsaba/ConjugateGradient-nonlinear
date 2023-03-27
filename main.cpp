#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <string>
#include <cmath>
#include "NonLinearCG.h"

using namespace std;

double f(vector<double> &x)
{
    double r=0.0;
    //Sphere function
    for(int i=0;i<x.size();i++)
        r += (x[i] * x[i]);
    return r;
}

void printVector(vector<double> &xpto, string name)
{
    for(int i=0;i<xpto.size();i++)
        cout<< name<<"["<<i<<"]: "<< xpto[i] << endl;
}

int main()
{
    double _deltaX = 0.01;
    double _error = 0.001;
    double _step = 0.01;
    long N = 40;

    // 1 - RANDOM NUMBER INITIALIZATION
    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<double> distribution(-1000.0, +1000.0);

    // 2 - DEFINITION OF DECISION VARIABLE X VECTOR
    vector<double> x(N, 0.0);
    for(int i=0;i<N;i++)
        x[i] = distribution(generator);
    printVector(x, string("X_START"));
    cout<< "-------------------------------------------"<< endl;

    // 3 - DEFINITION OF THE OBJECT ASSOCIATED TO THE METHOD
    NonLinearCG nlCG(_error, _step, _deltaX, x, f, true);

    // 4 - EXECUTION OF THE METHOD
    cout<< "EXECUTING ..."<< endl;
    nlCG.execute();

    // 5 - SHOW THE SOLUTION FOUND
    cout<< "-------------------------------------------"<< endl;
    printVector(x, string("X_RESULT"));
    cout<< "min F(X*): "<< f(x) << endl;

    return 0;
}
