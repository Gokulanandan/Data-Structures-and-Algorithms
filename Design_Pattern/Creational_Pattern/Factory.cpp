#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;
class Pizza {
    public:
        virtual void prepare() = 0;
        virtual void bake() = 0;
        virtual void cut() = 0;
        virtual void box() = 0;
        virtual ~Pizza()=default; 
};

class cheesePizza : public Pizza {
    public:
        void prepare(){
            cout<<"Started Preparing CheesePizza"<<endl;
        }
        void bake(){
            cout<<"Baking in Progress"<<endl;
            this_thread::sleep_for(chrono::seconds(2));
        }
        void cut(){
            cout<<"Cutting Cheese Pizza"<<endl;
            
        }
        void box(){
            cout<<"Packing Cheese Pizza"<<endl;
        }
};
class vegPizza : public Pizza {
    public:
        void prepare(){
            cout<<"Started Preparing VegPizza"<<endl;
        }
        void bake(){
            cout<<"Baking in Progress"<<endl;
            this_thread::sleep_for(chrono::seconds(2));
        }
        void cut(){
            cout<<"Cutting Veg Pizza"<<endl;
            
        }
        void box(){
            cout<<"Packing Veg Pizza"<<endl;
        }
};

class pizzaFactory{
    public:
        static Pizza* createPizza(string type){
            if(type == "Cheese")
                return new cheesePizza();
            else if(type == "Veg") {
                return new vegPizza();
            } else {
                return nullptr;
            }
        }
};



int main() {
    string pizzatype;
    cout<<"Enter the type of Pizza you want 1.Cheese 2.Veg"<<endl;
    cin>>pizzatype;
    auto pizza = pizzaFactory::createPizza(pizzatype);
    if(pizza){
        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();
        cout<<"pizza is ready"<<endl;
    } else {
        cout<<"Unknown Type"<<endl;
    }
    return 0;
}