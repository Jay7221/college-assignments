import streamlit as st

# Sample data for multiple-choice menus (modify as needed)
menu_data = {
    "What is your favorite color?": ["Red", "Green", "Blue", "Other"],
    "What kind of music do you enjoy?": ["Rock", "Pop", "Classical", "Electronic"]
}

# Function to handle user input and trigger appropriate responses
def handle_input(user_input):
    # Check for keywords to trigger multiple-choice menus
    for question, choices in menu_data.items():
        if question.lower() in user_input.lower():
            selection = st.selectbox(question, choices)
            return f"You selected: {selection}"

    # Default text response for non-matching keywords
    return f"I understand. Let me know if you have any other questions."

# Streamlit app layout
st.title("Chatbot Demo")

user_input = st.text_input("Enter your message:")

if user_input:
    response = handle_input(user_input)
    st.write("Chatbot:", response)

