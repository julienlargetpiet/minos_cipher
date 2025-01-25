# minos_cipher

## dependencies 

layer2.h --&gt; layer1.h --&gt; layer0.h --&gt; iostream, vector, deque

## What is this ?

It is a cipher method using combinatons, yes the same one from the 

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

Encrypting 'word'

```
std::string input_wrd = "word";
std::vector<unsigned int> vec = cipherer_minos(input_wrd);
unsigned int k = vec[0];
unsigned int n = vec[1];
unsigned int ciphered_wrd = vec[2];
std::string out_wrd = decipherer_minos(k, n, ciphered_wrd);
"word"
```




