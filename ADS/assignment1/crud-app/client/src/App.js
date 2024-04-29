import React, { useState, useEffect } from "react";
import axios from "axios";
import "./App.css"; // Import the CSS file

const App = () => {
  const [databases, setDatabases] = useState([]);
  const [selectedDatabase, setSelectedDatabase] = useState("");
  const [tables, setTables] = useState([]);
  const [selectedTable, setSelectedTable] = useState("");
  const [rows, setRows] = useState([]);
  const [formData, setFormData] = useState({});
  const [oldData, setOldData] = useState(null);

  useEffect(() => {
    // Fetch the list of databases on component mount
    fetchDatabases();
  }, []);

  useEffect(() => {
    // Fetch tables when a database is selected
    if (selectedDatabase) {
      setSelectedTable("");
      fetchTables(selectedDatabase);
    }
  }, [selectedDatabase]);

  useEffect(() => {
    // Fetch rows when a table is selected
    if (selectedTable) {
      fetchRows(selectedDatabase, selectedTable);
    }
  }, [selectedTable, selectedDatabase]);

  const fetchDatabases = async () => {
    try {
      const response = await axios.get("http://localhost:3001/");
      setDatabases(response.data);
    } catch (error) {
      console.error("Error fetching databases:", error);
    }
  };

  const fetchTables = async (database) => {
    try {
      const response = await axios.get(`http://localhost:3001/${database}`);
      setTables(response.data);
    } catch (error) {
      console.error("Error fetching tables:", error);
    }
  };

  const fetchRows = async (database, table) => {
    try {
      const response = await axios.get(
        `http://localhost:3001/${database}/${table}`
      );
      setRows(response.data);
      fetchTableSchema();
    } catch (error) {
      console.error("Error fetching rows:", error);
    }
  };

  const fetchTableSchema = async () => {
    try {
      const response = await axios.get(
        `http://localhost:3001/${selectedDatabase}/${selectedTable}/schema`
      );
      const schema = response.data;

      // Initialize form data with default values
      const defaultFormData = {};
      schema.forEach((column) => {
        defaultFormData[column.COLUMN_NAME] =
          column.DATA_TYPE === "varchar" ? "" : 0;
      });
      setFormData(defaultFormData);
    } catch (error) {
      console.error("Error fetching table schema:", error);
    }
  };

  const handleInputChange = (columnName, value) => {
    setFormData((prevFormData) => ({ ...prevFormData, [columnName]: value }));
  };

  const handleCreate = async (rowData) => {
    try {
      await axios.post(
        `http://localhost:3001/${selectedDatabase}/${selectedTable}`,
        rowData
      );
      // Refresh rows after creating a new one
      fetchRows(selectedDatabase, selectedTable);
    } catch (error) {
      console.error("Error creating row:", error);
    }
  };

  const handleUpdate = async (oldData, newData) => {
    try {
      await axios.put(
        `http://localhost:3001/${selectedDatabase}/${selectedTable}`,
        {
          oldData: oldData,
          newData: newData,
        }
      );
      // Refresh rows after updating
      fetchRows(selectedDatabase, selectedTable);
    } catch (error) {
      console.error("Error updating row:", error);
    }
  };

  const handleDelete = async (rowData) => {
    try {
      await axios.delete(
        `http://localhost:3001/${selectedDatabase}/${selectedTable}`,
        { data: rowData }
      );
      // Refresh rows after deleting
      fetchRows(selectedDatabase, selectedTable);
    } catch (error) {
      console.error("Error deleting row:", error);
    }
  };

  return (
    <div className="app-container">
      <h1>Database Viewer</h1>
      <div className="select-container">
        <label>Select Database:</label>
        <select
          value={selectedDatabase}
          onChange={(e) => setSelectedDatabase(e.target.value)}
        >
          <option value="">-- Select Database --</option>
          {databases.map((db) => (
            <option key={db.Database} value={db.Database}>
              {db.Database}
            </option>
          ))}
        </select>
      </div>
      <div>
        <label>Select Table:</label>
        <select
          value={selectedTable}
          onChange={(e) => setSelectedTable(e.target.value)}
        >
          <option value="">-- Select Table --</option>
          {tables.map((table) => (
            <option key={table} value={table}>
              {table}
            </option>
          ))}
        </select>
      </div>
      {selectedTable && (
        <div>
          <h2>Rows in {selectedTable}</h2>
          <table className="data-table">
            <thead>
              <tr>
                {rows.length > 0 &&
                  Object.keys(rows[0]).map((column) => (
                    <th key={column}>{column}</th>
                  ))}
                <th>Actions</th>
              </tr>
            </thead>
            <tbody>
              {rows.map((row, index) => (
                <tr key={index}>
                  {Object.entries(row).map(([columnName, value]) => (
                    <td key={columnName}>{value}</td>
                  ))}
                  <td>
                    <button
                      onClick={() => {
                        setOldData(row);
                        setFormData(row);
                      }}
                    >
                      Update
                    </button>
                    <button onClick={() => handleDelete(row)}>Delete</button>
                  </td>
                </tr>
              ))}
            </tbody>
          </table>
        </div>
      )}

      {selectedTable && (
        <div>
          <h2>{`Form for ${selectedTable}`}</h2>
          <form>
            {Object.entries(formData).map(([columnName, value]) => (
              <div key={columnName}>
                <label>{columnName}:</label>
                {typeof value === "string" ? (
                  <input
                    type="text"
                    value={value}
                    onChange={(e) =>
                      handleInputChange(columnName, e.target.value)
                    }
                  />
                ) : (
                  <input
                    type="number"
                    value={value}
                    onChange={(e) =>
                      handleInputChange(columnName, Number(e.target.value))
                    }
                  />
                )}
              </div>
            ))}
            {oldData ? (
              <button
                type="button"
                onClick={() => handleUpdate(oldData, formData)}
              >
                Update
              </button>
            ) : (
              <button type="button" onClick={() => handleCreate(formData)}>
                Create
              </button>
            )}
          </form>
        </div>
      )}
    </div>
  );
};

export default App;
