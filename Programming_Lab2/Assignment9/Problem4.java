import javax.swing.*;
import javax.swing.plaf.basic.DefaultMenuLayout;

import java.awt.*;

public class Problem4 extends JFrame {
    public Problem4() {
        setTitle("Layout Manager Example");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());
        for(int i = 1; i <= 9; ++i){
            JButton b = new JButton(Integer.toString(i));
            if(i % 7 == 0){
                add(b, BorderLayout.EAST);
            }
            if(i % 7 == 1){
                add(b, BorderLayout.WEST);
            }
            if(i % 7 == 2){
                add(b, BorderLayout.NORTH);
            }
            if(i % 7 == 3){
                add(b, BorderLayout.SOUTH);
            }
            if(i % 7 == 4){
                add(b, BorderLayout.CENTER);
            }
            if(i % 7 == 5){
                add(b, BorderLayout.AFTER_LAST_LINE);
            }
            if(i % 7 == 6){
                add(b, BorderLayout.AFTER_LINE_ENDS);
            }
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            Problem4 example = new Problem4();
            example.setVisible(true);
        });
    }
}
