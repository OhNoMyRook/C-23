#include <iostream>
#include <vector>

 
class QueueElement {
    private:
        int value;
        int priority;
    public:
        QueueElement(int in_value, int in_priority){
            value = in_value;
            priority = in_priority;
        }
        int get_priority(){
            return priority;
        };
        int get_value(){
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
      int pi = (ci - 1) / 2;
      if (data[ci].get_priority() <= data[pi].get_priority())
        break;
      T tmp = data[ci];
      data[ci] = data[pi];
      data[pi] = tmp;
      ci = pi;
    }
  }
 
  T poll() {

    int li = data.size() - 1;
    T frontItem = data[0];
    data[0] = data[li];
    data.pop_back();
 
    --li;
    int pi = 0;
 
    while (true) {
      int ci = pi * 2 + 1;
      if (ci > li)
        break;
      int rc = ci + 1;
      if (rc <= li && data[rc].get_priority() < data[ci].get_priority())
        ci = rc;
      if (data[pi].get_priority() >= data[ci].get_priority())
        break;
      T tmp = data[pi];
      data[pi] = data[ci];
      data[ci] = tmp;
      pi = ci;
    }
    return frontItem;
  }
 
  int peek() {
    T frontItem = data[0];
    return frontItem.get_value();
  }
 
  int Count() {
    return data.size();
  }

  bool is_empty(){
    if (data.size()){
        return true;
    }else{
        return false;
    }
  }
   
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