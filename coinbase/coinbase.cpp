#include <iostream>
#include <cpprest/ws_client.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

using namespace web::websockets::client;

class CoinbaseClient {
    public: 
        void connectToWebsocket();
};

void CoinbaseClient::connectToWebsocket() {
    constexpr auto WebSocketFeed{ U("wss://ws-feed.pro.coinbase.com") };
    // constexpr auto RequestStatus{ "{\"type\": \"subscribe\", \"channels\" : [{ \"name\": \"heartbeat\", \"product_ids\" : [\"ETH-USD\"] }]}" };

    json req = {
        {"type", "subscribe"},
        {"product_ids", {"ETH-USD"}},
        {"channels", {"ticker"}}
    };

    const auto RequestStatus{req.dump()};

    web::websockets::client::websocket_client webSocketClient;

    try {
        webSocketClient.connect(WebSocketFeed).wait();

        websocket_outgoing_message msg;
        msg.set_utf8_message(RequestStatus);
        webSocketClient.send(msg).wait();

        while (true) {
            auto receivedTask = webSocketClient.receive().then([](websocket_incoming_message ret_msg) {
                auto s = ret_msg.extract_string();
                std::cout << "Received" << s.get() << std::endl;
            });
            receivedTask.wait();
        }
        webSocketClient.close().wait();
    }
    catch (websocket_exception& e) {
        std::cout << "Websocket exception" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Other exception" << std::endl;
    }
}

int main() {
    CoinbaseClient cc;
    cc.connectToWebsocket();
    std::cout << "Hello World!";
    return 0;
}


    // constexpr auto WebSocketFeed{ U("wss://ws-feed.pro.coinbase.com") };
    // constexpr auto RequestStatus{ "{\"type\": \"subscribe\", \"channels\" : [{ \"name\": \"heartbeat\", \"product_ids\" : [\"ETH-EUR\"] }]}" };
    // web::websockets::client::websocket_client m_webSocket;
    // try {
    //     m_webSocket.connect(WebSocketFeed).wait();
    //     auto receivedTast = m_webSocket.receive().then([this](websocket_incoming_message ret_msg) {
    //     auto s = ret_msg.extract_string();
    //         m_logger->info("s = " + s.get());
    //     });

    //     websocket_outgoing_message msg;
    //     msg.set_utf8_message(RequestStatus);
    //     m_webSocket.send(msg).wait();
    //     receivedTast.wait();
    //     m_webSocket.close().wait();
    // }
    // catch (websocket_exception& e) {
    //     m_logger->error("coinbase: exception when setting websocket: " + string{ e.what() });
    // }
    // catch (std::exception& e) {
    //     m_logger->error("coinbase: exception when setting websocket: " + string{ e.what() });
    // }