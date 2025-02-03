let fs = require("fs");
let input = fs.readFileSync("input.txt").toString().trim().split("\n");
let arrs = input
  .pop()
  .split(" ")
  .map(Number)
  .sort((a, b) => b - a);
console.log(arrs);
