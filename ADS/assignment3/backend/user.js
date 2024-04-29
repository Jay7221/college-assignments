// userModel.js

const { DataTypes } = require("sequelize");
const sequelize = require("./db/conn");

const User = sequelize.define("User", {
  username: {
    type: DataTypes.STRING,
    allowNull: false,
    unique: true,
  },
  email: {
    type: DataTypes.STRING,
    allowNull: false,
    unique: true,
  },
  password: {
    type: DataTypes.STRING,
    allowNull: false,
  },
  role: {
    type: DataTypes.ENUM("student", "teacher"),
    allowNull: false,
    defaultValue: "student", // Assuming default role is student
  },
});

module.exports = User;
