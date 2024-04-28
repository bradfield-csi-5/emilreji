const process = require('node:process');
const fs = require('node:fs');
const readline = require('node:readline/promises');
const { stdin: input, stdout: output } = require('node:process');

const rl = readline.createInterface({ input, output });

const path = 'storage.txt';

const serialize = (obj) => { // JSON.stringify
  const stringData = JSON.stringify(obj);
  fs.writeFileSync(path, stringData);
}

const deserialize = () => { // JSON.parse
  const stringData = fs.readFileSync(path);
  const dataObj = JSON.parse(stringData);

  return dataObj;
}

const createStorage = () => {
  if (!fs.existsSync(path)) {
    // create new file w/ empty object
    console.log('creating file:');
    var createStream = fs.createWriteStream(path);
    createStream.write(JSON.stringify({}));
    createStream.end();
  }
}

;(async function() {
  createStorage();

  while (true) {
    const result = await rl.question('prompt> ');
    const arr = result.split(" ");
    const command = arr[0];

    const obj = deserialize();
    // moving here ensures sets from other clients are 
    // pulled in from file before next command is run

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
        serialize(obj);
      } else {
        console.log(`Invalid usage of set; expected set key=value; received: ${result}`);
      }
    } else {
      console.log(`Invalid command: ${command}`);
    }
    console.log(`Data object is: ${JSON.stringify(obj)}`)
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
