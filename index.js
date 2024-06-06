// source: https://www.acmicpc.net/step

const fs = require("fs");

// https://www.acmicpc.net/problem/1000
(() => {
  const input = fs.readFileSync("/dev/stdin").toString().split(" ");
  console.log(Number(input[0]) + Number(input[1]));
})();

// https://www.acmicpc.net/problem/1001
(() => {
  const input = fs.readFileSync("/dev/stdin").toString().split(" ");
  console.log(Number(input[0]) - Number(input[1]));
})();

// https://www.acmicpc.net/problem/10998
(() => {
  const input = fs.readFileSync("/dev/stdin").toString().split(" ");
  console.log(Number(input[0]) * Number(input[1]));
})();

// https://www.acmicpc.net/problem/1008
(() => {
  const input = fs.readFileSync("/dev/stdin").toString().split(" ");
  console.log(Number(input[0]) / Number(input[1]));
})();

// https://www.acmicpc.net/problem/10869
(() => {
  const input = fs.readFileSync("/dev/stdin").toString().split(" ");
  const [a, b] = input.map(Number);
  console.log(a + b);
  console.log(a - b);
  console.log(a * b);
  console.log(Math.floor(a / b));
  console.log(a % b);
})();

// https://www.acmicpc.net/problem/10926
(() => {
  const input = fs.readFileSync("/dev/stdin").toString().trim();
  console.log(`${input}??!`);
})();

// https://www.acmicpc.net/problem/2739
(() => {
  let input = fs.readFileSync("/dev/stdin").toString().trim();
  input = Number(input);
  for (let i = 1; i < 10; i++) {
    console.log(`${input} * ${i} = ${input * i}`);
  }
})();

// https://www.acmicpc.net/problem/10430
(() => {
  const input = fs.readFileSync("/dev/stdin").toString().split(" ");
  const [a, b, c] = input.map(Number);
  console.log((a + b) % c);
  console.log(((a % c) + (b % c)) % c);
  console.log((a * b) % c);
  console.log(((a % c) * (b % c)) % c);
})();

// https://www.acmicpc.net/problem/2753
(() => {
  let input = fs.readFileSync("/dev/stdin").toString();
  input = Number(input);
  const flag = (input % 4 === 0 && input % 100 !== 0) || input % 400 === 0;
  if (flag) {
    console.log(1);
    return;
  }
  console.log(0);
})();

// https://www.acmicpc.net/problem/2588
(() => {
  const input = fs.readFileSync("/dev/stdin").toString().split("\n");
  const num = Number(input[0]);
  const str = input[1].split("");

  const firstLine = num * Number(str[2]);
  const secondLine = num * Number(str[1]);
  const thirdLine = num * Number(str[0]);
  console.log(firstLine);
  console.log(secondLine);
  console.log(thirdLine);
  console.log(firstLine + secondLine * 10 + thirdLine * 100);
})();

// https://www.acmicpc.net/problem/11382
(() => {
  const input = fs.readFileSync("/dev/stdin").toString().split(" ");
  const [a, b, c] = input.map(Number);
  console.log(a + b + c);
})();

// https://www.acmicpc.net/problem/10171
(() => {
  console.log(`\\    /\\
   )  ( ')
  (  /  )
   \\(__)|
  `);
})();

// https://www.acmicpc.net/problem/10172
(() => {
  console.log(`|\\_/|
  |q p|   /}
  ( 0 )"""\\
  |"^"\`    |
  ||_/=\\\\__|
  `);
})();

// https://www.acmicpc.net/problem/1330
(() => {
  const input = fs.readFileSync("/dev/stdin").toString().split(" ");
  const [a, b] = input.map(Number);
  if (a > b) {
    console.log(">");
    return;
  }
  if (a < b) {
    console.log("<");
    return;
  }
  if (a == b) {
    console.log("==");
  }
})();

// https://www.acmicpc.net/problem/14681
(() => {
  const readline = require("readline");

  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
  });

  const input = [];

  rl.on("line", function (line) {
    input.push(line);
  }).on("close", function () {
    const [x, y] = input.map(Number);

    if (x > 0 && y > 0) {
      console.log(1);
    } else if (x < 0 && y > 0) {
      console.log(2);
    } else if (x < 0 && y < 0) {
      console.log(3);
    } else if (x > 0 && y < 0) {
      console.log(4);
    }

    process.exit();
  });
})();

// https://www.acmicpc.net/problem/2884
(() => {
  const input = fs.readFileSync("/dev/stdin").toString().split(" ");
  const [a, b] = input.map(Number);

  if (b >= 45) {
    console.log(`${a} ${b - 45}`);
    return;
  }
  if (b < 45 && a > 0) {
    console.log(`${a - 1} ${b + 15}`);
    return;
  }
  if (b < 45 && a == 0) {
    console.log(`23 ${b + 15}`);
    return;
  }
})();

(() => {})();

(() => {})();

(() => {})();

(() => {})();

(() => {})();

(() => {})();

(() => {})();
