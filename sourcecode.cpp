#include <iostream>
#include <time.h>
#include <chrono> // thư viện đo tốc độ thực thi

using namespace std;
long long n, x;
long long k = 100000000000;
long long a[3000000];
long long b[3000000];

void randomValue(){
    cout << "Input n: ";
    cin >> n;
    
    //cout << "Input k: ";
    //cin >> k;

    //sắp xếp ngẫu nhiên
    srand(time(0));
    for(int i = 0; i < n; i++)
        b[i] = rand() % k;

    // sắp xếp có thứ tự
    // int tmp, j;
    
    // for(int i = 1; i < n; i++){
    //     tmp = a[i];
    //     j = i - 1;

    //     while (j >= 0 && tmp < a[j]){
    //         a[j + 1] = a[j];
    //         j = j - 1;
    //     }
    //     a[j + 1] = tmp;
    // }

    //sắp xếp gần như có thứ tự
    // long long cnt = n * 0.05;
    // for(int i = 0; i < cnt; i++){
    //     long long z = rand() % n;
    //     b[z] = rand() % k;
    // }
    
    return;
}

void SelectionSort(){
    int min_idx = 0;

    for(int i = 0; i < n - 1; i++){
        min_idx = i;
        for(int j = i + 1; j < n; j++){
            if (a[j] < a[min_idx])
                min_idx = j;
        }  
        if (a[min_idx] < a[i])
            swap(a[min_idx], a[i]);
    }

    return;
}

void InsertionSort(){
    int tmp, j;
    
    for(int i = 1; i < n; i++){
        tmp = a[i];
        j = i - 1;

        while (j >= 0 && tmp < a[j]){
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = tmp;
    }

    return;
}

void InterchangeSort(){
	for(int i = 0; i < n - 1; i++)
		for(int j = i + 1; j < n; j++)
			if(a[i] > a[j])
				swap(a[i], a[j]);

    return;
}

void BubbleSort(){
    for(int i = 0; i < n - 1; i++)
	    for(int j = n - 1; j > i; j--)
            if (a[j - 1] > a[j]){
                swap(a[j] , a[j - 1]);
            }
	
    return;
}

void ShakerSort(){
    int index = 0, Left = 0, Right = n - 1;

	while(Left < Right){
		for(int i = Left; i < Right; i++){
			if (a[i] > a[i + 1]){
				swap(a[i], a[i + 1]);
				index = i;
			}
		}

		Right = index;

		for(int i = Right; i > Left; i--){
			if (a[i] < a[i - 1]){
				swap(a[i], a[i - 1]);
				index = i;
			}
		}
		Left = index;
	}

    return;
}

void printArray(){  
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;

    return;
}

void analysisSortAlgorithm(int tmp){

    for(int i = 0; i < n; i++)
        a[i] = b[i];

    if(tmp == 1){
        auto start = chrono::high_resolution_clock::now();
        
        SelectionSort();
        
        auto end = chrono::high_resolution_clock::now();

        cout << "Selection Sort:\n";
        //printArray(b, n);
    
        chrono::duration<double, milli> duration = end - start;
        cout << "Thoi gian thuc thi: " << fixed << duration.count() << " ms" << std::endl;

    }
    else if(tmp == 2){
        auto start = chrono::high_resolution_clock::now();
        
        InsertionSort();
        
        auto end = chrono::high_resolution_clock::now();

        cout << "Insertion Sort:\n";
        //printArray(b, n);
    
        chrono::duration<double, milli> duration = end - start;
        cout << "Thoi gian thuc thi: " << fixed << duration.count() << " ms" << std::endl;

    }
    else if(tmp == 3){
        auto start = chrono::high_resolution_clock::now();
        
        InterchangeSort();
        
        auto end = chrono::high_resolution_clock::now();

        cout << "Interchange Sort:\n";
        //printArray(b, n);
    
        chrono::duration<double, milli> duration = end - start;
        cout << "Thoi gian thuc thi: " << fixed << duration.count() << " ms" << std::endl;

    }
    else if(tmp == 4){
        auto start = chrono::high_resolution_clock::now();
        
        BubbleSort();
        
        auto end = chrono::high_resolution_clock::now();

        cout << "Bubble Sort:\n";
        //printArray(b, n);
    
        chrono::duration<double, milli> duration = end - start;
        cout << "Thoi gian thuc thi: " << fixed << duration.count() << " ms" << std::endl;
    
    }
    else if(tmp == 5){
        auto start = chrono::high_resolution_clock::now();
        
        ShakerSort();
        
        auto end = chrono::high_resolution_clock::now();

        cout << "Shaker Sort:\n";
        //printArray(b, n);
    
        chrono::duration<double, milli> duration = end - start;
        cout << "Thoi gian thuc thi: " << fixed << duration.count() << " ms" << std::endl;
    
    }
    
    return;
}

void printMenu(){
    cout << "-----------------------------------------------\n";
    cout << "Press 1: Analysis Selection sort" << endl;
    cout << "Press 2: Analysis Insertion sort" << endl;
    cout << "Press 3: Analysis Interchange sort" << endl;
    cout << "Press 4: Analysis Bubble sort" << endl;
    cout << "Press 5: Analysis Shaker sort" << endl;
    cout << "Press 6: Input n, k again" << endl;
    cout << "Press 7: Print Unsorted Array" << endl;
    cout << "Press 0: Exit" << endl;
    cout << "Your choose: ";
}

int main()
{

    
    cout << "Welcome to analysis Sort Algorithm!\n";
    randomValue();
    
    while(true){
        printMenu();
        cin.ignore();
        cin >> x;
        if(x == 0)
            break;
        else if(x == 6)
            randomValue();
        else if(x == 7)
            printArray();
        else if(0 < x && x < 6)
            for(int i = 1; i < 6; i++)
            analysisSortAlgorithm(i);
        else
            cout << endl;
    }

    return 0;
}
