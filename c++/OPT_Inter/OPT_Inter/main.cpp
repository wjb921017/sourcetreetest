#include <iostream>
#include "../FADBAD/FADBAD++/fadiff.h"
#include<math.h>

#define N 2
#define P 1
#define M 2
using namespace std;

void ReverseArray(int a[P][M]) 
{//数组转置
	int t;
	int m = M > P ? M : P;
	//这里的思路是取M和P的最大值，补全整个m*m矩阵然后再进行转置
	//在输出的时候输出M＊P
	for (int i = 0; i < m; i++)
	{
		for (int j = i; j < m; j++)
		{
			if (i != j) 
			{
				t = a[i][j]; a[i][j] = a[j][i]; a[j][i] = t;
			}
		}
	}
}
void ReverseArraydou(double a[P][M])
{//数组转置
	double t;
	int m = M > P ? M : P;
	//这里的思路是取M和P的最大值，补全整个m*m矩阵然后再进行转置
	//在输出的时候输出M＊P
	for (int i = 0; i < m; i++)
	{
		for (int j = i; j < m; j++)
		{
			if (i != j)
			{
				t = a[i][j]; a[i][j] = a[j][i]; a[j][i] = t;
			}
		}
	}
}


double f(double x1, double x2, double e)
{
	return x1 * x1 + x2 * x2 + e * (1 - x1)*(1 - x1);
}
double fx1(double x1, double x2, double e)
{
	//return f.x1(x1, x2, e);
	return 2 * x1 - 2 * e*(1 - x1);
}
double fx2(double x1, double x2, double e)
{
	return 2.0*x2;
}
double fx1x1(double x1, double x2, double e)
{
	return 2+2*e;
}
int fx1x2(int x1, int x2, int e)
{
	return 0;
}
int fx2x1(int x1, int x2, int e)
{
	return 0;
}
int fx2x2(int x1, int x2, int e)
{
	return 2;
}
void matrix_inverse(double(*a)[N], double(*b)[N])
{
	using namespace std;
	int i, j, k;
	double max, temp;
	// 定义一个临时矩阵t
	double t[N][N];
	// 将a矩阵临时存放在矩阵t[n][n]中
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			t[i][j] = a[i][j];
		}
	}
	// 初始化B矩阵为单位矩阵
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			b[i][j] = (i == j) ? (double)1 : 0;
		}
	}
	// 进行列主消元，找到每一列的主元
	for (i = 0; i < N; i++)
	{
		max = t[i][i];
		// 用于记录每一列中的第几个元素为主元
		k = i;
		// 寻找每一列中的主元元素
		for (j = i + 1; j < N; j++)
		{
			if (fabs(t[j][i]) > fabs(max))
			{
max = t[j][i];
k = j;
			}
		}
		//cout<<"the max number is "<<max<<endl;
		// 如果主元所在的行不是第i行，则进行行交换
		if (k != i)
		{
			// 进行行交换
			for (j = 0; j < N; j++)
			{
				temp = t[i][j];
				t[i][j] = t[k][j];
				t[k][j] = temp;
				// 伴随矩阵B也要进行行交换
				temp = b[i][j];
				b[i][j] = b[k][j];
				b[k][j] = temp;
			}
		}
		if (t[i][i] == 0)
		{
			cout << "\nthe matrix does not exist inverse matrix\n";
			break;
		}
		// 获取列主元素
		temp = t[i][i];
		// 将主元所在的行进行单位化处理
		//cout<<"\nthe temp is "<<temp<<endl;
		for (j = 0; j < N; j++)
		{
			t[i][j] = t[i][j] / temp;
			b[i][j] = b[i][j] / temp;
		}
		for (j = 0; j < N; j++)
		{
			if (j != i)
			{
				temp = t[j][i];
				//消去该列的其他元素
				for (k = 0; k < N; k++)
				{
					t[j][k] = t[j][k] - temp * t[i][k];
					b[j][k] = b[j][k] - temp * b[i][k];
				}
			}

		}

	}
}
void printmaxtix(double*arr, int iRows, int iCols)
{
	
	for (int i = 0; i < iRows; i++)
	{
		for (int j = 0; j < iCols; j++)
		{
			cout << *(arr + i * iRows + j) << endl;

		}
	}
}
void printmaxtixint(int*arr, int iRows, int iCols)
{

	for (int i = 0; i < iRows; i++)
	{
		for (int j = 0; j < iCols; j++)
		{
			cout << *(arr + i * iRows + j) << endl;

		}
	}
}
int main()
{


	//m = zeros(1, 50); a = zeros(1, 50); b = zeros(1, 50); f0 = zeros(1, 50); %a b为最优点坐标，f0为最优点函数值，f1 f2最优点梯度。
	double  m[50], a[50], b[50], f0[50] = { 0 };

	//	syms x1 x2 e; %e为罚因子。

	//	m(1) = 1; c = 10; a(1) = 0; b(1) = 0; %c为递增系数。赋初值。
	m[0] = 1;
	double c = 10;
	a[0] = 0;
	b[0] = 0;
	f0[0] = 1;
	double x1 = a[0];
	double x2 = b[0];
	double e = m[0];
	//	f = x1 ^ 2 + x2 ^ 2 + e * (1 - x1) ^ 2; f0(1) = 1;
	//fx1 = diff(f, 'x1'); fx2 = diff(f, 'x2'); fx1x1 = diff(fx1, 'x1'); fx1x2 = diff(fx1, 'x2'); fx2x1 = diff(fx2, 'x1'); fx2x2 = diff(fx2, 'x2'); %求偏导、海森元素。
	for (int i = 0; i < 50; i++)
	{
		x1 = a[i];
		x2 = b[i];
		e = m[i];
		for (int j= 0; j < 50; j++)
		{
			double f1 = fx1(x1, x2, e);
			//cout << x1;
			//cout << f1;
			double f2 = fx2(x1, x2,e);
			
			int f11 = fx1x1(x1,x2, e);
			int f12 = fx1x2(x1, x2, e);
			int f21 = fx2x1(x1, x2, e);
			int f22 = fx2x2(x1, x2,e);
			double value_comp = sqrt(f1*f1 + f2 * f2);
			if (value_comp <= 0.002)
			{
				a[i + 1] = x1;
				b[i + 1] = x2;
				f0[i + 1] = f(x1, x2, e);
				
				break;
			}
			else
			{
				double dd = (f1*x1 +f1*e*x1 + f2*x2 -f1*e) / (f1*f1 +  f2*f2+e*f1*f1);
				x1 = x1 - dd * f1; 
				x2 = x2 - dd * f2;
				//cout << x1;
				//cout << x2;
				
			}
		}
		double value1 = sqrt((a[i + 1] - a[i])*(a[i + 1] - a[i]) + (b[i + 1] - b[i])*(b[i + 1] - b[i]));
		double value2 = abs((f0[i + 1] - f0[i]) / f0[i]);
		if (value1 <= 0.001 && (value2 <= 0.001))
		{
			cout << "a[i+1]" << i << "," << a[i + 1] << endl;
			cout << "b[i+1]" << i << "," << b[i + 1] << endl;
				
			cout << "f0[i+1]" << i << "," << f0[i + 1] << endl;

			break;
		}
		else
		{
			m[i + 1] = c * m[i];
		}



			

		
	}
	return cin.get();


	
}
//
//#include <iostream>
//#include "../FADBAD/FADBAD++/fadiff.h"
//#include<math.h>
//
//#define N 2
//#define P 1
//#define M 2
//using namespace std;
//
//void ReverseArray(int a[P][M])
//{//数组转置
//	int t;
//	int m = M > P ? M : P;
//	//这里的思路是取M和P的最大值，补全整个m*m矩阵然后再进行转置
//	//在输出的时候输出M＊P
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = i; j < m; j++)
//		{
//			if (i != j)
//			{
//				t = a[i][j]; a[i][j] = a[j][i]; a[j][i] = t;
//			}
//		}
//	}
//}
//void ReverseArraydou(double a[P][M])
//{//数组转置
//	double t;
//	int m = M > P ? M : P;
//	//这里的思路是取M和P的最大值，补全整个m*m矩阵然后再进行转置
//	//在输出的时候输出M＊P
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = i; j < m; j++)
//		{
//			if (i != j)
//			{
//				t = a[i][j]; a[i][j] = a[j][i]; a[j][i] = t;
//			}
//		}
//	}
//}
//
//
//int f(int x1, int x2, int e)
//{
//	return x1 * x1 + x2 * x2 + e * (1 - x1)*(1 - x1);
//}
//int fx1(int x1, int x2, int e)
//{
//	//return f.x1(x1, x2, e);
//	return 2 * x1 - 2 * e*(1 - x1);
//}
//int fx2(int x1, int x2, int e)
//{
//	return 2 * x2;
//}
//int fx1x1(int x1, int x2, int e)
//{
//	return 2 + 2 * e;
//}
//int fx1x2(int x1, int x2, int e)
//{
//	return 0;
//}
//int fx2x1(int x1, int x2, int e)
//{
//	return 0;
//}
//int fx2x2(int x1, int x2, int e)
//{
//	return 2;
//}
//void matrix_inverse(double(*a)[N], double(*b)[N])
//{
//	using namespace std;
//	int i, j, k;
//	double max, temp;
//	// 定义一个临时矩阵t
//	double t[N][N];
//	// 将a矩阵临时存放在矩阵t[n][n]中
//	for (i = 0; i < N; i++)
//	{
//		for (j = 0; j < N; j++)
//		{
//			t[i][j] = a[i][j];
//		}
//	}
//	// 初始化B矩阵为单位矩阵
//	for (i = 0; i < N; i++)
//	{
//		for (j = 0; j < N; j++)
//		{
//			b[i][j] = (i == j) ? (double)1 : 0;
//		}
//	}
//	// 进行列主消元，找到每一列的主元
//	for (i = 0; i < N; i++)
//	{
//		max = t[i][i];
//		// 用于记录每一列中的第几个元素为主元
//		k = i;
//		// 寻找每一列中的主元元素
//		for (j = i + 1; j < N; j++)
//		{
//			if (fabs(t[j][i]) > fabs(max))
//			{
//				max = t[j][i];
//				k = j;
//			}
//		}
//		//cout<<"the max number is "<<max<<endl;
//		// 如果主元所在的行不是第i行，则进行行交换
//		if (k != i)
//		{
//			// 进行行交换
//			for (j = 0; j < N; j++)
//			{
//				temp = t[i][j];
//				t[i][j] = t[k][j];
//				t[k][j] = temp;
//				// 伴随矩阵B也要进行行交换
//				temp = b[i][j];
//				b[i][j] = b[k][j];
//				b[k][j] = temp;
//			}
//		}
//		if (t[i][i] == 0)
//		{
//			cout << "\nthe matrix does not exist inverse matrix\n";
//			break;
//		}
//		// 获取列主元素
//		temp = t[i][i];
//		// 将主元所在的行进行单位化处理
//		//cout<<"\nthe temp is "<<temp<<endl;
//		for (j = 0; j < N; j++)
//		{
//			t[i][j] = t[i][j] / temp;
//			b[i][j] = b[i][j] / temp;
//		}
//		for (j = 0; j < N; j++)
//		{
//			if (j != i)
//			{
//				temp = t[j][i];
//				//消去该列的其他元素
//				for (k = 0; k < N; k++)
//				{
//					t[j][k] = t[j][k] - temp * t[i][k];
//					b[j][k] = b[j][k] - temp * b[i][k];
//				}
//			}
//
//		}
//
//	}
//}
//void printmaxtix(double*arr, int iRows, int iCols)
//{
//
//	for (int i = 0; i < iRows; i++)
//	{
//		for (int j = 0; j < iCols; j++)
//		{
//			cout << *(arr + i * iRows + j) << endl;
//
//		}
//	}
//}
//void printmaxtixint(int*arr, int iRows, int iCols)
//{
//
//	for (int i = 0; i < iRows; i++)
//	{
//		for (int j = 0; j < iCols; j++)
//		{
//			cout << *(arr + i * iRows + j) << endl;
//
//		}
//	}
//}
//int main()
//{
//
//
//	//m = zeros(1, 50); a = zeros(1, 50); b = zeros(1, 50); f0 = zeros(1, 50); %a b为最优点坐标，f0为最优点函数值，f1 f2最优点梯度。
//	int m[50], a[50], b[50], f0[50] = { 0 };
//
//	//	syms x1 x2 e; %e为罚因子。
//
//	//	m(1) = 1; c = 10; a(1) = 0; b(1) = 0; %c为递增系数。赋初值。
//	m[0] = 1;
//	int c = 10;
//	a[0] = 0;
//	b[0] = 0;
//	f0[0] = 1;
//	//	f = x1 ^ 2 + x2 ^ 2 + e * (1 - x1) ^ 2; f0(1) = 1;
//	//fx1 = diff(f, 'x1'); fx2 = diff(f, 'x2'); fx1x1 = diff(fx1, 'x1'); fx1x2 = diff(fx1, 'x2'); fx2x1 = diff(fx2, 'x1'); fx2x2 = diff(fx2, 'x2'); %求偏导、海森元素。
//	for (int i = 0; i < 50; i++)
//	{
//		//for (int j; j < 100; j++)
//		{
//			int f1 = fx1(a[i], b[i], m[i]);
//			int f2 = fx2(a[i], b[i], m[i]);
//
//			int f11 = fx1x1(a[i], b[i], m[i]);
//			int f12 = fx1x2(a[i], b[i], m[i]);
//			int f21 = fx2x1(a[i], b[i], m[i]);
//			int f22 = fx2x2(a[i], b[i], m[i]);
//			double value_comp = sqrt(f1*f1 + f2 * f2);
//			if (value_comp <= 0.001)
//			{
//				a[i + 1] = a[i];
//				b[i + 1] = b[i];
//				f0[i + 1] = f(a[i], b[i], m[i]);
//				break;
//			}
//			else
//			{
//				double aa[2][2] = { f11,f12, f21 ,f22 };
//				double bb[2][2] = { 0 };
//
//				matrix_inverse(aa, bb);  //求逆函数
//				int cc[2][2] = { f1,f2 };
//
//				ReverseArray(cc);
//
//				int dd[1][2] = { a[i],b[i] };
//				ReverseArray(dd);
//
//				double mul[2][2] = { 0 };
//				for (int i = 0; i < 2; i++)
//				{
//					for (int j = 0; j < 1; j++)
//					{
//						mul[i][j] = 0;
//						for (int k = 0; k < 2; k++)
//						{
//							mul[i][j] += bb[i][k] * cc[k][j];
//							cout << bb[i][k];
//							cout << cc[k][j];
//							cout << mul[i][j];
//						}
//					}
//				}
//				//printmaxtix((double *)bb, 2, 2);
//				//printmaxtixint((int *)cc,2,1);
//				ReverseArraydou(mul);
//
//
//				//cin.get();
//				a[i] = dd[0][0] - mul[0][0]; b[i] = dd[1][0] - mul[1][0];
//			}
//			double value1 = sqrt((a[i + 1] - a[i])*(a[i + 1] - a[i]) + (b[i + 1] - b[i])*(b[i + 1] - b[i]));
//			double value2 = abs((f0[i + 1] - f0[i]) / f0[i]);
//			if (value1 <= 0.001 && (value2 <= 0.001))
//			{
//				cout << "a[i+1]" << i << "," << a[i + 1] << endl;
//				cout << "b[i+1]" << i << "," << b[i + 1] << endl;
//
//				cout << "f0[i+1]" << i << "," << f0[i + 1] << endl;
//
//				break;
//			}
//			else
//			{
//				m[i + 1] = c * m[i];
//			}
//
//
//
//
//
//		}
//	}
//	return cin.get();
//
//
//	//	if (double(sqrt((a(k + 1) - a(k)) ^ 2 + (b(k + 1) - b(k)) ^ 2)) <= 0.001) && (double(abs((f0(k + 1) - f0(k)) / f0(k))) <= 0.001) % 罚因子迭代收敛条件
//	//		a(k + 1) % 输出最优点坐标，罚因子迭代次数，最优值
//	//		b(k + 1)
//	//		k
//	//		f0(k + 1)
//	//		break;
//	//	else
//	//		m(k + 1) = c * m(k);
//	//end
//	//	end
//
//}
