using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

namespace XtlSharp.Native
{
    internal class NativeWrapper
    {
        private const string dll = "libxtl";

        [DllImport(dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr TS_GetLastError();

        [DllImport(dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern int TS_Fill(IntPtr tensorRef, double value);

        [DllImport(dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern int TS_Elementwise_1(IntPtr a, IntPtr r, int op);

        [DllImport(dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern int TS_Elementwise_1_Cls(IntPtr a, IntPtr r, int op);

        [DllImport(dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern int TS_Elementwise_2(IntPtr a, IntPtr b, IntPtr r, int op);

        [DllImport(dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern int TS_Elementwise_2_Bitwise(IntPtr a, IntPtr b, IntPtr r, int op);

        [DllImport(dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern int TS_Elementwise_3(IntPtr a, IntPtr b, IntPtr c, IntPtr r, int op);

        [DllImport(dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern int TS_Cast(IntPtr x, int type, IntPtr r);

        [DllImport(dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern int TS_Clip(IntPtr x, double min, double max, IntPtr r);

        [DllImport(dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern int TS_Pow(IntPtr x, double value, IntPtr r);

        [DllImport(dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern int TS_IsClose(IntPtr a, IntPtr b, double rtol, double atol, bool equal_nan, IntPtr r);

        [DllImport(dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern int TS_AllClose(IntPtr a, IntPtr b, double rtol, double atol, IntPtr r);
    }
}
