# LAB Report
# Topic: Sort Alogorithm 
# Course: DSA
## Creater: Võ Hữu Tuấn (RINz) - 22CLC03 - HCMUS
## Một số lưu ý:

    #include  <chrono> // Thư viện đo tốc độ thực thi  
### - Cấu trúc của đo tốc độ sẽ là:

 // Đo thời gian bắt đầu  
    auto start = chrono::high_resolution_clock::now();  

 // Chạy thuật toán  
    Algorithm();  

 // Đo thời gian kết thúc  
    auto end = chrono::high_resolution_clock::now();  

 // Tính thời gian thực thi  
    chrono::duration<double, milli> duration = end - start;  
    cout << "Thoi gian thuc thi: " << duration.count() << " s" << endl;  

    *milli : millisecond hay mili giây (ms), nếu để trống mặc định sẽ là giây (s).  

### - Lúc xuất duration.count() nhớ dùng "fixed()" để số không bị làm tròn.  
### - Khi chạy với số lượng phần tử lớn có thể bị Runtime limit error (Quá thời gian thực thi)  
### - Nếu dùng VS code và bị RLE thì vào file "settings.json" và thêm dòng lệnh này:  
        {
            "cpp.debugSettings": {
             "limitTime": 1000000 // tăng giới hạn lên 60k ms hay 60s
           }
        }
