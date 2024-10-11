//Name:Iliya Ebadi
//ID: 168935237
//Email: tebadi@myseneca.ca
#ifndef SENECA_CC_H_
#define SENECA_CC_H_
#include <iostream>

namespace seneca {
    class CC {
    private:
        char* name;                
        unsigned long long number;  
        short cvv;                 
        short expMonth;            
        short expYear;             

        
        void display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const; 
        bool validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear) const; 
        void prnNumber(unsigned long long CCnum) const; 

    public:
        CC();  
        ~CC(); 

        
        void set();
        void cleanUp();
        bool isEmpty() const;

        void set(const char* cc_name, unsigned long long cc_no, short cvv, short expMon = 12, short expYear = 24);

 
        void display() const; 
    };
}

#endif
