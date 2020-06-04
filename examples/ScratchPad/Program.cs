using System;
using XtlSharp;

namespace ScratchPad
{
    class Program
    {
        static void Main(string[] args)
        {
            XArray x = new XArray(new Shape(2, 3), DType.Float32);
            XArray y = new XArray(new Shape(2, 3), DType.Float32);

            x.Fill(2);
            y.Fill(3);
            var z = xt.Less(x, y);
            var data_z = z.ToArray();
        }
    }
}
