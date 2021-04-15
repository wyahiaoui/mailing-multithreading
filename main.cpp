#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <functional>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <thread>

#include <chrono>
#include <thread_pool.hpp>
#include <list_creator.hpp>
#include <utils.hpp>
#include <menu.hpp>

// #define DEBUG

using namespace std;
using namespace std::chrono;



void send_mail(string mail_addr, string content) 
{
    std::this_thread::sleep_for(std::chrono::milliseconds(delay_time));
#ifdef DEBUG 
    std::unique_lock<mutex> locker(mtx);
    cout << "sent " << content << " to " << mail_addr  << endl;
    locker.unlock();
#endif
}


void submain() {
    vector<string> mail_list = list_of_mails(entries_count);
    cout << "A list of " << entries_count << " emails is randomly created\n";
    ThreadPool pool;
    cout << "Pool Threads is Ready.\nThreads are being executed ...\n";
    int i = 0;
    for (; i < entries_count; i++) {
        pool.enqueue(std::bind(send_mail, mail_list[i], "Hello"));
    }
    cout << "Waiting for mails sending to finish ..." << endl;
    pool.wait_finished();
    cout << "Mails sending is finished with success" << endl;
}



int main () 
{
    cout << PROGRAM_DETAILS << endl;
    menu(submain);

    return 0;
}
 