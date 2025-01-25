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


