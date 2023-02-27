/* Question 3: This solution provides an implementation of a Bag data structure with its corresponding methods. The Bag is implemented using a C++ class that contains 
a vector as its internal data structure. I am aware there a Unordered sets in the standard template library in C++ but I am not familiar with it so I decided to go with 
this structure. */

#include <iostream>
#include <vector>
using namespace std;

class Bag {
public:
    void add(const int element) {
        elements.push_back(element);
    }

    bool remove(const int element) {
        for (auto it = elements.begin(); it != elements.end(); ++it) {
            if (*it == element) {
                elements.erase(it);
                return true;
            }
        }
        return false;
    }

    int find(const int element) const {
        for (auto it = elements.begin(); it != elements.end(); ++it) {
            if (*it == element) {
                return *it;
            }
        }
        return -1;
    }

    vector<int> findAll(const int element) const {
        vector<int> result;
        for (auto it = elements.begin(); it != elements.end(); ++it) {
            if (*it == element) {
                result.push_back(*it);
            }
        }
        return result;
    }

    void display() const {
        for (auto it = elements.begin(); it != elements.end(); ++it) {
            cout << *it << '\t';
        }
        cout << endl;
    }

private:
    vector<int> elements;
};

int main(){

    Bag uset;
    uset.add(2);
    uset.add(4);
    uset.add(6);
    uset.add(4);
    uset.display();
    cout << uset.find (6) << endl;
    vector <int> findall= uset.findAll(4) ;
    for (auto it = findall.begin(); it != findall.end(); ++it){
        cout << *it <<'\t';
    }
    cout << endl;
}