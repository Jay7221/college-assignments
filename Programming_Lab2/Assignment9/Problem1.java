import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.io.*;
import java.awt.event.*;

class Problem1{
	private JFrame mainFrame;
	private void prepareGUI(){
		mainFrame = new JFrame("Problem 1");
		mainFrame.setSize(400, 400);
		mainFrame.setLayout(new FlowLayout());


		mainFrame.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent windowEvent){
				System.exit(0);
			}
		});

		JMenuBar mb1 = new JMenuBar();
		JMenuBar mb2 = new JMenuBar();
		JMenuItem mi1 = new JMenuItem("Up");
		JMenuItem mi2 = new JMenuItem("Down");
		JMenuItem mi3 = new JMenuItem("Reset");

		mb1.add(mi1);
		mb1.add(mi2);
		mb2.add(mi3);

		mainFrame.add(mb1);
		mainFrame.add(mb2);

		mainFrame.setVisible(true);

	}
	public static void main(String args[]){
		Problem1 p = new Problem1();
		p.prepareGUI();
	}
}
