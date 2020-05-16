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

/*
 TODO: left naive implementation for now (slower)
 let isPrime = (num: int) =>
   switch (num) {
   | 1 => false
   | _ =>
     let topNum = num + 2;
     let a = List2.gen(~n=num) |> List.map(_ => true);
     let upper = sqrt(a |> List.length |> float_of_int) |> int_of_float;
     let sieve = {
       let rec genSieve = (xs, i, limit: int) =>
         switch (xs, i) {
           | (xs, i) => {
               i |> List.nth(xs) === true ? [] : []
             }
         | _ when i === limit => xs
         | _ => xs
         };
       genSieve(a, 0, upper);
     };
     true;
   };
   */

/*
   NOTE:
   a stands for -> alpha, the first
   o -> omega, and the last
 */
let primes = (~start: int, ~ending: int) =>
  List2.gen(~start, ~n=ending) |> List.filter(isPrime);

let num = 2909;

Js.log(
  primes(~start=5, ~ending=31) |> Array.of_list,
);
