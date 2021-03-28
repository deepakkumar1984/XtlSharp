using NumSharp;
using System;
using XtlSharp;

namespace ScratchPad
{
    class Program
    {
        static void Main(string[] args)
        {
            PerfTest1();
            PerfTest1();
            PerfTest1();
        }

        private static void PerfTest1()
        {
            DateTime start = DateTime.Now;
            var x = xt.random.Uniform(new XtlSharp.Shape(30000, 100), 0, 1, XtlSharp.DType.Float64);
            var y = xt.random.Uniform(new XtlSharp.Shape(30000, 100), 0, 1, XtlSharp.DType.Float64);
            
            var d = 0.5 * xt.Sqrt(x) + xt.Sin(y) * xt.Log(x) - xt.Exp(y);
            Console.WriteLine("Duration: " + (DateTime.Now - start).TotalSeconds);

            //DateTime start = DateTime.Now;
            //var x = np.random.uniform(0, 1, new NumSharp.Shape(30000, 1000));
            //var y = np.random.uniform(0, 1, new NumSharp.Shape(30000, 1000));
            //var d = 0.5 * np.sqrt(x) + np.sin(y);
            //Console.WriteLine("Duration: " + (DateTime.Now - start).TotalSeconds);
        }
    }
}
    