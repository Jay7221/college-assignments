// components/auth/Signup.js

import React, { useState } from "react";
import { registerUser } from "../api/auth/authApi";
import { useNavigate } from "react-router-dom";
import "./Signup.css";

function Signup() {
  const [username, setUsername] = useState("");
  const [email, setEmail] = useState("");
  const [password, setPassword] = useState("");
  const [role, setRole] = useState("student"); // Default role is 'student'
  const [error, setError] = useState("");
  const navigate = useNavigate();

  const handleSignup = async (event) => {
    event.preventDefault();
    try {
      // Call the registerUser function from the authApi with username, email, password, and role
      const data = await registerUser(username, email, password, role);

      localStorage.setItem("token", data.token);
      console.log("Signup successful: ", data);
      navigate(`/student/${email}`);
      // Redirect to the login page after successful signup
    } catch (error) {
      setError("Error signing up");
      console.error("Error during signup:", error);
    }
  };

  return (
    <div className="container">
      <h2>Signup</h2>
      <form onSubmit={handleSignup}>
        <div className="form-group">
          <label>Email:</label>
          <input
            type="text"
            value={username}
            onChange={(e) => setUsername(e.target.value)}
          />
        </div>
        <div className="form-group">
          <label>Username:</label>
          <input
            type="text"
            value={email}
            onChange={(e) => setEmail(e.target.value)}
          />
        </div>
        <div className="form-group">
          <label>Password:</label>
          <input
            type="password"
            value={password}
            onChange={(e) => setPassword(e.target.value)}
          />
        </div>
        <div className="form-group">
          <label>Role:</label>
          <select value={role} onChange={(e) => setRole(e.target.value)}>
            <option value="student">Student</option>
            <option value="teacher">Teacher</option>
          </select>
        </div>
        <button type="submit">Signup</button>
        {error && <p className="error-message">{error}</p>}
      </form>
    </div>
  );
}

export default Signup;
