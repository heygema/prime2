/*
   please refer to Sieve of Eratosthenes algorithm
   https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 */

module List2 = {
  let gen = (~start: int, ~n: int) => {
    let rec genList = (xs, n) =>
      switch n {
      | 0 => list{0, ...xs}
      | _ if start === n => list{n, ...xs}
      | _ => genList(list{n, ...xs}, n - 1)
      }
    genList(list{}, n)
  }
}

/*
   ref: https://stackoverflow.com/questions/11768958/prime-sieve-in-haskell
*/

@gentype
let isPrime = (n: int) => {
  let rec isPrime = (d: int) => {
    open Int32
    switch d {
    | _ if d * d > n => true
    | _ if rem(n |> of_int, d |> of_int) === 0->of_int => false
    | _ => isPrime(d + 1)
    }
  }
  switch n {
  | 0
  | 1 => false
  | _ => isPrime(2)
  }
}

@gentype
let primes = (~start: int, ~ending: int) =>
  List2.gen(~start, ~n=ending) |> List.filter(isPrime) |> Array.of_list
