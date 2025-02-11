let fs = require("fs");
let [_, ...input] = fs.readFileSync("input.txt").toString().trim().split("\n");
let arrs = input
  .map((v) => v.split(" ").map(Number))
  .sort((a, b) => {
    if (a[0] - b[0] < 0 || (a[0] == b[0] && a[1] < b[1])) return -1;
    return 0;
  });
for (const arr of arrs) {
  console.log(arr.join(" "));
}
