#include "NonLinearCG.h"

NonLinearCG::NonLinearCG(double _error, double _step, double _deltaX, vector<double>&_X, double (*_f)(vector<double>&), bool _printIteration)
{
    printIteration = _printIteration;
    error = _error;
    step = _step;
    deltaX = _deltaX;
    x = &_X;
    f = _f;
}

void NonLinearCG::grad(vector<double> &x, vector<double> &_grad_f)
{
    double lastXi = 0.0;
    for(int i=0;i<x.size();i++)
    {
        if(i>0)
            x[i-1] = lastXi;

        double __f = f(x);

        lastXi = x[i];

        x[i] += deltaX;

        double __fd = f(x);

        _grad_f[i] = ( __fd - __f ) / deltaX;
    }
}

void NonLinearCG::execute()
{
    vector<double> grad_f(x->size(), 0.0);

    grad((*x), grad_f);
    printVector(grad_f, string("grad_start"));

    if(printIteration)
    {
        cout<< "-------------------------------------------"<< endl;
        cout<< "k["<<0<<"] --------> f(x): " << f(*x) << endl;
        cout<< "-------------------------------------------"<< endl;
    }
    vector<double> p(x->size(), 0.0);
    for(int i=0;i<(*x).size();i++)
        p[i] = -1.0 * grad_f[i];

    int k = 0;
    if(printIteration)
    {
        cout<< "-------------------------------------------"<< endl;
        cout<< "[k] " << "f(x)" <<"\t"<< "error" <<"\t"<< endl;
        cout<< "-------------------------------------------"<< endl;
    }

    double sum_error =0.0;
    do
    {
        double alpha = step;

        for(int i=0;i<(*x).size();i++)
            (*x)[i] = (*x)[i] + alpha * p[i];

        double a =0.0, b=0.0, beta;

        for(int i=0;i<(*x).size();i++)
            b += (grad_f[i] * grad_f[i]);

        grad(*x, grad_f);
        for(int i=0;i<(*x).size();i++)
            a += (grad_f[i] * grad_f[i]);

        beta = a/b;

        for(int i=0;i<(*x).size();i++)
            p[i] = -1 * grad_f[i]  + beta * p[i];

        k++;

        sum_error =0.0;
        for(int i=0;i<grad_f.size();i++)
            sum_error += sqrt(grad_f[i] * grad_f[i]);

        if(printIteration)
            cout<< "["<<k<<"] " << f(*x) <<"\t"<< sum_error <<"\t"<< endl;
    }
    while ( sum_error > error );
}

void NonLinearCG::printVector(vector<double> &xpto, string name)
{
    for(int i=0;i<xpto.size();i++)
        cout<< name<<"["<<i<<"]: "<< xpto[i] << endl;
}
