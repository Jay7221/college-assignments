const express = require("express");
const { Takes } = require("../models");

const router = express.Router();

// API endpoint to get data from the Takes table
router.get("/takes", async (req, res) => {
  try {
    const takes = await Takes.findAll();
    res.status(200).json(takes);
  } catch (error) {
    console.error("Error fetching data from Takes:", error);
    res.status(500).send("Internal Server Error");
  }
});

// API endpoint to add data to the Takes table
router.post("/takes", async (req, res) => {
  try {
    const { ID, course_id, sec_id, semester, year, grade } = req.body;
    const newTakes = await Takes.create({
      ID,
      course_id,
      sec_id,
      semester,
      year,
      grade,
    });
    res.status(201).json(newTakes);
  } catch (error) {
    console.error("Error adding data to Takes:", error);
    res.status(500).send("Internal Server Error");
  }
});

module.exports = router;
