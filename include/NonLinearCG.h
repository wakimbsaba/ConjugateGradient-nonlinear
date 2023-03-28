/////////////////////////////////////////////////
///
///  \class NonLinearCG
///
///  \brief General implementation of Non Linear Conjugate Gradient.
///
///  \author    Wakim B. Saba
///  <a href="http://lattes.cnpq.br/6231635928638396">(lattes), </a>
///  <a href="https://br.linkedin.com/in/wakim-saba-9940445">(linkedin)</a>
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

