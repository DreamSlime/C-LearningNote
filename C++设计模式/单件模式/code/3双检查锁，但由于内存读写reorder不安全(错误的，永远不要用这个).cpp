class Singleton {
   private:
    Singleton();
    Singleton(const Singleton& other);

   public:
    static Singleton* getInstance();
    static Singleton* m_instance;
}

Singleton* Singleton::getInstance3() {
    if (m_instance == nullptr) {
        Lock lock;
        if (m_instance == nullptr) {
            m_instance = new Singleton();
        }
    }
    return m_instance;
}

reorder通常认为指定序列会按我们假设的顺序进行
m_instance = new Singleton();
假象顺序：
1.先分配内存
2.调用构造器
3.将内存地址给m_instance
但是在汇编中可能132步骤进行
则在第二步(3)就不是nullptr了，这时如果有个新的线程进来，则直接返回对象
这里返回的对象只是分配了一个内存，可能还没调用构造,所以会返回一个错误的对象