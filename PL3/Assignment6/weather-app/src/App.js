import "./App.css";
import React, { useState, useEffect } from "react";
import { Dimmer, Loader } from "semantic-ui-react";
import Weather from "./components/weather";

const API_URL = "https://api.openweathermap.org/data/2.5/";
const API_KEY = "7a17c4f953f8c9e4e8701d84b9264f00";

function App() {
  const [pastSearches, setPastSearches] = useState([]);
  const [city, setCity] = useState("Sangli");
  const [data, setData] = useState([]);
  const fetchData = async () => {
    const URL = `${API_URL}weather?q=${city}&appid=${API_KEY}`;
    const response = await fetch(URL);
    const resData = await response.json();
    setData(resData);
  };
  const addData = (data) => {
    let newArr = [data, ...pastSearches];
    console.log(newArr.map((elem) => elem.name));
    newArr = newArr.filter((elem, ind, arr) => {
      for (let i = 0; i < ind; ++i) {
        if (arr[i].name === arr[ind].name) {
          return false;
        }
      }
      return true;
    });
    console.log(newArr.map((elem) => elem.name));
    setPastSearches(newArr);
  };
  useEffect(() => {
    fetchData();
  }, []);
  const refresh = () => {
    if (data) {
      addData(data);
    }
    fetchData();
  };
  let ind = 0;
  return (
    <div className="App">
      <input
        type="text"
        value={city}
        id="city"
        onChange={(e) => {
          setCity(e.target.value);
        }}
      />
      <button onClick={refresh}>Search</button>
      {typeof data.main != "undefined" ? (
        <Weather weatherData={data} />
      ) : (
        <div>
          <Dimmer active>
            <Loader>Loading ...</Loader>
          </Dimmer>
        </div>
      )}
      <div className="past-searches">
        <h1>Past Searches</h1>
        {pastSearches.map((data, index) => {
          ++ind;
          return (
            <h4
              className="past-search-item"
              onClick={() => {
                setData(data);
              }}
              key={ind}
            >
              {data.name}
            </h4>
          );
        })}
      </div>
    </div>
  );
}

export default App;
