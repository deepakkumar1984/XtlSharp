using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

namespace XtlSharp.Native
{
    public class NativeWrapper
    {
        private const string dll = "libxtl";

        [DllImport(dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern int TS_Fill(IntPtr tensorRef, float value);

        [DllImport(dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern int TS_Binary(IntPtr a, IntPtr b, IntPtr r, int op);

        [DllImport(dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr TS_GetLastError();
    }
}
