#!/usr/bin/node
const request = require('request');
const url = `https://swapi-api.hbtn.io/api/films/${process.argv[2]}/`;

request(url, async function (error, response, body) {
  if (error) throw error;
  const characters = JSON.parse(body).characters;
  for (const c in characters) {
    const res = await new Promise((resolve, reject) => {
      request(characters[c], function (error, response, body) {
        if (error) throw error;
        resolve(JSON.parse(body).nakme);
      });
    });
    console.log(res);
  }
});
