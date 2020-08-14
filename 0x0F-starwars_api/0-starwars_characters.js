#!/usr/bin/node
const request = require('request');
const url = `https://swapi-api.hbtn.io/api/films/${process.argv[2]}/`;

// request(url, function (error, response, body) {
//   if (error) {
//     console.log(error);
//   } else {
//     console.log(JSON.parse(body).characters);
//   }
// });

request(url, function (error, response, body) {
  if (error) throw error;
  const characters = JSON.parse(body).characters;
  for (var c in characters) {
    request(characters[c], function (error, response, body) {
      if (error) throw error;
      console.log(JSON.parse(body).name);
    });
  }
});
