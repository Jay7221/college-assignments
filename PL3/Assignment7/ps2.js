let mapFunction = function() {
    if (this.scores) {
        for (let i = 0; i < this.scores.length; ++i) {
            let player = this.scores[i];
            emit(player.name, player.score);
        }
    }
};
let reduceFunction = function(key, values) {
    return Array.sum(values);
};
db.games.mapReduce(
    mapFunction,
    reduceFunction,
    {
        out: "player_total_scores"
    }
);
