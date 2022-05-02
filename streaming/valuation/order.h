#ifndef INTERNAL_ORDER_H_
#define INTERNAL_ORDER_H_

enum InternalOrderType { BID, ASK };

class Order {
 	public:
	Order(double price, double volume, InternalOrderType orderType) : price(price), volume(volume), orderType(orderType) {}
	
	double getPrice() const { return price; }

	double getVolume() const { return volume; }
	void setVolume(double volume) { this->volume = volume; }

	InternalOrderType type() const { return orderType; }

	private:
	const double price;
	double volume;
	const InternalOrderType orderType;
};

#endif  // INTERNAL_ORDER_H_
