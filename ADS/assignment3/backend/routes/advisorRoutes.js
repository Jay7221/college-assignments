const express = require("express");
const { Advisor } = require("../models");

const router = express.Router();

// API endpoint to get data from the Advisor table
router.get("/advisors", async (req, res) => {
  try {
    const advisors = await Advisor.findAll();
    res.status(200).json(advisors);
  } catch (error) {
    console.error("Error fetching data from Advisor:", error);
    res.status(500).send("Internal Server Error");
  }
});

// API endpoint to add data to the Advisor table
router.post("/advisors", async (req, res) => {
  try {
    const { s_ID, i_ID } = req.body;
    const newAdvisor = await Advisor.create({
      s_ID,
      i_ID,
    });
    res.status(201).json(newAdvisor);
  } catch (error) {
    console.error("Error adding data to Advisor:", error);
    res.status(500).send("Internal Server Error");
  }
});

module.exports = router;
