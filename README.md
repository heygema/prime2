# Prime2
[![license](https://img.shields.io/github/license/DAVFoundation/captain-n3m0.svg?style=flat-square)](LICENSE)

This is just another prime numbers generator, look at [primes](https://www.npmjs.com/package/primes).
coded in ReasonML (idk why), hence the name prime2.

available for global command
## Install
```bash
# as global command
npm install -g prime2

# as package
npm install prime2
```

## To include in Reason project:
in bsconfig.json
```
"bs-dependencies": ["prime2"]
```

available as Prime module
```ocaml
Prime.isPrime: int -> boolean
Prime.primes: ~start: int ~ending: int -> array(int)
```

## Execute as command line (these days however there's npx)
```bash
npx prime2 --check 3
```

```bash
prime2 --check 3 # output > true

prime2 --generate 0 10  # output > [2, 3, 5, 7]
```

## As js/ts utils
```typescript
import * as prime2 from 'prime2';

// return true if n is prime.
prime2.isPrime(n: number): boolean;

// primes
// generate list of primes starting from `start` to `ending`
prime2.primes(start: number, ending: number):  number[]
```
