import tkinter as tk
from tkinter import messagebox
from tkinter import ttk
from neo4j import GraphDatabase

# Custom style class for tkinter application
class CustomStyle:
    def __init__(self):
        self.background_color = '#f0f0f0'
        self.foreground_color = '#333333'
        self.highlight_color = '#4285f4'
        self.font = ('Arial', 10)
        self.label_font = ('Arial', 10, 'bold')

# Database manager class remains unchanged
class DatabaseManager:
    def __init__(self, uri, username, password):
        self._uri = uri
        self._username = username
        self._password = password
        self._driver = None

    def connect(self):
        self._driver = GraphDatabase.driver(self._uri, auth=(self._username, self._password))

    def disconnect(self):
        if self._driver is not None:
            self._driver.close()

    def check_citation(self, paper_a_id, paper_b_id):
        with self._driver.session() as session:
            result = session.run("""
            MATCH path = (p1:Paper {id: $paper_a_id})-[:CITES*]->(p2:Paper {id: $paper_b_id})
            RETURN relationships(path) AS citations
            """, paper_a_id=paper_a_id, paper_b_id=paper_b_id)
            paths = result.single()
            if paths:
                return [(rel.start_node['id'], rel.end_node['id']) for rel in paths['citations']]
            else:
                return None

    def get_paper_classification(self, paper_id):
        with self._driver.session() as session:
            result = session.run("""
            MATCH (p:Paper {id: $paper_id})
            RETURN p.class as classification
            """, paper_id=paper_id)
            return [record['classification'] for record in result]

# Application class with custom UI elements
class Application(tk.Tk):
    def __init__(self, db_manager, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.title("Research Papers Database Search")
        self.db_manager = db_manager
        self.custom_style = CustomStyle()
        self.configure(background=self.custom_style.background_color)
        self.current_search = "citation"
        self.create_widgets()

    def create_widgets(self):
        self.label_paper_a = ttk.Label(self, text="Paper A ID:", font=self.custom_style.label_font, background=self.custom_style.background_color, foreground=self.custom_style.foreground_color)
        self.label_paper_a.grid(row=0, column=0, padx=5, pady=5, sticky='w')
        self.entry_paper_a = ttk.Entry(self, font=self.custom_style.font)
        self.entry_paper_a.grid(row=0, column=1, padx=5, pady=5)

        self.label_paper_b = ttk.Label(self, text="Paper B ID:", font=self.custom_style.label_font, background=self.custom_style.background_color, foreground=self.custom_style.foreground_color)
        self.label_paper_b.grid(row=1, column=0, padx=5, pady=5, sticky='w')
        self.entry_paper_b = ttk.Entry(self, font=self.custom_style.font)
        self.entry_paper_b.grid(row=1, column=1, padx=5, pady=5)

        self.label_paper_id = ttk.Label(self, text="Paper ID:", font=self.custom_style.label_font, background=self.custom_style.background_color, foreground=self.custom_style.foreground_color)
        self.label_paper_id.grid(row=2, column=0, padx=5, pady=5, sticky='w')
        self.entry_paper_id = ttk.Entry(self, font=self.custom_style.font)
        self.entry_paper_id.grid(row=2, column=1, padx=5, pady=5)

        self.btn_search = ttk.Button(self, text="Search Citation", command=self.search, style='Custom.TButton')
        self.btn_search.grid(row=3, column=0, columnspan=2, padx=5, pady=5, sticky='ew')

        self.toggle_search_btn = ttk.Button(self, text="Switch to Classification Search", command=self.toggle_search, style='Custom.TButton')
        self.toggle_search_btn.grid(row=4, column=0, columnspan=2, padx=5, pady=5, sticky='ew')

    def toggle_search(self):
        if self.current_search == "citation":
            self.current_search = "classification"
            self.toggle_search_btn.config(text="Switch to Citation Search")
            self.label_paper_a.grid_forget()
            self.entry_paper_a.grid_forget()
            self.label_paper_b.grid_forget()
            self.entry_paper_b.grid_forget()
            self.label_paper_id.grid(row=0, column=0, padx=5, pady=5, sticky='w')
            self.entry_paper_id.grid(row=0, column=1, padx=5, pady=5)
        else:
            self.current_search = "citation"
            self.toggle_search_btn.config(text="Switch to Classification Search")
            self.label_paper_a.grid(row=0, column=0, padx=5, pady=5, sticky='w')
            self.entry_paper_a.grid(row=0, column=1, padx=5, pady=5)
            self.label_paper_b.grid(row=1, column=0, padx=5, pady=5, sticky='w')
            self.entry_paper_b.grid(row=1, column=1, padx=5, pady=5)
            self.label_paper_id.grid_forget()
            self.entry_paper_id.grid_forget()

    def search(self):
        if self.current_search == "citation":
            paper_a_id = self.entry_paper_a.get()
            paper_b_id = self.entry_paper_b.get()
            cited = self.db_manager.check_citation(paper_a_id, paper_b_id)
            if cited:
                messagebox.showinfo("Citation Search Result", f"Paper {paper_a_id} cites Paper {paper_b_id}")
            else:
                messagebox.showinfo("Citation Search Result", f"Paper {paper_a_id} does not cite Paper {paper_b_id}")
        else:
            paper_id = self.entry_paper_id.get()
            classifications = self.db_manager.get_paper_classification(paper_id)
            messagebox.showinfo("Classification Search Result", f"Paper {paper_id} has the following classifications: {', '.join(classifications)}")

if __name__ == "__main__":
    # Neo4j connection details
    uri = "bolt://localhost:7687"
    username = "ads"
    password = "Jay@1234"

    # Create and connect to database manager
    db_manager = DatabaseManager(uri, username, password)
    db_manager.connect()

    # Create and run the application
    app = Application(db_manager)
    app.mainloop()

    # Disconnect from the database
    db_manager.disconnect()
