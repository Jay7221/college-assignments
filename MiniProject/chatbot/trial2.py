import streamlit as st
import numpy as np
import pandas as pd
import time

df = pd.DataFrame({
    'col1': [1, 2, 3, 4],
    'col2': [4, 3, 4, 1]
})

st.write(df)
arr = np.random.randn(10, 20)
st.dataframe(arr)

df = pd.DataFrame(np.random.randn(10, 20),
                  columns=(f"col {i}" for i in range(20)))
st.dataframe(df.style.highlight_max(axis=0, color="blue"))
st.table(df)

chart_data = pd.DataFrame(
    np.random.randn(20, 3),
    columns=['a', 'b', 'c']
)

if st.checkbox('Show line chart'):
    st.line_chart(chart_data)

map_data = pd.DataFrame(
    np.random.randn(1000, 2) / [50, 50] + [37.76, -122.4],
    columns=['lat', 'lon']
)
st.map(map_data)

x = st.slider('value of x')

st.write(f"{x} squared is {x * x}")

def onc():
    st.write(st.session_state.name)
    st.session_state.name = ''

st.text_input("Your name", key="name", on_change=onc)

st.write(f"Your name is {st.session_state.name}")

option = st.selectbox(
    'Which number do you like best ?',
    [1, 43, 1]
)

st.write(f"You selected {option}")

add_selection = st.sidebar.selectbox(
    'How would you like to be contacted?',
    ('Email', 'Home phone', 'Mobile phone')
)


add_slider = st.sidebar.slider(
    'Select a range of values',
    0.0, 100.0, (25.0, 75.0)
)


left_column, right_column = st.columns(2)

left_column.button('Press me!')

with right_column:
    chosen = st.radio(
        'Sorting hat',
        ("Gryffindor", "Ravenclaw", "Hufflepuff", "Slytherin")
    )
    st.write(f"You are in {chosen} house!")


"Starting a long computation..."

latest_iteration = st.empty()
bar = st.progress(0)

for i in range(100):
    latest_iteration.text(f"Iteration {i + 1}")
    bar.progress(i + 1)
    time.sleep(0.1)

"...and now we\'re done"
