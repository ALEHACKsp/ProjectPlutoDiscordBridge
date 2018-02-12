// JavaScript source code
const config = require("./config.json")
const Discord = require("discord.js")
const client = new Discord.Client()

const app = require("express")();
const http = require('http').Server(app);
const io = require("socket.io")(http);

client.on('ready', () => {
    console.log(`Logged in as ${client.user.tag}`);

    http.listen(3000, () => {
        console.log("Listening on port 3000");
    })
});

function getTeamName(team) {
	if(team == 1)
		return "Axis";
	if(team == 2)
		return "Allies";
	if(team == 3)
		return "Spectators";

	return "None";
}

io.on("connection", socket => {
    let channel = client.channels.get(config.channel_id);
    channel.send("A server disconnected!");

    socket.on("disconnect", () => {
        channel.send("A server disconnected!");
    });

    socket.on("chat_message", (key, serverName, user, team, msg) => {
    	if (key.trim() === config.password.trim()) {
    		msg = msg.replace("","");
    		channel.send("[" + serverName + "] **" + getTeamName(team.trim()) + "** [" + user + "]: " + msg); //just edit this string to your wishes
		}
		else {
			return;
		}
    });
});

client.login(config.bot_token);
