const p2869 = () => {
  const fs = require("fs");
  const input = fs.readFileSync("2869.txt").toString().split(" ").map(Number);
  const [a, b, v] = input;

  let days = 0;

  // 시간 초과
  // let meters = 0;
  // while (true) {
  //   days++;
  //   meters += a;
  //   if (meters >= v) break;
  //   meters -= b;
  // }

  // 목표 지점에서 내려가는 높이를 빼야하는 이유는
  // 오전 중에 a 만큼 올라갈 때 목표치 v에 도달하면 b만큼 내려가지 않아도 되기에
  // 목표 높이가 v가 아니라 v-b가 되는 것
  days = Math.ceil((v - b) / (a - b));
  console.log(days);
};

const p5086 = () => {
  const fs = require("fs");
  const inputs = fs
    .readFileSync("5086.txt")
    .toString()
    .split("\n")
    .map((v) => v.split(" ").map(Number));
  for (const input of inputs) {
    const [a, b] = input;
    if (a == 0 && b == 0) break;
    if (b % a == 0) console.log("factor");
    else if (a % b == 0) console.log("multiple");
    else console.log("neither");
  }
};

const p2501 = () => {
  const fs = require("fs");
  const input = fs.readFileSync("2501.txt").toString().split(" ").map(Number);
  const [n, k] = input;
  const arrs = [];
  for (let i = 1; i <= n; i++) {
    if (n % i == 0) arrs.push(i);
  }
  console.log(arrs[k - 1] ? arrs[k - 1] : 0);
};

const p9506 = () => {
  const fs = require("fs");
  const inputs = fs.readFileSync("9506.txt").toString().split("\n").map(Number);
  inputs.pop();
  const arrs = [];
  let sum = 0;
  for (const n of inputs) {
    for (let i = 1; i < n; i++) {
      if (n % i == 0) arrs.push(i);
    }
    sum = arrs.reduce((acc, cur) => (acc += cur), 0);
    if (sum == n) console.log(`${n} = ${arrs.join(" + ")}`);
    else console.log(`${n} is NOT perfect.`);
    arrs.length = 0;
  }
};

const p1978 = () => {
  const fs = require("fs");
  const [_, inputs] = fs.readFileSync("1978.txt").toString().trim().split("\n");
  const input = inputs.split(" ").map(Number);
  if (input[0] == 1) input.shift();
  const arrs = [];
  for (const n of input) {
    arrs.push(n);
    for (let i = 2; i < n; i++) {
      if (n % i == 0) {
        arrs.pop();
        break;
      }
    }
  }
  console.log(arrs.length);
};

const p2581 = () => {
  const fs = require("fs");
  const [m, n] = fs
    .readFileSync("2581.txt")
    .toString()
    .trim()
    .split("\n")
    .map(Number);
  const arrs = [];
  for (let i = m; i <= n; i++) {
    if (i == 1) continue;
    arrs.push(i);
    for (let j = 2; j < i; j++) {
      if (i % j == 0) {
        arrs.pop();
        break;
      }
    }
  }
  if (!arrs.length) console.log(-1);
  else {
    console.log(`${arrs.reduce((acc, cur) => (acc += cur), 0)}\n${arrs[0]}`);
  }
};

const p11653 = () => {
  const fs = require("fs");
  const input = fs.readFileSync("11653.txt").toString().trim();
  let n = Number(input);

  const arrs = [];
  while (n > 1) {
    for (let i = 2; i <= n; i++) {
      if (n % i == 0) {
        n /= i;
        arrs.push(i);
        break;
      }
    }
  }
  console.log(arrs.join("\n"));
};

const p27323 = () => {
  let fs = require("fs");
  let input = fs.readFileSync("27323.txt").toString().split("\n").map(Number);
  let a = input[0],
    b = input[1];
  console.log(a * b);
};

const p1085 = () => {
  let fs = require("fs");
  let input = fs
    .readFileSync("1085.txt")
    .toString()
    .trim()
    .split(" ")
    .map(Number);
  let [x, y, w, h] = input;
  console.log(Math.min(x, y, w - x, h - y));
};

const p3009 = () => {
  let fs = require("fs");
  let input = fs
    .readFileSync("3009.txt")
    .toString()
    .trim()
    .split("\n")
    .map((v) => v.split(" ").map(Number));

  // let a, b, c, x, y;
  // for (let i = 0; i < 2; i++) {
  //   a = input[0][i];
  //   b = input[1][i];
  //   c = input[2][i];
  //   if (a == b) !x ? (x = c) : (y = c);
  //   else if (b == c) !x ? (x = a) : (y = a);
  //   else if (c == a) !x ? (x = b) : (y = b);
  // }
  // console.log(x, y);
  let xArrs = input.map((v) => v[0]).sort();
  let yArrs = input.map((v) => v[1]).sort();
  let x = xArrs[0] == xArrs[1] ? xArrs[2] : xArrs[0];
  let y = yArrs[0] == yArrs[1] ? yArrs[2] : yArrs[0];
  console.log(x, y);
};

const p15894 = () => {
  let fs = require("fs");
  let input = fs.readFileSync("15894.txt").toString().trim();
  let n = Number(input);
  console.log(4 * n);
};

const p9063 = () => {
  let fs = require("fs");
  let [_, ...input] = fs
    .readFileSync("input.txt")
    .toString()
    .trim()
    .split("\n");
  input = input.map((v) => v.split(" ").map(Number));
  let x = input.map((v) => v[0]).sort((a, b) => a - b);
  let y = input.map((v) => v[1]).sort((a, b) => a - b);
  let width = x.at(-1) - x[0];
  let height = y.at(-1) - y[0];
  console.log(width * height);
};

const p10101 = () => {
  let fs = require("fs");
  let inputs = fs
    .readFileSync("input.txt")
    .toString()
    .trim()
    .split("\n")
    .map(Number);
  let [a, b, c] = inputs;
  if (a + b + c != 180) console.log("Error");
  else if (a == b && b == c) console.log("Equilateral");
  else if (a == b || b == c || c == a) console.log("Isosceles");
  else console.log("Scalene");
};

const p5073 = () => {
  let fs = require("fs");
  let inputs = fs
    .readFileSync("input.txt")
    .toString()
    .trim()
    .split("\n")
    .map((v) => v.split(" ").map(Number));
  inputs.pop();
  for (let input of inputs) {
    let [a, b, c] = input.sort();
    if (c >= a + b) console.log("Invalid");
    else if (a == b && b == c) console.log("Equilateral");
    else if (a == b || b == c || c == a) console.log("Isosceles");
    else console.log("Scalene");
  }
};

const p14215 = () => {
  let fs = require("fs");
  let input = fs
    .readFileSync("input.txt")
    .toString()
    .trim()
    .split(" ")
    .map(Number);
  let [a, b, c] = input.sort((a, b) => a - b);
  if (c >= a + b) console.log(a + b - 1 + b + a);
  else console.log(a + b + c);
};

const main = () => {
  p14215();
};

main();
