# High Frequency Parallel Crypto Streaming and Valuation

## Summary
We aim to parallelize the streaming and valuation of various cryptocurrencies across a number of cloud hosted exchanges.

## Background

## Challenge
The project is challenging due to the number of different axix's of parallelism available. It is further enhanced due to some aspects that we will need to learn more about as we go about implementing our solution. For starters, some axis' of parallelism are across exchanges, across asset classes, and across running valuation models per asset class. Some of these may need more computation resources than others. For example, the streaming of asset information from a given exchange can be given a core per, but perhaps the actual valuation model for a given asset may need more computation resources than the former. These are problems that we have considered to begin with, but will need to experiment heavily to find the best speedup.

Further, there are a number of different constraints, especially given the fact that we are in the high frequency trading space. We will need to consider optimizations not typically performed in real world examples of software, due to the fact that time constraints pose a hard cutoff. If we cannot process a new piece of market data before the next one comes in, it is essentially useless to us. It is like cracking the enigma machine right after the code has switched.

## Resources

## Goals and Deliverables

## Platform Choice

## Schedule
