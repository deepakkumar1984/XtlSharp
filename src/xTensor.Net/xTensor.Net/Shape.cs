using System;
using System.Collections.Generic;
using System.Text;

namespace xTensor
{
    public class Shape
    {
        public long[] Data { get; set; }

        public int Dimension => Data.Length;

        public int Length => Data.Length;

        public long Size
        {
            get
            {
                if (Data.Length == 0)
                    return 0;

                var total = 1L;
                for (int i = 0; i < Data.Length; ++i)
                    total *= Data[i];
                return total;
            }
        }

        public Shape(params long[] shape)
        {
            Data = shape;
        }

        public long this[int index]
        {
            get
            {
                return Data[index];
            }
            set
            {
                Data[index] = value;
            }
        }
    }
}
