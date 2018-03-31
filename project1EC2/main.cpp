/*  Program: Vending Machine
 Author: Miguel Bravo
 Class: CSCI 110
 Date: 9/19/14
 Description: Project 1 - EC version 2
 
 I certify that the code below is my own work.
	
	Exception(s): N/A
 
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    
    // decalare variables
    int purchaseAmount;
    int change;
    int quarter;
    int dime;
    int nickel;
    int flag = true;
    int flag2=true;
    int coins = 0;
    int totalPurchaseAmount=0;
    int avgPurchaseAmount;
    int totalPurchase=0;
    int numQ=0;
    string reply;
    //Temp placeholders
    int x;
    int y;
    
    // Welcome message
    cout << "Simple Vending Program for MB (E.C. Version 2) \n";
    
    // while loop for repeated purchases
    while (flag) {
        cout << "\nEnter a purchase amount [5-100] --> ";
        cin >>  purchaseAmount;
        
        // total purchase amount
        totalPurchaseAmount += purchaseAmount;
        
        // control statement
        if(purchaseAmount>=5 && purchaseAmount<=100 && purchaseAmount%5==0){
            
            // total purchase count
            totalPurchase++;
            
            cout << "You entered a purchase amount of "<< purchaseAmount << " cents." << endl;
            
            // calculate change
            change = 100 - purchaseAmount;
            cout << " \nYour change of " << change << " cents ";
            
            
            //calc quarter
            quarter = change / 25;
            coins += quarter;
            x = change - (quarter*25);
            cout << "is given as ";
            
            cout << "\n" << x << "\n";
            
            
            
            if(numQ<=4){
                if(quarter==1){
                    numQ+=1;
                cout << quarter << " Q, ";
                //numQ -=quarter;
                   
                cout << "\n" << numQ << "\n";
                    
                }else
                if(quarter==2){
                    numQ+=2;
                    cout << quarter << " Q, ";
                    //numQ -=quarter;
                    
                    cout << "\n" << numQ << "\n";
                }else
                if(quarter==3){
                    numQ+=3;
                    cout << quarter << " Q, ";
                    //numQ -=quarter;
                    
                    cout << "\n" << numQ << "\n";
                }else
                if(quarter==4){
                    numQ+=4;
                    cout << quarter << " Q, ";
                    //numQ -=quarter;
                    
                    cout << "\n" << numQ << "\n";
                }else{
                quarter=0;
                cout << quarter << " Q, ";
            }
            }
            
            
            
            // calc dime
            dime = x/10;
            y = x - (dime*10);
            cout << dime << " D, ";
            coins += dime;
            
            // calc nickel
            nickel = y/5;
            cout << nickel << " N.\n";
            coins += nickel;
            
            // value of total coins entered
            cout << "The value of your " << coins << " coins adds up to " << change << " cents. \n";
            
            cout << "Thank you for using my program. \n\n";
            
            flag=false;
            flag2=true;
            
        }else{
            cout << "Unable to process an invalid purchase amount of " << purchaseAmount << " cents. \nOnly coins between [5-100] and a multiple of 5 cents can be inserted.\n" << endl;
            
            // subtract invalid input
            totalPurchaseAmount -= purchaseAmount;
            
            // flag
            flag=false;
            flag2=false;
        }
        
        while(flag2){
            
            // Process again?
            cout << "\nProcess again (y/n)?  \n";
            cin >> reply;
            
            if("n"==reply){
                cout << "\nThank you for using my program.\n";
                flag=false;
                flag2=false;
            }else if("y"==reply) {
                //reset coin count
                coins = 0;
                // flag mod
                flag = true;
                flag2=false;
            }else {
                cout << "Invalid input. You did not enter 'y' or 'n'. Please enter again. \n";
                flag=false;
                flag2=true;
            }
        }
    }
    
    if(totalPurchaseAmount>0){
        
        cout << "\nPurchase summary: \n";
        // totalPurchaseAmount
        cout << "Your total purcahse amount is "<< totalPurchaseAmount << ".\n";
        
        // avg purchase amount
        avgPurchaseAmount = totalPurchaseAmount/totalPurchase;
        cout << "Your average purchase amount is " << avgPurchaseAmount <<
        ".\n";
    }
}


