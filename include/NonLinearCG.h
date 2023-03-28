/////////////////////////////////////////////////
///
///  \class NonLinearCG
///
///  \brief General implementation of Non Linear Conjugate Gradient.
///
///  \author    Wakim B. Saba
[[ http://lattes.cnpq.br/6231635928638396 | Lattes Page ]]
<a href="https://br.linkedin.com/in/wakim-saba-9940445">(linkedin)</a>
[Conjugate gradient method](<https://en.wikipedia.org/wiki/Conjugate_gradient_method> "Wikipedia:Conjugate gradient method")

///
///  \version   1.0.0.0
///
///  \date      2023
///
///  \copyright (Apache License).
///
/////////////////////////////////////////////////

#ifndef NONLINEARCG_H
#define NONLINEARCG_H

#include <iostream>
#include <vector>
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

    private:

		void grad(vector<double> &x, vector<double> &_grad_f);

		double (*f)(vector<double>&);

		void printVector(vector<double> &xpto, string name);
};

#endif // NONLINEARCG_H

