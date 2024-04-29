const teacherMiddleware = (req, res, next) => {
  if (req.user && req.user.role === "teacher") {
    next();
  } else {
    res.status(403).json({ message: "Forbidden" });
  }
};

module.exports = teacherMiddleware;
