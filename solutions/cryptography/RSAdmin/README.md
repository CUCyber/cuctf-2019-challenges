# RSAdmin

This is an RSA challenge where the vulnerability is prime reuse. If we download the keylist and compare every key's N to every other key using the GCD algorithm, we can determine if a prime was reused. If a prime *was* reused, the GCD of two N's will not be 1.

In this case, both Mollie and Randolph's keys (N) have a GCD != 1. We can use this to trivially factor either key, recreate their private key, and sign the message as an Administrator.
