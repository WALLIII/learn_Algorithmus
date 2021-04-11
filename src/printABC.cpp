
#include <iostream>
#include <thread>
#include <condition_variable>
#include <vector>
#include <algorithm>

// std::mutex mtx;  ////实例化mutsx对象，不要理解为定义变量
// std::condition_variable cvar; //定义信号唤醒线程
// char g_ch = 0;
// /*用std::unique_lockstd::mutex 和cv.wait配合，wait把lock释放然后等待后面的条件，
// 当后面条件达成时锁重新得到继续执行以下代码，unique_lock ()允许中间释放锁*/
// void print_fun(char ch)
// {
//     int cyle_cnt = 10;
//     char ch_ = ch - 'A';

//     for (int i = 0; i < cyle_cnt; i++)
//     {
//         std::unique_lock<std::mutex> ulk(mtx);
//         cvar.wait(ulk, [ch_] { return ch_ == g_ch; });
//         std::cout << (char)(ch_ + 'A');
//         g_ch = (ch_ + 1) % 3;
//         ulk.unlock();

//         cvar.notify_all(); //来唤醒所有线程
//     }
// }

// int main()
// {
//     std::vector<std::thread> threads;
//     threads.push_back(std::thread(print_fun, 'A'));
//     threads.push_back(std::thread(print_fun, 'B'));
//     threads.push_back(std::thread(print_fun, 'C'));

//     std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));

//     std::cout << std::endl;

//     return 0;
// }



std::mutex data_mutex;
std::condition_variable data_var;
bool flag = true;
 
void printA()
{
    for(int i=0;i<10;++i)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::unique_lock<std::mutex> lck(data_mutex) ;
        data_var.wait(lck,[]{return flag;});
        // std::cout<<"thread: "<< std::this_thread::get_id() << "   printf: " << "A" <<std::endl;
        std::cout<<'A';
        flag = false;
        data_var.notify_all();
    }
}
 
void printB()
{
    for(int i=0;i<10;++i)
    {
        std::unique_lock<std::mutex> lck(data_mutex) ;
        data_var.wait(lck,[]{return !flag;});
        // std::cout<<"thread: "<< std::this_thread::get_id() << "   printf: " << "B" <<std::endl;
        std::cout<<'B';
        flag = true;
        data_var.notify_all();
    }
}
 
// int main()
// {
//     std::thread tA(printA);
//     std::thread tB(printB);
//     tA.join();
//     tB.join();
//     return 0;
// }