import streamlit as st
import pickle
import pandas as pd
import numpy as np
from datetime import datetime
from datetime import timedelta
from settings import llms, embeddings

cur_date = datetime.now()
pruning_date = datetime.strptime(f"{datetime.now().year}-09-15", "%Y-%m-%d")
if pruning_date > cur_date:
    pruning_date = datetime.strptime(
        f"{datetime.now().year - 1}-09-15", "%Y-%m-%d")
days_after_pruning = (cur_date - pruning_date).days


def init_sidebar():
    cities = [
        "Sangli",
        "Solapur",
        "Nashik"
    ]

    grape_species = [
        "None planted",
        "Thompson Seedless",
        "Red Globe"
    ]
    st.sidebar.title("User Settings")

    st.sidebar.text_input("User Name", key="user_name")
    st.sidebar.slider("Number of Days after pruning: ",
                      min_value=max(0, days_after_pruning - 30), max_value=min(days_after_pruning + 30, 366), value=days_after_pruning, key="days_after_pruning")
    st.sidebar.selectbox("Location (City)", options=cities, key="location")
    st.sidebar.selectbox(
        "Grape Species", options=grape_species, key="grape_species")
    st.sidebar.line_chart(disease_predictions())
    st.sidebar.info(
        """Welcome to AgroHelp. Here you can define the setting of your farm to get more relevant responses.""")
    st.sidebar.selectbox('LLM', options=llms, key='llm')
    st.sidebar.selectbox('Embedding', options=embeddings, key='embedding')


def disease_predictions():
    location_to_index = {
        'Sangli': 4,
        'Solapur': 7,
        'Nashik': 9,
    }
    risk_levels = {
        'nil': 0,
        'low': 1,
        'moderate': 2,
        'high': 3,
        'very high': 4
    }

    df = pd.read_csv('../datasets/processed_data.csv')
    X = df.drop(['Downy Mildew', 'Powdery Mildew', 'Anthracnose'], axis=1)
    ind = location_to_index[st.session_state.location]

    downy_mildew_classfier = pickle.load(
        open('../models/downy_mildew_classifier.sav', 'rb'))
    downy_mildew_res = list(
        downy_mildew_classfier.predict(X.loc[ind: ind + 7]))

    powdery_mildew_classfier = pickle.load(
        open('../models/powdery_mildew_classifier.sav', 'rb'))
    powdery_mildew_res = list(
        powdery_mildew_classfier.predict(X.loc[ind: ind + 7]))

    anthracnose_classfier = pickle.load(
        open('../models/anthracnose_classifier.sav', 'rb'))
    anthracnose_res = list(
        anthracnose_classfier.predict(X.loc[ind: ind + 7]))

    res_dict = {
        'Downy Mildew': [],
        'Powdery Mildew': [],
        'Anthracnose': [],
    }
    for i in range(7):
        cur = datetime.now()
        date = datetime.strptime(
            f"{cur.year}-{cur.month}-{cur.day}", "%Y-%m-%d")
        date += timedelta(days=i)
        # res_dict['date'].append(date.strftime("%Y-%m-%d"))
        res_dict['Downy Mildew'].append(downy_mildew_res[i])
        res_dict['Powdery Mildew'].append(powdery_mildew_res[i])
        res_dict['Anthracnose'].append(anthracnose_res[i])
    st.session_state.risk_levels = str(res_dict)
    return pd.DataFrame(res_dict)
