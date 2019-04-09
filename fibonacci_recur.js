// es6
const fibonacci = num => (num < 2 ? num : fibonacci(num - 1) + fibonacci(num - 2));

// es5
function fibo(num) {
  return num < 2 ? num : fibo(num - 1) + fibo(num - 2);
}
