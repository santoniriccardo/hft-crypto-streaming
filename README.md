# High Frequency Parallel Crypto Streaming and Valuation

## Summary
We aim to parallelize the streaming and valuation of various cryptocurrencies across a number of cloud hosted exchanges.

## Background

## Challenge
The project is challenging due to the number of different axix's of parallelism available. It is further enhanced due to some aspects that we will need to learn more about as we go about implementing our solution. For starters, some axis' of parallelism are across exchanges, across asset classes, and across running valuation models per asset class. Some of these may need more computation resources than others. For example, the streaming of asset information from a given exchange can be given a core per, but perhaps the actual valuation model for a given asset may need more computation resources than the former. These are problems that we have considered to begin with, but will need to experiment heavily to find the best speedup.

Further, there are a number of different constraints, especially given the fact that we are in the high frequency trading space. We will need to consider optimizations not typically performed in real world examples of software, due to the fact that time constraints pose a hard cutoff. If we cannot process a new piece of market data before the next one comes in, it is essentially useless to us. It is like cracking the enigma machine right after the code has switched. Not only that, but different exchanges may have different latencies, causing our internal valuation model to interact differently depending on the exchange. This could further lead to unique optimizations given what we discover about the markets.

Not only that, but some exchange API's may offer a streaming API, whereas others may offer a pub-sub or polling model. This will further pose challenges and cause us to reconsider some of our parallel approaches as need be.

## Resources
We aim to connect to a number of different popular exchange API's, such as Coinbase, Binance, Pyth network, Coin, etc. While these have resources available, they will all be different, and therefore will pose even more unique constraints and have their own setup costs. We aim and would prefer to code in c++, though may have to consider go depending on how widely available client libraries are.

Further, we aim to use machines with 32-64 cores available, such as some GHC machines, and PSC machines we used throughout the semester.

Besides for the API's and machines, we do not have much other reference except for internship experience in the HFT space, though not directly with crypto.

## Goals and Deliverables
There are a number of different milestones that are applicable for our project.

### 75 %
We aim to be connected to at least 5 exchanges, streaming at least 1 asset from each exchange. The information from these exchanges will feed into one unified valuation model. Synchronization will need to be performed here as necessary.

Further, we will want to have experimented with a number of different parallelization approaches beyond our baseline linear code, and have chosen the best speedup to continue experimenting with further.

### 100 %
We aim to be connected to at least 5 exchanges, streaming at lesat 5 assets from each exchange. This will require parallelism along both axis', probably splitting up each exchage + asset pair into their own core. Further, each asset will have their own valuation service running on a separate core, with concurrency/synchronization as necessary for the API streaming cores to send their information to this other core.

Here, we will need to experiment more heavily with the communication/message passing amongst cores to pass market data to the correct computation core. Further, we will need to experiment with paralellization strategies amongst the core(s) performing the actualy valuation model.

### 125 %
We aim to connect to many more exchanges + asset pairs, increasing the number of cores + resources utilized and performance at the same time. Further, we would like to improve valuation model engine, and perform larger degrees of parallelism along this axis as we increase the complexity of the valuation models.


## Platform Choice
We believe c++ or go will be the most effective, in combination with our platform with a large number of CPUs seeing as we aim to heavily utilize independent cores for their own respective computations. Further, lots of these operations will be io intensive such as streaming information, and will therefore be less suited to a GPU architecture for example.

## Schedule
