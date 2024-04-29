// Classroom.js
import React, { useState, useEffect } from "react";
import api from "./api";
import "./Classroom.css";

function Classroom() {
  const [classrooms, setClassrooms] = useState([]);
  const [formData, setFormData] = useState({
    building: "",
    room_number: "",
    capacity: "",
  });
  const [updateMode, setUpdateMode] = useState(false);
  const [updatingBuilding, setUpdatingBuilding] = useState(null);

  useEffect(() => {
    fetchData();
  }, []);

  const fetchData = async () => {
    try {
      const response = await api.get("/classrooms");
      setClassrooms(response.data);
    } catch (error) {
      console.error("Error fetching data:", error);
    }
  };

  const handleInputChange = (e) => {
    const { name, value } = e.target;
    setFormData((prevData) => ({ ...prevData, [name]: value }));
  };

  const handleAddClassroom = async () => {
    try {
      if (updateMode) {
        await api.put(`/classrooms/${updatingBuilding}`, formData);
        setUpdateMode(false);
        setUpdatingBuilding(null);
      } else {
        await api.post("/classrooms", formData);
      }
      fetchData();
      setFormData({ building: "", room_number: "", capacity: "" });
    } catch (error) {
      console.error("Error adding/updating classroom:", error);
    }
  };

  const handleUpdateClassroom = (classroom) => {
    setUpdateMode(true);
    setUpdatingBuilding(classroom.building);
    setFormData({ ...classroom });
  };

  const handleDeleteClassroom = async (building) => {
    try {
      await api.delete(`/classrooms/${building}`);
      fetchData();
    } catch (error) {
      console.error("Error deleting classroom:", error);
    }
  };

  return (
    <div className="classroom-container">
      <h1>Classrooms</h1>

      <form className="classroom-form">
        {/* Input fields for adding/updating a classroom */}
        <label>
          Building:
          <input
            type="text"
            name="building"
            value={formData.building}
            onChange={handleInputChange}
          />
        </label>
        <label>
          Room Number:
          <input
            type="text"
            name="room_number"
            value={formData.room_number}
            onChange={handleInputChange}
          />
        </label>
        <label>
          Capacity:
          <input
            type="text"
            name="capacity"
            value={formData.capacity}
            onChange={handleInputChange}
          />
        </label>
        {/* Button to add/update a classroom */}
        <button type="button" onClick={handleAddClassroom}>
          {updateMode ? "Update Classroom" : "Add Classroom"}
        </button>
      </form>

      <table className="classroom-table">
        <thead>
          <tr>
            <th>Building</th>
            <th>Room Number</th>
            <th>Capacity</th>
            <th>Actions</th>
          </tr>
        </thead>
        <tbody>
          {classrooms.map((classroom) => (
            <tr key={classroom.building}>
              {/* Display form fields if in update mode */}
              {updateMode && updatingBuilding === classroom.building ? (
                <>
                  <td>
                    <input
                      type="text"
                      name="building"
                      value={formData.building}
                      onChange={handleInputChange}
                    />
                  </td>
                  <td>
                    <input
                      type="text"
                      name="room_number"
                      value={formData.room_number}
                      onChange={handleInputChange}
                    />
                  </td>
                  <td>
                    <input
                      type="text"
                      name="capacity"
                      value={formData.capacity}
                      onChange={handleInputChange}
                    />
                  </td>
                </>
              ) : (
                // Display classroom details if not in update mode
                <>
                  <td>{classroom.building}</td>
                  <td>{classroom.room_number}</td>
                  <td>{classroom.capacity}</td>
                </>
              )}
              {/* Buttons to update and delete a classroom */}
              <td>
                {updateMode && updatingBuilding === classroom.building ? (
                  <button type="button" onClick={handleAddClassroom}>
                    Confirm Update
                  </button>
                ) : (
                  <button
                    type="button"
                    onClick={() => handleUpdateClassroom(classroom)}
                  >
                    Update
                  </button>
                )}
                <button
                  type="button"
                  onClick={() => handleDeleteClassroom(classroom.building)}
                >
                  Delete
                </button>
              </td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
}

export default Classroom;
