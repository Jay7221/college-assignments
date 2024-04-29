// Department.js
import React, { useState, useEffect } from "react";
import api from "./api";
import "./Department.css";

function Department() {
  const [departments, setDepartments] = useState([]);
  const [formData, setFormData] = useState({
    dept_name: "",
    building: "",
    budget: "",
  });
  const [updateMode, setUpdateMode] = useState(false);
  const [updatingDeptName, setUpdatingDeptName] = useState(null);

  useEffect(() => {
    fetchData();
  }, []);

  const fetchData = async () => {
    try {
      const response = await api.get("/departments");
      setDepartments(response.data);
    } catch (error) {
      console.error("Error fetching data:", error);
    }
  };

  const handleInputChange = (e) => {
    const { name, value } = e.target;
    setFormData((prevData) => ({ ...prevData, [name]: value }));
  };

  const handleAddDepartment = async () => {
    try {
      if (updateMode) {
        await api.put(`/departments/${updatingDeptName}`, formData);
        setUpdateMode(false);
        setUpdatingDeptName(null);
      } else {
        await api.post("/departments", formData);
      }
      fetchData();
      setFormData({ dept_name: "", building: "", budget: "" });
    } catch (error) {
      console.error("Error adding/updating department:", error);
    }
  };

  const handleUpdateDepartment = (dept) => {
    setUpdateMode(true);
    setUpdatingDeptName(dept.dept_name);
    setFormData({ ...dept });
  };

  const handleDeleteDepartment = async (deptName) => {
    try {
      await api.delete(`/departments/${deptName}`);
      fetchData();
    } catch (error) {
      console.error("Error deleting department:", error);
    }
  };

  return (
    <div className="department-container">
      <h1>Departments</h1>

      <form className="department-form">
        {/* Input fields for adding/updating a department */}
        <label>
          Department Name:
          <input
            type="text"
            name="dept_name"
            value={formData.dept_name}
            onChange={handleInputChange}
          />
        </label>
        <label>
          Building:
          <input
            type="text"
            name="building"
            value={formData.building}
            onChange={handleInputChange}
          />
        </label>
        <label>
          Budget:
          <input
            type="text"
            name="budget"
            value={formData.budget}
            onChange={handleInputChange}
          />
        </label>
        {/* Button to add/update a department */}
        <button type="button" onClick={handleAddDepartment}>
          {updateMode ? "Update Department" : "Add Department"}
        </button>
      </form>

      <table className="department-table">
        <thead>
          <tr>
            <th>Department Name</th>
            <th>Building</th>
            <th>Budget</th>
            <th>Actions</th>
          </tr>
        </thead>
        <tbody>
          {departments.map((department) => (
            <tr key={department.dept_name}>
              {/* Display form fields if in update mode */}
              {updateMode && updatingDeptName === department.dept_name ? (
                <>
                  <td>
                    <input
                      type="text"
                      name="dept_name"
                      value={formData.dept_name}
                      onChange={handleInputChange}
                    />
                  </td>
                  <td>
                    <input
                      type="text"
                      name="building"
                      value={formData.building}
                      onChange={handleInputChange}
                    />
                  </td>
                  <td>
                    <input
                      type="text"
                      name="budget"
                      value={formData.budget}
                      onChange={handleInputChange}
                    />
                  </td>
                </>
              ) : (
                // Display department details if not in update mode
                <>
                  <td>{department.dept_name}</td>
                  <td>{department.building}</td>
                  <td>{department.budget}</td>
                </>
              )}
              {/* Buttons to update and delete a department */}
              <td>
                {updateMode && updatingDeptName === department.dept_name ? (
                  <button type="button" onClick={handleAddDepartment}>
                    Confirm Update
                  </button>
                ) : (
                  <button
                    type="button"
                    onClick={() => handleUpdateDepartment(department)}
                  >
                    Update
                  </button>
                )}
                <button
                  type="button"
                  onClick={() => handleDeleteDepartment(department.dept_name)}
                >
                  Delete
                </button>
              </td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
}

export default Department;
