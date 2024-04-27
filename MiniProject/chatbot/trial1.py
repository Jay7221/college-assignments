import streamlit as st

# Sample data for multiple-choice menus (modify as needed)
menu_data = {
    "What is the menu?": ["Cheese Burger", "Pizza", "Hamburger"]
}

# Function to keep track of conversation history
def update_history(message):
    if "history" not in st.session_state:
        st.session_state["history"] = []
    st.session_state["history"].append(message)

# Function to handle user input and trigger appropriate responses
def handle_input(user_input):
    update_history("User: " + user_input)

    # Check for keywords to trigger multiple-choice menus
    for question, choices in menu_data.items():
        if question.lower() in user_input.lower():
            selection = st.selectbox(question, choices)
            update_history(f"Chatbot: {selection}")
            return f"You selected: {selection}"

    # Default text response for non-matching keywords
    update_history("Chatbot: I understand. Let me know if you have any other questions.")
    return f"I understand. Let me know if you have any other questions."

# Streamlit app layout
st.title("Chatbot Demo")

# Display conversation history
if "history" in st.session_state:
    for message in st.session_state["history"]:
        st.write(message)

user_input = st.text_input("Enter your message:")

if user_input:
    response = handle_input(user_input)
    st.write("Chatbot:", response)
    st.write("Thank you for using the application!")  # Final message

