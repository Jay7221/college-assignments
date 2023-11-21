import React, { useState } from "react";

const Card = ({ characterData: data }) => {
  const [show, setShow] = useState(false);
  const toggleShow = () => {
    if (show) {
      setShow(false);
    } else {
      setShow(true);
    }
  };
  return (
    <div className="card" onClick={toggleShow}>
      <div></div>

      {show ? (
        <div className="modal">
          <p>Name : {data.name}</p>
          <p>Gender: {data.gender}</p>
          <p>Mass : {data.mass}</p>
          <p>Height : {data.height}</p>
          <p>Skin Color : {data.skin_color}</p>
          <p>Eye Color: {data.eye_color}</p>
        </div>
      ) : (
        <div>
          <img
            src={`https://picsum.photos/id/${parseInt(
              100 * Math.random()
            )}/400`}
            alt={data.name}
          />
        </div>
      )}
      <div>
        <h3>{data.name}</h3>
      </div>
    </div>
  );
};

export default Card;
