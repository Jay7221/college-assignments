const express = require("express");
const { Classroom } = require("../models");

const router = express.Router();

// GET all classrooms
router.get('/classrooms', async (req, res) => {
    try {
        const classrooms = await Classroom.findAll();
        res.status(200).json(classrooms);
    } catch (error) {
        console.error('Error fetching classrooms:', error);
        res.status(500).send('Internal Server Error');
    }
});

module.exports = router;

// POST new classroom
router.post('/classrooms', async (req, res) => {
    const { building, room_number, capacity } = req.body;
    console.log(`Building:${building}, room:${room_number}, cap:${capacity}`);
    try {
        const newClassroom = await Classroom.create({
            building,
            room_number,
            capacity,
        });
        res.status(201).json(newClassroom);
    } catch (error) {
        console.error('Error adding classroom:', error);
        res.status(500).send('Internal Server Error');
    }
});


// Update Classroom endpoint
router.put('/classrooms/:building', async (req, res) => {
    const { building } = req.params;
    const updatedClassroomData = req.body;

    try {
        // Find the classroom by building
        const classroom = await Classroom.findByPk(building);

        // If the classroom is found, update its data
        if (classroom) {
            await classroom.update(updatedClassroomData);
            res.status(200).send('Classroom updated successfully.');
        } else {
            res.status(404).send('Classroom not found.');
        }
    } catch (error) {
        console.error('Error updating classroom:', error);
        res.status(500).send('Internal Server Error');
    }
});

// DELETE classroom by building and room_number
router.delete('/classrooms/:building/:room_number', async (req, res) => {
    const { building, room_number } = req.params;
    try {
        const deletedRowCount = await Classroom.destroy({
            where: { building, room_number },
        });
        if (deletedRowCount > 0) {
            res.status(200).send('Classroom deleted successfully');
        } else {
            res.status(404).send('Classroom not found');
        }
    } catch (error) {
        console.error('Error deleting classroom:', error);
        res.status(500).send('Internal Server Error');
    }
});

module.exports = router;



module.exports = router;
