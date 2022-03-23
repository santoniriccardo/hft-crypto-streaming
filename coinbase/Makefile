APP_NAME=coinbase

OBJS=coinbase.o

CXX = g++ -m64 -std=c++17
CXXFLAGS = -I. -O3 -L/usr/local/opt/openssl/lib -I/usr/local/opt/openssl/include -lcpprest -lssl -lcrypto -lboost_system -lboost_thread-mt -lboost_chrono-mt

default: $(APP_NAME)

$(APP_NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp
	$(CXX) $< $(CXXFLAGS) -c -o $@

clean:
	/bin/rm -rf *~ *.o $(APP_NAME) *.class



# CC=g++ 
# CFLAGS=-Wall -g -std=c++11 -L/usr/local/opt/openssl/lib -I/usr/local/opt/openssl/include -lcpprest -lssl -lcrypto -lboost_system -lboost_thread-mt -lboost_chrono-mt

# all: TradingBot

# TradingBot: TradingBot.o
# TradingBot.o: TradingBot.c 

# clean:
# 	rm -f TradingBot TradingBot.o
# run: TradingBot
# 	./TradingBot
# make: g++ -Wall -g -std=c++11 -o TradingBot TradingBot.cpp -L/usr/local/opt/openssl/lib -I/usr/local/opt/openssl/include -lcpprest -lssl -lcrypto -lboost_system -lboost_thread-mt -lboost_chrono-mt