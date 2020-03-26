using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Aml.Engine;
using Aml.Engine.CAEX;
using System.Data;
using System.Threading.Tasks;
using System;

namespace Adapter
{
    public class Class1
    {
    }

    public class Startup
    {
        public async Task<object> Invoke(dynamic input)
        {
            Console.WriteLine(input.i);
            if (input.i == 1)
            {
                var caexDocument = CAEXDocument.New_CAEXDocument();
                caexDocument.SaveToFile("build/Lucas_ist_ein_doofi.aml", true);
            }
            return this.Add7((int)input.c);
        }

        int Add7(int v)
        {
            return Helper.Add7(v);
        }
    }

    static class Helper
    {
        public static int Add7(int v)
        {
            return v + 7;
        }
    }
}
