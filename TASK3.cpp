#include<iostream>
#include<string>
using namespace std;

string arr[3][3]={
    {"A", "B", "C"},
    {"D", "E", "F"},
    {"G", "H", "I"}
};

void display(string arr1[3][3]){
    for(int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cout << arr1[i][j];
            if(j<2) {
                cout << " | ";
            }
        }
        cout << endl;
        if (i<2){
            cout << "==========\n";
        }
    }
}

bool checkWinner(string arr1[3][3]){
    int count=0, count2=0;
    //ROW CHECK
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(arr1[i][j]=="X")
                count++;
        }
        if(count==3){
            cout << "Player X wins!!";
            return true;
        }
            count=0;
    }
    //COLUMN CHECK
    count=0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(arr1[j][i]=="X")
                count++;
        }
        if(count==3){
            cout << "Player X wins!!";
            return true;
        }
            count=0;
    }
    //diagonal check
    count=0;
           for(int j=0; j<3; j++){
            if(arr1[j][j]=="X")
                count++;
        }
        if(count==3){
            cout << "Player X wins!!";
            return true;
        }
    //RIGHT DIAGONAL 
    count=0;
      for(int j=2; j>=0; j--){
            if(arr1[2-j][j]=="X")
                count++;
        }
        if(count==3){
            cout << "Player X wins!!";
            return true;
        }
    //ROW CHECK
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(arr1[i][j]=="O")
                count2++;
        }
        if(count2==3){
            cout << "Player O wins!!";
            return true;
        }
       
            count2=0;
    }
    //COLUMN CHECK
    count2=0;
        for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(arr1[j][i]=="O")
                count2++;
        }
        if(count2==3){
            cout << "Player O wins!!";
            return true;
        }
      
            count2=0;
    }
//DIAGONAL CHECK
count2=0;
        for(int j=0; j<3; j++){
            if(arr1[j][j]=="O")
                count2++;
        }
        if(count2==3){
            cout << "Player O wins!!";
            return true;
        }
    
      //RIGHT DIAGONAL 
      count2=0;
      for(int j=2; j>=0; j--){
            if(arr1[2-j][j]=="O")
                count2++;
        }
        if(count2==3){
            cout << "Player O wins!!";
            return true;
        }
        
        count2=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(arr1[i][j]!=" "){
                    count2++;
                }
            }
        }
        if(count2==9){
            cout<<"\nIts a draw.\n";
            display(arr1);
            return 0;
        }
    return false;
}

int main(){
    label3:
    display(arr);
    char play1, play2;
    cout << "\nEnter player 1 sign: ";
    cin >> play1;

    if(play1 == 'X')
        play2 = 'O';
    else
        play2 = 'X';

    string box;
    bool val = false;
    string arr2[3][3] = {{" ", " ", " "}, {" ", " ", " "}, {" ", " ", " "}};

    // Play the game
    while(val!=true){
        display(arr2);

        cout << "Player 1 turn.\nEnter box(A-I): ";
        label:
        cin >> box;
        if (box<"A" || box>"I"){
            cout << "\nInvalid choice.\nEnter again";
            goto label;
        }
int count=0;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(arr[i][j] == box && arr2[i][j] == " "){
                    arr2[i][j] = play1;
                    val = checkWinner(arr2);
                    if(val==true){
                    cout<<"Player 1 wins\n";
                      display(arr2);
                   return 0;;}
                   }
                else if(arr[i][j] == box && arr2[i][j] != " "){
                  cout<<"\n!!!Invalid choice.!!!\nEnter again\n"; 
                    goto label;
                }
                  
                }
            
            }
            
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(arr2[i][j]!=" ")
                    count++;
                }
            }
            if(count==9){
                cout<<"\nGame Over!!\nDo you want to play again?(Y/N)";
                cin>>box;
                if(box=="Y" || box=="y"){
                    goto label3;
                }
                else{
                    return 0;
                }
            }
        
count=0;
        display(arr2);

        cout << "Player 2 turn.\nEnter box(A-I): ";
        label2:
        cin >> box;
        if (box<"A" || box>"I"){
            cout << "\nInvalid choice.\nEnter again";
            goto label2;
        }

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(arr[i][j] == box && arr2[i][j] == " "){
                    arr2[i][j] = play2;
                    val = checkWinner(arr2);
                    if(val==true){
                    cout<<"Player 2 wins\n";
                    display(arr2);
                   return 0;}
                }
                 else if(arr[i][j] == box && arr2[i][j] != " "){
                   cout<<"\n!!!Invalid choice.!!!\nEnter again\n"; 
                    goto label;
                }
                
            }
            
                
        }
        for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(arr2[i][j]!=" ")
                    count++;
                }
            }
                    if(count==9){
                cout<<"\nGame Over!!\nDo you want to play again?(Y/N)";
                cin>>box;
                if(box=="Y" || box=="y"){
                    goto label3;
                }
                else{
                    return 0;
                }
            }

    } 

    return 0;
}

