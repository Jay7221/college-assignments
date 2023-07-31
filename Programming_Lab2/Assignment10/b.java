import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JTextField;
import javax.swing.JPanel;
import java.awt.*;
import java.awt.event.*;
import java.util.concurrent.Flow;
public class b extends JFrame implements ActionListener{
    final int EQUAL = 0;
    JButton equalTo, clear;
    JTextField input, output;
    final int HEIGHT = 300, WIDTH = 50;
    public b(){
        this.setSize(500, 500);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setTitle("Calculator");

        input = new JTextField();
        input.setPreferredSize(new Dimension(HEIGHT, WIDTH));
        input.addActionListener(this);
        this.add(input, BorderLayout.NORTH);
        input.setFont(new Font("Sans Serif", Font.PLAIN, 30));

        equalTo = new JButton("=");
        equalTo.setFocusable(false);
        equalTo.addActionListener(this);
        this.add(equalTo);

        output = new JTextField();
        output.setPreferredSize(new Dimension(HEIGHT, WIDTH));
        output.addActionListener(this);
        this.add(output, BorderLayout.NORTH);
        output.setFont(new Font("Sans Serif", Font.PLAIN, 30));


        this.setLayout(new FlowLayout());
        this.setVisible(true);
    }
    @Override
    public void actionPerformed(ActionEvent e){
        if(e.getSource() == equalTo){
            int num = Integer.parseInt(input.getText());
            long ans = 1;
            while(num > 1){
                ans *= num;
                --num;
            }
            output.setText(Long.toString(ans));
        }
    }
    public static void main(String args[]){
        b calc = new b();
    }
}
