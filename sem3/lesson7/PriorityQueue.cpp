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
      int pi = (ci-1) / 2;
      if (data[ci].get_priority() >= data[pi].get_priority())
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
      int ci = pi*2 + 1;
      if (ci > li)
        break;
      int rc = ci+1;
      if (rc <= li && data[rc].get_priority() < data[ci].get_priority())
        ci = rc;
      if (rc <= li && data[rc].get_priority() > data[ci].get_priority())
        ci = ci;
      if (data[pi].get_priority() <= data[ci].get_priority())
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
    if (Count()){
        return true;
    }else{
        return false;
    }
  }
   
};


int main()
{
    QueueElement a(7, 5);
    QueueElement b(8, 6);
    QueueElement c(11, 4);
    QueueElement d(14, 1);
    QueueElement e(20, 2);
    QueueElement f(109, 3);
    QueueElement g(71, 0);
    QueueElement h(-3, 7);

    //Элементы имеют данные (числовые значения) - первый аргумент, и приоритеты (чем меньше значение приоритета, тем раньше "обслуживается" этот элемент) - второй аргумент
    //В данном наборе элементов порядок "обслуживания" следующий: 71(имеет высший приоритет среди остальных - 0), 14 (приоритет = 1), 20 (=2), 109, 11, 7, 8, -3
    //Можно бы было также заменить числовые данные на, условно, имена, заменив тип данных с инта на чар
  
    PriorityQueue<QueueElement> pq;
    
    
    pq.push(a);
    pq.push(b);
    pq.push(c);
    pq.push(d);
    pq.push(e);
    pq.push(f);
    pq.push(g);
    pq.push(h);

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

    pq.poll();

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
    
    //В консоль выведены все элементы в порядке приоритетности, и, к счастью, этот порядок совпадает с указанным в 107 строке 

    return 0;
}