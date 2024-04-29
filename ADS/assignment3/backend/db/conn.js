// database.js

const Sequelize = require("sequelize");
const config = require("../config/config");

const sequelize = new Sequelize("ads_sample", "root", "Jay@1234", {
  host: "localhost",
  dialect: "mysql",
});

sequelize
  .authenticate()
  .then(() => {
    console.log("Connection has been established successfully.");
  })
  .catch((error) => {
    console.log("Unable to connect to the database: ", error);
  });

// Sync Sequelize models with the database
sequelize
  .sync({ force: config.forceSync })
  .then(() => {
    console.log("Database synced");
  })
  .catch((err) => {
    console.error("Error syncing database:", err);
  });

module.exports = sequelize;
