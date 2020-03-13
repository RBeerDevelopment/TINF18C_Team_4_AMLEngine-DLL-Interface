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
            //var container = new Aml.Engine.AmlObjects.AutomationMLContainer();

            //Test folder_path_src= aml file

            //https://stackoverflow.com/questions/6386113/using-system-io-packaging-to-generate-a-zip-file
            var container = new Aml.Engine.AmlObjects.AutomationMLContainer(folder_path_src, FileMode.OpenOrCreate);

            //container.Package

            //container.


            using (Package zip = System.IO.Packaging.Package.Open(file_target, FileMode.OpenOrCreate))
            {
                string destFilename = ".\\" + Path.GetFileName(folder_path_src);
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





        public static void DeCompress(string file_path_src, string folder_path_target)
        {
            //https://github.com/AutomationML/AMLEngine/wiki/M_AML_Container_AMLContainerExtension_CreateAMLSelfContainingContainerWithAllReferencesResolved

            var container = new Aml.Engine.AmlObjects.AutomationMLContainer(file_path_src);

            container.ExtractAllFiles(folder_path_target);
        }
    }
}
