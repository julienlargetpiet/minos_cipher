# minos_cipher

## dependencies 

layer2.h --&gt; layer1.h --&gt; layer0.h --&gt; iostream, vector, deque

## What is this ?

It is a cipher method using combinatons, yes the same one from 

                        n! / ((n-k)! * k!)
                        
Basically, it proceeds as following

For the cipherer:

- converting all input characters as binary onto 7 bits into a boolean deque
- finding the number of **iterations** to have if we want to have a deque that matches the one created before according to the **all_comb** algorithm
- that's it !

For the decipherer

- accessing the number of iterations, which should be the **encrypted file**, and the private **n** and **k** number
- generating the boolean deque according to the inputs
- converting final binary to string

## Example

### Ciphering letter per letter

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

## Why ?

Just as a Proof Of Concept

This algorithm has 0 collision. 



