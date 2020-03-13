using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication
{
    public static class PrintHelper
    {

        public static void welcome()
        {
            // print welcome,license .... Doc , explanat

            Console.WriteLine("welcome, doc, explant");
        }

        public static void exit()
        {
            // print welcome,license .... Doc , explanat

            Console.WriteLine("thanks for working with us, please donate under ...");
        }

        public static void loopExplanation()
        {
            // entscheide
            Console.Clear();
            Console.WriteLine("What do you want to do?");
            Console.WriteLine("Type \"Validate\" to Validate an AML-File");
            Console.WriteLine("Type \"Compress\" or \"Decompress\" to Compress or Decompress an existing AMLX-File");
            Console.WriteLine("Type \"Quit\" or \"Exit\" to exit the Program");
        }

        public static void DeCompressor_Choosage(CompressTypeEnum Compress)
        {
            Console.Clear();
            if (Compress== CompressTypeEnum.Compress)
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
    }
}
