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
        public async Task<object> Invoke(dynamic payload)
        {
            Console.WriteLine($"Calling function {payload.name}");
            Console.WriteLine($"With {payload.input}");
            if (payload.name == "createTestFile")
            {
                var caexDocument = CAEXDocument.New_CAEXDocument();
                caexDocument.SaveToFile("build/Lucas_ist_ein_doofi.aml", true);
            }
            return true;
        }
    }
}
