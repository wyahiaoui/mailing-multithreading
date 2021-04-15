#include <condition_variable>
#include <functional>
#include <iostream>
// #include <future>
#include <vector>
#include <thread>
#include <queue>
 
class ThreadPool
{
public:
    using Task = std::function<void()>;
 
    explicit ThreadPool()
    {
        start(max_thread);
    }
 
    ~ThreadPool()
    {
        stop();
    }
    void enqueue(Task task);
    void wait_finished();
private:
    std::vector<std::thread> active_threads;
    std::condition_variable queue_event;
    std::condition_variable pool_finished;
    std::mutex queue_mutex;
    int max_thread = std::thread::hardware_concurrency();
    bool pool_stop = false;
    int busy = 0;
    std::queue<Task> tasks;
    void start(int used_thread);
    void stop() noexcept;
};
 


 
void ThreadPool::start(int used_thread)
{
    for (int i = 0; i < used_thread; ++i)
    {
        active_threads.emplace_back([=] {
            while (true)
            {
                Task task;

                {
                    std::unique_lock<std::mutex> lock{queue_mutex};

                    queue_event.wait(lock, [=] { return pool_stop || !tasks.empty(); });
                    
                    if (pool_stop && tasks.empty())
                        break;
                    ++busy;
                    task = std::move(tasks.front());
                    tasks.pop();
                }

                task();
                {
                    std::unique_lock<std::mutex> lock{queue_mutex};
                    --busy;
                }
                pool_finished.notify_one();
            }
        });
    }
}
void ThreadPool::stop() noexcept
{
    {
        std::unique_lock<std::mutex> lock{queue_mutex};
        pool_stop = true;
    }

    queue_event.notify_all();

    for (auto &thread : active_threads)
        thread.join();
}
void ThreadPool::enqueue(Task task)
{
    {
        std::unique_lock<std::mutex> lock{queue_mutex};
        tasks.emplace(std::move(task));
    }

    queue_event.notify_one();
}
void ThreadPool::wait_finished()
{
    std::unique_lock<std::mutex> lock(queue_mutex);
    pool_finished.wait(lock, [this](){ return tasks.empty() && (busy == 0); });
}