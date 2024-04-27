import streamlit as st
from streamlit_chat import message
import random
from langchain_google_genai import GoogleGenerativeAI
from dotenv import load_dotenv
import os

load_dotenv()
API_KEY = os.getenv("GEMINI_API")

llm = GoogleGenerativeAI(model='gemini-pro', google_api_key=API_KEY)

def init_sidebar():
    cities = [
        "Sangli",
        "Solapur",
        "Nashik"
    ]

    st.sidebar.slider("Number of Days after pruning: ", 
                            min_value=20, max_value=100, value=4, key="days_after_pruning")
    st.sidebar.selectbox("Location (City)", options=cities, key="location")
    st.sidebar.info("This is AgroHelp.")

init_sidebar()

if "history" not in st.session_state:
    st.session_state.history = []
    st.session_state.history.append(("bot", "Welcome to AgroHelp ! How may I help you ?"))


def get_response(msg):
    res = llm.invoke(msg)
    return res

def handle_chat_submit():
    user_msg = st.session_state.user_message
    bot_res = get_response(user_msg)
    st.session_state.history.append(("user", user_msg))
    st.session_state.history.append(("bot", bot_res))


for msg_type, msg_data in st.session_state.history:
    if msg_type == "user":
        message(msg_data, is_user=True, avatar_style="thumbs")
    elif msg_type == "bot":
        message(msg_data, key=str(random.randint(1, 1000)))

st.chat_input("Enter your text here", key="user_message", on_submit=handle_chat_submit)
