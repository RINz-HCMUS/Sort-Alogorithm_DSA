#include <iostream>
#include <string.h>
#include <chrono>
#include <time.h>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

void Output100(){
    ifstream ifs("names.txt");
    ofstream ofs("100.txt");

    vector<string> input;
    string s = "";
    
    while(!ifs.eof()){
        getline(ifs, s);
        input.push_back(s);    
    }

    int index;
    for(int i = 0; i < 100; i++){
        index = rand() % input.size();
        ofs << input[index];
        if(i != 99)
            ofs << endl;
    }

    ifs.close();
    ofs.close();

    return;
}


void Output1000(){
    ifstream ifs("names.txt");
    ofstream ofs("1000.txt");

    vector<string> input;
    string s = "";
    
    while(!ifs.eof()){
        getline(ifs, s);
        input.push_back(s);    
    }

    int index;
    for(int i = 0; i < 1000; i++){
        index = rand() % input.size();
        ofs << input[index];
        if(i != 999)
            ofs << endl;
    }

    ifs.close();
    ofs.close();

    return;

}


void Output10000(){
    ifstream ifs("names.txt");
    ofstream ofs("10000.txt");

    vector<string> input;
    string s = "";
    
    while(!ifs.eof()){
        getline(ifs, s);
        input.push_back(s);    
    }

    int index;
    for(int i = 0; i < 10000; i++){
        index = rand() % input.size();
        ofs << input[index];
        if(i != 9999)
            ofs << endl;
    }

    ifs.close();
    ofs.close();

    return;

}


void Output50000(){
       ifstream ifs("names.txt");
    ofstream ofs("50000.txt");

    vector<string> input;
    string s = "";
    
    while(!ifs.eof()){
        getline(ifs, s);
        input.push_back(s);    
    }

    int index;
    for(int i = 0; i < 50000; i++){
        index = rand() % input.size();
        ofs << input[index];
        if(i != 49999)
            ofs << endl;
    }

    ifs.close();
    ofs.close();

    return;

}

void ChangeOutput(){
    srand(time(0));
    Output100();
    Output1000();
    Output10000();
    Output50000();

    return;
}

void binarySearch(vector<string> a, const string s) {
    int left = 0;
    int right = a.size() - 1;

    while(left <= right){
        int mid = left + (right - left) / 2;

        if(a[mid] == s)
            return;
        
        else if(a[mid] < s)
            left = mid + 1;
         
        else
            right = mid - 1;
        
    }

    return; 
}


void BubbleSort(string filename){
    // input
    ifstream ifs(filename);

    vector<string> a, b;
    string s = "";
    
    while(!ifs.eof()){
        getline(ifs, s);
        a.push_back(s);    
    }

    ifs.close();
    
    for(int i = 0; i < a.size(); i++)
        b.push_back(a[i]);

    auto start = chrono::high_resolution_clock::now();

    // sorting    
    for(int i = 0; i < a.size() - 1; i++)
	    for(int j = a.size() - 1; j > i; j--)
            if (a[j - 1] > a[j]){
                swap(a[j] , a[j - 1]);
            }
	// binary search
        for(int i = 0; i < a.size(); i++){
            string s = a[i];

            int left = 0;
            int right = a.size() - 1;

            while(left <= right){
            int mid = left + (right - left) / 2;

             if(a[mid] == s)
                break;
        
            else if(a[mid] < s)
                left = mid + 1;
         
            else
                right = mid - 1;
        
            }
        }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    cout << "Bubble Sort + BS - " << filename << " - " << fixed << duration.count() << " ms - 22127439" << endl;
    return;
}


void SelectionSort(string filename){
    // input
    ifstream ifs(filename);

    vector<string> a, b;
    string s = "";
    
    while(!ifs.eof()){
        getline(ifs, s);
        a.push_back(s);    
    }

    ifs.close();

    for(int i = 0; i < a.size(); i++)
        b.push_back(a[i]);

    auto start = chrono::high_resolution_clock::now();
    // sorting 

    int min_idx = 0;

    for(int i = 0; i < a.size() - 1; i++){
        min_idx = i;
        for(int j = i + 1; j < a.size(); j++){
            if (a[j] < a[min_idx])
                min_idx = j;
        }  
        if (a[min_idx] < a[i])
            swap(a[min_idx], a[i]);
    }
    // BS
    for(int i = 0; i < a.size(); i++){
            string s = a[i];

            int left = 0;
            int right = a.size() - 1;

            while(left <= right){
            int mid = left + (right - left) / 2;

             if(a[mid] == s)
                break;
        
            else if(a[mid] < s)
                left = mid + 1;
         
            else
                right = mid - 1;
        
            }
        }
    //
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    cout << "Selection Sort + BS - " << filename << " - " << fixed << duration.count() << " ms - 22127439" << endl;

    return;
}


