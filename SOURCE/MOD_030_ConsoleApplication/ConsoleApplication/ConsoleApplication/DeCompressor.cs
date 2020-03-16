using System;
using System.Collections.Generic;
using System.IO;
using System.IO.Packaging;
using System.Text;

namespace ConsoleApplication
{
    public static class DeCompressor
    {
        public static void Compress(string folder_path_src, string file_target)
        {
            // ! Verlangt file_target kein Verzechniss sondern Datei



            // creates empty AMLX / ZIP in target directory
            var container = new Aml.Engine.AmlObjects.AutomationMLContainer(file_target, FileMode.OpenOrCreate);


            using (Package zip = container.Package)
            {
                string destFilename = ".\\" + Path.GetFileName(file_target);
                Uri uri = PackUriHelper.CreatePartUri(new Uri(destFilename, UriKind.Relative));
                if (zip.PartExists(uri))
                {
                    zip.DeletePart(uri);
                }
                PackagePart part = zip.CreatePart(uri, "", CompressionOption.Normal);
                using (FileStream fileStream = new FileStream(folder_path_src, FileMode.Open, FileAccess.Read))
                {
                    using (Stream dest = part.GetStream())
                    {
                        fileStream.CopyTo(dest);
                    }
                }
            }

        }

        public static void DeCompress(string file_path_src,string folder_path_target)
        {
            try
            {
                var container = new Aml.Engine.AmlObjects.AutomationMLContainer(file_path_src);
                container.ExtractAllFiles(folder_path_target);
            }
            catch (IOException ex)
            {
                
                Console.WriteLine($"Error occured ( {ex})");
                Console.WriteLine("\n Cannot find file..");
            }
        }
    }
}
