/*
(Tệp chương trình: CT.CPP; Thời gian chạy chương trình ≤ 1 giây)

Cho trước đồ thị có trọng số G = (V, E) gồm n đỉnh biểu diễn dưới dạng ma trận trọng số không âm và một đỉnh u.

Yêu cầu: Tìm chu trình Hamilton của G bắt đầu tại u có tổng trọng số trên các cạnh là nhỏ nhất sử dụng thuật toán duyệt toàn thể.

Dữ liệu: Vào từ tệp CT.INP:

Dòng đầu chứa hai số nguyên dương n và u, trong đó n là số đỉnh, u là đỉnh của G, với 1 <= u <= n <= 100.
Trong n dòng tiếp theo, mỗi dòng thứ i chứa n số tự nhiên c[i][j] mô tả ma trận trọng số của G. Trong đó, với hai đỉnh i, j (i khác j) có cạnh nối thì 0 < c[i][j] <= 50, nếu không có cạnh nối thì c[i][j] = 10000 và c[i][i] = 0.
Kết quả: Ghi ra tệp CT.OUT:

Nếu tìm được chu trình Hamilton thỏa mãn yêu cầu thì ghi ra theo quy cách:
Dòng đầu ghi tổng trọng số của tất cả các cạnh trong chu trình Hamilton tìm được;
Dòng sau ghi dãy các đỉnh trên chu trình Hamilton tìm được bắt đầu từ u.
Nếu không có chu trình Hamilton thì ghi giá trị 0.
*/

