let fs = require("fs");
let input = fs.readFileSync("input.txt").toString().trim().split("\n");
let n = Number(input.shift());
let arrs = input
  .map((v) => v.split(" "))
  .map((v, i) => {
    v[0] = Number(v[0]);
    return { i, age: v[0], name: v[1] };
  })
  .sort((a, b) => {
    if (a.age < b.age) return -1;
    else if (a.age == b.age && a.i < b.i) return -1;
    return 0;
  });

for (let i = 0; i < n; i++) {
  console.log(arrs[i].age, arrs[i].name);
}
