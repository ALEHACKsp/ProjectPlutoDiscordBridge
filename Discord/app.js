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
    let channels = client.channels;
    console.log("A server connected!")

    socket.on("disconnect", () => {
        console.log("A server disconnected!")
    });

    socket.on("chat_message", (key, serverName, user, team, msg) => {
    	if (key.trim() === config.key.trim()) {
    		msg = msg.replace("","");
            let channel = channels.get(config.servers[serverName]);
    		channel.send("**" + getTeamName(team.trim()) + "** [" + user + "]: " + msg); //just edit this string to your wishes
		}
		else {
			return;
		}
    });
});

client.on("message", msg => {
    //TODO!
    if (!msg.author.bot)
		io.emit("discord_message",config.key,"LUUUUL",msg.author.username,msg.content)
});
client.login(config.bot_token);
