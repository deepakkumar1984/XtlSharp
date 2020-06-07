using System;
using XtlSharp;

namespace ScratchPad
{
    class Program
    {
        static void Main(string[] args)
        {
            XArray x = new XArray(new float[] { 1, 2, 3, 4, 5, 6, 7, 8, 9 }).Reshape(3, 3);
            var y = x[":", 1];
            var d = y.ToArray();
        }
    }
}
