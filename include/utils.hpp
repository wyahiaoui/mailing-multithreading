#ifndef UTILS_HPP
#define UTILS_HPP

#include <mutex>
#include <condition_variable>

#define DEFAULT_MAX_ENTRIES 1000000
#define DEFAULT_DELAY_TIME 500

int entries_count = DEFAULT_MAX_ENTRIES;
int delay_time = DEFAULT_DELAY_TIME;

#define PROGRAM_DETAILS "This program is used to: \n\n"  \
"\t - Create a list of random mails with given entries counts\n" \
"\t - Read the list\n" \
"\t - Send message to addresses\n\n"

std::mutex mtx;
std::condition_variable cond;

#endif