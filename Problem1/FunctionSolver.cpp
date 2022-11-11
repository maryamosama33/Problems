#include <bits/stdc++.h>

using namespace std;

class Function
{
    virtual double evaluateAt(double x) = 0;
};

class SimpleFunction : public Function
{
    function<double(double)> fun;

public:
    SimpleFunction(function<double(double)> fun)
    {
        this->fun = fun;
    }
    double evaluateAt(double x)
    {
        return fun(x);
    }
};

class CompositeFunction : public Function
{
    function<double(double)> fun1;
    function<double(double)> fun2;
public:
    CompositeFunction(function<double(double)> fun1, function<double(double)> fun2)
    {
        this->fun1 = fun1;
        this->fun2 = fun2;
    }

    double evaluateAt(double x)
    {
        return fun1(fun2(x));
    }
};

class DerivativeFunction:public Function
{
    function<double(double)> fun;
    double deltaX;

public:
    DerivativeFunction(function<double(double)> fun, double deltaX)
    {
        this->fun = fun;
        this->deltaX = deltaX;
    }

    double evaluateAt(double x)
    {
        double res = (fun(x + deltaX) - fun(x - deltaX)) / (2 * deltaX);
        return res;
    }
};

double cube(double x)
{
    return x * x * x;
}

double square(double x)
{
    return x * x;
}

int main()
{
    SimpleFunction fun(cube);
    CompositeFunction fun2(cube, square);
    DerivativeFunction fun3(square, 1);
    cout << fun.evaluateAt(2) << '\n' << fun2.evaluateAt(2) << '\n' << fun3.evaluateAt(5);
}