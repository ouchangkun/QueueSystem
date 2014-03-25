#include "QueueSystemSimulation.h"
#include <cstdlib>
#include "Random.h"
#include <iostream>

int main()
{
    int total_service_time;
    int window_num;
    std::cout << "请输入营业的总时长(分钟):";
    std::cin >> total_service_time;
    std::cout << "请输入提供办理业务的窗口数目(至少一个):";
    std::cin >> window_num;

    srand((unsigned)time_t(NULL));
    double sum = 0;
    for (int i = 0; i < 100; i++)
    {
        sum += QueueSystemSimulation(total_service_time, window_num);
    }
    std::cout << sum / 100 << std::endl;
    system("pause");
    return 0;
}
