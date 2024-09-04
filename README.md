# Encryption and Decryption Algorithm

## Overview

This repository contains an encryption and decryption algorithm designed to shift characters in a string by a specified key. The encryption process handles words and spaces differently, incrementing the key for each subsequent word. The decryption process reverses the encryption, relying on a dictionary to determine the correct key for each word.

## Encryption Algorithm

### How It Works

1. **Character Shifting:** Each character in the input string is shifted by a specified key value (`toIncrement`). 
   - Example: With `toIncrement = 3` and input "hello":
     - `h -> k`
     - `e -> h`
     - `l -> o`
     - `l -> o`
     - `o -> r`
   - Special Handling:
     - If `z` and `toIncrement = 1`, it wraps around to `a`.
     - If `toIncrement` is negative (e.g., `-2`), it decrements each character accordingly.
   
2. **Handling Spaces:** The key value increments by 2 for each subsequent word.
   - Example: For the sentence "Beauty of nature" with an initial key of 2:
     - "Beauty" is encrypted with key 2.
     - "of" is encrypted with key 4.
     - "nature" is encrypted with key 6.
   - Result: `"Dgcwva sj tgzaxk"`

## Decryption Algorithm

### How It Works

1. **Reverse Character Shifting:** Characters are shifted back by the key value used during encryption.
   - The key is negative of the encryption key.
   - Example: For the encrypted word "CCTJWU" with a key of -2, the decryption will return "AARHUS".
   
2. **Handling Dictionary Entries:** The algorithm uses a dictionary (e.g., `Dictionary.txt`) to determine the exact key for decryption. This ensures that decrypted words match dictionary entries.

### Example

Sentence Based on dictionary:
```
AARHUS AARON ABABA
```

Encryption of "AARHUS AARON ABABA" with `toIncrement = 2` results in:
```
CCTJWU EEVSR GHGHG

```

Decryption of `"CCTJWU EEVSR GHGHG"` will use a key of `-2` to return to `"AARHUS AARON ABABA"`.

## Usage

1. **Encryption:**
   - Input: `"your text"`
   - Key: `2`
   - Output: Encrypted text with incremental keys.

2. **Decryption:**
   - Input: Encrypted text
   - Dictionary: `Dictionary.txt`
   - Output: Decrypted text using the dictionary to find the correct key.

## Files

- `Encryption_Algorithm.cpp`: Contains the encryption algorithm.
- `Decryption_Algorithm.cpp`: Contains the decryption algorithm.
- `Dictionary.txt`: A sample dictionary for decryption.
