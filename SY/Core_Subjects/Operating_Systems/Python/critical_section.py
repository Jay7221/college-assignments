from threading import *

lock = Lock()

x = 0

def inr():
    for i in range(1000000):
        global x
        x += 1

if __name__ == '__main__':
    t1 = Thread(target = inr)
    t2 = Thread(target = inr)

    t1.start()
    t2.start()

    t1.join()
    t2.join()

    print(x)
