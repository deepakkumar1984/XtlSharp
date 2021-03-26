using System;
using XtlSharp;
using Random = XtlSharp.Random;

namespace ScratchPad
{
    class Program
    {
        static void Main(string[] args)
        {
            var r = Random.Rand(new Shape(3, 3), 0, 1);
            var d = r.ToArray();
        }
    }
}
