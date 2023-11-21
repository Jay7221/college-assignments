// Q1
db.students.aggregate([
    {
        $group: {
            _id: "$age",
            name: { $push: "$firstName" }
        }
    }
])

// Q2
db.students.aggregate([
    {
        $group: {
            _id: {
                name: "$firstName",
                age: "$age"
            },
            count: { "$sum": 1 }

        }
    }
])

// Q3
db.students.aggregate([
    {
        $group: {
            _id: {
                firstName: "$firstName",
                lastName: "$lastName",
            },
            age: { $sum: "$age" },
            totalMarks: { $sum: "$examsMarks" }

        }
    }
])

// Q4
db.students.aggregate([
    {
        $match: {
            age: { $gt: 21 }
        }
    },
    {
        $group: {
            _id: {
                firstName: "$firstName",
                lastName: "$lastName",
            },
            age: { $sum: "$age" },
            totalMarks: { $sum: "$examsMarks" }

        }
    }
])

// Q5
db.students.aggregate([
    { $unwind: "$status" },
    {
        $group: {
            _id: {
                course: "$status.course",
                batch: "$status.batch",
            },
            enrolled: { $push: "$firstName" }
        }
    }
])
