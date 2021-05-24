#include <semaphore.h>
class H2O {
public:
    
    sem_t h;
    sem_t o;
    pthread_barrier_t barrier;
    
    H2O() {
        sem_init(&h, 0, 2);
        sem_init(&o, 0, 1);
        pthread_barrier_init(&barrier, 0, 3);
    }

    void hydrogen(function<void()> releaseHydrogen) {
        sem_wait(&h);
        pthread_barrier_wait(&barrier);
        releaseHydrogen();
        sem_post(&h);
    }

    void oxygen(function<void()> releaseOxygen) {
        sem_wait(&o);
        pthread_barrier_wait(&barrier);
        releaseOxygen();
        sem_post(&o);
    }
};
