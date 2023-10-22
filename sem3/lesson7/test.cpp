#include <iostream>
#include <vector>

class QueueElement {
    private:
        int value;
        int priority;
    public:
        QueueElement(int in_value, int in_priority) {
            value = in_value;
            priority = in_priority;
        }

        int get_priority() {
            return priority;
        };

        int get_value() {
            return value;
        };
};

template<typename T>
class PriorityQueue {
    private:
        std::vector<T> data;
    public:
        PriorityQueue() {}

        void push(T item) {
            data.push_back(item);  
            int ci = data.size() - 1;
            while (ci > 0) {
                int parent_index = (ci - 1) / 2;
                if (data[parent_index].get_priority() <= data[ci].get_priority()) {
break;
}
std::swap(data[parent_index], data[ci]);
ci = parent_index;
}
};

    T poll() {
    if (empty()){
        } else {
            int max_element_index = -1; 
            for (int i = 0; i < data.size() - 1; i++) {
                if (data[i].get_priority() > data[max_element_index].get_priority()) {
                    max_element_index = i;
                }
            }
            if (data[max_element_index].get_priority() == 
                data[data.size() - 1].get_priority()) {
                max_element_index = data.size() - 1;
            }  
            std::swap(data[0], data[max_element_index]);
            data.pop_back();
            return data[0];
        };
    };

    int peek() {
    T frontItem = data[0];
    return frontItem.get_value();
  }
 
  int Count() {
    return data.size();
  }

    bool empty() {
        return data.empty();
    };
};

int main()
{
    QueueElement a(7, 6);
    QueueElement b(8, 5);
    QueueElement c(11, 4);
    QueueElement d(14, 3);
    QueueElement e(20, 2);
    QueueElement f(109, 1);

  
    PriorityQueue<QueueElement> pq;
    
    
    pq.push(a);
    pq.push(b);
    pq.push(c);
    pq.push(d);
    pq.push(e);
    pq.push(f);
    
    std::cout << "Size of pq is : " << pq.Count() << std::endl;
    std::cout << "This element has max priority: " << pq.peek() << std::endl;
    
    pq.poll();

    std::cout << "Size of pq is : " << pq.Count() << std::endl;
    std::cout << "This element has max priority: " << pq.peek() << std::endl;
    
    pq.poll();

    std::cout << "Size of pq is : " << pq.Count() << std::endl;
    std::cout << "This element has max priority: " << pq.peek() << std::endl;

    pq.poll();

    std::cout << "Size of pq is : " << pq.Count() << std::endl;
    std::cout << "This element has max priority: " << pq.peek() << std::endl;

    //pq.poll();

    //std::cout << "Size of pq is : " << pq.Count() << std::endl;
    //std::cout << "This element has max priority: " << pq.peek() << std::endl;
    
    return 0;
}