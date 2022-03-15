#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX_SIZE 100
#define PI 3.141592653589793

//https://www.cnblogs.com/hrlnw/archive/2013/04/28/3012368.html

//复数
struct complex
{
    double real;
    double image;
};
complex a1[MAX_SIZE], a2[MAX_SIZE], result[MAX_SIZE], w[MAX_SIZE];

//复数相乘计算
complex operator*(complex a, complex b)
{
    complex r;
    r.real = a.real * b.real - a.image * b.image;
    r.image = a.real * b.image + a.image * b.real;
    return r;
}

//复数相加计算
complex operator+(complex a, complex b)
{
    complex r;
    r.real = a.real + b.real;
    r.image = a.image + b.image;
    return r;
}
//复数相减计算
complex operator-(complex a, complex b)
{
    complex r;
    r.real = a.real - b.real;
    r.image = a.image - b.image;
    return r;
}
//复数除法计算
complex operator/(complex a, double b)
{
    complex r;
    r.real = a.real / b;
    r.image = a.image / b;
    return r;
}
//复数虚部反计算
complex operator~(complex a)
{
    complex r;
    r.real = a.real;
    r.image = 0 - a.image;
    return r;
}

//重新排列方法1，该方法是用pow函数效率比较低
void reverse1(int * id, int size, int m)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int exp = (i >> j) & 1;
            id[i] += exp * (int)pow((double)2, (double)(m - j - 1));
        }
    }
};

//重新排列方法2，效率较高
void reverse2(int * id, int size, int m)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < (m + 1) / 2;  j++)
        {
            int v1 = ((1 << j) & i) << (m - 2 * j - 1);
            int v2 = (1 << (m - j - 1) & i) >> (m - 2 * j - 1);
            id[i] |= (v1 | v2);
        }
    }
};

//计算并存储需要乘的w值
void compute_w(complex w[], int size)
{
    for(int i = 0; i < size / 2; i++)
    {
        w[i].real = cos(2 * PI * i / size);
        w[i].image = sin(2 * PI * i / size);
        w[i + size / 2].real = 0 - w[i].real;
        w[i + size / 2].image = 0 - w[i].image;
    }
};
//快速傅里叶
void fft(complex in[], int size)
{
    int * id = new int[size];
    memset(id, 0, sizeof(int) * size);
    int m = log((double)size) / log((double)2);
    reverse2(id, size, m);    //将输入重新排列，符合输出
    complex * resort = new complex[size];
    memset(resort, 0, sizeof(complex) * size);
    int i, j, k, s;
    for(i = 0; i < size; i++)
        resort[i] = in[id[i]];
    for(i = 1; i <= m; i++)
    {
        s = (int)pow((double)2, (double)i);
        for(j = 0; j < size / s; j++)
        {
            for(k = j * s; k < j * s + s / 2; k++)
            {        
                complex k1 = resort[k] + w[size / s * (k - j * s)] * resort[k + s / 2];
                resort[k + s / 2] = resort[k] - w[size / s * (k - j * s)] * resort[k + s / 2];
                resort[k] = k1;
            }
        }
    }
    for(i = 0; i < size; i++)
        in[i] = resort[i];
    delete[] id;
    delete[] resort;
};
//快速逆傅里叶
void ifft(complex in[], int size)
{
    int * id = new int[size];
    memset(id, 0, sizeof(int) * size);
    int m = log((double)size) / log((double)2);
    reverse2(id, size, m);    //将输入重新排列，符合输出
    complex * resort = new complex[size];
    memset(resort, 0, sizeof(complex) * size);
    int i, j, k, s;
    for(i = 0; i < size; i++)
        resort[i] = in[id[i]];
    for(i = 1; i <= m; i++)
    {
        s = (int)pow((double)2, (double)i);
        for(j = 0; j < size/s; j++)
        {
            for(k = j * s; k < j * s + s / 2; k++)
            {
                complex k1 = (resort[k] + (~w[size / s * (k - j * s)]) * resort[k + s / 2]);
                resort[k + s / 2] = (resort[k] - (~w[size / s * (k - j * s)]) * resort[k + s/2]);
                resort[k] = k1;
            }
        }
    }
    for(i = 0; i < size; i++)
        in[i] = resort[i] / size;
    delete[] id;
    delete[] resort;
};

int main()
{
    //输入两个多项式数列
    int size, size1, size2, i;
    memset(a1, 0, sizeof(a1));
    memset(a2, 0, sizeof(a2));
    memset(w, 0, sizeof(w));
    memset(result, 0, sizeof(result));
    printf("size1 = ");
    scanf("%d", &size1);
    printf("size2 = ");
    scanf("%d", &size2);
    printf("a = ");
    char a[MAX_SIZE];
    scanf("%s", a);
    printf("b = ");
    char b[MAX_SIZE];
    scanf("%s", b);
    for(i = 0; i < size1; i++)
        a1[i].real = *(a + i) - '0';
    for(i = 0; i < size2; i++)
        a2[i].real = *(b + i) - '0';
    size = size1 > size2 ? size1 * 2 : size2 * 2;
    compute_w(w, size);
    fft(a1, size);
    fft(a2, size);
    for(i = 0; i < size; i++)
        result[i] = a1[i] * a2[i];
    ifft(result, size);
    for(i = 0;i < size1 + size2 - 1; i++)
        printf("%.2lf ", result[i].real);
    printf("\n");
    return 0;
}