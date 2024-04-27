from langchain_google_genai import GoogleGenerativeAI
from langchain_core.output_parsers import StrOutputParser
from langchain_core.prompts import ChatPromptTemplate
from rag_utils import get_context
import streamlit as st
from settings import GEMINI, LLAMA
from langchain_community.llms import Ollama

import os
from dotenv import load_dotenv
load_dotenv()
API_KEY = os.getenv("GEMINI_API")


def get_response(user_query, chat_history):

    relevant_chunks = get_context(user_query)
    context = '\n---\n'.join([doc.page_content for doc in relevant_chunks])
    farm_details = f"""location:{st.session_state.location}\ngrape variety:{st.session_state.grape_species}"""
    relevant_chunks.extend(get_context(farm_details, 2))

    template = """
    You are a helpful farm assistant. Answer the following questions considering the history of the conversation and the context provided. If the answer is not derivable from chat history, context and farm details, respond with "No records regarding query found":

    Chat history: {chat_history}

    User question: {user_question}

    Farm Details: {farm_details}

    Context: {context}
    """

    prompt = ChatPromptTemplate.from_template(template)

    if st.session_state.llm == GEMINI:
        llm = GoogleGenerativeAI(model='gemini-pro', google_api_key=API_KEY)
    else:
        llm = Ollama(model='llama2')

    chain = prompt | llm | StrOutputParser()

    return chain.stream({
        "chat_history": chat_history,
        "user_question": user_query,
        "context": context,
        "farm_details": farm_details
    })
