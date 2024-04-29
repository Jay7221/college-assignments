// AddCoursePage.js

import React, { useState } from "react";
import axios from "axios";

const AddCoursePage = () => {
  const [courseId, setCourseId] = useState("");
  const [title, setTitle] = useState("");
  const [deptName, setDeptName] = useState("");
  const [credits, setCredits] = useState("");
  const [error, setError] = useState("");

  const handleAddCourse = async (e) => {
    e.preventDefault();

    try {
      // Make API call to add a new course
      await axios.post("http://localhost:3001/api/courses", {
        course_id: courseId,
        title,
        dept_name: deptName,
        credits,
      });

      // Clear the form fields after successful addition
      setCourseId("");
      setTitle("");
      setDeptName("");
      setCredits("");
      setError("");
    } catch (error) {
      console.error("Error adding course:", error);
      setError("An error occurred while adding the course. Please try again.");
    }
  };

  return (
    <div>
      <h2>Add Course</h2>
      <form onSubmit={handleAddCourse}>
        <label>
          Course ID:
          <input
            type="text"
            value={courseId}
            onChange={(e) => setCourseId(e.target.value)}
            required
          />
        </label>
        <label>
          Title:
          <input
            type="text"
            value={title}
            onChange={(e) => setTitle(e.target.value)}
            required
          />
        </label>
        <label>
          Department Name:
          <input
            type="text"
            value={deptName}
            onChange={(e) => setDeptName(e.target.value)}
            required
          />
        </label>
        <label>
          Credits:
          <input
            type="number"
            value={credits}
            onChange={(e) => setCredits(e.target.value)}
            required
          />
        </label>
        <button type="submit">Add Course</button>
      </form>
      {error && <p style={{ color: "red" }}>{error}</p>}
    </div>
  );
};

export default AddCoursePage;
