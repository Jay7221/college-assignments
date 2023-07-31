import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class d extends JFrame {
    private JLabel usernameLabel;
    private JTextField usernameField;
    private JLabel passwordLabel;
    private JPasswordField passwordField;
    private JButton loginButton;

    private String[] validUsernames = {"user1", "user2", "user3"};
    private String[] validPasswords = {"password1", "password2", "password3"};

    public d() {
        setTitle("Login Application");
        setSize(300, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setLayout(new GridLayout(3, 2));

        usernameLabel = new JLabel("Username:");
        usernameField = new JTextField(20);

        passwordLabel = new JLabel("Password:");
        passwordField = new JPasswordField(20);

        loginButton = new JButton("Login");
        loginButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String username = usernameField.getText();
                String password = new String(passwordField.getPassword());

                if (isValidLogin(username, password)) {
                    JOptionPane.showMessageDialog(d.this, "Login Successful!");
                    displayUserInfo(username);
                } else {
                    JOptionPane.showMessageDialog(d.this, "Wrong username or password!");
                }

                // Clear the fields after login attempt
                usernameField.setText("");
                passwordField.setText("");
            }
        });

        add(usernameLabel);
        add(usernameField);
        add(passwordLabel);
        add(passwordField);
        add(new JLabel()); // Empty label for layout consistency
        add(loginButton);
    }

    private boolean isValidLogin(String username, String password) {
        for (int i = 0; i < validUsernames.length; i++) {
            if (username.equals(validUsernames[i]) && password.equals(validPasswords[i])) {
                return true;
            }
        }
        return false;
    }

    private void displayUserInfo(String username) {
        // Simulating user information display
        System.out.println("User: " + username);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            d loginApp = new d();
            loginApp.setVisible(true);
        });
    }
}
