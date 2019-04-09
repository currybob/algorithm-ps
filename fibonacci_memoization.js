const memoFibo = (() => {
  const memo = {};
  const fibo = num => {
    if (num < 2) return num;

    const result = (memo[num - 1] || fibo(num - 1)) + (memo[num - 2] || fibo(num - 2));
    memo[num] = result;

    return result;
  };

  return fibo;
})();
