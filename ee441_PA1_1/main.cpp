#include <iostream>
using namespace std;

template <int N>
class Matrix
{
private:
    double data[N][N];
public:
    int const SIZE = N;
    Matrix();
    int GetData(int row, int col)const;
    void SetData(int row, int col, int val);
    void getCofactor(Matrix<N>& matrix1, Matrix<N>& matrix2, int p, int q);
    int determinantOfMatrix(Matrix<N> matrix1, int n);


};

template <int N>
Matrix<N>::Matrix(){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++)
            if(i == j){
                data[i][j] = 1;
            }
            else{
                data[i][j] = 0;
            }
    }
}

template <int N>
int Matrix<N>::GetData(int row, int col)const{
    if(row < SIZE && col < SIZE) {
        return data[row][col];
    }
    else{
        std::cout << "Input dimensions are not valid for this function" << std::endl;
    }
}

template <int N>
void Matrix<N>::SetData(int row, int col, int val){
    if(row < SIZE && col < SIZE) {
        data[row][col] = val;
    }
    else{
        std::cout << "Input dimensions are not valid for this function" << std::endl;
    }
}

template <int N>
Matrix<N> Print_Matrix(Matrix<N> matrix1){;
    for(int i = 0; i < N; i++){
        for (int j = 0; j < N; j++) {
            std::cout << matrix1.GetData(i,j) << " " << std::flush;
        }
        std::cout << " " << std::endl;
    }
}

template <int N>
Matrix<N> Add_Matrices(Matrix<N> matrix1, Matrix<N> matrix2){
    Matrix<N> sum_matrix;
    for(int i = 0; i < N; i++){
        for (int j = 0; j < N; j++) {
            double value;
            value = matrix1.GetData(i,j) + matrix2.GetData(i,j);
            sum_matrix.SetData(i,j, value);
        }
    }
    return sum_matrix;
}

template <int N>
Matrix<N> Sub_Matrices(Matrix<N> matrix1, Matrix<N> matrix2){
    Matrix<N> diff_matrix;
    for(int i = 0; i < N; i++){
        for (int j = 0; j < N; j++) {
            int value;
            value = matrix1.GetData(i,j) - matrix2.GetData(i,j);
            diff_matrix.SetData(i,j, value);
            //std::cout << sum_matrix.GetData(i,j) << std::endl;
        }
    }
    return diff_matrix;
}

template <int N>
Matrix<N> Mult_Matrices(Matrix<N> matrix1, Matrix<N> matrix2){
    Matrix<N> mult_matrix;
    int value = 0;
    for(int i = 0; i < N; i++){
        for (int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++){
                value += matrix1.GetData(i,k) * matrix2.GetData(k,j);
            }
            mult_matrix.SetData(i,j, value);
            value = 0;
        }
    }
    return mult_matrix;
}

template <int N>
void Matrix<N>:: getCofactor(Matrix<N>& matrix1, Matrix<N>& matrix2, int p,
                 int q)
{
    int i = 0, j = 0;

    // Looping for each element of the matrix
    for (int row = 0; row < matrix1.SIZE; row++)
    {
        for (int col = 0; col < matrix1.SIZE; col++)
        {
            //  Copying into temporary matrix only those
            //  element which are not in given row and
            //  column
            if (row != p && col != q)
            {
                matrix2.SetData(i,j++, matrix1.GetData(row,col));

                // Row is filled, so increase row index and
                // reset col index
                if (j == matrix1.SIZE - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

template <int N>
int Matrix<N>::determinantOfMatrix(Matrix<N> matrix1, int n)
{
    int D = 0; // Initialize result

    //  Base case : if matrix contains single element
    if (n == 1)
        return matrix1.data[0][0];

    Matrix<N> temp; // To store cofactors

    /*
     *
     *              |c00  c01  c02|
     *    temp=     |c10  c11  c21|
     *              |c20  c01  c22|         stores the cofactors
     *
     */

    int sign = 1; // To store sign multiplier

    // Iterate for each element of first row
    for (int f = 0; f < n; f++)
    {
        // Getting Cofactor of mat[0][f]
        getCofactor(matrix1, temp, 0, f);
        D += sign * matrix1.data[0][f]
             * determinantOfMatrix(temp, n - 1);   //bir satır için yapsak yetiyor bu nedenşe data[0][f]

        // terms are to be added with alternate sign
        sign = -sign; // cofactor (-1)^(n+1) çarpılıyor bu nedenle bir pos bir neg
    }

    return D;
}

int main() {

    Matrix<5> Matrix_1;
    Matrix<5> Matrix_2;
    Matrix<5> Matrix_3;
    Matrix<2> Matrix_4;
    Matrix<1> Matrix_5;
    Matrix<2> Matrix_6;
    Matrix<2> Matrix_7;


    Matrix_4.SetData(0,0,4);
    Matrix_4.SetData(0,1,1);
    Matrix_4.SetData(1,0,2);
    Matrix_4.SetData(1,1,2);
    //determinant 6 olmalı

    Matrix_5.SetData(0,0,7);

    Matrix_6.SetData(0,0,1);
    Matrix_6.SetData(0,1,5);
    Matrix_6.SetData(1,0,3);
    Matrix_6.SetData(1,1,2);




    std::cout << "data[2][3]: " << Matrix_1.GetData(2,3) << std::endl;
    std::cout << "data[1][1]: " << Matrix_1.GetData(1,1) << std::endl;
    //std::cout << "data[7][1]: " << Matrix_1.GetData(7,1) << std::endl;

    //Matrix_3 = Add_Matrices(Matrix_1,Matrix_2);


    for(int i = 0; i < Matrix_1.SIZE; i++){
        for(int j = 0; j < Matrix_1.SIZE; j++){
            std::cout << Add_Matrices(Matrix_1,Matrix_2).GetData(i,j) << " " << std::flush;
        }
        std::cout << " " << std::endl;
    }

    for(int i = 0; i < Matrix_1.SIZE; i++){
        for(int j = 0; j < Matrix_1.SIZE; j++){
            Matrix_3.SetData(i,j,Sub_Matrices(Matrix_1,Matrix_2).GetData(i,j));
        }
    }
    std::cout << "Matrix 3: " << std::endl;
    Print_Matrix(Matrix_3);

    cout << "Matrix 5'in det: " <<  Matrix_5.determinantOfMatrix(Matrix_5, Matrix_5.SIZE) << endl;
    cout << "Matrix 2'in det: " <<  Matrix_2.determinantOfMatrix(Matrix_2, Matrix_2.SIZE) << endl;
    //cout << "Matrix 5'in size: " <<  Matrix_5.SIZE << endl;
    //cout << "Matrix 4'ün size: " <<  Matrix_4.SIZE << endl;
    cout << "Matrix 4'ün determinantı: " <<  Matrix_4.determinantOfMatrix(Matrix_4, Matrix_4.SIZE) << endl;

    for(int i = 0; i < Matrix_4.SIZE; i++){
        for(int j = 0; j < Matrix_4.SIZE; j++){
            Matrix_7.SetData(i,j,Mult_Matrices(Matrix_4,Matrix_6).GetData(i,j));
            //std::cout << Matrix_7.GetData(i,j) << " " << std::flush;
        }
        //std::cout << " " << std::endl;
    }

    std::cout << "testing Print_Matrix..."<< std::endl;
    std::cout << "Matrix 4 " <<  std::endl;
    Print_Matrix(Matrix_4);
    std::cout << "Matrix 6 " <<  std::endl;
    Print_Matrix(Matrix_6);

    std::cout << "Matrix 7:  " << std::endl;
    Print_Matrix(Matrix_7);

    return 0;
}
