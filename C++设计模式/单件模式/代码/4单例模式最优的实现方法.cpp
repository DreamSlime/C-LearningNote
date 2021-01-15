#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

class SingletonCPP {
   private:
    SingletonCPP();
    SingletonCPP(const SingletonCPP& other);

   public:
    static SingletonCPP* getInstance();
    static std::atomic<SingletonCPP*> m_instance;
    static std::mutex m_mutex;
};

SingletonCPP* SingletonCPP::getInstance() {
    SingletonCPP* tmp = m_instance.load(std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire);  //获取内存fence
    if (tmp == nullptr) {
        std::lock_guard<std::mutex> lock(m_mutex);
        tmp = m_instance.load(std::memory_order_relaxed);
        if (tmp == nullptr) {
            tmp = new SingletonCPP;
            std::atomic_thread_fence(
                std::memory_order_release);  //释放内存fence
            m_instance.store(tmp, std::memory_order_relaxed);
        }
    }
    return tmp;
}

int main() {
    SingletonCPP* instance = SingletonCPP::getInstance();
    return 0;
}