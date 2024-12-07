#include <iostream>
#include <math.h>
#include <string>
#include <sstream> // stringstream : used to manipulate string-based I/O

using namespace std;
float decimal_to_binary(int number){

    float answer = 0;
    int i = 0;

    while(number != 0){
        float bit = number & 1;  //using answer and bit as float. why ?
        answer += (bit * pow(10 , i));
        number >>= 1;
        i++;
    }

    cout << "Answer in binary system is  " << answer << endl;
}

float binary_to_decimal(int number){

    float answer = 0;
    int i = 0;

    while(number != 0){
        float digit = number % 10;
        if(digit == 1){
            answer += pow(2 , i);
        }
        number /= 10;
        i++;
    }

    cout << "Answer in decimal system is : " << answer << endl;
}

float decimal_to_hexadecimal(int number){
    //Convert decimal to hexa-decimal
    stringstream ss;
    ss << hex << number; //Use 'hex' manipulator to convert to hexadecimal

    string hexa_decimal = ss.str();

    cout << "Answer in hexadecimal system is : " << hexa_decimal << endl;

}

float hexadecimal_to_decimal(string hex_number){
    int decimal_number;
    stringstream ss;
    ss << hex_number;
    ss >> hex >> decimal_number;

    cout << "Answer in decimal system is : " << decimal_number << endl;
}

string binary_to_hexadecimal(const string& binary){
    unsigned long decimal = stoul(binary, nullptr, 2);

    stringstream hex_stream;
    hex_stream << hex << decimal;
    cout << "Answer in hexa_decimal system is : " ;
    cout << hex_stream.str() << endl;
}

float hexadecimal_to_binary(string hex_number){
    float new_number = hexadecimal_to_decimal(hex_number);
    decimal_to_binary(new_number);
}
int main(){
    string option = "Yes";
    while(option == "Yes"){

        int choice;

        cout << "Your choices :- " << endl;
        cout << "1. Decimal to Binary" << endl;
        cout << "2. Binary to Decimal" << endl;
        cout << "3. Decimal to Hexadecimal" << endl;
        cout << "4. Hexadecimal to Decimal" << endl;
        cout << "5. Binary to Hexadecimal" << endl;
        cout << "6. Hexadecimal to Binary" << endl;

        cout << "Enter your choice : ";
        cin >> choice;
        
        if (choice == 1){
            int number;
            cout << "Enter your desired number : ";
            cin >> number;
            decimal_to_binary(number);
        }

        else if (choice == 2){
            int number;
            cout << "Enter your desired number : ";
            cin >> number;
            binary_to_decimal(number);
        }

        else if (choice == 3){
            int number;
            cout << "Enter your desired number : ";
            cin >> number;
            decimal_to_hexadecimal(number);
        }

        else if (choice == 4){
            string hex_number;
            cout << "Enter a hexadecimal number : ";
            cin >> hex_number;
            hexadecimal_to_decimal(hex_number);
        }

        else if (choice == 5){
            string number;
            cout << "Enter your desired number : ";
            cin >> number;
            cout << binary_to_hexadecimal(number);
        }

        else if (choice == 6){
            string hex_number;
            cout << "Enter a hexadecimal number : ";
            cin >> hex_number;
            hexadecimal_to_binary(hex_number);
        }

        else{
            cout << "You have entered an invalid choice!" << endl;
        }
        
        cout << "Do you want to continue? (Yes/No) : ";
        cin >> option;
    }
    
    return 0;
}