void InsertionSort(string filename){
    // input
    ifstream ifs(filename);

    vector<string> a, b;
    string s = "";
    
    while(!ifs.eof()){
        getline(ifs, s);
        a.push_back(s);    
    }

    ifs.close();

    for(int i = 0; i < a.size(); i++)
        b.push_back(a[i]);

    auto start = chrono::high_resolution_clock::now();
   
    // sorting 

    int j;
    string tmp;
    
    for(int i = 1; i < a.size(); i++){
        tmp = a[i];
        j = i - 1;

        while (j >= 0 && tmp < a[j]){
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = tmp;
    }
    // BS
    for(int i = 0; i < a.size(); i++){
            string s = a[i];

            int left = 0;
            int right = a.size() - 1;

            while(left <= right){
            int mid = left + (right - left) / 2;

             if(a[mid] == s)
                break;
        
            else if(a[mid] < s)
                left = mid + 1;
         
            else
                right = mid - 1;
        
            }
        }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    cout << "Insertion Sort + BS - " << filename << " - " << fixed << duration.count() << " ms - 22127439" << endl;

    return;
}


void merge(vector<string>& a, int l, int m, int r){
    int nLeft = m - l + 1;
    int nRight = r - m;

    vector<string>  leftArr(nLeft);
    vector<string> rightArr(nRight);

    for (int i = 0; i < nLeft; i++) 
        leftArr[i] = a[l + i];
    

    for (int i = 0; i < nRight; i++) 
        rightArr[i] = a[m + 1 + i];
    

    int i = 0, j = 0, k = l;

    while (i < nLeft && j < nRight){
        if (leftArr[i] <= rightArr[j]){
            a[k] = leftArr[i];
            i++;
        } 
        else{
            a[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < nLeft){
        a[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < nRight){
        a[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<string>& a, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

void MergeSort_Main(string filename){
    ifstream ifs(filename);

    vector<string> a, b;
    string s = "";
    
    while(!ifs.eof()){
        getline(ifs, s);
        a.push_back(s);    
    }

    ifs.close();
    
    for(int i = 0; i < a.size(); i++)
        b.push_back(a[i]);

    auto start = chrono::high_resolution_clock::now();
    
    mergeSort(a, 0, a.size() - 1);

    // BS
    for(int i = 0; i < a.size(); i++){
            string s = a[i];

            int left = 0;
            int right = a.size() - 1;

            while(left <= right){
            int mid = left + (right - left) / 2;

             if(a[mid] == s)
                break;
        
            else if(a[mid] < s)
                left = mid + 1;
         
            else
                right = mid - 1;
        
            }
        }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    cout << "Merge Sort + BS - " << filename << " - " << fixed << duration.count() << " ms - 22127439" << endl;

}


void QuickSort(vector<string>& a, int l, int r){
	int m = (l + r) / 2, i = l, j = r;
    string p = a[m];
	
	while (i < j){
		while (a[i] < p){
			i++;
		}
		while (a[j] > p){
			j--;
		}
		if (i <= j){
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (i < r){
		QuickSort(a, i, r);
	}
	if (l < j){
		QuickSort(a, l, j);
	}
}

void QuickSort_Main(string filename){
    ifstream ifs(filename);
    vector<string> a, b;
    string s = "";
    
    while(!ifs.eof()){
        getline(ifs, s);
        a.push_back(s);    
    }

    ifs.close();

    for(int i = 0; i < a.size(); i++)
        b.push_back(a[i]);

    auto start = chrono::high_resolution_clock::now();
    // soring 
    QuickSort(a, 0, a.size() - 1);

    // BS
    
        for(int i = 0; i < a.size(); i++){
            string s = a[i];

            int left = 0;
            int right = a.size() - 1;

            while(left <= right){
            int mid = left + (right - left) / 2;

             if(a[mid] == s)
                break;
        
            else if(a[mid] < s)
                left = mid + 1;
         
            else
                right = mid - 1;
        
            }
        }
            
        
    
     auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    cout << "Quick sort + BS - " << filename << " - " << fixed << duration.count() << " ms - 22127439" << endl;

}

struct binDiagram{
    queue<string> q;
};

void RadixSort(string filename){
    ifstream ifs(filename);
    vector<string> a, b;
    string s = "";
    int maxlen = 0; // find max length
    while(!ifs.eof()){
        getline(ifs, s);
        if(maxlen < s.size())
            maxlen = s.size();
        a.push_back(s);
    }

    for(int i = 0; i < a.size(); i++)
        b.push_back(a[i]);
    
    ifs.close();

    auto start = chrono::high_resolution_clock::now();
    // sorting
    string tmp;
    int idx;
    binDiagram binn[27];

    while(true){
        maxlen--;
        for(int i = 0; i < a.size(); i++){
                if(a[i].size() <= maxlen)
                    binn[0].q.push(a[i]);
                else{
                    idx = a[i][maxlen] - 'a' + 1;
                    if(idx < 0)
                        idx += 32;
                    binn[idx].q.push(a[i]);
                }
        }
        int j = 0;
        for(int i = 0; i < 27; i++){
            while(!binn[i].q.empty()){
                tmp = binn[i].q.front();
                binn[i].q.pop();
                a[j] = tmp;
                j++;
            }
        }
        if(maxlen == 0)
            break;
    }

    // BS
    for(int i = 0; i < a.size(); i++){
            string s = a[i];

            int left = 0;
            int right = a.size() - 1;

            while(left <= right){
            int mid = left + (right - left) / 2;

             if(a[mid] == s)
                break;
        
            else if(a[mid] < s)
                left = mid + 1;
         
            else
                right = mid - 1;
        
            }
        }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    cout << "Radix sort + BS - " << filename << " - " << fixed << duration.count() << " ms - 22127439" << endl;

}


void linearsearch(vector<string> a, string s){
    for(int i = 0; i < a.size(); i++)
        if(a[i] == s)
            return;
    
    return;
}

void linearsearch_Main(string filename){
    ifstream ifs(filename);
    vector<string> a, b;
    string s = "";
    
    while(!ifs.eof()){
        getline(ifs, s);
        a.push_back(s);    
    }

    ifs.close();

    for(int i = 0; i < a.size(); i++)
        b.push_back(a[i]);
    auto start = chrono::high_resolution_clock::now();
    
    for(int i = 0; i < b.size(); i++){
        linearsearch(a, b[i]);
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    cout << "Linearsearch - " << filename << " - " << fixed << duration.count() << " ms - 22127439" << endl;

}

void Menu(){
    char x, y;
    cout << "Sorting and searching program (PART 1) .\n";
    cout << "by Vo Huu Tuan - 22127439\n";
    while(true){
        cout << "------------------------------------------\n";
        cout << "Choose algorithm:\n";
        cout << "Press 0 to Linear Search\n";
        cout << "Press 1 to Bubble sort + Binary search\n";
        cout << "Press 2 to Selection sort + Binary search\n";
        cout << "Press 3 to Insertion sort + Binary search\n";
        cout << "Press 4 to Merge sort + Binary search\n";
        cout << "Press 5 to Quick sort + Binary search\n";
        cout << "Press 6 to Radix sort + Binary search\n";
        cout << "Press another key to Exit.\n";
        cout << "Your choose: ";
        cin >> x;

        if('0' <= x && x < '7'){
            cout << "Choose Array use:\n";
            cout << "Press a to 100 names\n";
            cout << "Press b to 1000 names\n";
            cout << "Press c to 10000 names\n";
            cout << "Press d to 50000 names\n";
            cout << "Your choose: ";
            cin.ignore();
            cin >> y;
            if('a' <= y && y <= 'd'){
                
                string s = "";
                if(y == 'a')
                    s += "100";
                else if(y == 'b')
                    s += "1k";
                else if(y == 'c')
                    s += "10k";
                else if(y == 'd')
                    s += "50k";
                else
                    return;    
            
                s = s + ".txt";
                
                
                switch(x){
                    case '0':{
                        linearsearch_Main(s);
                        break;
                    }
                    case '1':{
                        BubbleSort(s);
                        break;
                    }
                    case '2':{
                        SelectionSort(s);
                        break;
                    }
                    case '3':{
                        InsertionSort(s);
                        break;
                    }
                    case '4':{
                        MergeSort_Main(s);
                        break;
                    }
                    case '5':{
                        QuickSort_Main(s);
                        break;
                    }
                    case '6':{
                        RadixSort(s);
                        break;
                    }
                }
            }
        }
        else
            return;
    }
}
int main(){

    //ChangeOutput();
    //linesearch_Main("50000.txt");
    Menu();
    return 0;
}