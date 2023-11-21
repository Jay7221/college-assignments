import React, { useEffect, useState } from "react";
import "./App.css";
import Card from "./components/Card";
const API_URL = "https://swapi.dev/api/";
function App() {
  const [characters, setCharacters] = useState([]);
  useEffect(() => {
    const fetchData = async () => {
      const URL = `${API_URL}people/`;
      const res = await fetch(URL);
      const resData = await res.json();
      const characterData = resData["results"];
      setCharacters(characterData);
    };
    fetchData();
  }, []);
  return (
    <div className="app">
      <h1>Star-Wars!</h1>

      {characters?.length > 0 ? (
        <div className="container">
          {characters.map((data) => (
            <Card characterData={data} />
          ))}
        </div>
      ) : (
        <div className="empty">
          <h2>No characters found</h2>
        </div>
      )}
    </div>
  );
}

export default App;
