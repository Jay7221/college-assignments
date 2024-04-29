// Courses.js
import React, { useState, useEffect } from "react";
import api from "./api";
import "./Courses.css";

function Courses() {
  const [courses, setCourses] = useState([]);
  const [formData, setFormData] = useState({
    course_id: "",
    title: "",
    dept_name: "",
    credits: "",
  });
  const [updateMode, setUpdateMode] = useState(false);
  const [updatingCourseId, setUpdatingCourseId] = useState(null);

  useEffect(() => {
    fetchData();
  }, []);

  const fetchData = async () => {
    try {
      const response = await api.get("/courses");
      setCourses(response.data);
    } catch (error) {
      console.error("Error fetching data:", error);
    }
  };

  const handleInputChange = (e) => {
    const { name, value } = e.target;
    setFormData((prevData) => ({ ...prevData, [name]: value }));
  };

  const handleAddCourse = async () => {
    try {
      if (updateMode) {
        await api.put(`/courses/${updatingCourseId}`, formData);
        setUpdateMode(false);
        setUpdatingCourseId(null);
      } else {
        await api.post("/courses", formData);
      }
      fetchData();
      setFormData({ course_id: "", title: "", dept_name: "", credits: "" });
    } catch (error) {
      console.error("Error adding/updating course:", error);
    }
  };

  const handleUpdateCourse = (course) => {
    setUpdateMode(true);
    setUpdatingCourseId(course.course_id);
    setFormData({ ...course });
  };

  const handleDeleteCourse = async (courseId) => {
    try {
      await api.delete(`/courses/${courseId}`);
      fetchData();
    } catch (error) {
      console.error("Error deleting course:", error);
    }
  };

  return (
    <div className="courses-container">
      <h1>Courses</h1>

      <form className="courses-form">
        {/* Input fields for adding/updating a course */}
        <label>
          Course ID:
          <input
            type="text"
            name="course_id"
            value={formData.course_id}
            onChange={handleInputChange}
          />
        </label>
        <label>
          Title:
          <input
            type="text"
            name="title"
            value={formData.title}
            onChange={handleInputChange}
          />
        </label>
        <label>
          Department Name:
          <input
            type="text"
            name="dept_name"
            value={formData.dept_name}
            onChange={handleInputChange}
          />
        </label>
        <label>
          Credits:
          <input
            type="number"
            name="credits"
            value={formData.credits}
            onChange={handleInputChange}
          />
        </label>
        {/* Button to add/update a course */}
        <button type="button" onClick={handleAddCourse}>
          {updateMode ? "Update Course" : "Add Course"}
        </button>
      </form>

      <table className="courses-table">
        <thead>
          <tr>
            <th>Course ID</th>
            <th>Title</th>
            <th>Department Name</th>
            <th>Credits</th>
            <th>Actions</th>
          </tr>
        </thead>
        <tbody>
          {courses.map((course) => (
            <tr key={course.course_id}>
              {/* Display form fields if in update mode */}
              {updateMode && updatingCourseId === course.course_id ? (
                <>
                  <td>
                    <input
                      type="text"
                      name="course_id"
                      value={formData.course_id}
                      onChange={handleInputChange}
                    />
                  </td>
                  <td>
                    <input
                      type="text"
                      name="title"
                      value={formData.title}
                      onChange={handleInputChange}
                    />
                  </td>
                  <td>
                    <input
                      type="text"
                      name="dept_name"
                      value={formData.dept_name}
                      onChange={handleInputChange}
                    />
                  </td>
                  <td>
                    <input
                      type="number"
                      name="credits"
                      value={formData.credits}
                      onChange={handleInputChange}
                    />
                  </td>
                </>
              ) : (
                // Display course details if not in update mode
                <>
                  <td>{course.course_id}</td>
                  <td>{course.title}</td>
                  <td>{course.dept_name}</td>
                  <td>{course.credits}</td>
                </>
              )}
              {/* Buttons to update and delete a course */}
              <td>
                {updateMode && updatingCourseId === course.course_id ? (
                  <button type="button" onClick={handleAddCourse}>
                    Confirm Update
                  </button>
                ) : (
                  <button
                    type="button"
                    onClick={() => handleUpdateCourse(course)}
                  >
                    Update
                  </button>
                )}
                <button
                  type="button"
                  onClick={() => handleDeleteCourse(course.course_id)}
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

export default Courses;
