# ProjectPlutoDiscordBridge
A bridge between the Plutonium MW3 Server and Discord.

To use it follow these instructions:

# Plutonium Server
To install this extension on your plutonium server just drop the "PlutoBridge.dll","d3d9.dll" and the "config.txt" in your servers directory.

You want to edit the config .txt to your needs:
```
yourpassword
http://127.0.0.1:3000
````
While the first value indicates the password for the connection to the discord bot and the IP the host where the bot is running, if it runs on the same host as the server does leave the ip as it is.

# Discord Bot
Clone or download the "Discord" directory from the source code, install the needed modules using:
```
npm install --save express
npm install --save discord.js
npm install --save socket.io
```
Add the bot to your server using discord's developer panel.
Edit the config.json to your needs.
```JSON
{
	"bot_token":"<the token of your bot user>",
	"channel_id":"<the channel id, where the messages should be send>",
	"password": "<the password your specified in the config.txt>"
}
```
And finally run it using:
```node app.js ```

If you have any issues, use the [issue reporter](https://github.com/Boboo99/ProjectPlutoDiscordBridge/issues) of the repo.

Special thanks to [StaRT](https://github.com/StaRT1337) my dude!
