using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication
{
    class DeCompressor
    {
        public void Compress(string folder_path_src, string file_target)
        {
        }

        public void DeCompress(string file_path_src,string folder_path_target)
        {
            var container = new Aml.Engine.AmlObjects.AutomationMLContainer(file_path_src);
            container.ExtractAllFiles(folder_path_target);
        }
    }
}
