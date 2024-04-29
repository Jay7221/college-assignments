// StudentDashboard.js
import React, { useState, useEffect } from "react";
import api from "./api";
import "./StudentDashboard.css";
import { useParams } from "react-router-dom";
import Navbar from "./Navbar";

function StudentDashboard() {
  const [currentlyTakenCourses, setCurrentlyTakenCourses] = useState([]);
  const [allCourses, setAllCourses] = useState([]);
  const { studentId } = useParams();

  useEffect(() => {
    fetchStudentData();
    fetchAllCourses();
  }, [studentId]);

  const fetchStudentData = async () => {
    try {
      const response = await api.get(`/student/${studentId}/courses`);
      setCurrentlyTakenCourses(response.data);
    } catch (error) {
      console.error("Error fetching student data:", error);
    }
  };

  const fetchAllCourses = async () => {
    try {
      const response = await api.get("/courses");
      setAllCourses(response.data);
    } catch (error) {
      console.error("Error fetching all courses:", error);
    }
  };

  const handleAddCourse = async (courseId) => {
    try {
      await api.post(`/student/${studentId}/courses`, { course_id: courseId });
      fetchStudentData();
    } catch (error) {
      console.error("Error adding course:", error);
    }
  };

  const handleDeleteCourse = async (courseId) => {
    try {
      await api.delete(`/student/${studentId}/${courseId}`);
      fetchStudentData();
    } catch (error) {
      console.error("Error deleting course:", error);
    }
  };

  return (
    <div className="student-dashboard-container">
      <Navbar />
      <h1>Student Dashboard</h1>

      <div className="currently-taken-courses">
        <h2>Currently Taken Courses</h2>
        <table>
          <thead>
            <tr>
              <th>Course ID</th>
              <th>Action</th>
            </tr>
          </thead>
          <tbody>
            {currentlyTakenCourses.map((course) => (
              <tr key={course.course_id}>
                <td>{course.course_id}</td>
                <td>
                  <button onClick={() => handleDeleteCourse(course.course_id)}>
                    Drop Course
                  </button>
                </td>
              </tr>
            ))}
          </tbody>
        </table>
      </div>

      <div className="all-courses">
        <h2>All Courses</h2>
        <table>
          <thead>
            <tr>
              <th>Course ID</th>
              <th>Title</th>
              <th>Action</th>
            </tr>
          </thead>
          <tbody>
            {allCourses.map((course) => (
              <tr key={course.course_id}>
                <td>{course.course_id}</td>
                <td>{course.title}</td>
                <td>
                  <button onClick={() => handleAddCourse(course.course_id)}>
                    Add Course
                  </button>
                </td>
              </tr>
            ))}
          </tbody>
        </table>
      </div>
    </div>
  );
}

export default StudentDashboard;
