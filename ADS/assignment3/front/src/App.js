// App.js

import React from "react";
import { BrowserRouter as Router, Route, Routes } from "react-router-dom";
import Login from "./components/Login";
import Department from "./components/Department";
import Classroom from "./components/Classroom";
import Signup from "./components/Signup";
import StudentDashboard from "./components/StudentDashboard";
import Courses from "./components/Courses";
import TimeSlot from "./components/TimeSlot";

const App = () => {
  return (
    <Router>
      <Routes>
        <Route path="/" element={<Login />} />
        <Route path="/signup" element={<Signup />} />
        <Route path="/student/:studentId/*" element={<StudentDashboard />} />
        <Route path="/classrooms" element={<Classroom />} />
        <Route path="/departments" element={<Department />} />
        <Route path="/courses" element={<Courses />} />
        <Route path="/timeslots" element={<TimeSlot />} />
      </Routes>
    </Router>
  );
};

export default App;
