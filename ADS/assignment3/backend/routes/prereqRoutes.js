const express = require("express");
const { Prereq } = require("../models");

const router = express.Router();

// API endpoint to get data from the Prereq table
router.get("/prereqs", async (req, res) => {
  try {
    const prereqs = await Prereq.findAll();
    res.status(200).json(prereqs);
  } catch (error) {
    console.error("Error fetching data from Prereq:", error);
    res.status(500).send("Internal Server Error");
  }
});

// API endpoint to add data to the Prereq table
router.post("/prereqs", async (req, res) => {
  try {
    const { course_id, prereq_id } = req.body;
    const newPrereq = await Prereq.create({
      course_id,
      prereq_id,
    });
    res.status(201).json(newPrereq);
  } catch (error) {
    console.error("Error adding data to Prereq:", error);
    res.status(500).send("Internal Server Error");
  }
});

module.exports = router;
