//
// Created by BlazarLin on 2020/7/25.
//

#ifndef CODES_CHP6_H
#define CODES_CHP6_H

#endif //CODES_CHP6_H
#include <iostream>
using namespace std;

void chp62Practices();

//6.2 写一个matrix操作类
template<typename elemType>
class MatrixPro{
    friend MatrixPro<elemType>
            operator+(const MatrixPro<elemType>&, const MatrixPro<elemType>&);

    friend MatrixPro<elemType>
            operator*(const MatrixPro<elemType>&, const MatrixPro<elemType>&);

public:
    MatrixPro(int rows, int columns):_rows(rows),_cols(columns){
        int size = _rows*_cols;
        _matrix = new elemType[size];
        for(int ix=0;ix<size;++ix)
            _matrix[ix]=elemType();
    }
    MatrixPro(const MatrixPro& rhs){
        _rows=rhs._rows;_cols=rhs._cols;
        int mat_size = _rows*_cols;
        _matrix=new elemType[mat_size];
        for(int ix=0;ix<mat_size;++ix)
            _matrix[ix]=rhs._matrix[ix];
    }
    ~MatrixPro(){delete [] _matrix;}

    MatrixPro& operator=(const MatrixPro &rhs){
        if(this != &rhs){
            _rows=rhs._rows;_cols=rhs._cols;
            int mat_size = _rows*_cols;
            delete [] _matrix;
            _matrix = new elemType[mat_size];
            for(int ix=0;ix<mat_size;++ix)
                _matrix[ix]=rhs._matrix[ix];
        }
        return *this;
    }

    void operator+=(const MatrixPro&);

    elemType& operator()(int row, int column){
        return _matrix[row*cols()+column];
    }

    const elemType& operator()(int row, int column)const{
        return _matrix[row*cols()+column];
    }

    int rows() const {return _rows;}
    int cols() const {return _cols;}

    bool same_size(const MatrixPro &m)const{
        return rows() == m.rows() && cols() == m.cols();
    }

    bool comfortable(const MatrixPro &m) const{
        return (cols()==m.rows());
    }

    ostream& print(ostream&) const;


protected:
    int _rows;
    int _cols;
    elemType *_matrix;
};

template<typename elemType>
inline ostream&
operator<<(ostream& os, const  MatrixPro<elemType> &m){
    return m.print(os);
}

template <typename elemType>
MatrixPro< elemType >
operator+( const MatrixPro<elemType> &m1, const MatrixPro<elemType> &m2 )
{
// make sure m1 & m2 are same size
    MatrixPro<elemType> result( m1 );
    result += m2;
    return result;
}

//模板类的友元函数操作符重载
template <typename elemType>
MatrixPro<elemType> operator*( const MatrixPro<elemType> &m1, const MatrixPro<elemType> &m2 )
{
// m1’s columns must equal m2’s rows ...
    MatrixPro<elemType> result( m1.rows(), m2.cols() );
    for ( int ix = 0; ix < m1.rows(); ix++ ) {
        for ( int jx = 0; jx < m1.cols(); jx++ ) {
            result( ix, jx ) = 0;
            for ( int kx = 0; kx < m1.cols(); kx++ )
                result( ix, jx ) += m1( ix, kx ) * m2( kx, jx );
        }
    }
    return result;
}

template <typename elemType>
void MatrixPro<elemType>::operator+=( const MatrixPro &m ){
// make sure m1 & m2 are same size
    int matrix_size = cols() * rows();
    for ( int ix = 0; ix < matrix_size; ++ix )
        ( *( _matrix + ix )) += ( *( m._matrix + ix ));
}

template <typename elemType>
ostream& MatrixPro<elemType>::print( ostream &os ) const {
    int col = cols();
    int matrix_size = col * rows();
    for ( int ix = 0; ix < matrix_size; ++ix ){
        if ( ix % col == 0 ) os << endl;
        os << ( *( _matrix + ix )) << ' ';
    }
    os << endl;
    return os;
}