#include <semaphore.h>

#define EATING 1
#define THINKING 0

class DiningPhilosophers {
private:
    int state[5] = {THINKING, THINKING, THINKING, THINKING, THINKING};
    mutex m;
    pthread_barrier_t b;
public:
    DiningPhilosophers() {
        pthread_barrier_init(&b, 0, 5);
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        while (1){
            m.lock();
            if (this->state[(philosopher + 4) % 5] != EATING && this->state[(philosopher + 1) % 5] != EATING){
                this->state[philosopher] = EATING;
                pickLeftFork();
                pickRightFork();
                m.unlock();
                break;
            }
            m.unlock();
            std::this_thread::yield();
        }
        eat();
        
        putLeftFork();
        putRightFork();
        this->state[philosopher] = THINKING;
        
        pthread_barrier_wait(&b);
		
    }
};
