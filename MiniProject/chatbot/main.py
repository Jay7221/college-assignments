import streamlit as st
from langchain_core.messages import AIMessage, HumanMessage
from sidebar import init_sidebar
from chat_utils import get_response


# app config
st.set_page_config(page_title="AgroHelp", page_icon="vector-grapes-icon.jpg")
st.title("AgroHelp")
init_sidebar()
st.markdown(
    r"""
    <style>
    .stDeployButton {
            visibility: hidden;
        }
    </style>
    """, unsafe_allow_html=True
)

# session state
if "chat_history" not in st.session_state:
    st.session_state.chat_history = [
        AIMessage(content="Welcome to AgroHelp. How can I help you?"),
    ]


# conversation
for message in st.session_state.chat_history:
    if isinstance(message, AIMessage):
        with st.chat_message("AI", avatar="vector-grapes-icon.jpg"):
            st.write(message.content)
    elif isinstance(message, HumanMessage):
        with st.chat_message("Human"):
            st.write(message.content)

# user input
user_query = st.chat_input("Type your message here...")
if user_query is not None and user_query != "":
    st.session_state.chat_history.append(HumanMessage(content=user_query))

    with st.chat_message("Human"):
        st.markdown(user_query)

    with st.chat_message("AI", avatar="vector-grapes-icon.jpg"):
        response = st.write_stream(get_response(
            user_query, st.session_state.chat_history))

    st.session_state.chat_history.append(AIMessage(content=response))
