import java.io.*;
class JavaGetStateExp implements Runnable{
	public void run(){
		Thread.State state = Thread.currentThread().getState();
		System.out.println("Running thread name : " + Thread.currentThread().getName());
		System.out.println("State of thread : " + state);
	}
}

class Problem1{
	public static void main(String args[]){
		JavaGetStateExp g = new JavaGetStateExp();
		Thread t1 = new Thread(g);
		Thread t2 = new Thread(g);
		t1.start();
		t2.start();
	}
}
