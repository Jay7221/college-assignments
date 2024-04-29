const express = require("express");
const bcrypt = require("bcryptjs");
const jwt = require("jsonwebtoken");
const config = require("../config/config");
const User = require("../user");

const router = express.Router();

router.post("/signup", async (req, res) => {
  const { username, email, password, role } = req.body;

  try {
    const existingUser = await User.findOne({ where: { email } });

    if (existingUser) {
      return res.status(400).json({ message: "User already exists" });
    }

    const salt = await bcrypt.genSalt(10);
    const hashedPassword = await bcrypt.hash(password, salt);

    const newUser = await User.create({
      username,
      email,
      password: hashedPassword,
      role,
    });
    const payload = {
      user: {
        id: newUser.id,
        role: newUser.role,
      },
    };

    jwt.sign(payload, config.jwtSecret, { expiresIn: "1h" }, (error, token) => {
      if (error) throw error;
      res.json({ token });
    });
  } catch (error) {
    console.log(`Signup error: ${error}`);
    res.status(500).json({ message: "Server error" });
  }
});

router.post("/login", async (req, res) => {
  const { email, password } = req.body;

  try {
    const user = await User.findOne({ where: { email } });
    if (!user) {
      return res.status(404).json({ message: "User not found" });
    }
    const isMatch = await bcrypt.compare(password, user.password);
    if (!isMatch) {
      return res.status(401).json({ message: "Invalid credentials" });
    }
    const payload = {
      user: {
        id: user.id,
        role: user.role,
      },
    };

    jwt.sign(payload, config.jwtSecret, { expiresIn: "1h" }, (error, token) => {
      if (error) throw error;
      res.json({ token });
    });
  } catch (error) {
    console.log(`Login error: ${error}`);
    res.status(500).json({ message: "Server error" });
  }
});

module.exports = router;
