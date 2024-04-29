// src/db.js

const DB_HOST = "192.168.43.225";
const DB_PORT = 3306;
const DB_USER = "root";
const DB_PASSWORD = "Jay@1234";

const API_URL = `http://${DB_HOST}:${DB_PORT}`;

export const fetchTables = async () => {
  console.log("Requesting tables ...");
  const response = await fetch(`${API_URL}/tables`, {
    headers: {
      Authorization: `Basic ${btoa(`${DB_USER}:${DB_PASSWORD}`)}`,
    },
  });
  console.log(`Got response: ${response}`);
  const data = await response.json();
  return data;
};

export const fetchTableData = async (tableName) => {
  const response = await fetch(`${API_URL}/table/${tableName}`, {
    headers: {
      Authorization: `Basic ${btoa(`${DB_USER}:${DB_PASSWORD}`)}`,
    },
  });
  const data = await response.json();
  return data;
};

// Add functions for CRUD operations (create, update, delete) as needed
