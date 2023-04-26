import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

public class NoteApp extends JFrame {
    private JList<String> noteList;
    private DefaultListModel<String> listModel;
    private JTextArea editor;
    private JMenuBar menuBar;

    static final String DB_URL = "jdbc:mysql://localhost:3306/programming_lab_2";
    static final String USERNAME = "root";
    static final String PASSWORD = "Jay@1234";
    Connection conn = null;
    private void connect(){
        if(conn == null){
            try {
                    Class.forName("com.mysql.cj.jdbc.Driver");

                    System.out.println("Connecting to database ...");

                    conn = DriverManager.getConnection(DB_URL, USERNAME, PASSWORD);

                    System.out.println("Successfully connected!");
            }
            catch(Exception e) {
                    System.out.println(e);
            }

        }
    }

    void putAll(){
        connect();
        try{
            String sql = "SELECT name FROM Notes;";
            Statement stmt = conn.createStatement();
            ResultSet rs = stmt.executeQuery(sql);
            while(rs.next()){
                listModel.addElement(rs.getString("name"));
            }
    
        }catch(Exception e){
            System.out.println(e);
        }        
    }
    private void removeNote(String noteName){
        try{
            connect();
            String sql = "DELETE FROM Notes WHERE name='" + noteName + "';";
            Statement stmt = conn.createStatement();
            stmt.executeUpdate(sql);

        }catch(Exception e){
            System.out.println(e);
        }
    }
    private void setNote(String noteName, String noteData){
        try{
            connect();
            String sql = "UPDATE Notes SET data='" + noteData + "' WHERE name='" + noteName + "';";
            Statement stmt = conn.createStatement();
            stmt.executeUpdate(sql);

        }catch(Exception e){
            System.out.println(e);
        }
    }
    private void createNewNote(String note){
        try{
            connect();
            String sql = "INSERT INTO Notes VALUES ('" + note + "' , ' ');";
            Statement stmt = conn.createStatement();
            stmt.executeUpdate(sql);
        }catch(Exception e){
            System.out.println(e);
        }
    }

    public NoteApp() {
        super("Note Taking Application");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(800, 600);

        // Create notes directory if it doesn't exist
        File notesDir = new File("notes");
        notesDir.mkdir();

        // Create note list and add it to the UI
        listModel = new DefaultListModel<String>();
        noteList = new JList<String>(listModel);
        noteList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        noteList.addListSelectionListener(new NoteSelectionListener());
        JScrollPane noteScrollPane = new JScrollPane(noteList);
        noteScrollPane.setPreferredSize(new Dimension(200, 0));
        add(noteScrollPane, BorderLayout.EAST);

        // Create editor and add it to the UI
        editor = new JTextArea();
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

        putAll();

        // Show UI
        setVisible(true);
    }

    private class NoteSelectionListener implements ListSelectionListener {

        public void valueChanged(ListSelectionEvent event) {
            if (!event.getValueIsAdjusting()) {
                String selectedNote = noteList.getSelectedValue();
                connect();
                if (selectedNote != null) {
                    try {

                        StringBuilder text = new StringBuilder();
                        Statement stmt = conn.createStatement();
                        String sql = "SELECT data FROM Notes WHERE name='" + selectedNote + "'";
                        ResultSet rs = stmt.executeQuery(sql);
                        if(rs.next()){
                            editor.setText(rs.getString("data"));
                        }else{
                            editor.setText("");
                        }
                        
                    } catch (Exception e) {
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
                String newNote = name;
                try {
                    createNewNote(newNote);
                    listModel.addElement(newNote);
                } catch (Exception e) {
                    JOptionPane.showMessageDialog(NoteApp.this, "Error creating note: " + e.getMessage());
                }
            }
        }
    }

    private class SaveNoteListener implements ActionListener{
        public void actionPerformed(ActionEvent event){
            try{
                String noteName = noteList.getSelectedValue();
                if(noteName != null){
                    setNote(noteName, editor.getText());
                }
            }catch(Exception exception){
                System.out.println(exception);
            }
        }
    }

    private class DeleteNoteListener implements ActionListener{
        public void actionPerformed(ActionEvent event){
            try{
                String noteName = noteList.getSelectedValue();
                listModel.removeElement(noteList.getSelectedValue());
                if(noteName != null){
                    removeNote(noteName);
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

