//
//  main.cpp
//  Test5Revision
//
//  Created by Laura Walsh on 27/03/2019.
//  Copyright © 2019 Laura Walsh. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;


double average_2d(int n, int m){
    
    if(n<0||m<0){
        cout << "Invalid array size -quit" << endl;
        exit(1);
    }
    else if(n<=0||m<=0){
        cout << "Invalid array size -quit" << endl;
        exit(1);
    }
    else if(n==0||m==0){
        cout << "Invalid array size -quit" << endl;
        exit(1);
}
    
    double** array = new double*[n];
    for(int i=0; i< n; i++){
        array[i] = new double[m];
    }
    
    
    srand((unsigned)time(NULL));
    for (int i =0; i< n; i++){
        cout << endl;
        for(int j=0; j< m; j++){
            array[i][j] = rand()% 100;
            cout << array[i][j] << ",  ";
        }
    }
    
    double average =0.;
    for(int i=0; i< n; i++)
        for(int j=0; j< m; j++) average += array[i][j];
    
    average /= (n*m);
    cout << endl<<"Average of 2d array is: " << average;
    
    for(int i =0; i< n; i++) delete[] array[i];
    delete[] array;
    
    return average;
    
    
}

int max_3d(int n, int m, int k){
    if (n <= 0 || m <= 0 || k <= 0) {
        cout << "Invalid array size - quit" << endl;
        exit(1);
    }
    
    int*** array = new int**[n];
    for(int i=0;i<n; i++){
        array[i] = new int*[m];
        for(int j=0; j<m;j++)
            array[i][j] = new int[k];
    }
    
    
    srand((unsigned)time(NULL));
    for(int i=0; i< n; i++)
        for(int j=0; j< m; j++)
            for(int h=0; h< k; h++)
                array[i][j][h] = rand()% 100;
    
    
    for(int i=0; i< n; i++){
        for(int j=0; j< m; j++){
            cout << endl;
            for(int h=0; h< k; h++){
                cout << array[i][j][h] << ", " <<endl;
            }}}
    
    int max_v = array[0][0][0];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int l = 0; l < k; l++)
                if (array[i][j][k] > max_v) max_v = array[i][j][k];
    
    
    cout << endl<< "Max value of 3d array is : " << max_v;
    
    
    for(int i =0; i< n; i++){
        for(int j=0; j< m; j++) delete[] array[i][j];
        delete[] array [i];
    }
    delete[] array;
    
    return max_v;
    
    
}









int main(){
    
    average_2d(2, 3);
    
    cout << endl << endl;
    
    max_3d(2,2,2);
    
    return 0;
}
