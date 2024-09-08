/*
    Sparse Matrix Implementation Array Implementation.
    Author: Owen Walstrom
    Date: 9/8/2024
    
*/

#include <iostream>
#include <vector>
using namespace std;

class SparseMatrix{
    private:
        vector<int> rowArray, columnArray, valueArray;

    public:
        SparseMatrix(){
           rowArray = {};
           columnArray = {};
           valueArray = {};

        }
        void addValue(int row, int column, int value){
            //do not add 0 values to sparse matrix
            if(value != 0){
                //check if row and column of new value is already taken
                for(int i = 0; i < this->rowArray.size(); i++){
                    if(row == this->rowArray[i]){
                        if(this->columnArray[i] == column){
                            cout << "Error: already a value at specificed column and row.\n";
                            return;
                        }
                    }
                }
                this->rowArray.push_back(row);
                this->columnArray.push_back(column);
                this->valueArray.push_back(value);
            }
        }
        int getValue(int targetRow, int targetColumn){
            for(int i = 0; i < this->rowArray.size(); i++){
                if(this->rowArray[i] == targetRow){
                    if(this->columnArray[i] == targetColumn){
                        return this->valueArray[i];
                    }
                }
            }
            cout << "Error: no value at targeted row and column.\n";
            return 0;
        }
        void setValue(int targetRow, int targetColumn, int newValue){
            for(int i = 0; i < this->rowArray.size(); i++){
                if(this->rowArray[i] == targetRow){
                    if(this->columnArray[i] == targetColumn){
                        this->valueArray[i] = newValue;
                        break;
                    }
                }
            }
        }
        void deleteValue(int targetRow, int targetColumn){
            for(int i = 0; i < this->rowArray.size(); i++){
                if(this->rowArray[i] == targetRow){
                    if(this->columnArray[i] == targetColumn){
                        this->rowArray.erase(this->rowArray.begin() + i);
                        this->columnArray.erase(this->columnArray.begin() + i);
                        this->valueArray.erase(this->valueArray.begin() + i);
                    }
                }
            }
        }
        void display(){
            string rowOutput = "[";
            string columnOutput = "[";
            string valueOutput = "[";

            for(int i = 0; i < this->rowArray.size(); i++){
                rowOutput = rowOutput + to_string(this->rowArray[i]) + ",";
                columnOutput = columnOutput + to_string(this->columnArray[i])+ ",";
                valueOutput = valueOutput + to_string(this->valueArray[i])+ ",";
            }
            cout << rowOutput << "]\n";
            cout << columnOutput << "]\n";
            cout << valueOutput << "]\n\n";
        }
};




int main() {
    SparseMatrix myMatrix;
    //populate matrix
    myMatrix.addValue(0, 2, 3);
    myMatrix.addValue(0, 4, 4);
    myMatrix.addValue(1, 2, 5);
    myMatrix.addValue(1, 3, 7);
    myMatrix.addValue(3, 1, 2);
    myMatrix.addValue(3, 2, 6);

    //tests
    myMatrix.display();
    myMatrix.addValue(1, 2, 7);
    myMatrix.display();
    myMatrix.deleteValue(1, 2);
    myMatrix.display();
    myMatrix.addValue(1, 2, 7);
    myMatrix.display();
    myMatrix.getValue(100, 100);
    return 0;
};