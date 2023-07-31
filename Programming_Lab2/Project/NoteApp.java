import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;

public class NoteApp extends JFrame {
    private JList<File> noteList;
    private DefaultListModel<File> listModel;
    private JTextArea editor;
    private JMenuBar menuBar;

    public NoteApp() {
        super("Note Taking Application");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(800, 600);

        // Create notes directory if it doesn't exist
        File notesDir = new File("notes");
        notesDir.mkdir();

        // Create note list and add it to the UI
        listModel = new DefaultListModel<File>();
        noteList = new JList<File>(listModel);
        noteList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        noteList.addListSelectionListener(new NoteSelectionListener());
        JScrollPane noteScrollPane = new JScrollPane(noteList);
        noteScrollPane.setPreferredSize(new Dimension(200, 0));
        add(noteScrollPane, BorderLayout.EAST);

        // Create editor and add it to the UI
        editor = new JTextArea();
        editor.setFont(new Font("Comic Sans", Font.PLAIN, 30));
        JScrollPane editorScrollPane = new JScrollPane(editor);
        add(editorScrollPane, BorderLayout.CENTER);

        
        // Create menu bar
        menuBar = new JMenuBar();
        add(menuBar, BorderLayout.NORTH);

        // Add "New Note" button
        JButton newNoteButton = new JButton("New Note");
        newNoteButton.addActionListener(new NewNoteListener());
        newNoteButton.setFocusable(false);
        menuBar.add(newNoteButton);

        // Add "Save Note" button
        JButton saveNoteButton = new JButton("Save Note");
        saveNoteButton.addActionListener(new SaveNoteListener());
        saveNoteButton.setFocusable(false);
        menuBar.add(saveNoteButton);

        // Add "Delete Note button"
        JButton deletNoteButton = new JButton("Delete Note");
        deletNoteButton.addActionListener(new DeleteNoteListener());
        deletNoteButton.setFocusable(false);
        menuBar.add(deletNoteButton);

        // Populate note list with existing notes
        for (File file : notesDir.listFiles()) {
            if (file.isFile() && file.getName().endsWith(".note")) {
                listModel.addElement(file);
            }
        }

        // Show UI
        setVisible(true);
    }

    private class NoteSelectionListener implements ListSelectionListener {
        public void valueChanged(ListSelectionEvent event) {
            if (!event.getValueIsAdjusting()) {
                File selectedNote = noteList.getSelectedValue();
                if (selectedNote != null) {
                    try {
                        BufferedReader reader = new BufferedReader(new FileReader(selectedNote));
                        StringBuilder text = new StringBuilder();
                        String line;
                        while ((line = reader.readLine()) != null) {
                            text.append(line + "\n");
                        }
                        reader.close();
                        editor.setText(text.toString());
                    } catch (IOException e) {
                        JOptionPane.showMessageDialog(NoteApp.this, "Error loading note: " + e.getMessage());
                    }
                } else {
                    editor.setText("");
                }
            }
        }
    }

    private class NewNoteListener implements ActionListener {
        public void actionPerformed(ActionEvent event) {
            String name = JOptionPane.showInputDialog(NoteApp.this, "Enter name for new note:");
            if (name != null && !name.trim().isEmpty()) {
                File newNote = new File("notes/" + name.trim() + ".note");
                try {
                    newNote.createNewFile();
                    listModel.addElement(newNote);
                } catch (IOException e) {
                    JOptionPane.showMessageDialog(NoteApp.this, "Error creating note: " + e.getMessage());
                }
            }
        }
    }

    private class SaveNoteListener implements ActionListener{
        public void actionPerformed(ActionEvent event){
            try{
                File file = noteList.getSelectedValue();
                if(file != null){
                    BufferedWriter writer = new BufferedWriter(new FileWriter(file));
                    String text = editor.getText();
                    writer.write(text);
                    writer.flush();
                    writer.close();    
                }
            }catch(Exception exception){
                System.out.println(exception);
            }
        }
    }

    private class DeleteNoteListener implements ActionListener{
        public void actionPerformed(ActionEvent event){
            try{
                File file = noteList.getSelectedValue();
                int option = JOptionPane.showConfirmDialog(NoteApp.this, "Are you sure you want to delete this note ?"
                 + file.getName(), "delete", JOptionPane.YES_NO_OPTION);
                if(option != 0){
                    return;
                }
                if(file != null){
                    listModel.removeElement(file);
                    file.delete();
                }
            }catch(Exception exception){
                System.out.println(exception);
            }
        }
    }

    public static void main(String[] args) {
        new NoteApp();
    }
}

