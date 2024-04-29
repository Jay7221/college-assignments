// api.js
const express = require('express');
const router = express.Router();
const { Department } = require('../models'); // Assuming your Sequelize models are in a 'models' folder

// Create Department
router.post('/departments', async (req, res) => {
    try {
        const department = await Department.create(req.body);
        res.json(department);
    } catch (error) {
        console.error('Error creating department:', error);
        res.status(500).send('Internal Server Error');
    }
});

// Read All Departments
router.get('/departments', async (req, res) => {
    try {
        const departments = await Department.findAll();
        res.json(departments);
    } catch (error) {
        console.error('Error fetching departments:', error);
        res.status(500).send('Internal Server Error');
    }
});

// Update Department
router.put('/departments/:dept_name', async (req, res) => {
    const { dept_name } = req.params;
    try {
        const department = await Department.findByPk(dept_name);
        if (!department) {
            return res.status(404).send('Department not found');
        }
        await department.update(req.body);
        res.json(department);
    } catch (error) {
        console.error('Error updating department:', error);
        res.status(500).send('Internal Server Error');
    }
});

// Delete Department
router.delete('/departments/:dept_name', async (req, res) => {
    const { dept_name } = req.params;
    try {
        const department = await Department.findByPk(dept_name);
        if (!department) {
            return res.status(404).send('Department not found');
        }
        await department.destroy();
        res.send('Department deleted successfully');
    } catch (error) {
        console.error('Error deleting department:', error);
        res.status(500).send('Internal Server Error');
    }
});

module.exports = router;
