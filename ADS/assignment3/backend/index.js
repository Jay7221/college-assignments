const express = require("express");
const cors = require("cors");
const bodyParser = require("body-parser");
const classroomRoutes = require("./routes/classroomRoutes");
const departmentRoutes = require("./routes/departmentRoutes");
const courseRoutes = require("./routes/courseRoutes");
const advisorRoutes = require("./routes/advisorRoutes");
const instructorRoutes = require("./routes/instructorRoutes");
const prereqRoutes = require("./routes/prereqRoutes");
const sectionRoutes = require("./routes/sectionRoutes");
const studentRoutes = require("./routes/studentRoutes");
const takesRoutes = require("./routes/takesRoutes");
const teachRoutes = require("./routes/teachRoutes");
const timeslotRoutes = require("./routes/timeslotRoutes");
const authRoutes = require("./routes/authRoutes");

const app = express();
const PORT = 3001;

app.use(bodyParser.json());
app.use(cors());

app.use("/api", classroomRoutes);
app.use("/api", departmentRoutes);
app.use("/api", courseRoutes);
app.use("/api", advisorRoutes);
app.use("/api", instructorRoutes);
app.use("/api", prereqRoutes);
app.use("/api", sectionRoutes);
app.use("/api", studentRoutes);
app.use("/api", takesRoutes);
app.use("/api", teachRoutes);
app.use("/api/timeslots", timeslotRoutes);
app.use("/api", authRoutes);

// Define your API routes here...

app.listen(PORT, () => {
  console.log(`Server is running on port ${PORT}`);
});
