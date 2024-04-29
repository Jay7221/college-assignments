import React from "react";
import { Link } from "react-router-dom";
import "./Navbar.css";

const Navbar = () => {
  return (
    <nav>
      <ul>
        <li>
          <Link to="/classrooms">Classrooms</Link>
        </li>
        <li>
          <Link to="/departments">Departments</Link>
        </li>
        <li>
          <Link to="/courses">Courses</Link>
        </li>
        <li>
          <Link to="/timeslots">Time Slots</Link>
        </li>
      </ul>
    </nav>
  );
};

export default Navbar;
