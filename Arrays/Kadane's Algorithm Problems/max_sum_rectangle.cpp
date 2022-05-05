#include <iostream>
#include <vector>

using namespace std;

int max_sum(vector<vector<int>>& , int, int);

int main() {

    int row, column;
    cout << "Enter the size of row and column" << endl;
    cin >> row >> column;
    vector<vector<int>> mat;
    vector<int> row_mat(column, 0);
    cout << "Enter matrix elements" << endl;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            cin >> row_mat[j];
        }
        mat.push_back(row_mat);
    }
    int final_ans = max_sum(mat, row, column);
    cout << final_ans << endl;
    return 0;
}

int max_sum(vector<vector<int>> &mat , int n, int m) {

    int row = n, col = m;
    int max_sum = INT_MIN;
    
    for(int left = 0; left < col; left++) {

        vector<int> final_mat (row, 0);
        for(int right = left; right < col; right++) {

            for(int i = 0; i < row; i++) {
                final_mat[i] += mat[i][right];
            }

            //kadane's Algorithm
            int current_sum = 0;
            for(int i = 0; i < row; i++) { 
                current_sum += final_mat[i];
                if (current_sum > max_sum) 
                    max_sum = current_sum;
                if(current_sum < 0) 
                    current_sum = 0;
            }
        }
    }
    return max_sum;
}
