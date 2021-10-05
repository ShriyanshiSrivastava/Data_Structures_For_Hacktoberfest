#include <iostream>

using namespace std;

//defining the class Shape to demonstrate the concept of Hierarchial Inheritence in CPP
class Shape {
    //protected member variables are only accessible within the class and its descendent classes
    protected:
        float width, height;

    //public members are accessible everywhere
    public:
        void setDimensions(float w, float h) {
            cout << "Setting the Dimensions using the parent Class: Shape\n";
            cout << "The dimensions are: " << w << " and " << h << "\n\n";

            width = w;
            height = h;
        }
};

//Class Rectangle inherites the Shape class
class Rectangle: public Shape {
    //Method Overriding
    public: float area() {
        return (width * height);
    }
};

//Class Triangle inherites the Shape class
class Triangle: public Shape {
    //Method Overriding
    public: float area() {
        return (width * height / 2);
    }
};

//Defining the main method to access the members of the class
int main() {

    cout << "\n\nWelcome to Studytonight :-)\n\n\n";
    cout << " =====  Program to demonstrate the concept of Hierarchial Inheritence in CPP  ===== \n\n";

    //Declaring the Class objects to access the class members
    Rectangle rectangle;
    Triangle triangle;

    rectangle.setDimensions(5, 3);
    triangle.setDimensions(2, 5);

    cout << "\nArea of the Rectangle computed using Rectangle Class is : " << rectangle.area() << "\n\n\n";
    cout << "Area of the Triangle computed using Triangle Class is: " << triangle.area();

    cout << "\n\n\n";

    return 0;
}
