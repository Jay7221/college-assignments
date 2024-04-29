const express = require("express");
const { Student, Takes } = require("../models");

const router = express.Router();

// API endpoint to get data from the Student table
router.get("/students", async (req, res) => {
  try {
    const students = await Student.findAll();
    res.status(200).json(students);
  } catch (error) {
    console.error("Error fetching data from Student:", error);
    res.status(500).send("Internal Server Error");
  }
});

// API endpoint to add data to the Student table
router.post("/students", async (req, res) => {
  try {
    const { ID, name, dept_name, tot_cred } = req.body;
    const newStudent = await Student.create({
      ID,
      name,
      dept_name,
      tot_cred,
    });
    res.status(201).json(newStudent);
  } catch (error) {
    console.error("Error adding data to Student:", error);
    res.status(500).send("Internal Server Error");
  }
});

// Get currently taken courses for a student
router.get("/student/:studentId/courses", async (req, res) => {
  const studentId = req.params.studentId;

  try {
    const student = await Student.findByPk(studentId, {
      include: {
        model: Takes,
        attributes: ["course_id", "sec_id", "semester", "year", "grade"],
      },
    });

    if (!student) {
      return res.status(404).json({ error: "Student not found" });
    }

    const currentlyTakenCourses = student.Takes.map((takes) => takes.toJSON());
    return res.json(currentlyTakenCourses);
  } catch (error) {
    console.error("Error fetching currently taken courses:", error);
    return res.status(500).json({ error: "Internal Server Error" });
  }
});

// Add a course for a student
router.post("/student/:studentId/courses", async (req, res) => {
  const studentId = req.params.studentId;
  const { course_id, sec_id, semester, year, grade } = {
    ...req.body,
    sec_id: "",
    semester: "2",
    year: 2021,
    grade: "A",
  };

  try {
    // Check if the student exists
    const student = await Student.findByPk(studentId);

    if (!student) {
      return res.status(404).json({ error: "Student not found" });
    }

    // Add logic to create a Takes entry
    await Takes.create({
      ID: studentId,
      course_id,
      sec_id,
      semester,
      year,
      grade,
    });

    return res.json({ success: true });
  } catch (error) {
    console.error("Error adding course:", error);
    return res.status(500).json({ error: "Internal Server Error" });
  }
});

// Delete a course for a student
router.delete("/student/:studentId/:course_id", async (req, res) => {
  const { studentId, course_id } = req.params;

  try {
    // Check if the student and Takes entry exist
    const student = await Student.findByPk(studentId);
    const takesEntry = await Takes.findOne({
      where: { ID: studentId, course_id },
    });

    if (!student || !takesEntry) {
      return res.status(404).json({ error: "Student or course not found" });
    }

    // Add logic to delete the Takes entry
    await takesEntry.destroy();

    return res.json({ success: true });
  } catch (error) {
    console.error("Error deleting course:", error);
    return res.status(500).json({ error: "Internal Server Error" });
  }
});

module.exports = router;
