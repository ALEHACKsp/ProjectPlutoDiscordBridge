// JavaScript source code
//require the config
const config = require("./config")
//require the discord library
const Discord = require("discord.js")
//create a new client
const client = new Discord.Client()

const app = require("express")();
const http = require('http').Server(app);
const io = require("socket.io")(http);

//emit this function once the client is ready
client.on('ready', () => {
    console.log(`Logged in as ${client.user.tag}`);
});

//emit this function when a user connects in-game
io.on("connection", socket => {
    let channel = client.channels.get("411579189456797703");
    channel.send("A user has connected");

    //emit this function when a user disconnects in-game
    socket.on("disconnect", () => {
        channel.send("A user disconnected");
    });

    //emit this function when a new message is sent
    socket.on("chat_message", (key, serverName, msg) => {

    });
});

//login the client to the token found in the config
client.login(config.TOKEN);