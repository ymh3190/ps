// source: https://www.acmicpc.net/step

let path;
if (process.platform === "linux") path = "/dev/stdin";
else if (process.platform === "win32") path = "./input.txt";

// https://www.acmicpc.net/problem/1000
(() => {
  let fs = require("fs");
  let input = fs.readFileSync("/dev/stdin").toString().split(" ");
  console.log(Number(input[0]) + Number(input[1]));
})();

// https://www.acmicpc.net/problem/1001
(() => {
  let fs = require("fs");
  let input = fs.readFileSync("/dev/stdin").toString().split(" ");
  console.log(Number(input[0]) - Number(input[1]));
})();

// https://www.acmicpc.net/problem/10998
(() => {
  let fs = require("fs");
  let input = fs.readFileSync("/dev/stdin").toString().split(" ");
  console.log(Number(input[0]) * Number(input[1]));
})();

// https://www.acmicpc.net/problem/1008
(() => {
  let fs = require("fs");
  let input = fs.readFileSync("/dev/stdin").toString().split(" ");
  console.log(Number(input[0]) / Number(input[1]));
})();

// https://www.acmicpc.net/problem/10869
(() => {
  let fs = require("fs");
  let input = fs.readFileSync("/dev/stdin").toString().split(" ");
  let [a, b] = input.map(Number);
  console.log(a + b);
  console.log(a - b);
  console.log(a * b);
  console.log(Math.floor(a / b));
  console.log(a % b);
})();

// https://www.acmicpc.net/problem/10926
(() => {
  let fs = require("fs");
  let input = fs.readFileSync("/dev/stdin").toString().trim();
  console.log(`${input}??!`);
})();

// https://www.acmicpc.net/problem/2739
(() => {
  let fs = require("fs");
  let input = fs.readFileSync("/dev/stdin").toString().trim();
  input = Number(input);
  for (let i = 1; i < 10; i++) {
    console.log(`${input} * ${i} = ${input * i}`);
  }
})();

// https://www.acmicpc.net/problem/10430
(() => {
  let fs = require("fs");
  let input = fs.readFileSync("/dev/stdin").toString().split(" ");
  let [a, b, c] = input.map(Number);
  console.log((a + b) % c);
  console.log(((a % c) + (b % c)) % c);
  console.log((a * b) % c);
  console.log(((a % c) * (b % c)) % c);
})();

// https://www.acmicpc.net/problem/2753
(() => {
  let fs = require("fs");
  let input = fs.readFileSync("/dev/stdin").toString();
  input = Number(input);
  let flag = (input % 4 === 0 && input % 100 !== 0) || input % 400 === 0;
  if (flag) {
    console.log(1);
    return;
  }
  console.log(0);
})();

