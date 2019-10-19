//
// Created by pilcq on 2019/10/19.
//
//题目：实现一个4×4的Matrix class，至少提供以下接口：矩阵加法、矩阵乘法、打印函数print（）、复核员算符+=，以及一组支持下标操作的function call运算符。
//
//知识点：typedef，构造函数（默认构造函数，有参无默认构造函数），输出流重载，友函数，
//函数调用运算符重载（function call），声明写法：type &operator()(int a,intb,…)或type operator()(int a,int b…) const. 根据类参数是 const还是可变，函数调用运算符的定义也要考虑是否加const。
//operator重载运算符，声明写法 type operator+（const class&）：文中分别采用常规的成员函数形式定义和友函数定义
//原文链接：https://blog.csdn.net/weixin_43184615/article/details/83001479

#include<iostream>
using namespace std;

typedef float elemType;//方便我们转换为template形式

class Matrix
{
	//friend声明不受访问权限的影响，放在class开始处
	//friend Matrix operator+(const Matrix&, const Matrix&);  //矩阵加法
	friend Matrix operator*(const Matrix&, const Matrix&);  //矩阵乘法

public:
	//声明构造函数
	Matrix();
	Matrix(const elemType*);
	Matrix(elemType a11, elemType a12, elemType a13, elemType a14,
		elemType a21, elemType a22, elemType a23, elemType a24,
		elemType a31, elemType a32, elemType a33, elemType a34,
		elemType a41, elemType a42, elemType a43, elemType a44);


	int rows() const { return 4; }
	int cols() const { return 4; }

	Matrix operator+(const Matrix&);//矩阵加法

	void operator+=(const Matrix&); //声明+=复合运算符

	ostream& print(ostream& os) const;

	//重载函数调用运算符(),用于const类型的类，本例中的m,m1,m2
	elemType operator()(int row, int column) const
	{
		return _matrix[row][column];
	}
	//重载函数调用运算符(),用于可变类型的类，本例中的result
	elemType &operator()(int row, int column)
	{
		return _matrix[row][column];
	}

private:
	elemType _matrix[4][4];
};

//定义构造函数
//默认构造函数
Matrix::Matrix()
{
	_matrix[0][0] = 0.; _matrix[0][1] = 0.; _matrix[0][2] = 0.; _matrix[0][3] = 0.;
	_matrix[1][0] = 0.; _matrix[1][1] = 0.; _matrix[1][2] = 0.; _matrix[1][3] = 0.;
	_matrix[2][0] = 0.; _matrix[2][1] = 0.; _matrix[2][2] = 0.; _matrix[2][3] = 0.;
	_matrix[3][0] = 0.; _matrix[3][1] = 0.; _matrix[3][2] = 0.; _matrix[3][3] = 0.;
}
//有参无默认构造函数，接受一个数组
Matrix::Matrix(const elemType *array)
{
	int array_index = 0;
	for (int ix = 0; ix < 4; ++ix)
	    for (int jx = 0; jx < 4; ++jx)
		    _matrix[ix][jx] = array[array_index++];
}
//有参无默认构造函数，接受16个数据值
Matrix::Matrix(elemType a11, elemType a12, elemType a13, elemType a14,
	elemType a21, elemType a22, elemType a23, elemType a24,
	elemType a31, elemType a32, elemType a33, elemType a34,
	elemType a41, elemType a42, elemType a43, elemType a44)
{
	_matrix[0][0] = a11; _matrix[0][1] =a12; _matrix[0][2] = a13; _matrix[0][3] =a14;
	_matrix[1][0] = a21; _matrix[1][1] = a22; _matrix[1][2] = a23; _matrix[1][3] =a24;
	_matrix[2][0] = a31; _matrix[2][1] = a32; _matrix[2][2] = a33; _matrix[2][3] =a34;
	_matrix[3][0] = a41; _matrix[3][1] = a42; _matrix[3][2] = a43; _matrix[3][3] = a44;
}

//定义输出流重载，注意格式
inline ostream& operator<<(ostream& os, const Matrix &rhs)
{
	return rhs.print(os);
}
//定义print函数，用于输出流重载
ostream& Matrix::print(ostream& os) const
{
	int cnt = 0;
	for (int ix = 0; ix < 4; ++ix)
	{
		for (int jx = 0; jx < 4; ++jx)
		{
			if (cnt && !(cnt % 4)) os << endl;
			os << _matrix[ix][jx] << ' ';
			++cnt;
		}
	}
	os << endl;
	return os;
}

//定义+ 重载运算符,采用常规的成员函数形式定义
Matrix Matrix::operator+( const Matrix &m )
{
	Matrix result;
	for (int ix = 0; ix < m.rows(); ++ix)
	{
		for (int jx = 0; jx < m.cols(); ++jx)
		{
			result(ix, jx) = 0;
			result(ix, jx) = _matrix[ix][jx] + m(ix, jx);
		}
	}
	return result;
}

//定义 * 重载运算符，采用友函数形式定义
Matrix operator*(const Matrix &m1, const Matrix &m2)
{
	Matrix result;
	for (int ix = 0; ix < m1.rows(); ++ix)
	{
		for (int jx = 0; jx < m1.cols(); ++jx)
		{
			result(ix, jx) = 0;
			for (int kx = 0; kx < m1.cols();++kx)
			    result(ix, jx) += m1(ix, kx) * m2(kx, jx);
		}
	}
	return result;
}

//定义 += 重载运算符
void Matrix::operator+=(const Matrix &m)
{
	for (int ix = 0; ix < m.rows();++ix)
	    for (int jx = 0; jx < m.cols(); ++jx)
		    _matrix[ix][jx] += m(ix, jx);
}

int testChp45()
{
	Matrix m;
	cout << m << endl;

	elemType ar[16] = { 1, 0, 0, 0, 0, 1, 0, 0,
		0, 0, 1, 0, 0, 0, 0, 1 };
	Matrix m1(ar);
	cout << m1 << endl;

	Matrix m2(m1);
	cout << m2 << endl;

	elemType ar2[16] = {
		1.3, 0.4, 2.6, 8.2, 6.2, 1.7, 1.3, 8.3,
		4.2, 7.4, 2.7, 1.9, 6.3, 8.1, 5.6, 6.6
	};
	Matrix m3(ar2);
	cout << m3 << endl;

	Matrix m4 = m3*m1;
	cout << m4 << endl;

	Matrix m5 = m3 + m4;
	cout << m5 << endl;

	m3 += m4;
	cout << m3 << endl;
    return 0;
}
