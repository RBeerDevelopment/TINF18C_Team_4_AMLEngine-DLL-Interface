using Aml.Engine.CAEX;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Adapter
{
    public static class CaexOpener
    {
        public  static CAEXDocument OpenCaexSafe(string path)
        {
            try
            {
                if (!File.Exists(path))
                {
                    Console.WriteLine($"Cannot find file {path}");
                    Console.WriteLine($"Try to create new one in {path}");

                    var cAEXDocument = CAEXDocument.New_CAEXDocument();

                    cAEXDocument.SaveToFile(path,true);

                    return cAEXDocument;
                }



                return CAEXDocument.LoadFromFile(path);
            }
            catch (Exception ex)
            {
                Console.WriteLine($"ERROR: {ex.Message}");
                return null;
            }
        }

    }
}
