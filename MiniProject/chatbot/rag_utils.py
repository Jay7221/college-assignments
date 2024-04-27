from langchain_community.vectorstores import Chroma
from langchain_community.document_loaders import DirectoryLoader
from langchain.text_splitter import CharacterTextSplitter
from langchain_google_genai.embeddings import GoogleGenerativeAIEmbeddings
import os
from settings import GOOGLE_EMBEDDING, SENTENCE_TRANS
import streamlit as st
from langchain_community.embeddings.sentence_transformer import (
    SentenceTransformerEmbeddings,
)


from dotenv import load_dotenv
load_dotenv()


def get_context(query, num_chunks=7):
    if st.session_state.embedding == GOOGLE_EMBEDDING:
        embeddings = GoogleGenerativeAIEmbeddings(model='models/embedding-001')
        db = Chroma(persist_directory='./chroma_db',
                    embedding_function=embeddings)
    else:
        embeddings = SentenceTransformerEmbeddings(
            model_name="all-MiniLM-L6-v2")
        db = Chroma(persist_directory='./chroma_db_2',
                    embedding_function=embeddings)

    docs = db.similarity_search(query, k=num_chunks)
    return docs


if __name__ == '__main__':
    while True:
        query = input("Enter your query: ")
        context = get_context(query, num_chunks=10)
        print("CONTEXT:\n\n")
        print('\n-------\n'.join([doc.page_content for doc in context]))
