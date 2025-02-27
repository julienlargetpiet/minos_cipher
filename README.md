# minos_cipher

## dependencies 

layer2.h --&gt; layer1.h --&gt; layer0.h --&gt; iostream, vector, deque

## What is this ?

It is a cipher method using combinations, yes the same one from 

                        n! / ((n-k)! * k!)

[![Watch the video](example.mp4)](example.mp4)

Basically, it proceeds as following

For the cipherer:

- converting all input characters as binary onto 7 bits into a boolean deque
- finding the number of **iterations** to have if we want to have a deque that matches the one created before according to the **all_comb** algorithm
- that's it !

For the decipherer

- accessing the number of iterations, the private **n** (which should be the encrypted file) and the **k** number
- generating the boolean deque according to the inputs
- converting final binary to string

## Example

### Ciphering letter per letter (7 bits)

Fast but not secure. Indeed, each ciphered letter has 1 / 128 chances to be discovered.

Indeed, the number of total combinations is:

$\Sigma_{k=0}^{7} \frac{7!}{(7 - k)! \cdot k! }$ 

```
std::string input_snt = "This a sentence! Really cool :) .";
std::vector<unsigned int> vec;
unsigned int k;
unsigned int n;
unsigned int ciphered_val;
std::string out_snt;

for (char val : input_snt) {
  vec = cipherer_minos1b(val);
  x1 = vec[0];
  public_info = vec[1];
  x2 = vec[2];
  out_snt.push_back(decipherer_minos1b(x1, public_info, x2));
};

std::cout << out_snt << "\n";

```

Output:

`"This a sentence! Really cool :) ."`

## 2 Letters by 2 Letters (14 bits)

A bit slower (2 milliseconds for the example), but the 2 letters have 1 / 16384 chances to be discovered.

Indeed, the number of total combinations is:

$\Sigma_{k=0}^{14} \frac{14!}{(14 - k)! \cdot k! }$ 

```
unsigned int step = 2;

input_snt = "ThisIsHelloWorld";

std::string rtn_str = "";
std::string cur_str;

const unsigned int nref = input_snt.length();
unsigned int i = 0;
unsigned int i2;
while (i < nref) {
  cur_str = "";
  i2 = 0;
  while (i2 < step & i + i2 < nref) {
    cur_str.push_back(input_snt[i + i2]);
    i2 += 1;
  };
  vec = cipherer_minos(cur_str);
  x1 = vec[0];
  public_info = vec[1];
  x2 = vec[2];
  rtn_str += decipherer_minos(x1, public_info, x2);
  i += step;
};
std::cout << rtn_str << "\n";
```

Output:

"ThisIsHelloWorld"

## n Letters by n Letters (7 * n bits)

When n takes higher value, the security will greatly increase but the execution time wil also greatly increase.

The number of total combinations is:

$\Sigma_{k=0}^{n} \frac{n!}{(n - k)! \cdot k! }$ 

## Why ?

Just as a Proof Of Concept

This algorithm has 0 collision. 



