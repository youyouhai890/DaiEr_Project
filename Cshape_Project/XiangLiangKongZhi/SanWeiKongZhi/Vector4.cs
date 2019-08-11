using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SanWeiKongZhi
{
    class Vector4
    {
        //四维坐标
        public double x, y, z, w;
        public Vector4() { }    //构造
        public Vector4(double x,double y, double z,double w)        //构造
        {
            this.x = x;
            this.y = y;
            this.z = z;
            this.w = w;
            
        }

        public Vector4(Vector4 v)
        {
            this.x = v.x;
            this.y = v.y;
            this.z = v.z;
            this.w = v.w;
        }    

        //计算向量的方向
        public static Vector4 operator -(Vector4 a,Vector4 b)
        {
            return new Vector4( a.x - b.x , a.y - b.y , a.z - b.z , a.w - b.w );
        }
        
        public Vector4 Cross(Vector4 v)
        {
            //叉积
            return new Vector4(this.y*v.z-this.z*v.y,this.z*v.x-this.x*v.z,this.x*v.y-this.y*v.x,0);
        }  
        public float Dot(Vector4 v)
        {
            //点积
            return (float)( this.x * v.x + this.y * v.y + this.z * v.z );
        }

        public Vector4 Normalized
        {
            get
            {
                //向量的规范化公式(取模),sqrt应该是平方根
                double Mod = Math.Sqrt( x * x + y * y + z * z + w * w );
                return new Vector4( x / Mod , y / Mod , z / Mod , w / Mod );
            }
        }


    }
}
