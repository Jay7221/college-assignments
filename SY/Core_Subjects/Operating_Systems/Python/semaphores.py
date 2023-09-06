from threading import *
import time

sem = Semaphore(3)

# Semaphore(1) -> in this case it behaves similar to lock -> Binary Semaphore


# Semaphore(>1) -> counting semaphore


# Semaphore(3) => At a time atmost 3 threads can access critical section
# Basically there are three instances of the resource

def task(name):
    sem.acquire()
    for i in range(5):
        print("{} working".format(name))
        time.sleep(1)
    sem.release()

if __name__ == '__main__':
    t1 = Thread(target=task, args=('Thread-1',))
    t2 = Thread(target=task, args=('Thread-2',))
    t3 = Thread(target=task, args=('Thread-3',))
    t4 = Thread(target=task, args=('Thread-4',))
    t5 = Thread(target=task, args=('Thread-5',))

    t1.start()
    t2.start()
    t3.start()
    t4.start()
    t5.start()

