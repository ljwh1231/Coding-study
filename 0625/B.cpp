#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Cows {
public:
    string name;
    int milk_sum;
    Cows (string _name) {
        name = _name;
        milk_sum = 0;
    }
};

void add_milk(Cows* _cow, string _name, int milk) {
    for(int i = 0; i < 7; i++) {
        if(_cow[i].name == _name) {
            _cow[i].milk_sum += milk;

            break;
        }
    }
}

bool compare(Cows a, Cows b) {
    if(a.milk_sum < b.milk_sum) {
        return true;
    }
    else if(a.milk_sum == b.milk_sum) {
        return a.name < b.name;
    } else {
        return false;
    }
}

int main() {
    Cows bessie = Cows("Bessie");
    Cows elsie = Cows("Elsie");
    Cows daisy = Cows("Daisy");
    Cows gertie = Cows("Gertie");
    Cows annabelle =Cows("Annabelle");
    Cows maggie = Cows("Maggie");
    Cows henrietta = Cows("Henrietta");

    Cows rank[7] = { bessie, elsie, daisy, gertie, annabelle, maggie, henrietta };
    // vector<Cows> cow_list;

    // cow_list.push_back(bessie);
    // cow_list.push_back(elsie);
    // cow_list.push_back(daisy);
    // cow_list.push_back(gertie);
    // cow_list.push_back(annabelle);
    // cow_list.push_back(maggie);
    // cow_list.push_back(henrietta);
    

    int sessions;
    cin >> sessions;

    for(int i = 0; i < sessions; i++) {
        string cow;
        int milk;
        cin >> cow >> milk;
        add_milk(rank, cow, milk);
        sort(rank, rank + 7, compare);
    }
    int iter = 0;
    for(int i = 1; i < 7; i++) {
        if(rank[0].milk_sum != rank[i].milk_sum){
            if(rank[i].milk_sum == rank[i + 1].milk_sum) {
                cout << "Tie" << endl;
                break;
            } else {
                cout << rank[i].name << endl;
                break;
            }
        }
        else{
            if (i == 6)
                cout << "Tie" << endl;
        }
    }
    return 0;
}