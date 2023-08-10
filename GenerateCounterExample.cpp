#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> bruteForce(vector<int> arg){
	vector<vector<int>> solutions;
	int n = arg.size();
	for(int i = 0; i < n-3; i++)
		for(int j=i+1; j<n-2; j++)
			for(int k=j+1; k<n-1; k++)
				for(int l=k+1; l<n; l++)
					if(arg[i]+arg[j]+arg[k]+arg[l]==0){
						vector<int> temp{arg[i], arg[j], arg[j], arg[l]};
						solutions.push_back(temp);
					}
	return solutions;
} 

vector<int> studentSolution(vector<int> arg){
	int n = arg.size();
	int x0 = 0;
	int y0 = n-1;
	int x1 = 1;
	int y1 = n-2;
	while(x0 != y0){
		int a = arg[x0]+arg[y0];
		a*=-1;
		while(x1 != y1 && x1<n && y1>0){
			if(arg[x1]+arg[y1] < a)
				x1++;
			else if(arg[x1]+arg[y1] > a)
				y1--;		
			else{
				vector<int> solution {arg[x0], arg[x1], arg[y0], arg[y1]};
				return solution; 
			}
		}
		if(a*-1<=0)
			x0++;
		else
			y0--;
		x1=x0+1;
		y1=y0-1;
	}
	vector<int> v;
    return v;
}

int testing()
{
	set<int> tempTestCase;
	vector<int> testCase;
	for(int i=0; i<10; i++){
		tempTestCase.insert(rand()%20-10);
	}
	for(int c:tempTestCase)
	    testCase.push_back(c);
	sort(testCase.begin(), testCase.end());
	vector<vector<int>> solutions = bruteForce(testCase);
	vector<int> student = studentSolution(testCase);	
	if(student.size() != 0){
		cout << "Try again!";
		for(int a: testCase)
			cout << a << " ";
		cout<<endl;
		return -1;
	}
	else if(student.size() == 0 && solutions.size() != 0){
		cout << "Didn't work for test case: ";
		for(int a: testCase)
			cout << a << " ";
		cout << "\nMissed solutions: \n";
		for(vector<int> b: solutions)
			cout << b[0] << " "<< b[1] << " "<< b[2] << " "<< b[3] << endl;
	}	
	return 0;
}

int main(){
    bool notFound = true;
    /*while(notFound){
        if(testing()==0)
            notFound = false;
    }*/
	for(int i=0;i<100;i++)
		if(testing()==0)
			break;
    return 0;
}