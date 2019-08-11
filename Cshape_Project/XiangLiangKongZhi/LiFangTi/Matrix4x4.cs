using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LiFangTi
{
    class Matrix4x4
    {
        private double[,] pts;  //二维数组,矩阵
        public Matrix4x4()  //初始化时构造函数
        {
            //给矩阵赋值
            pts = new double[4 , 4];
        }

        public double this[int i,int j] //索引
        {
            //为了对应数组下标所以-1
            get { return pts[i - 1 ,j - 1]; }
            set { pts[i - 1 , j - 1] = value; }
        }

        public Matrix4x4 Mul(Matrix4x4 m)
        {
            //定义新的矩阵,矩阵之间相乘后会获得新的矩阵
            Matrix4x4 newM = new Matrix4x4();

            for ( int w = 1 ; w <= 4 ; w++ )      //行
                for ( int h = 1 ; h <= 4 ; h++ )        //高
                    for ( int n = 1 ; n <= 4 ; n++ )    
                    {
                                          //N列(横向) , N行(垂直) , 向量跟矩阵相乘后相加
                        newM[w , h] += this[w , n] * m[n , h];
                    }
            return newM;

        }

        //顶点跟矩阵相乘
        public Vector4 Mul(Vector4 v )
        {
            //定义新的向量,原来的向量通常不会改变
            Vector4 newV = new Vector4();

            newV.x = v.x * this[1 , 1] + v.y * this[2 , 1] + v.z * this[3 , 1] + v.w * this[4 , 1];
            newV.y = v.x * this[1 , 2] + v.y * this[2 , 2] + v.z * this[3 , 2] + v.w * this[4 , 2];
            newV.z = v.x * this[1 , 3] + v.y * this[2 , 3] + v.z * this[3 , 3] + v.w * this[4 , 3];
            newV.w = v.x * this[1 , 4] + v.y * this[2 , 4] + v.z * this[3 , 4] + v.w * this[4 , 4];

            return newV;
        }

        //矩阵的转置
        public Matrix4x4 Transpose()
        {
            Matrix4x4 t = new Matrix4x4();
            for ( int i = 1 ; i <= 4 ; i++ )
                for ( int j = 1 ; j <= 4 ; j++ )
                    t[i , j] = this[j , i];

            return t;
            
        }

    }
}
