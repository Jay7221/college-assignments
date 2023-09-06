import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JTextField;
import javax.swing.JPanel;
import java.awt.*;
import java.awt.event.*;
import java.util.concurrent.Flow;
public class a extends JFrame implements ActionListener{
    final int EQUAL = 0;
    JButton equalTo, clear;
    JButton digit[];
    JPanel buttons;
    JTextField input1, operation, input2, output;
    JButton[] operations;
    String[] operation_symbols = {"+", "-", "/", "*"};
    String curOperation;
    final int HEIGHT = 100, WIDTH = 20;
    public a(){
        this.setSize(500, 500);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setTitle("Calculator");


        input1 = new JTextField();
        input1.setPreferredSize(new Dimension(HEIGHT, WIDTH));
        input1.addActionListener(this);
        this.add(input1, BorderLayout.NORTH);

        operation = new JTextField();
        operation.setPreferredSize(new Dimension(WIDTH, WIDTH));
        operation.addActionListener(this);
        this.add(operation, BorderLayout.NORTH);

        input2 = new JTextField();
        input2.setPreferredSize(new Dimension(HEIGHT, WIDTH));
        input2.addActionListener(this);
        this.add(input2, BorderLayout.NORTH);

        output = new JTextField();
        output.setPreferredSize(new Dimension(HEIGHT, WIDTH));
        output.addActionListener(this);
        this.add(output, BorderLayout.NORTH);

        buttons = new JPanel();
        buttons.setLayout(new GridLayout(4, 4));
        digit = new JButton[10];
        for(int i = 0; i < 10; ++i){
            digit[i] = new JButton(Integer.toString(i));
            digit[i].setFocusable(false);
            digit[i].addActionListener(this);
            buttons.add(digit[i]);
        }
        equalTo = new JButton("=");
        equalTo.setFocusable(false);
        equalTo.addActionListener(this);
        buttons.add(equalTo);

        operations = new JButton[4];
        for(int i = 0; i < 4; ++i){
            operations[i] = new JButton(operation_symbols[i]);
            operations[i].setFocusable(false);
            operations[i].addActionListener(this);
            this.add(operations[i]);
        }

        clear = new JButton("clear");
        clear.setFocusable(false);
        clear.addActionListener(this);
        buttons.add(clear);

        this.add(buttons, BorderLayout.CENTER);

        this.setLayout(new FlowLayout());
        this.setVisible(true);
    }
    @Override
    public void actionPerformed(ActionEvent e){
        for(int i = 0; i < 4; ++i){
            if(e.getSource() == operations[i]){
                curOperation = operation_symbols[i];
                operation.setText(curOperation);
                return;
            }
        }
        if(e.getSource() == equalTo){
            int num1 = Integer.parseInt(input1.getText());
            int num2 = Integer.parseInt(input2.getText());
            int ans = 0;
            curOperation = operation.getText();
            curOperation.strip();
            if(curOperation.equals("+")){
                ans = num1 + num2;
            }
            if(curOperation.equals("-")){
                ans = num1 - num2;
            }
            if(curOperation.equals("/")){
                ans = num1 / num2;
            }
            if(curOperation.equals("*")){
                ans = num1 * num2;
            }
            output.setText(Integer.toString(ans));
        }
        else if(e.getSource() == clear){
            input1.setText("");
            input2.setText("");
        }
        else{
            for(int i = 0; i < 10; ++i){
                if(e.getSource() == digit[i]){
                    if(input2.isBackgroundSet()){
                        input2.setText(input2.getText() + Integer.toString(i));
                    }else{
                        input1.setText(input1.getText() + Integer.toString(i));
                    }
                }
            }
        }
    }
    public static void main(String args[]){
        a calc = new a();
    }
}
