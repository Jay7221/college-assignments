# import
from langchain_chroma import Chroma
from langchain_community.document_loaders import TextLoader
from langchain_google_genai.embeddings import GoogleGenerativeAIEmbeddings
from langchain_community.embeddings.sentence_transformer import (
    SentenceTransformerEmbeddings,
)
from langchain_text_splitters import CharacterTextSplitter
from dotenv import load_dotenv
load_dotenv()

# load the document and split it into chunks
loader = TextLoader("book.txt")
documents = loader.load()
print(documents)

# split it into chunks
text_splitter = CharacterTextSplitter(chunk_size=1000, chunk_overlap=0)
docs = text_splitter.split_documents(documents)

# create the open-source embedding function
embeddings = SentenceTransformerEmbeddings(
    model_name="all-MiniLM-L6-v2")


# load it into Chroma
db = Chroma.from_documents(docs, embeddings,
                           persist_directory='./chroma_db_2')

# query it
query = "What are grapes ?"
docs = db.similarity_search(query)

# print results
print(docs[0].page_content)
print(docs)


def load_documents():
    loader = DirectoryLoader(TMP_DIR.as_posix(), glob='**/*.pdf')
    documents = loader.load()
    return documents


def split_documents(documents):
    text_splitter = CharacterTextSplitter(chunk_size=1000, chunk_overlap=0)
    texts = text_splitter.split_documents(documents)
    return texts


def embeddings_on_local_vectordb(texts):
    vectordb = Chroma.from_documents(texts, embedding=GoogleGenerativeAIEmbeddings(),
                                     persist_directory=LOCAL_VECTOR_STORE_DIR.as_posix())
    vectordb.persist()
    retriever = vectordb.as_retriever(search_kwargs={'k': 7})
    return retriever


def process_documents():
    try:
        for source_doc in st.session_state.source_docs:
            #
            with tempfile.NamedTemporaryFile(delete=False, dir=TMP_DIR.as_posix(), suffix='.pdf') as tmp_file:
                tmp_file.write(source_doc.read())
            #
            documents = load_documents()
            #
            for _file in TMP_DIR.iterdir():
                temp_file = TMP_DIR.joinpath(_file)
                temp_file.unlink()
            #
            texts = split_documents(documents)
            #
            if not st.session_state.pinecone_db:
                st.session_state.retriever = embeddings_on_local_vectordb(
                    texts)
            else:
                st.session_state.retriever = embeddings_on_pinecone(texts)
    except Exception as e:
        st.error(f"An error occurred: {e}")
