// Login.js

import React, { useState } from "react";
import { loginUser } from "../api/auth/authApi";
import { useNavigate } from "react-router-dom";
import "./Login.css";

function Login() {
  const [email, setEmail] = useState("");
  const [password, setPassword] = useState("");
  const [error, setError] = useState("");
  const navigate = useNavigate();

  const handleLogin = async (event) => {
    event.preventDefault();
    try {
      const data = await loginUser(email, password);
      localStorage.setItem("token", data.token);
      console.log("Login successful: ", data);
      navigate(`/student/${email}`);
    } catch (error) {
      setError("Invalid email or password");
      console.error("Error during login:", error);
    }
  };

  return (
    <div className="container">
      <h2>Login</h2>
      <form onSubmit={handleLogin}>
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
        <button type="submit">Login</button>
        {error && <p className="error-message">{error}</p>}
      </form>
    </div>
  );
}

export default Login;
