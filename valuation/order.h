enum OrderType { BID, ASK };

class Order {
 	public:
	Order(double price, double volume, OrderType orderType) : price(price), volume(volume), orderType(orderType) {}
	
	double getPrice() const { return price; }

	double getVolume() const { return volume; }
	void setVolume(double volume) { this->volume = volume; }

	OrderType type() const { return orderType; }

	private:
	const double price;
	double volume;
	const OrderType orderType;
};