const express = require("express");
const { Instructor } = require("../models");

const router = express.Router();

// API endpoint to get data from the Instructor table
router.get("/instructors", async (req, res) => {
  try {
    const instructors = await Instructor.findAll();
    res.status(200).json(instructors);
  } catch (error) {
    console.error("Error fetching data from Instructor:", error);
    res.status(500).send("Internal Server Error");
  }
});

// API endpoint to add data to the Instructor table
router.post("/instructors", async (req, res) => {
  try {
    const { ID, name, dept_name, salary } = req.body;
    const newInstructor = await Instructor.create({
      ID,
      name,
      dept_name,
      salary,
    });
    res.status(201).json(newInstructor);
  } catch (error) {
    console.error("Error adding data to Instructor:", error);
    res.status(500).send("Internal Server Error");
  }
});

module.exports = router;
