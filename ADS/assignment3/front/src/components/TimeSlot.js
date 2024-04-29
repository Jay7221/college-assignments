// TimeSlotComponent.js
import React, { useState, useEffect } from "react";
import api from "./api"; // Assuming you have an api.js file for API calls
import "./TimeSlot.css"; // Import your stylesheet

const TimeSlotComponent = () => {
  const [timeSlots, setTimeSlots] = useState([]);
  const [newTimeSlot, setNewTimeSlot] = useState({
    time_slot_id: "",
    day: "",
    start_time: "",
    end_time: "",
  });
  const [updatingTimeSlot, setUpdatingTimeSlot] = useState(null);

  useEffect(() => {
    fetchTimeSlots();
  }, []);

  const fetchTimeSlots = async () => {
    try {
      const response = await api.get("/timeslots");
      setTimeSlots(response.data);
    } catch (error) {
      console.error("Error fetching TimeSlots:", error);
    }
  };

  const formatDateTimeForMySQL = (dateTimeString) => {
    const dateTime = new Date(dateTimeString);
    const formattedDateTime = dateTime
      .toISOString()
      .slice(0, 19)
      .replace("T", " ");
    return formattedDateTime;
  };

  // ...

  const createNewTimeSlot = async () => {
    try {
      const formattedNewTimeSlot = {
        ...newTimeSlot,
        start_time: formatDateTimeForMySQL(newTimeSlot.start_time),
        end_time: formatDateTimeForMySQL(newTimeSlot.end_time),
      };
      await api.post("/timeslots", formattedNewTimeSlot);
      fetchTimeSlots();
      setNewTimeSlot({
        time_slot_id: "",
        day: "",
        start_time: "",
        end_time: "",
      });
    } catch (error) {
      console.error("Error creating TimeSlot:", error);
    }
  };

  const updateExistingTimeSlot = async () => {
    try {
      const formattedUpdatingTimeSlot = {
        ...updatingTimeSlot,
        start_time: formatDateTimeForMySQL(updatingTimeSlot.start_time),
        end_time: formatDateTimeForMySQL(updatingTimeSlot.end_time),
      };
      await api.put(
        `/timeslots/${updatingTimeSlot.time_slot_id}`,
        formattedUpdatingTimeSlot
      );
      fetchTimeSlots();
      setUpdatingTimeSlot(null);
    } catch (error) {
      console.error("Error updating TimeSlot:", error);
    }
  };

  const deleteTimeSlot = async (timeSlotId) => {
    try {
      await api.delete(`/timeslots/${timeSlotId}`);
      fetchTimeSlots();
    } catch (error) {
      console.error("Error deleting TimeSlot:", error);
    }
  };

  const handleUpdateClick = (timeSlot) => {
    setUpdatingTimeSlot({ ...timeSlot });
  };

  return (
    <div className="time-slot-container">
      <h2>TimeSlots</h2>
      <ul className="time-slot-list">
        {timeSlots.map((timeSlot) => (
          <li key={timeSlot.time_slot_id} className="time-slot-item">
            <div>
              <strong>ID:</strong> {timeSlot.time_slot_id}
            </div>
            <div>
              <strong>Day:</strong> {timeSlot.day}
            </div>
            <div>
              <strong>Time:</strong> {timeSlot.start_time} - {timeSlot.end_time}
            </div>
            <div className="time-slot-buttons">
              <button
                onClick={() => handleUpdateClick(timeSlot)}
                className="update-button"
              >
                Update
              </button>
              <button
                onClick={() => deleteTimeSlot(timeSlot.time_slot_id)}
                className="delete-button"
              >
                Delete
              </button>
            </div>
          </li>
        ))}
      </ul>

      <div className="time-slot-form">
        <h3>Create New TimeSlot</h3>
        <label>
          Time Slot ID:
          <input
            type="text"
            value={newTimeSlot.time_slot_id}
            onChange={(e) =>
              setNewTimeSlot({ ...newTimeSlot, time_slot_id: e.target.value })
            }
          />
        </label>
        <label>
          Day:
          <input
            type="text"
            value={newTimeSlot.day}
            onChange={(e) =>
              setNewTimeSlot({ ...newTimeSlot, day: e.target.value })
            }
          />
        </label>
        <label>
          Start Time:
          <input
            type="datetime-local"
            value={newTimeSlot.start_time}
            onChange={(e) =>
              setNewTimeSlot({ ...newTimeSlot, start_time: e.target.value })
            }
          />
        </label>
        <label>
          End Time:
          <input
            type="datetime-local"
            value={newTimeSlot.end_time}
            onChange={(e) =>
              setNewTimeSlot({ ...newTimeSlot, end_time: e.target.value })
            }
          />
        </label>
        <button onClick={createNewTimeSlot}>Create TimeSlot</button>
      </div>

      {updatingTimeSlot && (
        <div className="time-slot-form">
          <h3>Update TimeSlot</h3>
          <label>
            Time Slot ID:
            <input
              type="text"
              value={updatingTimeSlot.time_slot_id}
              onChange={(e) =>
                setUpdatingTimeSlot({
                  ...updatingTimeSlot,
                  time_slot_id: e.target.value,
                })
              }
            />
          </label>
          <label>
            Day:
            <input
              type="text"
              value={updatingTimeSlot.day}
              onChange={(e) =>
                setUpdatingTimeSlot({
                  ...updatingTimeSlot,
                  day: e.target.value,
                })
              }
            />
          </label>
          <label>
            Start Time:
            <input
              type="datetime-local"
              value={updatingTimeSlot.start_time}
              onChange={(e) =>
                setUpdatingTimeSlot({
                  ...updatingTimeSlot,
                  start_time: e.target.value,
                })
              }
            />
          </label>
          <label>
            End Time:
            <input
              type="datetime-local"
              value={updatingTimeSlot.end_time}
              onChange={(e) =>
                setUpdatingTimeSlot({
                  ...updatingTimeSlot,
                  end_time: e.target.value,
                })
              }
            />
          </label>
          <button onClick={updateExistingTimeSlot}>Update TimeSlot</button>
        </div>
      )}
    </div>
  );
};

export default TimeSlotComponent;
