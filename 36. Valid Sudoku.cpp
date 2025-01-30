class Solution {
    public boolean isValidSudoku(char[][] board) {
        boolean[][] row=new boolean[9][9];
        boolean[][] col=new boolean[9][9];
        boolean[][] box=new boolean[9][9];

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char c=board[i][j];
                if(c == '.') continue;
                int num=c-'0'-1;
                int k=i/3*3+j/3;

                if(row[i][num] || col[j][num] || box[k][num]){
                    return false;
                }
                row[i][num]=true;
                col[j][num]=true;
                box[k][num]=true;
            }
        }
        return true;
    }
}
// Tóm tắt quá trình kiểm tra:
// Duyệt qua từng ô (i, j) trong bảng.
// Nếu ô chứa số ('1' đến '9'):
// Tính chỉ số num (số đang xét) và k (ô vuông nhỏ đang xét).
// Kiểm tra xem số num đã tồn tại trong:
// Hàng i, cột j, hoặc ô vuông nhỏ k.
// Nếu có trùng lặp, trả về false.
// Nếu không trùng lặp, đánh dấu số num trong hàng, cột, và ô vuông nhỏ tương ứng.
// Nếu duyệt hết bảng mà không vi phạm, bảng hợp lệ.