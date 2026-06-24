#include <iostream>
using namespace std;

struct Node {
    int year;
    Node* left;
    Node* right;

    Node(int x) {
        year = x;
        left = right = NULL;
    }
};

// Thêm nút vào BST
Node* insert(Node* root, int x) {
    if (root == NULL)
        return new Node(x);

    if (x <= root->year)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

// Tìm kiếm trên BST
bool search(Node* root, int x) {
    if (root == NULL)
        return false;

    if (root->year == x)
        return true;

    if (x < root->year)
        return search(root->left, x);
    else
        return search(root->right, x);
}

int main() {
    int a[] = {2001, 2002, 2006, 2007, 2003,
               2004, 2005, 2001, 1999, 2004};

    int n = sizeof(a) / sizeof(a[0]);

    Node* root = NULL;

    // Xây dựng BST
    for (int i = 0; i < n; i++)
        root = insert(root, a[i]);

    int x = 2004;

    if (search(root, x))
        cout << "Tim thay nam sinh " << x << endl;
    else
        cout << "Khong tim thay!" << endl;

    /*
    PHAN TICH DO PHUC TAP

    - Mỗi bước tìm kiếm chỉ thực hiện các phép so sánh O(1).

    - Thuật toán chỉ đi theo một nhánh từ gốc đến lá.
      Số nút phải duyệt chính là chiều cao cây h.

    => T(n) = O(h)

    + Trường hợp tốt nhất:
      Phần tử nằm ngay tại gốc.
      T(n) = O(1)

    + Trường hợp trung bình:
      Cây tương đối cân bằng.
      h ≈ log2(n)
      T(n) = O(log n)

    + Trường hợp xấu nhất:
      Cây bị lệch hoàn toàn.
      h = n
      T(n) = O(n)

    Kết luận:
    Độ phức tạp tìm kiếm trên BST là O(h).
    */
}