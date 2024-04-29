const Sequelize = require("sequelize");
const sequelize = new Sequelize("ads_sample", "root", "Jay@1234", {
  host: "localhost",
  dialect: "mysql",
});

module.exports = sequelize;
