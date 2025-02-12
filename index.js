let fs = require("fs");
let input = fs.readFileSync("input.txt").toString().trim().split("\n");
let arrs = input[1].split(" ").map(Number);
let map = new Map();

[...new Set(arrs)].sort((a, b) => a - b).forEach((v, i) => map.set(v, i));

let ret = "";
arrs.forEach((v) => {
  ret += `${map.get(v)} `;
});
console.log(ret);
