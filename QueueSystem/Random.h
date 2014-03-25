#ifndef __RANDOM_H_
#define __RANDOM_H_

// 生成[0,1)之间的一个随机值
double uniform();
// 返回服从泊松分布的随机变量的一个随机值
double getPoisson(double lambda);
// 返回服从负指数分布的随机变量的一个随机值
double getExponentail(double lambda);

#endif