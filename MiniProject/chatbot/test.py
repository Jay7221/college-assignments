# import
from langchain_chroma import Chroma
from langchain_community.embeddings.sentence_transformer import (
    SentenceTransformerEmbeddings,
)

# create the open-source embedding function
embedding_function = SentenceTransformerEmbeddings(
    model_name="all-MiniLM-L6-v2")

query = "What is Downy Mildew ?"

# load from disk
db3 = Chroma(persist_directory="./chroma_db",
             embedding_function=embedding_function)
docs = db3.similarity_search(query)
print(docs[0].page_content)
