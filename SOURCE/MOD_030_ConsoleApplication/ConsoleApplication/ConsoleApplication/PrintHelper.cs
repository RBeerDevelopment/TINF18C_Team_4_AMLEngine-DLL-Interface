using System;
using System.IO;
using System.Windows.Forms;

namespace ConsoleApplication
{
    public static class PrintHelper
    {

        public static void welcome()
        {
            // print welcome,license .... Doc , explanat

            Console.WriteLine("welcome, doc, explant");
        }

        public static void Exit(string Message = "")
        {
            Console.WriteLine(Message);
            System.Threading.Thread.Sleep(3000);
        }

        public static void loopExplanation()
        {
            // entscheide
            Console.Clear();
            Console.WriteLine("What do you want to do?");
            Console.WriteLine("Type \"Validate\" to Validate an AML-File");
            Console.WriteLine("Type \"Compress\" or \"Decompress\" to Compress or Decompress an existing AMLX-File");
            Console.WriteLine("Type \"Options\" to Edit the Configuration");
            Console.WriteLine("Type \"Quit\" or \"Exit\" to exit the Program");
        }

        public static void DeCompressor_Choosage(bool Compress = true)
        {
            Console.Clear();
            if (Compress)
                Console.WriteLine("Compress a Folder to an AMLX-File\n");
            else
                Console.WriteLine("De-Compress an AMLX-File to a Folder\n");
        }

        public static void PrepareConsoleForNewInput()
        {
            Console.SetCursorPosition(0, Console.CursorTop - 1);
            Console.WriteLine("                                                                                                                                                        ");
            Console.SetCursorPosition(0, Console.CursorTop - 2);
        }

        public static string GetFile(string Filename = "Any File" , string FileExtensions = "")
        {
            OpenFileDialog dialog = new OpenFileDialog
            {
                Multiselect = false,
                Title = "Open " + Filename,
            };
            if (!String.IsNullOrEmpty(FileExtensions))
                dialog.Filter = Filename + "|" + FileExtensions;
            if (dialog.ShowDialog() == DialogResult.OK && File.Exists(@dialog.FileName))
                return @dialog.FileName;
            else
                return null;
        }

        public static string GetDirectory()
        {
            FolderBrowserDialog dialog = new FolderBrowserDialog();
            if (dialog.ShowDialog() == DialogResult.OK && Directory.Exists(@dialog.SelectedPath) && File.GetAttributes(@dialog.SelectedPath).HasFlag(FileAttributes.Directory))
                return @dialog.SelectedPath;
            else
                return null;
        }

        public static void println(string message, ConsoleColor color)
        {
            ConsoleColor defaultColor = Console.ForegroundColor;

            Console.ForegroundColor = color;

            Console.WriteLine(message);

            Console.ForegroundColor = defaultColor;
        }

        public static string line()
        {
            var x = "";
            for (int i = 0; i < 50; i++)
            {
                x += "_";
            }


            return x;
        }

        public static void printOptions()
        {
                Console.Clear();
                Console.WriteLine("Available Options to configure this Program: \n");
                Console.WriteLine("AutoRepair: Automatically repais all Issues found while Validating\n");
                Console.WriteLine("PrintAllVal: Prints all found Elements to the Console while Validating\n\n");
                Console.WriteLine("Which Config do you want to Change?");
                Console.WriteLine("Type Exit, Quit or just press Enter to go back to Menu\n");
        }

        public static void printOptionAutoRepair(bool CurrentValue)
        {
            Console.Clear();
            Console.WriteLine("What should be the new Value?");
            Console.WriteLine("Current Value :" + CurrentValue.ToString());
            Console.WriteLine("Possible Values: ");
            Console.WriteLine(" - false (default): The Validator asks before each repair, if the User wants to Repair this Issue.");
            Console.WriteLine(" - true: The Validator automatically repairs all Issues found");
        }

        public static void printOptionPrintAllVal(bool CurrentValue)
        {
            Console.Clear();
            Console.WriteLine("What should be the new Value?");
            Console.WriteLine("Current Value :" + CurrentValue.ToString());
            Console.WriteLine("Possible Values: ");
            Console.WriteLine(" - false (default): The Validator does not print all Elements");
            Console.WriteLine(" - true: The Validator prints all found Elements");
        }
    }
}
