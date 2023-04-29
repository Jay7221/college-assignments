import java.io.*;
class Customer{
	int amount = 10000;
	synchronized void withdraw(int amount){
		System.out.println("Processing withdraw...");

		if(this.amount < amount){
			System.out.println("Insufficient balance... Waiting for deposit...");
			try{
				wait();
			}catch(Exception e){
				System.out.println(e);
			}
		}
		this.amount -= amount;
		System.out.println("Withdraw completed...");
	}
	synchronized void deposit(int amount){
		System.out.println("Processing deposit...");
		this.amount += amount;
		System.out.println("Deposit completed...");
		notify();
	}
}
class Problem3{
	public static void main(String args[]){
		final Customer c = new Customer();
		new Thread(){
			public void run(){
				c.withdraw(15000);
			}
		}.start();
		new Thread(){
			public void run(){
				c.deposit(10000);
			}
		}.start(); 
	}
}
