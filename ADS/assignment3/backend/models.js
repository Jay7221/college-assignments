// models.js
const { DataTypes } = require("sequelize");
const sequelize = require("./database");

const Classroom = sequelize.define("Classroom", {
  building: {
    type: DataTypes.STRING(30),
    primaryKey: true,
  },
  room_number: {
    type: DataTypes.INTEGER,
    primaryKey: true,
  },
  capacity: {
    type: DataTypes.INTEGER,
  },
});

const Department = sequelize.define("Department", {
  dept_name: {
    type: DataTypes.STRING(30),
    primaryKey: true,
  },
  building: {
    type: DataTypes.STRING(30),
  },
  budget: {
    type: DataTypes.DECIMAL(10, 2),
  },
});

const TimeSlot = sequelize.define("TimeSlot", {
  time_slot_id: {
    type: DataTypes.STRING(30),
    primaryKey: true,
  },
  day: {
    type: DataTypes.STRING(30),
  },
  start_time: {
    type: DataTypes.TIME,
  },
  end_time: {
    type: DataTypes.TIME,
  },
});

const Course = sequelize.define("Course", {
  course_id: {
    type: DataTypes.STRING(30),
    primaryKey: true,
  },
  title: {
    type: DataTypes.STRING(30),
  },
  dept_name: {
    type: DataTypes.STRING(30),
  },
  credits: {
    type: DataTypes.INTEGER,
  },
});

const Instructor = sequelize.define("Instructor", {
  ID: {
    type: DataTypes.STRING(30),
    primaryKey: true,
  },
  name: {
    type: DataTypes.STRING(30),
  },
  dept_name: {
    type: DataTypes.STRING(30),
  },
  salary: {
    type: DataTypes.DECIMAL(10, 2),
  },
  password: {
    type: DataTypes.STRING(30),
  },
});

const Section = sequelize.define("Section", {
  course_id: {
    type: DataTypes.STRING(30),
    primaryKey: true,
  },
  sec_id: {
    type: DataTypes.STRING(30),
    primaryKey: true,
  },
  semester: {
    type: DataTypes.STRING(30),
    primaryKey: true,
  },
  year: {
    type: DataTypes.INTEGER,
    primaryKey: true,
  },
  building: {
    type: DataTypes.STRING(30),
  },
  room_number: {
    type: DataTypes.INTEGER,
  },
  time_slot_id: {
    type: DataTypes.STRING(30),
  },
});

const Teaches = sequelize.define("Teaches", {
  ID: {
    type: DataTypes.STRING(30),
    primaryKey: true,
  },
  course_id: {
    type: DataTypes.STRING(30),
    primaryKey: true,
  },
  sec_id: {
    type: DataTypes.STRING(30),
    primaryKey: true,
  },
  semester: {
    type: DataTypes.STRING(30),
    primaryKey: true,
  },
  year: {
    type: DataTypes.INTEGER,
    primaryKey: true,
  },
});

const Student = sequelize.define("Student", {
  ID: {
    type: DataTypes.STRING(30),
    primaryKey: true,
  },
  name: {
    type: DataTypes.STRING(30),
  },
  dept_name: {
    type: DataTypes.STRING(30),
  },
  tot_cred: {
    type: DataTypes.INTEGER,
  },
  password: {
    type: DataTypes.STRING(30),
  },
});

const Takes = sequelize.define("Takes", {
  ID: {
    type: DataTypes.STRING(30),
    primaryKey: true,
  },
  course_id: {
    type: DataTypes.STRING(30),
    primaryKey: true,
  },
  sec_id: {
    type: DataTypes.STRING(30),
    primaryKey: true,
  },
  semester: {
    type: DataTypes.STRING(30),
    primaryKey: true,
  },
  year: {
    type: DataTypes.INTEGER,
    primaryKey: true,
  },
  grade: {
    type: DataTypes.STRING(30),
  },
});

const Advisor = sequelize.define("Advisor", {
  s_ID: {
    type: DataTypes.STRING(30),
    primaryKey: true,
  },
  i_ID: {
    type: DataTypes.STRING(30),
  },
});

const Prereq = sequelize.define("Prereq", {
  course_id: {
    type: DataTypes.STRING(30),
    primaryKey: true,
  },
  prereq_id: {
    type: DataTypes.STRING(30),
    primaryKey: true,
  },
});

// Define associations
Classroom.hasMany(Section, { foreignKey: "building", sourceKey: "building" });
Section.belongsTo(Classroom, { foreignKey: "building", targetKey: "building" });

Department.hasMany(Course, { foreignKey: "dept_name", sourceKey: "dept_name" });
Course.belongsTo(Department, {
  foreignKey: "dept_name",
  targetKey: "dept_name",
});

Instructor.hasMany(Teaches, { foreignKey: "ID", sourceKey: "ID" });
Teaches.belongsTo(Instructor, { foreignKey: "ID", targetKey: "ID" });

Instructor.hasOne(Advisor, { foreignKey: "i_ID", sourceKey: "ID" });
Advisor.belongsTo(Instructor, { foreignKey: "i_ID", targetKey: "ID" });

Student.hasOne(Advisor, { foreignKey: "s_ID", sourceKey: "ID" });
Advisor.belongsTo(Student, { foreignKey: "s_ID", targetKey: "ID" });

Student.hasMany(Takes, { foreignKey: "ID", sourceKey: "ID" });
Takes.belongsTo(Student, { foreignKey: "ID", targetKey: "ID" });

Course.hasMany(Takes, { foreignKey: "course_id", sourceKey: "course_id" });
Takes.belongsTo(Course, { foreignKey: "course_id", targetKey: "course_id" });

Course.hasMany(Prereq, { foreignKey: "course_id", sourceKey: "course_id" });
Prereq.belongsTo(Course, { foreignKey: "course_id", targetKey: "course_id" });

Course.hasMany(Prereq, { foreignKey: "prereq_id", sourceKey: "course_id" });
Prereq.belongsTo(Course, { foreignKey: "prereq_id", targetKey: "course_id" });

Section.hasMany(Teaches, {
  foreignKey: ["course_id", "sec_id", "semester", "year"],
});
Teaches.belongsTo(Section, {
  foreignKey: ["course_id", "sec_id", "semester", "year"],
});

// Synchronize the model with the database
sequelize
  .sync()
  .then("Table create successfully")
  .catch((error) => console.log(`Error occured:${error}`));

module.exports = {
  Classroom,
  Department,
  TimeSlot,
  Course,
  Instructor,
  Section,
  Teaches,
  Student,
  Takes,
  Advisor,
  Prereq,
};
