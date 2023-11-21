import React, { useState } from "react";
import "./App.css";

const App = () => {
  const [number, setNumber] = useState(0);
  const increment = () => {
    setNumber(number + 1);
  };
  const decrement = () => {
    setNumber(Math.max(number - 1, 0));
  };
  return (
    <div className="App">
      <button className="increment" onClick={increment}>
        +
      </button>
      <button className="number">{number}</button>
      <button className="decrement" onClick={decrement}>
        -
      </button>
    </div>
  );
};

export default App;
