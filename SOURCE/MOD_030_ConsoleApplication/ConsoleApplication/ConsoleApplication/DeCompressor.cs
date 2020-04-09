using System;
using System.Collections.Generic;
using System.IO;

namespace ConsoleApplication
{
    public static class DeCompressor
    {
        public static void Compress(string sourceAMLFile, string file_target, List<string> OtherFiles)
        {
            try
            {
                // creates empty AMLX / ZIP in target directory
                string filename = Path.Combine(file_target, "Compressed-AMLX.amlx");

                // Create AML Container
                var container = new Aml.Engine.AmlObjects.AutomationMLContainer(filename, FileMode.Create);

                // Add Root-Element of AMLX-File
                var Root = container.AddRoot(sourceAMLFile, new Uri("/" + Path.GetFileName(sourceAMLFile), UriKind.Relative));

                //Add More Files if User wants more
                foreach (string NextFile in OtherFiles)
                {
                    if (Path.GetExtension(NextFile).ToUpper() == ".XSD")
                        container.AddCAEXSchema(NextFile, new Uri("/" + Path.GetFileName(NextFile), UriKind.Relative));
                    else
                        container.AddAnyContent(Root, NextFile, new Uri("/" + Path.GetFileName(NextFile), UriKind.Relative));
                }
                // Finally Close File
                container.Close();

                PrintHelper.printCentredLine("Sucessfully Created AMLX-File \n \n");
            }
            catch (Exception e)
            {
                Console.WriteLine("Exception: " + e.ToString());
                PrintHelper.println("Could not Create AMLX-File",ConsoleColor.Red);
            }

            PrintHelper.Exit("Returning to Main Menu");

        }

        public static void DeCompress(string file_path_src,string folder_path_target)
        {
            try
            {
                var container = new Aml.Engine.AmlObjects.AutomationMLContainer(file_path_src);
                container.ExtractAllFiles(folder_path_target);
                PrintHelper.printCentredLine("\nSuccessfully Extracted Files");
            }
            catch (IOException ex)
            {
                PrintHelper.println($"Error occured ( {ex})", ConsoleColor.Red);
                PrintHelper.println("\n Cannot find file..", ConsoleColor.Red);
            }
            catch (Exception e)
            {
                Console.WriteLine("Exception: " + e.ToString());
                PrintHelper.println("\nCould not Extract Files", ConsoleColor.Red);
            }
            PrintHelper.Exit("\n\nReturning to Main Menu");
        }
    }
}
