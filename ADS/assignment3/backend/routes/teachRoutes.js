const express = require("express");
const { Teaches } = require("../models");

const router = express.Router();

// API endpoint to get data from the Teaches table
router.get("/teaches", async (req, res) => {
  try {
    const teaches = await Teaches.findAll();
    res.status(200).json(teaches);
  } catch (error) {
    console.error("Error fetching data from Teaches:", error);
    res.status(500).send("Internal Server Error");
  }
});

// API endpoint to add data to the Teaches table
router.post("/teaches", async (req, res) => {
  try {
    const { ID, course_id, sec_id, semester, year } = req.body;
    const newTeaches = await Teaches.create({
      ID,
      course_id,
      sec_id,
      semester,
      year,
    });
    res.status(201).json(newTeaches);
  } catch (error) {
    console.error("Error adding data to Teaches:", error);
    res.status(500).send("Internal Server Error");
  }
});
module.exports = router;
