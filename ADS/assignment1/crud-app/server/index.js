const express = require("express");
const mysql = require("mysql");
const cors = require("cors");
const dbConfig = require("./dbConfig");

const app = express();
app.use(express.json());
app.use(cors());

const pool = mysql.createPool(dbConfig);

function handleQueryResult(res, err, data) {
    if (err) {
        return res.json({ Error: err.sqlMessage });
    }
    return res.json(data);
}

// Get all databases
function getAllDatabases(req, res) {
    const sql = "SHOW DATABASES;";
    pool.query(sql, (err, data) => handleQueryResult(res, err, data));
}

// Get tables in a database
function getTablesInDatabase(req, res) {
    const database = req.params.database;
    const sql = `SHOW TABLES FROM ${database};`;
    pool.query(sql, (err, data) =>
        handleQueryResult(
            res,
            err,
            data.map((table) => Object.values(table)[0])
        )
    );
}

// Get all rows from a table
function getAllRows(req, res) {
    const { database, table } = req.params;
    const sql = `SELECT * FROM ${database}.${table};`;
    pool.query(sql, (err, data) => handleQueryResult(res, err, data));
}

// Insert a new row into a table
function addRow(req, res) {
    const { database, table } = req.params;
    const newRowData = req.body;
    const columns = Object.keys(newRowData).join(", ");
    const values = Object.values(newRowData)
        .map((value) => (typeof value === "string" ? `'${value}'` : value))
        .join(", ");
    const sql = `INSERT INTO ${database}.${table} (${columns}) VALUES (${values})`;

    pool.query(sql, (err, data) => handleQueryResult(res, err, data));
}

// Delete rows from a table
function deleteRows(req, res) {
    const { database, table } = req.params;
    const rowData = req.body;
    const columns = Object.keys(rowData);
    const values = Object.values(rowData).map((value) =>
        typeof value === "string" ? `'${value}'` : value
    );
    const rowString = columns
        .map((col, index) => `${col}=${values[index]}`)
        .join(" AND ");
    const sql = `DELETE FROM ${database}.${table} WHERE ${rowString};`;

    pool.query(sql, (err, data) => handleQueryResult(res, err, data));
}

// Update a row in a table
function updateRow(req, res) {
    const { database, table } = req.params;
    const oldRowData = req.body.oldData;
    const newRowData = req.body.newData;

    const oldColumns = Object.keys(oldRowData);
    const oldValues = Object.values(oldRowData).map((value) =>
        typeof value === "string" ? `'${value}'` : value
    );

    const oldString = oldColumns
        .map((col, index) => `${col}=${oldValues[index]}`)
        .join(" AND ");

    const newColumns = Object.keys(newRowData);
    const newValues = Object.values(newRowData).map((value) =>
        typeof value === "string" ? `'${value}'` : value
    );
    const newString = newColumns
        .map((col, index) => `${col}=${newValues[index]}`)
        .join(", ");

    const sql = `UPDATE ${database}.${table} SET ${newString} WHERE ${oldString};`;

    pool.query(sql, (err, data) => handleQueryResult(res, err, data));
}

// Get table schema
function getTableSchema(req, res) {
    const { database, table } = req.params;
    const sql = `
    SELECT 
        COLUMN_NAME,
        IS_NULLABLE,
        DATA_TYPE
    FROM information_schema.columns
    WHERE TABLE_SCHEMA = '${database}' AND TABLE_NAME = '${table}';
  `;
    pool.query(sql, (err, data) => handleQueryResult(res, err, data));
}

app.get("/", getAllDatabases);
app.get("/:database", getTablesInDatabase);
app.get("/:database/:table", getAllRows);
app.post("/:database/:table", addRow);
app.delete("/:database/:table", deleteRows);
app.put("/:database/:table", updateRow);
app.get("/:database/:table/schema", getTableSchema);

const PORT = 3001;
app.listen(PORT, () => {
    console.log(`Server is running on port ${PORT}`);
});
