import java.io.*;
class Multi implements Runnable{
	public void run(){
		System.out.println("Thread is running...");
	}
}
class Problem2{
	public static void main(String args[]){
		Multi m = new Multi();
		Thread t1 = new Thread(m);
		Thread t2 = new Thread();
		System.out.println("Start thread : " + t1.getName());
		t1.start();
		System.out.println("Start thread : " + t2.getName());
		t2.start();
	}
}
