import tkinter as tk
from tkinter import messagebox
from neo4j import GraphDatabase

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

class Application(tk.Tk):
    def __init__(self, db_manager, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.title("Research Papers Database Search")
        self.db_manager = db_manager
        self.create_widgets()

    def create_widgets(self):
        self.label_paper_a = tk.Label(self, text="Paper A ID:")
        self.label_paper_a.grid(row=0, column=0, padx=5, pady=5)
        self.entry_paper_a = tk.Entry(self)
        self.entry_paper_a.grid(row=0, column=1, padx=5, pady=5)

        self.label_paper_b = tk.Label(self, text="Paper B ID:")
        self.label_paper_b.grid(row=1, column=0, padx=5, pady=5)
        self.entry_paper_b = tk.Entry(self)
        self.entry_paper_b.grid(row=1, column=1, padx=5, pady=5)

        self.label_paper_id = tk.Label(self, text="Paper ID:")
        self.label_paper_id.grid(row=2, column=0, padx=5, pady=5)
        self.entry_paper_id = tk.Entry(self)
        self.entry_paper_id.grid(row=2, column=1, padx=5, pady=5)

        self.btn_search_citation = tk.Button(self, text="Search Citation", command=self.search_citation)
        self.btn_search_citation.grid(row=3, column=0, padx=5, pady=5)

        self.btn_search_classification = tk.Button(self, text="Search Classification", command=self.search_classification)
        self.btn_search_classification.grid(row=3, column=1, padx=5, pady=5)

    def search_citation(self):
        paper_a_id = self.entry_paper_a.get()
        paper_b_id = self.entry_paper_b.get()
        cited = self.db_manager.check_citation(paper_a_id, paper_b_id)
        if cited:
            messagebox.showinfo("Citation Search Result", f"Paper {paper_a_id} cites Paper {paper_b_id}")
        else:
            messagebox.showinfo("Citation Search Result", f"Paper {paper_a_id} does not cite Paper {paper_b_id}")

    def search_classification(self):
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
