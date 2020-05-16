/*
   please refer to Sieve of Eratosthenes algorithm
   https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 */

module List2 = {
  let gen = (~start: int, ~n: int) => {
    let rec genList = (xs, n) => {
      switch (n) {
      | 0 => [0, ...xs]
      | _ when start === n => [n, ...xs]
      | _ => genList([n, ...xs], n - 1)
      };
    };
    genList([], n);
  };
};

/*
   ref: https://stackoverflow.com/questions/11768958/prime-sieve-in-haskell
*/

[@gentype "isPrime"]
let isPrime = (n: int) => {
  let rec isPrime = (d: int) =>
    Int32.(
      switch (d) {
      | _ when d * d > n => true
      | _ when rem(n |> of_int, d |> of_int) === 0->of_int => false
      | _ => isPrime(d + 1)
      }
    );
  switch (n) {
  | 0
  | 1 => false
  | _ => isPrime(2)
  };
};

[@gentype]
let primes = (~start: int, ~ending: int) =>
  List2.gen(~start, ~n=ending) |> List.filter(isPrime) |> Array.of_list;
