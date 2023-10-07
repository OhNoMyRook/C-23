#include <iostream>
#include <vector>
#include <algorithm>

class Container {
private:
    std::vector<Container*> connections;
    double current_water;
    double total_amount;

public:
    // Конструктор
    Container(){
        current_water = 0;
        total_amount = 1;
    };

    // Методы
    void connectTo(Container &other) {
        connections.push_back(&other);
        other.connections.push_back(this);
        for (auto elem : connections){
            elem->connections.push_back(&other);
            other.connections.push_back(elem);
        }
        for (auto elem : other.connections){
            elem->connections.push_back(this);
            connections.push_back(elem);
        }
        double temp = this -> total_amount;
        double temp_1 = other.total_amount;
        this -> total_amount += other.total_amount;
        for (Container *connection : this->connections) {
            connection->total_amount = this->total_amount;
        }
        this->current_water = (this->current_water*temp+(other.current_water)*temp_1)/(this->total_amount);
        for (Container *connection : this->connections) {
            connection->current_water = this->current_water;
        };
    }

    double getAmount() {
        return this->current_water;
    };

    void addWater(double amount) {
        if ((this->current_water+amount/this->total_amount)<0){
            std::cout << "There is no enough water" << std::endl;
        }else{
            this->current_water += amount/this->total_amount;
            for (Container *connection : this->connections) {
                connection->current_water = this->current_water;
            };
        }
    };
};

int main(){

    Container a;
    Container b;
    Container c;
    Container d;

    d.addWater(8);
    a.addWater(12);
    std::cout << a.getAmount() << " " << b.getAmount() << " " << c.getAmount() << " " << d.getAmount() << std::endl;
    a.connectTo(b);
    std::cout << a.getAmount() << " " << b.getAmount() << " " << c.getAmount() << " " << d.getAmount() << std::endl;
    b.connectTo(c);
    std::cout << a.getAmount() << " " << b.getAmount() << " " << c.getAmount() << " " << d.getAmount() << std::endl;
    b.connectTo(d);
    std::cout << a.getAmount() << " " << b.getAmount() << " " << c.getAmount() << " " << d.getAmount() << std::endl;
    a.addWater(16);
    std::cout << a.getAmount() << " " << b.getAmount() << " " << c.getAmount() << " " << d.getAmount() << std::endl;

    Container e;
    e.connectTo(d);
    std::cout << a.getAmount() << " " << b.getAmount() << " " << c.getAmount() << " " << d.getAmount() << " " << e.getAmount() << std::endl;
    e.addWater(-100);
    std::cout << a.getAmount() << " " << b.getAmount() << " " << c.getAmount() << " " << d.getAmount() << " " << e.getAmount() << std::endl;

    Container f;
    Container g;
    f.connectTo(g);
    std::cout << a.getAmount() << " " << b.getAmount() << " " << c.getAmount() << " " << d.getAmount() << " " << e.getAmount() << " " << f.getAmount() << " " << g.getAmount() << std::endl;
    g.addWater(2);
    std::cout << a.getAmount() << " " << b.getAmount() << " " << c.getAmount() << " " << d.getAmount() << " " << e.getAmount() << " " << f.getAmount() << " " << g.getAmount() << std::endl;
}
