# Spelling-Bee C++
Solves The New York Magazine's Spelling Bee puzzle

To test some coding ideas and strategies I had recently acquired I wrote a program which solves the ‘Spelling Bee’ puzzle published in issues of The New York Magazine. The puzzle provides 6 ‘minor’ English characters and 1 ‘major’ English character. Out of the 7 characters total one must construct words greater than 5 characters. Words must always contain the major character at least once (letters can appear multiple times per word). The more words one can come up with which fit these restrictions, the better the solution. 
My program takes a list of 70,000 English words and feeds them into a hash table. I chose to utilize a hash table to ensure a (generally) constant lookup time. The lookup time is essential because a brute force algorithm generates every possible character combination (up to 9 characters) and checks each to see if it is hashed. If it is hashed it is added to the solution. 
An obvious limitation of this system is the word list. The word list does not contain every English word, so clearly some words will be missed.   
 
