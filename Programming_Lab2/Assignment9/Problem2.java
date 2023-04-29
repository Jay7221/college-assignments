import java.util.ConcurrentModificationException;

import javax.swing.*;

public class Problem2 extends JFrame {
    private JLabel nameLabel;
    private JTextField nameField;
    private JLabel ageLabel;
    private JTextField ageField;
    private JLabel courseLabel;
    private JComboBox<String> courseComboBox;
    private JButton submitButton;

    public Problem2() {
        setTitle("Admission Form");
        setSize(300, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setLayout(new java.awt.FlowLayout());

        nameLabel = new JLabel("Name:");
        nameField = new JTextField(20);

        ageLabel = new JLabel("Age:");
        ageField = new JTextField(3);

        courseLabel = new JLabel("Course:");
        String[] courses = {"Engineering", "Medical", "Arts"};
        courseComboBox = new JComboBox<>(courses);

        submitButton = new JButton("Submit");
        submitButton.addActionListener(e -> submitForm());

		JPanel namePanel = new JPanel();
		JPanel agePanel = new JPanel();
		JPanel coursePanel = new JPanel();
		JPanel submitPanel = new JPanel();
		namePanel.add(nameLabel);
		namePanel.add(nameField);
		agePanel.add(ageLabel);
		agePanel.add(ageField);
		coursePanel.add(courseLabel);
		coursePanel.add(courseComboBox);
		submitPanel.add(submitButton);
        add(namePanel);
        add(agePanel);
        add(coursePanel);
        add(submitPanel);
    }

    private void submitForm() {
        String name = nameField.getText();
        String age = ageField.getText();
        String course = (String) courseComboBox.getSelectedItem();

        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Course: " + course);

        // Perform further processing with the form data
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            Problem2 admissionForm = new Problem2();
            admissionForm.setVisible(true);
        });
    }
}
