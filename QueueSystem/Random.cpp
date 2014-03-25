#include <iostream>
#include <cmath>

// 生成[0,1)之间的一个随机值
double uniform()
{
    
    return (double)rand() / (RAND_MAX + 1);
}
// 返回服从泊松分布的随机变量的一个随机值
double getPoisson(double lambda)
{
    int t = 0;
    double p = exp(-lambda);
    double f = p;
    double u = uniform();
    while (true)
    {
        if (f > u)
            break;
        t++;
        p = p*lambda / t;
        f += p;
    }
    return t;
}
// 返回服从负指数分布的随机变量的一个随机值
double getExponentail(double lambda)
{
    return -log(1 - uniform()) / lambda;
}