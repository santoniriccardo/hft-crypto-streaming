enum OrderType { BID, ASK };

class Order {
 	public:
	Order(double price, double quantity, OrderType orderType) : price(price), quantity(quantity), orderType(orderType) {}
	
	double getPrice() const { return price; }

	double getQuantity() const { return quantity; }

	OrderType type() const { return orderType; }

	private:
	const double price;
	const double quantity;
	const OrderType orderType;
};