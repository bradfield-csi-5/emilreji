const process = require('node:process');

const readline = require('node:readline/promises');
const { stdin: input, stdout: output } = require('node:process');

const rl = readline.createInterface({ input, output });

const obj = {};

;(async function() {
  while (true) {
    const result = await rl.question('prompt> ');
    const arr = result.split(" ");
    const command = arr[0];

    if (command === "get") {
      const key = arr[1];
      if (!!key && arr.length === 2) {
        const value = obj[key];

        console.log(value);
      } else {
        console.log(`Invalid usage of get; expected get key; received: ${result}`);
      }
    } else if (command === "set") {
      const keyValuePair = arr[1]?.split("=");
      const key = keyValuePair[0];
      const value = keyValuePair[1];

      if (!!arr[1] && !!key && !!value && arr.length === 2) {
        obj[key] = value;
      } else {
        console.log(`Invalid usage of set; expected set key=value; received: ${result}`);
      }
    } else {
      console.log(`Invalid command: ${command}`);
    }
  }
})().catch(function(err) {
  console.log('Error:');
  console.log(JSON.stringify(err));
  process.exit();
});

process.on('SIGINT', () => {
  console.log('\nReceived SIGINT (aka Ctrl + C) so exiting.');
  process.exit();
});



/*
Output prompt
Wait for STDIN
Receive input and store in object and key/value
Return to 
*/