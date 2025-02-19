const arrs = [1, 2, 3];

// out of range가 안뜨네
// output: undefined
// console.log(arrs[4]);

// console.log(new Array(100).fill().map(() => new Array(100).fill(0)));

const fa = (n) => {
  if (n === 1) {
    return 2;
  }
  return 2 * fa(n - 1);
};
console.log(fa(6));