// https://www.acmicpc.net/problem/11382
(() => {
  let fs = require("fs");
  let input = fs.readFileSync("/dev/stdin").toString().split(" ");
  let [a, b, c] = input.map(Number);
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
  let fs = require("fs");
  let input = fs.readFileSync("/dev/stdin").toString().split(" ");
  let [a, b] = input.map(Number);
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
  let readline = require("readline");

  let rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
  });

  let input = [];

  rl.on("line", function (line) {
    input.push(line);
  }).on("close", function () {
    let [x, y] = input.map(Number);

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
  let fs = require("fs");
  let input = fs.readFileSync("/dev/stdin").toString().split(" ");
  let [a, b] = input.map(Number);

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

// https://www.acmicpc.net/problem/2480
(() => {
  let fs = require("fs");
  let input = fs.readFileSync("/dev/stdin").toString().split(" ");
  let [a, b, c] = input.map(Number);

  let reward;
  if (a === b && b === c) {
    reward = 10000 + a * 1000;
  } else if (a === b || b === c || c === a) {
    reward = 1000;
    if (a === b) {
      reward += a * 100;
    } else if (b === c) {
      reward += b * 100;
    } else if (c === a) {
      reward += c * 100;
    }
  } else if (a !== b && b !== c && c !== a) {
    if (a > b && a > c) {
      reward = 100 * a;
    } else if (b > a && b > c) {
      reward = 100 * b;
    } else if (c > a && c > b) {
      reward = 100 * c;
    }
  }
  console.log(reward);
})();

// https://www.acmicpc.net/problem/9498
(() => {
  let fs = require("fs");
  let input = fs.readFileSync("/dev/stdin").toString();
  input = Number(input);

  let score;
  if (input >= 90) {
    score = "A";
  } else if (input >= 80) {
    score = "B";
  } else if (input >= 70) {
    score = "C";
  } else if (input >= 60) {
    score = "D";
  } else {
    score = "F";
  }
  console.log(score);
})();

// https://www.acmicpc.net/problem/10950
(() => {
  let fs = require("fs");
  let input = fs.readFileSync("/dev/stdin").toString().split("\n");
  let t = Number(input[0]);

  for (let i = 1; i <= t; i++) {
    let [a, b] = input[i].split(" ").map(Number);
    console.log(a + b);
  }
})();

// https://www.acmicpc.net/problem/25304
(() => {
  let fs = require("fs");
  let input = fs.readFileSync("/dev/stdin").toString().split("\n");
  let x = Number(input[0]);
  let n = Number(input[1]);

  let sum = 0;
  for (let i = 2; i <= n + 1; i++) {
    let [a, b] = input[i].split(" ").map(Number);
    sum += a * b;
  }

  if (x === sum) {
    console.log("Yes");
  } else {
    console.log("No");
  }
})();

// https://www.acmicpc.net/problem/8393
(() => {
  let fs = require("fs");
  let input = fs.readFileSync("/dev/stdin").toString();
  let n = Number(input);

  let sum = Math.floor((n * (n + 1)) / 2);
  console.log(sum);
})();

// https://www.acmicpc.net/problem/25314
(() => {
  let fs = require("fs");
  let input = fs.readFileSync("/dev/stdin").toString();
  let n = Number(input) / 4;

  let str = "";
  for (let i = 0; i < n; i++) {
    str += "long ";
  }
  console.log(str + "int");
})();

// https://www.acmicpc.net/problem/15552
(() => {
  let fs = require("fs");
  let [t, ...arrs] = fs.readFileSync("/dev/stdin").toString().split("\n");
  t = Number(t);

  let answer = "";
  for (let i = 0; i < t; i++) {
    let [a, b] = arrs[i].split(" ").map(Number);
    answer += `${a + b} \n`;
  }
  console.log(answer);
})();

// https://www.acmicpc.net/problem/11021
(() => {
  let fs = require("fs");
  let [t, ...arrs] = fs.readFileSync("/dev/stdin").toString().split("\n");
  t = Number(t);

  let answer = "";
  for (let i = 0; i < t; i++) {
    let [a, b] = arrs[i].split(" ").map(Number);
    answer += `Case #${i + 1}: ${a + b} \n`;
  }
  console.log(answer);
})();

// https://www.acmicpc.net/problem/11022
(() => {
  let fs = require("fs");
  let [t, ...arrs] = fs.readFileSync("/dev/stdin").toString().split("\n");
  t = Number(t);

  let answer = "";
  for (let i = 0; i < t; i++) {
    let [a, b] = arrs[i].split(" ").map(Number);
    answer += `Case #${i + 1}: ${a} + ${b} = ${a + b}\n`;
  }
  console.log(answer);
})();

// https://www.acmicpc.net/problem/10952
(() => {
  let fs = require("fs");
  let input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
  let n = input.length;

  let answer = "";
  for (let i = 0; i < n - 1; i++) {
    let [a, b] = input[i].split(" ").map(Number);
    answer += a + b + "\n";
  }
  console.log(answer);
})();

// https://www.acmicpc.net/problem/10951
(() => {
  let fs = require("fs");
  let input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
  let n = input.length;

  let answer = "";
  for (let i = 0; i < n; i++) {
    let [a, b] = input[i].split(" ").map(Number);
    answer += `${a + b} \n`;
  }
  console.log(answer);
})();

// https://www.acmicpc.net/problem/10807
(() => {
  let fs = require("fs");
  let input = fs.readFileSync("/dev/stdin").toString().split("\n");
  let n = Number(input[0]);
  let arrs = input[1].split(" ").map(Number);
  let v = Number(input[2]);

  let answer = 0;
  for (let i = 0; i < n; i++) {
    if (arrs[i] === v) answer++;
  }
  console.log(answer);
})();

// https://www.acmicpc.net/problem/10871
(() => {
  let fs = require("fs");
  let input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
  let [n, x] = input[0].split(" ").map(Number);
  let arrs = input[1].split(" ").map(Number);

  let answer = "";
  for (let i = 0; i < n; i++) {
    if (arrs[i] < x) answer += `${arrs[i]} `;
  }
  console.log(answer);
})();

// https://www.acmicpc.net/problem/10818
(() => {
  let fs = require("fs");
  let input = fs.readFileSync("/dev/stdin").toString().split("\n");
  let n = Number(input[0]);
  let arrs = input[1].split(" ").map(Number);

  let max = arrs[0];
  let min = arrs[0];
  for (let i = 1; i < n; i++) {
    if (arrs[i] > max) max = arrs[i];
    else if (arrs[i] < min) min = arrs[i];
  }
  console.log(min, max);
})();

// https://www.acmicpc.net/problem/2562
(() => {
  let fs = require("fs");
  let input = fs.readFileSync("/dev/stdin").toString().split("\n");
  let arrs = input.map(Number);
  let n = arrs.length;

  let index = 1;
  let max = arrs[0];
  for (let i = 1; i < n; i++) {
    if (arrs[i] > max) {
      max = arrs[i];
      index = i + 1;
    }
  }
  console.log(`${max}\n${index}`);
})();

// https://www.acmicpc.net/problem/10810
(() => {
  let fs = require("fs");
  let input = fs.readFileSync("/dev/stdin").toString().split("\n");
  let [n, m] = input[0].split(" ").map(Number);
  let arrs = [];
  for (let i = 0; i < n; i++) {
    arrs.push(0);
  }

  for (let i = 1; i <= m; i++) {
    let [a, b, c] = input[i].split(" ").map(Number);
    for (let j = a - 1; j < b; j++) {
      arrs[j] = c;
    }
  }
  console.log(...arrs);
})();

// https://www.acmicpc.net/problem/10813
(() => {
  let fs = require("fs");
  let input = fs.readFileSync("/dev/stdin").toString().split("\n");
  let [n, m] = input[0].split(" ").map(Number);
  let arrs = [];
  for (let i = 0; i < n; i++) {
    arrs.push(i + 1);
  }

  let temp;
  for (let i = 1; i <= m; i++) {
    let [a, b] = input[i].split(" ").map(Number);
    temp = arrs[b - 1];
    arrs[b - 1] = arrs[a - 1];
    arrs[a - 1] = temp;
  }
  console.log(...arrs);
})();

// https://www.acmicpc.net/problem/5597
(() => {
  let fs = require("fs");
  let input = fs.readFileSync("/dev/stdin").toString().split("\n").map(Number);

  let answer = [];
  for (let i = 0; i < 30; i++) {
    if (input.includes(i + 1)) continue;
    answer.push(i + 1);
  }
  answer.sort((a, b) => a - b);
  console.log(`${answer[0]}\n${answer[1]}`);
})();

// https://www.acmicpc.net/problem/3052
(() => {
  let fs = require("fs");
  let input = fs.readFileSync("/dev/stdin").toString().split("\n").map(Number);

  let arrs = [];
  for (let i = 0; i < 10; i++) {
    arrs.push(input[i] % 42);
  }
  arrs = [...new Set(arrs)];
  console.log(arrs.length);
})();

// https://www.acmicpc.net/problem/27866
(() => {
  const fs = require("fs");
  const input = fs.readFileSync("/dev/stdin").toString().split("\n");
  const str = input[0];
  const index = Number(input[1]) - 1;
  console.log(str[index]);
})();

// https://www.acmicpc.net/problem/11654
(() => {
  const fs = require("fs");
  const input = fs.readFileSync("/dev/stdin").toString().trim();
  console.log(input.charCodeAt(0));
})();

// https://www.acmicpc.net/problem/11720
(() => {
  const fs = require("fs");
  const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
  const n = Number(input[0]);
  const strs = input[1];

  let answer = 0;
  for (let i = 0; i < n; i++) {
    answer += Number(strs[i]);
  }
  console.log(answer);
})();

// https://www.acmicpc.net/problem/2675
(() => {
  const fs = require("fs");
  const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
  const t = Number(input[0]);

  let answer = "";
  for (let i = 1; i <= t; i++) {
    const [r, s] = input[i].split(" ");
    s.split("").forEach((v) => {
      for (let j = 0; j < r; j++) {
        answer += v;
      }
    });
    answer += "\n";
  }
  console.log(answer);
})();

// https://www.acmicpc.net/problem/1152
(() => {
  const fs = require("fs");
  const path = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
  const input = fs.readFileSync(path).toString().trim().split(" ");
  const strs = input;

  let answer = [];
  for (let i = 0; i < strs.length; i++) {
    if (strs[i] === "") continue;
    answer.push(strs[i]);
  }
  console.log(answer.length);
})();

// https://www.acmicpc.net/problem/2908
(() => {
  const fs = require("fs");
  const input = fs.readFileSync("/dev/stdin").toString().split(" ");
  const [str1, str2] = input;

  const s1 = str1[2] + str1[1] + str1[0];
  const s2 = str2[2] + str2[1] + str2[0];
  let answer;
  if (Number(s1) > Number(s2)) answer = s1;
  else answer = s2;
  console.log(answer);
})();

// https://www.acmicpc.net/problem/11718
(() => {
  const fs = require("fs");
  const input = fs.readFileSync("/dev/stdin").toString().split("\n");
  const strs = input;
  let answer = "";
  for (const str of strs) {
    answer += str + "\n";
  }
  console.log(answer);
})();

// https://www.acmicpc.net/problem/3003
(() => {
  const fs = require("fs");
  const input = fs.readFileSync("/dev/stdin").toString().split(" ");
  const arrs = [1, 1, 2, 2, 2, 8];

  const answer = [];
  for (let i = 0; i < arrs.length; i++) {
    answer.push(arrs[i] - input[i]);
  }
  console.log(answer.join(" "));
})();

// https://www.acmicpc.net/problem/10988
// https://sunflo0524.tistory.com/37 <- better than me
(() => {
  const fs = require("fs");
  const input = fs.readFileSync("/dev/stdin").toString().trim().split("");
  const strs = input;
  const half = Math.floor(strs.length / 2);

  for (let i = 0; i < half; i++) {
    if (strs[i] !== strs[strs.length - 1 - i]) {
      console.log(0);
      return;
    }
  }
  console.log(1);
})();

(() => {})();

(() => {})();

(() => {})();

(() => {})();

(() => {})();

(() => {})();

(() => {})();

(() => {})();

(() => {})();

(() => {})();

(() => {})();

(() => {})();

// https://www.acmicpc.net/problem/2941
(() => {})();

// https://www.acmicpc.net/submit/1157/79831785
// https://mywebproject.tistory.com/468 <- better than me
(() => {})();

// https://www.acmicpc.net/problem/2444
(() => {})();

// https://www.acmicpc.net/problem/10809
(() => {})();

// https://www.acmicpc.net/problem/25083
(() => {})();

// https://www.acmicpc.net/problem/5622
(() => {
  const fs = require("fs");
  const input = fs.readFileSync("/dev/stdin").toString();
  const strs = input;
  const arrs = ["ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"];

  let answer = 0;
  for (let i = 0; i < strs.length; i++) {
    for (let j = 0; j < arrs.length; j++) {
      if (arrs[j].includes(strs[i])) {
        answer += j + 3;
        break;
      }
    }
  }
  console.log(answer);
})();

// https://www.acmicpc.net/problem/2588
(() => {
  const fs = require("fs");
  const input = fs.readFileSync("/dev/stdin").toString().split("\n");
  const up = input[0];
  const down = input[1];

  const one = Number(up) * Number(down[2]);
  const ten = Number(up) * Number(down[1]);
  const hundred = Number(up) * Number(down[0]);
  const sum = one + ten * 10 + hundred * 100;
  console.log(one);
  console.log(ten);
  console.log(hundred);
  console.log(sum);
})();

// https://www.acmicpc.net/problem/2525
(() => {
  const fs = require("fs");
  const input = fs.readFileSync("/dev/stdin").toString().split("\n");
  const [a, b] = input[0].split(" ").map(Number);
  const c = Number(input[1]);

  let hr = a;
  let min = b + c;
  if (min >= 60) {
    hr += Math.floor(min / 60);
    min = min % 60;
    if (hr >= 24) {
      hr -= 24;
    }
  }
  console.log(hr, min);
})();

// https://www.acmicpc.net/problem/2438
(() => {
  const fs = require("fs");
  const input = fs.readFileSync("/dev/stdin").toString();
  const n = Number(input);

  let str = "";
  for (let i = 1; i < n + 1; i++) {
    for (let j = 0; j < i; j++) {
      str += "*";
    }
    str += "\n";
  }
  console.log(str);
})();

// https://www.acmicpc.net/problem/2439
(() => {
  const fs = require("fs");
  const input = fs.readFileSync("/dev/stdin").toString();
  const n = Number(input);

  let str = "";
  let star = "";
  let blank = "";
  for (let i = 0; i < n; i++) {
    star += "*";
    for (let j = 0; j < n - i - 1; j++) {
      blank += " ";
    }
    str += blank + star + "\n";
    blank = "";
  }
  console.log(str);
})();

// https://www.acmicpc.net/problem/10811
(() => {
  const fs = require("fs");
  const input = fs.readFileSync("/dev/stdin").toString().split("\n");
  const [n, m] = input[0].split(" ").map(Number);

  const arrs = new Array(n).fill(1).map((v, i) => v + i);

  for (let i = 0; i < m; i++) {
    const tmps = [];
    const [a, b] = input[i + 1].split(" ").map(Number);
    for (let j = a - 1; j < b; j++) {
      tmps.push(arrs[j]);
    }
    tmps.reverse();
    arrs.splice(a - 1, tmps.length, ...tmps);
  }
  console.log(...arrs);
})();

// https://www.acmicpc.net/problem/1546
(() => {
  const fs = require("fs");
  const input = fs.readFileSync("/dev/stdin").toString().split("\n");
  const n = Number(input[0]);
  const scores = input[1].split(" ").map(Number);

  let max = 0;
  for (let i = 0; i < n; i++) {
    if (scores[i] > max) {
      max = scores[i];
    }
  }

  let avg = 0;
  for (let i = 0; i < scores.length; i++) {
    avg += ((scores[i] / max) * 100) / n;
  }
  console.log(avg);
})();

// https://www.acmicpc.net/problem/9086
(() => {
  const fs = require("fs");
  const input = fs.readFileSync("/dev/stdin").toString().split("\n");
  const n = Number(input[0]);

  let str = "";
  for (let i = 0; i < n; i++) {
    str += input[i + 1][0] + input[i + 1].at(-1) + "\n";
  }
  console.log(str);
})();
