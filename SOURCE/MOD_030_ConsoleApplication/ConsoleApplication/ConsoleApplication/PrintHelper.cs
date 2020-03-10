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

            Console.WriteLine("you have to choose ");
            Console.WriteLine("1 => Validate");
            Console.WriteLine("2 => De / compress");
            Console.WriteLine("3 => Exit programm");
        }

        public static void DeCompressor_Choosage()
        {
            Console.WriteLine("you have to choose ");
            Console.WriteLine("1 => Compress");
            Console.WriteLine("2 => De / compress");
        }
    }
}
