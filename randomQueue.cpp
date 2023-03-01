/*4.	Q4: I spent a good amount of time solving this problem. I had a clear understanding of the big idea, which was to implement a queue that selects a random element
 to remove. At first, I tried using components from a previous problem (q3 in the same assignment). However, the challenging part was figuring out how to maintain constant
  time complexity for both the add() and remove() operations. After considering a few different options, I decided to use two vectors: one for storing the elements and 
  another for storing the indices. I used the push_back() function to add elements to the elements vector, and kept track of their positions in the vector using indices. 
  The remove() function selects a random index from the indices vector, uses it to retrieve the corresponding element from the elements vector, and then removes that index 
  from the indices vector. This way, I was able to maintain the constant time complexity requirement for both add() and remove() operations..*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class randomQueue {
public:
    void add(int element) {
        elements.push_back(element);
        indices.push_back(elements.size() - 1);
    }

    int remove() {
        int random_index = randomGen();
        int random_element = elements[indices[random_index]];
        indices[random_index] = indices.back();
        indices.pop_back();
        return random_element;
    }

      void display()  {
       
        for (const auto& idx : indices) {
        std::cout << elements[idx] << " ";
    }
        cout << endl;
    }

private:
    vector<int> elements;
    vector<int> indices;

    int randomGen() {
        static bool seeded = false;
        if (!seeded) {
            srand(time(nullptr));
            seeded = true;
        }
        return rand() % indices.size();
    }

    
  
};

int main() {
    randomQueue test;
    test.add(1);
    test.add(2);
    test.add(3);
    test.add(4);
    test.add(5);

    test.remove();
    test.display();

    test.remove();
    test.remove();
    test.display();


   


   
}
