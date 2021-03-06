//  
//  main.cpp
//  QueueSystem
//
//  Create by Euryugasaki on 2014-03-24.
//  Copyright (c) 2014 Euryugasaki. All rights reserved.
// 

#include "QueueSystemSimulation.h"
#include <cstdlib>
#include <iostream>

#define SIMULATION_NUM 100000    // 模拟次数

int main()
{
    int total_service_time;
    int window_num;
    std::cout << "Please input the total service time(min):";
    std::cin >> total_service_time;
    std::cout << "Please input the service window's number(at least one):";
    std::cin >> window_num;

    srand((unsigned)time_t(NULL));
    double sum = 0;
    for (int i = 0; i < SIMULATION_NUM; i++)
    {
        sum += QueueSystemSimulation(total_service_time, window_num);
    }
    std::cout << "The average customer stay in the bank's expectations:" << sum / SIMULATION_NUM << std::endl;
    system("pause");

    return 0;
}
