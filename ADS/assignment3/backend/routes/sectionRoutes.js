const express = require("express");
const { Section } = require("../models");
const { route } = require("./classroomRoutes");

const router = express.Router();

// API endpoint to get data from the Section table
router.get("/sections", async (req, res) => {
  try {
    const sections = await Section.findAll();
    res.status(200).json(sections);
  } catch (error) {
    console.error("Error fetching data from Section:", error);
    res.status(500).send("Internal Server Error");
  }
});

// API endpoint to add data to the Section table
router.post("/sections", async (req, res) => {
  try {
    const {
      course_id,
      sec_id,
      semester,
      year,
      building,
      room_number,
      time_slot_id,
    } = req.body;
    const newSection = await Section.create({
      course_id,
      sec_id,
      semester,
      year,
      building,
      room_number,
      time_slot_id,
    });
    res.status(201).json(newSection);
  } catch (error) {
    console.error("Error adding data to Section:", error);
    res.status(500).send("Internal Server Error");
  }
});

module.exports = router;
