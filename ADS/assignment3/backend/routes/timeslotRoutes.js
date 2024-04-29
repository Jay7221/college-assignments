// timeslotRoutes.js
const express = require('express');
const router = express.Router();
const { TimeSlot } = require('../models');

// Create TimeSlot
router.post('/', async (req, res) => {
    const newTimeSlotData = req.body;

    try {
        const newTimeSlot = await TimeSlot.create(newTimeSlotData);
        res.status(201).json(newTimeSlot);
    } catch (error) {
        console.error('Error creating timeslot:', error);
        res.status(500).send('Internal Server Error');
    }
});

// Read All TimeSlots
router.get('/', async (req, res) => {
    try {
        const allTimeSlots = await TimeSlot.findAll();
        res.status(200).json(allTimeSlots);
    } catch (error) {
        console.error('Error fetching timeslots:', error);
        res.status(500).send('Internal Server Error');
    }
});

// Read Single TimeSlot
router.get('/:time_slot_id', async (req, res) => {
    const { time_slot_id } = req.params;

    try {
        const timeSlot = await TimeSlot.findByPk(time_slot_id);
        if (timeSlot) {
            res.status(200).json(timeSlot);
        } else {
            res.status(404).send('TimeSlot not found.');
        }
    } catch (error) {
        console.error('Error fetching timeslot:', error);
        res.status(500).send('Internal Server Error');
    }
});

// Update TimeSlot
router.put('/:time_slot_id', async (req, res) => {
    const { time_slot_id } = req.params;
    const updatedTimeSlotData = req.body;

    try {
        const timeSlot = await TimeSlot.findByPk(time_slot_id);
        if (timeSlot) {
            await timeSlot.update(updatedTimeSlotData);
            res.status(200).send('TimeSlot updated successfully.');
        } else {
            res.status(404).send('TimeSlot not found.');
        }
    } catch (error) {
        console.error('Error updating timeslot:', error);
        res.status(500).send('Internal Server Error');
    }
});

// Delete TimeSlot
router.delete('/:time_slot_id', async (req, res) => {
    const { time_slot_id } = req.params;

    try {
        const timeSlot = await TimeSlot.findByPk(time_slot_id);
        if (timeSlot) {
            await timeSlot.destroy();
            res.status(204).send();
        } else {
            res.status(404).send('TimeSlot not found.');
        }
    } catch (error) {
        console.error('Error deleting timeslot:', error);
        res.status(500).send('Internal Server Error');
    }
});

module.exports = router;
