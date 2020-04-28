using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication
{
    public class Options
    {
        public bool AutoRepair;
        public bool PrintAllVal;
        public Options()
        {
            AutoRepair = bool.Parse(PrintHelper.GetRegistryKey("AutoRepair") ?? "false");
            PrintAllVal = bool.Parse(PrintHelper.GetRegistryKey("PrintAllVal") ?? "false");
        }

        public void SaveOptions()
        {
            PrintHelper.SetRegistryKey("AutoRepair", AutoRepair.ToString());
            PrintHelper.SetRegistryKey("PrintAllVal", PrintAllVal.ToString());
        }
    }
}
