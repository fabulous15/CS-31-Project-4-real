//
//  main.cpp
//  CS 31 Project 4
//
//  Created by Guoran Ye on 5/12/18.
//  Copyright © 2018 Guoran Ye. All rights reserved.
//

#include <iostream>
using namespace std;

int tally(const string a[], int n, string target){
    int i;
    int j = 0;
    if (n < 0){
        return -1;
    }
    else{
        for (i = 0; i < n; i++)
            if (a[i] == target){
                j++;
            }
        return j;
    }
}

int findMatch(const string a[], int n, string target){
    int i;
    if (n < 0){
        return -1;
    }
    else{
        if (tally(a, n, target) == 0){
            return -1;
        }
        else{
            for (i = 0; i < n; i++){
                if (a[i] == target){
                    break;
                }
            }
            return i;
        }
    }
}

bool findRun(const string a[], int n, string target, int& begin, int& end){
    int i;
    int j;
    if (findMatch(a, n, target) == -1){
        return false;
    }
    else{
        begin = findMatch(a, n, target);
        j = findMatch(a, n, target);
        for (i = begin + 1; i < n - begin; i++){
            if (a[i] == target){
                j++;
            }
            else{
                break;
            }
        }
        end = j;
        return true;
    }
}

int positionOfMin(const string a[], int n){
    int i;
    string min = a[0];
    for (i = 1; i < n; i++){
        if (a[i] < min){
            min = a[i];
        }
    }
    return findMatch(a, n, min);
}

int moveToEnd(string a[], int n, int pos){
    int i;
    if (n < 0){
        return -1;
    }
    else{
        string tem = a[pos];
        for (i = pos; i < n - 1; i++){
            a[i] = a[i+1];
        }
        a[n-1] = tem;
        return pos;
    }
}

int moveToBeginning(string a[], int n, int pos){
    int i;
    if (n < 0){
        return -1;
    }
    else{
        string tem = a[pos];
        for (i = 0; i < pos; i++){
            a[pos - i] = a[pos - i - 1];
        }
        a[0] = tem;
        return pos;
    }
}

int findDifference(const string a1[], int n1, const string a2[], int n2){
    int i;
    int j = 0;
    if (n1 < 0 || n2 < 0){
        return -1;
    }
    else{
        for (i = 0; i < n1 && i < n2; i++){
            if (a1[i] == a2[i]){
                j++;
            }
            else break;
        }
        return j;
    }
}

int eliminateDups(string a[], int n){
    int i = 1;
    int j = 1;
    int l = 0;
    int k;
    if (n < 0){
        return -1;
    }
    else if (n == 0){
        return 0;
    }
    else{
        for (i = 1; i < n; i++){
            if (a[i] != a[i-1]){
                j++;
            }
            else{
                moveToBeginning(a, n, i);
                l++;
            }
        }
        for (k = 0; k < j; k++){
            a[k] = a[k+l];
        }
        return j;
    }
}

bool subsequence(const string a1[], int n1, const string a2[], int n2){
    int i;
    int j;
    int k = 0;
    for (i = 0; i < n2; i++){
        for (j = k; j < n1; j++){
            if (a2[i] == a1[j]){
                k = j + 1;
                break;
            }
        }
        if (j == n1){
            return false;
        }
    }
    return true;
}

int makeMerger(const string a1[], int n1, const string a2[], int n2, string result[], int max){
    int i;
    int j;
    if (n1 < 0 || n2 < 0){
        return -1;
    }
    else{
        string tem;
        if (n1 + n2 > max){
            return -1;
        }
        else{
            for (i = 0; i < n1; i++){
                result[i] = a1[i];
            }
            for (i = n1; i < n1 + n2; i++){
                result[i] = a2[i-n1];
            }
            for (i = 1; i < n1 +n2; i++){
                for (j = 0; j < i; j++){
                    if (result[i-j] >= result[i-j-1]){
                        break;
                    }
                    else{
                        tem = result[i-j];
                        result[i-j] = result[i-j-1];
                        result[i-j-1] = tem;
                    }
                }
            }
            return n1 + n2;
        }
    }
}

int separate(string a[], int n, string separator){
    int i = 0;
    int j = 0;
    int k;
    if (n < 0){
        return -1;
    }
    else if (n == 0){
        return 0;
    }
    else{
        for (k = 0; k < n; k++){
            if (a[i] < separator){
                moveToBeginning(a, n, i);
                j++;
                i++;
            }
            else if (a[i] > separator){
                moveToEnd(a, n, i);
            }
            else{
                i++;
            }
        }
        return j;
    }
}

int main()
{
    int i;
    string g[4] = { "romanoff", "rogers", "thor", "banner" };
    int s = separate(g, 4, "rogers");
    cout << s << endl;
    for (i = 0; i < 9; i++){
        cout << g[i] << " ";
    }
}
