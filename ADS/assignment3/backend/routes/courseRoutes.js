const express = require("express");
const { Course } = require("../models");

const router = express.Router();

// API endpoint to get data from the Course table
router.get("/courses", async (req, res) => {
  try {
    const courses = await Course.findAll();
    res.status(200).json(courses);
  } catch (error) {
    console.error("Error fetching data from Course:", error);
    res.status(500).send("Internal Server Error");
  }
});

// API endpoint to add data to the Course table
router.post("/courses", async (req, res) => {
  try {
    const { course_id, title, dept_name, credits } = req.body;
    const newCourse = await Course.create({
      course_id,
      title,
      dept_name,
      credits,
    });
    res.status(201).json(newCourse);
  } catch (error) {
    console.error("Error adding data to Course:", error);
    res.status(500).send("Internal Server Error");
  }
});

module.exports = router;
