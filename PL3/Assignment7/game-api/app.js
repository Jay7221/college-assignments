const express = require('express');
const app = express();

const MongoClient = require('mongodb').MongoClient;

const port = process.env.PORT || 3009;

app.listen(port, () => {
    console.log(`Server is running on port ${port}`);
});


const uri = 'mongodb://127.0.0.1:27017/';
const client = new MongoClient(uri);
client.connect(err => {
    if (err) {
        console.log(`Error connecting to MongoDB : ${err}`);
    }
    else {
        console.log('Connected to MongoDB');
    }
})

app.get('/games', async (req, res) => {
    const db = client.db('pl3');
    const gamesCollection = db.collection('games');
    const gamesData = await gamesCollection.find().toArray();

    gamesData.forEach(game => {
        if (game.scores) {
            const scores = game.scores.map(score => score.score);
            const averageScore = scores.reduce((a, b) => a + b, 0) / scores.length;
            game.averageScore = averageScore;
        }
        else {
            game.averageScore = 'No Data';
        }
    });

    let html = `<html>
<head>
<style>
table{
border-collapse: collapse;
}
th, td {
  border: 1px solid;
padding: 1rem;
}
</style>

</head>
<body><table>
        <tr>
<th>Game</th>
<th>Genre</th>
<th>Publisher</th>
<th>Release Date</th>
<th>Rating</th>
<th>Average Score</th>
</tr>

`;
    gamesData.forEach(game => {
        html += `<tr>
        <td>${game.name}</td>
        <td>${game.genre ? game.genre : 'No Data'}</td>
        <td>${game.publisher ? game.publisher : 'No Data'}</td>
        <td>${game.released ? game.released : 'No Data'}</td>
        <td>${game.rating ? game.rating : 'No Data'}</td>
        <td>${game.averageScore}</td>
        </tr>`;

    });
    res.send(html);
    html += '</table></body></html>';
});
