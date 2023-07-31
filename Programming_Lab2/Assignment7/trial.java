import java.io.*;
class trial{
	static int cnt = 0;
	public static class Mt implements Runnable{
		public void run(){
			for(int i = 0; i < 100000; ++i){
				++cnt;
			}
		}
	}
	public static void main(String args[]){
		Mt mt = new Mt();
		Thread t1 = new Thread(mt);
		Thread t2 = new Thread(mt);
		t1.start();
		t2.start();

		System.out.println(cnt);
	}
}
