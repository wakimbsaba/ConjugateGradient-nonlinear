#ifndef NONLINEARCG_H
#define NONLINEARCG_H
#include<iostream>
#include<vector>
#include <cmath>

using namespace std;

class NonLinearCG
{
private:

    bool printIteration;

    double error;

    double step;

    double deltaX;

    vector<double>*x;

    public:

        NonLinearCG(double error, double step, double deltaX, vector<double>&X, double (*f)(vector<double>&), bool printIteration = false);

        void execute();

        virtual ~NonLinearCG(){};


    protected:

    private:

        void grad(vector<double> &x, vector<double> &_grad_f);

        double (*f)(vector<double>&);

        void printVector(vector<double> &xpto, string name);
};

#endif // NONLINEARCG_H

